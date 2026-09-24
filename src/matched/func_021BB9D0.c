/*
 * function: func_021BB9D0
 * address:  0x021BB9D0
 * packet:   pkt_021BB9D0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BB9D8   0x021BB9D8  thumb ov093
 *   func_021BB9D0   0x021BB9D0  thumb ov093
 *
 * tail-call thunk to func_021BB9D8
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void func_021BB9D8(void);

void func_021BB9D0(void)
{
    func_021BB9D8();
}
