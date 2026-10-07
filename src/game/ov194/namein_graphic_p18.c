/*
 * file:     namein_graphic_p18.c
 * unit:     yes
 * function: func_021F42A0, func_021F42E8, func_021F436C, func_021F4390, func_021F4394, func_021F43A0, func_021F4408, func_021F4450, func_021F4480
 * address:  0x021F42A0
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_02045808 0x02045808 arm
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B454 0x0204B454 arm
 *   func_02035D20 0x02035D20 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_020257D0 0x020257D0 thumb
 *   func_0204B404 0x0204B404 arm
 *   d_020A1B38 0x020A1B38 data a4
 *   func_02045874  0x02045874  arm
 *   func_020458F8  0x020458F8  arm
 *   func_02045EC0  0x02045EC0  arm
 *   d_020A7370     0x020A7370  data
 */
#include "../../matched/include/Obj03342.h"
#include "../../matched/include/Obj01576.h"
#include "../../matched/include/Obj06641.h"
#include "../../matched/include/Obj24910.h"
#include "../../matched/include/Obj05514.h"
#include "../../matched/include/Obj14505.h"
#include "../../matched/include/Obj01287.h"

struct Grid;
struct Obj;
struct Obj020437AC;
struct U16Vec;
struct Actor;
struct PtS;
struct Vec2;
struct MsgBank;
typedef unsigned int   u32;

typedef struct {short x,y;} Vec2;

typedef unsigned short u16;

typedef unsigned char u8;

extern void func_0204ADA4(u32 i);
extern void func_02045808(struct U16Vec *vec);
extern void func_0202570C(struct Grid *g);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204B3B4(struct Obj *p);
extern void func_02082BCC(unsigned char *,unsigned,unsigned);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern unsigned func_02035D20(unsigned *,unsigned *);
extern int func_0201C6C4(int,int);
extern void func_020257D0(struct Obj *);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern struct U16Vec *func_02045874(struct U16Vec *src, u32 heapId);
extern u16 func_020458F8(struct U16Vec *vec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
void func_021F42A0(unsigned char *p);
void func_021F42E8(char *p);
void func_021F436C(unsigned char *p);
unsigned func_021F4390(unsigned char *p);
void func_021F4394(unsigned char *p);
int func_021F43A0(char *p);
int func_021F4408(int x, int y);
int func_021F4450(int *p, int *q);
int func_021F4480(u8 *p, int a, int b);
extern short d_020A1B38[];
extern u32  d_020A7370;

void func_021F42A0(unsigned char *p) {
    if (((struct Obj03342 *)p)->f2C) {
        func_0204ADA4(((struct Obj03342 *)p)->f24);
        func_02045808(((struct Obj03342 *)p)->f28);
        func_0202570C(((struct Obj03342 *)p)->f2C);
        func_020437AC(((struct Obj03342 *)p)->f30);
    }
    func_0204ADA4(((struct Obj03342 *)p)->f8);
    func_0204A8D4((u32)(((struct Obj03342 *)p)->fC));
    func_0204AFD8(((struct Obj03342 *)p)->f10);
    func_0204B3B4(((struct Obj03342 *)p)->f0);
    func_02082BCC(p,0,0x3c);
}

void func_021F42E8(char *p) {
    int rect[4];
    unsigned x,y;
    Vec2 pos;
    int point[2];
    switch (((struct Obj01576 *)p)->f18) {
    case 0:
        func_0204B454((struct Actor *)((struct Obj01576 *)p)->f0,(struct PtS *)&pos,0);
        ((struct Obj01576 *)p)->f14=0;
        if (func_02035D20(&x,&y)) {
            rect[0]=pos.x-16; rect[1]=pos.y-16;
            rect[2]=pos.x+16; rect[3]=pos.y+16;
            point[0]=x; point[1]=y;
            if (func_021F4450(rect,point)) {
                func_021F4394((unsigned char *)p);
                ((struct Obj01576 *)p)->f18=1;
            }
        }
        break;
    case 1:
        if (func_021F43A0(p)) {((struct Obj01576 *)p)->f14=1; ((struct Obj01576 *)p)->f18=0;}
        break;
    }
}

void func_021F436C(unsigned char *p){if(((struct Obj06641 *)p)->f34){if(func_0201C6C4(((struct Obj06641 *)p)->f38,((struct Obj06641 *)p)->f30)==0){func_020257D0(*(struct Obj * *)&((struct Obj06641 *)p)->f2C);((struct Obj06641 *)p)->f34=0;}}}

unsigned func_021F4390(unsigned char *p){return ((struct Obj24910 *)p)->f14;}

void func_021F4394(unsigned char *p){((struct Obj01576 *)p)->f20=0;*(unsigned *)&((struct Obj01576 *)p)->f1C=1;}

int func_021F43A0(char *p) {
    Vec2 pos;
    int tick;
    if (((struct Obj01576 *)p)->f1C) {
        tick=((struct Obj01576 *)p)->f20;
        ((struct Obj01576 *)p)->f20=tick+1;
        func_0204B454((struct Actor *)((struct Obj01576 *)p)->f0,(struct PtS *)&pos,0);
        pos.y=20-((12*d_020A1B38[((unsigned short)(32767*tick/8)>>4)*2])>>12);
        func_0204B404((struct Obj *)(((struct Obj01576 *)p)->f0),(const struct Vec2 *)(&pos),0);
        if (((struct Obj01576 *)p)->f20>8) ((struct Obj01576 *)p)->f1C=0;
        return 0;
    }
    return 1;
}

int func_021F4408(int x, int y)
{
    switch (x) {
    case 0:
    case 5:
    case 6:
    case 7:
        return 0;
    case 1: return 3;
    case 2: return 4;
    case 3: return 1;
    case 4: return y == 0xffff ? 5 : 2;
    default: return 0;
    }
}

int func_021F4450(int *p, int *q){return ((((struct Obj14505 *)q)->f0-((struct Obj05514 *)p)->f0)<=(((struct Obj05514 *)p)->f8-((struct Obj05514 *)p)->f0)) & ((((struct Obj14505 *)q)->f4-((struct Obj05514 *)p)->f4)<=(((struct Obj05514 *)p)->fC-((struct Obj05514 *)p)->f4));}


int func_021F4480(u8 *p, int a, int b)
{
    switch (a) {
    case 0:
        return 0;
    case 1:
        if (func_020458F8((struct U16Vec *)(((struct Obj01287 *)p)->f2D0)) == 0)
            return (int)func_02045EC0((struct MsgBank *)d_020A7370,
                                 *(u16 *)(*(u32 *)&((struct Obj01287 *)p)->f2C4 + 4));
        return (int)func_02045874((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    case 2:
        return (int)func_02045874((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    case 3:
        return 0;
    case 4:
        return (int)func_02045874((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    case 5:
        return (int)func_02045874((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    case 6:
        return (int)func_02045874((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    case 7:
        return (int)func_02045874((struct U16Vec *)(((struct Obj01287 *)p)->f2D0), b);
    default:
        return 0;
    }
}
