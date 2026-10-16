/*
 * function: G2x_SetBGyAffine_
 * address:  0x0207D59C
 * packet:   pkt_0207D59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      G2x_SetBGyAffine_ (libgx.TWL.HYB.a g2.o)
 * notes:    y2 is computed before the x row, and the x row is folded into its store (DWARF lists dx, dy, y2 and no x2); matrix stores before dx/dy.
 *
 * symbols:
 *   (none)
 */

typedef long fx32;
typedef short fx16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;

typedef union {
    struct {
        fx32 _00, _01;
        fx32 _10, _11;
    };
    fx32 m[2][2];
    fx32 a[4];
} MtxFx22;

typedef struct {
    u16 lcdc;
    u16 bg;
    u16 obj;
    u16 arm7;
    u16 tex;
    u16 texPltt;
    u16 clrImg;
    u16 bgExtPltt;
    u16 objExtPltt;
    u16 sub_bg;
    u16 sub_obj;
    u16 sub_bgExtPltt;
    u16 sub_objExtPltt;
} GX_VRAMCnt_;

typedef struct {
    GX_VRAMCnt_ vramCnt;
} GX_State;

#define reg_GX_VRAMCNT   (*(vu32 *)0x04000240)
#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)
#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)
#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)
#define reg_GX_VRAM_HI_CNT (*(vu16 *)0x04000248)

#define GX_FX32_FX16(x) ((fx16)((x) >> 4))

void G2x_SetBGyAffine_(u32 addr, const MtxFx22 *mtx, int centerX, int centerY, int x1, int y1)
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
