/*
 * function: func_021B8040
 * address: 0x021B8040
 * packet: pkt_ov173_021B8040
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
#include "../include/Obj00180.h"
#include "../include/Obj24194.h"
#include "../include/Obj24195.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void func_021B8040(u8 *p)
{
    if(((struct Obj00180 *)p)->f1B8<=4) {
        CLACT_SetActorAnimSeq(((struct Obj00180 *)p)->f108,17);
        CLACT_SetActorAnimSeq(((struct Obj00180 *)p)->f104,16);
        return;
    }
    if(((struct Obj24194 *)(*(u8 * *)&((struct Obj00180 *)p)->f0))->f16+4 < ((struct Obj00180 *)p)->f1B8) {
        CLACT_SetActorAnimSeq(((struct Obj00180 *)p)->f108,17);
        CLACT_SetActorAnimSeq(((struct Obj00180 *)p)->f104,2);
        return;
    }
    if(((struct Obj24195 *)(*(u8 * *)&((struct Obj00180 *)p)->f0))->f16==0) {
        CLACT_SetActorAnimSeq(((struct Obj00180 *)p)->f108,3);
        CLACT_SetActorAnimSeq(((struct Obj00180 *)p)->f104,16);
    }
}
