/****************************************************************/
/*																*/
/*	CSCE531 - "Pascal" and "C" Compilers						*/
/*																*/
/*	--encode.c--												*/
/*																*/
/*	This File Contains routines that support the				*/
/*	"Encode Module".											*/
/*																*/
/*	Maximus Brandel												*/
/*  Konstantin Rubin											*/
/*	Ibrahim Elsayed												*/
/****************************************************************/

#include <stdlib.h>
#include "defs.h"
#include "types.h"
#include "symtab.h"
#include "message.h"
#include "backend-x86.h"
#include "encode.h"

void declare_var(VAR_ID_LIST list_id, TYPE type){
	/* Return if type tag is TYERROR OR TYFUNC */
	if (ty_query(type) == TYERROR || ty_query(type) == TYFUNC) return;

	/* While list_id != NULL */
	while(list_id){
		ST_ID st_id = list_id->id;	
		/* Get the id from the Symbol Table */
		char *id = st_get_id_str(st_id);
		/* Get the size and alignment of the type */
		unsigned int size = get_size(type);
		int alignment = get_align(type);

		if (size != 0 && alignment != 0){
			/* Call backend functions */
			/* Declare variable*/
			b_global_decl(id, alignment, size);
			/* Allocate memory for the variable */
			b_skip(size);
		}else
			bug("Something messed up in declare_var");
		/* Go to next item in list */	
		list_id = list_id->next;
	}
}

unsigned int get_size(TYPE type){

    /* Get the TYPETAG from ty_query */
    TYPETAG tag;
    tag = ty_query(type);

    /* For arrays */
    INDEX_LIST indices;
    unsigned int array_size;
    TYPE temp_type = type;

    /* For subrange */
    long low, high;

    switch(tag){
    	case TYUNSIGNEDCHAR:
    		return 1;//sizeof(unsigned char);
    	case TYSIGNEDCHAR:
    		return 1;//sizeof(signed char);
    	case TYUNSIGNEDSHORTINT:
    		return 2;//sizeof(unsigned short int);
    	case TYSIGNEDSHORTINT:
    		return 2;//sizeof(signed short int);
    	case TYUNSIGNEDINT:
    		return 4;//sizeof(unsigned int);
    	case TYSIGNEDINT:
    		return 4;//sizeof(signed int);
    	case TYUNSIGNEDLONGINT:
    		return 4;//sizeof(unsigned long int);
    	case TYSIGNEDLONGINT:
    		return 4;//sizeof(signed long int);
    	case TYFLOAT:
    		return 4;//sizeof(float);
    	case TYDOUBLE:
    		return 8;//sizeof(double);
    	case TYLONGDOUBLE:
    		return 8;//sizeof(long double);
    	case TYARRAY:
    		/* Get array size recursively */
    		array_size = get_size(ty_query_array(type, &indices));
    		/* While indices != NULL */
			while (indices) { 
				/* Get the low and high values */
				ty_query_subrange(indices->type,&low,&high);
				/* Calculate new array_size */
				array_size *= high - low + 1;
				/* Go to next indice */		
				indices = indices->next;
			}		
			return array_size;	
    	case TYSUBRANGE:
    		return get_size(ty_query_subrange(type, &low, &high));
    	case TYPTR:
    		return 4;//sizeof(char *);
    	// case TYVOID:
    	// 	return 0;
    	// case TYSTRUCT:
    	// 	return 0;
    	// case TYUNION:
    	// 	return 0;
    	// case TYENUM:
    	// 	return 0;
    	// case TYSET:
    	// 	return 0;
    	//case TYFUNC:
    	// 	return -98;
    	// case TYBITFIELD:
    	// 	return 0;
    	//case TYERROR:
    	//	return -99;
    	default:
    		bug("Illegal type tag %d in get_size", tag);
    		return 0;
    }
}

