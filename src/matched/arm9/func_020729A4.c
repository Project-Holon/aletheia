/*
 * function: SND_CHANNEL_ClearClaimedMask
 * address:  0x020729A4
 * packet:   pkt_020729C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gNNSSndWaveOutState  0x0214DEC0  data
 *
 * Clears a mask out of the FIRST word of the channel-allocator global
 * (gNNSSndWaveOutState+0), a different word from SND_CHANNEL_UnlockChannels's +0x08 and from
 * NNS_SndWaveOutFreeChannel's +0x04.
 *
 * The parameter is already a MASK, not an index: the image complements the
 * PARAMETER itself (`mvn r0, r0` at 0x020729A8) before the load, whereas
 * NNS_SndWaveOutFreeChannel's free-by-index complements a shifted 1 (`mvn r0, r2, lsl r0`).
 * That one instruction is the whole distinction between the two functions.
 *
 * NO PIN NEEDED: EXACT under both dsi/1.1p1 and ../2.0/sp2 (the base pool word
 * is live at exactly one point, so there is nothing for 1.1p1 to hoist into a
 * callee-saved register -- the frame is a bare leaf with no push at all).
 * Recorded because its cluster neighbours DO need ../2.0/sp2; see
 * docs/families/cluster_020726D0.h.
 *
 * This file was parked in src/pending at MATCH only because the `symbols:`
 * block was missing its gNNSSndWaveOutState line, so the single ABS32 site had no
 * address to resolve; the C was always byte-correct.  Adding the line resolves
 * the site as `literal x25` (e.g. the pool word at 0x02072970, outside this
 * range) and the verdict is EXACT.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/SND_CHANNEL_ClearClaimedMask.c \
 *       --func SND_CHANNEL_ClearClaimedMask --addr 0x020729A4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 gNNSSndWaveOutState;

void SND_CHANNEL_ClearClaimedMask(u32 mask)
{
    gNNSSndWaveOutState &= ~mask;
}
