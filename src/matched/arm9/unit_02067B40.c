/*
 * unit:     yes
 * function: NNS_G2dSetRndCore3DSoftSpriteZvalue
 * address:  0x02067B40
 * packet:   pkt_02067AAC
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The H/V flip lane of the NNS G2D cell-to-OAM composer: two setters, a
 * pair of predicates, and the one word the predicates read.
 *
 * The composer state's +0x24 word carries the two flip bits:
 *   bit0  flip horizontally
 *   bit1  flip vertically
 * NNS_G2dSetRndCoreFlipMode (0x02067B78, not in this file, see
 * docs/notes/g2d_flip_setter.c.txt) sets both from two BOOLs;
 * NNSi_G2dIsRndCoreFlipH and NNSi_G2dIsRndCoreFlipV answer them one at a time.  The functions that consume them are
 * NNSi_G2dDrawOam3D and NNSi_G2dDrawCellToSurface3D, and the arithmetic there is the whole
 * reason this lane matters to a rig composer: with the flip bit set, the
 * OAM entry's own position field is replaced by
 *
 *     x' = -(x + objWidth [shape][size])       (attr1 bits 0-8,  9-bit)
 *     y' = -(y + objHeight[shape][size])       (attr0 bits 0-7,  8-bit)
 *
 * with shape from attr0 bits 14-15, size from attr1 bits 14-15, and the
 * two tables at 0x020A17F0 (width) and 0x020A17D8 (height), three rows of
 * four u16 on an 8-byte row stride.  An OAM composer that flips the pixels
 * but leaves the entry's x/y alone lands every flipped part at the wrong
 * place by its own width or height.
 *
 * NNS_G2dSetRndCore3DSoftSpriteZvalue and NNS_G2dSetRndCoreSurface are plain word stores and none of these
 * saves lr, so they all print as a `.word` run in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02067B40.c \
 *       --addr 0x02067B40 --arm
 */

typedef unsigned int u32;

struct G2dOamState {
    u32 pad00[9];
    u32 flip;      /* +0x24 */
    u32 pad28[3];
    u32 f34;       /* +0x34 */
};

void NNS_G2dSetRndCore3DSoftSpriteZvalue(struct G2dOamState *p, u32 v)
{
    p->f34 = v;
}

void NNS_G2dSetRndCoreSurface(u32 *p, u32 v)
{
    *p = v;
}

u32 NNSi_G2dIsRndCoreFlipH(const struct G2dOamState *p)
{
    return (p->flip & 1) != 0;
}

u32 NNSi_G2dIsRndCoreFlipV(const struct G2dOamState *p)
{
    return (p->flip & 2) != 0;
}
