/*
 * function: func_021B9DD4
 * address:  0x021B9DD4
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9DFC  0x021B9DFC  thumb
 *   func_021B9DEC  0x021B9DEC  thumb
 *
 * Fires the two thunks func_021B9DFC and func_021B9DEC on the same argument.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_021B9DFC(void *a);
extern void func_021B9DEC(void *a);

void func_021B9DD4(void *a)
{
    func_021B9DFC(a);
    func_021B9DEC(a);
}
