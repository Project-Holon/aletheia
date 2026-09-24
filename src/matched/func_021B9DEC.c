/*
 * function: func_021B9DEC
 * address:  0x021B9DEC
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9EA0  0x021B9EA0  thumb
 *
 * Tail call thunk onto func_021B9EA0.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_021B9EA0(void *a);

void func_021B9DEC(void *a)
{
    func_021B9EA0(a);
}
