#ifndef GAME_OV208_ZUKAN_DETAIL_VOICE_H
#define GAME_OV208_ZUKAN_DETAIL_VOICE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zukan_detail_voice.c, prototypes copied from their definitions. */

struct Ov208Ctx;
struct ZukanDetailVoice;

#include "../types.h"

struct TcbTask;

void ZUKAN_DETAIL_VOICE_SetHeapId(u16 *dst, u16 value);
u32 ZUKAN_DETAIL_VOICE_Init(void *workAlloc, u32 unused, u16 *heapIdPtr, u32 unused2, struct Ov208Ctx *ctx);
u32 ZUKAN_DETAIL_VOICE_Exit(void *workAlloc, u32 unused, void *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
int ZUKAN_DETAIL_VOICE_Main(void *unused, int *seq, u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_HandleKeyEvent(void *unused, void *unused2, void *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx, int key);
void ZUKAN_DETAIL_VOICE_ApplyPendingDisplay(struct TcbTask *unused, void *voiceArg);
void ZUKAN_DETAIL_VOICE_FadeOutBgm(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_RestoreBgm(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_UpdateBgmFade(int unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_CreateNumberActors(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_DeleteNumberActors(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_SetNumberDigits(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *unused2, int seconds, u16 hundredths);
void ZUKAN_DETAIL_VOICE_LoadPokemonGraphics(u16 *heapIdPtr, u8 *p, struct Ov208Ctx *ctx, u32 slot);
void ZUKAN_DETAIL_VOICE_UnloadPokemonGraphics(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *unused2, u32 slot);
void ZUKAN_DETAIL_VOICE_UpdatePokemonScaleAnim(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_ResetPokemonTransform(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_FinishScaleAnim(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_CreateTimerWindow(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_DeleteTimerWindow(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_DrawSpeciesName(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_ClearTimerWindow(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_FlushTimerWindow(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_LoadWindowPalette(unsigned short *heapIdPtr, void *unused, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_NoOpA(void *unused, void *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_NoOpB(void *unused, void *voice, struct Ov208Ctx *ctx, int seconds, int hundredths);
void ZUKAN_DETAIL_VOICE_NoOpC(void *unused, void *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_UpdatePlaybackTimer(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_StopVoice(int unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_SwitchPokemonSlot(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_HandlePlayInput(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_CreateWaveformWindow(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_DeleteWaveformWindow(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_UpdateWaveformDelay(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_InitWaveformState(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_ScrollWaveform(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_DrawWaveform(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx, u16 species, u16 form);
void ZUKAN_DETAIL_VOICE_UpdateWaveformTiles(u16 *heapIdPtr, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_SetActorsNormalMode(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
void ZUKAN_DETAIL_VOICE_SetActorsAlphaMode(void *unused, struct ZukanDetailVoice *voice, struct Ov208Ctx *ctx);
/* END mkheaders: generated region */

#endif
