/*
 * function: GX_SetBankForTex
 * address:  0x02080294
 * packet:   pkt_02080294
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libgx gx_vramcnt.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Assigns VRAM banks A..D to texture images: returns the banks no longer
 * used to LCDC, records the new set, turns 3D texturing off when no bank is
 * given (else on, clearing the acknowledge bits), programs VRAMCNT_A..D
 * (enable, MST 3, the slot in bits 3-4), then rewrites the LCDC mapping.
 *
 * symbols:
 *   GX_VRAMCNT_SetLCDC_  0x0207FD34  arm
 *   gGXState             0x02150E4C  data
 */

#include "../include/G_GX_State.h"

typedef unsigned short u16;
typedef unsigned char u8;
typedef volatile u8 vu8;
typedef volatile u16 vu16;

typedef enum {
    GX_VRAM_TEX_NONE = 0x00,
    GX_VRAM_TEX_0_A = 0x01,
    GX_VRAM_TEX_0_B = 0x02,
    GX_VRAM_TEX_0_C = 0x04,
    GX_VRAM_TEX_0_D = 0x08,
    GX_VRAM_TEX_01_AB = 0x03,
    GX_VRAM_TEX_012_ABC = 0x07,
    GX_VRAM_TEX_0123_ABCD = 0x0f,
    GX_VRAM_TEX_01_BC = 0x06,
    GX_VRAM_TEX_012_BCD = 0x0e,
    GX_VRAM_TEX_01_CD = 0x0c,
    GX_VRAM_TEX_01_AC = 0x05,
    GX_VRAM_TEX_01_AD = 0x09,
    GX_VRAM_TEX_01_BD = 0x0a,
    GX_VRAM_TEX_012_ABD = 0x0b,
    GX_VRAM_TEX_012_ACD = 0x0d
} GXVRamTex;

extern struct GX_State gGXState;

extern void GX_VRAMCNT_SetLCDC_(int lcdc);

#define reg_G3X_DISP3DCNT (*(vu16 *)0x04000060)

#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)
#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)
#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)
#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)

#define REG_G3X_DISP3DCNT_TME_MASK 0x0001
#define REG_G3X_DISP3DCNT_RO_MASK  0x3000

#define VRAMCNT(ofs) (0x80 | 3 | ((ofs) << 3))

void GX_SetBankForTex(GXVRamTex tex)
{
    gGXState.vramCnt_lcdc = (u16)(~tex & (gGXState.vramCnt_lcdc | gGXState.vramCnt_tex));
    gGXState.vramCnt_tex = (u16)tex;

    if (tex == GX_VRAM_TEX_NONE) {
        reg_G3X_DISP3DCNT &= ~(REG_G3X_DISP3DCNT_RO_MASK | REG_G3X_DISP3DCNT_TME_MASK);
    } else {
        reg_G3X_DISP3DCNT = (u16)((reg_G3X_DISP3DCNT & ~REG_G3X_DISP3DCNT_RO_MASK) | REG_G3X_DISP3DCNT_TME_MASK);

        switch (tex) {
        case GX_VRAM_TEX_01_AC:
            reg_GX_VRAMCNT_A = VRAMCNT(0);
            reg_GX_VRAMCNT_C = VRAMCNT(1);
            break;
        case GX_VRAM_TEX_01_AD:
            reg_GX_VRAMCNT_A = VRAMCNT(0);
            reg_GX_VRAMCNT_D = VRAMCNT(1);
            break;
        case GX_VRAM_TEX_01_BD:
            reg_GX_VRAMCNT_B = VRAMCNT(0);
            reg_GX_VRAMCNT_D = VRAMCNT(1);
            break;
        case GX_VRAM_TEX_012_ABD:
            reg_GX_VRAMCNT_A = VRAMCNT(0);
            reg_GX_VRAMCNT_B = VRAMCNT(1);
            reg_GX_VRAMCNT_D = VRAMCNT(2);
            break;
        case GX_VRAM_TEX_012_ACD:
            reg_GX_VRAMCNT_A = VRAMCNT(0);
            reg_GX_VRAMCNT_C = VRAMCNT(1);
            reg_GX_VRAMCNT_D = VRAMCNT(2);
            break;
        case GX_VRAM_TEX_0_D:
            reg_GX_VRAMCNT_D = VRAMCNT(0);
            break;
        case GX_VRAM_TEX_01_CD:
            reg_GX_VRAMCNT_D = VRAMCNT(1);
        case GX_VRAM_TEX_0_C:
            reg_GX_VRAMCNT_C = VRAMCNT(0);
            break;
        case GX_VRAM_TEX_012_BCD:
            reg_GX_VRAMCNT_D = VRAMCNT(2);
        case GX_VRAM_TEX_01_BC:
            reg_GX_VRAMCNT_C = VRAMCNT(1);
        case GX_VRAM_TEX_0_B:
            reg_GX_VRAMCNT_B = VRAMCNT(0);
            break;
        case GX_VRAM_TEX_0123_ABCD:
            reg_GX_VRAMCNT_D = VRAMCNT(3);
        case GX_VRAM_TEX_012_ABC:
            reg_GX_VRAMCNT_C = VRAMCNT(2);
        case GX_VRAM_TEX_01_AB:
            reg_GX_VRAMCNT_B = VRAMCNT(1);
        case GX_VRAM_TEX_0_A:
            reg_GX_VRAMCNT_A = VRAMCNT(0);
            break;
        default:
            break;
        }
    }
    GX_VRAMCNT_SetLCDC_(gGXState.vramCnt_lcdc);
}
