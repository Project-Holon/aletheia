/*
 * file:     union_oneself_p14.c
 * unit:     yes
 * function: func_0217FA10, func_0217FA54, func_0217FA78, func_0217FA9C
 * address:  0x0217FA10
 * region:   ov019
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
 *   func_02047400  0x02047400  arm
 *   func_02047564  0x02047564  arm
 *   func_0204767C  0x0204767C  arm
 *   func_020477A4  0x020477A4  arm
 *   func_0204762C 0x0204762C arm
 *   func_02047738 0x02047738 arm
 *   func_02047504 0x02047504 arm
 *   func_02047910 0x02047910 arm
 *   func_0216D88C 0x0216D88C thumb ov010
 *   func_02047AC8 0x02047AC8 arm
 */
#include "../../matched/include/Obj02366.h"
#include "../../matched/include/Obj09421.h"
#include "../../matched/include/Obj03097.h"

struct G3dOwner;
struct G3dRec;
struct G3dSys;
struct Rec;
struct Actor;
struct Arg;
struct VecFx32;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct { int x,y,z; } VecFx32;

extern void func_02082BCC(void *p, u32 v, u32 n);
extern void *func_02047400(void *a0, u32 n, void *a2);
extern struct G3dRec *func_02047564(struct G3dOwner *a0, const struct G3dOwner *a1, int a2);
extern void *func_0204767C(u32 a0, u32 *a1, int a2);
extern u32 func_020477A4(struct G3dSys *sys, u32 idx);
extern void func_0204762C(struct Rec *p);
extern void func_02047738(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern int func_02047910(void *p, int idx, int amount);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern int func_02047AC8(void *a, struct Arg *b);
void func_0217FA10(char *self, u32 *out, u32 a2, u16 a3);
void func_0217FA54(u32 *p);
void func_0217FA78(u32 *p);
void func_0217FA9C(u32 *p, u32 *b);


/*
 * Addresses are Black-image addresses.
 */
void func_0217FA10(char *self, u32 *out, u32 a2, u16 a3)
{
    func_02082BCC(out, 0, 0x14);
    out[0] = a2;
    ((struct Obj02366 *)out)->f10 = a3;
    out[1] = (u32)func_02047400((void *)(((struct Obj09421 *)self)->f14), 0, (void *)(((struct Obj09421 *)self)->f14));
    out[2] = (u32)func_02047564((struct G3dOwner *)out[1], (const struct G3dOwner *)(((struct Obj09421 *)self)->f18), 0);
    out[3] = (u32)func_0204767C(out[1], &out[2], 1);
    func_020477A4((struct G3dSys *)out[3], 0);
}

void func_0217FA54(u32 *p) { func_0204762C((struct Rec *)p[2]); func_02047738((struct Rec *)p[3]); func_02047504((struct Rec *)p[1]); func_02082BCC(p,0,0x14); }

void func_0217FA78(u32 *p)
{
    func_02047910((void *)p[3], 0, 0x1000);
    (((struct Obj03097 *)p)->f12)++;
    if (((struct Obj03097 *)p)->f12 > 90) func_0217FA54(p);
}

void func_0217FA9C(u32 *p, u32 *b) { func_0216D88C((const struct Actor *)p[0], (struct VecFx32 *)b); b[1] -= 0x6000; func_02047AC8((void *)p[3], (struct Arg *)b); }
