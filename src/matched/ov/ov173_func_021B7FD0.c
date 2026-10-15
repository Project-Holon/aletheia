/*
 * function: POKE_SUMMARY_ACTOR_SetScrollAnim
 * address: 0x021B7FD0
 * packet: pkt_ov173_021B7FD0
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 */
#include "../include/Obj02506.h"
#include "../include/Obj24192.h"
#include "../include/Obj24193.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);
void POKE_SUMMARY_ACTOR_SetScrollAnim(u8 *p,int direction)
{
    CLACT_SetActorAnimFrame(((struct Obj02506 *)p)->f108,0);
    CLACT_SetActorAnimFrame(((struct Obj02506 *)p)->f104,0);
    if(direction>0) {
        if(((struct Obj24192 *)(*(u8 * *)&((struct Obj02506 *)p)->f0))->f16+4 < ((struct Obj02506 *)p)->f1B8) CLACT_SetActorAnimSeq(((struct Obj02506 *)p)->f104,10);
        else CLACT_SetActorAnimSeq(((struct Obj02506 *)p)->f104,23);
        CLACT_SetActorAnimSeq(((struct Obj02506 *)p)->f108,3);
    } else {
        if(((struct Obj24193 *)(*(u8 * *)&((struct Obj02506 *)p)->f0))->f16==0) CLACT_SetActorAnimSeq(((struct Obj02506 *)p)->f108,24);
        else CLACT_SetActorAnimSeq(((struct Obj02506 *)p)->f108,11);
        CLACT_SetActorAnimSeq(((struct Obj02506 *)p)->f104,2);
    }
}
