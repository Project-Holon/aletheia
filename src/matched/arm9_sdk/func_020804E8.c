/*
 * function: func_020804E8
 * address:  0x020804E8
 * packet:   pkt_020804E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GX_SetBankForClearImage (libgx.TWL.HYB.a gx_vramcnt.o)
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

#define reg_G3X_DISP3DCNT (*(vu16 *)0x04000060)
extern GX_State gGXState;
extern void GX_VRAMCNT_SetLCDC_(int lcdc);

void func_020804E8(int clrImg)
{
    gGXState.vramCnt.lcdc = (u16)(~clrImg & (gGXState.vramCnt.lcdc | gGXState.vramCnt.clrImg));
    gGXState.vramCnt.clrImg = (u16)clrImg;

    switch (clrImg) {
    case 0x003:
        reg_GX_VRAMCNT_A = 0x93;
        /* fall through */
    case 0x002:
        reg_GX_VRAMCNT_B = 0x9b;
        reg_G3X_DISP3DCNT |= 0x4000;
        break;
    case 0x00c:
        reg_GX_VRAMCNT_C = 0x93;
        /* fall through */
    case 0x008:
        reg_GX_VRAMCNT_D = 0x9b;
        reg_G3X_DISP3DCNT |= 0x4000;
        break;
    case 0:
        reg_G3X_DISP3DCNT &= ~0x4000;
        break;
    case 0x001:
        reg_GX_VRAMCNT_A = 0x9b;
        reg_G3X_DISP3DCNT |= 0x4000;
        break;
    case 0x004:
        reg_GX_VRAMCNT_C = 0x9b;
        reg_G3X_DISP3DCNT |= 0x4000;
        break;
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt.lcdc);
}
