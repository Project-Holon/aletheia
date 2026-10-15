/*
 * function: CTVT_MIC_StopVoice
 * address: 0x021BA234
 * packet: pkt_ov172_021BA234
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NNS_SndWaveOutStop 0x02072BDC arm
 */
#include "../include/Obj04555.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Slot02072BDC Slot02072BDC;
extern void NNS_SndWaveOutStop(Slot02072BDC *s);
void CTVT_MIC_StopVoice(void *p)
{
    ((struct Obj04555 *)p)->fC = 0;
    NNS_SndWaveOutStop(*(Slot02072BDC * *)&((struct Obj04555 *)p)->f20);
}
