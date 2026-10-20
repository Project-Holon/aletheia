#ifndef GAME_ARM9_BGWINFRM_H
#define GAME_ARM9_BGWINFRM_H

/* Public functions of bgwinfrm.c, prototypes copied from their definitions. */

struct BgWinFrmWork;

#include "../types.h"

struct BgWinFrmWork *BGWINFRM_Create(u32 transMode, u32 frameMax, u32 heapId);
void BGWINFRM_Delete(struct BgWinFrmWork *wk);
void BGWINFRM_AddFrame(struct BgWinFrmWork *wk, u32 idx, u32 bgFrame, u32 sizeX, u32 sizeY);
void BGWINFRM_SetFrameData(struct BgWinFrmWork *wk, u32 idx, const void *src);
void BGWINFRM_SetFrameDataArc(struct BgWinFrmWork *wk, u32 idx, u32 arcId, u32 datId, u32 compressed);
void BGWINFRM_SetFrameDataArcHandle(struct BgWinFrmWork *wk, u32 idx, void *arcHandle, u32 datId, u32 compressed);
void BGWINFRM_PutFrame(struct BgWinFrmWork *wk, u32 idx, s8 x, s8 y);
void BGWINFRM_ShowFrame(struct BgWinFrmWork *wk, u32 idx);
void BGWINFRM_HideFrame(struct BgWinFrmWork *wk, u32 idx);
void BGWINFRM_StartMove(struct BgWinFrmWork *wk, u32 idx, s8 moveX, s8 moveY, u8 count);
void BGWINFRM_UpdateMoves(struct BgWinFrmWork *wk);
u32 BGWINFRM_UpdateMove(struct BgWinFrmWork *wk, u32 idx);
u32 BGWINFRM_IsMoving(struct BgWinFrmWork *wk, u32 idx);
void BGWINFRM_ChangePalette(struct BgWinFrmWork *wk, u32 idx, s32 x, s32 y, u8 sizeX, u8 sizeY, u8 palette);
void BGWINFRM_PutBmpWin(struct BgWinFrmWork *wk, u32 idx, void *bmpWin);
u16 *BGWINFRM_GetFrameBuffer(struct BgWinFrmWork *wk, u32 idx);
u8 BGWINFRM_GetBgFrame(struct BgWinFrmWork *wk, u32 idx);
void BGWINFRM_GetPos(struct BgWinFrmWork *wk, u32 idx, s8 *x, s8 *y);
void BGWINFRM_GetSize(struct BgWinFrmWork *wk, u32 idx, u16 *sizeX, u16 *sizeY);
void BGWINFRM_SetClipArea(struct BgWinFrmWork *wk, u32 idx, s8 xmin, s8 xmax, s8 ymin, s8 ymax);
void BGWINFRM_EmptyStub(void);
u8 BGWINFRM_ScaleRatio(u32 a, u32 b, u32 c);
int BGWINFRM_GetScaleRank(u32 a, u32 b);

#endif
