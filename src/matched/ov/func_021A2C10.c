/*
 * function: WEATHER_TASK_DestroyParticleActor
 * address:  0x021A2C10
 * packet:   pkt_021A2C10
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12086.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

void WEATHER_TASK_DestroyParticleActor(u8 *p)
{
    u32 v = ((struct Obj12086 *)p)->f4;
    if (v != 0) {
        CLACT_DeleteActor((struct Obj *)v);
        ((struct Obj12086 *)p)->f4 = 0;
    }
}
