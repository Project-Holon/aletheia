/*
 * file:     palette_anime.c
 * unit:     yes
 * function: PALETTE_ANIME_Create, PALETTE_ANIME_Destroy, PALETTE_ANIME_Bind, PALETTE_ANIME_Update, PALETTE_ANIME_Start, PALETTE_ANIME_Stop, PALETTE_ANIME_Restore, PALETTE_ANIME_IsRunning, PALETTE_ANIME_StartImpl, PALETTE_ANIME_StopImpl, PALETTE_ANIME_UpdateImpl, PALETTE_ANIME_StepSinePulse60, PALETTE_ANIME_StepSinePulse30, PALETTE_ANIME_StepSinePulse90, PALETTE_ANIME_StepBlink20, PALETTE_ANIME_StepBlink10, PALETTE_ANIME_StepBlink30, PALETTE_ANIME_StepBlinkStrong20, PALETTE_ANIME_StepFadeIn, PALETTE_ANIME_StepFadeOut, PALETTE_ANIME_StepHold, PALETTE_ANIME_RestoreImpl, PALETTE_ANIME_IsRunningImpl, PALETTE_ANIME_Alloc, PALETTE_ANIME_Free, PALETTE_ANIME_Clear, PALETTE_ANIME_BindImpl, PALETTE_ANIME_ReleaseOriginal
 * address:  0x021C29C8
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from research_top.c, unit_021BFFC8.c, queue.c, palette_anime.c, PALETTE_ANIME_ReleaseOriginal.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free 0x020307B0 arm
 *   PALETTE_ANIME_Start  0x021C29F8  thumb  ov217
 *   PALETTE_ANIME_Stop  0x021C2A00  thumb  ov217
 *   PALETTE_ANIME_Update  0x021C29F0  thumb  ov217
 *   PALETTE_ANIME_Create  0x021C29C8  thumb  ov217
 *   PALETTE_ANIME_Destroy  0x021C29D8  thumb  ov217
 *   PALETTE_ANIME_Bind  0x021C29E8  thumb  ov217
 *   PALETTE_ANIME_Restore  0x021C2A08  thumb  ov217
 *   PALETTE_ANIME_IsRunning  0x021C2A10  thumb  ov217
 *   MI_CpuFill8  0x02082BCC  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   PALETTE_ANIME_ReleaseOriginal  0x021C2E20  thumb  ov217
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   PALANM_BlendColors 0x02021F64 thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   d_021C408C 0x021C408C data ov217 a1
 */
#include "research_types.h"

/* Palette blink and pulse animation of one palette range, 32 bytes. */
struct PaletteAnime {
    u16 heapId;
    s32 initialized;
    u16 *palette;       /* live palette entries that the animation writes */
    u16 *original;      /* heap copy of the entries, the blend source */
    u8 colorCount;
    u16 targetColor;    /* RGB555 colour the entries are blended toward */
    u32 running;
    u32 mode;           /* 0..9, selects the step function */
    u32 frame;
};

extern u32 GFL_HEAP_Free(void *mem);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void PALANM_BlendColors(u16 *src, u16 *dst, u32 count, int weight, u16 color);
extern int MI_CpuCopy8(int src, int dst, int size);
extern void MI_CpuFill8(void *dst, int val, int size);
extern const short FX_SinCosTable_[];
extern char d_021C408C[];

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

/* Allocates and clears an animation object. */
u32 PALETTE_ANIME_Create(u32 heapId)
{
    struct PaletteAnime *anime = PALETTE_ANIME_Alloc(heapId);
    PALETTE_ANIME_Clear(anime);
    return (u32)anime;
}

/* Releases the copy buffer, then the object. */
u32 PALETTE_ANIME_Destroy(struct PaletteAnime *anime)
{
    PALETTE_ANIME_ReleaseOriginal(anime);
    return PALETTE_ANIME_Free(anime);
}

/* Binds the animation to a palette range and snapshots its colours. */
void PALETTE_ANIME_Bind(struct PaletteAnime *anime, u16 *palette, u16 *original, int colorCount)
{
    PALETTE_ANIME_BindImpl(anime, palette, original, colorCount);
}

/* Veneer: advances the animation by one frame. */
void PALETTE_ANIME_Update(struct PaletteAnime *anime)
{
    PALETTE_ANIME_UpdateImpl(anime);
}

/* Veneer: starts the animation with a mode and target colour. */
void PALETTE_ANIME_Start(struct PaletteAnime *anime, u32 mode, u16 color)
{
    PALETTE_ANIME_StartImpl(anime, mode, color);
}

/* Veneer: stops the animation. */
void PALETTE_ANIME_Stop(struct PaletteAnime *anime)
{
    PALETTE_ANIME_StopImpl(anime);
}

