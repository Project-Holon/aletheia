/*
 * function: NNS_G3dGlbGetWVMtx
 * address:  0x0206ADBC
 * packet:   pkt_0206AA78
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Pin evidence (2.0), measured 2026-09-19 by wave r8 lane small-3:
 *   The image re-materialises the flags object 0x02148B4C from its pool word
 *   at +002C (a fresh `ldr r0, [pc, #0x10]` after the call at +0018) and keeps
 *   a bare 56-byte body with a `push {r3, lr}` frame.  dsi/1.1p1 keeps the
 *   address live in a callee-saved register across the call and grows the
 *   frame to `push {r4, lr}` with 21 differing bytes; dsi/../2.0/sp2 with this
 *   C compiles to the original's 56 bytes with zero concrete mismatches.  Same
 *   tell ("kept constants", docs/FRONTEND-PINS.md) and same family as
 *   src/pending/NNSi_G3dGlbUpdateWV.c and src/pending/NNS_G3dGlbGetInvVPMtx.c, both already
 *   pinned to ../2.0/sp2 by wave r6.
 *
 * Rig-slot setup for bit 7: if the flags object's +0xfc word does not already
 * carry 0x80, run the slot teardown and set it.  The address of the slot at
 * 0x02148C7C is returned either way, which is why the pool word for it sits
 * last and is loaded once, after the branch target.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dGlbGetWVMtx.c \
 *       --func NNS_G3dGlbGetWVMtx --addr 0x0206ADBC --cc ../2.0/sp2 --arm
 *
 * symbols:
 *   g_renderState   0x02148B4C  data
 *   g_02148C7C   0x02148C7C  data
 *   NNSi_G3dGlbUpdateWV  0x0206AD64  arm
 */

typedef unsigned int u32;

extern u32 g_renderState[];
extern u32 g_02148C7C[];
extern void NNSi_G3dGlbUpdateWV(void);

u32 *NNS_G3dGlbGetWVMtx(void)
{
    if ((g_renderState[0x3f] & 0x80) == 0) {
        NNSi_G3dGlbUpdateWV();
        g_renderState[0x3f] |= 0x80;
    }
    return g_02148C7C;
}
