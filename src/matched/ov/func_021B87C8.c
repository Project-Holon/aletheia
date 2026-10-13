/*
 * function: FIELD_RAIL_SETTING_Copy
 * address:  0x021B87C8
 * packet:   pkt_021B87C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call with the two arguments swapped.
 *
 * symbols:
 *   MI_CpuCopy8  0x02082D44  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void MI_CpuCopy8(u32 a, u32 b, u32 c);

void FIELD_RAIL_SETTING_Copy(u32 a, u32 b)
{
    MI_CpuCopy8(b, a, 0x30);
}