int get_align(TYPE type){

    /* Get the TYPETAG from ty_query */
    TYPETAG tag;
    tag = ty_query(type);

    /* For arrays */
    INDEX_LIST indices;

    /* For subrange */
    long low, high;

    switch(tag){
    	case TYUNSIGNEDCHAR:
    		return 1;//sizeof(unsigned char);
    	case TYSIGNEDCHAR:
    		return 1;//sizeof(signed char);
    	case TYUNSIGNEDSHORTINT:
    		return 2;//sizeof(unsigned short int);
    	case TYSIGNEDSHORTINT:
    		return 2;//sizeof(signed short int);
    	case TYUNSIGNEDINT:
    		return 4;//sizeof(unsigned int);
    	case TYSIGNEDINT:
    		return 4;//sizeof(signed int);
    	case TYUNSIGNEDLONGINT:
    		return 4;//sizeof(unsigned long int);
    	case TYSIGNEDLONGINT:
    		return 4;//sizeof(signed long int);
    	case TYFLOAT:
    		return 4;//sizeof(float);
    	case TYDOUBLE:
    		return 8;//sizeof(double);
    	case TYLONGDOUBLE:
    		return 8;//sizeof(long double);
    	case TYARRAY:
    		return get_align(ty_query_array(type, &indices));
    	case TYSUBRANGE:
    		return get_align(ty_query_subrange(type, &low, &high));
    	case TYPTR:
    	 	return 4;//sizeof(char *);
    	// case TYVOID:
    	// 	return 0;
    	// case TYSTRUCT:
    	// 	return 0;
    	// case TYUNION:
    	// 	return 0;
    	// case TYENUM:
    	// 	return 0;
    	// case TYSET:
    	// 	return 0;
    	//case TYFUNC:
    	// 	return -98;
    	// case TYBITFIELD:
    	// 	return 0;
    	//case TYERROR:
    	// 	return -99;
    	default:
    		bug("Illegal type tag %d in get_align", tag);
    		return 0;
    }
}

