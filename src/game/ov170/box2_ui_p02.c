/*
 * file:     box2_ui_p02.c
 * unit:     yes
 * function: func_021EDD38, func_021EDECC, func_021EDF5C, func_021EDFC4, func_021EE008, func_021EE038, func_021EE0FC, func_021EE120
 * address:  0x021EDD38
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
 *   func_021EC0B0 0x021EC0B0 thumb
 *   func_021EC08C 0x021EC08C thumb
 *   func_020258E8 0x020258E8 thumb
 *   func_0202590C 0x0202590C thumb
 *   func_021DEB14 0x021DEB14 thumb
 *   func_021EDB64 0x021EDB64 thumb
 *   func_021EB874 0x021EB874 thumb
 *   func_021EC01C 0x021EC01C thumb
 *   func_021EC000 0x021EC000 thumb ov170
 *   d_021EFCD8 0x021EFCD8 data a2
 *   func_02025774 0x02025774 thumb
 *   func_021EB85C  0x021EB85C  thumb  ov170
 *   func_021EBFCC 0x021EBFCC thumb
 *   func_02025538 0x02025538 thumb
 *   func_02043678 0x02043678 arm
 *   func_020255A0 0x020255A0 thumb
 */
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj24025.h"
#include "../../matched/include/Obj24026.h"
#include "../../matched/include/Obj09226.h"
#include "../../matched/include/Obj01419.h"

struct Grid;
struct Obj02025774;
struct Bmp;
struct Sys;
typedef signed short   s16;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef unsigned short u16;

struct Param {void *bmp; short x,y; u32 f8,fc; u8 f10,f11; u16 f12;u32 f14;};

extern void func_021EC0B0(char *p, int i, short *a, short *b, unsigned short space);
extern void func_021EC08C(char *p, int i, int a, int b, unsigned short c);
extern void func_020258E8(struct Obj02025774 *p, s16 *out_x, s16 *out_y);
extern void func_0202590C(struct Grid *g, s16 x, s16 y);
extern unsigned char func_021DEB14(unsigned char *p, int a);
extern void func_021EDB64(char *p, int a, int i);
extern void func_021EB874(char **p, unsigned a, int i);
extern u32 func_021EC01C(char *p, int i);
extern void func_021EC000(char *, int, int);
extern void func_02025774(u8 *g, u32 a);
extern void func_021EB85C(unsigned char *p, int i);
extern void func_021EBFCC(char *p, int i, int v);
extern void *func_02025538(u32,void *);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern struct Grid *func_020255A0(struct Sys *sys, const struct Param *param);
void func_021EDD38(char *p, int d);
void func_021EDECC(unsigned char *p, int d);
void func_021EDF5C(unsigned char *p);
void func_021EDFC4(char *p, int i);
void func_021EE008(char *p, int a, int b);
void func_021EE038(char *p, int a, int b, int c);
void func_021EE0FC(char *p);
void func_021EE120(char *p);
extern const short d_021EFCD8[];


void func_021EDD38(char *p, int d)
{
    short t[4];
    int step;
    int i;
    short x, y;
    int k;
    step = ((d < 0 ? -d : d) == 5) ? 2 : 8;
    if (d < 0)
        step *= -1;
    for (i = 0; i < 6u; i++) {
        func_021EC0B0(*(char * *)&((struct Obj00000 *)p)->f2C, i + 0x2D, &t[3], &t[2], 0);
        x = t[2] + step;
        func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, i + 0x2D, (short)t[3], (short)x, (short)0);
        func_020258E8(*(void **)(*(char * *)&((struct Obj00000 *)p)->f2C + i * 8 + 0xC), &t[1], &t[0]);
        y = t[0] + step;
        func_0202590C(*(void **)(*(char * *)&((struct Obj00000 *)p)->f2C + i * 8 + 0xC), t[1], y);
        if (x < -0x10) {
            k = func_021DEB14((unsigned char *)p, 4);
            func_021EDB64(p, k, i + 0x2D);
            func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, i + 0x2D, (short)t[3], (short)(x + 0xCC), (short)0);
            func_021EB874((char **)p, k, i + 1);
            func_0202590C(*(void **)(*(char * *)&((struct Obj00000 *)p)->f2C + i * 8 + 0xC), t[1], y + 0xCC);
        } else if (x >= 0xBA) {
            k = func_021DEB14((unsigned char *)p, -1);
            func_021EDB64(p, k, i + 0x2D);
            func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, i + 0x2D, (short)t[3], (short)(x - 0xCC), (short)0);
            func_021EB874((char **)p, k, i + 1);
            func_0202590C(*(void **)(*(char * *)&((struct Obj00000 *)p)->f2C + i * 8 + 0xC), t[1], y - 0xCC);
        }
    }
    if (func_021EC01C(*(char * *)&((struct Obj00000 *)p)->f2C, 2) == 1) {
        func_021EC0B0(*(char * *)&((struct Obj00000 *)p)->f2C, 2, &t[3], &t[2], 0);
        func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, 2, (short)t[3], (short)(t[2] + step), (short)0);
    }
}

