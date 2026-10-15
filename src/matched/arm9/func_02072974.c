/*
 * function: SND_CHANNEL_UnlockChannels
 * address:  0x02072974
 * packet:   pkt_0207292C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  +0010 PC24 SND_UnlockChannel           -> unresolved: 020895F8 (arm, from header) has no witness outside 02072974..020729A4
 *
 * symbols:
 *   SND_UnlockChannel    0x020895F8  arm
 *   gNNSSndWaveOutState       0x0214DEC0  data
 *
 * Releases one channel of the allocator: unlocks it and clears the channel bit
 * from the word at gNNSSndWaveOutState + 8.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/SND_CHANNEL_UnlockChannels.c \
 *       --func SND_CHANNEL_UnlockChannels --addr 0x02072974 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void SND_UnlockChannel(u32 chan, u32 a);
extern u32  gNNSSndWaveOutState[];

void SND_CHANNEL_UnlockChannels(u32 chan)
{
    if (chan == 0) {
        return;
    }
    SND_UnlockChannel(chan, 0);
    gNNSSndWaveOutState[2] &= ~chan;
}
