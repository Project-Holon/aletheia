/*
 * function: CLACT_GetActorPaletteIndex
 * address:  0x0204B7F8
 * packet:   pkt_0204B764
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Same as CLACT_GetActorCharacterIndex one field up, at +0x5e.  Unlabelled leaf for the
 * same reason.
 *
 * symbols:
 *   none (no external calls, no data references)
 */
#include "../include/Obj16081.h"

typedef unsigned char  u8;
typedef unsigned short u16;

u16 CLACT_GetActorPaletteIndex(u8 *p)
{
    return ((struct Obj16081 *)p)->f5E;
}
