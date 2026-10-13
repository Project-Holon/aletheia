/*
 * function: VS_MULTI_LIST_DeleteActors
 * address: 0x021F72BC
 * packet: pkt_ov097_021F72BC
 * region: ov097
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 */
#include "../include/Obj21994.h"
struct Obj;
struct Bank;
extern void CLACT_DeleteActor(struct Obj *);
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
void VS_MULTI_LIST_DeleteActors(char *p)
{
    unsigned i;
    for (i = 0; i < 24; i++)
        CLACT_DeleteActor(*(struct Obj **)(p + i * 4 + 0x54));
    CLACT_DeleteUnit(*(struct Bank * *)&((struct Obj21994 *)p)->f50);
}
