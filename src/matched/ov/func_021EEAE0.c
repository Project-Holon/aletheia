/*
 * function: func_021EEAE0
 * address:  0x021EEAE0
 * packet:   pkt_021EEAE0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0   0x020307B0  arm arm9
 *   func_021EEAE0   0x021EEAE0  thumb ov093
 *
 * tail-call thunk to func_020307B0
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern u32 func_020307B0(void *p);

void func_021EEAE0(void *p)
{
    func_020307B0(p);
}
