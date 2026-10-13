/*
 * function: NNS_G3dGlbGetViewPort
 * address:  0x0206AE94
 * packet:   pkt_0206AA78
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Pin evidence (2.0), measured 2026-09-19 by wave r8 lane small-3: with
 * dsi/1.1p1 every one of the four guarded arms is if-converted into predicated
 * instructions (`cmp r0, #0` / `ldrne ip, [pc, #0x54]` / `ldrne ip, [ip, #0xa0]`
 * / `andne ip, ip, #0xff` / `strne ip, [r0]`), which shortens the body to 100
 * bytes and leaves 81 differing bytes; dsi/../2.0/sp2 emits the image's
 * branchy form (`cmp` / `beq` over an unconditional body, with only the last
 * arm predicated as `bxeq lr`) at exactly 116 bytes with zero concrete
 * mismatches.  Same front end as the rest of this packet's filed rows
 * (docs/FRONTEND-PINS.md: pkt_0206AA78 keeps constants live / re-materialises
 * them from the pool per front end).  Neither `-proc arm7tdmi` nor volatile
 * destination pointers changed the 1.1p1 if-conversion.
 *
 * Four-byte nibble extractor: the word at g_renderState + 0xa0 is spread over up
 * to four word-sized destinations, one byte per word, low byte first.  Each
 * arm re-spells the global rather than sharing a named local, which is what
 * makes the image re-load the pool word in every arm (and what puts the first
 * arm's value in ip while the rest use r0).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G3dGlbGetViewPort.c \
 *       --func NNS_G3dGlbGetViewPort --addr 0x0206AE94 --cc ../2.0/sp2 --arm
 *
 * symbols:
 *   g_renderState  0x02148B4C  data
 */

typedef unsigned int u32;

extern u32 g_renderState[];

void NNS_G3dGlbGetViewPort(u32 *a0, u32 *a1, u32 *a2, u32 *a3)
{
    if (a0 != 0)
        *a0 = g_renderState[0x28] & 0xff;
    if (a1 != 0)
        *a1 = (g_renderState[0x28] >> 8) & 0xff;
    if (a2 != 0)
        *a2 = (g_renderState[0x28] >> 16) & 0xff;
    if (a3 != 0)
        *a3 = (g_renderState[0x28] >> 24) & 0xff;
}
