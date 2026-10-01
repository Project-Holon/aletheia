/*
 * function: func_021C30D4
 * address:  0x021C30D4
 * packet:   pkt_ov021_021C30D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Halves every RGB555 colour in LCDC VRAM bank 0x06860000 (0xC000 halfwords)
 * to darken the captured screen. 2026-10-01: logic is right; residue is
 * scheduling. The image extracts b, g, r, a in that order with the 1 mask
 * hoisted to r7 and 0x1F rematerialised per use, and ORs (b<<10 | a<<15),
 * then g<<5, then r. Every variant tried (shift-then-mask, mask-then-shift,
 * GX_RGBA macro order, reversed OR order) hoists 0x1F and computes a or r
 * first. Try a bitfield struct or an inline helper per channel next.
 */

typedef unsigned char u8;
typedef unsigned short u16;

extern int func_020808F4(void);
extern void func_0207FDCC(int);

void func_021C30D4(void)
{
    int old = func_020808F4();
    u16 *p = (u16 *)0x06860000;
    int i;

    for (i = 0; i < 0xC000; i++) {
        u16 c = *p;
        u8 b = (c >> 10) & 0x1F;
        u8 g = (c >> 5) & 0x1F;
        u8 r = c & 0x1F;
        u8 a = (c >> 15) & 1;

        *p = (a << 15) | ((u8)(b >> 1) << 10) | ((u8)(g >> 1) << 5) | (u8)(r >> 1);
        p++;
    }
    func_0207FDCC(old);
}
