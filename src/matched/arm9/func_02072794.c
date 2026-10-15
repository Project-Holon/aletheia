/*
 * function: NNS_SndSetMasterPan
 * address:  0x02072794
 * packet:   pkt_020728E8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   SND_SetMasterPan  0x02089754  arm
 *   SND_ResetMasterPan  0x02089774  arm
 */

typedef unsigned int u32;

extern void SND_SetMasterPan(int pan);
extern void SND_ResetMasterPan(void);

void NNS_SndSetMasterPan(u32 flag)
{
    if (flag != 0) {
        SND_SetMasterPan(0x40);
    } else {
        SND_ResetMasterPan();
    }
}
