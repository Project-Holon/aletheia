/*
 * function: GAME_DATA_IsSaving
 * address:  0x02012E40
 * packet:   pkt_02012158
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A one-byte getter for the field at +0x1CE, entry attested by the pool word
 * 0x02012E41 that the sibling setter pair loads.  0x1CE does not fit a Thumb
 * immediate, so the offset comes from the function's own literal pool while
 * the pointer stays in r0.
 *
 
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_DATA_IsSaving.c \
 *       --func GAME_DATA_IsSaving --addr 0x02012E40 --cc 1.1p1 --thumb
 */
#include "../include/Obj16727.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


u8 GAME_DATA_IsSaving(const u8 *o)
{
    return *(const u8 *)&((struct Obj16727 *)o)->f1CE;
}

