/*
 * unit:     no
 * function: sub_0202AD88
 * address:  0x0202AD88
 * packet:   pkt_0202AC60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A plain byte getter at offset 0x19. No relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0202AD88.c \
 *       --func sub_0202AD88 --addr 0x0202AD88 --cc 1.1p1 --thumb
 */
#include "../include/Obj16758.h"

typedef unsigned char u8;
typedef unsigned int u32;

u32 sub_0202AD88(void *obj)
{
    return ((struct Obj16758 *)obj)->f19;
}
