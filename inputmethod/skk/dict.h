/*
 *	$Id$
 */

#ifndef  __DICT_H__
#define  __DICT_H__


#include  <kiklib/kik_types.h>
#include  <mkf/mkf_conv.h>


#define  MAX_DIGIT_NUM  3	/* 100 */
#define  MAX_CANDS  100
#define  CAND_UNIT  5


void  dict_final(void) ;

u_int  dict_completion( mkf_char_t *  caption , u_int  caption_len , void **  aux , int  step) ;

void  dict_completion_finish( void **  aux) ;

u_int  dict_completion_reset_and_finish( mkf_char_t *  caption , void **  aux) ;

u_int  dict_candidate( mkf_char_t *  caption , u_int  caption_len , void **  aux , int  step) ;

void  dict_candidate_get_state( void *  aux , int *  cur , u_int *  num) ;

void  dict_candidate_get_list( void *  aux , char *  list , size_t  list_size ,
		mkf_conv_t *  conv) ;

void  dict_candidate_finish( void **  aux) ;

u_int  dict_candidate_reset_and_finish( mkf_char_t *  caption , void **  aux) ;

int  dict_candidate_add_to_local( void *  aux) ;

int  dict_add_new_word_to_local( mkf_char_t *  caption , u_int  caption_len ,
		mkf_char_t *  word , u_int  word_len) ;

void  dict_set_global( char *  dict) ;


#endif