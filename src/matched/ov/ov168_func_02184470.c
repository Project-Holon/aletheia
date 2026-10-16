/*
 * function: MICTEST_ArmMic
 * address:  0x02184470
 * packet:   pkt_02184470
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MIC_StartLimitedSampling  0x0208B500  arm
 */
#include "../include/Obj10643.h"

extern void MIC_StartLimitedSampling(int *);

void MICTEST_ArmMic(int *p)
{
    if (((struct Obj10643 *)p)->f30 == 0) {
        MIC_StartLimitedSampling(p);
        ((struct Obj10643 *)p)->f28 = 1;
    } else {
        ((struct Obj10643 *)p)->f2C = 1;
    }
}
