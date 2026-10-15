/*
 * function: CTVT_MIC_FreeChannel
 * address:  0x021BA1D8
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to NNSi_SndWaveOutUnlockChannel with the field at +0x20.
 *
 * symbols:
 *   NNSi_SndWaveOutUnlockChannel  0x02072A88  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24096.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void NNSi_SndWaveOutUnlockChannel(u32 *p);

void CTVT_MIC_FreeChannel(void *p)
{
    NNSi_SndWaveOutUnlockChannel((u32 *)((struct Obj24096 *)p)->f20);
}
