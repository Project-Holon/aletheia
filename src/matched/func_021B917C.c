/*
 * function: func_021B917C
 * address:  0x021B917C
 * packet:   pkt_021B917C
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA54C   0x021BA54C  thumb ov093
 *   func_021B917C   0x021B917C  thumb ov093
 *
 * tail-call thunk to func_021BA54C
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void func_021BA54C(void);

void func_021B917C(void)
{
    func_021BA54C();
}
