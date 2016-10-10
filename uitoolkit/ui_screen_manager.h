/*
 *	$Id$
 */

#ifndef __UI_SCREEN_MANAGER_H__
#define __UI_SCREEN_MANAGER_H__

#include <stdio.h> /* FILE */
#include "ui_screen.h"
#include "ui_main_config.h"

int ui_screen_manager_init(char* mlterm_version, u_int depth, u_int max_screens_multiple,
                           u_int num_of_startup_screens, ui_main_config_t* main_config);

int ui_screen_manager_final(void);

u_int ui_screen_manager_startup(void);

int ui_close_dead_screens(void);

u_int ui_get_all_screens(ui_screen_t*** _screens);

int ui_mlclient(char* args, FILE* fp);

#endif