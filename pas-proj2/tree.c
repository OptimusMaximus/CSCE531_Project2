/****************************************************************/
/*																                              */
/*	CSCE531 - "Pascal" and "C" Compilers						            */
/*																                              */
/*	--tree.c--													                        */
/*																                              */
/*	This File Contains routines that support the				        */
/*	"Tree Module".												                      */
/*																                              */
/*	Konstantin Rubin											                      */
/*  Maximus Brandel												                      */
/*	Ibrahim Elsayed												                      */
/****************************************************************/

#include <stdlib.h>
#include "tree.h"
#include "types.h"
#include <stdio.h>
#include <assert.h>

/* Endogenous linked list of currently unresolved pointer types.
   Initially empty */
static TYPE_LIST LIST_OF_UNRESOLVED_PTRS = NULL;
TYPE build_unresolved_pointer(TYPE ret_type, TYPE object)
{
	TYPE_LIST new_unresolved_pointer;
	new_unresolved_pointer = (TYPE_LIST) malloc(sizeof(TLIST_NODE));
	if (object == NULL){
		new_unresolved_pointer->type = ret_type; 
		new_unresolved_pointer->next = LIST_OF_UNRESOLVED_PTRS;
		LIST_OF_UNRESOLVED_PTRS = new_unresolved_pointer;
	}
	else
		new_unresolved_pointer->next = NULL;
	return ret_type;
} 

/* Install a typename into the symbol table */
void create_typename(ST_ID id,TYPE new_type)
{
	ST_DR new_data_rec;
	new_data_rec = stdr_alloc();

	//Fill the fields of the new symbol table data record
	new_data_rec->tag=TYPENAME;
	new_data_rec->u.typename.type=new_type;

	// Install the new data record in the symbol table
	if (!st_install(id,new_data_rec)) {
		error("This Type name is already installed");
	}
}
/* Install a global variable declaration into the symbol table */
void create_gdecl(VAR_ID_LIST list,TYPE type)
{
  //checking if the variable has a type of function
	if (ty_query(type) == TYFUNC) {
		error("Variable(s) must be of data type");		
	}

	ST_DR new_data_rec;

	while(list!=NULL)
	{
		resolve_all_ptr();

		new_data_rec = stdr_alloc();

		// Fill the fields of the new symbol table data record
		new_data_rec->tag=GDECL;
		new_data_rec->u.decl.type=type;
		new_data_rec->u.decl.sc=NO_SC;
		new_data_rec->u.decl.is_ref=FALSE;
		new_data_rec->u.decl.err = (ty_query(type) == TYERROR ? TRUE : FALSE);

		// Install the new data record in the symbol table
		if (!st_install(list->id,new_data_rec)) {
			error("Duplicate variable declaration: \"%s\"", st_get_id_str(list->id));
			free(new_data_rec);
		}

		list=list->next;
	}
}


/* This function checks if an ST_ID is already installed in the symbol table as a typename typename,if the id was not installed an error is issued.
 * It take one parameter; an ST_ID.If the ID was NULL a bug is found.
 * As an output it returns a type object; if the error is issued then an error type is returned else the original type is returned.
 */
TYPE check_typename(ST_ID id) {
	
	ST_DR chcktype;
	int chck;

  //if the id is null then bug is found 
	if (id == NULL)
		bug("null id passed to \"st_install\"");

	if ((chcktype = st_lookup(id,&chck)) == NULL) {
		error("Undeclared type name: \"%s\"", st_get_id_str(id));
		return ty_build_basic(TYERROR);
	}

	return chcktype->u.typename.type;
	
}

/* This function checks if the second index of the subrange is larger than the first, then it buids the subrange type.
 * It take two parameters; both an int representing the first and second indexes. 
 * As an output it returns a type object; if the error is issued then an error type is returned else the original type is returned.
 */
// TYPE check_subrange(long a, long b) {
// 	if (a < b) {
// 		return ty_build_subrange(ty_build_basic(TYSIGNEDLONGINT), a, b);
// 	}
// 	//error("Invalid subrange %i .. %i", a, b);
// 	error("Empty subrange in array index");
// 	error("Illegal index type (ignored)");
// 	//return NULL;
// 	return ty_build_basic(TYERROR);
// }

/* This function checks a function type to see if it's a simple type.
 * It take one parameter; a type object.If the type was a function then an error message is issued.
 * As an output it returns a type object; if the error is issued then an error type is returned else the original type is returned.
 */
TYPE check_function_type(TYPE type) {
	if (ty_query(type) == TYERROR) {
		error("Error in the function return type");
		return ty_build_basic(TYERROR);
	}

	if (ty_query(type) == TYFUNC) {
		error("Function return type must be simple type");
		return type; 
	}

	if (ty_query(type) == TYARRAY) {
		error("Function return type must be simple type");
		return type; 
	}

	return type;
}

/* This function checks an array to see if it's element type is valid.
 * It takes two parameters; a type object,and an INDEX_LIST index_list.If the type was not in the symbol table then an
 error is issued .
 * As an output it returns a type object; if the error is issued then an error type is returned else an array type is returned.
 */
TYPE check_array(TYPE type, INDEX_LIST i) {
	if (ty_query(type) == TYERROR) {
		error("Data type expected for array elements");
		return ty_build_basic(TYERROR);
	}
	if (ty_query(type) == TYFUNC) {
		error("Data type expected for array elements");
		error("Variable(s) must be of data type");
		return ty_build_basic(TYERROR);
	}


	return ty_build_array(type, i);
}

/* build a variable id list by pushing new id to the front */
VAR_ID_LIST build_var_id_list (VAR_ID_LIST list,ST_ID id)
{
  VAR_ID_LIST id_list, temp_list;

  id_list = (VAR_ID_LIST) malloc(sizeof(VAR_ID));

  id_list->id = id;
  id_list->next = NULL;
  //checking if the list is empty 
  if (list!=NULL)
  {
    // pushing the list to the back of new id 
    id_list->next=list;
  } 
  return id_list;  
}

