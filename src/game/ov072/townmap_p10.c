/*
 * file:     townmap_p10.c
 * unit:     yes
 * function: func_021BAD84, func_021BADBC, func_021BADF4, func_021BAE44
 * address:  0x021BAD84
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BA774 0x021BA774 thumb ov072
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B878 0x0204B878 arm
 *   func_021BAA30  0x021BAA30  thumb  ov072
 */
#include "../../matched/include/Obj03666.h"

struct Obj;
struct Vec2;
typedef short s16;

typedef struct { s16 x; s16 y; } Pos;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    int obj;
    int f4;
    int f8[10];
    u8 f30;
    u8 f31;
    u8 f32;
    int f34;
    int f38;
    int f3c;
    int f40;
} W;

extern int func_021BA774(char *p, int i);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B3DC(struct Obj *obj, unsigned int v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021BAA30(W *p, int a);
void func_021BAD84(int *p, int *b);
void func_021BADBC(char *p, int v);
void func_021BADF4(W *p);
void func_021BAE44(W *p);

void func_021BAD84(int *p, int *b) { Pos pos; pos.x=b[0]+func_021BA774((char *)p,2); pos.y=b[1]+func_021BA774((char *)p,3); if(p[0]) func_0204B404((struct Obj *)p[0],(const struct Vec2 *)(&pos),0); }

void func_021BADBC(char *p, int v) { ((struct Obj03666 *)p)->f32=v; if(((struct Obj03666 *)p)->f32!=255) { if(((struct Obj03666 *)p)->f0) { func_0204B3DC((struct Obj *)((struct Obj03666 *)p)->f0,1); func_0204B878((struct Obj *)(((struct Obj03666 *)p)->f0),((struct Obj03666 *)p)->f32); } } else { if(((struct Obj03666 *)p)->f0) func_0204B3DC((struct Obj *)((struct Obj03666 *)p)->f0,0); } }


void func_021BADF4(W *p)
{
    int r;

    r = 0;
    if (func_021BA774((char *)p, 11) == 4 || func_021BA774((char *)p, 11) == 5) {
        r = 1;
        if (p->f40 != 0) {
            r = 0;
        }
    }
    if (p->f38 != 0 || r != 0) {
        func_021BAA30(p, 1);
        func_021BADBC((char *)p, p->f31);
    } else {
        func_021BAA30(p, 0);
    }
}


void func_021BAE44(W *p)
{
    int r;

    r = 0;
    if (func_021BA774((char *)p, 11) == 4 || func_021BA774((char *)p, 11) == 5) {
        r = 1;
        if (p->f40 != 0) {
            r = 0;
        }
    }
    if (p->f38 != 0 || r != 0) {
        if (p->obj != 0) {
            func_021BAA30(p, 1);
            func_021BADBC((char *)p, p->f30);
        }
    } else {
        func_021BAA30(p, 0);
    }
}
