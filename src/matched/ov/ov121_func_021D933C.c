/*
 * function: MYSTERY_UpdateScrollB
 * address: 0x021D933C
 * packet: pkt_ov121_021D933C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_GetClactActor 0x021D6C58 thumb ov121
 *   CLACT_GetActorPos 0x0204B53C arm
 *   CLACT_SetActorPos 0x0204B528 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 */
#include "../include/Obj02178.h"
#include "../include/Obj05355.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int   u32;
struct Obj;
extern void *MYSTERY_GetClactActor(u8 *p, int i);
struct Actor;
struct Pt;
extern void CLACT_GetActorPos(const struct Actor *actor, struct Pt *out);
extern void CLACT_SetActorPos(struct Actor *actor, const struct Pt *src);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void BG_SYS_ResetSlot(u32 index, u32 a, u32 b);
void MYSTERY_UpdateScrollB(u8 *p)
{
    int i;
    u8 *q;
    void *sprite;
    s16 xy[2];
    if(((struct Obj02178 *)p)->f10!=-16384) {
        int base=((struct Obj02178 *)p)->f14;
        ((struct Obj02178 *)p)->f10=base+((-16384-base)*((struct Obj02178 *)p)->f8)/60;
        if((((struct Obj02178 *)p)->f8)++>60) ((struct Obj02178 *)p)->f10=-16384;
    }
    for(i=0;i<32;i++) {
        q=p+i*4;
        ((struct Obj05355 *)q)->f18=((struct Obj05355 *)q)->f18+((struct Obj05355 *)q)->f98;
        if(((struct Obj05355 *)q)->f18>=851968) ((struct Obj05355 *)q)->f18=-65536;
        sprite=MYSTERY_GetClactActor(((struct Obj02178 *)p)->f118,i+1);
        CLACT_GetActorPos(sprite,(struct Pt *)xy);
        xy[1]=((struct Obj05355 *)q)->f18>>12;
        CLACT_SetActorPos(sprite,(const struct Pt *)xy);
        if(xy[1]>=0 && xy[1]<=208) CLACT_SetActorDrawEnable(sprite,1);
        else CLACT_SetActorDrawEnable(sprite,0);
    }
    ((struct Obj02178 *)p)->fC=((struct Obj02178 *)p)->fC+((struct Obj02178 *)p)->f10;
    BG_SYS_ResetSlot(3,3,((struct Obj02178 *)p)->fC>>12);
    BG_SYS_ResetSlot(7,3,((struct Obj02178 *)p)->fC>>12);
}
