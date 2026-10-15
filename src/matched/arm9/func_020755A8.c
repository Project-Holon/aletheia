/*
 * function: NNS_SndArcPlayerStartSeqEx
 * address:  0x020755A8
 * packet:   pkt_0207533C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_SndArcGetSeqInfo  0x02074324  arm
 *   NNSi_SndArcPlayerStartSeq  0x02075698  arm
 */
#include "../include/Obj08951.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *NNS_SndArcGetSeqInfo(int index);
extern u32 NNSi_SndArcPlayerStartSeq(u32 a0, u32 a1, u32 a2, u32 a3, u8 *s0, u32 s1);

u32 NNS_SndArcPlayerStartSeqEx(u32 a, int b, int c, int d, u32 e)
{
    u8 *p = NNS_SndArcGetSeqInfo(e);

    if (p == 0) return 0;
    if (d < 0) d = ((struct Obj08951 *)p)->f8;
    if (c < 0) c = ((struct Obj08951 *)p)->f4;
    if (b < 0) b = ((struct Obj08951 *)p)->f9;
    return NNSi_SndArcPlayerStartSeq(a, (u32)b, (u32)c, (u32)d, (u8 *)p, e);
}