/* Build a parameter list  */
PARAM_LIST build_param_list(VAR_ID_LIST id_list,TYPE type,BOOLEAN value)
{
	//creates a parameter list from single type list of ids: a,b,c : Real
	VAR_ID_LIST id_ptr = id_list;
	PARAM_LIST head = NULL;
  PARAM_LIST new_param;

	while(id_ptr != NULL)
	{
    //adding values to the new id
    new_param = (PARAM_LIST) malloc(sizeof(PARAM));
    new_param->id = id_ptr->id;
    new_param->type = type;
    new_param->sc = NO_SC;
    new_param->err = FALSE;
    new_param->is_ref = value;
    new_param->prev = NULL;
    new_param->next = NULL;

    new_param->next=head;
    head=new_param;
    //moving id_ptr to the next node 
    id_ptr = id_ptr->next;
	}

	return new_param;
}

PARAM_LIST check_param(PARAM_LIST p) 
{
	
	if (!p) bug("%s:%d check_params received a NULL pointer\n", __FILE__, __LINE__);
	if (!p->id) bug("%s:%d check_params received a pointer to NULL id\n", __FILE__, __LINE__);

	
	if (ty_query(p->type) == TYARRAY || ty_query(p->type) == TYFUNC) {
		error("Parameter type must be a simple type");
	}
	
	PARAM_LIST c = p->next;
	while (c) {
		if (!strcmp(st_get_id_str(p->id), st_get_id_str(c->id))) {
			// ids are identical, return null instead of duplicate
			error("Duplicate parameter name: \"%s\"", st_get_id_str(p->id));
		}
		if (ty_query(c->type) == TYARRAY || ty_query(c->type) == TYFUNC) {
			error("Parameter type must be a simple type");
		}
		c = c->next;
	}
	
	return p;
}

/* This function concatenates two parameter lists together as one.
 * It takes two parameters,both are parameter lists.
 * As an output, it returns a parameter list that includes both of the input parameter lists.
 */
PARAM_LIST concatenate_param_list (PARAM_LIST list1,PARAM_LIST list2)
{
	if (!list1 && !list2) return NULL;	
	if (!list1) return list2;		
	if (!list2) return list1;		


	PARAM_LIST new_list;
	new_list=list1;
	while (new_list->next!=NULL)
	{
		new_list=new_list->next;
	}
	new_list->next=list2;
	return list1;
}

/* This function adds a new node at the end of an index list.
 * It takes two parameters,one is an index list, and the other is atype object.
 * As an output, it returns an index_list with the new node included.
 */
INDEX_LIST concatenate_index_lists (INDEX_LIST list1,TYPE type)
{
	INDEX_LIST ptr, list2;
	
	list2 = (INDEX_LIST) malloc(sizeof(INDEX));
	list2 = create_list_from_type(type);
	
	ptr=list1;
	while (ptr->next)
	{
		ptr = ptr->next;
	}
	ptr->next = list2;
	return list1;

}

/* This function creates the index list for the arrays.
 * It takes one parameter,a type object; which should be a subrange.
 * As an output, it returns an index_list.
 */
INDEX_LIST create_list_from_type(TYPE type)
{
	if (ty_query(type) == TYERROR) return NULL;
	INDEX_LIST index;
	index=(INDEX_LIST) malloc(sizeof(INDEX));
	index->type=type;
	index->next=NULL;
	index->prev=NULL;
	return index;
}


/* This function traverse the linked list of unresolved pointers and resolves them..
 * It takes no parameter and returns nothing.
 * An error message is issued for every unresolved pointer.
 */
void resolve_all_ptr()
{
	int block;
	ST_ID id;
	ST_DR data_rec;

  TYPE_LIST unresolved = LIST_OF_UNRESOLVED_PTRS;
  LIST_OF_UNRESOLVED_PTRS = NULL;
	
	while(unresolved!=NULL)
	{
		ty_query_ptr(unresolved->type, &id);
		data_rec = st_lookup(id,&block);
		if (data_rec == NULL)
		{
			error("Unresolved type name: \"%s\"", st_get_id_str(id));
			unresolved = unresolved->next;
			continue;
		}
		if (data_rec->tag == TYPENAME)
		{
			if(!ty_resolve_ptr(unresolved->type, data_rec->u.typename.type))
				error("Unresolved type name: \"%s\"", st_get_id_str(id));
		}	
		else
		{
			error("Unidentified type tag\n");
		}
		unresolved=unresolved->next;
	}
}

void enter_main_body(){
  b_func_prologue("main");
}

void exit_main_body(){
  b_func_epilogue("main");
}

/* Function to install function/procedure heading into symbol table.
   Also takes the return type(Char, Integer, Void...) and builds the appropriate function type
   based on the DIRECTIVE(External, Forward). This function type is assigned to the new data record. 
   Examples: 
   Procedure scanf; External;
   Function getchar : Char; External;
   Function abc : Integer; Forward;
*/
void install_func_head(ST_ID id, TYPE ret_type, DIRECTIVE dir){
   PARAM_LIST params;
   BOOLEAN check_args;

   /* Creates empty data record */
   ST_DR data_rec = stdr_alloc();

   /* Assign tag as a GDECL */
   data_rec->tag = GDECL;
   /* Set reference parameter to FALSE */
   data_rec->u.decl.is_ref = FALSE;
   /* Set the function name */
   data_rec->u.decl.v.global_func_name = st_get_id_str(id);

   /*If function/procedure is declared as External then Storage Class = EXTERN_SC,
   check_args = FALSE which is in type, so we need to build a function type*/
   if (dir == DIR_EXTERNAL) {      
      data_rec->u.decl.sc = EXTERN_SC;
      data_rec->u.decl.type = ty_build_func(ret_type, params, FALSE);
   }
   /*Else function/procedure is declared as Forward then Storage Class = NO_SC,
   check_args = TRUE which is in type, so we need to build a function type*/
   else if (dir == DIR_FORWARD) {
      data_rec->u.decl.sc = NO_SC;
      data_rec->u.decl.type = ty_build_func(ret_type, params, TRUE);
   }
   else {
      error("How did I get here...I'm in install_func_head()");
   }   

   /* Install into symbol table */
   if (!st_install(id, data_rec)) {
      error("Duplicate forward or external function declaration");
      free(data_rec);
   }

}

