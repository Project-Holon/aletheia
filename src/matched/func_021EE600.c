/*
 * function: func_021EE600
 * address:  0x021EE600
 * packet:   pkt_021EE600
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0   0x020307B0  arm arm9
 *   func_021EE600   0x021EE600  thumb ov093
 *
 * tail-call thunk to func_020307B0
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void func_020307B0(void);

void func_021EE600(void)
{
    func_020307B0();
}
