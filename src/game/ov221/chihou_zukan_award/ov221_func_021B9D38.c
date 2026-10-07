/*
 * function: func_021B9D38
 * address: 0x021B9D38
 * packet: pkt_ov221_021B9D38
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02040804 0x02040804 arm
 *   func_02041EE4 0x02041EE4 arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */
#include "../../../matched/include/Obj02558.h"
#include "../../../matched/include/Obj26068.h"
struct Obj;
struct Vec2 { short x,y; };
extern unsigned func_02040804(unsigned);
extern void func_02041EE4(unsigned,unsigned,unsigned);
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *,const struct Vec2 *,unsigned);
void func_021B9D38(unsigned char *p)
{
    int amount;
    if(((struct Obj26068 *)(*(unsigned char * *)&((struct Obj02558 *)p)->f4))->f4!=0) return;
    amount=func_02040804(1);
    if(!amount) return;
    if(p[0x44]==0) {
        struct Vec2 pair;
        if(amount>=2) amount=2;
        func_02041EE4(1,5,amount);
        func_02041EE4(2,5,amount);
        func_0204B454((struct Actor *)*(struct Obj * *)&((struct Obj02558 *)p)->f54,(struct PtS *)&pair,0);
        pair.y+=(short)amount;
        func_0204B404(*(struct Obj * *)&((struct Obj02558 *)p)->f54,&pair,0);
        p[0x44]=0;
        return;
    }
    p[0x44]--;
}
