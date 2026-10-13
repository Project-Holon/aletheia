/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0201AA14
 * packet:   pkt_0201A5FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: POKEPARTY_GetCapacity, POKEPARTY_GetCount
 *
 * Two plain word getters, four bytes each: the object's first word and the
 * word at +4.  Both are called from POKEPARTY_GetNonEggCount (0x0201AA1C, still open)
 * and POKEPARTY_GetCount is also called from the unit at 0x0201AC2C, which is
 * where the concrete relocations against it are attested from.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0201AA14.c \
 *       --addr 0x0201AA14 --thumb
 */
#include "../include/Obj17207.h"
#include "../include/Obj17208.h"

typedef unsigned int u32;

u32 POKEPARTY_GetCapacity(void *p)
{
    return ((struct Obj17207 *)p)->f0;
}

u32 POKEPARTY_GetCount(void *p)
{
    return ((struct Obj17208 *)p)->f4;
}
