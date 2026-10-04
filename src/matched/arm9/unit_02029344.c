/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02029344
 * packet:   pkt_0202918C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02029344, sub_02029348
 *
 * Two leaf helpers on the same object as the six checker/trampoline pairs of
 * pkt_0202918C's neighbour packets: sub_02029344 is a plain word setter at
 * offset 4, and sub_02029348 clears four fields (two words at +0xc/+0x1c,
 * two halfwords at +0x18/+0x1a) that the checker wrappers elsewhere test and
 * arm. Neither function has a relocation of any kind.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02029344.c \
 *       --addr 0x02029344 --thumb
 */
#include "../include/Obj01618.h"
#include "../include/Obj17256.h"

typedef unsigned short u16;
typedef unsigned int u32;

void sub_02029344(void *obj, u32 value)
{
    ((struct Obj17256 *)obj)->f4 = value;
}

void sub_02029348(void *obj)
{
    ((struct Obj01618 *)obj)->f1C = 0;
    ((struct Obj01618 *)obj)->fC = 0;
    ((struct Obj01618 *)obj)->f18 = 0;
    ((struct Obj01618 *)obj)->f1A = 0;
}
