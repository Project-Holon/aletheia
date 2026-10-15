/*
 * function: BOX2_MAIN_PlaceMonScene
 * address: 0x021DE8B4
 * packet: pkt_ov170_021DE8B4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two-byte zero alignment padding follows the 202-byte function.
 * symbols:
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb ov170
 *   BOX2_SEQ_GetSlotPos 0x021EC548 thumb ov170
 */
#include "../include/Obj10648.h"
#include "../include/Obj10649.h"
#include "../include/Obj23852.h"
typedef struct {
    unsigned short idx, slot;
    int mode, x, y, vx, vy;
    unsigned left:1;
    unsigned up:1;
} Mover;
extern void BOX2_SEQ_GetActorSurfacePos(char *, int, short *, short *, unsigned short);
extern void BOX2_SEQ_GetSlotPos(unsigned, short *, short *, int);
void BOX2_MAIN_PlaceMonScene(unsigned char *p, int slot, unsigned idx, int mode, int flag)
{
    Mover *o = *(Mover * *)&((struct Obj23852 *)(*(char * *)&((struct Obj10648 *)p)->f2C))->f60;
    short pos[2];
    short to[2];
    int d;
    BOX2_SEQ_GetActorSurfacePos(*(char * *)&((struct Obj10648 *)p)->f2C,10,&pos[1],&pos[0],0);
    BOX2_SEQ_GetSlotPos(idx,&to[1],&to[0],mode);
    if(flag==1){to[1]+=8;to[0]+=8;}else{to[0]+=4;}
    o->idx=idx;
    o->slot=slot;
    ((struct Obj10649 *)o)->f18&=3;
    o->mode=mode;
    {
        int tx=to[1];
        int px=pos[1];
        int ty;
        int py;
        if(px>tx){o->left=1;d=px-tx;}else{o->left=0;d=tx-px;}
        o->vx=(d<<8)/8;
        ty=to[0];
        py=pos[0];
        if(py>ty){((struct Obj10649 *)o)->f18|=2;d=py-ty;}
        else{((struct Obj10649 *)o)->f18&=~2;d=ty-py;}
        o->vy=(d<<8)/8;
        o->x=px<<8;
        o->y=py<<8;
    }
}
