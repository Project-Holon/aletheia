/*
 * function: WIFI_2DCHAR_SetActorPos
 * address: 0x021C41DC
 * packet: pkt_ov127_021C41DC
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_SetActorPos 0x0204B528 arm
 */
#include "../include/Obj10463.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Actor;
typedef struct Pt {u16 x,y;} Pt;
extern void CLACT_SetActorPos(struct Actor *, const struct Pt *);
void WIFI_2DCHAR_SetActorPos(u8 *p,int x,int y)
{
    Pt pos;
    pos.x=x; pos.y=y;
    CLACT_SetActorPos(*(struct Actor * *)&((struct Obj10463 *)p)->f4, &pos);
    if (((struct Obj10463 *)p)->f8 != 0) {
        pos.x=(s16)pos.x+8;
        pos.y=(s16)pos.y+14;
        CLACT_SetActorPos(*(struct Actor * *)&((struct Obj10463 *)p)->f8, &pos);
    }
}
