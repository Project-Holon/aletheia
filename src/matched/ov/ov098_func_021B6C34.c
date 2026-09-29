/*
 * function: func_021B6C34
 * address:  0x021B6C34
 * packet:   pkt_ov098_021B6C34
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The handed extent runs on into the unlabelled leaf func_021B6C60
 * (filed as ov098_func_021B6C60.c).
 *
 * symbols:
 *   func_0207D63C  0x0207D63C  arm
 */

typedef unsigned char u8;

extern void func_0207D63C(int, int, int, int, int);

void func_021B6C34(char *p, int a)
{
    *(int *)p = a;
    *(u8 *)(p + 0x14) = 0;
    *(int *)(p + 4) = 0x1f000;
    *(int *)(p + 8) = 0x7000;
    func_0207D63C(0x04000050, 2, 0x3d, 0x1f, 7);
}
