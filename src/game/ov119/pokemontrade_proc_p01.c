/*
 * file:     pokemontrade_proc_p01.c
 * unit:     yes
 * function: func_021D8980, func_021D89A8, func_021D89CC, func_021D89EC, func_021D8A18, func_021D8A24, func_021D8A50, func_021D8AA8, func_021D8ADC, func_021D8AF4, func_021D8B0C, func_021D8B38, func_021D8B54, func_021D8C0C
 * address:  0x021D8980
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B65B4 0x021B65B4 thumb ov067
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021B6548 0x021B6548 thumb ov067
 *   func_02008FEC 0x02008FEC thumb
 *   func_02009020 0x02009020 thumb
 *   func_0203D7B0 0x0203D7B0 arm
 *   func_0203D7BC 0x0203D7BC arm
 *   func_0203C554 0x0203C554 arm
 *   func_020173EC 0x020173EC thumb
 *   func_02005E30 0x02005E30 thumb
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_02005DF8 0x02005DF8 thumb
 *   func_0209C0A4 0x0209C0A4 arm
 *   func_021DB7AC 0x021DB7AC thumb ov119
 *   func_02035CB8  0x02035CB8  arm
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 */
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj22697.h"
#include "../../matched/include/Obj22698.h"
#include "../../matched/include/Obj22699.h"
#include "../../matched/include/Obj22701.h"
#include "../../matched/include/Obj22702.h"
#include "../../matched/include/Obj22703.h"
#include "../../matched/include/Obj22704.h"
#include "../../matched/include/Obj01726.h"
#include "../../matched/include/Obj06422.h"

struct Sub02008F80Obj;
struct Actor;
struct PtS;
struct Obj;
struct Vec2;
typedef unsigned int u32;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef short s16_021D8A18;

typedef signed char s8;

typedef int s32;

typedef signed short s16_021D8B54;

typedef signed short s16_021D8C0C;

extern void func_021B65B4(u32 *p, u32 a1);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern int func_021B6548(unsigned char *p, unsigned int id, int v);
extern struct Sub02008F80Obj *func_02008FEC(void *sys);
extern int func_02009020(void *obj, int v);
extern void func_0203D7B0(u8 a0);
extern void func_0203D7BC(u8 a0);
extern void func_0203C554(u32 a);
extern u32 func_020173EC(void);
extern int func_0203CD98(void);
extern void func_02005E30(u32 a);
extern void func_02005DE4(void *p);
extern int func_02005E64(void);
extern void func_02005D90(int,int);
extern void func_02005DF8(u32 a);
extern int func_0209C0A4(int a, int b);
extern void func_021DB7AC(char *,int,int);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern void func_0204B454(struct Actor *actor, struct PtS *out, u16 space);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
int func_021D8980(char *p);
int func_021D89A8(char *p);
void func_021D89CC(char *p);
int func_021D89EC(const u8 *p);
u8 func_021D8A18(u8 *p);
int func_021D8A24(void *p);
void func_021D8A50(void *p);
int func_021D8AA8(void *p);
int func_021D8ADC(char *p);
int func_021D8AF4(int a, char *p);
int func_021D8B0C(int a, int b);
void func_021D8B38(char *p);
void func_021D8B54(void *p);
void func_021D8C0C(void *p);

/*
 * 2026-10-02: the first call's target 021B65B4 (thumb, ov067 window) was an
 *  unlabelled tail-call stub; seeded in layout/function_starts.txt and matched
 *  as src/matched/ov/ov067_func_021B65B4.c, so every call now resolves.
 */
int func_021D8980(char *p)
{
    func_021B65B4(*(u32 * *)&((struct Obj00001 *)p)->f9C0, 1);
    func_021B6558((unsigned char *)(*(u32 * *)&((struct Obj00001 *)p)->f9C0), 1, 1);
    return func_021B6548((unsigned char *)(*(u32 * *)&((struct Obj00001 *)p)->f9C0), 1, 1);
}


int func_021D89A8(char *p)
{
    void *o = func_02008FEC(((struct Obj22697 *)p)->f82C);
    int r = 0;
    if (func_02009020(o, 0) == -1)
        r = 1;
    return r;
}


void func_021D89CC(char *p)
{
    func_0203D7B0(0);
    func_0203D7BC(0);
    func_0203C554(0);
    ((struct Obj22699 *)(*(char * *)&((struct Obj22698 *)p)->f8))->f8 = 3;
}


