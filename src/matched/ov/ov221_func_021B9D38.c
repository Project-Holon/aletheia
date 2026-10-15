/*
 * function: CHIHOU_ZUKAN_AWARD_UpdateActor
 * address: 0x021B9D38
 * packet: pkt_ov221_021B9D38
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02040804 0x02040804 arm
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
#include "../include/Obj02558.h"
#include "../include/Obj26068.h"
struct Obj;
struct Vec2 { short x,y; };
extern unsigned func_02040804(unsigned);
extern void BG_SYS_ResetSlot(unsigned,unsigned,unsigned);
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void CLACT_AddActorSurfacePos(struct Obj *,const struct Vec2 *,unsigned);
void CHIHOU_ZUKAN_AWARD_UpdateActor(unsigned char *p)
{
    int amount;
    if(((struct Obj26068 *)(*(unsigned char * *)&((struct Obj02558 *)p)->f4))->f4!=0) return;
    amount=func_02040804(1);
    if(!amount) return;
    if(p[0x44]==0) {
        struct Vec2 pair;
        if(amount>=2) amount=2;
        BG_SYS_ResetSlot(1,5,amount);
        BG_SYS_ResetSlot(2,5,amount);
        CLACT_GetActorSurfacePos((struct Actor *)*(struct Obj * *)&((struct Obj02558 *)p)->f54,(struct PtS *)&pair,0);
        pair.y+=(short)amount;
        CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct Obj02558 *)p)->f54,&pair,0);
        p[0x44]=0;
        return;
    }
    p[0x44]--;
}
