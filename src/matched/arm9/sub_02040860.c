/*
 * function: BG_SYS_SetScrollRegs
 * address:  0x02040860
 * packet:   pkt_02040618
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   G2x_SetBGyAffine_  0x0207D59C  arm
 *   g_BgConfig     0x02146A44  data
 *
 * The affine half of the BG scroll module: push a layer's transform, plus
 * its current scroll position, into that layer's hardware parameter block.
 * Only the four affine-capable layers have one, so only cases 2, 3, 6 and 7
 * do anything: main engine BG2 and BG3 at 0x04000020 and 0x04000030, sub
 * engine BG2 and BG3 at 0x04001020 and 0x04001030.  Cases 0, 1, 4, 5 and
 * everything above 7 share the exit.
 *
 * The empty arms are load-bearing, not decoration: the dense jump table
 * only exists because the case labels run from 0 without gaps
 * (docs/idioms/empty-switch-arms-are-what-make-the-table.md).  Written as
 * four cases the compiler would emit a comparison chain instead.
 *
 * Unlike BG_SYS_FillScrollArea, the subscript here stays the variable `layer` in
 * every arm rather than the arm's own case constant.  That is what the
 * `mla lr, r0, ip, lr` inside each arm says: the multiply is still live,
 * so the index cannot have been a literal.  The four arms therefore differ
 * only in one pooled register address, which is also why all four share the
 * single 0x02146A44 pool word at the end of the function.
 *
 * The transform arguments are this function's own parameters 2 to 4, passed
 * straight through untouched (nothing in any arm writes r1, r2 or r3), and
 * the scroll pair goes on the stack as arguments 5 and 6.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_SetScrollRegs.c \
 *       --func BG_SYS_SetScrollRegs --addr 0x02040860 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct BgLayer {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u32 scrollX;
    u32 scrollY;
    u8  mode;
    u8  unk1D;
    u8  unk1E;
    u8  unk1F;
    u32 unk20;
    u32 unk24;
    u32 unk28;
};

extern struct BgLayer *g_BgConfig;

extern void G2x_SetBGyAffine_(void *reg, u32 a, u32 b, u32 c, u32 x, u32 y);

void BG_SYS_SetScrollRegs(u32 layer, u32 a, u32 b, u32 c)
{
    switch (layer) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        G2x_SetBGyAffine_((void *)0x04000020, a, b, c,
                      g_BgConfig[layer].scrollX, g_BgConfig[layer].scrollY);
        break;
    case 3:
        G2x_SetBGyAffine_((void *)0x04000030, a, b, c,
                      g_BgConfig[layer].scrollX, g_BgConfig[layer].scrollY);
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        G2x_SetBGyAffine_((void *)0x04001020, a, b, c,
                      g_BgConfig[layer].scrollX, g_BgConfig[layer].scrollY);
        break;
    case 7:
        G2x_SetBGyAffine_((void *)0x04001030, a, b, c,
                      g_BgConfig[layer].scrollX, g_BgConfig[layer].scrollY);
        break;
    }
}
