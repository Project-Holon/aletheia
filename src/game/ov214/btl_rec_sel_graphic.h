#ifndef GAME_OV214_BTL_REC_SEL_GRAPHIC_H
#define GAME_OV214_BTL_REC_SEL_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_rec_sel_graphic.c, prototypes copied from their definitions. */

#include "../types.h"

char *BTL_REC_SEL_GRAPHIC_Create(u32 a,u32 heap);
void BTL_REC_SEL_GRAPHIC_Delete(char *p);
void BTL_REC_SEL_GRAPHIC_Draw(u8 *p);
void BTL_REC_SEL_GRAPHIC_Draw3d(u8 *p);
void BTL_REC_SEL_GRAPHIC_DrawEnd(char *p);
u32 BTL_REC_SEL_GRAPHIC_GetCamera(u8 *p);
void BTL_REC_SEL_GRAPHIC_VBlank(void *unused,u8 *p);
void BTL_REC_SEL_GRAPHIC_InitBg(void *p,u32 heap);
void BTL_REC_SEL_GRAPHIC_DeleteBg(void *p);
void BTL_REC_SEL_GRAPHIC_Noop(void *p);
void BTL_REC_SEL_GRAPHIC_TickDisplay(void *p);
void BTL_REC_SEL_GRAPHIC_InitClact(unsigned char *p, int a, int b);
void BTL_REC_SEL_GRAPHIC_DeleteClact(void *p);
void BTL_REC_SEL_GRAPHIC_DrawClact(void *p);
void BTL_REC_SEL_GRAPHIC_VBlankClact(void *p);
u32 BTL_REC_SEL_GRAPHIC_GetClactBank(u32 *p);
void BTL_REC_SEL_GRAPHIC_InitG3d(u32 **out,u32 heap);
void BTL_REC_SEL_GRAPHIC_DeleteG3d(int *p);
void BTL_REC_SEL_GRAPHIC_DrawG3d(unsigned int *p);
void BTL_REC_SEL_GRAPHIC_DrawG3dEnd(void *work);
/* END mkheaders: generated region */

#endif
