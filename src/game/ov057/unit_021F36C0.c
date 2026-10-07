/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F37BC, func_021F381C
 * address:  0x021F36C0
 * region:   ov057
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_020490F4  0x020490F4  arm
 *   func_02046E24  0x02046E24  arm
 *   func_02046F50  0x02046F50  arm
 *   func_02046FF8  0x02046FF8  arm
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_02046BE0  0x02046BE0  arm
 *   func_02049238  0x02049238  arm
 *   d_021F38A8     0x021F38A8  data  a4
 *   d_021F387C     0x021F387C  data  a4
 *   d_021F3888     0x021F3888  data  a4
 *   d_021F3898     0x021F3898  data  a4
 *   func_02047738  0x02047738  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047504  0x02047504  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_02047910  0x02047910  arm
 */
#include "../../matched/include/Obj07671.h"

struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Tagged;
struct Rec;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct Res {
    u32 res[7];
    u32 tex[3];
    u32 anm[4];
    u32 obj[3];
} Res;

typedef unsigned char  u8;

extern u16 func_02188C84(u8 *p);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02046E24(u32 a0, u32 a1);
extern u32 func_02046F50(struct Tagged *p, u32 sel);
extern int func_02046FF8(int *self);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void func_02046BE0(u32 a, u32 b);
extern void func_02049238(void *);
extern void func_02047738(struct Rec *p);
extern void func_0204762C(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);
extern int func_02047910(void *a, int idx, int amount);
void func_021F36C0(int a, int b, Res *p);
void func_021F37BC(int a, int b, char *p);
void func_021F381C(void *a, void *b, u8 *p);
extern const u32 d_021F38A8[];
extern const u32 d_021F387C[];
extern const u32 d_021F3888[];
extern const u32 d_021F3898[];


void func_021F36C0(int a, int b, Res *p)
{
    void *h;
    int i;
    u32 t;

    h = func_020490F4(0xbe, (u16)((func_02188C84((u8 *)b) & 0x7fff) | 0x8000));
    for (i = 0; i < 7; i++) {
        if (func_02046F50((struct Tagged *)(p->res[i] = (u32)func_02046E24((u32)h, d_021F38A8[i])), 2)) {
            func_02046FF8((int *)p->res[i]);
        }
    }
    for (i = 0; i < 3; i++) {
        t = d_021F387C[i];
        if (func_02046F50((struct Tagged *)p->res[t], 2)) {
            p->tex[i] = (u32)func_02047400((void *)p->res[t], 0, (void *)p->res[t]);
        } else {
            p->tex[i] = (u32)func_02047400((void *)p->res[t], 0, 0);
        }
    }
    for (i = 0; i < 4; i++) {
        p->anm[i] = (u32)func_02047564((struct G3dOwner *)p->tex[d_021F3888[i]], (const struct G3dOwner *)p->res[d_021F3898[i]], 0);
    }
    for (i = 0; i < 3; i++) {
        p->obj[i] = (u32)func_0204767C(p->tex[i], p->anm, 4);
    }
    func_020477A4((struct G3dSys *)p->obj[0], 0);
    func_020477A4((struct G3dSys *)p->obj[0], 3);
    func_020477A4((struct G3dSys *)p->obj[1], 1);
    func_020477A4((struct G3dSys *)p->obj[2], 2);
    func_02046BE0(1, 1);
    func_02049238(h);
}


void func_021F37BC(int a, int b, char *p)
{
    int i;
    for (i = 0; i < 3; i++)
        func_02047738((struct Rec *)(*(int *)(p + i * 4 + 0x38)));
    for (i = 0; i < 4; i++)
        func_0204762C((struct Rec *)(*(int *)(p + i * 4 + 0x28)));
    for (i = 0; i < 3; i++)
        func_02047504((struct Rec *)(*(int *)(p + i * 4 + 0x1c)));
    for (i = 0; i < 7; i++) {
        if (func_02046F50((struct Tagged *)(*(int *)(p + i * 4)), 2))
            func_020470D0((u32 *)(*(int *)(p + i * 4)));
        func_02046EFC((struct Tagged *)(*(int *)(p + i * 4)));
    }
}


void func_021F381C(void *a, void *b, u8 *p)
{
    u32 m = 1 << 12;

    func_02047910((void *)(((struct Obj07671 *)p)->f38), 0, m);
    func_02047910((void *)(((struct Obj07671 *)p)->f38), 3, m);
    func_02047910((void *)(((struct Obj07671 *)p)->f3C), 1, m);
    func_02047910((void *)(((struct Obj07671 *)p)->f40), 2, m);
    func_02046BE0(1, 1);
}
