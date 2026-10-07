/*
 * file:     pmsiv_wordwin_p08.c
 * unit:     yes
 * function: func_021BFC20, func_021BFC64, func_021BFCA4, func_021BFD60, func_021BFD94
 * address:  0x021BFC20
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BF734 0x021BF734 thumb ov110
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021BFED0 0x021BFED0 thumb ov110
 *   func_021BFF7C 0x021BFF7C thumb ov110
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_021BC78C 0x021BC78C thumb ov110
 *   func_021BC7DC 0x021BC7DC thumb ov110
 *   func_021BF7EC 0x021BF7EC thumb ov110
 *   func_021BFDB0 0x021BFDB0 thumb ov110
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B454 0x0204B454 arm
 */
#include "../../matched/include/Obj04452.h"
#include "../../matched/include/Obj13801.h"
#include "../../matched/include/Obj03756.h"
#include "../../matched/include/Obj13802.h"
#include "../../matched/include/Obj13803.h"

struct Obj;
struct Vec2_021BFC64;
struct Descriptor;
struct Cfg;
struct Actor;
struct PtS;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef struct { u16 x,y; } Vec2_021BFC64;

typedef signed short s16;

typedef struct Vec2_021BFD94 { s16 x,y; } Vec2_021BFD94;

extern void func_0204B3DC(struct Obj *p, u32 v);
extern unsigned func_021BF734(u8 *);
extern void func_0204B404(struct Obj *p, const struct Vec2_021BFC64 *delta, u32 which);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_021BFED0(u8 *,int);
extern void func_021BFF7C(u8 *,unsigned,unsigned);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *cfg);
extern void func_021BC78C(u8 *,int,int,int,int);
extern int func_021BC7DC(u8 *);
extern void func_021BF7EC(const u8 *,u16 *,u16 *);
extern void func_021BFDB0(u8 *,u32,u32);
extern u32 func_0204B3F4(struct Obj *p);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
void func_021BFC20(u8 *p, unsigned visible);
void func_021BFC64(u8 *p, unsigned i);
void func_021BFCA4(u8 *p,int amount);
int func_021BFD60(u8 *p);
u32 func_021BFD94(u8 *p,Vec2_021BFD94 *out);

void func_021BFC20(u8 *p, unsigned visible) {
    if (visible) {
        if (**(unsigned * *)&((struct Obj04452 *)p)->f9C==0) func_0204B3DC(((struct Obj04452 *)p)->f14,1);
        else func_0204B3DC(((struct Obj04452 *)p)->f14,0);
        func_0204B3DC(((struct Obj04452 *)p)->f1C, func_021BF734(*(u8 * *)&((struct Obj04452 *)p)->f4)>14 ? 1 : 0);
    } else {
        func_0204B3DC(((struct Obj04452 *)p)->f14,visible);
        func_0204B3DC(((struct Obj04452 *)p)->f1C,0);
    }
}

/*
 * extent: two bytes of alignment padding follow the return.
 */
void func_021BFC64(u8 *p, unsigned i) {
    Vec2_021BFC64 pos;
    if (i != -1) {
        pos.x = 0x70*(i&1)+0x3e;
        pos.y = 0x18*((i>>1)+1);
        func_0204B404(((struct Obj13801 *)p)->f14, (const struct Vec2_021BFC64 *)(&pos), 0);
        func_0204B878(((struct Obj13801 *)p)->f14, 8);
    }
}

void func_021BFCA4(u8 *p,int amount) {
    int count,i;
    u8 newy;
    int newstart,start,step;
    u8 y;
    func_021BFED0(p,amount);
    count=amount*2;
    start=((struct Obj03756 *)p)->f98;
    newstart=start+count;
    step=24*amount;
    newy=(u8)(((struct Obj03756 *)p)->f94+step);
    if(amount<0) {
        start=newstart;
        y=newy;
        count=-count;
        amount=-amount;
    } else {
        y=(u8)(((struct Obj03756 *)p)->f94+192);
        start+=16;
        if(count+start>func_021BF734(*(u8 * *)&((struct Obj03756 *)p)->f4)) count--;
    }
    for(i=0;i<count;i++) {
        func_021BFF7C(p,start+i,y);
        if(i&1) y+=24;
    }
    ((struct Obj03756 *)p)->f94=newy;
    ((struct Obj03756 *)p)->f98=newstart;
    func_02045334((struct Descriptor *)((struct Obj03756 *)p)->fC);
    func_02045374((struct Cfg *)(((struct Obj03756 *)p)->fC));
    func_021BC78C(p+0x6c,2,1,step,amount);
}

int func_021BFD60(u8 *p) { u16 x,y; if(func_021BC7DC(p+0x6c)) { func_021BF7EC(*(const u8 * *)&((struct Obj13802 *)p)->f4,&x,&y); func_021BFDB0(p,x,y); return 1; } return 0; }

u32 func_021BFD94(u8 *p,Vec2_021BFD94 *out) { u32 result; result=func_0204B3F4(((struct Obj13803 *)p)->f1C); func_0204B454(((struct Obj13803 *)p)->f1C,(struct PtS *)out,0); return result; }