/* Function to install a data_rec of TYPE function if not already installed.  Next it enters the local scope of the 
   function/procedure.  Next it installs parameters into symbol table with tag of PDECL. 
   Next it initializes the offset and returns the offset calculated.  
   Example:
   Procedure rst;
   begin
      j := abc;
   end; { rst }

   Function abc : Integer;
   begin
      xyz;
      abc := 18;
      k := 20;
      abc := 19
   end; { abc }

   Two possiblities: 1-> If function name not already in symbol table, then install it as a fresh FDECL
   2-> Already in symbol table (st_lookup() returns a ST_DR).  Only allowable situation is previous installment
   was a GDECL of a function of the same type that is not external(has to forward declaration).  Look at the storage 
   class to see if external or not.  Anything else is semantic error(FDECL is duplicate definition, not a function, function
   but args or return type don't match) */
int prepare_to_enter_func_body(ST_ID id, TYPE ret_type) {
   ST_DR data_rec;
   PARAM_LIST params;
   BOOLEAN check_args;
   TYPE ret_type1;
   int block;
   int init_offset;

   /* Call st_lookup to see if id is previously installed in current block */
   data_rec = st_lookup(id, &block);

   /* If not previously installed then install as new FDECL */
   if (data_rec == NULL) {
      data_rec = stdr_alloc();
      data_rec->tag = FDECL;
      data_rec->u.decl.type = ty_build_func(ret_type, params, FALSE);
      data_rec->u.decl.sc = NO_SC;
      data_rec->u.decl.is_ref = FALSE;
      data_rec->u.decl.v.global_func_name = st_get_id_str(id);

      if (!st_install(id, data_rec)) {
        error("Couldn't install into symbol table inside of enter_func()");
        free(data_rec);
      }
   } 
   else {
      /* Previous installment must be GDECL with same type and NO_SC as storage class */
      if (data_rec->tag != GDECL || data_rec->u.decl.sc != NO_SC) {
        error("Error in enter_func(), no GDECL or no NO_SC");
        return;
      } 
      else {
        /* Check to see if the return type passed in matches the return type you get with the st_lookup */
 	      ret_type1 = ty_query_func(data_rec->u.decl.type, &params, &check_args);

        if (ty_test_equality(ret_type, ret_type1) == TRUE) {
          /*Change tag from GDECL to FDECL */
          data_rec->tag = FDECL;
        }
        else {
          error("Error in enter_func(), return types not equal");
        }
      }
   }

    fi_top++; // increment stack
    func_id_stack[fi_top] = id; //set value

   /* Enter local scope of the function */
   st_enter_block();

   /* Initiialize the formal parameter offset calculation */
   b_init_formal_param_offset();
   
   /* Install parameters into symbol table(from left to right) as new PDECL */
   install_params(params);

   /* Get initial offset */
   init_offset = b_get_local_var_offset();
   //error("in enter_func(), offset is %d ", init_offset);
   if (data_rec->u.decl.type == TYVOID) {
      init_offset -= 8;
   }
   
   return init_offset;
}

/* Function that enters the local scope of the function body, emits code to store formal
   parameters and allocates space for the return value and local vars */
void enter_func_body(ST_ID id, TYPE ret_type, int loc_var_offset) {
   TYPE ret_type1;
   TYPE param_type;
   PARAM_LIST params;
   BOOLEAN check;
   TYPETAG tag;
   TYPETAG param_tag;

   int block;
   ST_DR data_rec;
   long low,high;

   //error("local offset is %d", loc_var_offset);
   /* Enter the function */
   b_func_prologue(st_get_id_str(id));

   /* Query the function to get parameters */
   data_rec = st_lookup(id, &block);
   ret_type1 = ty_query_func(data_rec->u.decl.type, &params, &check);
   /* Get the tag associated with the return type */
   tag = ty_query(ret_type);

   // TODO: Still need local variables section for extra credit



   while (params != NULL) {
      param_tag = ty_query(params->type);
      data_rec = st_lookup(params->id, &block);

      if (param_tag == TYSUBRANGE) { 
         param_type = ty_query_subrange(ret_type1, &low, &high);
         b_store_formal_param(ty_query(param_type));
      }
      else if (data_rec->u.decl.is_ref == TRUE) { //VAR params
         b_store_formal_param(TYPTR);
      } else {
         b_store_formal_param(param_tag);
      }

      params = params->next;
   }

   /* If function not a procedure */
   if (tag != TYVOID) {
      /* Allocate size for return value */
      b_alloc_return_value();
   }

   /* Allocate size for local variables */
   b_alloc_local_vars(loc_var_offset);
}

/* Function that emits code to end a function body & exits scope of function */
void exit_func_body(ST_ID id, TYPE ret_type) {
  TYPETAG tag;
  long low, high;

  /* Get the tag associated with the return type */
  tag = ty_query(ret_type);

  //pops the function id from the global stack;
  fi_top--;

  if (tag == TYSUBRANGE) {
    b_prepare_return(ty_query(ty_query_subrange(ret_type, &low, &high)));
  }
  else {
    b_prepare_return(tag);
  }

  b_func_epilogue(st_get_id_str(id));
  st_exit_block();
}


/* Function to install parameters, used in enter_func() 
   Parameters are installed as PDECL */
