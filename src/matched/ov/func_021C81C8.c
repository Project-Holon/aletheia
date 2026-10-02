/*
 * function: func_021C81C8
 * address:  0x021C81C8
 * packet:   pkt_021C81C8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC948   0x021BC948  thumb ov093
 *   func_021C81C8   0x021C81C8  thumb ov093
 *
 * tail-call thunk to func_021BC948
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u16 func_021BC948(u8 *p, u8 *x, int flag);

u16 func_021C81C8(u8 *p, u8 *x, int flag)
{
    return func_021BC948(p, x, flag);
}
