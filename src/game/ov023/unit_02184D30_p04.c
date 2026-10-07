/*
 * file:     unit_02184D30_p04.c
 * unit:     yes
 * function: func_02185628, func_02185670, func_021856AC, func_021856CC, func_021856F4, func_02185730, func_02185764, func_021857F4, func_02185814
 * address:  0x02185628
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02039338  0x02039338  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_02186444  0x02186444  thumb  ov023
 *   func_02185354  0x02185354  thumb  ov023
 *   func_021852F4  0x021852F4  thumb  ov023
 *   func_021861C4  0x021861C4  thumb  ov023
 *   func_021862B0  0x021862B0  thumb  ov023
 *   func_0202208C 0x0202208C thumb
 *   func_021865B4  0x021865B4  thumb  ov023
 *   func_02186660  0x02186660  thumb  ov023
 *   func_02186164  0x02186164  thumb  ov023
 *   func_02184114  0x02184114  thumb  ov022
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_02184560  0x02184560  thumb  ov023
 *   func_02184180 0x02184180 thumb ov022
 *   func_0201F02C 0x0201F02C thumb
 *   func_0203996C  0x0203996C  arm
 */
#include "../../matched/include/Obj13025.h"
#include "../../matched/include/Obj20350.h"
#include "../../matched/include/Obj20351.h"
#include "../../matched/include/Obj02742.h"
#include "../../matched/include/Obj05108.h"
#include "../../matched/include/Obj00525.h"

struct Entry;
struct WordSet;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int   u32;

struct bf4210 {
    unsigned char a : 3;
    unsigned char b : 3;
    unsigned char c : 2;
};

typedef signed int     s32;

extern void func_02082BCC(void *p, int v, int n);
extern u16 func_02039338(void);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_02186444(char *p, u32 v);
extern void func_02185354(char *p);
extern void func_021852F4(void *p, int v);
extern void func_021861C4(u8 *w, u32 msg, int mode);
extern int  func_021862B0(char *p);
extern void func_0202208C(void *, unsigned int, unsigned int, unsigned int,
                        unsigned int, unsigned int, unsigned int);
extern int func_021865B4(char *p);
extern int func_02186660(char *p);
extern int func_02186164(char *p);
extern int func_02184114(unsigned char *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_02184560(char *p, int a);
extern char *func_02184180(unsigned char *p, int i);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern struct Entry *func_0203996C(s32 idx);
int func_02185628(char *p, int x);
int func_02185670(unsigned char *p, int a1);
int func_021856AC(char *p, int a1);
int func_021856CC(char *p, int a1);
int func_021856F4(char *p, int a);
int func_02185730(char *p, int a1);
int func_02185764(char *p, int x);
void func_021857F4(char *p, int a, int i);
int func_02185814(char *p, int a1);


int func_02185628(char *p, int x)
{
    u8 b[4];

    func_02082BCC(b, 0, 4);
    b[2] = 1;
    b[0] = func_02039338();
    if (func_0203D3A8(func_020399A8(), 0x2905, 4, (u32)((void *)b)))
        func_02186444(p, 12);
    func_02185354(p);
    return x;
}


int func_02185670(unsigned char *p, int a1)
{
    ((struct bf4210 *)(p + 0x4210))->b = 0;
    ((struct Obj13025 *)p)->f9288 = 0;
    func_02186444((char *)p, 4);
    func_021852F4(((struct Obj13025 *)p)->f100, 0);
    func_02185354((char *)p);
    return a1;
}


int func_021856AC(char *p, int a1)
{
    func_021861C4((u8 *)p, 6, 1);
    func_02186444(p, 0xd);
    func_02185354(p);
    return a1;
}


int func_021856CC(char *p, int a1)
{
    if (func_021862B0(p)) {
        ((struct Obj20350 *)p)->f1A4 = 0;
        func_02186444(p, 0xe);
    }
    func_02185354(p);
    return a1;
}

int func_021856F4(char *p, int a)
{
    if (++((struct Obj20351 *)p)->f1A4 > 60) {
        func_0202208C(0, 8, 8, 0, 0x10, 1, 0x28);
        a = 3;
    }
    func_02185354(p);
    return a;
}


int func_02185730(char *p, int a1)
{
    if (func_021862B0(p)) {
        if (((struct Obj02742 *)p)->f178 == 0)
            ((struct Obj02742 *)p)->f178 = (void *)func_021865B4(p);
        func_02186444(p, 0x10);
    }
    func_02185354(p);
    return a1;
}


int func_02185764(char *p, int x)
{
    int m;

    m = func_02186660(p);
    if (((struct Obj05108 *)p)->f1AC != func_02186164(p) || ((struct Obj05108 *)p)->f9280 != 0) {
        func_02185354(p);
        return x;
    }
    switch (m) {
    case 0:
        func_02186444(p, 0x11);
        func_02184114((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj05108 *)p)->f4));
        break;
    case 1:
        func_02186444(p, 4);
        func_021852F4((void *)(((struct Obj05108 *)p)->f100), 0);
        func_0201F7A8((void *)(((struct Obj05108 *)p)->f11C), 2);
        if (func_02039338() == 0) {
            func_02184560(p, 1);
            ((struct Obj05108 *)p)->f9E6C = 1;
        }
        break;
    }
    func_02185354(p);
    return x;
}

/*
 * Original narrows the lookup index to u8; its extern expresses the observed call-site width.
 */
void func_021857F4(char *p, int a, int i)
{
    char *v;
    v = func_02184180(**(u8 ** *)&((struct Obj00525 *)p)->f4, (u8)i);
    if (v != 0)
        func_0201F02C(((struct Obj00525 *)p)->f10, a, v);
}


int func_02185814(char *p, int a1)
{
    int z;
    z = 0;
    if (func_0203D3A8(func_0203996C(0xff), 0x2906, 0, 0)) {
        func_02186444(p, 0x12);
        func_021857F4(p, z, z);
        a1 = 2;
    }
    func_02185354(p);
    return a1;
}
