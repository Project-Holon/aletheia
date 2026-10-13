/*
 * function: FIELD_FOG_FADE_IsFade
 * address:  0x021A0244
 * packet:   pkt_021A0244
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk on the object 0x2c bytes in.
 *
 * symbols:
 *   FIELD_FOG_FadeIsRunning  0x021A0250  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int FIELD_FOG_FadeIsRunning(u32 a);

int FIELD_FOG_FADE_IsFade(u8 *p)
{
    return FIELD_FOG_FadeIsRunning((u32)(p + 0x2c));
}