void encode_expr(EXPR expr)
{    
    if (expr == NULL)
        bug("Expression is null ");
	error("expr->tag = %d ", expr->tag);
	
/*	char *temp = st_get_id_str(expr->u.gid);
	printf("var %s", temp);*/
    switch (expr->tag) {
        case LFUN: //expr->tag = 4
        case ERROR: break; //expr->tag = 10
        case INTCONST:  //expr->tag = 0
            b_push_const_int(expr->u.intval);
            if(ty_query(expr->type) == TYUNSIGNEDCHAR)
                b_convert(TYSIGNEDLONGINT, TYUNSIGNEDCHAR);
            if(ty_query(expr->type) == TYSIGNEDCHAR)
                b_convert(TYSIGNEDLONGINT, TYSIGNEDCHAR);
            break;
        case REALCONST:   //expr->tag = 1   
            b_push_const_double(expr->u.realval);
            break;
        case STRCONST: //expr->tag = 2
            b_push_const_string(expr->u.strval);
            break;
        case GID: //expr->tag = 3
            b_push_ext_addr(st_get_id_str(expr->u.gid));
            break;
        case LVAR:     //expr->tag = 4 
            b_push_loc_addr(0);
            int i = 0;
            for (i = 0; i < expr->u.lvar.link_count; i++) {
                b_offset(FUNC_LINK_OFFSET);
                b_deref(TYPTR);
            }
            b_offset(expr->u.lvar.offset);
            if (expr->u.lvar.is_ref == TRUE)
                b_deref(TYPTR);
            break;
        case NULLOP:   //expr->tag = 6    
            b_push_const_int(0);
            break;   
        case UNOP:  //expr->tag = 7       
            encode_unop(expr->u.unop.op, expr);
            break;
        case BINOP://expr->tag = 8
            encode_binop(expr->u.binop.op, expr);
            break;
        case FCALL:  //expr->tag = 9      
            encode_fcall(expr->u.fcall.function, expr->u.fcall.args);
            break;
    }
}
void encode_unop(EXPR_UNOP op, EXPR expr)
{
    long low, high;
    TYPE baseT;
    TYPETAG tag, rval_tag;
    ST_ID id;
    TYPE type, base_type;
    BOOLEAN converted_to_int;

	error("encode_unop op = %d ", op);

    encode_expr(expr->u.unop.operand);

    converted_to_int = FALSE;
    tag = ty_query(expr->u.unop.operand->type);
    rval_tag = ty_query(expr->type);
	
	
    switch(op) {
        case INDIR_OP:
        case PLUS_OP: break;
        case CONVERT_OP:      
            if(tag==TYSUBRANGE) { 
                base_type = ty_query_subrange(expr->u.unop.operand->type, &low, &high);
                b_convert(TYSUBRANGE, ty_query(base_type));
            } 
            else if(tag==TYPTR) { 

            } 
            else
                b_convert(tag, rval_tag);
            break;
         case NEG_OP:   
            b_negate(tag); 
            break;
         case ORD_OP:
            if(tag==TYUNSIGNEDCHAR)
                b_convert(tag, TYSIGNEDLONGINT);
            break;
         case CHR_OP:
            if(tag==TYSIGNEDLONGINT) 
                b_convert(tag, TYUNSIGNEDCHAR);
            break;
         case SUCC_OP:   
            if(tag!=TYSIGNEDLONGINT) {
                b_convert(tag,TYSIGNEDLONGINT);
                converted_to_int = TRUE;
            }
            b_push_const_int(1);
            b_arith_rel_op(B_ADD, TYSIGNEDLONGINT);
            if(converted_to_int == TRUE) 
                b_convert(TYSIGNEDLONGINT,tag);
            break;
        case PRED_OP:
            if(tag != TYSIGNEDLONGINT) {
                b_convert(tag,TYSIGNEDLONGINT);
                converted_to_int = TRUE;
            }

            b_push_const_int(-1);
            b_arith_rel_op(B_ADD, TYSIGNEDLONGINT);

            if(converted_to_int == TRUE)
                b_convert(TYSIGNEDLONGINT, tag);
            break;
        case NEW_OP:       
            b_alloc_arglist(4);
            //b_push_const_int(get_type_size(ty_query_ptr(expr->u.unop.operand->type, &id, &type)));
            //get_type_size function does not exist
            b_push_const_int(get_size(ty_query_ptr(expr->u.unop.operand->type, &id)));//, &type)));
            b_load_arg(TYUNSIGNEDINT);
            b_funcall_by_name("malloc", TYPTR);
            b_assign(TYPTR);
            b_pop();
            break;
        case DISPOSE_OP:   
            b_load_arg(TYPTR);
            b_funcall_by_name("free", TYVOID);
            break;
        case DEREF_OP:     
            b_deref(tag);
            break;
        case SET_RETURN_OP: 
            b_set_return(ty_query(expr->u.unop.operand->type));
            break;
    }
}