int func_021D89EC(const u8 *p)
{
    int n;
    int i;

    n = func_020173EC();
    if (p == 0) {
        return 0;
    }
    for (i = 0; i < n; i++) {
        if (p[i] != 0) {
            return 1;
        }
    }
    return 0;
}


u8 func_021D8A18(u8 *p) { return ((struct Obj22701 *)p)->f11F2; }


/*
 * True when the object has a session and its state index is in range.
 */
int func_021D8A24(void *p)
{
    int v;

    if (*(int *)&((struct Obj00001 *)p)->f8 == 0)
        return 0;
    v = ((struct Obj00001 *)p)->f118C;
    if (v >= 4)
        return 0;
    return func_0203CD98() != 0;
}

void func_021D8A50(void *p) {
 int v;
 if(((struct Obj00001 *)p)->f1094!=0) {
 v=++((struct Obj00001 *)p)->f1094;
 if(v==2) {func_02005E30(6); return;}
 if(v==8) {
 func_02005DE4((void *)1); func_02005E64();
 ++((struct Obj00001 *)p)->f11F8;
 func_02005D90(0x3f3,0xffff); func_02005DF8(1);
 ((struct Obj00001 *)p)->f1094=0;
 }
 }
}


int func_021D8AA8(void *p)
{
    unsigned int x = ((struct Obj22702 *)p)->f118C;
    int r = 0;

    switch (x) {
    case 0:
    case 4:
    case 6:
    case 7:
    case 8:
        break;
    default:
        r = 1;
    }
    return r;
}

int func_021D8ADC(char *p)
{
    int r = 0;
    int v = ((struct Obj22703 *)p)->f118C;
    if (v == 3 || v == 9)
        r = 1;
    return r;
}

int func_021D8AF4(int a, char *p)
{
    if (a >= 2)
        return func_0209C0A4(a - 2, 6);
    return ((struct Obj22704 *)p)->f630;
}

int func_021D8B0C(int a, int b)
{
    if (a >= 2) {
        return (a - 2) % 6 + b * 6;
    }
    if (b < 3)
        return a + b * 2;
    return -1;
}

void func_021D8B38(char *p)
{
    ((struct Obj00001 *)p)->f1080 += 1;
    ((struct Obj00001 *)p)->f1084 = 1;
    func_021DB7AC(p, 0, 0);
}


void func_021D8B54(void *p)
{
    int o1, o2;
    int d;

    if (func_02035CB8((u32 *)(&o1), (u32 *)(&o2)) == 0)
        return;
    if (((struct Obj01726 *)p)->fF60 == 0)
        ((struct Obj01726 *)p)->fF5C = 0;
    if (((struct Obj01726 *)p)->fF60 != 0) {
        d = ((s16_021D8B54)((struct Obj01726 *)p)->fF64 - (s16_021D8B54)((struct Obj01726 *)p)->fF68) - o1;
        if (d < 0)
            d = -d;
        if (d > 2)
            ((struct Obj01726 *)p)->fF5C = 1;
        d = ((s16_021D8B54)((struct Obj01726 *)p)->fF66 - (s16_021D8B54)((struct Obj01726 *)p)->fF6A) - o2;
        if (d < 0)
            d = -d;
        if (d > 2)
            ((struct Obj01726 *)p)->fF5C = 1;
        d = (s16_021D8B54)((struct Obj01726 *)p)->fF64 - o1;
        if (d < 0)
            d = -d;
        if (d > 6) {
            d = (s16_021D8B54)((struct Obj01726 *)p)->fF66 - o2;
            if (d < 0)
                d = -d;
            if (d > 6)
                ((struct Obj01726 *)p)->fF70 = 0;
        }
    }
    if ((unsigned int)o2 >= 0x10 && (unsigned int)o2 < 0x90) {
        ((struct Obj01726 *)p)->fF54 = o1;
        ((struct Obj01726 *)p)->fF58 = o2;
    }
}

void func_021D8C0C(void *p) {
 int x,y; s16_021D8C0C pos[2];
 if(((struct Obj06422 *)p)->fF60!=0) {
 if(func_02035CB8((unsigned int *)(&x),(unsigned int *)(&y))!=0) {
 func_0204B454((struct Actor *)((struct Obj06422 *)p)->fF60,(struct PtS *)((char *)p+0xf6c),1);
 pos[0]=x+((struct Obj06422 *)p)->fF68;
 pos[1]=y+((struct Obj06422 *)p)->fF6A;
 if(pos[1]>150) pos[1]=150;
 func_0204B404((struct Obj *)(((struct Obj06422 *)p)->fF60),(const struct Vec2 *)pos,1);
 }
 }
}
