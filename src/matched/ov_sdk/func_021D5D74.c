/*
 * function: DWCi_FNTlDrawCharEx
 * address:  0x021D5D74
 * packet:   pkt_021D5D74
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_FNTlDrawCharEx 0x021D5D74 arm
 *   NNSi_G2dCharCanvasDrawChar  0x02068EA0  arm  arm9
 *
 * Forward five arguments plus a 16-bit index to the global-object dispatcher.
 * Addresses are Black-image addresses.
 */

typedef signed char    s8;
typedef unsigned short u16;
struct Ctx;
struct Fnt2;
extern s8 NNSi_G2dCharCanvasDrawChar(struct Ctx *ctx, struct Fnt2 **font, int x, int y, int a6, u16 code);

int DWCi_FNTlDrawCharEx(int a0, int a1, int a2, int a3, unsigned short s0, int s1)
{
    return NNSi_G2dCharCanvasDrawChar((struct Ctx *)a0, (struct Fnt2 **)(*(int *)0x021DE680 + s1 * 8), a1, a2, a3, s0);
}

