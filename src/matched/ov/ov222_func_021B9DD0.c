/*
 * function: func_021B9DD0
 * address: 0x021B9DD0
 * packet: pkt_ov222_021B9DD0
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: two zero alignment bytes at 021B9E42; no follower.
 * symbols:
 *   func_02040804 0x02040804 arm
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 */
#include "../include/Obj02560.h"
#include "../include/Obj26080.h"
typedef unsigned char u8;
typedef signed short s16;
typedef struct {s16 x,y;} Pt;
extern unsigned func_02040804(unsigned);
extern void BG_SYS_ResetSlot(unsigned,unsigned,unsigned);
typedef unsigned int   u32;
struct Actor;
struct Obj;
struct PtS;
struct Vec2;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
void func_021B9DD0(char*p)
{
    int v;
    Pt pos;
    if(((struct Obj26080 *)(*(char* *)&((struct Obj02560 *)p)->f4))->f4==0){
        v=func_02040804(1);
        if(v!=0){
            if(((struct Obj02560 *)p)->f44==0){
                if(v>=2)v=2;
                BG_SYS_ResetSlot(1,5,v);BG_SYS_ResetSlot(2,5,v);
                CLACT_GetActorSurfacePos(*(void* *)&((struct Obj02560 *)p)->f54,(struct PtS *)(&pos),0);
                pos.y=pos.y+(s16)v;
                CLACT_AddActorSurfacePos(*(void* *)&((struct Obj02560 *)p)->f54,(const struct Vec2 *)(&pos),0);
                ((struct Obj02560 *)p)->f44=0;
            }else --((struct Obj02560 *)p)->f44;
        }
    }
}
