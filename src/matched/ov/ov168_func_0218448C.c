/*
 * function: MICTEST_DisarmMic
 * address:  0x0218448C
 * packet:   pkt_0218448C
 * region:   ov168
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MIC_StopLimitedSampling  0x0208B528  arm
 */
#include "../include/Obj23823.h"

extern int MIC_StopLimitedSampling(void);

void MICTEST_DisarmMic(int *p)
{
    MIC_StopLimitedSampling();
    ((struct Obj23823 *)p)->f28 = 0;
}
