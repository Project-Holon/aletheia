/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202B57C
 * packet:   pkt_0202B4BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ISS_SYS_Get3dsSys, ISS_SYS_GetDungeonSys
 *
 * Two word getters, at offsets 0x24 and 0x18, packed into a single 8-byte
 * pair with no gap. Neither has a relocation.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202B57C.c \
 *       --addr 0x0202B57C --thumb
 */
#include "../include/Obj17265.h"
#include "../include/Obj17266.h"

typedef unsigned int u32;

u32 ISS_SYS_Get3dsSys(void *obj)
{
    return ((struct Obj17265 *)obj)->f24;
}

u32 ISS_SYS_GetDungeonSys(void *obj)
{
    return ((struct Obj17266 *)obj)->f18;
}
