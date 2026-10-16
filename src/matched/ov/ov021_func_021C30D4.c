/*
 * function: FLD3D_CI_DarkenCapturedScreen
 * address:  0x021C30D4
 * packet:   pkt_ov021_021C30D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Halves every RGB555 colour in LCDC VRAM bank 0x06860000 (0xC000 halfwords)
 * to darken the captured screen. The parameter is unused (the caller passes
 * one). The channels are extracted into u8 locals (b, g, r, a), then halved
 * as separate `x = x >> 1` statements in b, g, r order; that keeps every
 * channel in its own register so the scheduler interleaves the four chains,
 * and the halving order picks which truncation is scheduled early. Casts
 * inline in the OR expression serialise the chains instead.
 *
 * symbols:
 *   GX_ResetBankForBG  0x020808F4  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int GX_ResetBankForBG(void);
extern void func_0207FDCC(int);

void FLD3D_CI_DarkenCapturedScreen(u32 unused)
{
    int old = GX_ResetBankForBG();
    u16 *p = (u16 *)0x06860000;
    int i;

    for (i = 0; i < 0xC000; i++) {
        u16 c = *p;
        u8 b = (c >> 10) & 0x1F;
        u8 g = (c >> 5) & 0x1F;
        u8 r = c & 0x1F;
        u8 a = (c >> 15) & 1;

        b = b >> 1;
        g = g >> 1;
        r = r >> 1;
        *p = (a << 15) | (b << 10) | (g << 5) | r;
        p++;
    }
    func_0207FDCC(old);
}
