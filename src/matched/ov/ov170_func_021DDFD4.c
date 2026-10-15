/*
 * function: BOX2_MAIN_UpdateMoverX
 * address: 0x021DDFD4
 * packet: pkt_ov170_021DDFD4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb ov170
 */
#include "../include/Obj00000.h"
typedef struct {
    unsigned short idx, slot, f4, f6;
    int vx,vy;
    short dx,dy,x,y;
} Obj;
extern void BOX2_SEQ_GetActorSurfacePos(char *,int,short *,short *,unsigned short);
void BOX2_MAIN_UpdateMoverX(unsigned char *p,Obj *o)
{
    short t[2];
    unsigned i;
    i=*(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C+o->slot+0x3dd2);
    BOX2_SEQ_GetActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C,*(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C+o->idx+0x3dd2),&o->x,&o->y,0);
    BOX2_SEQ_GetActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C,i,&t[1],&t[0],0);
    if(o->x<=t[1]){
        o->dx=1;
        o->vx=((t[1]-o->x)<<16)/8;
    }else{
        o->dx=-1;
        o->vx=((o->x-t[1])<<16)/8;
    }
    if(o->y<=t[0]){
        o->dy=1;
        o->vy=((t[0]-o->y)<<16)/8;
    }else{
        o->dy=-1;
        o->vy=((o->y-t[0])<<16)/8;
    }
}
