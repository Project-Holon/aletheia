/*
 * function: func_021ACBC8
 * address:  0x021ACBC8
 * packet:   pkt_ov021_021ACBC8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern int func_021AC1E0(u32 a);

void func_021ACBC8(u32 a, int v)
{
    u8 *p;

    if (a != 0) {
        p = (u8 *)func_021AC1E0(a);
        if (v == 1)
            p[10] = 0;
        else
            p[10] = 1;
    }
}
