/*
 * file:     gxstate.c
 * function: GX_InitGXState
 * address:  0x02080CC4
 * packet:   pkt_02080CC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GX_InitGXState (libgx.TWL.HYB.a gxstate.o)
 *
 * symbols:
 *   gGXState   0x02150E4C  data
 */

#include "../types.h"
#include "../sdk_ioreg.h"

#include "../sdk_fx.h"

#include "../sdk_gx.h"

#define reg_GX_VRAMCNT   (*(vu32 *)REG_VRAMCNT_A_ADDR)
#define reg_GX_VRAMCNT_E (*(vu8 *)REG_VRAMCNT_E_ADDR)
#define reg_GX_VRAMCNT_F (*(vu8 *)REG_VRAMCNT_F_ADDR)
#define reg_GX_VRAMCNT_G (*(vu8 *)REG_VRAMCNT_G_ADDR)
#define reg_GX_VRAM_HI_CNT (*(vu16 *)REG_VRAMCNT_H_ADDR)

#define GX_FX32_FX16(x) ((fx16)((x) >> 4))

extern GX_State gGXState;

void GX_InitGXState(void)
{
    gGXState.vramCnt.lcdc = 0;
    gGXState.vramCnt.bg = 0;
    gGXState.vramCnt.obj = 0;
    gGXState.vramCnt.arm7 = 0;
    gGXState.vramCnt.tex = 0;
    gGXState.vramCnt.texPltt = 0;
    gGXState.vramCnt.clrImg = 0;
    gGXState.vramCnt.bgExtPltt = 0;
    gGXState.vramCnt.objExtPltt = 0;
    gGXState.vramCnt.sub_bg = 0;
    gGXState.vramCnt.sub_obj = 0;
    gGXState.vramCnt.sub_bgExtPltt = 0;
    gGXState.vramCnt.sub_objExtPltt = 0;
    reg_GX_VRAMCNT = 0;
    reg_GX_VRAMCNT_E = 0;
    reg_GX_VRAMCNT_F = 0;
    reg_GX_VRAMCNT_G = 0;
    reg_GX_VRAM_HI_CNT = 0;
}
