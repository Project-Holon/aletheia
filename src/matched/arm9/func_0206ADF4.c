/*
 * function: NNS_G3dGlbGetInvWVMtx
 * address:  0x0206ADF4
 * packet:   pkt_0206AA78
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Pin evidence (2.0), measured 2026-09-19 by wave r8 lane small-3: identical
 * shape and identical tell to its twin src/matched/NNS_G3dGlbGetWVMtx.c - the flags
 * object 0x02148B4C is re-materialised from its pool word at +002C after the
 * call, 56 bytes, `push {r3, lr}`, zero concrete mismatches under
 * dsi/../2.0/sp2 where dsi/1.1p1 keeps the address live in r4 and grows the
 * frame.  The only difference from the twin is the slot address returned
 * (0x02148CAC instead of 0x02148C7C), which each function carries in its own
 * pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dGlbGetInvWVMtx.c \
 *       --func NNS_G3dGlbGetInvWVMtx --addr 0x0206ADF4 --cc ../2.0/sp2 --arm
 *
 * symbols:
 *   g_renderState   0x02148B4C  data
 *   g_02148CAC   0x02148CAC  data
 *   NNSi_G3dGlbUpdateWV  0x0206AD64  arm
 */

typedef unsigned int u32;

extern u32 g_renderState[];
extern u32 g_02148CAC[];
extern void NNSi_G3dGlbUpdateWV(void);

u32 *NNS_G3dGlbGetInvWVMtx(void)
{
    if ((g_renderState[0x3f] & 0x80) == 0) {
        NNSi_G3dGlbUpdateWV();
        g_renderState[0x3f] |= 0x80;
    }
    return g_02148CAC;
}
