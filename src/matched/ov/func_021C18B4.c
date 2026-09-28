/*
 * function: func_021C18B4
 * address:  0x021C18B4
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0203CD98  0x0203CD98  arm
 *
 * Returns the second argument, or 2 when sub_0203CD98 reports 0.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int sub_0203CD98(int a);

int func_021C18B4(int a, int b)
{
    int r = b;

    if (sub_0203CD98(a) == 0) {
        r = 2;
    }

    return r;
}
