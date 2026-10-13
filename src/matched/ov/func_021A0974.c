/*
 * function: FIELD_LIGHT_BeginBlendDefault
 * address:  0x021A0974
 * packet:   pkt_021A0974
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Calls FIELD_LIGHT_BeginBlend(its own argument 1, its own argument 2, its own argument 3, 0x3c) and returns nothing.
 *
 * symbols:
 *   FIELD_LIGHT_BeginBlend  0x021A0980  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void FIELD_LIGHT_BeginBlend(u8 *a, u8 *b, u8 *c, u32 d);

void FIELD_LIGHT_BeginBlendDefault(u32 a1, u32 a2, u32 a3)
{
    FIELD_LIGHT_BeginBlend((u8 *)a1, (u8 *)a2, (u8 *)a3, 0x3c);
}

