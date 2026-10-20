#ifndef GAME_OV177_WIFIBATTLEMATCH_GRAPHIC_H
#define GAME_OV177_WIFIBATTLEMATCH_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wifibattlematch_graphic.c, prototypes copied from their definitions. */

#include "../types.h"

int *WIFIBATTLEMATCH_GRAPHIC_Create(unsigned swap, u16 heap);
void WIFIBATTLEMATCH_GRAPHIC_Delete(char *p);
void WIFIBATTLEMATCH_GRAPHIC_Draw(u8 *p);
int WIFIBATTLEMATCH_GRAPHIC_GetCamera(int *p);
void WIFIBATTLEMATCH_GRAPHIC_VBlank(int a, int *p);
void WIFIBATTLEMATCH_GRAPHIC_InitBg(void *p, unsigned short heap);
void WIFIBATTLEMATCH_GRAPHIC_DeleteBg(void *p);
void WIFIBATTLEMATCH_GRAPHIC_Noop(void *p);
void WIFIBATTLEMATCH_GRAPHIC_TickDisplay(int *unused);
void WIFIBATTLEMATCH_GRAPHIC_InitClact(int *p, int b, int c);
void WIFIBATTLEMATCH_GRAPHIC_DeleteClact(int *p);
void WIFIBATTLEMATCH_GRAPHIC_DrawClact(void *p);
void WIFIBATTLEMATCH_GRAPHIC_VBlankClact(int *unused);
int WIFIBATTLEMATCH_GRAPHIC_GetClactBank(int *p);
/* END mkheaders: generated region */

#endif
