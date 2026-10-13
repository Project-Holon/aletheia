/*
 * function: func_021BA8D0
 * address: 0x021BA8D0
 * packet: pkt_ov223_021BA8D0
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   func_0207D63C 0x0207D63C arm
 */
#include "../include/Obj02939.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Actor;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void func_0207D63C(unsigned,int,int,int,int);
void func_021BA8D0(char *p)
{
    u8 i;
    switch(((struct Obj02939 *)p)->f214) {
    case 1:
        for(i=0;i<3;i++) CLACT_SetActorDrawEnable(*(void **)(p+i*148+108),1);
        ((struct Obj02939 *)p)->f214=2;
        break;
    case 2:
        if(((struct Obj02939 *)p)->f210<16) {
            ++((struct Obj02939 *)p)->f210;
            if(((struct Obj02939 *)p)->f210==16) {
                for(i=0;i<3;i++) CLACT_SetActorObjMode(*(void **)(p+i*148+108),0);
                ((struct Obj02939 *)p)->f214=3;
            }
            func_0207D63C(0x04001050,0,63,((struct Obj02939 *)p)->f210,16-((struct Obj02939 *)p)->f210);
        } else ((struct Obj02939 *)p)->f214=3;
        break;
    case 3:
        func_0207D63C(0x04001050,4,63,8,8);
        ((struct Obj02939 *)p)->f214=0;
        break;
    }
}
