/*
 * function: GX_VRAMCNT_SetLCDC_
 * address:  0x0207FD34
 * packet:   pkt_0207FD34
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TwlSDK libgx gx_vramcnt.o (.comment stamp 4.0.0.1024, dsi/1.1p1).
 * Static in the vendor object: maps every bank named in the LCDC mask
 * (A..G, H, I) to the LCDC (enable bit, MST 0).
 */

typedef unsigned char u8;
typedef volatile u8 vu8;

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
