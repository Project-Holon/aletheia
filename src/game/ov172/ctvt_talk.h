#ifndef GAME_OV172_CTVT_TALK_H
#define GAME_OV172_CTVT_TALK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of ctvt_talk.c, prototypes copied from their definitions. */

#include "../types.h"
#include "../ov172/ctvt_types.h"

struct CtvtTalk *CTVT_TALK_Create(char *unused, u16 heap);
void CTVT_TALK_Delete(void *ctx, char *talk);
void CTVT_TALK_Init(void *a, char *p);
void CTVT_TALK_Exit(void *ctx, char *talk);
u32 CTVT_TALK_Main(void *p, CtvtTalk *s);
void CTVT_TALK_SetMicMode(char *unused, char *p);
void CTVT_TALK_HandleInput(u8 *c, u8 *q);
void CTVT_TALK_UpdateVoiceSend(void *ctx, CtvtTalk *st);
void CTVT_TALK_UpdateVoiceIcon(void *ctx, char *talk);
void CTVT_TALK_HandleLevelSlider(void *unused, CtvtTalk *q);
void CTVT_TALK_DrawLine(int ctx, char *talk, u8 *p, u8 x0, u8 y0, u8 x1, u8 y1, u8 value);
void CTVT_TALK_PlotPixel(u8 *p, u8 x, u8 y, u8 value);
void CTVT_TALK_ShowMessage(void *p, char *q, int id);
void CTVT_TALK_OpenConfirmMenu(void *p, char *q);
void CTVT_TALK_UpdateConfirmMenu(void *self, CtvtTalk *q);
int CTVT_TALK_CheckEnd(void *p, s32 *out);
void CTVT_TALK_BeginWaveform(void *p, CtvtTalk *q);
void CTVT_TALK_DrawWaveform(int ctx, char *obj, s16 *tbl, u8 value, int idx, u16 v);
int CTVT_TALK_HitCenter(int a, int b, int mode);
struct CtvtMic *CTVT_TALK_GetMic(void *unused, struct CtvtTalk *p);
/* END mkheaders: generated region */

#endif
