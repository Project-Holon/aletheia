/*
 * function: EFFECT_ENCOUNT_Exit
 * address:  0x021AA7CC
 * packet:   pkt_021AA7CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   EFFECT_ENCOUNT_MarkSpotForRestore  0x021AAB54  thumb  ov021
 *   EFFECT_ENCOUNT_DeleteEffectObj  0x021AAFFC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 EFFECT_ENCOUNT_MarkSpotForRestore(u32, u32, u32, u32);
extern u32 EFFECT_ENCOUNT_DeleteEffectObj(u32);

int EFFECT_ENCOUNT_Exit(u32 a, u32 b, u32 c, u32 d)
{
EFFECT_ENCOUNT_MarkSpotForRestore(a, b, c, d);
return EFFECT_ENCOUNT_DeleteEffectObj(b);
}

