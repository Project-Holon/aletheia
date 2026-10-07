/*
 * file:     unit_021BB954_p15.c
 * unit:     yes
 * function: func_021BC868, func_021BC940, func_021BC958, func_021BC9FC, func_021BCA14, func_021BCAB8, func_021BCAD0, func_021BCB70
 * address:  0x021BC868
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_020200CC 0x020200CC thumb
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BA8BC 0x021BA8BC thumb ov099
 *   func_0202020C 0x0202020C thumb
 *   func_0201F868 0x0201F868 thumb
 *   func_021BA874 0x021BA874 thumb ov099
 *   func_021BAAB8 0x021BAAB8 thumb ov099
 *   func_021BB9C8  0x021BB9C8  thumb  ov099
 *   func_021BB9F4  0x021BB9F4  thumb  ov099
 *   func_021BBA20  0x021BBA20  thumb  ov099
 *   func_02012934 0x02012934 thumb
 *   func_0201A090 0x0201A090 thumb
 */
#include "../../matched/include/Obj00977.h"
#include "../../matched/include/Obj18193.h"
#include "../../matched/include/Obj01915.h"
#include "../../matched/include/Obj22029.h"
#include "../../matched/include/Obj18194.h"
#include "../../matched/include/Obj01916.h"
#include "../../matched/include/Obj22030.h"
#include "../../matched/include/Obj18201.h"
#include "../../matched/include/Obj02154.h"
#include "../../matched/include/Obj22031.h"

struct Descriptor;
struct Obj;
struct PrintSys;
struct BigObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32_021BC868;

typedef signed int     s32_021BC868;

typedef unsigned long  u32_021BC940;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32_021BC940;

typedef int BOOL;

typedef unsigned long  u32_021BC958;

typedef signed int     s32_021BC958;

typedef unsigned long  u32_021BC9FC;

typedef signed long    s32_021BC9FC;

typedef unsigned long  u32_021BCA14;

typedef signed int     s32_021BCA14;

typedef unsigned long  u32_021BCAB8;

typedef signed long    s32_021BCAB8;

typedef unsigned long  u32_021BCAD0;

typedef signed int     s32_021BCAD0;

typedef unsigned int u32_021BCB70;

extern void *func_02045770(struct Descriptor *p);
extern u32_021BC868 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *d);
extern s32_021BC868 func_020200CC(struct Obj *o);
extern void func_021BA8EC(char *);
extern int func_021BA8BC(void *p);
extern void func_0202020C(struct Obj *o, u16 *a, u16 *b);
extern u32_021BC868 func_0201F868(void *p);
extern void func_021BA874(void *, int);
extern void func_021BAAB8(char *, int, int);
extern void func_021BB9C8(int a);
extern void func_021BB9F4(int a);
extern void func_021BBA20(int a);
extern void *func_02012934(const struct BigObj *);
extern int func_0201A090(void *, void *, u32_021BCB70 *);
int func_021BC868(char *p, int v);
int func_021BC940(char *p, int v);
int func_021BC958(char *p, int v);
int func_021BC9FC(char *p, int v);
int func_021BCA14(char *p, int v);
int func_021BCAB8(char *p, int v);
int func_021BCAD0(char *p, int v);
int func_021BCB70(void *rules, const struct BigObj *obj, u32_021BCB70 *mask);

int func_021BC868(char *p, int v)
{
    int r;
    void *q;
    q = ((struct Obj00977 *)p)->f1B8;
    if (((struct Obj00977 *)p)->f1B0 != 0) {
        if (func_0201C6C4(q, func_02045770(((struct Obj00977 *)p)->f1AC)) == 0) {
            func_02045334(((struct Obj00977 *)p)->f1AC);
            ((struct Obj00977 *)p)->f1B0 = 0;
        }
    }
    r = func_020200CC(((struct Obj00977 *)p)->fBC);
    if (r == -1) return v;
    func_021BA8EC(p);
    ((struct Obj00977 *)p)->f1A4 = (void *)func_021BA8BC(((struct Obj00977 *)p)->f1A4);
    func_0202020C(((struct Obj00977 *)p)->fBC, 0, (u16 *)(p + 0x234));
    func_0201F868(((struct Obj00977 *)p)->fB8);
    if (r == -2) {
        if (((struct Obj00977 *)p)->f135C == 3 || ((struct Obj00977 *)p)->f135C == 4) {
            func_021BA874(p, ((struct Obj00977 *)p)->f242 - 1);
            func_021BAAB8(p, 0x60, 0);
            ((struct Obj00977 *)p)->f1CC = 0x45;
        } else {
            ((struct Obj00977 *)p)->f1CC = 0x1c;
        }
    } else {
        if (((struct Obj00977 *)p)->f135C == 3 || ((struct Obj00977 *)p)->f135C == 4) {
            ((struct Obj00977 *)p)->f1CC = r;
        } else if (r == 0x5b) {
            ((struct Obj00977 *)p)->f1CC = 0x75;
        } else {
            ((struct Obj00977 *)p)->f1CC = r;
        }
    }
    return v;
}


