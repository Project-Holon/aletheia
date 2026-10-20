#ifndef GAME_OV111_VIEWER_TEXT_H
#define GAME_OV111_VIEWER_TEXT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of viewer_text.c, prototypes copied from their definitions. */

#include "../ov111/viewer_types.h"
#include "../types.h"

void VIEWER_TEXT_Init(ViewerWork *p);
void VIEWER_TEXT_Exit(ViewerWork *p);
void VIEWER_TEXT_Draw(ViewerWork *p, void **bg, const ViewerInfo *info);
void VIEWER_TEXT_DrawTable(ViewerWork *p, int k, int flush);
void VIEWER_TEXT_DrawList(ViewerWork *p, int k, int flush);
void VIEWER_TEXT_FlushWindow(ViewerWork *p, void **bg);
void VIEWER_TEXT_DrawWindow(ViewerWork *p, void *bg, void *info);
void VIEWER_TEXT_PrintColorAt(void *a, ViewerWork *p, int x, int y, void *s, int idx);
void VIEWER_TEXT_DrawRow(ViewerWork *p, void *a, u32 sel, int y, int idx);
void VIEWER_TEXT_AddRow(ViewerWork *p, int v);
void VIEWER_TEXT_BuildRowList(void *p, ViewerInfo *info);
void VIEWER_TEXT_DrawPage(ViewerWork *p, int scroll, int flush, int idx);
void VIEWER_TEXT_PrintNumber(ViewerWork *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int idx);
void VIEWER_TEXT_PrintDigits(ViewerWork *p, void *a, int x, int dx, int y, void *s, u32 n, u8 digits, u32 mode, int k, int idx);
void VIEWER_TEXT_PrintString(ViewerWork *p, void *a, int x, int dx, int y, void *s, u32 mode, int idx);
void VIEWER_TEXT_PrintStringClipped(ViewerWork *p, void *win, int x, int ofs, int y, void *str, u32 mode, int col);
void VIEWER_TEXT_PrintStringPad(ViewerWork *p, void *a, int x, int dx, int y, void *s, u32 n, u32 mode, int idx);
void VIEWER_TEXT_PrintWrapped(ViewerWork *p, void *a, int x, int dx, int y, void *s, int n, u8 kind, u32 mode, int w0, int h0, int idx);
void VIEWER_TEXT_Print(ViewerWork *p, void *a, int x, int dx, int y, void *s);
void VIEWER_TEXT_PrintRow(ViewerWork *p, void *a, int y, const ViewerInfo *info, void *s, int idx);
void VIEWER_TEXT_NoOp(void *work, void *bg, u32 flag, void *str);
void VIEWER_TEXT_InitActors(ViewerAnim *a, u32 x);
void VIEWER_TEXT_CreateActor(ViewerAnim *a);
void VIEWER_TEXT_DeleteActors(ViewerAnim *a);
void VIEWER_TEXT_SetActorAnim(ViewerAnim *p, int idx, u8 a, u8 b);
int VIEWER_TEXT_Create(void *proc, int *seq, void *parent);
int VIEWER_TEXT_Main(void *a, void *b, int c, ViewerTextWork *p);
int VIEWER_TEXT_Delete(void *proc, void *seq, int c, ViewerTextWork *p);
void VIEWER_TEXT_VBlank(void *unused, ViewerTextWork *p);
void VIEWER_TEXT_LoadResources(ViewerTextWork *p, ViewerArgs *parent);
void VIEWER_TEXT_FreeResources(ViewerTextWork *p);
void VIEWER_TEXT_InitVram(void);
void VIEWER_TEXT_InitBg(ViewerTextWork *p);
void VIEWER_TEXT_ExitBg(ViewerTextWork *p);
void VIEWER_TEXT_LoadBgResources(ViewerTextWork *p);
void VIEWER_TEXT_FreeBgResources(ViewerTextWork *p);
void VIEWER_TEXT_InitClact(ViewerTextWork *p);
/* END mkheaders: generated region */

#endif
