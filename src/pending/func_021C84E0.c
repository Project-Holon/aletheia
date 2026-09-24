/*
 * function: func_021C84E0
 * address:  0x021C84E0
 * packet:   pkt_021C84E0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021C84F4   0x021C84F4  thumb ov093
 *   func_021C84E0   0x021C84E0  thumb ov093
 *
 * Blocking site: the ABS32 pool word at +0004 names 0x021C84F4, which is not a function
 * start in ov093's listing (it is a word inside a literal pool) and has no
 * witness outside this function's own bytes, so the field stays wildcarded and
 * the entry cannot reach EXACT.  Every concrete byte matches.
 *
 * tail-call thunk to func_021C84F4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void func_021C84F4(void);

void func_021C84E0(void)
{
    func_021C84F4();
}
