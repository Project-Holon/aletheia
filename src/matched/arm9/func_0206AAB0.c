/*
 * function: NNS_G3dGlbMaterialColorSpecEmi
 * address:  0x0206AAB0
 * packet:   pkt_0206AA78
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_renderState       0x02148B4C  data
 *
 * The +0x98 twin of NNS_G3dGlbMaterialColorDiffAmb, same unlabelled-leaf shape in the same
 * gap, same packing (field, one-bit flag at bit 15, payload).
 *
 * Extent note: the listing's inferred extent for this address runs to the
 * next label at 0x0206AAD4, so the verdict is EXACT*; 0x0206AAB0 joins
 * 0x0206AA8C in the unlabelled-follower report.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dGlbMaterialColorSpecEmi.c \
 *       --func NNS_G3dGlbMaterialColorSpecEmi --addr 0x0206AAB0 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 g_renderState[];

void NNS_G3dGlbMaterialColorSpecEmi(u32 v, u32 bits, u32 flag)
{
    g_renderState[0x26] = v | (bits << 16) | ((u32)(flag != 0) << 15);
}
