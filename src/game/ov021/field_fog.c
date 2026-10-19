/*
 * file:     field_fog.c
 * unit:     yes
 * function: FIELD_FOG_Create, FIELD_FOG_Delete, FIELD_FOG_Main, FIELD_FOG_Reflect, FIELD_FOG_SetFlag, FIELD_FOG_SetBlendMode, FIELD_FOG_SetSlope, FIELD_FOG_SetOffset, FIELD_FOG_SetColorRgb, FIELD_FOG_SetColorA, FIELD_FOG_GetSlope, FIELD_FOG_InitFogTable, FIELD_FOG_FADE_Init, FIELD_FOG_FADE_InitEx, FIELD_FOG_FADE_IsFade, FIELD_FOG_FadeIsRunning, FIELD_FOG_FadeStart, FIELD_FOG_FadeStep, FIELD_FOG_FadeGetOffset, FIELD_FOG_FadeGetSlope
 * address:  0x021A0104
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split (CL110): __FILE__ anchor field_fog.c at 0x021A0104; ends at the field_zonefog.c anchor 0x021A02C4.
 * The fade helpers 0x021A0260..0x021A02A8 are called only by this file.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   d_021DDE1C     0x021DDE1C  data
 *   GFL_HEAP_Free  0x020307B0  arm
 *   G3X_SetFog  0x0207DC44  arm
 *   G3X_SetFogTable  0x0207DD10  arm
 */
#include "../types.h"

#define FIELD_FOG_TABLE_MAX 32

/* Linear fade of the fog offset and slope over a fixed number of frames. */
typedef struct {
    u16 frame;
    u16 frameMax;
    u32 startOffset;
    int offsetRange;
    u32 startSlope;
    int slopeRange;
} FieldFogFade;

/* Fog state of the field map (0x44 bytes); written to the 3D engine in FIELD_FOG_Reflect. */
typedef struct {
    u8 flag;
    u8 blendMode;
    u8 slope;
    u8 alpha;
    u32 offset;
    u16 colorRgb;
    u16 padA;
    u8 fogTable[FIELD_FOG_TABLE_MAX];
    FieldFogFade fade;
    u32 changed;
} FieldFog;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 GFL_HEAP_Free(void *p);
extern void G3X_SetFog(int enable, int fogMode, int fogSlope, int fogOffset);
extern void G3X_SetFogTable(void *src);
void FIELD_FOG_InitFogTable(FieldFog *fog);
int FIELD_FOG_FadeIsRunning(FieldFogFade *fade);
void FIELD_FOG_FadeStart(FieldFogFade *fade, u32 startOffset, u32 endOffset, u16 startSlope, u16 endSlope, u16 frames);
void FIELD_FOG_FadeStep(FieldFogFade *fade);
u32 FIELD_FOG_FadeGetOffset(FieldFogFade *fade);
u16 FIELD_FOG_FadeGetSlope(FieldFogFade *fade);
extern char d_021DDE1C[];

FieldFog *FIELD_FOG_Create(u16 heapId)
{
    FieldFog *fog = (FieldFog *)GFL_HEAP_Alloc(heapId, sizeof(FieldFog), 1, d_021DDE1C, 0x89);
    fog->blendMode = 0;
    fog->alpha = 0x1F;
    fog->offset = 0x7FFF;
    FIELD_FOG_InitFogTable(fog);
    return fog;
}

void FIELD_FOG_Delete(FieldFog *fog)
{
    GFL_HEAP_Free(fog);
}

void FIELD_FOG_Main(FieldFog *fog)
{
    if (FIELD_FOG_FadeIsRunning(&fog->fade)) {
        FIELD_FOG_FadeStep(&fog->fade);
        fog->offset = FIELD_FOG_FadeGetOffset(&fog->fade);
        fog->slope = FIELD_FOG_FadeGetSlope(&fog->fade);
        fog->changed = 1;
    }
}

