/*
 * function: FLDEFF_SHADOW_Start
 * address:  0x021AC2C0
 * packet:   pkt_ov021_021AC2C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gFldeffShadowObjFuncs  0x021D9098  data
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Arg { u32 a; u32 b; } Arg;

extern int FIELD_EFFECT_GetResource(u32 a, u32 b);
extern void FIELD_EFFECT_AddObject(u32 a, u8 *b, u32 c, u32 d, Arg *e, u32 f);
extern u8 gFldeffShadowObjFuncs[];

void FLDEFF_SHADOW_Start(u32 a, u32 b)
{
    Arg s;

    s.a = FIELD_EFFECT_GetResource(b, 0);
    s.b = a;
    FIELD_EFFECT_AddObject(b, gFldeffShadowObjFuncs, 0, 0, &s, 0);
}
