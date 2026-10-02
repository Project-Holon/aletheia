/*
 * function: func_021DCF9C
 * address:  0x021DCF9C
 * packet:   pkt_021DCF9C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D7040   0x021D7040  thumb ov093
 *   func_021DCF9C   0x021DCF9C  thumb ov093
 *
 * tail-call thunk to func_021D7040
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void func_021D7040(void *n);

void func_021DCF9C(void *n)
{
    func_021D7040(n);
}