/* Veneer: copies the original colours back to the palette. */
int PALETTE_ANIME_Restore(struct PaletteAnime *anime)
{
    return PALETTE_ANIME_RestoreImpl(anime);
}

/* Veneer: reads the running flag; the second argument is ignored. */
void PALETTE_ANIME_IsRunning(struct PaletteAnime *anime, u32 unused)
{
    PALETTE_ANIME_IsRunningImpl(anime);
}

/* Starts the animation: mode and colour set, frame counter cleared. */
void PALETTE_ANIME_StartImpl(struct PaletteAnime *anime, u32 mode, u16 color)
{
    anime->running = 1;
    anime->mode = mode;
    anime->frame = 0;
    anime->targetColor = color;
}

/* Clears the running flag. */
void PALETTE_ANIME_StopImpl(struct PaletteAnime *anime)
{
    anime->running = 0;
}

/* Runs the step function of the current mode while the animation is running. */
void PALETTE_ANIME_UpdateImpl(struct PaletteAnime *anime)
{
    if (anime->initialized == 0)
        return;
    if (anime->running == 0)
        return;
    switch (anime->mode) {
    case 0:
        PALETTE_ANIME_StepSinePulse60(anime);
        break;
    case 1:
        PALETTE_ANIME_StepSinePulse30(anime);
        break;
    case 2:
        PALETTE_ANIME_StepSinePulse90(anime);
        break;
    case 3:
        PALETTE_ANIME_StepBlink20(anime);
        break;
    case 4:
        PALETTE_ANIME_StepBlink10(anime);
        break;
    case 5:
        PALETTE_ANIME_StepBlink30(anime);
        break;
    case 6:
        PALETTE_ANIME_StepBlinkStrong20(anime);
        break;
    case 7:
        PALETTE_ANIME_StepFadeIn(anime);
        break;
    case 8:
        PALETTE_ANIME_StepFadeOut(anime);
        break;
    case 9:
        PALETTE_ANIME_StepHold(anime);
        break;
    }
}

/*
 * Mode 0: sine pulse with a period of 60 frames, weight scaled by 10/32.
 * The weight is narrowed to u8 before the call and the colour stays a
 * scalar u16; the weight local is reused for the scaled value.
 */
void PALETTE_ANIME_StepSinePulse60(struct PaletteAnime *anime)
{
    u16 angle = (u16)((anime->frame << 16) / 60u);
    u8 weight = (u8)(int)(16.0f + 16.0f * ((float)FX_SinCosTable_[(angle >> 4) * 2] / 4096.0f));
    weight = weight * 10 / 32;
    PALANM_BlendColors(anime->original, anime->palette, anime->colorCount, weight, anime->targetColor);
    anime->frame += 1;
}

/* Mode 1: sine pulse with a period of 30 frames, weight scaled by 3/32. */
void PALETTE_ANIME_StepSinePulse30(struct PaletteAnime *anime)
{
    u16 angle = (u16)((anime->frame << 16) / 30u);
    u8 weight = (u8)(int)(16.0f + 16.0f * ((float)FX_SinCosTable_[(angle >> 4) * 2] / 4096.0f));
    weight = weight * 3 / 32;
    PALANM_BlendColors(anime->original, anime->palette, anime->colorCount, weight, anime->targetColor);
    anime->frame += 1;
}

/* Mode 2: sine pulse with a period of 90 frames, weight scaled by 3/32. */
void PALETTE_ANIME_StepSinePulse90(struct PaletteAnime *anime)
{
    u16 angle = (u16)((anime->frame << 16) / 90u);
    u8 weight = (u8)(int)(16.0f + 16.0f * ((float)FX_SinCosTable_[(angle >> 4) * 2] / 4096.0f));
    weight = weight * 3 / 32;
    PALANM_BlendColors(anime->original, anime->palette, anime->colorCount, weight, anime->targetColor);
    anime->frame += 1;
}

/* Mode 3: blink (weight 0 or 6, toggling every 4 frames) for 20 frames, then stop and restore. */
void PALETTE_ANIME_StepBlink20(struct PaletteAnime *anime)
{
    int weight;
    if ((anime->frame >> 2 & 1) == 0) weight = 0;
    else weight = 6;
    PALANM_BlendColors(anime->original, anime->palette, anime->colorCount, weight, anime->targetColor);
    anime->frame += 1;
    if (anime->frame > 20) {
        PALETTE_ANIME_StopImpl(anime);
        PALETTE_ANIME_RestoreImpl(anime);
    }
}

