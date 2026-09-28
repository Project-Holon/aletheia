/*
 * function: func_0207D4B0
 * address:  0x0207D4B0
 * packet:   pkt_0207D4B0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GX_SetGraphicsMode  0x0207D4B0  arm
 *   sIsDispOn           0x020A84BC  data
 *   sDispMode           0x02150E0C  data
 *
 * TwlSDK libgx gx.o. Specifies display mode and BG mode for the MAIN engine.
 */

typedef unsigned int u32;
typedef unsigned short u16;

#define reg_GX_DISPCNT (*(volatile u32 *)0x04000000)

#define REG_GX_DISPCNT_MODE_MASK   0x00030000
#define REG_GX_DISPCNT_MODE_SHIFT  16
#define REG_GX_DISPCNT_VRAM_MASK   0x000C0000
#define REG_GX_DISPCNT_BGMODE_MASK 0x00000007
#define REG_GX_DISPCNT_BG02D3D_MASK 0x00000008
#define REG_GX_DISPCNT_BGMODE_SHIFT 0
#define REG_GX_DISPCNT_BG02D3D_SHIFT 3

#define GX_DISPMODE_OFF 0

extern u16 sDispMode;
extern u16 sIsDispOn;

void func_0207D4B0(int dispMode, int bgMode, int bg0_2d3d)
{
    u32 cnt = reg_GX_DISPCNT;

    sDispMode = (u16)dispMode;
    if (!sIsDispOn)
    {
        dispMode = GX_DISPMODE_OFF;
    }

    cnt &= ~(REG_GX_DISPCNT_BGMODE_MASK |
             REG_GX_DISPCNT_BG02D3D_MASK | REG_GX_DISPCNT_MODE_MASK | REG_GX_DISPCNT_VRAM_MASK);

    reg_GX_DISPCNT = (u32)(cnt |
                           (dispMode << REG_GX_DISPCNT_MODE_SHIFT) |
                           (bgMode << REG_GX_DISPCNT_BGMODE_SHIFT) | (bg0_2d3d <<
                                                                      REG_GX_DISPCNT_BG02D3D_SHIFT));

    if (sDispMode == GX_DISPMODE_OFF)
    {
        sIsDispOn = 0;
    }
}
