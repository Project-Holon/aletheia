/*
 * function: func_021D53C0
 * address:  0x021D53C0
 * packet:   pkt_021D53C0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D53C8   0x021D53C8  thumb ov093
 *   func_021D53C0   0x021D53C0  thumb ov093
 *
 * tail-call thunk to func_021D53C8
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void func_021D53C8(unsigned char *p);

void func_021D53C0(unsigned char *p)
{
    func_021D53C8(p);
}
