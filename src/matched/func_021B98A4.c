/*
 * function: func_021B98A4
 * address:  0x021B98A4
 * packet:   pkt_021B98A4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B98AC   0x021B98AC  thumb ov093
 *   func_021B98A4   0x021B98A4  thumb ov093
 *
 * tail-call thunk to func_021B98AC
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void func_021B98AC(void);

void func_021B98A4(void)
{
    func_021B98AC();
}