static inline void SetFogColor(u16 color, int alpha)
{
    *(volatile u32 *)0x04000358 = (u32)(color | (alpha << 16));
}

void FIELD_FOG_Reflect(FieldFog *fog)
{
    if (fog->changed) {
        G3X_SetFog(fog->flag, fog->blendMode, fog->slope, fog->offset);
        SetFogColor(fog->colorRgb, fog->alpha);
        G3X_SetFogTable(fog->fogTable);
        fog->changed = 0;
    }
}

void FIELD_FOG_SetFlag(FieldFog *fog, u32 flag)
{
    fog->flag = flag;
    fog->changed = 1;
}

void FIELD_FOG_SetBlendMode(FieldFog *fog, u32 blendMode)
{
    fog->blendMode = blendMode;
    fog->changed = 1;
}

void FIELD_FOG_SetSlope(FieldFog *fog, u32 slope)
{
    fog->slope = slope;
    fog->changed = 1;
}

void FIELD_FOG_SetOffset(FieldFog *fog, u32 offset)
{
    fog->offset = offset;
    fog->changed = 1;
}

void FIELD_FOG_SetColorRgb(FieldFog *fog, u32 colorRgb)
{
    fog->colorRgb = colorRgb;
    fog->changed = 1;
}

void FIELD_FOG_SetColorA(FieldFog *fog, u32 alpha)
{
    fog->alpha = alpha;
    fog->changed = 1;
}

u32 FIELD_FOG_GetSlope(FieldFog *fog)
{
    return fog->slope;
}

/* Default fog table: a linear ramp, entry i = 4i + 4i/32. */
void FIELD_FOG_InitFogTable(FieldFog *fog)
{
    int i;
    for (i = 0; i < FIELD_FOG_TABLE_MAX; i++) {
        fog->fogTable[i] = i * 4;
        fog->fogTable[i] += (i * 4) / FIELD_FOG_TABLE_MAX;
    }
}

/* Fade from the current offset and slope to the given ones. */
void FIELD_FOG_FADE_Init(FieldFog *fog, u32 endOffset, u32 endSlope, u32 frames)
{
    FIELD_FOG_FadeStart(&fog->fade, fog->offset, endOffset, fog->slope, endSlope, frames);
}

void FIELD_FOG_FADE_InitEx(FieldFog *fog, u32 startOffset, u32 endOffset, u32 startSlope, u32 endSlope, u16 frames)
{
    FIELD_FOG_FadeStart(&fog->fade, startOffset, endOffset, startSlope, endSlope, frames);
}

int FIELD_FOG_FADE_IsFade(FieldFog *fog)
{
    return FIELD_FOG_FadeIsRunning(&fog->fade);
}

int FIELD_FOG_FadeIsRunning(FieldFogFade *fade)
{
    if (fade->frame < fade->frameMax) {
        return 1;
    }
    return 0;
}

void FIELD_FOG_FadeStart(FieldFogFade *fade, u32 startOffset, u32 endOffset, u16 startSlope, u16 endSlope, u16 frames)
{
    fade->frame = 0;
    fade->frameMax = frames;
    fade->startOffset = startOffset;
    fade->offsetRange = endOffset - startOffset;
    fade->startSlope = startSlope;
    fade->slopeRange = endSlope - startSlope;
}

void FIELD_FOG_FadeStep(FieldFogFade *fade)
{
    if (fade->frame < fade->frameMax) {
        fade->frame = fade->frame + 1;
    }
}

u32 FIELD_FOG_FadeGetOffset(FieldFogFade *fade)
{
    int value = fade->offsetRange * fade->frame / fade->frameMax;
    return value + fade->startOffset;
}

u16 FIELD_FOG_FadeGetSlope(FieldFogFade *fade)
{
    int value = fade->slopeRange * fade->frame / fade->frameMax;
    return value + fade->startSlope;
}