void encode_binop(EXPR_BINOP out, EXPR expr)
{
  TYPETAG type_tag;
  TYPETAG left_type_tag, right_type_tag;
  error("encode_binop out = %d", out);
  encode_expr(expr->u.binop.left);
  encode_expr(expr->u.binop.right);
  type_tag = ty_query(expr->type);
  left_type_tag = ty_query(expr->u.binop.left->type);
  right_type_tag = ty_query(expr->u.binop.right->type);
  
  switch (out) {
    case SYMDIFF_OP:
    case OR_OP:
    case XOR_OP:
    case AND_OP:  break;
    case ADD_OP:  b_arith_rel_op(B_ADD, type_tag); break;

    case SUB_OP: b_arith_rel_op(B_SUB, type_tag); break;

    case MUL_OP: b_arith_rel_op(B_MULT, type_tag);break;

    case DIV_OP: b_arith_rel_op(B_DIV, type_tag); break;

    case MOD_OP: b_arith_rel_op(B_MOD, type_tag); break;
    
    case REALDIV_OP: b_arith_rel_op(B_DIV, type_tag); break;
    
    case EQ_OP:b_arith_rel_op(B_EQ, type_tag);   break;

    case LESS_OP: b_arith_rel_op(B_LT, type_tag); break;
    
    case LE_OP: b_arith_rel_op(B_LE, type_tag); break;
    
    case NE_OP: b_arith_rel_op(B_NE, type_tag); break;
    
    case GE_OP: b_arith_rel_op(B_GE, type_tag); break;
    
    case GREATER_OP: b_arith_rel_op(B_GT, type_tag); break;
   
    case ASSIGN_OP:  
        if(expr->u.binop.left->tag == LVAR)
            b_push_loc_addr(expr->u.binop.left->u.lvar.offset);
        if(left_type_tag != right_type_tag)
            b_convert(right_type_tag, left_type_tag);
        b_assign(left_type_tag);
        b_pop();
        break;
  }
}

void encode_fcall(EXPR func, EXPR_LIST args)
{
    int arg_list_size;
    EXPR_LIST t_arg;
    char *func_gname;
    TYPE func_ret_type;
    TYPETAG arg_tag;
    PARAM_LIST func_params;
    BOOLEAN check_args;

    func_ret_type = ty_query_func(func->type, &func_params, &check_args);
    arg_list_size = 0;
    t_arg = args;

    if(func->tag == GID)
        func_gname = st_get_id_str(func->u.gid);
    t_arg = args;
    while(t_arg != NULL) {

        if(ty_query(t_arg->expr->type)==TYDOUBLE||ty_query(t_arg->expr->type)==TYFLOAT)
            arg_list_size += 8;
        else
            arg_list_size += 4;

        t_arg=t_arg->next;
    }

    b_alloc_arglist(arg_list_size);
    t_arg=args;
    while(t_arg!=NULL) {

        encode_expr(t_arg->expr);
        arg_tag = ty_query(t_arg->expr->type);
        if(func_params != NULL) {
            if(func_params->is_ref==TRUE) { 
                if(is_lval(t_arg->expr)==FALSE)
                  bug("Function argument expected to be lval in encode_fcall_expr");

                if(ty_test_equality(t_arg->expr->type, func_params->type)==FALSE) 
                   error("Parameter types do not match");

                b_load_arg(TYPTR);
            } 
            else { 
                if(is_lval(t_arg->expr)==TRUE) 
                    b_deref(arg_tag);
                if(arg_tag==TYSIGNEDCHAR||arg_tag==TYUNSIGNEDCHAR) { 
                    b_convert(arg_tag,TYSIGNEDLONGINT);
                    b_load_arg(TYSIGNEDLONGINT);
                } 
                else if(arg_tag==TYFLOAT) { 
                    b_convert(arg_tag,TYDOUBLE);
                    b_load_arg(TYDOUBLE);
                } 
                else 
                    b_load_arg(arg_tag);
            }
         } 
        else {     
            if(is_lval(t_arg->expr)==TRUE) 
                b_deref(arg_tag);
            if(arg_tag==TYSIGNEDCHAR||arg_tag==TYUNSIGNEDCHAR) { 
                b_convert(arg_tag, TYSIGNEDLONGINT);
                b_load_arg(TYSIGNEDLONGINT);
            } 
            else if(arg_tag==TYFLOAT) { 
                b_convert(arg_tag,TYDOUBLE);
                b_load_arg(TYDOUBLE);
            } 
            else 
                b_load_arg(arg_tag);
        }

        t_arg=t_arg->next;

        if(func_params!=NULL) 
            func_params=func_params->next;
    }
    b_funcall_by_name(func_gname,ty_query(func_ret_type));
}
