#ifndef GAME_OV021_TALKMSGWIN_H
#define GAME_OV021_TALKMSGWIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of talkmsgwin.c, prototypes copied from their definitions. */

struct Strbuf;
struct TextPrinter;
struct BmpWin;

#include "../ov021/talkmsgwin_types.h"
#include "../ov021/talkmsgwin_types.h"
#include "../types.h"
#include "../sdk_fx.h"

TalkMsgWinSys *TALKMSGWIN_Create(const TalkMsgWinParam *param);
void TALKMSGWIN_LoadTexture(TalkMsgWinSys *sys);
void TALKMSGWIN_Update(TalkMsgWinSys *sys);
void TALKMSGWIN_EndUpdate(TalkMsgWinSys *sys);
void TALKMSGWIN_Draw(TalkMsgWinSys *sys);
void TALKMSGWIN_Delete(TalkMsgWinSys *sys);
void TALKMSGWIN_SetupPlainWindow(TalkMsgWinSys *sys, int index, struct Strbuf *str, u8 x, u8 y, u8 width, u8 height, u32 unusedColor, u32 frameType, u32 wait, u8 textX, u8 textY);
void TALKMSGWIN_SetupUpperBalloon(TalkMsgWinSys *sys, int index, const VecFx32 *pos, struct Strbuf *str, u32 unusedColor, u32 frameType, u32 tailSide, u32 wait);
void TALKMSGWIN_SetupLowerBalloon(TalkMsgWinSys *sys, int index, const VecFx32 *pos, struct Strbuf *str, u32 unusedColor, u32 frameType, u32 tailSide, u32 wait);
void TALKMSGWIN_SetupAutoBalloon(TalkMsgWinSys *sys, int index, const VecFx32 *pos, struct Strbuf *str, u8 unusedColor, u32 frameType, u32 wait);
void TALKMSGWIN_Release(TalkMsgWinSys *sys, int index);
void TALKMSGWIN_Open(TalkMsgWinSys *sys, int index);
void TALKMSGWIN_Close(TalkMsgWinSys *sys, int index);
u32 TALKMSGWIN_IsFree(TalkMsgWinSys *sys, u32 index);
int TALKMSGWIN_IsShown(TalkMsgWinSys *sys, int index);
struct TextPrinter *TALKMSGWIN_GetPrintStream(TalkMsgWinSys *sys, u32 index);
struct BmpWin *TALKMSGWIN_GetBmpWin(TalkMsgWinSys *sys, u32 index);
void TALKMSGWIN_Reprint(TalkMsgWinSys *sys, int index, struct Strbuf *str, u32 wait);
struct BmpWin *TALKMSGWIN_AddFrameWindow(TalkMsgWinSys *sys, u8 x, u8 y, u8 width, u8 height, u32 frameType);
void TALKMSGWIN_DrawWindowFrame(TalkMsgWinSys *sys, struct BmpWin *bmpWin, u32 frameType);
void TALKMSGWIN_ClearWindowFrame(TalkMsgWinSys *sys, struct BmpWin *bmpWin);
void TALKMSGWIN_DeleteFrameWindow(TalkMsgWinSys *sys, struct BmpWin *bmpWin);
TalkMsgWin *TALKMSGWIN_InitEntry(TalkMsgWin *win);
int TALKMSGWIN_IsEntryFree(TalkMsgWin *win);
int TALKMSGWIN_IsEntryShown(TalkMsgWin *win);
struct BmpWin *TALKMSGWIN_AddBmpWin(TalkMsgWinSys *sys, u8 x, u8 y, u8 width, u8 height);
void TALKMSGWIN_SetupEntry(TalkMsgWinSys *sys, TalkMsgWin *win, const VecFx32 *pos, struct Strbuf *str, const TalkMsgWinConfig *config);
void TALKMSGWIN_ReleaseEntry(TalkMsgWinSys *sys, TalkMsgWin *win);
void TALKMSGWIN_RequestOpen(TalkMsgWin *win);
void TALKMSGWIN_RequestClose(TalkMsgWin *win);
void TALKMSGWIN_UpdateBalloon(TalkMsgWinSys *sys, TalkMsgWin *win);
void TALKMSGWIN_UpdatePlainWindow(TalkMsgWinSys *sys, TalkMsgWin *win);
void TALKMSGWIN_DrawEntry(TalkMsgWinSys *sys, TalkMsgWin *win);
void TALKMSGWIN_DrawBalloonShape(TalkMsgWinSys *sys, TalkMsgWin *win, int tailOnly);
int TALKMSGWIN_ProjectToWorld(const VecFx32 *relPos, int *screenX, int *screenY, VecFx32 *outWorld);
void TALKMSGWIN_GetAnchorWindowPoint(TalkMsgWin *win, TalkMsgWin *anchor, int *screenX, int *screenY, VecFx32 *outWorld);
void TALKMSGWIN_GetTailBaseX(int x, int w, int side, u16 *left, u16 *right);
int TALKMSGWIN_CalcTail(TalkMsgWin *win, int targetX, int targetY, VecFx32 *outBaseA, VecFx32 *outBaseB);
void TALKMSGWIN_GetWindowCornerPoints(TalkMsgWin *win, VecFx32 *outTopLeft, VecFx32 *outTopRight, VecFx32 *outBottomLeft, VecFx32 *outBottomRight);
void TALKMSGWIN_BuildShape(TalkMsgWinSys *sys, TalkMsgWin *win, const VecFx32 *tip, VecFx32 *tailBaseA, VecFx32 *tailBaseB, VecFx32 *topLeft, VecFx32 *topRight, VecFx32 *bottomLeft, VecFx32 *bottomRight);
u32 TALKMSGWIN_UpdateShape(TalkMsgWinSys *sys, TalkMsgWin *win);
void TALKMSGWIN_SetupCamera(TalkMsgWinSys *sys, int useCameraObject);
void TALKMSGWIN_SaveCamera(TalkMsgWinSys *sys);
void TALKMSGWIN_RestoreCamera(TalkMsgWinSys *sys);
u32 TALKMSGWIN_LoadFrameGraphics(TalkMsgWinSys *sys, TalkMsgWinParam *param);
void TALKMSGWIN_UploadTexture(TalkMsgWinSys *sys);
void TALKMSGWIN_ReloadFrameGraphics(TalkMsgWinSys *sys);
void TALKMSGWIN_DrawSimpleFrame(const TalkMsgWinParam *style, struct BmpWin *bmpWin, int tailSide);
void TALKMSGWIN_DrawCorneredFrame(const TalkMsgWinParam *style, struct BmpWin *bmpWin, int tailSide);
void TALKMSGWIN_DrawFrameByType(const TalkMsgWinParam *style, struct BmpWin *bmpWin, u8 frameType, u32 tailSide);
void TALKMSGWIN_DrawEntryFrame(TalkMsgWinSys *sys, TalkMsgWin *win);
void TALKMSGWIN_RedrawEntryFrame(TalkMsgWinSys *sys, TalkMsgWin *win);
void TALKMSGWIN_ClearFrame(const TalkMsgWinParam *style, struct BmpWin *bmpWin);
/* END mkheaders: generated region */

#endif
