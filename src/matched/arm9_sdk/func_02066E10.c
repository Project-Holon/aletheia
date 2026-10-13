/*
 * function: NNS_G2dSetOamSoftEmuAutoZOffsetStep
 * address:  0x02066E10
 * packet:   pkt_02066E10
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sOamSoftEmuAutoZOffsetStep 0x020A8218 data
 */

#define sOamSoftEmuAutoZOffsetStep (*(int *)0x020A8218)

void NNS_G2dSetOamSoftEmuAutoZOffsetStep(int step)
{
    sOamSoftEmuAutoZOffsetStep = step;
}
