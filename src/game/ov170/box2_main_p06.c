/*
 * file:     box2_main_p06.c
 * unit:     yes
 * function: func_021DDFD4, func_021DE07C
 * address:  0x021DDFD4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021EC0B0 0x021EC0B0 thumb ov170
 *   func_021EC548 0x021EC548 thumb
 */
#include "../../matched/include/Obj00000.h"

typedef struct {
    unsigned short idx, slot, f4, f6;
    int vx,vy;
    short dx,dy,x,y;
} Obj_021DDFD4;

typedef struct {
    unsigned short idx;
    unsigned short slot;
    unsigned short f4;
    unsigned short f6;
    int vx;
    int vy;
    short dx;
    short dy;
    short x;
    short y;
} Obj_021DE07C;

extern void func_021EC0B0(char *,int,short *,short *,unsigned short);
extern void func_021EC548(unsigned i, short *x, short *y, int mode);
void func_021DDFD4(unsigned char *p,Obj_021DDFD4 *o);
void func_021DE07C(unsigned char *p, Obj_021DE07C *o);

void func_021DDFD4(unsigned char *p,Obj_021DDFD4 *o)
{
    short t[2];
    unsigned i;
    i=*(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C+o->slot+0x3dd2);
    func_021EC0B0(*(char * *)&((struct Obj00000 *)p)->f2C,*(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C+o->idx+0x3dd2),&o->x,&o->y,0);
    func_021EC0B0(*(char * *)&((struct Obj00000 *)p)->f2C,i,&t[1],&t[0],0);
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


void func_021DE07C(unsigned char *p, Obj_021DE07C *o)
{
    short t[2];
    func_021EC0B0(*(char * *)&((struct Obj00000 *)p)->f2C, *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + o->idx + 0x3DD2), &o->x, &o->y, 0);
    func_021EC548(o->slot, &t[1], &t[0], p[0x1A]);
    t[0] += 0xC0;
    if (o->x <= t[1]) {
        o->dx = 1;
        o->vx = ((t[1] - o->x) << 16) / 8;
    } else {
        o->dx = -1;
        o->vx = ((o->x - t[1]) << 16) / 8;
    }
    if (o->y <= t[0]) {
        o->dy = 1;
        o->vy = ((t[0] - o->y) << 16) / 8;
    } else {
        o->dy = -1;
        o->vy = ((o->y - t[0]) << 16) / 8;
    }
}
