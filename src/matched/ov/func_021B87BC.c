/*
 * function: FIELD_RAIL_SETTING_Clear
 * address:  0x021B87BC
 * packet:   pkt_021B87BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call thunk: pins arguments 2 and 3 to 0 and 48.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void MI_CpuFill8();

void FIELD_RAIL_SETTING_Clear(u32 a)
{
    MI_CpuFill8(a, 0, 48);
}