// TODO: Still working on it
void install_params(PARAM_LIST list) {
   long low, high;

   while (list != NULL) {
      /* Creates empty data record */
      ST_DR data_rec = stdr_alloc();

      data_rec->tag = PDECL;
      data_rec->u.decl.sc = list->sc;
      data_rec->u.decl.is_ref = list->is_ref;
      data_rec->u.decl.err = list->err;
      
      if (ty_query(list->type) == TYSUBRANGE) {
         data_rec->u.decl.type = ty_query_subrange(list->type, &low, &high);
      }
      else {
         data_rec->u.decl.type = list->type;
      }

      /* If referenced parameter */
      if (list->is_ref == TRUE) {
         data_rec->u.decl.v.offset = b_get_formal_param_offset(TYPTR);
      }
      else {
         data_rec->u.decl.v.offset = b_get_formal_param_offset(data_rec->u.decl.type);
      }

      st_install(list->id, data_rec);
      list = list->next;
   }
}

/************************************************************************
 * Prepend an EXPR onto the front of an EXPR_LIST                       *
 *                                                                      *
 * Return: altered EXPR_LIST list                                       *
 ************************************************************************/
EXPR_LIST expr_prepend(EXPR expr, EXPR_LIST list) {
   EXPR_LIST alt_list;
   alt_list = (EXPR_LIST)malloc(sizeof(EXPR_LIST_NODE));

   alt_list->expr = expr;
   alt_list->next = NULL;

   //check if list is empty
   if (list != NULL) {
      //pushing the list to the end of alt_list
      alt_list->next = list;
   }

   return alt_list;
}

/************************************************************************
 * Reverses a list of EXPRs                                             *
 *                                                                      *
 * Return: reversed EXPR_LIST                                           *
 ************************************************************************/
EXPR_LIST expr_list_reverse(EXPR_LIST list) {
   EXPR_LIST tmp;
   EXPR_LIST prev = NULL;

   while (list != NULL) {
      tmp = list->next;
      list->next = prev;
      prev = list;
      list = tmp;
   }
 
   return prev;
}

/* Deallocates an expression tree.  Subexpressions and other subobjects
   are deallocated recursively, postorder. */
void expr_free(EXPR expr){

    if (expr != NULL){
      expr_free(expr);
      free(expr);
    }
  
}

void expr_list_free(EXPR_LIST list){
  
  if (list != NULL){
    expr_list_free(list);
    free(list);
  }
  
}

/************************************************************************
 * Creates a new (GID, LFUN, LVAR) type                                 *
 *                                                                      *
 * Return: the new node  

   Examples:
   i := 5;   i  would be a id_expr node 
   j := i;   both j and i would be an expr node                         *
 ************************************************************************/
EXPR make_id_expr(ST_ID id) {
   ST_DR data_rec;
   int block;
   EXPR ret;
   ret = (EXPR)malloc(sizeof(EXPR_NODE));
   assert(ret != NULL);

   //look up information for id, error if not found or TYPENAME
   data_rec = st_lookup(id, &block);
   if (data_rec == NULL) {
      error("Undeclared identifier \"%s\" in expression", st_get_id_str(id));
      return make_error_expr();
   } 
   
   if (data_rec->tag == TYPENAME) {
      error("Identifier \"%s\" installed as TYPENAME", st_get_id_str(id));
      return make_error_expr();
   }

   ret->type = data_rec->u.decl.type;
   switch(data_rec->tag) {
      case GDECL:
         ret->tag = GID;
         ret->u.gid = id;
         break;
      case LDECL:
      case PDECL:
         ret->tag = LVAR;
         ret->u.lvar.is_ref = data_rec->u.decl.is_ref;
         ret->u.lvar.link_count = st_get_cur_block() - block;
         ret->u.lvar.offset = data_rec->u.decl.v.offset;
         break;
      case FDECL:
         if (block <= 1) {
            ret->tag = GID;
            ret->u.gid = id;
         }
         else {
            ret->tag = LFUN;
            ret->u.lfun.global_name = data_rec->u.decl.v.global_func_name;
            ret->u.lfun.link_count = st_get_cur_block() - block;
         }
         break;       
      default:
         break;
   }
   return ret;
}

/************************************************************************
 * Creates a new INTCONST node with given type and value               *
 *                                                                      *
 * Return: the new node 
   Example:
   i := 5;  5 would be an intconst expr node                            *
 ************************************************************************/
EXPR make_intconst_expr(long val, TYPE type) {
   EXPR ret;
   ret = (EXPR)malloc(sizeof(EXPR_NODE));
   assert(ret != NULL);
   ret->tag = INTCONST;
   ret->type = type;
   ret->u.intval = val;
   return ret;
}

/************************************************************************
 * Creates a new REALCONST node with TYDOUBLE type and given value      *
 *                                                                      *
 * Return: the new node  
   Example:
   i := 16.01  16.01 would be a realconst expr node                     *
 ************************************************************************/
EXPR make_realconst_expr(double val) {
   EXPR ret;
   ret = (EXPR)malloc(sizeof(EXPR_NODE));
   assert(ret != NULL);
   ret->tag = REALCONST;
   ret->type = ty_build_basic(TYDOUBLE);
   ret->u.realval = val;
   return ret;
}

/************************************************************************
 * Creates a new STRCONST node                                          *
 *                                                                      *
 * Return: the new node                                                 *
 ************************************************************************/
EXPR make_strconst_expr(char *str) {
   EXPR ret;
   ret = (EXPR)malloc(sizeof(EXPR_NODE));
   assert(ret != NULL);
   ret->tag = STRCONST;
   ret->type = ty_build_ptr(ty_build_basic(TYUNSIGNEDCHAR));//(NULL, ty_build_basic(TYUNSIGNEDCHAR));
   ret->u.strval = str;
   return ret;
}  

/************************************************************************
 * Creates a new NULLOP node with given op and TYPE depends on op       *
 *                                                                      *
 * Return: the new node                                                 *
 ************************************************************************/
