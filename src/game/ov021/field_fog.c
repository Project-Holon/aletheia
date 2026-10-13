/*
 * file:     field_fog.c
 * unit:     yes
 * function: func_021A0104, func_021A0138, func_021A0140, func_021A0170, func_021A01A4, func_021A01AC, func_021A01B4, func_021A01BC, func_021A01C4, func_021A01CC, func_021A01D4, func_021A01D8, func_021A01FC, func_021A0224, func_021A0244, func_021A0250, func_021A0260, func_021A0280, func_021A0290, func_021A02A8
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
 *   func_02030734  0x02030734  arm
 *   d_021DDE1C     0x021DDE1C  data
 *   func_020307B0  0x020307B0  arm
 *   func_0207DC44  0x0207DC44  arm
 *   func_0207DD10  0x0207DD10  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

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

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *p);
extern void func_0207DC44(int enable, int fogMode, int fogSlope, int fogOffset);
extern void func_0207DD10(u8 *fogTable);
void func_021A01D8(FieldFog *fog);
int func_021A0250(FieldFogFade *fade);
void func_021A0260(FieldFogFade *fade, u32 startOffset, u32 endOffset, u16 startSlope, u16 endSlope, u16 frames);
void func_021A0280(FieldFogFade *fade);
u32 func_021A0290(FieldFogFade *fade);
u16 func_021A02A8(FieldFogFade *fade);
extern char d_021DDE1C[];

FieldFog *func_021A0104(u16 heapId)
{
    FieldFog *fog = (FieldFog *)func_02030734(heapId, sizeof(FieldFog), 1, d_021DDE1C, 0x89);
    fog->blendMode = 0;
    fog->alpha = 0x1F;
    fog->offset = 0x7FFF;
    func_021A01D8(fog);
    return fog;
}

void func_021A0138(FieldFog *fog)
{
    func_020307B0(fog);
}

void func_021A0140(FieldFog *fog)
{
    if (func_021A0250(&fog->fade)) {
        func_021A0280(&fog->fade);
        fog->offset = func_021A0290(&fog->fade);
        fog->slope = func_021A02A8(&fog->fade);
        fog->changed = 1;
    }
}

static inline void SetFogColor(u16 color, int alpha)
{
    *(volatile u32 *)0x04000358 = (u32)(color | (alpha << 16));
}

void func_021A0170(FieldFog *fog)
{
    if (fog->changed) {
        func_0207DC44(fog->flag, fog->blendMode, fog->slope, fog->offset);
        SetFogColor(fog->colorRgb, fog->alpha);
        func_0207DD10(fog->fogTable);
        fog->changed = 0;
    }
}

void func_021A01A4(FieldFog *fog, u32 flag)
{
    fog->flag = flag;
    fog->changed = 1;
}

void func_021A01AC(FieldFog *fog, u32 blendMode)
{
    fog->blendMode = blendMode;
    fog->changed = 1;
}

void func_021A01B4(FieldFog *fog, u32 slope)
{
    fog->slope = slope;
    fog->changed = 1;
}

void func_021A01BC(FieldFog *fog, u32 offset)
{
    fog->offset = offset;
    fog->changed = 1;
}

void func_021A01C4(FieldFog *fog, u32 colorRgb)
{
    fog->colorRgb = colorRgb;
    fog->changed = 1;
}

void func_021A01CC(FieldFog *fog, u32 alpha)
{
    fog->alpha = alpha;
    fog->changed = 1;
}

u32 func_021A01D4(FieldFog *fog)
{
    return fog->slope;
}

/* Default fog table: a linear ramp, entry i = 4i + 4i/32. */
void func_021A01D8(FieldFog *fog)
{
    int i;
    for (i = 0; i < FIELD_FOG_TABLE_MAX; i++) {
        fog->fogTable[i] = i * 4;
        fog->fogTable[i] += (i * 4) / FIELD_FOG_TABLE_MAX;
    }
}

/* Fade from the current offset and slope to the given ones. */
void func_021A01FC(FieldFog *fog, u32 endOffset, u32 endSlope, u32 frames)
{
    func_021A0260(&fog->fade, fog->offset, endOffset, fog->slope, endSlope, frames);
}

void func_021A0224(FieldFog *fog, u32 startOffset, u32 endOffset, u32 startSlope, u32 endSlope, u16 frames)
{
    func_021A0260(&fog->fade, startOffset, endOffset, startSlope, endSlope, frames);
}

int func_021A0244(FieldFog *fog)
{
    return func_021A0250(&fog->fade);
}

int func_021A0250(FieldFogFade *fade)
{
    if (fade->frame < fade->frameMax) {
        return 1;
    }
    return 0;
}

void func_021A0260(FieldFogFade *fade, u32 startOffset, u32 endOffset, u16 startSlope, u16 endSlope, u16 frames)
{
    fade->frame = 0;
    fade->frameMax = frames;
    fade->startOffset = startOffset;
    fade->offsetRange = endOffset - startOffset;
    fade->startSlope = startSlope;
    fade->slopeRange = endSlope - startSlope;
}

void func_021A0280(FieldFogFade *fade)
{
    if (fade->frame < fade->frameMax) {
        fade->frame = fade->frame + 1;
    }
}

u32 func_021A0290(FieldFogFade *fade)
{
    int value = fade->offsetRange * fade->frame / fade->frameMax;
    return value + fade->startOffset;
}

u16 func_021A02A8(FieldFogFade *fade)
{
    int value = fade->slopeRange * fade->frame / fade->frameMax;
    return value + fade->startSlope;
}
