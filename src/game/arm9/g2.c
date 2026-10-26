/*
 * file:     g2.c
 * unit:     yes
 * function: G2x_SetBGyAffine_, G2x_SetBlendAlpha_, G2x_SetBlendBrightness_, G2x_SetBlendBrightnessExt_, DWCi_WindowG2x_ChangeBlendBrightness_
 * address:  0x0207D59C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#include "../types.h"
#include "../sdk_ioreg.h"

#include "../sdk_fx.h"

#include "../sdk_gx.h"

void G2x_SetBGyAffine_(uptr addr, const MtxFx22 *mtx, int centerX, int centerY, int x1, int y1);
void G2x_SetBlendAlpha_(unsigned int *reg, unsigned int a, unsigned int b, unsigned int c, unsigned int d);
void G2x_SetBlendBrightness_(uptr addr, int plane, int brightness);
void G2x_SetBlendBrightnessExt_(uptr addr, int plane1, int plane2, int ev1, int ev2, int brightness);
void DWCi_WindowG2x_ChangeBlendBrightness_(uptr addr, int brightness);

#define reg_GX_VRAMCNT   (*(vu32 *)REG_VRAMCNT_A_ADDR)

#define reg_GX_VRAMCNT_E (*(vu8 *)REG_VRAMCNT_E_ADDR)

#define reg_GX_VRAMCNT_F (*(vu8 *)REG_VRAMCNT_F_ADDR)

#define reg_GX_VRAMCNT_G (*(vu8 *)REG_VRAMCNT_G_ADDR)

#define reg_GX_VRAM_HI_CNT (*(vu16 *)REG_VRAMCNT_H_ADDR)

#define GX_FX32_FX16(x) ((fx16)((x) >> 4))

/*
 * sdk:      G2x_SetBGyAffine_ (libgx.TWL.HYB.a g2.o)
 * notes:    y2 is computed before the x row, and the x row is folded into its store (DWARF lists dx, dy, y2 and no x2); matrix stores before dx/dy.
 */
void G2x_SetBGyAffine_(uptr addr, const MtxFx22 *mtx, int centerX, int centerY, int x1, int y1)
{
    fx32 dx, dy, y2;

    ((vu32 *)addr)[0] = (u32)((u16)GX_FX32_FX16(mtx->_00) | ((u16)GX_FX32_FX16(mtx->_01) << 16));
    ((vu32 *)addr)[1] = (u32)((u16)GX_FX32_FX16(mtx->_10) | ((u16)GX_FX32_FX16(mtx->_11) << 16));
    dx = x1 - centerX;
    dy = y1 - centerY;
    y2 = mtx->_10 * dx + mtx->_11 * dy + (centerY << 12);
    ((vu32 *)addr)[2] = (u32)((mtx->_00 * dx + mtx->_01 * dy + (centerX << 12)) >> 4);
    ((vu32 *)addr)[3] = (u32)(y2 >> 4);
}

void G2x_SetBlendAlpha_(unsigned int *reg, unsigned int a, unsigned int b,
                        unsigned int c, unsigned int d)
{
    *reg = (a | 0x40) | (b << 8) | ((c | (d << 8)) << 16);
}

#define reg_GX_DISPSTAT (*(vu16 *)REG_DISPSTAT_ADDR)

/*
 * sdk:      G2x_SetBlendBrightness_ (libgx.TWL.HYB.a g2.o)
 */
void G2x_SetBlendBrightness_(uptr addr, int plane, int brightness)
{
    if (brightness < 0) {
        *(vu16 *)addr = (u16)(plane | 0xc0);
        *(vu16 *)(addr + 4) = (u16)-brightness;
    } else {
        *(vu16 *)addr = (u16)(plane | 0x80);
        *(vu16 *)(addr + 4) = (u16)brightness;
    }
}

#define reg_GX_DISPSTAT (*(vu16 *)REG_DISPSTAT_ADDR)

/*
 * sdk:      G2x_SetBlendBrightnessExt_ (libgx.TWL.HYB.a g2.o)
 */
void G2x_SetBlendBrightnessExt_(uptr addr, int plane1, int plane2, int ev1, int ev2, int brightness)
{
    *(vu16 *)(addr + 2) = (u16)(ev1 | (ev2 << 8));
    if (brightness < 0) {
        *(vu16 *)addr = (u16)(plane1 | 0xc0 | (plane2 << 8));
        *(vu16 *)(addr + 4) = (u16)-brightness;
    } else {
        *(vu16 *)addr = (u16)(plane1 | 0x80 | (plane2 << 8));
        *(vu16 *)(addr + 4) = (u16)brightness;
    }
}

#define reg_GX_DISPSTAT (*(vu16 *)REG_DISPSTAT_ADDR)

/*
 * sdk:      G2x_ChangeBlendBrightness_ (libgx.TWL.HYB.a g2.o)
 */
void DWCi_WindowG2x_ChangeBlendBrightness_(uptr addr, int brightness)
{
    u16 tmp = *(vu16 *)addr;

    if (brightness < 0) {
        if ((tmp & 0xc0) == 0x80) {
            *(vu16 *)addr = (u16)((tmp & ~0xc0) | 0xc0);
        }
        *(vu16 *)(addr + 4) = (u16)-brightness;
    } else {
        if ((tmp & 0xc0) == 0xc0) {
            *(vu16 *)addr = (u16)((tmp & ~0xc0) | 0x80);
        }
        *(vu16 *)(addr + 4) = (u16)brightness;
    }
}
