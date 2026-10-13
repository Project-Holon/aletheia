/*
 * function: func_02075560
 * address:  0x02075560
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
 */
#include "../include/Obj08950.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *NNS_SndArcGetSeqInfo(int index);
extern u32 func_02075698(u32 a0, u32 a1, u32 a2, u32 a3, u8 *s0, u32 s1);

u32 func_02075560(u32 a, u32 b)
{
    u8 *p = NNS_SndArcGetSeqInfo(b);

    if (p == 0) return 0;
    return func_02075698(a, ((struct Obj08950 *)p)->f9, ((struct Obj08950 *)p)->f4, ((struct Obj08950 *)p)->f8,
                         (u8 *)p, b);
}
