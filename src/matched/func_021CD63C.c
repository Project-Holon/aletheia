/*
 * function: func_021CD63C
 * address:  0x021CD63C
 * packet:   pkt_021CD63C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CCAA8   0x021CCAA8  thumb ov093
 *   func_021CD63C   0x021CD63C  thumb ov093
 *
 * tail-call thunk to func_021CCAA8
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void func_021CCAA8(void);

void func_021CD63C(void)
{
    func_021CCAA8();
}
