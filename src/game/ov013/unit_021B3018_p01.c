/*
 * file:     unit_021B3018_p01.c
 * unit:     yes
 * function: func_021B3018, func_021B3064
 * address:  0x021B3018
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B4C38     0x021B4C38  data a4
 *   d_021B4C2C     0x021B4C2C  data a4
 *   d_021B3C50     0x021B3C50  data a4
 *   func_02082D44  0x02082D44  arm
 */
#include "unit_021B3018_types.h"

extern u32 d_021B4C38[];
extern VadState d_021B4C2C;
extern VadCfg d_021B3C50;
extern void func_02082D44(void *dst, void *src, int n);

void func_021B3018(void);
void func_021B3064(void *p);

void func_021B3018(void)
{
    int i;
    for (i = 0; i < 4; i++) d_021B4C38[i] = 0x1000000;
    d_021B4C2C.f4 = 0;
    d_021B4C2C.f0 = 0;
    d_021B3C50.f0 = 0;
    d_021B3C50.f4 = 0;
    d_021B4C2C.f8 = 0;
}

void func_021B3064(void *p)
{
    if (!p)
        return;
    func_02082D44(&d_021B3C50, p, 0x10);
}
