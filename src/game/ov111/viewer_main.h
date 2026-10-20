#ifndef GAME_OV111_VIEWER_MAIN_H
#define GAME_OV111_VIEWER_MAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of viewer_main.c, prototypes copied from their definitions. */

#include "../ov111/viewer_types.h"
#include "../types.h"

int VIEWER_MAIN_Create(void *man, int *state, ViewerArgs *args);
void VIEWER_MAIN_InitInfo(ViewerInfo *info);
void VIEWER_MAIN_PlaySe(ViewerWork *p, int speed);
int VIEWER_MAIN_Main(void *proc, int *seq, int c, ViewerWork *p);
int VIEWER_MAIN_Delete(void *man, int *state, ViewerArgs *args, ViewerWork *p);
void VIEWER_MAIN_LoadResources(ViewerWork *p);
void VIEWER_MAIN_FreeResources(ViewerWork *p);
void VIEWER_MAIN_SetupBgSlot(ViewerWork *p, int k, int alt);
void VIEWER_MAIN_ClearBgSlot(ViewerWork *p, int k);
void VIEWER_MAIN_InitBg(void);
int VIEWER_MAIN_GetBgParamA(int x);
int VIEWER_MAIN_GetBgParamB(int x);
void VIEWER_MAIN_LoadBgResources(ViewerWork *p);
void VIEWER_MAIN_ExitBg(void);
void VIEWER_MAIN_SetBgSlotKind(ViewerWork *p, int kind);
void VIEWER_MAIN_ResetBgSlot(ViewerWork *p);
void VIEWER_MAIN_Draw(ViewerWork *p);
void VIEWER_MAIN_UpdateRowA(ViewerWork *p, int flag);
void VIEWER_MAIN_UpdateRowB(ViewerWork *p, int flag);
void VIEWER_MAIN_UpdateRowC(ViewerWork *p, int flag);
void VIEWER_MAIN_UpdateRows(ViewerWork *p, int flag);
int VIEWER_MAIN_Update(ViewerWork *p);
void VIEWER_MAIN_SetWindowPlane(int side);
int VIEWER_MAIN_UpdateWindows(char *p);
void VIEWER_MAIN_InitBrightness(ViewerWork *p);
int VIEWER_MAIN_CheckInputModeSwitch(ViewerWork *p);
int VIEWER_MAIN_HandleKey(ViewerWork *p);
void VIEWER_MAIN_ToggleFavorite(ViewerWork *p);
void VIEWER_MAIN_SetRowState(ViewerWork *p, int flag, int v);
void VIEWER_MAIN_SetRowDrawEnable(ViewerWork *p, int flag);
void VIEWER_MAIN_DrawRowBg(ViewerWork *p, int flag);
int VIEWER_MAIN_HitRow(ViewerWork *p, int hit);
int VIEWER_MAIN_HandleRowTouch(ViewerWork *p, int hit);
int VIEWER_MAIN_HandleRowKey(ViewerWork *p, int hit);
void VIEWER_MAIN_HandlePageTouch(ViewerWork *p);
void VIEWER_MAIN_HandlePageInput(ViewerWork *p);
int VIEWER_MAIN_HandleInput(ViewerWork *p);
int VIEWER_MAIN_UpdateInput(ViewerWork *p);
void VIEWER_MAIN_DrawSelected(ViewerWork *p, int sel, int *seq);
void VIEWER_MAIN_VBlank(void *task, ViewerWork *p);
void VIEWER_MAIN_InitLcdBrightness(void);
void VIEWER_MAIN_UploadBg(ViewerWork *p);
void VIEWER_MAIN_SetWindowRect(void *p);
void VIEWER_MAIN_CopyBg3(const u8 *src, u8 *dst);
void VIEWER_MAIN_CopyBg6(const u8 *src, u8 *dst);
void VIEWER_MAIN_ClearBgBuf(u32 bg, int mode);
void VIEWER_MAIN_UploadBgBuf(u32 bg, const void *src, int mode);
void VIEWER_MAIN_ClearBg(ViewerWork *p);
void VIEWER_MAIN_UpdateBrightness(ViewerWork *p);
void VIEWER_MAIN_CheckTouch(ViewerWork *p);
void VIEWER_MAIN_HandleScrollTouch(ViewerWork *p, int side);
void VIEWER_MAIN_BlitRect(u8 *dst, const u8 *src, int x, int y, int w, int h, int mode, int sel);
int VIEWER_MAIN_BlitBrush(u8 *pix, const u8 *brush, int x1, int y1, int *px, int *py, int a, int b, int clip, int side);
void VIEWER_MAIN_CopyTouchPos(ViewerTouchPos *src, ViewerTouchPos *dst);
int VIEWER_MAIN_DrawBrushStroke(u8 *pix, ViewerTouchPos *cur, ViewerTouchPos *prev, int flush, const void *src, u8 clip, u8 side);
/* END mkheaders: generated region */

#endif
