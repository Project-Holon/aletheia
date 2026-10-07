/*
 * file:     bsubway_scr_p12.c
 * unit:     yes
 * function: func_021C909C, func_021C90AC, func_021C90D0, func_021C90E4
 * address:  0x021C909C
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
 *   func_021AC1E0  0x021AC1E0  thumb  ov021
 *   func_0204784C  0x0204784C  arm
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC1CC  0x021AC1CC  thumb  ov021
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 */
#include "../../matched/include/Obj18344.h"

struct AnmCtl;
struct G3dOwner;
struct G3dRec;
struct G3dSys;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { u32 x, y, z; } V;

typedef struct { u8 pad[0x15]; u8 f15; u8 f16; u8 f17; u32 f18; } E;

typedef signed int     s32;

typedef signed short   s16;

typedef signed char    s8;

typedef struct S5 { u32 v[5]; } S5;

extern int func_021AC1E0(u32 a);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern int func_021AC1AC(u32 a);
extern void func_021AC1CC(u32, u32 *);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
void func_021C909C(u32 a);
void func_021C90AC(u32 a);
int func_021C90D0(u32 a, u32 b, u32 c, u32 d);
void func_021C90E4(u32 a, u32 *q);

void func_021C909C(u32 a)
{
    if (a != 0)
        ((u8 *)func_021AC1E0(a))[0x14] = 1;
}

void func_021C90AC(u32 a)
{
    u32 z;
    E *e;
    if (a != 0) {
        z = 0;
        e = (E *)func_021AC1E0(a);
        e->f15 = 1;
        e->f16 = 0;
        func_0204784C((struct AnmCtl *)e->f18, 1, (s32 *)(&z));
    }
}


/*
 * Emitted from the ov021 instruction shape.
 *
 * Addresses are Black-image addresses.
 */
int func_021C90D0(u32 a, u32 b, u32 c, u32 d)
{
if (a != 0) {
    return ((struct Obj18344 *)((u8 *)(func_021AC1E0(a))))->f16;
}
return 1;
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C90E4(u32 a, u32 *q)
{
    *(S5 *)q = *((S5 *)func_021AC1AC(a));
    func_021AC1CC(a, q + 1);
    q[9] = (u32)func_02047400((void *)(((u32 *)q[0])[2]), 0, (void *)(((u32 *)q[0])[2]));
    q[7] = (u32)func_02047564((struct G3dOwner *)q[9], (const struct G3dOwner *)(((u32 *)q[0])[6]), 0);
    q[8] = (u32)func_02047564((struct G3dOwner *)q[9], (const struct G3dOwner *)(((u32 *)q[0])[7]), 0);
    q[6] = (u32)func_0204767C(q[9], q + 7, 2);
    func_020477A4((struct G3dSys *)q[6], 0);
    func_020477A4((struct G3dSys *)q[6], 1);
    q[14] = (u32)func_02047400((void *)(((u32 *)q[0])[4]), 0, (void *)(((u32 *)q[0])[4]));
    q[13] = (u32)func_0204767C(q[14], 0, 0);
}
