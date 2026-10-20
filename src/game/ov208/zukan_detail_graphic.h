#ifndef GAME_OV208_ZUKAN_DETAIL_GRAPHIC_H
#define GAME_OV208_ZUKAN_DETAIL_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zukan_detail_graphic.c, prototypes copied from their definitions. */

#include "../types.h"

void ZUKAN_DETAIL_GRAPHIC_Init3dSettings(void);
char *ZUKAN_DETAIL_GRAPHIC_InitBgGraphics(unsigned display,unsigned short heap,int threeD);
void ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics(char *p);
void ZUKAN_DETAIL_GRAPHIC_DrawFrame(char *p);
void ZUKAN_DETAIL_GRAPHIC_ApplyCamera(char *p);
void ZUKAN_DETAIL_GRAPHIC_EndDraw3d(char *p);
int ZUKAN_DETAIL_GRAPHIC_Reset3dState(char *p);
void ZUKAN_DETAIL_GRAPHIC_Init3dSystem(char *p, unsigned short x);
void ZUKAN_DETAIL_GRAPHIC_Delete3dSystem(char *p);
void ZUKAN_DETAIL_GRAPHIC_VBlankTransfer(int unused, char *p);
void ZUKAN_DETAIL_GRAPHIC_CreateWindows(void *p,u16 heap);
void ZUKAN_DETAIL_GRAPHIC_DeleteWindows(void *p);
void ZUKAN_DETAIL_GRAPHIC_NoOp(char *unused);
void ZUKAN_DETAIL_GRAPHIC_TransferOam(char *unused);
void ZUKAN_DETAIL_GRAPHIC_InitActorSystem(unsigned char *p, int resCfg, int heapId);
void ZUKAN_DETAIL_GRAPHIC_ExitActorSystem(char *p);
void ZUKAN_DETAIL_GRAPHIC_DrawActors(char *p);
void ZUKAN_DETAIL_GRAPHIC_VBlankActors(char *unused);
int ZUKAN_DETAIL_GRAPHIC_ResetCameraState(int *p);
void ZUKAN_DETAIL_GRAPHIC_CreateSystemAndCamera(u32 **p,u16 heap);
void ZUKAN_DETAIL_GRAPHIC_DeleteCameraAndSystem(int *p);
void ZUKAN_DETAIL_GRAPHIC_ApplyCameraLookAt(int *p);
void ZUKAN_DETAIL_GRAPHIC_EndDraw(char *p);
/* END mkheaders: generated region */

#endif
