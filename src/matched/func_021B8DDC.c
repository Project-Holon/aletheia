/*
 * function: func_021B8DDC
 * address:  0x021B8DDC
 * packet:   pkt_021B8DDC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B8D08   0x021B8D08  thumb ov093
 *   func_021B8DDC   0x021B8DDC  thumb ov093
 *
 * tail-call thunk to func_021B8D08
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void func_021B8D08(void);

void func_021B8DDC(void)
{
    func_021B8D08();
}
