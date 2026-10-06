/*
 * file:     unit_0207FD34_p02.c
 * unit:     yes
 * function: func_02080100, func_020801F8
 * address:  0x02080100
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GX_VRAMCNT_SetLCDC_   0x0207FD34  arm
 *   gGXState              0x02150E4C  data
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

typedef enum {
    GX_VRAM_NONE = 0x0000,
    GX_VRAM_A = 0x0001,
    GX_VRAM_B = 0x0002,
    GX_VRAM_C = 0x0004,
    GX_VRAM_D = 0x0008,
    GX_VRAM_E = 0x0010,
    GX_VRAM_F = 0x0020,
    GX_VRAM_G = 0x0040,
    GX_VRAM_H = 0x0080,
    GX_VRAM_I = 0x0100
} GXVRam;

extern void GX_VRAMCNT_SetLCDC_(int lcdc);
void func_02080100(int bgExtPltt);
void func_020801F8(int objExtPltt);
extern GX_State gGXState;


#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)

#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)

#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)

#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)

#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)

#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)

#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)

#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)

#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)

#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)

#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)


#define reg_G3X_DISP3DCNT (*(vu16 *)0x04000060)


/*
 * sdk:      GX_SetBankForBGExtPltt (libgx.TWL.HYB.a gx_vramcnt.o)
 */
void func_02080100(int bgExtPltt)
{
    gGXState.vramCnt.lcdc = (u16)(~bgExtPltt & (gGXState.vramCnt.lcdc | gGXState.vramCnt.bgExtPltt));
    gGXState.vramCnt.bgExtPltt = (u16)bgExtPltt;

    switch (bgExtPltt) {
    case 0:
        reg_GX_DISPCNT &= ~0x40000000;
        break;
    case 0x010:
        reg_GX_DISPCNT |= 0x40000000;
        reg_GX_VRAMCNT_E = 0x84;
        break;
    case 0x040:
        reg_GX_DISPCNT |= 0x40000000;
        reg_GX_VRAMCNT_G = 0x8c;
        break;
    case 0x060:
        reg_GX_VRAMCNT_G = 0x8c;
        /* fall through */
    case 0x020:
        reg_GX_VRAMCNT_F = 0x84;
        reg_GX_DISPCNT |= 0x40000000;
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}


#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)

#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)

#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)

#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)

#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)

#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)

#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)

#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)

#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)

#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)

#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)


#define reg_G3X_DISP3DCNT (*(vu16 *)0x04000060)


/*
 * sdk:      GX_SetBankForOBJExtPltt (libgx.TWL.HYB.a gx_vramcnt.o)
 */
void func_020801F8(int objExtPltt)
{
    gGXState.vramCnt.lcdc = (u16)(~objExtPltt & (gGXState.vramCnt.lcdc | gGXState.vramCnt.objExtPltt));
    gGXState.vramCnt.objExtPltt = (u16)objExtPltt;

    switch (objExtPltt) {
    case 0x020:
        reg_GX_DISPCNT |= 0x80000000;
        reg_GX_VRAMCNT_F = 0x85;
        break;
    case 0x040:
        reg_GX_DISPCNT |= 0x80000000;
        reg_GX_VRAMCNT_G = 0x85;
        break;
    case 0:
        reg_GX_DISPCNT &= ~0x80000000;
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}
