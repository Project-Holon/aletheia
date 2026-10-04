/*
 * unit:     no
 * function: sub_0202AE04
 * address:  0x0202AE04
 * packet:   pkt_0202AC60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A plain word getter at offset 0x10. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202AE04.c \
 *       --func sub_0202AE04 --addr 0x0202AE04 --cc 1.1p1 --thumb
 */
#include "../include/Obj16760.h"

typedef unsigned int u32;

u32 sub_0202AE04(void *obj)
{
    return ((struct Obj16760 *)obj)->f10;
}
