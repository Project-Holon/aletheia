/*
 * function: func_021C84D8
 * address:  0x021C84D8
 * packet:   pkt_021C84D8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CC668   0x021CC668  thumb ov093
 *   func_021C84D8   0x021C84D8  thumb ov093
 *
 * tail-call thunk to func_021CC668
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void func_021CC668(void);

void func_021C84D8(void)
{
    func_021CC668();
}
