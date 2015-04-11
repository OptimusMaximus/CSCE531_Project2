/****************************************************************/
/*																*/
/*	CSCE531 - "Pascal" and "C" Compilers						*/
/*																*/
/*	--tree.c--													*/
/*																*/
/*	This File Contains routines that support the				*/
/*	"Tree Module".												*/
/*																*/
/*	Konstantin Rubin											*/
/*  Maximus Brandel												*/
/*	Ibrahim Elsayed												*/
/****************************************************************/

#include <stdlib.h>
#include "tree.h"
#include "types.h"
#include <stdio.h>

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
	new_data_rec= stdr_alloc();

	//Fill the fields of the new symbol table data record
	new_data_rec->tag=TYPENAME;
	new_data_rec->u.typename.type=new_type;

	// Install the new data record in the symbol table
	if (!st_install(id,new_data_rec)) {
		// Issue an error message 
		error("This Type name is already installed");
	}
}
/* Install a global variable declaration into the symbol table */
void create_gdecl(VAR_ID_LIST list,TYPE type)
{
    //checking if the variable has a type 
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
			//writing an error message
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
TYPE check_subrange(long a, long b) {
	if (a < b) {
		return ty_build_subrange(ty_build_basic(TYSIGNEDLONGINT), a, b);
	}
	//error("Invalid subrange %i .. %i", a, b);
	error("Empty subrange in array index");
	error("Illegal index type (ignored)");
	//return NULL;
	return ty_build_basic(TYERROR);
}

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

/* Two possiblities: 1-> If function name not already in symbol table, then install it as a fresh FDECL
2-> Already in symbol table (st_lookup() returns a ST_DR).  Only allowable situation is previous installment
was a GDECL of a function of the same type that is not external(has to forward declaration).  Look at the storage 
class to see if external or not.  Anything else is semantic error(FDECL is duplicate definition, not a function, function
but args or return type don't match) */
int enter_func(ST_ID id, TYPE ret_type) {
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

   // fi_top++; // increment stack
   // func_id_stack[fi_top] = id; //set value

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

/* Emits code to store formal
   parameters and allocates space for the return value and local vars */
void enter_func_body(ST_ID id, TYPE ret_type, int loc_var_offset) {
   TYPE ret_type1;
   TYPE param_type;
   PARAM_LIST params;
   BOOLEAN check;
   TYPETAG func_tag;
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
   func_tag = ty_query(ret_type);

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
   if (func_tag != TYVOID) {
      /* Allocate size for return value */
      b_alloc_return_value();
   }

   /* Allocate size for local variables */
   b_alloc_local_vars(loc_var_offset);
}

/* Emits code to end a function body & exits scope of function */
void exit_func_body(ST_ID id, TYPE type) {
  TYPE func_type;
  PARAM_LIST params;
  BOOLEAN check;
  TYPETAG func_tag;
  long low,high;

  func_tag = ty_query(type);

  //pops the function id from the global stack;
  //fi_top--;

  if (func_tag == TYSUBRANGE) {
    b_prepare_return(ty_query(ty_query_subrange(type, &low, &high)));
  }
  else {
    b_prepare_return(func_tag);
  }

  b_func_epilogue(st_get_id_str(id));
  st_exit_block();
}


/* Function to install parameters, used in enter_func() 
   Parameters are installed as PDECL */
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