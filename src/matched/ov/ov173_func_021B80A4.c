/*
 * function: POKE_SUMMARY_ACTOR_OpenDecideWin
 * address:  0x021B80A4
 * packet:   pkt_021B80A4
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 */
#include "../include/Obj10671.h"
#include "../include/Obj24196.h"
typedef unsigned short u16;
typedef unsigned int u32;

struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

int POKE_SUMMARY_ACTOR_OpenDecideWin(char *p, u16 v)
{
    char *q = p + 0x1d0;

    ((struct Obj10671 *)q)->fA = 0;
    ((struct Obj10671 *)q)->f6 = 0xd;
    ((struct Obj10671 *)q)->f8 = v;
    CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj24196 *)p)->f138), 9);
    return 0xd;
}
