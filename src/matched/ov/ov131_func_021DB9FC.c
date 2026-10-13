/*
 * function: P_STA_SKILL_HideSlot
 * address:  0x021DB9FC
 * packet:   pkt_021DB9FC
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14078.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);

void P_STA_SKILL_HideSlot(void *a, void *b, u8 *p)
{
    CLACT_SetActorDrawEnable(((struct Obj14078 *)p)->f8, 0);
    CLACT_SetActorDrawEnable(((struct Obj14078 *)p)->fC, 0);
}
