/*
 * file:     unit_021BD8D8_p04.c
 * unit:     yes
 * function: func_021BE2DC, func_021BE384, func_021BE3CC, func_021BE448
 * address:  0x021BE2DC
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
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049E74 0x02049E74 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_020307B0  0x020307B0  arm
 *   func_0203FB44  0x0203FB44  arm
 *   func_021BE4EC  0x021BE4EC  thumb  ov099
 *   func_02042FB0  0x02042FB0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_021BDD60 0x021BDD60 thumb ov099
 */
#include "../../matched/include/Obj05265.h"

typedef unsigned short u16;

typedef unsigned int u32_021BE2DC;

typedef unsigned char  u8;

typedef unsigned long  u32_021BE384;

typedef signed char    s8;

typedef signed short   s16;

typedef signed long    s32;

typedef int BOOL;

typedef struct {
    void *f00;
    char pad[4];
    void *f08;
    char pad2[4];
    u32_021BE384 f10;
    u32_021BE384 f14;
} S;

typedef unsigned int u32_021BE3CC;

extern void func_02049B68(void *a, u32_021BE2DC b, u32_021BE2DC c, u32_021BE2DC d, u32_021BE2DC e, u16 f);
extern u32_021BE2DC func_02049740(void *a0, u32_021BE2DC a1, u32_021BE2DC a2, u32_021BE2DC a3, u32_021BE2DC a4, u16 flags);
extern void *func_02049E74(void *a0, u32_021BE2DC a1, u32_021BE2DC a2, u32_021BE2DC a3, u16 a4);
extern void *func_02049EF4(void *, u32_021BE2DC, u32_021BE2DC, void **, u16);
extern u32_021BE384 func_020307B0(void *p);
extern void func_0203FB44(u32_021BE384 layer, u32_021BE384 offset, u32_021BE384 size);
extern int func_021BE4EC(int a);
extern void func_02042FB0(u32_021BE3CC idx, u32_021BE3CC x, u32_021BE3CC y, u16 value);
extern void func_02041B6C(u32_021BE3CC bit);
extern int func_021BDD60(int x);
void func_021BE2DC(char *p, int a, int b);
void func_021BE384(S *s);
void func_021BE3CC(char *p, int a, u8 b, u8 c, u32_021BE3CC d, int e);
int func_021BE448(unsigned int a, int b);

void func_021BE2DC(char *p, int a, int b)
{
    func_02049B68((void *)a, 4, 0, 0x100, 0x80, b);
    func_02049B68((void *)a, 4, 4, 0x100, 0x80, b);
    ((struct Obj05265 *)p)->f10 = func_02049740((void *)a, 13, 1, 0, 0, b);
    ((struct Obj05265 *)p)->f14 = func_02049740((void *)a, 13, 6, 0, 0, b);
    if (((struct Obj05265 *)p)->f8 == 0) {
        ((struct Obj05265 *)p)->f8 = func_02049E74((void *)a, 13, 0, (u32_021BE2DC)(p + 12), b);
    }
    if (((struct Obj05265 *)p)->f0 == 0) {
        ((struct Obj05265 *)p)->f0 = func_02049EF4((void *)a, 21, 0, (void **)(p + 4), b);
    }
}


void func_021BE384(S *s)
{
    if (s->f00 != 0) {
        func_020307B0(s->f00);
        s->f00 = 0;
    }

    if (s->f08 != 0) {
        func_020307B0(s->f08);
        s->f08 = 0;
    }

    func_0203FB44(1, (u16)s->f10, (u16)(s->f10 >> 16));
    func_0203FB44(6, (u16)s->f14, (u16)(s->f14 >> 16));
}


void func_021BE3CC(char *p, int a, u8 b, u8 c, u32_021BE3CC d, int e)
{
    int row;
    u32_021BE3CC stride;
    u16 *base;
    int i, j;
    int t;

    base = (u16 *)(*(char **)(p + 4) + 0xC);
    t = func_021BE4EC(a);
    row = (d >> 4) * 2;
    stride = (u32_021BE3CC)**(u16 **)(p + 4) >> 3;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            func_02042FB0(a, j + b, i + c, (t << 12) + (base + (d & 0xF) * 2)[(row + i) * stride + j]);
        }
    }
    func_02041B6C((u8)a);
}

int func_021BE448(unsigned int a, int b)
{
    int r = 15;
    switch (a) {
    case 4:
        if (b == 2) r = 4;
        else r = 3;
        break;
    case 5:
        if (b == 2) r = 6;
        else r = 5;
        break;
    case 6:
        if (b == 2) r = 10;
        else r = 9;
        break;
    case 2: r = 2; break;
    case 0: r = 15; break;
    case 3: r = 1; break;
    default:
        if (func_021BDD60(a) != 0) {
            if (b == 2) r = 8;
            else r = 7;
        } else if (a >= 15) {
            r = 14;
        }
        break;
    }
    return r;
}