void func_021EDECC(unsigned char *p, int d)
{
    short t[2];
    if (d < 0 && p[0x14] == func_021DEB14(p, -1)) {
        func_021EC0B0(*(char * *)&((struct Obj00000 *)p)->f2C, 2, &t[1], &t[0], 0);
        func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, 2, t[1], -0x22, 0);
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 2, 1);
        return;
    }
    if (d > 0 && p[0x14] == func_021DEB14(p, 4)) {
        func_021EC0B0(*(char * *)&((struct Obj00000 *)p)->f2C, 2, &t[1], &t[0], 0);
        func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, 2, t[1], 0xcc, 0);
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 2, 1);
    }
}


void func_021EDF5C(unsigned char *p)
{
    unsigned i;
    short xy[2];
    for (i = 0; i < 6; i++) {
        if (p[0x14] == func_021DEB14(p, (signed char)(i - 1))) {
            func_021EC0B0(*(char * *)&((struct Obj00000 *)p)->f2C, 2, &xy[1], &xy[0], 0);
            func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, 2, (short)xy[1], (short)(i * 0x22), (short)0);
            func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 2, 1);
            return;
        }
    }
    func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 2, 0);
}

void func_021EDFC4(char *p, int i)
{
    short y = d_021EFCD8[i];
    func_021EC08C(*(char * *)&((struct Obj00000 *)p)->f2C, 3, 0xce, y, 0);
    func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 3, 1);
    func_0202590C(((struct Obj24025 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f4, 0x9e, y - 8);
    func_02025774(((struct Obj24026 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f4, 1);
}

/*
 * Two-way: with flag 1 run the pair update, otherwise release slot 3
 *   and post 0 to the p+0x2c+4 object.
 */
void func_021EE008(char *p, int a, int b)
{
    if (b == 1) {
        func_021EB85C((unsigned char *)p, a);
        func_021EDFC4(p, a);
        return;
    }
    func_021EC000((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 3, 0);
    func_02025774((u8 *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 4)), 0);
}


void func_021EE038(char *p, int a, int b, int c)
{
    p[0x1F] = a;
    p[0x20] = b;
    p[0x21] = c;
    if (a == 0) {
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 6, 1);
        func_021EBFCC(*(char * *)&((struct Obj00000 *)p)->f2C, 6, 1);
    } else if (a == 1) {
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 6, 0);
    } else {
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 6, 1);
        func_021EBFCC(*(char * *)&((struct Obj00000 *)p)->f2C, 6, 0xF);
    }
    if (b == 0) {
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 7, 1);
        func_021EBFCC(*(char * *)&((struct Obj00000 *)p)->f2C, 7, 0);
    } else if (b == 1) {
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 7, 0);
    } else {
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 7, 1);
        func_021EBFCC(*(char * *)&((struct Obj00000 *)p)->f2C, 7, 0xE);
    }
    if (c == 0) {
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 8, 1);
        func_021EBFCC(*(char * *)&((struct Obj00000 *)p)->f2C, 8, 0);
    } else if (c == 1) {
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 8, 0);
    } else {
        func_021EC000(*(char * *)&((struct Obj00000 *)p)->f2C, 8, 1);
        func_021EBFCC(*(char * *)&((struct Obj00000 *)p)->f2C, 8, 2);
    }
}

/*
 * Release slots 6, 7 and 8 of the 0x9E74 array.
 */
void func_021EE0FC(char *p)
{
    func_021EC000((char *)(((struct Obj09226 *)p)->f2C), 6, 0);
    func_021EC000((char *)(((struct Obj09226 *)p)->f2C), 7, 0);
    func_021EC000((char *)(((struct Obj09226 *)p)->f2C), 8, 0);
}

void func_021EE120(char *p)
{
    struct Param s;
    u32 i;
    ((struct Obj01419 *)p)->f0=func_02025538(76,((struct Obj01419 *)p)->f9E70);
    ((struct Obj01419 *)p)->f8=func_02043678(12,2,32,76);
    s.bmp=((struct Obj01419 *)p)->f8;s.x=0;s.y=0;
    s.f8=((struct Obj01419 *)p)->fA120;s.fc=0;
    s.f10=4;s.f11=1;s.f12=65535;s.f14=0;
    ((struct Obj01419 *)p)->f4=func_020255A0(((struct Obj01419 *)p)->f0,&s);
    func_02025774(((struct Obj01419 *)p)->f4,0);
    for (i=7;i<=8;i++) {
        ((void **)(p+4))[i*2+1]=func_02043678(12,2,32,76);
        s.bmp=((void **)(p+4))[i*2+1];s.x=36;s.y=20;s.f11=3;
        ((void **)(p+4))[i*2]=func_020255A0(((struct Obj01419 *)p)->f0,&s);
    }
    for (i=0;i<6;i++) {
        ((void **)(p+4))[(i+1)*2+1]=func_02043678(2,1,32,76);
        s.bmp=((void **)(p+4))[(i+1)*2+1];s.x=316;s.y=i*34+2;s.f11=1;
        ((void **)(p+4))[(i+1)*2]=func_020255A0(((struct Obj01419 *)p)->f0,&s);
    }
}
