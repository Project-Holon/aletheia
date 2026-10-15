/*
 * function: NNSi_SndWaveOutLockChannels
 * address:  0x0207292C
 * packet:   pkt_0207292C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   SND_LockChannel  0x020895D8  arm
 *   gNNSSndWaveOutState     0x0214DEC0  data
 *
 * Channel allocator, claim-by-mask.  Refuses an empty mask (returns 1), refuses
 * a mask that overlaps the in-use word at gNNSSndWaveOutState+8 (returns 0), otherwise
 * locks it through SND_LockChannel and ORs it in.  Matched SND_CHANNEL_UnlockChannels is the
 * matching release and reads the same +0x08 word.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md, and
 * docs/families/cluster_020726D0.h).  THE C BELOW IS UNCHANGED from the version
 * this file carried while it was parked in src/pending as DIFF: only the
 * compiler moved.  Under dsi/1.1p1 -O4,p the base pool word 0x0214DEC0 is live
 * at two points (the `tst` before the call and the `orr` after it), so 1.1p1
 * hoists it into callee-saved r4 and the parameter into r5, giving
 * `push {r3, r4, r5, lr}` for the image's `push {r4, lr}` and folding the two
 * pool entries into one: 68 bytes against the original's 72, 26 concrete bytes
 * out.  The image RELOADS the pool word after the call
 * (`ldr r1,[pc,#0x10]` at 0x0207295C, a second entry at 0x02072970) which is
 * exactly what the pin reproduces.  Under ../2.0/sp2: 72 bytes, 0 mismatches.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/NNSi_SndWaveOutLockChannels.c \
 *       --func NNSi_SndWaveOutLockChannels --addr 0x0207292C --cc ../2.0/sp2 --arm
 */

#include "../include/G_Global0214DEC0.h"

extern struct Global0214DEC0 gNNSSndWaveOutState;
typedef unsigned int   u32;
extern void SND_LockChannel(u32 chBitMask, u32 flags);

int NNSi_SndWaveOutLockChannels(int mask)
{
    if (mask == 0) return 1;
    if ((mask & gNNSSndWaveOutState.flags8) != 0) return 0;
    SND_LockChannel(mask, 0);
    gNNSSndWaveOutState.flags8 |= mask;
    return 1;
}