int func_021BC940(char *p, int v)
{
    func_021BB9C8((int)p);
    ((struct Obj18193 *)p)->f1CC = 0x56;
    return v;
}


/*
 * Twins: func_021BCA14 (+0x22 byte, +0x134e halfword) and func_021BCAD0
 * (stores 1 - r at +0x20).
 */
int func_021BC958(char *p, int v)
{
    int r;
    int q;

    q = ((struct Obj01915 *)p)->f1B8;
    if (((struct Obj01915 *)p)->f1B0 != 0) {
        if (func_0201C6C4((struct PrintSys *)q, (void *)((int)func_02045770((struct Descriptor *)((struct Obj01915 *)p)->f1AC))) == 0) {
            func_02045334((struct Descriptor *)((struct Obj01915 *)p)->f1AC);
            ((struct Obj01915 *)p)->f1B0 = 0;
        }
    }
    r = func_020200CC((struct Obj *)(((struct Obj01915 *)p)->fBC));
    if (r != -2) {
        if (r == -1) {
            return v;
        }
        ((struct Obj01915 *)p)->f134C = r;
        ((struct Obj22029 *)(*(char * *)&((struct Obj01915 *)p)->f248))->f21 = r;
    }
    ((struct Obj01915 *)p)->f1CC = 0x4e;
    func_021BA8EC(p);
    ((struct Obj01915 *)p)->f1A4 = (void *)func_021BA8BC(((struct Obj01915 *)p)->f1A4);
    func_0202020C((struct Obj *)(((struct Obj01915 *)p)->fBC), 0, (u16 *)(p + 0x236));
    func_0201F868((void *)(((struct Obj01915 *)p)->fB8));
    return v;
}


int func_021BC9FC(char *p, int v)
{
    func_021BB9F4((int)p);
    ((struct Obj18194 *)p)->f1CC = 0x58;
    return v;
}


/*
 * Twin of func_021BC958 (+0x22 byte, +0x134e halfword, +0x238 out slot).
 */
int func_021BCA14(char *p, int v)
{
    int r;
    int q;

    q = ((struct Obj01916 *)p)->f1B8;
    if (((struct Obj01916 *)p)->f1B0 != 0) {
        if (func_0201C6C4((struct PrintSys *)q, (void *)((int)func_02045770((struct Descriptor *)((struct Obj01916 *)p)->f1AC))) == 0) {
            func_02045334((struct Descriptor *)((struct Obj01916 *)p)->f1AC);
            ((struct Obj01916 *)p)->f1B0 = 0;
        }
    }
    r = func_020200CC((struct Obj *)(((struct Obj01916 *)p)->fBC));
    if (r != -2) {
        if (r == -1) {
            return v;
        }
        ((struct Obj01916 *)p)->f134E = r;
        ((struct Obj22030 *)(*(char * *)&((struct Obj01916 *)p)->f248))->f22 = r;
    }
    ((struct Obj01916 *)p)->f1CC = 0x4e;
    func_021BA8EC(p);
    ((struct Obj01916 *)p)->f1A4 = (void *)func_021BA8BC(((struct Obj01916 *)p)->f1A4);
    func_0202020C((struct Obj *)(((struct Obj01916 *)p)->fBC), 0, (u16 *)(p + 0x238));
    func_0201F868((void *)(((struct Obj01916 *)p)->fB8));
    return v;
}


int func_021BCAB8(char *p, int v)
{
    func_021BBA20((int)p);
    ((struct Obj18201 *)p)->f1CC = 0x5A;
    return v;
}


/*
 * Twin of func_021BC958: stores 1 - r at +0x20 of the record at +0x248 and
 * hands +0x23a to func_0202020C.
 */
int func_021BCAD0(char *p, int v)
{
    int r;
    int q;

    q = ((struct Obj02154 *)p)->f1B8;
    if (((struct Obj02154 *)p)->f1B0 != 0) {
        if (func_0201C6C4((struct PrintSys *)q, (void *)((int)func_02045770((struct Descriptor *)((struct Obj02154 *)p)->f1AC))) == 0) {
            func_02045334((struct Descriptor *)((struct Obj02154 *)p)->f1AC);
            ((struct Obj02154 *)p)->f1B0 = 0;
        }
    }
    r = func_020200CC((struct Obj *)(((struct Obj02154 *)p)->fBC));
    if (r != -2) {
        if (r == -1) {
            return v;
        }
        ((struct Obj22031 *)(*(char * *)&((struct Obj02154 *)p)->f248))->f20 = 1 - r;
    }
    ((struct Obj02154 *)p)->f1CC = 0x4e;
    func_021BA8EC(p);
    ((struct Obj02154 *)p)->f1A4 = (void *)func_021BA8BC(((struct Obj02154 *)p)->f1A4);
    func_0202020C((struct Obj *)(((struct Obj02154 *)p)->fBC), 0, (u16 *)(p + 0x23a));
    func_0201F868((void *)(((struct Obj02154 *)p)->fB8));
    return v;
}

int func_021BCB70(void *rules, const struct BigObj *obj, u32_021BCB70 *mask)
{
    *mask = 0;
    return func_0201A090(rules, func_02012934(obj), mask);
}