EXPR make_null_expr(EXPR_NULLOP op) {
   EXPR ret;
   ret = (EXPR)malloc(sizeof(EXPR_NODE));
   assert(ret != NULL);
   ret->tag = NULLOP;
   ret->u.nullop.op = op;

   if (op == NIL_OP) {
      ret->type = ty_build_basic(TYVOID);
   }
   else if (op == NULL_EOF_OP || op == NULL_EOLN_OP) {
      ret->type = ty_build_basic(TYSIGNEDCHAR);
   }
   return ret;
}

/************************************************************************
 * Creates a new ERROR node with type ty_build_basic(TYERROR).          *
 * Returns new node                                                     *
 ************************************************************************/
EXPR make_error_expr() {
   EXPR ret;
   ret = (EXPR)malloc(sizeof(EXPR_NODE));
   assert(ret != NULL);
   ret->tag = ERROR;
   ret->type = ty_build_basic(TYERROR);
   return ret;
}

/************************************************************************
 * Function checks to see if EXPR is l-value, can be done by looking    *
 * at tag and other information                                         *
 *                                                                      *
 * Return: Boolean value, TRUE if l-value                               *
 ************************************************************************/
BOOLEAN is_lval(EXPR expr) {
   //fist check tag of expr
   if (expr->tag == LVAR) { //all LVARs are l-val
      return TRUE;
   }
   else if (expr->tag == GID) {
      if (ty_query(expr->type) == TYFUNC || ty_query(expr->type) == TYERROR) { //l-val only if data type
         return FALSE;
      }
      else {
         return TRUE;
      }
   }
   else if (expr->tag == UNOP) {
      if (expr->u.unop.op == INDIR_OP) { //l-val if indirection op
         return TRUE;
      }
   }
   else {
      return FALSE;
   }
}

/************************************************************************
 * Creates a new EXPR node of type FCALL                                *
 *                                                                      *
 * Return: the new node                                                 *
 ************************************************************************/
EXPR make_fcall_expr(EXPR func, EXPR_LIST args) {
   BOOLEAN check;
   PARAM_LIST param;
   TYPE ret_type;
   TYPETAG expr_type;
   EXPR_LIST aCopy = args; //copy of arg list for adding deref/convert

   //check that func is of function type
   if (ty_query(func->type) != TYFUNC) {
      error("not functiontype");
      return make_error_expr();
   }

   //check check_args flag
   ret_type = ty_query_func(func->type, &param, &check);
   
   if (!check) { //likely an external function
      //make all arguments r-values and unary-convert         
      while (aCopy != NULL) {
         if (is_lval(aCopy->expr)) { //create a deref node
            EXPR derefNode = make_un_expr(DEREF_OP, aCopy->expr);
            aCopy->expr = derefNode; //expr now points to deref node
         }

         //perform conversions
         expr_type = ty_query(aCopy->expr->type);
         if (expr_type == TYSIGNEDCHAR || expr_type == TYUNSIGNEDCHAR) {
            EXPR convertedNode = make_un_expr(CONVERT_OP, aCopy->expr);
            convertedNode->type = ty_build_basic(TYSIGNEDLONGINT);
            aCopy->expr = convertedNode;//expr now points to convert node
         }
         else if (expr_type == TYFLOAT) {
            EXPR convertedNode = make_un_expr(CONVERT_OP, aCopy->expr);
            convertedNode->type = ty_build_basic(TYDOUBLE);
            aCopy->expr = convertedNode;//expr now points to convert node
         }
         
         aCopy = aCopy->next;
      }
   }
   else { //check_args is true
      while (aCopy != NULL && param != NULL) {
         if (param->is_ref == TRUE) { //VAR parameter
            //actual arg must be an l-value whose type 
            //matches the type of the formal param
            if(ty_test_equality(aCopy->expr->type, param->type) == FALSE) {
               error("types not equal");
               return make_error_expr();
            }
         }
         else {
            //make actual arg an r-value
            if (is_lval(aCopy->expr) == TRUE) {
               EXPR derefNode = make_un_expr(DEREF_OP, aCopy->expr);
               aCopy->expr = derefNode; //expr now points to convert node
            }
      
            //perfrom conversions
            expr_type = ty_query(aCopy->expr->type);
            if (expr_type == TYSIGNEDCHAR || expr_type == TYUNSIGNEDCHAR) {
               EXPR convertedNode = make_un_expr(CONVERT_OP, aCopy->expr);
               convertedNode->type = ty_build_basic(TYSIGNEDLONGINT);
               aCopy->expr = convertedNode;
            }
            else if (expr_type == TYFLOAT) {
               EXPR convertedNode = make_un_expr(CONVERT_OP, aCopy->expr);
               convertedNode->type = ty_build_basic(TYDOUBLE);
               aCopy->expr = convertedNode;
            }
         }

         //try to convert to type of formal parameter

        aCopy = aCopy->next;
        param = param->next;
      }
   }
   //check number formal args and param args and if differ then error

   //create an fcall node
   EXPR ret;
   ret = (EXPR)malloc(sizeof(EXPR_NODE));
   assert(ret != NULL);
   ret->tag = FCALL;
   ret->type = ret_type;
   ret->u.fcall.args = args;
   ret->u.fcall.function = func;

   return ret;
}

/************************************************************************
 * Creates a new UNOP node, with op and sub                             *
 * Also creates DEREF nodes and conversions if necessary                *
 *                                                                      *
 * Return: the new node                                                 *
 ************************************************************************/
