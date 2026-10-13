/*
 * file:     fx.c
 * unit:     yes
 * function: FX_Init, func_0207D14C
 * address:  0x0207D148
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * sdk:      FX_Modf (libfx.TWL.HYB.a fx.o)
 *   (none)
 */
typedef long fx32;

typedef short fx16;

typedef unsigned short u16;

void FX_Init(void);
fx32 func_0207D14C(fx32 x, fx32 *iPtr);

void FX_Init(void){ }


fx32 func_0207D14C(fx32 x, fx32 *iPtr)
{
    if (x >= 0) {
        *iPtr = x & 0x7ffff000;
        return x & 0xfff;
    } else {
        *iPtr = -(-x & 0x7ffff000);
        return -(-x & 0xfff);
    }
}
