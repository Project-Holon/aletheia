/*
 * function: NNS_SndWaveOutAllocChannel
 * address:  0x02072A44
 * packet:   pkt_02072A44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * blocker:  +0040 ABS32 gNNSSndWaveOutHandles             -> unresolved: 0214DECC (data, from header) has no witness outside 02072A44..02072A88
 *
 * symbols:
 *   NNSi_SndWaveOutLockChannels    0x0207292C  arm
 *   gNNSSndWaveOutHandles       0x0214DECC  data
 *
 * Claims one bit with NNSi_SndWaveOutLockChannels and, on success, seeds the matching slot of
 * the stride-0x14 table and clears its +8 word; the slot address is returned.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_SndWaveOutAllocChannel.c \
 *       --func NNS_SndWaveOutAllocChannel --addr 0x02072A44 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

typedef struct {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0c;
    u32 unk10;
} Slot02072A44;

extern int NNSi_SndWaveOutLockChannels(int mask);
extern Slot02072A44 gNNSSndWaveOutHandles[];

Slot02072A44 *NNS_SndWaveOutAllocChannel(u32 idx)
{
    Slot02072A44 *s;

    if (NNSi_SndWaveOutLockChannels(1 << idx) == 0) {
        return 0;
    }
    s = &gNNSSndWaveOutHandles[idx];
    s->unk00 = idx;
    s->unk08 = 0;
    return s;
}
