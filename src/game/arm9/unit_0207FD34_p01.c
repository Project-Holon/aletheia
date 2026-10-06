/*
 * file:     unit_0207FD34_p01.c
 * unit:     yes
 * function: func_0207FD34, func_0207FDCC
 * address:  0x0207FD34
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
 *   gGXState             0x02150E4C  data
 */
typedef unsigned char u8;

typedef volatile u8 vu8;

typedef unsigned short u16;

typedef enum {
    GX_VRAM_BG_NONE = 0x00,
    GX_VRAM_BG_16_F = 0x20,
    GX_VRAM_BG_16_G = 0x40,
    GX_VRAM_BG_32_FG = 0x60,
    GX_VRAM_BG_64_E = 0x10,
    GX_VRAM_BG_80_EF = 0x30,
    GX_VRAM_BG_80_EG = 0x50,
    GX_VRAM_BG_96_EFG = 0x70,
    GX_VRAM_BG_128_A = 0x01,
    GX_VRAM_BG_128_B = 0x02,
    GX_VRAM_BG_128_C = 0x04,
    GX_VRAM_BG_128_D = 0x08,
    GX_VRAM_BG_256_AB = 0x03,
    GX_VRAM_BG_256_BC = 0x06,
    GX_VRAM_BG_256_CD = 0x0c,
    GX_VRAM_BG_384_ABC = 0x07,
    GX_VRAM_BG_384_BCD = 0x0e,
    GX_VRAM_BG_512_ABCD = 0x0f,
    GX_VRAM_BG_256_AC = 0x05,
    GX_VRAM_BG_256_AD = 0x09,
    GX_VRAM_BG_256_BD = 0x0a,
    GX_VRAM_BG_384_ABD = 0x0b,
    GX_VRAM_BG_384_ACD = 0x0d
} GXVRamBG;

typedef struct {
    u16 lcdc;
    u16 bg;
} GXVRamState;

void GX_SetBankForBG(GXVRamBG bg);
extern GXVRamState gGXState;


#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)

#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)

#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)

#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)

#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)

#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)

#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)

#define reg_GX_VRAMCNT_H (*(vu8 *)0x04000248)

#define reg_GX_VRAMCNT_I (*(vu8 *)0x04000249)


#define VRAMCNT_LCDC 0x80


static void GX_VRAMCNT_SetLCDC_(int lcdc)
{
    if (lcdc & 0x001) {
        reg_GX_VRAMCNT_A = VRAMCNT_LCDC;
    }
    if (lcdc & 0x002) {
        reg_GX_VRAMCNT_B = VRAMCNT_LCDC;
    }
    if (lcdc & 0x004) {
        reg_GX_VRAMCNT_C = VRAMCNT_LCDC;
    }
    if (lcdc & 0x008) {
        reg_GX_VRAMCNT_D = VRAMCNT_LCDC;
    }
    if (lcdc & 0x010) {
        reg_GX_VRAMCNT_E = VRAMCNT_LCDC;
    }
    if (lcdc & 0x020) {
        reg_GX_VRAMCNT_F = VRAMCNT_LCDC;
    }
    if (lcdc & 0x040) {
        reg_GX_VRAMCNT_G = VRAMCNT_LCDC;
    }
    if (lcdc & 0x080) {
        reg_GX_VRAMCNT_H = VRAMCNT_LCDC;
    }
    if (lcdc & 0x100) {
        reg_GX_VRAMCNT_I = VRAMCNT_LCDC;
    }
}


#define reg_GX_VRAMCNT_A (*(vu8 *)0x04000240)

#define reg_GX_VRAMCNT_B (*(vu8 *)0x04000241)

#define reg_GX_VRAMCNT_C (*(vu8 *)0x04000242)

#define reg_GX_VRAMCNT_D (*(vu8 *)0x04000243)

#define reg_GX_VRAMCNT_E (*(vu8 *)0x04000244)

#define reg_GX_VRAMCNT_F (*(vu8 *)0x04000245)

#define reg_GX_VRAMCNT_G (*(vu8 *)0x04000246)


#define VRAMCNT(ofs) (0x80 | 1 | ((ofs) << 3))


void GX_SetBankForBG(GXVRamBG bg)
{
    gGXState.lcdc = (u16)(~bg & (gGXState.lcdc | gGXState.bg));
    gGXState.bg = (u16)bg;

    switch (bg) {
    case GX_VRAM_BG_128_D:
        reg_GX_VRAMCNT_D = VRAMCNT(0);
        break;
    case GX_VRAM_BG_256_CD:
        reg_GX_VRAMCNT_D = VRAMCNT(1);
    case GX_VRAM_BG_128_C:
        reg_GX_VRAMCNT_C = VRAMCNT(0);
        break;
    case GX_VRAM_BG_384_BCD:
        reg_GX_VRAMCNT_D = VRAMCNT(2);
    case GX_VRAM_BG_256_BC:
        reg_GX_VRAMCNT_C = VRAMCNT(1);
    case GX_VRAM_BG_128_B:
        reg_GX_VRAMCNT_B = VRAMCNT(0);
        break;
    case GX_VRAM_BG_512_ABCD:
        reg_GX_VRAMCNT_D = VRAMCNT(3);
    case GX_VRAM_BG_384_ABC:
        reg_GX_VRAMCNT_C = VRAMCNT(2);
    case GX_VRAM_BG_256_AB:
        reg_GX_VRAMCNT_B = VRAMCNT(1);
    case GX_VRAM_BG_128_A:
        reg_GX_VRAMCNT_A = VRAMCNT(0);
        break;
    case GX_VRAM_BG_384_ABD:
        reg_GX_VRAMCNT_A = VRAMCNT(0);
        reg_GX_VRAMCNT_B = VRAMCNT(1);
        reg_GX_VRAMCNT_D = VRAMCNT(2);
        break;
    case GX_VRAM_BG_384_ACD:
        reg_GX_VRAMCNT_D = VRAMCNT(2);
    case GX_VRAM_BG_256_AC:
        reg_GX_VRAMCNT_A = VRAMCNT(0);
        reg_GX_VRAMCNT_C = VRAMCNT(1);
        break;
    case GX_VRAM_BG_256_AD:
        reg_GX_VRAMCNT_A = VRAMCNT(0);
        reg_GX_VRAMCNT_D = VRAMCNT(1);
        break;
    case GX_VRAM_BG_256_BD:
        reg_GX_VRAMCNT_B = VRAMCNT(0);
        reg_GX_VRAMCNT_D = VRAMCNT(1);
        break;
    case GX_VRAM_BG_96_EFG:
        reg_GX_VRAMCNT_G = VRAMCNT(3);
    case GX_VRAM_BG_80_EF:
        reg_GX_VRAMCNT_F = VRAMCNT(2);
    case GX_VRAM_BG_64_E:
        reg_GX_VRAMCNT_E = VRAMCNT(0);
        break;
    case GX_VRAM_BG_80_EG:
        reg_GX_VRAMCNT_G = VRAMCNT(2);
        reg_GX_VRAMCNT_E = VRAMCNT(0);
        break;
    case GX_VRAM_BG_32_FG:
        reg_GX_VRAMCNT_G = VRAMCNT(1);
    case GX_VRAM_BG_16_F:
        reg_GX_VRAMCNT_F = VRAMCNT(0);
        break;
    case GX_VRAM_BG_16_G:
        reg_GX_VRAMCNT_G = VRAMCNT(0);
        break;
    case GX_VRAM_BG_NONE:
    default:
        break;
    }
    GX_VRAMCNT_SetLCDC_(gGXState.lcdc);
}
