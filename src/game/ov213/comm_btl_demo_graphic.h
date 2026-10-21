#ifndef GAME_OV213_COMM_BTL_DEMO_GRAPHIC_H
#define GAME_OV213_COMM_BTL_DEMO_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of comm_btl_demo_graphic.c, prototypes copied from their definitions. */

#include "../types.h"

void *COMM_BTL_DEMO_GRAPHIC_Create(unsigned mode,unsigned heap);
void COMM_BTL_DEMO_GRAPHIC_Delete(unsigned char *p);
void COMM_BTL_DEMO_GRAPHIC_Draw(char *p);
void COMM_BTL_DEMO_GRAPHIC_Draw3d(char *p);
void COMM_BTL_DEMO_GRAPHIC_DrawEnd(char *p);
u32 COMM_BTL_DEMO_GRAPHIC_GetCamera(char *p);
void COMM_BTL_DEMO_GRAPHIC_VBlank(void *unused,char *p);
void COMM_BTL_DEMO_GRAPHIC_InitBg(void *p, unsigned heap);
void COMM_BTL_DEMO_GRAPHIC_DeleteBg(void *p);
void COMM_BTL_DEMO_GRAPHIC_Noop(void *work);
void COMM_BTL_DEMO_GRAPHIC_TickDisplay(void *work);
void COMM_BTL_DEMO_GRAPHIC_InitClact(void **out, struct DispVramCfg *a, int b);
void COMM_BTL_DEMO_GRAPHIC_DeleteClact(void *p);
void COMM_BTL_DEMO_GRAPHIC_DrawClact(void *work);
void COMM_BTL_DEMO_GRAPHIC_VBlankClact(void *work);
void *COMM_BTL_DEMO_GRAPHIC_GetClactBank(void **p);
void COMM_BTL_DEMO_GRAPHIC_InitG3d(u32 **p,unsigned heap);
void COMM_BTL_DEMO_GRAPHIC_DeleteG3d(int *p);
void COMM_BTL_DEMO_GRAPHIC_DrawG3d(int *p);
void COMM_BTL_DEMO_GRAPHIC_DrawG3dEnd(void *unused);
/* END mkheaders: generated region */

#endif
