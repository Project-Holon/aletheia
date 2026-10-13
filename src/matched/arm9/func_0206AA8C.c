/*
 * function: NNS_G3dGlbMaterialColorDiffAmb
 * address:  0x0206AA8C
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
 * Unlabelled leaf: no prologue, so disasm.py never traced it and it sits in
 * the 76-byte gap between NNS_G3dGlbLightColor and NNS_G3dGlbGetInvCameraMtx, between two of the
 * flags object's literal pools.  Packs a 16-bit field, a one-bit flag at bit
 * 15 and a 16-bit payload into the word at 0x02148B4C + 0x94.
 *
 * Extent note: the follower at 0x0206AAB0 is unlabelled too, so the listing's
 * inferred extent for this address runs to the next label at 0x0206AAD4 and
 * the verdict is EXACT*.  Both addresses are reported for
 * layout/function_starts.txt rather than edited in.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dGlbMaterialColorDiffAmb.c \
 *       --func NNS_G3dGlbMaterialColorDiffAmb --addr 0x0206AA8C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 g_renderState[];

void NNS_G3dGlbMaterialColorDiffAmb(u32 v, u32 bits, u32 flag)
{
    g_renderState[0x25] = v | (bits << 16) | ((u32)(flag != 0) << 15);
}