/* Mode 4: same blink as mode 3 but it stops after 10 frames. */
void PALETTE_ANIME_StepBlink10(struct PaletteAnime *anime)
{
    int weight;
    if ((anime->frame >> 2 & 1) == 0) weight = 0;
    else weight = 6;
    PALANM_BlendColors(anime->original, anime->palette, anime->colorCount, weight, anime->targetColor);
    anime->frame += 1;
    if (anime->frame > 10) {
        PALETTE_ANIME_StopImpl(anime);
        PALETTE_ANIME_RestoreImpl(anime);
    }
}

/* Mode 5: blink (weight 0 or 6) for 30 frames, then stop and restore. */
void PALETTE_ANIME_StepBlink30(struct PaletteAnime *anime)
{
    int weight = ((anime->frame >> 2) & 1) == 0 ? 0 : 6;
    PALANM_BlendColors(anime->original, anime->palette, anime->colorCount, weight, anime->targetColor);
    if (++anime->frame > 30) {
        PALETTE_ANIME_StopImpl(anime);
        PALETTE_ANIME_RestoreImpl(anime);
    }
}

/* Mode 6: strong blink (weight 0 or 9) for 20 frames, then stop and restore. */
void PALETTE_ANIME_StepBlinkStrong20(struct PaletteAnime *anime)
{
    int weight = ((anime->frame >> 2) & 1) == 0 ? 0 : 9;
    PALANM_BlendColors(anime->original, anime->palette, anime->colorCount, weight, anime->targetColor);
    if (++anime->frame > 20) {
        PALETTE_ANIME_StopImpl(anime);
        PALETTE_ANIME_RestoreImpl(anime);
    }
}

/* Mode 7: fade toward the target colour, weight rising 0..7 over 20 frames, then held at 7. */
void PALETTE_ANIME_StepFadeIn(struct PaletteAnime *anime)
{
    u32 frame = anime->frame;
    u8 weight;
    if (frame < 0x14)
        weight = (u8)(frame * 7 / 0x14);
    else
        weight = 7;
    PALANM_BlendColors(anime->original, anime->palette, anime->colorCount, weight, anime->targetColor);
    anime->frame++;
}

/* Mode 8: fade back, weight falling 7..0 over 30 frames, then stop and restore. */
void PALETTE_ANIME_StepFadeOut(struct PaletteAnime *anime)
{
    unsigned int weight = 7 - anime->frame * 7 / 30;
    PALANM_BlendColors(anime->original, anime->palette, anime->colorCount, (u8)weight, anime->targetColor);
    if (++anime->frame > 30) {
        PALETTE_ANIME_StopImpl(anime);
        PALETTE_ANIME_RestoreImpl(anime);
    }
}

/* Mode 9: hold the full blend (weight 7). */
void PALETTE_ANIME_StepHold(struct PaletteAnime *anime)
{
    PALANM_BlendColors(anime->original, anime->palette, anime->colorCount, 7, anime->targetColor);
    anime->frame++;
}

/* Copies the original colours back over the live palette. */
int PALETTE_ANIME_RestoreImpl(struct PaletteAnime *anime)
{
    return MI_CpuCopy8((int)anime->original, (int)anime->palette, anime->colorCount << 1);
}

/* Returns the running flag. */
u32 PALETTE_ANIME_IsRunningImpl(struct PaletteAnime *anime)
{
    return anime->running;
}

/* Allocates the 32-byte object and records the heap id. */
struct PaletteAnime *PALETTE_ANIME_Alloc(u32 heapId)
{
    struct PaletteAnime *anime = GFL_HEAP_Alloc(heapId, 32, 0, d_021C408C, 667);
    anime->heapId = heapId;
    return anime;
}

u32 PALETTE_ANIME_Free(struct PaletteAnime *anime)
{
    return GFL_HEAP_Free(anime);
}

/* Clears the object but keeps the heap id. */
void PALETTE_ANIME_Clear(struct PaletteAnime *anime)
{
    u16 heapId = anime->heapId;
    MI_CpuFill8(anime, 0, 0x20);
    anime->heapId = heapId;
}

/* Marks the animation initialized, stores the range and copies count colours from original into a heap buffer. */
void PALETTE_ANIME_BindImpl(struct PaletteAnime *anime, u16 *palette, u16 *original, int colorCount)
{
    int i;
    anime->initialized = 1;
    anime->palette = palette;
    anime->colorCount = colorCount;
    anime->original = GFL_HEAP_Alloc(anime->heapId, colorCount * 2, 0, d_021C408C, 728);
    for (i = 0; i < colorCount; i++)
        anime->original[i] = original[i];
}

/* Releases the colour buffer and clears the initialized flag. */
void PALETTE_ANIME_ReleaseOriginal(struct PaletteAnime *anime)
{
    GFL_HEAP_Free(anime->original);
    anime->initialized = 0;
}
