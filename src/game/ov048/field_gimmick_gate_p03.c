/*
 * file:     field_gimmick_gate_p03.c
 * unit:     yes
 * function: func_021F3870, func_021F3880, func_021F38EC, func_021F3908
 * address:  0x021F3870
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F47BC 0x021F47BC thumb ov048
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE4C4  0x021BE4C4  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_021F4698  0x021F4698  thumb  ov048
 *   func_021F39A8 0x021F39A8 thumb ov048
 *   func_021F3C14 0x021F3C14 thumb ov048
 *   func_021897A0 0x021897A0 thumb ov021
 *   func_02012EC0 0x02012EC0 thumb
 *   func_0200C0E8 0x0200C0E8 thumb
 *   func_0200C3B0 0x0200C3B0 thumb
 */
#include "../../matched/include/Obj00377.h"

struct M;
struct Ctx;
struct Big;
struct Blk34;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Obj {
    u16 f00;
    int f04;
    int f08;
    int f0C;
    int f10;
    int f14;
} Obj;

typedef struct Cfg {
    u16 a;
    u8 b;
    u8 c;
    u8 d;
    int w;
} Cfg;

extern void func_021F47BC(struct M *p, int v);
extern void *func_02188C80(void *p);
extern u16 func_02188C84(u8 *p);
extern int func_02188D2C(int *p);
extern void *func_02189764(unsigned char *p, int id, int a, int b);
extern void *func_021BE4C4(int a, int b, int c);
extern void *func_020120F4(const struct Ctx *p);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_021F4698(unsigned char *p);
extern void func_021F39A8(void **p);
extern void func_021F3C14(char *p);
extern void func_021897A0(unsigned char *p, int id);
extern void *func_02012EC0(struct Big *p);
extern void *func_0200C0E8(void *p);
extern u16 func_0200C3B0(struct Blk34 *p);
void func_021F3870(int *p);
Obj *func_021F3880(int a);
void func_021F38EC(int *p);
void func_021F3908(int *p);

void func_021F3870(int *p) { func_021F47BC((void *)p[5], p[6] << 12); }


Obj *func_021F3880(int a)
{
    u16 r5;
    int r7;
    Obj *o;
    int v;
    Cfg c;

    r5 = func_02188C84((u8 *)a);
    r7 = func_02188D2C((int *)a);
    o = func_02189764((unsigned char *)a, 0, r5, 0x68);
    func_02082BCC(o, 0, 0x68);
    o->f00 = r5;
    o->f04 = a;
    v = (int)func_02188C80((void *)a);
    o->f0C = v;
    o->f08 = (int)func_020120F4((const struct Ctx *)v);
    o->f10 = 0;
    c.a = r5;
    c.b = 7;
    c.c = 8;
    c.d = 3;
    c.w = (int)func_021BE4C4(r7, 1, 0);
    o->f14 = (int)func_021F4698((unsigned char *)(&c));
    return o;
}

void func_021F38EC(int *p) { if(p) {func_021F39A8((void **)p);func_021F3C14((char *)p);func_021897A0((unsigned char *)p[1],0);} }

void func_021F3908(int *p) { if(p[4]==0) { ((struct Obj00377 *)p)->f64=func_0200C3B0(func_0200C0E8(func_02012EC0((void *)p[2]))); p[4]=1; } }
