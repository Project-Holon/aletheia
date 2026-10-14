/*
 * function: COMM_TVT_SYS_HideSlotMarker
 * address:  0x021BE2E0
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail call to CLACT_SetActorDrawEnable with the field at +0x1b0 and a zero.
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj24141.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *v, unsigned int zero);

void COMM_TVT_SYS_HideSlotMarker(void *p)
{
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj24141 *)p)->f1B0, 0);
}
