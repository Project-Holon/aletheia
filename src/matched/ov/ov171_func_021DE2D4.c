/*
 * function: DENDOU_VIEW_CreateButtonActors
 * address: 0x021DE2D4
 * packet: pkt_ov171_021DE2D4
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: group the integer table offset before adding its symbol base.
 * symbols:
 *   CLACT_CreateUnit 0x0204B100 arm
 *   DENDOU_VIEW_CreateActor 0x021DE290 thumb ov171
 *   DENDOU_VIEW_SetActorVisible 0x021DE064 thumb ov171
 *   sButtonActorTemplates 0x021DEBA4 data a4
 */
#include "../include/Obj01756.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
struct Obj;
extern struct Obj *DENDOU_VIEW_CreateActor(char *p, const char *q);
extern void DENDOU_VIEW_SetActorVisible(int *, int, int);
extern const char sButtonActorTemplates[];
void DENDOU_VIEW_CreateButtonActors(char *p)
{
    unsigned i;
    *(int *)&((struct Obj01756 *)p)->fB70 = (int)CLACT_CreateUnit(31, 0, 0x8c);
    for (i = 0; i < 16; ++i)
        *(int *)(p + 0xb74 + i * 4) = 0;
    for (i = 12; i <= 15; ++i)
        *(int *)(p + 0xb74 + i * 4) = (int)DENDOU_VIEW_CreateActor(p, sButtonActorTemplates + (i * 24 - 0x120));
    if (((struct Obj01756 *)p)->fC5F == 1) {
        DENDOU_VIEW_SetActorVisible((int *)p, 12, 0);
        DENDOU_VIEW_SetActorVisible((int *)p, 13, 0);
    }
}
