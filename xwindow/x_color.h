/*
 *	$Id$
 */

#ifndef  __X_COLOR_H__
#define  __X_COLOR_H__


/* This must be included ahead of Xft.h on XFree86-4.0.x or before. */
#include  <X11/Xlib.h>

#ifdef  USE_TYPE_XFT
#include  <X11/Xft/Xft.h>
#endif


#ifdef  USE_TYPE_XFT
typedef XftColor  x_color_t ;
#else
typedef XColor  x_color_t ;
#endif


int  x_load_named_xcolor( Display *  display , int  screen , x_color_t *  xcolor , char *  name) ;

int  x_load_rgb_xcolor( Display *  display , int  screen , x_color_t *  xcolor ,
	u_short  red , u_short  green , u_short  blue) ;

int  x_unload_xcolor( Display *  display , int  screen , x_color_t *  xcolor) ;

int  x_get_xcolor_rgb( u_short *  red , u_short *  green , u_short *  blue , x_color_t *  xcolor) ;

int  x_xcolor_fade( Display *  display , int  screen , x_color_t *  xcolor , u_int  fade_ratio) ;


#endif
