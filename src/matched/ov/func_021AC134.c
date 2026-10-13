/*
 * function: FIELD_EFFECT_ObjectTask
 * address:  0x021AC134
 * packet:   pkt_021AC134
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Untraced thunk: forwards the second argument.
 *
 * symbols:
 *   FIELD_EFFECT_UpdateObject  0x021AC178  thumb  ov021

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void FIELD_EFFECT_UpdateObject(u32 v);

void FIELD_EFFECT_ObjectTask(u32 a, u32 b)
{
    FIELD_EFFECT_UpdateObject(b);
}
