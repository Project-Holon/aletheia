/*
 * file:     unit_02072974.c
 * unit:     yes
 * function: SND_CHANNEL_UnlockChannels, SND_CHANNEL_ClearClaimedMask
 * address:  0x02072974
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020895F8    0x020895F8  arm
 *   g_0214DEC0       0x0214DEC0  data
 */
typedef unsigned int u32;

extern void func_020895F8(u32 channelMask, u32 flags);
void SND_CHANNEL_UnlockChannels(u32 channelMask);
void SND_CHANNEL_ClearClaimedMask(u32 channelMask);
extern u32  g_0214DEC0[];


/*
 * Releases one channel of the allocator: unlocks it and clears the channel bit
 * from the word at g_0214DEC0 + 8.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SND_CHANNEL_UnlockChannels.c \
 *       --func SND_CHANNEL_UnlockChannels --addr 0x02072974 --cc 1.1p1 --arm
 */
void SND_CHANNEL_UnlockChannels(u32 channelMask)
{
    if (channelMask == 0) {
        return;
    }
    func_020895F8(channelMask, 0);
    g_0214DEC0[2] &= ~channelMask;
}


/*
 * Clears a mask out of the FIRST word of the channel-allocator global
 * (g_0214DEC0+0), a different word from SND_CHANNEL_UnlockChannels's +0x08 and from
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
 * block was missing its g_0214DEC0 line, so the single ABS32 site had no
 * address to resolve; the C was always byte-correct.  Adding the line resolves
 * the site as `literal x25` (e.g. the pool word at 0x02072970, outside this
 * range) and the verdict is EXACT.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/SND_CHANNEL_ClearClaimedMask.c \
 *       --func SND_CHANNEL_ClearClaimedMask --addr 0x020729A4 --cc 1.1p1 --arm
 */
void SND_CHANNEL_ClearClaimedMask(u32 channelMask)
{
    g_0214DEC0[0] &= ~channelMask;
}
