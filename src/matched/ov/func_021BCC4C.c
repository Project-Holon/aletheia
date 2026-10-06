/*
 * function: func_021BCC4C
 * address:  0x021BCC4C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BCBD8  0x021BCBD8  thumb
 *
 * Tail call onto func_021BCBD8 with a zero second argument.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern u32 func_021BCBD8(char *p, int m);

void func_021BCC4C(void *a)
{
    func_021BCBD8(a, 0);
}
