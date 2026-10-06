/*
 * function: func_021DBA94
 * address: 0x021DBA94
 * packet: pkt_ov121_021DBA94
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02040618 0x02040618 arm
 */
#include "../include/Obj02834.h"
typedef signed short s16;
typedef signed char s8;
typedef unsigned int u32;
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_02040618(u32,u32,u32);
int func_021DBA94(char *p)
{
    int amount,i;
    s16 xy[4];
    if(((struct Obj02834 *)p)->fADC==0) goto idle;
    amount=(((struct Obj02834 *)p)->fADC*256)/16;
    for(i=0;i<8;i++) {
        if(*(void **)(p+i*4+0xb28)) {
            func_0204B454(*(void **)(p+i*4+0xb28),(struct PtS *)(xy+2),0);
            xy[2]-=(s16)amount;
            func_0204B404(*(void **)(p+i*4+0xb28),(const struct Vec2 *)(xy+2),0);
            func_0204B454(*(void **)(p+i*4+0xb28),(struct PtS *)xy,0);
            if(xy[0]>=-16 && xy[0]<=272 && xy[1]>=-16 && xy[1]<=208)
                func_0204B3DC(*(void **)(p+i*4+0xb28),1);
            else func_0204B3DC(*(void **)(p+i*4+0xb28),0);
        }
    }
    if(((struct Obj02834 *)p)->fAE0) {
        func_0204B454(((struct Obj02834 *)p)->fAF0,(struct PtS *)(xy+2),0);
        xy[2]-=(s16)amount;
        func_0204B404(((struct Obj02834 *)p)->fAF0,(const struct Vec2 *)(xy+2),0);
        if(xy[2]>=-96 && xy[2]<=352 && xy[3]>=-96 && xy[3]<=288)
            func_0204B3DC(((struct Obj02834 *)p)->fAF0,1);
        else func_0204B3DC(((struct Obj02834 *)p)->fAF0,0);
    }
    func_02040618(3,1,amount);
    func_02040618(2,1,amount);
    if((((struct Obj02834 *)p)->fAD8)++>=15) {
        ((struct Obj02834 *)p)->fAD0^=1;
        ((struct Obj02834 *)p)->fADC=0;
    }
    return 0;
idle:
    return 1;
}
