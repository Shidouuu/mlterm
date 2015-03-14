/*
 *	$Id$
 */

#ifndef  __ML_TERMCAP_H__
#define  __ML_TERMCAP_H__


#include  <kiklib/kik_types.h>


typedef enum  ml_special_key
{
	SPKEY_DELETE = 0 ,
	SPKEY_BACKSPACE ,
	SPKEY_ESCAPE ,
	SPKEY_END ,
	SPKEY_HOME ,
	SPKEY_BEGIN ,
	SPKEY_ISO_LEFT_TAB ,
	SPKEY_KP_MULTIPLY ,
	SPKEY_KP_ADD ,
	SPKEY_KP_SEPARATOR ,
	SPKEY_KP_SUBTRACT ,
	SPKEY_KP_DELETE ,
	SPKEY_KP_DIVIDE ,
	SPKEY_KP_END ,
	SPKEY_KP_HOME ,
	SPKEY_KP_BEGIN ,
	SPKEY_KP_UP ,
	SPKEY_KP_DOWN ,
	SPKEY_KP_RIGHT ,
	SPKEY_KP_LEFT ,
	SPKEY_KP_INSERT ,
	SPKEY_KP_PRIOR ,
	SPKEY_KP_NEXT ,
	SPKEY_KP_F1 ,
	SPKEY_KP_F2 ,
	SPKEY_KP_F3 ,
	SPKEY_KP_F4 ,
	SPKEY_UP ,
	SPKEY_DOWN ,
	SPKEY_RIGHT ,
	SPKEY_LEFT ,
	SPKEY_FIND ,
	SPKEY_INSERT ,
	SPKEY_EXECUTE ,
	SPKEY_SELECT ,
	SPKEY_PRIOR ,
	SPKEY_NEXT ,
	SPKEY_F1 ,
	SPKEY_F2 ,
	SPKEY_F3 ,
	SPKEY_F4 ,
	SPKEY_F5 ,
	SPKEY_F6 ,
	SPKEY_F7 ,
	SPKEY_F8 ,
	SPKEY_F9 ,
	SPKEY_F10 ,
	SPKEY_F11 ,
	SPKEY_F12 ,
	SPKEY_F13 ,
	SPKEY_F14 ,
	SPKEY_F15 ,
	SPKEY_F16 ,
	SPKEY_F17 ,
	SPKEY_F18 ,
	SPKEY_F19 ,
	SPKEY_F20 ,
	SPKEY_F21 ,
	SPKEY_F22 ,
	SPKEY_F23 ,
	SPKEY_F24 ,
	SPKEY_F25 ,
	SPKEY_F26 ,
	SPKEY_F27 ,
	SPKEY_F28 ,
	SPKEY_F29 ,
	SPKEY_F30 ,
	SPKEY_F31 ,
	SPKEY_F32 ,
	SPKEY_F33 ,
	SPKEY_F34 ,
	SPKEY_F35 ,
	SPKEY_F36 ,
	SPKEY_F37

} ml_special_key_t ;

typedef enum  ml_termcap_str_field
{
	TC_DELETE ,
	TC_BACKSPACE ,
	TC_HOME ,
	TC_END ,
	TC_F1 ,
	TC_F2 ,
	TC_F3 ,
	TC_F4 ,
	TC_F5 ,

	MAX_TERMCAP_STR_FIELDS

} ml_termcap_str_field_t ;

typedef enum  ml_termcap_bool_field
{
	TC_BCE ,

	MAX_TERMCAP_BOOL_FIELDS

} ml_termcap_bool_field_t ;

typedef struct  ml_termcap_entry
{
	char *  name ;

	char *  str_fields[MAX_TERMCAP_STR_FIELDS] ;
	int8_t  bool_fields[MAX_TERMCAP_BOOL_FIELDS] ;

} ml_termcap_entry_t ;


ml_termcap_entry_t *  ml_termcap_get( const char *  name) ;

void  ml_termcap_final() ;

char *   ml_termcap_get_str_field( ml_termcap_entry_t *  entry , ml_termcap_str_field_t  field) ;

int   ml_termcap_get_bool_field( ml_termcap_entry_t *  entry , ml_termcap_bool_field_t  field) ;

char *  ml_termcap_special_key_to_seq( ml_termcap_entry_t *  entry , ml_special_key_t  key ,
	int  modcode , int  is_app_keypad , int  is_app_cursor_keys , int  is_app_escape) ;


#endif