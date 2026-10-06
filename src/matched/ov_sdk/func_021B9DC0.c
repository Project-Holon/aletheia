/*
 * function: func_021B9DC0
 * address:  0x021B9DC0
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9DE4  0x021B9DE4  thumb  ov099
 *   func_021B9DF4  0x021B9DF4  thumb  ov099
 *
 * Two registered setup steps.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_021B9DE4(void *a, int b, u32 c);
extern void func_021B9DF4(void *a, int b);

void func_021B9DC0(void *a, u32 b, u32 c)
{
    func_021B9DE4(a, b, c);
    func_021B9DF4(a, b);
}
