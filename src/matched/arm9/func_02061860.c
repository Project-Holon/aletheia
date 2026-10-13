/*
 * function: NNSi_GfdRingIsFull
 * address:  0x02061860
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns whether the +0xc halfword equals the +4 word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNSi_GfdRingIsFull.c \
 *       --func NNSi_GfdRingIsFull --addr 0x02061860 --arm --cc 1.1p1
 */
#include "../include/Obj04778.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int NNSi_GfdRingIsFull(u8 *p)
{
    u16 a = ((struct Obj04778 *)p)->fC;
    u32 b = ((struct Obj04778 *)p)->f4;

    return a == b ? 1 : 0;
}
