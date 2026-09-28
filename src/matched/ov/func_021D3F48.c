/*
 * function: func_021D3F48
 * address:  0x021D3F48
 * packet:   pkt_021D3F48
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D3F48   0x021D3F48  thumb ov093
 *
 * strh v at #0xa
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

void func_021D3F48(u8 *p, u16 v)
{
    *(u16 *)&p[0xa] = v;
}
