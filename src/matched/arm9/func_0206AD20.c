/*
 * function: NNS_G3dGlbGetInvProjectionMtx
 * address:  0x0206AD20
 * packet:   pkt_0206AA78
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  label: MTX_Inverse44 (0x0206AB18) is reached only by the `bl` at
 *           +001C inside this function, so `label` has no witness outside the
 *           compared range 0206AD20..0206AD64 and the site stays wildcarded;
 *           own-pool: g_02148D0C (0x02148D0C) occurs exactly once in the whole
 *           arm9 image, in this function's own pool at 0x0206AD60 (+0040).
 *
 * Pin evidence (2.0), measured 2026-09-19 by wave r8 lane small-3: identical
 * shape and identical tell to src/pending/NNS_G3dGlbGetInvCameraMtx.c - the flags object
 * 0x02148B4C is re-materialised from its pool word at +0034 after the call,
 * 68 bytes (56 code + three pool words), `push {r3, lr}`, zero concrete
 * differences under dsi/../2.0/sp2 where dsi/1.1p1 grows the frame to r4 and
 * leaves 21 differing bytes.
 *
 * Rig-slot setup for bit 4: if the flags object's +0xfc word does not already
 * carry 0x10, hand the slot pair (0x02148B54, 0x02148D0C) to the matrix helper
 * and set it, then answer with the slot address either way.  Two of the four
 * sites resolve on `literal` (0x02148B4C x115, 0x02148B54 x22); the call and
 * the returned slot address stay wildcarded.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/NNS_G3dGlbGetInvProjectionMtx.c \
 *       --func NNS_G3dGlbGetInvProjectionMtx --addr 0x0206AD20 --cc ../2.0/sp2 --arm
 *
 * symbols:
 *   g_renderState   0x02148B4C  data
 *   SCREENTEX_ProjectionMatrix   0x02148B54  data
 *   g_02148D0C   0x02148D0C  data
 *   MTX_Inverse44  0x0206AB18  arm
 */

typedef unsigned int u32;

extern u32 g_renderState[];
extern u32 SCREENTEX_ProjectionMatrix[];
extern u32 g_02148D0C[];
extern void MTX_Inverse44(u32 *a, u32 *b);

u32 *NNS_G3dGlbGetInvProjectionMtx(void)
{
    if ((g_renderState[0x3f] & 0x10) == 0) {
        MTX_Inverse44(SCREENTEX_ProjectionMatrix, g_02148D0C);
        g_renderState[0x3f] |= 0x10;
    }
    return g_02148D0C;
}
