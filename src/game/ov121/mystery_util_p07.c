/*
 * file:     mystery_util_p07.c
 * unit:     yes
 * function: func_021DA6D0, func_021DA840, func_021DA84C, func_021DA854
 * address:  0x021DA6D0
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
 *   func_020362DC 0x020362DC arm
 *   func_0203633C 0x0203633C arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 *   func_021DAAA4 0x021DAAA4 thumb ov121
 *   d_021DF76C 0x021DF76C data a4
 *   func_021DA2C8  0x021DA2C8  thumb
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021DA8B0 0x021DA8B0 thumb ov121
 *   d_021DFBA0 0x021DFBA0 data a1
 */
#include "../../matched/include/Obj00360.h"
#include "../../matched/include/Obj06450.h"
#include "../../matched/include/Obj22893.h"

struct Obj;
struct Vec2;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef struct {s16 x,y;} Position;

typedef struct {int x,y;} TablePair;

typedef signed int     s32;

extern u32 func_020362DC(void);
extern u32 func_0203633C(void);
extern void func_020061E4(u32 a);
extern u64 _u32_div_f(u32,u32);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B878(struct Obj *p, u16 value);
extern s32 func_021DAAA4(int a, u16 *p, int angle, int bank, u8 index, u16 c1, u16 c2);
extern int func_021DA2C8(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *,int,u32);
extern void func_021DA8B0(u32 *p, u32 a);
int func_021DA6D0(u8 *p);
int func_021DA840(void **p);
void func_021DA84C(u8 *p,u32 i,u32 value);
void *func_021DA854(void *a,void *b,u16 heap);
extern const TablePair d_021DF76C[];
extern const char d_021DFBA0[];

/*
 * arithmetic: direct division helper uses quotient r0/remainder r1 as a scalar u64;
 *             the caller admits count zero, so ordinary C remainder is not used.
 */
int func_021DA6D0(u8 *p)
{
    u32 keys=func_020362DC();
    u32 repeat=func_0203633C();
    int changed=0;
    int i;
    int phase;
    int oldphase;
    u32 index;
    Position pos;
    if(repeat&64) {
        index=((struct Obj00360 *)p)->f8==0 ? ((struct Obj00360 *)p)->fC-1 : ((struct Obj00360 *)p)->f8-1;
        ((struct Obj00360 *)p)->f8=index;
        if(((struct Obj00360 *)p)->fC!=1) func_020061E4(0x548);
        changed=1;
    } else if(repeat&128) {
        if(((struct Obj00360 *)p)->fC!=1) func_020061E4(0x548);
        ((struct Obj00360 *)p)->f8+=1;
        ((struct Obj00360 *)p)->f8=(u32)(_u32_div_f(((struct Obj00360 *)p)->f8,((struct Obj00360 *)p)->fC)>>32);
        changed=1;
    } else if(keys&1) {
        func_020061E4(0x54c);
        return ((struct Obj00360 *)p)->f8;
    } else if(keys&2) {
        func_020061E4(0x551);
        if(((struct Obj00360 *)p)->fC==1) return -2;
        if(((struct Obj00360 *)p)->f8!=3) **(u32 * *)&((struct Obj00360 *)p)->f60=((struct Obj00360 *)p)->f8;
        ((struct Obj00360 *)p)->f8=((struct Obj00360 *)p)->fC-1;
        return ((struct Obj00360 *)p)->f8;
    }
    if(changed) {
        pos.x=d_021DF76C[*(u32 *)(p+8)].x;
        pos.y=d_021DF76C[*(u32 *)(p+8)].y+((struct Obj00360 *)p)->f2E*8;
        func_0204B404(((struct Obj00360 *)p)->f4,(const struct Vec2 *)(&pos),0);
        if(((struct Obj00360 *)p)->f8==3) func_0204B878(((struct Obj00360 *)p)->f4,2);
        else func_0204B878(((struct Obj00360 *)p)->f4,((struct Obj00360 *)p)->f30);
        if(*(void (**)(u32))(p+0x34)) (*(void (**)(u32))(p+0x34))(((struct Obj00360 *)p)->f38);
    }
    oldphase=((struct Obj00360 *)p)->f24;
    phase=oldphase+0x400;
    if(phase>=0x10000) ((struct Obj00360 *)p)->f24=oldphase-0xfc00;
    else ((struct Obj00360 *)p)->f24=phase;
    for(i=0;i<4;i++) {
        u8 *v=p+i*4;
        if(((struct Obj06450 *)v)->f4C!=((struct Obj06450 *)v)->f3C && ((struct Obj00360 *)p)->f24>=0x7dff && ((struct Obj00360 *)p)->f24<=0x81ff)
            ((struct Obj06450 *)v)->f3C=((struct Obj06450 *)v)->f4C;
        if(((struct Obj06450 *)v)->f3C)
            func_021DAAA4((int)((void *)15),(u16 *)(p+0x1a+i*2),((struct Obj00360 *)p)->f24,(u8)(((struct Obj00360 *)p)->f2C),(u8)(i+10),*(u16 *)(p+0x12+i*2),((struct Obj00360 *)p)->f22);
    }
    return -1;
}


/*
 * Addresses are Black-image addresses.
 */
int func_021DA840(void **p)
{
    return func_021DA2C8(*p);
}

void func_021DA84C(u8 *p,u32 i,u32 value)
{
    *(u32 *)(p+i*4+76)=value;
}

void *func_021DA854(void *a,void *b,u16 heap) { u8 *p; p=func_02030734(heap,20,0,d_021DFBA0,0x61c); func_02082BCC(p,0,20); ((struct Obj22893 *)p)->fC=a; func_021DA8B0((u32 *)p,(u32)b); return p; }
