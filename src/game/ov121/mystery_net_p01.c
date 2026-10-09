/*
 * file:     mystery_net_p01.c
 * unit:     yes
 * function: func_021DD980, func_021DD9CC
 * address:  0x021DD980
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_021DA3C0 0x021DA3C0 thumb ov121
 *   func_021DBEE4 0x021DBEE4 thumb ov121
 *   func_0204B84C 0x0204B84C arm
 *   func_021DAB50 0x021DAB50 thumb ov121
 *   func_02006984 0x02006984 thumb
 *   func_0204B454 0x0204B454 arm
 *   func_0204B5FC 0x0204B5FC arm
 *   func_021DE128 0x021DE128 thumb ov121
 *   func_021DE154 0x021DE154 thumb ov121
 *   func_0204B404 0x0204B404 arm
 *   func_02006BD0 0x02006BD0 thumb
 *   func_021DDC30 0x021DDC30 arm ov121
 *   func_021DDC44 0x021DDC44 arm ov121
 */
#include "../../matched/include/Obj03789.h"

struct Node;
struct Actor;
struct PtS;
typedef unsigned char  u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef signed short s16;

typedef struct { s16 x,y; } Point;

typedef struct { s16 kind,x,y; } Output;

extern void func_02030EAC(struct Node *n);
extern unsigned int func_020307B0(void *p);
extern void func_021DA3C0(u8 *p);
extern void func_021DBEE4(u32 p);
extern void func_0204B84C(void *,u8);
extern void func_021DAB50(void *a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last);
extern u32 func_02006984(u32,u32,u32,u32,u32,u32,u32,u32);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern u16 func_0204B5FC(const struct Actor *actor);
extern void func_021DE128(u8 *p, u16 b, int c, int d);
extern int func_021DE154(void *,void *,void *);
extern void func_0204B404(void *,const Point *,u16);
extern u32 func_02006BD0(u32 i);
extern void func_021DDC30(int,int);
extern void func_021DDC44(int,int);
void func_021DD980(char *p);
void func_021DD9CC(char *p);

/*
 * extent: two bytes of zero alignment padding after the return.
 */
void func_021DD980(char *p)
{
    if (((struct Obj03789 *)p)->f128) {
        func_02030EAC(((struct Obj03789 *)p)->f128);
        ((struct Obj03789 *)p)->f128=0;
    }
    if (((struct Obj03789 *)p)->f13C) func_020307B0(((struct Obj03789 *)p)->f13C);
    if (((struct Obj03789 *)p)->f134) func_020307B0(((struct Obj03789 *)p)->f134);
    func_021DA3C0(((struct Obj03789 *)p)->f144);
    func_021DBEE4((u32)p);
    func_020307B0(p);
}

/*
 * verdict: 612-byte lead; the rest of the 652-byte extent is the two ARM
 *   followers 021DDC30 and 021DDC44 (20 bytes each), filed as their own
 *   ARM leaves (pkt_ov121_021DDC30, pkt_ov121_021DDC44, W82 R11), which
 *   also resolve the ABS32 blend callbacks at +0x258/+0x25C.
 * lever: case 5 seeds the result flag with its own constant and ANDs the
 *   call in (done = 1; done &= f(...)); "f(...) & 1" or "1 & f(...)" CSEs
 *   the 1 with ok's r6 (11 bytes).
 */
void func_021DD9CC(char *p)
{
    char *q=*(char **)(p+0x11c);
    int layer,a,b,done,ok;
    u16 tick;
    void (*blend)(int,int);
    Point pos;
    int xy[2];
    Output pt;
    if(*(int *)(q+0x84)) { layer=14; blend=func_021DDC30; }
    else { blend=func_021DDC44; layer=30; }
    switch(*(u16 *)(p+0xdc)) {
    case 1:
        func_0204B84C(*(void **)(q+0x20),*(u32 *)(q+0x90));
        *(u16 *)(p+0xdc)=2;
        break;
    case 2:
        func_021DAB50((void *)layer,(u16 *)(q+0x24),(*(u16 *)(p+0xde)*0x7fff)/60,(u8)(*(u32 *)(q+0x88)),(const u16 *)(q+0x64),(const u16 *)(q+0x44));
        tick=*(u16 *)(p+0xde);
        a=tick*14/60;
        b=tick*-12/60;
        blend(a+2,b+12);
        if((*(u16 *)(p+0xde))++>60) {
            *(u16 *)(p+0xde)=0;
            *(u16 *)(p+0xdc)=3;
        }
        break;
    case 3: *(u16 *)(p+0xdc)=4; break;
    case 4:
        if(!*(int *)(p+0xe0))
            *(u32 *)(p+0xe8)=func_02006984(*(u16 *)(p+0xe4),*(u16 *)(p+0xe6),64,0,0,0,0,0);
        func_0204B454(*(void **)(q+0x20),(struct PtS *)(&pos),*(u32 *)(q+0x98));
        func_021DE128((u8 *)(p+0xec),func_0204B5FC(*(void **)(q+0x20)),pos.x,pos.y);
        *(u16 *)(p+0xdc)=5;
        break;
    case 5:
        ok=1;
        done=1;
        done&=func_021DE154(p+0xec,&pt,xy);
        pt.x=xy[0];
        pt.y=xy[1];
        func_0204B404(*(void **)(q+0x20),(Point *)&pt.x,*(u32 *)(q+0x98));
        if(!*(int *)(p+0xe0)) {
            if(func_02006BD0(*(u32 *)(p+0xe8))) ok=0;
            done &= ok;
        }
        if(done) *(u16 *)(p+0xdc)=6;
        break;
    case 6:
        func_021DAB50((void *)layer,(u16 *)(q+0x24),0x7fff-(*(u16 *)(p+0xde)*0x7fff)/60,(u8)(*(u32 *)(q+0x88)),(const u16 *)(q+0x64),(const u16 *)(q+0x44));
        tick=*(u16 *)(p+0xde);
        a=tick*-14/60;
        b=tick*12/60;
        blend(a+16,b);
        if((*(u16 *)(p+0xde))++>60) {
            *(u16 *)(p+0xde)=0;
            *(u16 *)(p+0xdc)=7;
        }
        break;
    case 7: *(u16 *)(p+0xdc)=8; break;
    case 8:
        func_0204B84C(*(void **)(q+0x20),*(u32 *)(q+0x8c));
        *(u16 *)(p+0xdc)=0;
        break;
    }
}
