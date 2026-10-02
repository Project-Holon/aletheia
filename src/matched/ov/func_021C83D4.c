/*
 * function: func_021C83D4
 * address:  0x021C83D4
 * packet:   pkt_021C83D4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC2B0   0x021BC2B0  thumb ov093
 *   func_021C83D4   0x021C83D4  thumb ov093
 *
 * tail-call thunk to func_021BC2B0
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int func_021BC2B0(u8 *p);

int func_021C83D4(u8 *p)
{
    return func_021BC2B0(p);
}
