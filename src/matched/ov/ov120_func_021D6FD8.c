/*
 * function: GTSNEGO_MSG_RestartIconAnim
 * address: 0x021D6FD8
 * packet: pkt_ov120_021D6FD8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_RestartActorAnim 0x0204B9A0 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 */
#include "../include/Obj10395.h"
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned int u32;
struct Actor;
struct Obj;
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
void GTSNEGO_MSG_RestartIconAnim(u8 *p, u32 flag)
{
    if (((struct Obj10395 *)p)->f140 != 0) {
        CLACT_RestartActorAnim(((struct Obj10395 *)p)->f140);
        CLACT_SetActorAutoAnim(((struct Obj10395 *)p)->f140, flag);
    }
}
