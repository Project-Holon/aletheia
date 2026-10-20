#ifndef GAME_OV112_MUSICAL_SHOT_SYS_H
#define GAME_OV112_MUSICAL_SHOT_SYS_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of musical_shot_sys.c, prototypes copied from their definitions. */

#include "../types.h"

int MUSICAL_SHOT_SYS_Exit(void *owner,void *arg,int flag,u8 *p);
int MUSICAL_SHOT_SYS_Update(int a,int b,int c,u8 *p);
void MUSICAL_SHOT_SYS_VBlank(void);
void MUSICAL_SHOT_SYS_InitGraphics(u8 *p);
void MUSICAL_SHOT_SYS_ExitGraphics(void *unused);
/* END mkheaders: generated region */

#endif
