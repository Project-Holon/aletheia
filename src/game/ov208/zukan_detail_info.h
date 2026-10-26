#ifndef GAME_OV208_ZUKAN_DETAIL_INFO_H
#define GAME_OV208_ZUKAN_DETAIL_INFO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zukan_detail_info.c, prototypes copied from their definitions. */

struct Ov208Heap;
struct Ov208InfoWork;
struct Ov208Ctx;

#include "../types.h"

struct TcbTask;

void ZUKAN_DETAIL_INFO_SetHeapId(u16 *p, u16 v);
int ZUKAN_DETAIL_INFO_Init(void *owner, int unused, u16 *heap);
int ZUKAN_DETAIL_INFO_Exit(char *first,unsigned unused,int owner,char *q,unsigned heap);
int ZUKAN_DETAIL_INFO_Main(void *unused, int *state, struct Ov208Heap *h, struct Ov208InfoWork *p, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_INFO_HandleKeyEvent(void *proc, void *seq, void *heap, struct Ov208InfoWork *st, struct Ov208Ctx *obj, int key);
void ZUKAN_DETAIL_INFO_NoOp(struct TcbTask *p, void *unused1);
int ZUKAN_DETAIL_INFO_HandleTouchLanguageButton(void *heap, struct Ov208InfoWork *st, struct Ov208Ctx *obj);
int ZUKAN_DETAIL_INFO_HandleKeyLanguageSelect(void *first,char *p,struct Ov208Ctx *key);
void ZUKAN_DETAIL_INFO_RefreshLanguagePanel(void *first,char *q,struct Ov208Ctx *third);
void ZUKAN_DETAIL_INFO_SelectLanguageButton(void *first,char *q,struct Ov208Ctx *third,int next);
void ZUKAN_DETAIL_INFO_CreateLanguageButtons(u16 *heap, char *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_INFO_DeleteLanguageButtons(int unused, char *q, u32 heap);
void ZUKAN_DETAIL_INFO_UpdateButtonPressAnim(void *unused, char *p, struct Ov208Ctx *key);
void ZUKAN_DETAIL_INFO_ResetButtons(int unused, char *q, struct Ov208Ctx *c, int *tbl);
void ZUKAN_DETAIL_INFO_GetPanelParams(const u16 *heap, u8 *p, struct Ov208Ctx *key, u16 *out1, u16 *out2, u16 *out3, u16 *out4, u32 *out5, u32 *out6, u32 *out7);
void ZUKAN_DETAIL_INFO_LoadHighlightPalettes(u16 *heap, u8 *p, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_INFO_NoOpHighlight(int unused0, char *unused1, unsigned unused2);
void ZUKAN_DETAIL_INFO_StartHighlightBlink(struct Ov208Heap *unused, struct Ov208InfoWork *p, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_INFO_ClearButtonHighlight(int unused, char *p, unsigned unused2);
void ZUKAN_DETAIL_INFO_UpdateHighlightBlink(struct Ov208Heap *heap, struct Ov208InfoWork *e, struct Ov208Ctx *ctx);
/* END mkheaders: generated region */

#endif