EXPR make_un_expr(EXPR_UNOP op, EXPR sub) {
   /*new node variables & initial assignments*/
   EXPR ret;
   ret = (EXPR)malloc(sizeof(EXPR_NODE));
   assert(ret != NULL);
   ret->tag = UNOP;
   ret->type = sub->type;
   ret->u.unop.op = op;
   ret->u.unop.operand = sub;
   /*querying variables*/
   TYPETAG sub_tag = ty_query(sub->type);
   ST_ID id;
   TYPE base_type,next;
   long low, high; 

   //error("op is %d", op);
   if (op == DEREF_OP) {
      return ret;
   }
   
   if (op == ADDRESS_OP || op == NEW_OP) { //expect l-values
      if (is_lval(sub) == FALSE) {
         return make_error_expr();
      }
   }
   else { //expect r-values
      //if op expects an r-value and sub is an l-value, add a DEREF node
      if (is_lval(sub) == TRUE) {
         ret->u.unop.operand = make_un_expr(DEREF_OP,sub);
      }
   }

   sub_tag = ty_query(sub->type);
   //subexpression is unary-converted
   if (is_lval(sub) == FALSE) {
      if (sub_tag == TYFLOAT) {
         EXPR convertedNode = make_un_expr(CONVERT_OP, sub);
         convertedNode->type = ty_build_basic(TYDOUBLE);
         ret->u.unop.operand = convertedNode;
      }
      else if (sub_tag == TYSUBRANGE) {
         EXPR convertedNode = make_un_expr(CONVERT_OP, sub);
         base_type = ty_query_subrange(sub->type, &low, &high);
         convertedNode->type = base_type;
         ret->u.unop.operand = convertedNode;
      }
   }

   sub_tag = ty_query(sub->type);
   //switch statement on op for error checking
   switch (op) {
      case CONVERT_OP:
         break;
      case DEREF_OP:
         break;
      case NEG_OP:
         //must be of type TYSIGNEDLONGINT, TYDOUBLE
         if (sub_tag != TYSIGNEDLONGINT &&  sub_tag != TYDOUBLE) {
            error("Incorrect type in NEG_OP");
            return make_error_expr();
         }
         break;
      case ORD_OP:
         //must be CHAR
         if (sub_tag != TYUNSIGNEDCHAR && sub_tag != TYSIGNEDCHAR) {
            error("Incorrect type in ORD_OP");
            return make_error_expr();
         }

         //since it returns int...I think the type needs to be changed
         ret->type = ty_build_basic(TYSIGNEDLONGINT);
         break;
      case CHR_OP:
         //converts byte value to char value...check type
         if (sub_tag != TYSIGNEDLONGINT && sub_tag != TYDOUBLE ) {
            error("Incorrect type in CHR_OP");
            return make_error_expr();
         }
   
         //returns char so updated type
         ret->type = ty_build_basic(TYUNSIGNEDCHAR);
         break;
      case SUCC_OP:
         //check type, must be ordinal type
         if (sub_tag != TYSIGNEDLONGINT && sub_tag != TYDOUBLE && sub_tag != TYUNSIGNEDCHAR) {
            error("Incorrect type in SUCC_OP");
            return make_error_expr();
         }
         break;
      case PRED_OP:
         if (sub_tag != TYSIGNEDLONGINT && sub_tag != TYDOUBLE && sub_tag != TYUNSIGNEDCHAR) {
            error("Incorrect type in PRED_OP");
            return make_error_expr();
         }
         break;
      case PLUS_OP:
         //check type
         if (sub_tag != TYSIGNEDLONGINT && sub_tag != TYDOUBLE) {
            error("Incorrect type in UPLUS_OP");
            return make_error_expr();
         }
         break; 
      case INDIR_OP:
         //returns a pointer, not sure if any other errors/checks
         ret->type = ty_query_ptr(sub->type, &id);//ty_query_ptr(sub->type, &id, &next);
      default:
         break;
   }
   return ret;
}
/* gram: expression (1st production), simple_expression (2nd production; 3rd, 4th, and 5th productions are optional), term (2nd production; 3rd is optional), standard_functions (3rd production -- if 2 arguments (optional))
   Returns a new BINOP node based on the op and the two subexpressions:
   1. If op expects r-value(s), then DEREF nodes are added as needed (the only
      binary op that expects an l-value is assignment, which expects an
      l-value on the left and an r-value on the right).
   2. Both left and right are unary-converted as above.
   3. Both left and right are binary converted (the only binary conversion
      requiring a convert node is long int->double).
   4. Currently, no binary operations are allowed on string constants except
      = and <> (EQ and NE), so if both subexpressions are string constants,
      they are converted to chars if possible (only if they are length 1).
      If one argument is a string constant and the other is of type char,
      then also try to convert the string constant.
   5. The rest of the behavior depends on the op (switch statement) and the
      typetags of the subexpressions, including error-checking and
      constant-folding (for example, arithmetic ops can't act on nonnumeric
      types).
*/

/************************************************************************
 * Creates a new BINOP node with op and expr left, right                *
 * Also creates DEREF nodes and conversions if necessary                *
 *                                                                      *
 * Return: the new node                                                 *
 ************************************************************************/
