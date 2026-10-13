/*
 * function: NNS_G3dGlbGetInvCameraMtx
 * address:  0x0206AAD4
 * packet:   pkt_0206AA78
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  own-pool: g_02148C4C (0x02148C4C) occurs exactly once in the whole
 *           arm9 image, in this function's own literal pool at 0x0206AB14
 *           (+0040), so `literal` has no witness outside the compared range
 *           0206AAD4..0206AB18 and no cut can free it.
 *
 * Pin evidence (2.0), measured 2026-09-19 by wave r8 lane small-3: the image
 * re-materialises the flags object 0x02148B4C from its pool word at +0034
 * after the call at +001C, keeps the frame at `push {r3, lr}` and the body at
 * 68 bytes (56 code + three pool words).  dsi/1.1p1 keeps 0x02148B4C live in
 * r4 across the call, grows the frame to `push {r4, lr}` and leaves 24
 * differing bytes; dsi/../2.0/sp2 with this C reproduces all 68 bytes with
 * zero concrete differences.  Same family tell as src/matched/NNS_G3dGlbGetWVMtx.c,
 * src/matched/NNS_G3dGlbGetInvWVMtx.c and src/pending/NNSi_G3dGlbUpdateWV.c.
 *
 * Rig-slot setup for bit 3: if the flags object's +0xfc word does not already
 * carry the bit, hand the slot pair (0x02148B98, 0x02148C4C) to the matrix
 * helper and set it, then answer with the slot address either way.  Three of
 * the four sites resolve (the call on `label`, the two other pool words on
 * `literal`); only the returned slot address stays wildcarded.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/NNS_G3dGlbGetInvCameraMtx.c \
 *       --func NNS_G3dGlbGetInvCameraMtx --addr 0x0206AAD4 --cc ../2.0/sp2 --arm
 *
 * symbols:
 *   g_renderState   0x02148B4C  data
 *   g_renderStateDrawParams   0x02148B98  data
 *   g_02148C4C   0x02148C4C  data
 *   func_0207B67C  0x0207B67C  arm
 */

typedef unsigned int u32;

extern u32 g_renderState[];
extern u32 g_renderStateDrawParams[];
extern u32 g_02148C4C[];
extern void func_0207B67C(u32 *a, u32 *b);

u32 *NNS_G3dGlbGetInvCameraMtx(void)
{
    if ((g_renderState[0x3f] & 8) == 0) {
        func_0207B67C(g_renderStateDrawParams, g_02148C4C);
        g_renderState[0x3f] |= 8;
    }
    return g_02148C4C;
}
