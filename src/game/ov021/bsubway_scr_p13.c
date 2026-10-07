/*
 * file:     bsubway_scr_p13.c
 * unit:     yes
 * function: func_021C9164, func_021C9190, func_021C9208, func_021C9258, func_021C928C
 * address:  0x021C9164
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02047504  0x02047504  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047738  0x02047738  arm
 *   func_0216DA30  0x0216DA30  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_02047910  0x02047910  arm
 *   func_020478B8  0x020478B8  arm
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_02047AC8  0x02047AC8  arm
 *   d_021DAC08     0x021DAC08  data  a4
 *   d_021DAB90  0x021DAB90  data  ov021  a4
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_0204784C  0x0204784C  arm
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 */
#include "../../matched/include/Obj02730.h"

struct Rec;
struct Actor;
struct VecFx32;
struct Arg;
struct AnmCtl;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 x, y, z; } V;

typedef struct { u8 pad[0x10]; u8 f10; u8 f11; u8 f12; u8 f13; u32 f14; u32 f18; u32 f1C; u32 f20; u32 f24; u8 pad28[0xc]; u32 f34; u32 f38; } E;

typedef struct V3 { int v[3]; } V3;

typedef struct T_021C9208 { int w[15]; } T_021C9208;

typedef struct { u32 a; V v; } T_021C9258;

typedef signed int     s32;

extern void func_0204762C(struct Rec *p);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern int func_0216DA30(int a0, int a1);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern void func_021AC1CC(u32, V3 *);
extern int func_02047910(void *a, int idx, int amount);
extern int func_020478B8(void *a, int idx, int amount);
extern void func_0207ADC4(int *m);
extern void func_021AC1B8(u32 a, T_021C9208 *t);
extern int func_02047AC8(void *a0, struct Arg *a1);
extern int func_021ABEA0(u32 a, u32 b);
extern void func_021ABFA8(u32 a, void *tbl, u32 c, u32 d, void *t, u32 f);
extern int func_021AC1E0(u32 a);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
void func_021C9164(void *task, E *e);
void func_021C9190(u32 a, u8 *b);
void func_021C9208(u32 a, u32 *b);
void func_021C9258(u32 a, V *v);
void func_021C928C(u32 a);
extern T_021C9208 d_021DAC08;
extern u8 d_021DAB90[];

void func_021C9164(void *task, E *e)
{
    func_0204762C((struct Rec *)e->f1C);
    func_0204762C((struct Rec *)e->f20);
    func_02047738((struct Rec *)e->f18);
    func_02047504((struct Rec *)e->f24);
    func_02047738((struct Rec *)e->f34);
    func_02047504((struct Rec *)e->f38);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C9190(u32 a, u8 *b)
{
    V3 v;

    if (func_0216DA30(((struct Obj02730 *)b)->f10, (int)b) != 0) {
        func_0216D88C((const struct Actor *)((struct Obj02730 *)b)->f10, (struct VecFx32 *)&v);
        *(V3 *)(b + 0x28) = v;
        func_021AC1CC(a, &v);
        ((struct Obj02730 *)b)->f2C -= 0x4000;
        ((struct Obj02730 *)b)->f30 += 0x2800;
        if (b[0x14] == 0) {
            func_02047910((void *)(((struct Obj02730 *)b)->f18), 0, 0x1000);
        }
        if (b[0x15] == 1 && b[0x16] == 0) {
            if (func_020478B8((void *)(((struct Obj02730 *)b)->f18), 1, 0x1000) == 0) {
                b[0x16] = 1;
            }
        }
    }
}


void func_021C9208(u32 a, u32 *b)
{
    T_021C9208 t = d_021DAC08;

    func_0207ADC4(&t.w[6]);
    func_021AC1B8(a, &t);
    func_02047AC8((void *)b[6], (struct Arg *)(&t));
    *(V3 *)&t = *(V3 *)(b + 10);
    func_02047AC8((void *)b[13], (struct Arg *)(&t));
}

void func_021C9258(u32 a, V *v)
{
    T_021C9258 t;
    t.a = func_021ABEA0(a, 0xb);
    t.v = *v;
    func_021ABFA8(a, d_021DAB90, 0, 0, &t, 0);
}

void func_021C928C(u32 a)
{
    u32 z;
    E *e;
    if (a != 0) {
        e = (E *)func_021AC1E0(a);
        if (e->f10 == 0) {
            z = 0;
            e->f10 = 1;
            func_0204784C((struct AnmCtl *)e->f14, 1, (s32 *)(&z));
        }
    }
}
