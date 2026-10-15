/*
 * function: MYSTERY_ALBUM_UpdateScroll
 * address: 0x021DBA94
 * packet: pkt_ov121_021DBA94
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BG_SYS_FillScrollArea 0x02040618 arm
 */
#include "../include/Obj02834.h"
typedef signed short s16;
typedef signed char s8;
typedef unsigned int u32;
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void BG_SYS_FillScrollArea(u32,u32,u32);
int MYSTERY_ALBUM_UpdateScroll(char *p)
{
    int amount,i;
    s16 xy[4];
    if(((struct Obj02834 *)p)->fADC==0) goto idle;
    amount=(((struct Obj02834 *)p)->fADC*256)/16;
    for(i=0;i<8;i++) {
        if(*(void **)(p+i*4+0xb28)) {
            CLACT_GetActorSurfacePos(*(void **)(p+i*4+0xb28),(struct PtS *)(xy+2),0);
            xy[2]-=(s16)amount;
            CLACT_AddActorSurfacePos(*(void **)(p+i*4+0xb28),(const struct Vec2 *)(xy+2),0);
            CLACT_GetActorSurfacePos(*(void **)(p+i*4+0xb28),(struct PtS *)xy,0);
            if(xy[0]>=-16 && xy[0]<=272 && xy[1]>=-16 && xy[1]<=208)
                CLACT_SetActorDrawEnable(*(void **)(p+i*4+0xb28),1);
            else CLACT_SetActorDrawEnable(*(void **)(p+i*4+0xb28),0);
        }
    }
    if(((struct Obj02834 *)p)->fAE0) {
        CLACT_GetActorSurfacePos(((struct Obj02834 *)p)->fAF0,(struct PtS *)(xy+2),0);
        xy[2]-=(s16)amount;
        CLACT_AddActorSurfacePos(((struct Obj02834 *)p)->fAF0,(const struct Vec2 *)(xy+2),0);
        if(xy[2]>=-96 && xy[2]<=352 && xy[3]>=-96 && xy[3]<=288)
            CLACT_SetActorDrawEnable(((struct Obj02834 *)p)->fAF0,1);
        else CLACT_SetActorDrawEnable(((struct Obj02834 *)p)->fAF0,0);
    }
    BG_SYS_FillScrollArea(3,1,amount);
    BG_SYS_FillScrollArea(2,1,amount);
    if((((struct Obj02834 *)p)->fAD8)++>=15) {
        ((struct Obj02834 *)p)->fAD0^=1;
        ((struct Obj02834 *)p)->fADC=0;
    }
    return 0;
idle:
    return 1;
}
