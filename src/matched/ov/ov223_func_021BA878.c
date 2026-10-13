/*
 * function: func_021BA878,func_021BA8BC
 * unit: yes
 * address: 0x021BA878
 * packet: pkt_ov223_021BA878
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   func_0207D63C 0x0207D63C arm
 */
#include "../include/Obj10981.h"
#include "../include/Obj26089.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Actor;
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void func_0207D63C(unsigned,int,int,int,int);
void func_021BA878(char *p)
{
    u8 i;
    int alpha;
    for(i=0;i<3;i++) CLACT_SetActorObjMode(*(void **)(p+i*148+108),1);
    ((struct Obj10981 *)p)->f210=0;
    ((struct Obj10981 *)p)->f214=1;
    alpha=((struct Obj10981 *)p)->f210;
    func_0207D63C(0x04001050,0,63,alpha,16-alpha);
}
int func_021BA8BC(char *p)
{
    if(((struct Obj26089 *)p)->f214==0) return 1;
    return 0;
}
