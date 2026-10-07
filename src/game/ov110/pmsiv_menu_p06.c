/*
 * file:     pmsiv_menu_p06.c
 * unit:     yes
 * function: func_021BC78C, func_021BC7DC, func_021BC828, func_021BC868, func_021BC898, func_021BC8C0, func_021BC8FC
 * address:  0x021BC78C
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
 *   func_02041648 0x02041648 arm
 *   func_02041664 0x02041664 arm
 *   func_021B9BA4 0x021B9BA4 thumb ov110
 *   func_02030EAC 0x02030EAC arm
 *   func_02040618 0x02040618 arm
 *   _s32_div_f 0x0209C0A4 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0207D658 0x0207D658 arm
 *   func_021BC964 0x021BC964 thumb ov110
 */
#include "../../matched/include/Obj02461.h"
#include "../../matched/include/Obj05293.h"
#include "../../matched/include/Obj02818.h"
#include "../../matched/include/Obj03753.h"
#include "../../matched/include/Obj08002.h"
#include "../../matched/include/Obj03754.h"
#include "../../matched/include/Obj03241.h"

struct Node;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short s16;

extern unsigned int func_02041648(u8 channel);
extern u32 func_02041664(u8 channel);
extern void *func_021B9BA4(void (*fn)(void *, u8 *), u8 *p, int n);
extern void func_02030EAC(struct Node *n);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern int _s32_div_f(int, int);
extern void func_0207D63C(void *, int, int, int, int);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_021BC964(void *, u8 *);
void func_021BC78C(u8 *p, int a, int b, int step, int n);
int func_021BC7DC(u8 *p);
void func_021BC828(void *unused, u8 *p);
void func_021BC868(u8 *p, int a, int b, int start, int end, int frames);
int func_021BC898(u8 *p);
void func_021BC8C0(void *task, u8 *p);
void func_021BC8FC(u8 *p,int a,int start,int end,int n);

void func_021BC78C(u8 *p, int a, int b, int step, int n)
{
    ((struct Obj02461 *)p)->f0=a;
    if (b==0) {
        ((struct Obj02461 *)p)->f8=func_02041648(a);
        ((struct Obj02461 *)p)->f4=0;
    } else {
        ((struct Obj02461 *)p)->f8=func_02041664(a);
        ((struct Obj02461 *)p)->f4=3;
    }
    ((struct Obj02461 *)p)->fC=(((struct Obj02461 *)p)->f8+step)&511;
    ((struct Obj02461 *)p)->f8<<=12;
    ((struct Obj02461 *)p)->f10=(step<<12)/n;
    ((struct Obj02461 *)p)->f14=n;
    ((struct Obj02461 *)p)->f16=0;
}

int func_021BC7DC(u8 *p)
{
    switch (((struct Obj05293 *)p)->f16) {
    case 0:
        ((struct Obj05293 *)p)->f18=func_021B9BA4(func_021BC828,p,0);
        ++((struct Obj05293 *)p)->f16;
        break;
    case 1:
        if (((struct Obj05293 *)p)->f14==0) {
            func_02030EAC(((struct Obj05293 *)p)->f18);
            ++((struct Obj05293 *)p)->f16;
            return 1;
        }
        break;
    case 2: return 1;
    }
    return 0;
}

void func_021BC828(void *unused, u8 *p)
{
    if (((struct Obj02818 *)p)->f14) {
        ((struct Obj02818 *)p)->f8 += ((struct Obj02818 *)p)->f10;
        func_02040618((u8)(((struct Obj02818 *)p)->f0), (u8)(((struct Obj02818 *)p)->f4), (int)(((struct Obj02818 *)p)->f8>>12));
        --((struct Obj02818 *)p)->f14;
    } else {
        func_02040618((u8)(((struct Obj02818 *)p)->f0), (u8)(((struct Obj02818 *)p)->f4), (int)(((struct Obj02818 *)p)->fC));
    }
}

void func_021BC868(u8 *p, int a, int b, int start, int end, int frames)
{
    ((struct Obj03753 *)p)->f0 = a;
    ((struct Obj03753 *)p)->f4 = b;
    ((struct Obj03753 *)p)->f14 = frames;
    ((struct Obj03753 *)p)->f8 = start;
    ((struct Obj03753 *)p)->f10 = _s32_div_f(end - start, frames);
    ((struct Obj03753 *)p)->fC = end;
    ((struct Obj03753 *)p)->f18 = 0;
    ((struct Obj03753 *)p)->f1C = func_021B9BA4(func_021BC8C0, p, 0);
}

int func_021BC898(u8 *p)
{
    if (((struct Obj08002 *)p)->f18 == 0) {
        if (((struct Obj08002 *)p)->f14 == 0) {
            func_02030EAC(((struct Obj08002 *)p)->f1C);
            ((struct Obj08002 *)p)->f18 += 1;
            return 1;
        }
    } else {
        return 1;
    }
    return 0;
}

void func_021BC8C0(void *task, u8 *p)
{
    int level;
    if (((struct Obj03754 *)p)->f14 != 0) {
        ((struct Obj03754 *)p)->f8 += ((struct Obj03754 *)p)->f10;
        level = ((struct Obj03754 *)p)->f8 >> 3;
        ((struct Obj03754 *)p)->f14 -= 1;
    } else {
        level = ((struct Obj03754 *)p)->fC >> 3;
    }
    if (level > 16) level = 16;
    func_0207D63C((void *)0x04000050, ((struct Obj03754 *)p)->f0, ((struct Obj03754 *)p)->f4, level, 16 - level);
}

/*
 * lever: difference of stored fixed-point fields prevents shift factoring.
 */
void func_021BC8FC(u8 *p,int a,int start,int end,int n)
{
    func_0207D658(0x4000050,a,start);
    ((struct Obj03241 *)p)->f0=a;
    ((struct Obj03241 *)p)->f14=n;
    ((struct Obj03241 *)p)->f8=start<<12;
    ((struct Obj03241 *)p)->fC=end<<12;
    ((struct Obj03241 *)p)->f10=(((struct Obj03241 *)p)->fC-((struct Obj03241 *)p)->f8)/n;
    ((struct Obj03241 *)p)->f18=0;
    ((struct Obj03241 *)p)->f1C=func_021B9BA4(func_021BC964,p,0);
}
