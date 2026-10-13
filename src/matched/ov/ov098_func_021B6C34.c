/*
 * function: PDC_MSG_InitBlend
 * address:  0x021B6C34
 * packet:   pkt_ov098_021B6C34
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The handed extent runs on into the unlabelled leaf PDC_MSG_BlendStartFadeIn
 * (filed as ov098_func_021B6C60.c).
 *
 * symbols:
 *   func_0207D63C  0x0207D63C  arm
 */
#include "../include/Obj07937.h"

typedef unsigned char u8;

extern void func_0207D63C(int, int, int, int, int);

void PDC_MSG_InitBlend(char *p, int a)
{
    ((struct Obj07937 *)p)->f0 = a;
    ((struct Obj07937 *)p)->f14 = 0;
    ((struct Obj07937 *)p)->f4 = 0x1f000;
    ((struct Obj07937 *)p)->f8 = 0x7000;
    func_0207D63C(0x04000050, 2, 0x3d, 0x1f, 7);
}
