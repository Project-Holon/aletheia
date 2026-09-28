/*
 * function: func_021D3FA8
 * address:  0x021D3FA8
 * packet:   pkt_021D3FA8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D3FA8   0x021D3FA8  thumb ov093
 *
 * ldrh at #0x8
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

u16 func_021D3FA8(u8 *p)
{
    return *(u16 *)&p[0x8];
}
