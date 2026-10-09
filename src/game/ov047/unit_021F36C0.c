/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F370C, func_021F3740, func_021F3800, func_021F381C
 * address:  0x021F36C0
 * region:   ov047
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 *   func_0216D8E0 0x0216D8E0 thumb ov010
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_021F381C  0x021F381C  thumb  ov047
 *   func_02005728  0x02005728  thumb
 *   func_0203F684  0x0203F684  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 *   _ll_mul        0x0209C054  arm
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021F3840     0x021F3840  data  ov047  a1
 *   func_02082BCC 0x02082BCC arm
 *   func_021A30C8  0x021A30C8  thumb  ov021
 *   func_021AB100  0x021AB100  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB44C  0x021AB44C  thumb  ov021
 */
#include "../../matched/include/Obj20524.h"

struct Big;
struct Ctx;
struct Obj00020;
struct Rec94;
typedef unsigned short u16;

typedef unsigned char  u8;

typedef signed int     s32_021F36C0;

typedef unsigned int   u32;

typedef signed int     s32_021F370C;

typedef short s16;

typedef int s32_021F3740;

typedef long long s64;

typedef struct Rec12 { s32_021F3740 a; s32_021F3740 b; s32_021F3740 c; } Rec12;

typedef struct Obj {
    s32_021F3740 f00;
    u8 *f04;
    Rec12 r;
} Obj;

typedef signed int     s32_021F3800;

extern void *func_02188C80(void *p);
extern u16 func_02188C84(u8 *p);
extern void *func_02188CB4(struct Obj00020 *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern int *func_021897BC(char *p, int idx);
extern void *func_021A3074(unsigned char *p);
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern s32_021F36C0 *func_0200B3A4(struct Rec94 *p, u32 b);
extern void func_0216D8E0(u8 *,void *);
extern void func_021897A0(u8 *,int);
extern int func_021F381C(int *p);
extern u32 func_02005728(u32 range);
extern short func_0203F684(unsigned short x);
extern int _fflt(int a);
extern int _fadd(int a, int b);
extern int _fsub(int a, int b);
extern int _ffix(int a);
extern void func_02082BCC(void *,int,int);
void func_021F36C0(int a);
void func_021F370C(u32 a);
void func_021F3740(int a);
void func_021F3800(u32 a);
extern u8 d_021F3840[];


void func_021F36C0(int a)
{
    void **p;

    func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80((void *)a))), 0x1f);
    func_02189764((unsigned char *)a, 1, func_02188C84((u8 *)a), 0x14);
    p = (void **)func_021897BC((char *)a, 1);
    p[0] = func_02188CB4((void *)a);
    p[1] = func_021A3074(p[0]);
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
}

void func_021F370C(u32 a) { u8 *p; func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80((void *)a))),31); p=(u8 *)func_021897BC((char *)a,1); func_0216D8E0(*(u8 * *)&((struct Obj20524 *)p)->f4,p+8); func_021897A0((u8 *)a,1); }


void func_021F3740(int a)
{
    s16 *p;
    Obj *o;
    int r;
    int v;
    s32_021F3740 x;

    p = (s16 *)func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4(func_02188C80((void *)a))), 0x1f);
    o = (Obj *)func_021897BC((char *)a, 1);
    if (func_021F381C((int *)o) == 0) {
        o->r.b = 0;
        p[0] = 0;
        func_0216D8E0(o->f04, &o->r);
        return;
    }
    if (p[0] == 0) {
        p[1] = d_021F3840[func_02005728(4)];
    }
    v = p[1];
    if (v > 0) {
        r = _fadd(0x3f000000, _fflt(v << 12));
    } else {
        r = _fsub(_fflt(v << 12), 0x3f000000);
    }
    r = _ffix(r);
    x = func_0203F684((u16)p[0]);
    o->r.b = (s32_021F3740)(((s64)x * r + 0x800) >> 12);
    func_0216D8E0(o->f04, &o->r);
    p[0] = (p[0] + 8) % 360;
}

void func_021F3800(u32 a) { func_02082BCC(func_0200B3A4((struct Rec94 *)func_02012EC4(func_020120F4((const struct Ctx *)a)),31),0,4); }

extern u32 func_021A30C8(void **ctx);
extern int func_021AB100(u32 attr);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB44C(u16 id);

int func_021F381C(int *p)
{
    int r4 = func_021A30C8((void **)(*p));
    if (func_021AB100(r4) == 0) {
        return 0;
    }
    return func_021AB44C(func_021AB0F0(r4));
}

