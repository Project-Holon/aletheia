#ifndef GAME_OV217_PALETTE_ANIME_H
#define GAME_OV217_PALETTE_ANIME_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of palette_anime.c, prototypes copied from their definitions. */

struct PaletteAnime;

#include "../types.h"

u32 PALETTE_ANIME_Create(u32 heapId);
u32 PALETTE_ANIME_Destroy(struct PaletteAnime *anime);
void PALETTE_ANIME_Bind(struct PaletteAnime *anime, u16 *palette, u16 *original, int colorCount);
void PALETTE_ANIME_Update(struct PaletteAnime *anime);
void PALETTE_ANIME_Start(struct PaletteAnime *anime, u32 mode, u16 color);
void PALETTE_ANIME_Stop(struct PaletteAnime *anime);
int PALETTE_ANIME_Restore(struct PaletteAnime *anime);
void PALETTE_ANIME_IsRunning(struct PaletteAnime *anime, u32 unused);
void PALETTE_ANIME_StartImpl(struct PaletteAnime *anime, u32 mode, u16 color);
void PALETTE_ANIME_StopImpl(struct PaletteAnime *anime);
void PALETTE_ANIME_UpdateImpl(struct PaletteAnime *anime);
void PALETTE_ANIME_StepSinePulse60(struct PaletteAnime *anime);
void PALETTE_ANIME_StepSinePulse30(struct PaletteAnime *anime);
void PALETTE_ANIME_StepSinePulse90(struct PaletteAnime *anime);
void PALETTE_ANIME_StepBlink20(struct PaletteAnime *anime);
void PALETTE_ANIME_StepBlink10(struct PaletteAnime *anime);
void PALETTE_ANIME_StepBlink30(struct PaletteAnime *anime);
void PALETTE_ANIME_StepBlinkStrong20(struct PaletteAnime *anime);
void PALETTE_ANIME_StepFadeIn(struct PaletteAnime *anime);
void PALETTE_ANIME_StepFadeOut(struct PaletteAnime *anime);
void PALETTE_ANIME_StepHold(struct PaletteAnime *anime);
int PALETTE_ANIME_RestoreImpl(struct PaletteAnime *anime);
u32 PALETTE_ANIME_IsRunningImpl(struct PaletteAnime *anime);
struct PaletteAnime *PALETTE_ANIME_Alloc(u32 heapId);
u32 PALETTE_ANIME_Free(struct PaletteAnime *anime);
void PALETTE_ANIME_Clear(struct PaletteAnime *anime);
void PALETTE_ANIME_BindImpl(struct PaletteAnime *anime, u16 *palette, u16 *original, int colorCount);
void PALETTE_ANIME_ReleaseOriginal(struct PaletteAnime *anime);
/* END mkheaders: generated region */

#endif
