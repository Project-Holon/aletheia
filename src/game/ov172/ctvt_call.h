#ifndef GAME_OV172_CTVT_CALL_H
#define GAME_OV172_CTVT_CALL_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ctvt_call.c, prototypes copied from their definitions. */

struct TcbTask;
struct BgTemplate;

#include "../types.h"
#include "../ov172/ctvt_types.h"
struct CtvtDescriptor;

void *CTVT_CALL_Create(void *unused, u32 heapId);
void CTVT_CALL_Free(void *unused, void *v);
void CTVT_CALL_Init(void *ctx, u8 *p);
void CTVT_CALL_Exit(void *ctx, char *st);
int CTVT_CALL_Update(void *ctx, char *p);
void CTVT_CALL_HandleTouch(void *ctx, u8 *list);
void CTVT_CALL_RefreshPeers(void *ctx, u8 *list);
void CTVT_CALL_UpdateRows(void *ctx, char *list);
void CTVT_CALL_DrawRow(void *ctx, char *list, char *row, int idx);
void CTVT_CALL_PlaceCursor(void *ctx, char *list, char *cur, u8 idx);
void CTVT_CALL_UpdatePrompt(void *ctx, u8 *st);
void CTVT_CALL_UpdateTimeWindow(void *ctx, char *st);
int CTVT_CALL_CheckJoinRequest(void *ctx, void *unused, const void *name, unsigned long trainerId, unsigned long outfitVariant);
void CTVT_CALL_PrintMessage(void *ctx, char *st, int msgId);
void CTVT_CALL_PrintTimeMessage(void *ctx, char *st, unsigned long msgId);
void CTVT_CALL_WorkInit(char *self);
void CTVT_CALL_WorkDelete(u8 *p);
int CTVT_CALL_WorkMain(char *ctx);
void CTVT_CALL_VBlank(struct TcbTask *unused, void *ctxArg);
void CTVT_CALL_InitDisplay(u8 *p);
void CTVT_CALL_ExitDisplay(void *work);
void CTVT_CALL_InitBgLayer(const struct BgTemplate *tmpl, u8 bgId, u32 type);
void CTVT_CALL_InitGraphics(u8 *p);
void CTVT_CALL_ReleaseGraphics(u8 *p);
void CTVT_CALL_InitText(u8 *p);
void CTVT_CALL_DeleteText(CtvtWork *work);
void CTVT_CALL_SwitchScreen(u8 *p);
void CTVT_CALL_UpdateMemberWindows(u8 *p);
void CTVT_CALL_DrawMemberName(u8 *p, char *a, struct CtvtDescriptor *b);
/* END mkheaders: generated region */

#endif
