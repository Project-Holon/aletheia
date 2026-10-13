/*
 * file:     gxstate.c
 * function: func_02080CC4
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

extern GX_State gGXState;

void func_02080CC4(void)
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
