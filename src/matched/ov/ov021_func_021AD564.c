/*
 * function: FLDEFF_NAMIPOKE_SPLASH_StartOnEffect
 * address:  0x021AD564
 * packet:   pkt_ov021_021AD564
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sNamipokeSplashFuncs  0x021D9170  data
 *   FIELD_EFFECT_GetResource  0x021ABEA0  thumb  ov021
 *   FIELD_EFFECT_AddObject  0x021ABFA8  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct Arg { u32 f0; u32 f4; u32 f8; u32 fc; } Arg;

extern int FIELD_EFFECT_GetResource(u32 a, u32 b);
extern void FIELD_EFFECT_AddObject(u32 a, u8 *b, u32 c, u32 d, Arg *e, u32 f);
extern u8 sNamipokeSplashFuncs[];

void FLDEFF_NAMIPOKE_SPLASH_StartOnEffect(u32 a, u32 b, u32 c)
{
    Arg s;

    s.f4 = FIELD_EFFECT_GetResource(a, 9);
    s.f8 = b;
    s.fc = c;
    s.f0 = 0;
    FIELD_EFFECT_AddObject(a, sNamipokeSplashFuncs, 0, 0, &s, 1);
}
