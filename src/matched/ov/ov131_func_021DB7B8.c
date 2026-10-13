/*
 * function: P_STA_SKILL_DeleteSlotObjects
 * address:  0x021DB7B8
 * packet:   pkt_021DB7B8
 * region:   ov131
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10524.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void P_STA_SKILL_DeleteSlotObjects(void *a, void *b, u8 *p)
{
    CLACT_DeleteActor(((struct Obj10524 *)p)->f8);
    CLACT_DeleteActor(((struct Obj10524 *)p)->fC);
    ((struct Obj10524 *)p)->f0 = 0xff;
}
