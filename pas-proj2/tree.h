#ifndef TREE_C
#define TREE_C
#include "types.h" 
#include "symtab.h" 
#include "message.h" 

/* List of multiple variables */
typedef struct var_id {
    ST_ID id;
    struct var_id *next;
} VAR_ID, *VAR_ID_LIST;

/* Node to store id and type for function_heading */
typedef struct func_heading {
    ST_ID	id;
    TYPE	ret_type;
} FUNC_HEADING;

/* Procedure and function prototype directives */
typedef enum { DIR_EXTERNAL, DIR_FORWARD } DIRECTIVE;
   
TYPE build_unresolved_pointer(TYPE ret_type, TYPE object);

void create_typename(ST_ID id,TYPE new_type);

void create_gdecl(VAR_ID_LIST list,TYPE type);

TYPE check_typename( ST_ID id );

TYPE check_subrange( long a, long b);

TYPE check_array(TYPE array, INDEX_LIST i);

TYPE check_function_type(TYPE t);

PARAM_LIST check_param(PARAM_LIST p);

VAR_ID_LIST build_var_id_list (VAR_ID_LIST list,ST_ID id);

PARAM_LIST build_param_list(VAR_ID_LIST id_list,TYPE type,BOOLEAN value);

PARAM_LIST concatenate_param_list (PARAM_LIST list1,PARAM_LIST list2);

INDEX_LIST concatenate_index_lists (INDEX_LIST list1,TYPE type);

INDEX_LIST create_list_from_type(TYPE type);

void resolve_all_ptr();

/* Definitions for part 2 */
void enter_main_body();

void exit_main_body();

void install_func_head(ST_ID id, TYPE type, DIRECTIVE dir);

int enter_func(ST_ID id, TYPE ret_type);

void enter_func_body(ST_ID id, TYPE ret_type, int loc_var_offset);

void exit_func_body(ST_ID id, TYPE ret_type);

void install_params(PARAM_LIST list);

#endif

