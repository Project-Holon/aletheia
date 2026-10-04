/*
 * unit:     no
 * function: sub_0202ACC8
 * address:  0x0202ACC8
 * packet:   pkt_0202AC60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A plain word getter at offset 4. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202ACC8.c \
 *       --func sub_0202ACC8 --addr 0x0202ACC8 --cc 1.1p1 --thumb
 */
#include "../include/Obj16757.h"

typedef unsigned int u32;

u32 sub_0202ACC8(void *obj)
{
    return ((struct Obj16757 *)obj)->f4;
}
