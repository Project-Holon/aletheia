/*
 * function: func_021DA320
 * address: 0x021DA320
 * packet: pkt_ov129_021DA320
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 */
#include "../include/Obj10502.h"
typedef short s16;
typedef unsigned char u8;
typedef struct { s16 x,y; } Pair;
struct Actor;
struct PtS;
typedef unsigned short u16;
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
void func_021DA320(char *p)
{
    int i;
    int x,y;
    Pair s;
    for(i=0;i<((struct Obj10502 *)p)->f23C;i++){
        if(i>=((struct Obj10502 *)p)->f248 && i<((struct Obj10502 *)p)->f24C){
            x=16;
            y=16;
        }else{
            x=4;
            y=8;
        }
        CLACT_GetActorSurfacePos(*(void **)(p+i*0x1c+12),(struct PtS *)&s,0);
        (*(u8 **)(p+i*0x1c+16))[0]=s.y-y;
        (*(u8 **)(p+i*0x1c+16))[2]=s.x-x;
        (*(u8 **)(p+i*0x1c+16))[1]=s.y+y;
        (*(u8 **)(p+i*0x1c+16))[3]=s.x+x;
    }
}
