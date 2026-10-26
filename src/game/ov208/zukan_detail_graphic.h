#ifndef GAME_OV208_ZUKAN_DETAIL_GRAPHIC_H
#define GAME_OV208_ZUKAN_DETAIL_GRAPHIC_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zukan_detail_graphic.c, prototypes copied from their definitions. */

struct Unit;
struct DispVramCfg;
struct G3dCamera;

#include "../types.h"

struct TcbTask;

void ZUKAN_DETAIL_GRAPHIC_Init3dSettings(void);
char *ZUKAN_DETAIL_GRAPHIC_InitBgGraphics(unsigned display,unsigned short heap,int threeD);
void ZUKAN_DETAIL_GRAPHIC_ExitBgGraphics(char *p);
void ZUKAN_DETAIL_GRAPHIC_DrawFrame(char *p);
void ZUKAN_DETAIL_GRAPHIC_ApplyCamera(char *p);
void ZUKAN_DETAIL_GRAPHIC_EndDraw3d(char *p);
struct Unit *ZUKAN_DETAIL_GRAPHIC_Reset3dState(char *p);
void ZUKAN_DETAIL_GRAPHIC_Init3dSystem(char *p, unsigned short x);
void ZUKAN_DETAIL_GRAPHIC_Delete3dSystem(char *p);
void ZUKAN_DETAIL_GRAPHIC_VBlankTransfer(struct TcbTask *unused, void *arg);
void ZUKAN_DETAIL_GRAPHIC_CreateWindows(void *p,u16 heap);
void ZUKAN_DETAIL_GRAPHIC_DeleteWindows(void *p);
void ZUKAN_DETAIL_GRAPHIC_NoOp(char *unused);
void ZUKAN_DETAIL_GRAPHIC_TransferOam(char *unused);
void ZUKAN_DETAIL_GRAPHIC_InitActorSystem(unsigned char *p, const struct DispVramCfg *resCfg, int heapId);
void ZUKAN_DETAIL_GRAPHIC_ExitActorSystem(char *p);
void ZUKAN_DETAIL_GRAPHIC_DrawActors(char *p);
void ZUKAN_DETAIL_GRAPHIC_VBlankActors(char *unused);
struct Unit *ZUKAN_DETAIL_GRAPHIC_ResetCameraState(struct Unit **p);
void ZUKAN_DETAIL_GRAPHIC_CreateSystemAndCamera(u32 **p,u16 heap);
void ZUKAN_DETAIL_GRAPHIC_DeleteCameraAndSystem(struct G3dCamera **p);
void ZUKAN_DETAIL_GRAPHIC_ApplyCameraLookAt(struct G3dCamera **p);
void ZUKAN_DETAIL_GRAPHIC_EndDraw(char *p);
/* END mkheaders: generated region */

#endif
