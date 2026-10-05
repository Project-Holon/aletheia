/*
 * function: func_0202BECC
 * address:  0x0202BECC
 * packet:   pkt_0202BECC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Guarded one-argument forward: only when the node's first word is set does
 * func_0202BF90 get called with the node itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202BECC.c \
 *       --func func_0202BECC --addr 0x0202BECC --thumb --cc 1.1p1

 * Closed by the `matched` class: 0x0202BF90 was filed as an EXACT entry this wave (pkt_0202BEBC), matched with the object spelled as a struct.
 */
#include "../include/Obj03440.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0202BF90(u8 *p, u32 key);

void func_0202BECC(u8 *p, u32 key)
{
    if (((struct Obj03440 *)p)->f0 != 0) {
        func_0202BF90(p, key);
    }
}
