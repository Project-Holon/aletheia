/*
 * file:     beacon_view_p10.c
 * unit:     yes
 * function: func_021F1484, func_021F150C, func_021F155C, func_021F1704
 * address:  0x021F1484
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F1218 0x021F1218 thumb
 *   func_021F0EA4 0x021F0EA4 thumb
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0207C768 0x0207C768 arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   func_021F0EDC 0x021F0EDC thumb
 *   func_02031194 0x02031194 arm
 */
#include "../../matched/include/Obj00225.h"
#include "../../matched/include/Obj00710.h"

#define FX32_CONST(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))
struct S02030FB4;
struct TcblNode;
typedef unsigned char u8;

typedef signed short s16;

typedef unsigned int u32;

extern void func_021F1218(char *p, short x, short y);
extern void func_021F0EA4(char *p, unsigned a);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern void *func_02031290(struct S02030FB4 *p);
extern void func_02082BCC(void *p, int v, int n);
extern u32 func_0207C768(u32 a, u32 b);
extern void func_021F0EDC(char *p);
extern void func_02031194(struct TcblNode *n);
void func_021F1484(char *this, int a, u8 *b, u8 *c, void *s);
void func_021F150C(u8 *this, u8 *p, void *s);
void func_021F155C(char *p, u8 *e, int mode, u8 delay, int *r);
void func_021F1704(void *h, char *t);


void func_021F1484(char *this, int a, u8 *b, u8 *c, void *s)
{
    int i;
    u8 *e;

    if (b != 0) {
        if (a == 0)
            b[2] = 5;
        else
            b[2] = 0;
        func_021F1218((char *)b, -13 * (1 - b[2]), -40 * (1 - b[2]));
        func_021F0EA4((char *)b, 1);
    }
    for (i = 0; i < 5; i++) {
        e = (u8 *)(this + 0x1b8) + i * 0x34;
        if (e[1] != 0xff) {
            if (c == 0 || e[0] != c[0])
                func_021F155C(this, e, a, 0, s);
        }
    }
}


void func_021F150C(u8 *this, u8 *p, void *s)
{
    int k;

    p[2] = 1;
    func_021F1218((char *)p, -208, 0);
    func_021F0EA4((char *)p, 1);
    k = 0;
    if (this[0x7b] != 0)
        k = 8;
    func_021F155C((char *)this, p, 2, (u8)k, s);
    func_021F1484((char *)this, 1, 0, p, s);
}


void func_021F155C(char *p, u8 *e, int mode, u8 delay, int *r)
{
    u8 *t;

    t = func_02031290(func_020311B8(*(u32 *)(p + 0xa0), (void *)func_021F1704, 0x28, 0));
    func_02082BCC(t, 0, 0x28);
    t[0xc] = mode;
    if (t[0xc] == 0) {
        e[2] = e[2] - 1;
    } else if (t[0xc] == 1) {
        e[2] = e[2] + 1;
    }
    *(char **)(t + 4) = p;
    *(u8 **)(t + 8) = e;
    *(s16 *)(t + 0x10) = (1 - e[2]) * -13;
    *(s16 *)(t + 0x12) = (1 - e[2]) * -40;
    *(int *)(t + 0x14) = FX32_CONST(*(s16 *)(e + 8));
    *(int *)(t + 0x18) = FX32_CONST(*(s16 *)(e + 0xa));
    t[0xe] = 8;
    t[0xd] = delay;
    *(int *)(t + 0x1c) = func_0207C768(FX32_CONST(*(s16 *)(t + 0x10) - *(s16 *)(e + 8)), FX32_CONST(t[0xe]));
    *(int *)(t + 0x20) = func_0207C768(FX32_CONST(*(s16 *)(t + 0x12) - *(s16 *)(e + 0xa)), FX32_CONST(t[0xe]));
    *(int **)(t + 0x24) = r;
    (*r)++;
}


void func_021F1704(void *h, char *t)
{
    u8 *e;

    switch (((struct Obj00710 *)t)->f0) {
    case 0:
        if (((struct Obj00710 *)t)->fD != 0) {
            ((struct Obj00710 *)t)->fD = ((struct Obj00710 *)t)->fD - 1;
            return;
        }
        ((struct Obj00710 *)t)->fF = ((struct Obj00710 *)t)->fF + 1;
        if (((struct Obj00710 *)t)->fF < ((struct Obj00710 *)t)->fE) {
            int x = ((struct Obj00710 *)t)->f14 + ((struct Obj00710 *)t)->f1C;
            int y = ((struct Obj00710 *)t)->f18 + ((struct Obj00710 *)t)->f20;
            ((struct Obj00710 *)t)->f14 = x;
            ((struct Obj00710 *)t)->f18 = y;
            func_021F1218((char *)(*(u8 * *)&((struct Obj00710 *)t)->f8), (short)(x >> 12), (short)(y >> 12));
            return;
        }
        func_021F1218((char *)(*(u8 * *)&((struct Obj00710 *)t)->f8), ((struct Obj00710 *)t)->f10, ((struct Obj00710 *)t)->f12);
        e = *(u8 * *)&((struct Obj00710 *)t)->f8;
        if (e[2] == 0 || e[2] == 5) {
            ((struct Obj00710 *)t)->f0 = ((struct Obj00710 *)t)->f0 + 1;
            return;
        }
        break;
    case 1:
    default:
        e = *(u8 * *)&((struct Obj00710 *)t)->f8;
        if (((struct Obj00225 *)e)->f2C != 0)
            return;
        func_021F0EDC((char *)e);
        break;
    }
    **(int * *)&((struct Obj00710 *)t)->f24 = **(int * *)&((struct Obj00710 *)t)->f24 - 1;
    func_02031194(h);
}
