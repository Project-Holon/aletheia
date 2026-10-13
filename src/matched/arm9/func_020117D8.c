/*
 * function: ICA_ANIME_SetBuffer
 * address:  0x020117D8
 * packet:   pkt_020117D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Lay out `a1` rows of `a2` bytes each at stride a1*0xc into the three
 * buffers the record declares at +0x1c, +0x20 and +0x24, but only where the
 * matching flag word at +0x28, +0x2c and +0x30 is set.  a3 is the caller's
 * byte budget: if it is smaller than a1*0xc times the number of live flags
 * nothing is written and the call answers 0.  +0x18 records the row count.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ICA_ANIME_SetBuffer.c \
 *       --func ICA_ANIME_SetBuffer --addr 0x020117D8 --cc 1.1p1 --thumb
 */
#include "../include/Obj00064.h"

typedef unsigned char u8;
typedef unsigned int  u32;

int ICA_ANIME_SetBuffer(u8 *a0, int a1, u8 *a2, int a3)
{
    int total;
    int step;
    int k;

    total = 0;
    step = a1 * 0xc;
    k = 0;
    if (((struct Obj00064 *)a0)->f28 != 0) {
        total += step;
    }
    if (((struct Obj00064 *)a0)->f2C != 0) {
        total += step;
    }
    if (((struct Obj00064 *)a0)->f30 != 0) {
        total += step;
    }
    if (a3 < total) {
        return 0;
    }
    if (((struct Obj00064 *)a0)->f28 != 0) {
        *(u8 * *)&((struct Obj00064 *)a0)->f1C = a2;
        k++;
    }
    if (((struct Obj00064 *)a0)->f2C != 0) {
        *(u8 * *)&((struct Obj00064 *)a0)->f20 = a2 + step * k;
        k++;
    }
    if (((struct Obj00064 *)a0)->f30 != 0) {
        *(u8 * *)&((struct Obj00064 *)a0)->f24 = a2 + step * k;
        k++;
    }
    *(u32 *)&((struct Obj00064 *)a0)->f18 = a1;
    return 1;
}
