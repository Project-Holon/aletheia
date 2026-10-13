/*
 * function: func_021D928C
 * address: 0x021D928C
 * packet: pkt_ov121_021D928C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6C58 0x021D6C58 thumb ov121
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_GetActorPos 0x0204B53C arm
 *   CLACT_SetActorPos 0x0204B528 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_02041EE4 0x02041EE4 arm
 */
#include "../include/Obj02177.h"
#include "../include/Obj08089.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int   u32;
struct Obj;
extern void *func_021D6C58(u8 *p, int i);
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
struct Actor;
struct Pt;
extern void CLACT_GetActorPos(const struct Actor *actor, struct Pt *out);
extern void CLACT_SetActorPos(struct Actor *actor, const struct Pt *src);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void func_02041EE4(u32 index, u32 a, u32 b);
void func_021D928C(u8 *p)
{
    int i;
    void *sprite;
    u8 *q;
    s16 xy[2];
    if(((struct Obj02177 *)p)->f10!=-819) {
        int base=((struct Obj02177 *)p)->f14;
        ((struct Obj02177 *)p)->f10=base+((-819-base)*((struct Obj02177 *)p)->f8)/60;
        if((((struct Obj02177 *)p)->f8)++>60) ((struct Obj02177 *)p)->f10=-819;
    }
    for(i=0;i<32;i++) {
        sprite=func_021D6C58(((struct Obj02177 *)p)->f118,i+1);
        if(CLACT_GetActorDrawEnable(sprite)) {
            q=p+i*4;
            ((struct Obj08089 *)q)->f18=((struct Obj08089 *)q)->f18+((struct Obj08089 *)q)->f98;
            CLACT_GetActorPos(sprite,(struct Pt *)xy);
            xy[1]=((struct Obj08089 *)q)->f18>>12;
            CLACT_SetActorPos(sprite,(const struct Pt *)xy);
            if(xy[1]>=0 && xy[1]<=208) CLACT_SetActorDrawEnable(sprite,1);
            else CLACT_SetActorDrawEnable(sprite,0);
        }
    }
    ((struct Obj02177 *)p)->fC=((struct Obj02177 *)p)->fC+((struct Obj02177 *)p)->f10;
    func_02041EE4(3,3,((struct Obj02177 *)p)->fC>>12);
    func_02041EE4(7,3,((struct Obj02177 *)p)->fC>>12);
}
