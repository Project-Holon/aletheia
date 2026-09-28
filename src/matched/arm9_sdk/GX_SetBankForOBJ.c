/*
 * function: GX_SetBankForOBJ
 * address:  0x0207FFD0
 * packet:   pkt_0207FFD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libgx gx_vramcnt.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Assigns VRAM banks A, B, E, F, G to main-engine OBJ (MST 2), the same
 * shape as GX_SetBankForBG.
 *
 * symbols:
 *   GX_VRAMCNT_SetLCDC_  0x0207FD34  arm
 *   gGXState             0x02150E4C  data
 */

typedef unsigned short u16;
typedef unsigned char u8;
typedef volatile u8 vu8;

typedef enum {
    GX_VRAM_OBJ_NONE = 0x00,
    GX_VRAM_OBJ_16_F = 0x20,
    GX_VRAM_OBJ_16_G = 0x40,
    GX_VRAM_OBJ_32_FG = 0x60,
    GX_VRAM_OBJ_64_E = 0x10,
    GX_VRAM_OBJ_80_EF = 0x30,
    GX_VRAM_OBJ_80_EG = 0x50,
    GX_VRAM_OBJ_96_EFG = 0x70,
    GX_VRAM_OBJ_128_A = 0x01,
    GX_VRAM_OBJ_128_B = 0x02,
    GX_VRAM_OBJ_256_AB = 0x03
} GXVRamOBJ;

typedef struct {
    u16 lcdc;
    u16 bg;
    u16 obj;
} GXVRamState;

extern GXVRamState gGXState;

extern void GX_VRAMCNT_SetLCDC_(int lcdc);

#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)
#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)
#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)
#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)
#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)

#define VRAMCNT(ofs) (0x80 | 2 | ((ofs) << 3))

void GX_SetBankForOBJ(GXVRamOBJ obj)
{
    gGXState.lcdc = (u16)(~obj & (gGXState.lcdc | gGXState.obj));
    gGXState.obj = (u16)obj;

    switch (obj) {
    case GX_VRAM_OBJ_256_AB:
        reg_GX_VRAMCNT_B = VRAMCNT(1);
    case GX_VRAM_OBJ_128_A:
        reg_GX_VRAMCNT_A = VRAMCNT(0);
        break;
    case GX_VRAM_OBJ_128_B:
        reg_GX_VRAMCNT_B = VRAMCNT(0);
        break;
    case GX_VRAM_OBJ_96_EFG:
        reg_GX_VRAMCNT_G = VRAMCNT(3);
    case GX_VRAM_OBJ_80_EF:
        reg_GX_VRAMCNT_F = VRAMCNT(2);
    case GX_VRAM_OBJ_64_E:
        reg_GX_VRAMCNT_E = VRAMCNT(0);
        break;
    case GX_VRAM_OBJ_80_EG:
        reg_GX_VRAMCNT_G = VRAMCNT(2);
        reg_GX_VRAMCNT_E = VRAMCNT(0);
        break;
    case GX_VRAM_OBJ_32_FG:
        reg_GX_VRAMCNT_G = VRAMCNT(1);
    case GX_VRAM_OBJ_16_F:
        reg_GX_VRAMCNT_F = VRAMCNT(0);
        break;
    case GX_VRAM_OBJ_16_G:
        reg_GX_VRAMCNT_G = VRAMCNT(0);
        break;
    case GX_VRAM_OBJ_NONE:
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.lcdc);
}