EXPR make_bin_expr(EXPR_BINOP op, EXPR left, EXPR right) {
   TYPETAG left_type = ty_query(left->type);
   TYPETAG right_type = ty_query(right->type);
   long low, high;
   TYPE base_type;

   if (left->tag == ERROR || right->tag == ERROR) {
      return make_error_expr();
   }

   /*new node variables*/
   EXPR ret = (EXPR)malloc(sizeof(EXPR_NODE));
   assert(ret != NULL);

   ret->tag = BINOP;
   ret->u.binop.op = op;
   ret->u.binop.left = left;//initially
   ret->u.binop.right = right;//initially
   ret->type = left->type; //initially

   if (op == ASSIGN_OP) {
      if (is_lval(left) == FALSE) {
         error("Assignment requires l-value on the left");          
         return make_error_expr();
      }
      if (right_type == TYVOID || right_type == TYFUNC || right_type == TYERROR) {
         error("Cannot convert between nondata types");
         return make_error_expr();
      }
      else if ((left_type == TYUNSIGNEDLONGINT || left_type == TYSIGNEDLONGINT) && (right_type == TYFLOAT || right_type == TYDOUBLE || right_type == TYUNSIGNEDCHAR)) {
         error("Illegal conversion");
         return make_error_expr();
      }
      // else if (left_type == TYSIGNEDCHAR && (right_type == TYFLOAT || right_type == TYDOUBLE || right_type == TYSIGNEDLONGINT)) {
      //    error("Illegal conversion2");
      //    return make_error_expr();
      // }
      /*else if (left_type == TYDOUBLE || left_type == TYUNSIGNEDLONGINT || left_type == TYSIGNEDLONGINT || left_type == TYFLOAT) {
         if (right_type !=  TYUNSIGNEDLONGINT && right_type != TYFLOAT && right_type != TYSIGNEDLONGINT && right_type != TYDOUBLE) {
            error("Illegal conversion");
            return make_error_expr();
         }
      }
      else if (left_type == TYUNSIGNEDCHAR || left_type == TYSIGNEDCHAR) {
         if (right->tag == STRCONST) {
            ret->u.binop.right = make_intconst_expr(right->u.strval[0], ty_build_basic(TYSIGNEDLONGINT));
         }
         else {
            error("Illegal conversion");
            return make_error_expr();
         }
      }  
      else if (right_type != left_type) {
         error("Illegal conversion");
         return make_error_expr();
      }*/
   }


   //if op expects r-values, insert DEREF nodes if
   if (is_lval(left) == TRUE) {
      if (op != ASSIGN_OP) {
         EXPR derefNode = make_un_expr(DEREF_OP, left);
         ret->u.binop.left = derefNode; //left expr now points to deref
      }
   }

   if (is_lval(right) == TRUE) {
      EXPR derefNode = make_un_expr(DEREF_OP, right);
      ret->u.binop.right = derefNode; //right expr now points to deref
   }

   //perform unary conversions on left and right
   left_type = ty_query(left->type);
   right_type = ty_query(right->type);
   if (is_lval(left) == FALSE) {
      if (left_type == TYFLOAT && right_type == TYDOUBLE) {
         EXPR convertedNode = make_un_expr(CONVERT_OP, left);
         convertedNode->type = ty_build_basic(TYDOUBLE);
         ret->u.binop.left = convertedNode;
      }
      else if (right_type == TYFLOAT && left_type == TYDOUBLE) {
         EXPR convertedNode = make_un_expr(CONVERT_OP, right);
         convertedNode->type = ty_build_basic(TYDOUBLE);
         ret->u.binop.right = convertedNode;
      }
      else if (left_type == TYSUBRANGE) {
         EXPR convertedNode = make_un_expr(CONVERT_OP, left);
         base_type = ty_query_subrange(left->type, &low, &high);
         convertedNode->type = base_type;
         ret->u.binop.left = convertedNode;
      }
      else if (right_type == TYSUBRANGE) {
         EXPR convertedNode = make_un_expr(CONVERT_OP, right);
         base_type = ty_query_subrange(right->type, &low, &high);
         convertedNode->type = base_type;
         ret->u.binop.right = convertedNode;
      }
   }

   //perform binary conversions on left and right
   left_type = ty_query(ret->u.binop.left->type);
   right_type = ty_query(ret->u.binop.right->type);

   if (left_type == TYSIGNEDLONGINT && right_type == TYDOUBLE) {
      EXPR convertedNode = make_un_expr(CONVERT_OP, left);
      convertedNode->type = ty_build_basic(TYDOUBLE);
      ret->u.binop.left = convertedNode;
   }
   else if (right_type == TYSIGNEDLONGINT && left_type == TYDOUBLE) {
      EXPR convertedNode = make_un_expr(CONVERT_OP, right);
      convertedNode->type = ty_build_basic(TYDOUBLE);
      ret->u.binop.right = convertedNode;
   }

   left_type = ty_query(ret->u.binop.left->type);
   right_type = ty_query(ret->u.binop.right->type);

   switch(op) {
      case ADD_OP:
      case SUB_OP:
      case MUL_OP:
      case REALDIV_OP:
      case MOD_OP: //check the types, only numbers
         if ((right_type != TYDOUBLE && right_type != TYSIGNEDLONGINT) || (left_type != TYDOUBLE && left_type != TYSIGNEDLONGINT)) {
            error("Nonnumerical type argument(s) to arithmetic operation");
            printf("error here\n");
            return make_error_expr();
         }
         else if (right_type == TYSIGNEDLONGINT && left_type == TYSIGNEDLONGINT) {
            ret->type = ty_build_basic(TYSIGNEDLONGINT);
         }
         else {
            ret->type = ty_build_basic(TYDOUBLE);
         }
         break;
      case DIV_OP:
         ret->type = ty_build_basic(TYSIGNEDLONGINT);
         break;
      case LESS_OP:
          //error("in less than op");
          /*Type check*/
          if((right_type != TYSIGNEDLONGINT && right_type != TYFLOAT && right_type != TYDOUBLE && right_type != TYUNSIGNEDCHAR && right_type != TYSIGNEDCHAR) && (left_type != TYSIGNEDLONGINT && left_type != TYFLOAT && left_type != TYDOUBLE && left_type != TYUNSIGNEDCHAR && left_type != TYSIGNEDCHAR))
          {
            error("Illegal type arguments to comparison operator");
            return make_error_expr();
          }
          else if(((right_type != TYSIGNEDLONGINT || right_type != TYFLOAT || right_type != TYDOUBLE || right_type != TYUNSIGNEDCHAR || right_type != TYSIGNEDCHAR) || (left_type != TYSIGNEDLONGINT || left_type != TYFLOAT || left_type != TYDOUBLE || left_type != TYUNSIGNEDCHAR || left_type != TYSIGNEDCHAR)))
          {
            if(right_type != left_type)
            {
              error("Incompatible type arguments to comparison operator");
              return make_error_expr();
            }
          }
          /*If the left or right arguments are chars, promote*/
          if (right_type == TYSIGNEDCHAR || right_type == TYUNSIGNEDCHAR) {
            EXPR convertedNode = make_un_expr(CONVERT_OP, right);
            convertedNode->type = ty_build_basic(TYSIGNEDLONGINT);
            ret->u.binop.right = convertedNode;
         }
         else if (left_type == TYSIGNEDCHAR || left_type == TYUNSIGNEDCHAR) {
            EXPR convertedNode = make_un_expr(CONVERT_OP, left);
            convertedNode->type = ty_build_basic(TYSIGNEDLONGINT);
            ret->u.binop.left = convertedNode;
         } 
         ret->type = ty_build_basic(TYSIGNEDLONGINT);
          break; 
      case EQ_OP: break;
      case NE_OP:
          break;
      case GE_OP:
          break;
      case GREATER_OP: 
          //error("In greater than op");
          break;
      case LE_OP:
         //type check
         //convert
         //error("in <= op");
         if (right_type == TYSIGNEDCHAR || right_type == TYUNSIGNEDCHAR) {
            EXPR convertedNode = make_un_expr(CONVERT_OP, right);
            convertedNode->type = ty_build_basic(TYSIGNEDLONGINT);
            ret->u.binop.right = convertedNode;
         }
         else if (left_type == TYSIGNEDCHAR || left_type == TYUNSIGNEDCHAR) {
            EXPR convertedNode = make_un_expr(CONVERT_OP, left);
            convertedNode->type = ty_build_basic(TYSIGNEDLONGINT);
            ret->u.binop.left = convertedNode;
         } 
         ret->type = ty_build_basic(TYSIGNEDLONGINT);       
         break;
      case ASSIGN_OP:
         //check for illegal conversions

         break;
      default:
         break;
   }
   return ret;
}
/* gram: assignment_or_call_statement
   If lhs is a simple identifier, then id is the corresponding ST_ID.
   Case 1 -- rhs is non-NULL: Then this is probably an assignment statement --
      returns a new BINOP with tag ASSIGN_OP and lhs and rhs as operands.
      EXCEPTION: if id is the id of the current function (the one whose body
      we are in), then this is a return value assignment; checks that the
      function has non-void return type, then returns a new UNOP with type
      the return type of the function, and op SET_RETURN_OP.
   Case 2 -- rhs is NULL: Then this is not an assignment and id is ignored.
      If lhs is either New or Dispose, then this is the entire expression
      and so just return lhs.  Otherwise the behavior depends on the lhs tag:
      a) If GID or LFUN, then check that lhs is a Pascal procedure
         (else error), whence this is a procedure call without arguments;
         return a new FCALL node.
      b) If FCALL, then this should be a procedure call (with arguments).
         Check that the type (the return type of the function) tag is void;
   else error (a Pascal function call cannot stand alone as a
   statement).  If ok, then return the FCALL node.
      c) Any other tag is an error.
*/
EXPR check_assign_or_proc_call(EXPR lhs, ST_ID id, EXPR rhs) {

  /*if(rhs!=null){
    char *a->*st_get_id_str(id);
    if(){
    }//end if
    else{
    make_bin_expr(ASSIGN_OP, lhs, rhs);
    }//end else
  else{
    if(lhs.tag == New || lhs.tag == Dispose)
      return lhs;*/
   
   PARAM_LIST params;
   BOOLEAN check;

   //case1, if rhs non null, then return binop node with assign_op
   if (rhs != NULL) {
      //exception if id is id of current function
      if (id == func_id_stack[fi_top] && fi_top >= 0) {
         if (ty_query(ty_query_func(lhs->type, &params, &check)) != TYVOID) {
            //return type is nonvoid
            EXPR ret = make_un_expr(SET_RETURN_OP, rhs);
            ret->type = ty_query_func(lhs->type, &params, &check);
            return ret;
         }
         else {
            error("Function type is TYVOID\n");
            return make_error_expr();
         }
      }
      else {
         //returns binop with ASSIGN_OP
         EXPR ret = make_bin_expr(ASSIGN_OP, lhs, rhs);
         return ret;
      }
   }
   
   //case2, rhs is NULL
   else {
      if (lhs->tag == UNOP) {
         if (lhs->u.unop.op == NEW_OP || lhs->u.unop.op == DISPOSE_OP) {
            return lhs;
         }
      }
   
      if (lhs->tag == GID || lhs->tag == LFUN) {
         //check that lhs is a pascal procedure
         if (ty_query(lhs->type) == TYFUNC) {
            EXPR ret = make_fcall_expr(lhs, NULL);
            return ret;
         }
         else {
            error("Expected procedure name, saw data");
            return make_error_expr();      
         }
      }
      else if (lhs->tag == FCALL) {
         //check the return type is void
         if (ty_query(lhs->type) == TYVOID) {
            return lhs;
         }
         else {
            error("Procedure call to a nonvoid type");
            return make_error_expr();
         }
      }
      else { //any other tag is error
         error("Procedure call expected");
         return make_error_expr();
      }
   }
}   

/************************************************************************
 * Checks that both lo and hi are INTCONSTS of the same type, also      *
 * checks that the second index is larger than the first                * 
 * Previous check_subrange function took in long parameters             *
 *                                                                      *
 * Return: new subrange type                                            *
 ************************************************************************/
TYPE check_subrange(EXPR lo, EXPR hi) {
   long low, high;

   // check if INTCONSTS
   if (lo->tag != INTCONST || hi->tag != INTCONST) {
      error("Subrange indexs are not Integers");
      return ty_build_basic(TYERROR);
   }

   // create new subrange type if lo < hi
   low = lo->u.intval;
   high = hi->u.intval;

   if (low < high) {
      return ty_build_subrange(ty_build_basic(TYSIGNEDLONGINT), low, high);
   }
   
   error("Empty subrange in array index");
   error("Illegal index type (ignored)");

   return ty_build_basic(TYERROR);
}
