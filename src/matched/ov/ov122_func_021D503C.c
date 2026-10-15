/*
 * function: INTRUDE_COMM_VIEW_UpdateActorAnim
 * address: 0x021D503C
 * packet: pkt_ov122_021D503C
 * region: ov122
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: zero padding at 0x021D50B2; next function at 0x021D50B4.
 * symbols:
 *   INTRUDE_COMM_GetRequestState 0x02158630 thumb ov010
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb  arm9
 */
#include "../include/Obj00265.h"
typedef unsigned short u16;
typedef unsigned int   u32;
struct Ctx;
struct Obj;
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern int INTRUDE_COMM_GetRequestState(int a);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void INTRUDE_COMM_VIEW_UpdateActorAnim(char *p)
{
    switch (INTRUDE_COMM_GetRequestState(GAMESYSTEM_GetGameComm(((struct Obj00265 *)p)->f354))) {
    case 0:
    case 1:
        if (CLACT_GetActorAnimSeq(((struct Obj00265 *)p)->f390) == 20) {
            CLACT_SetActorAutoAnim(((struct Obj00265 *)p)->f390, 0);
            CLACT_SetActorAnimSeq(((struct Obj00265 *)p)->f390, 12);
        }
        break;
    case 2:
    case 3:
        if (CLACT_GetActorAnimSeq(((struct Obj00265 *)p)->f390) == 12) {
            CLACT_SetActorAutoAnim(((struct Obj00265 *)p)->f390, 1);
            CLACT_SetActorAnimSeq(((struct Obj00265 *)p)->f390, 20);
        }
        break;
    }
}
