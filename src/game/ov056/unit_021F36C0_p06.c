/*
 * file:     unit_021F36C0_p06.c
 * unit:     yes
 * function: func_021F3C4C, func_021F3C84, func_021F3CC4
 * address:  0x021F3C4C
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02047738  0x02047738  arm
 *   func_0204762C  0x0204762C  arm
 *   func_02047504  0x02047504  arm
 *   func_020470D0  0x020470D0  arm
 *   func_02046EFC  0x02046EFC  arm
 *   func_021F36D4  0x021F36D4  thumb  ov056
 *   func_0204784C  0x0204784C  arm
 *   func_0216DAC8  0x0216DAC8  thumb  ov010
 *   func_0216E084  0x0216E084  thumb  ov010
 *   func_02164010  0x02164010  thumb  ov010
 *   func_0216D88C  0x0216D88C  thumb  ov010
 *   func_021A3044  0x021A3044  thumb  ov021
 *   func_0216DC18  0x0216DC18  thumb  ov010
 */
#include "../../matched/include/Obj03652.h"
#include "../../matched/include/Obj01881.h"

struct Rec;
struct Tagged;
struct AnmCtl;
struct Actor;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

typedef signed int     s32;

typedef signed short   s16;

typedef struct VecFx32 { s32 x; s32 y; s32 z; } VecFx32;

extern void func_02047738(struct Rec *p);
extern void func_0204762C(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern int func_020470D0(u32 *p);
extern void func_02046EFC(struct Tagged *p);
extern int func_021F36D4(u32 a);
extern u32 func_0204784C(struct AnmCtl *c, u16 idx, s32 *frame);
extern void func_0216DAC8(unsigned int *p, unsigned int v);
extern void func_0216E084(void *a, unsigned int x, unsigned int y, unsigned int z, u16 k);
extern int func_02164010(int a);
extern void func_0216D88C(const struct Actor *a, struct VecFx32 *out);
extern void func_021A3044(u8 *p, void *v);
extern int func_0216DC18(void *a0, int a1);
void func_021F3C4C(u8 *p);
int func_021F3C84(u32 *p);
void func_021F3CC4(u8 *p, int flag);


void func_021F3C4C(u8 *p)
{
    func_02047738((struct Rec *)(((struct Obj03652 *)p)->f1C));
    func_0204762C((struct Rec *)(((struct Obj03652 *)p)->f14));
    func_0204762C((struct Rec *)(((struct Obj03652 *)p)->f18));
    func_02047504((struct Rec *)(((struct Obj03652 *)p)->f10));
    func_020470D0((u32 *)(((struct Obj03652 *)p)->f0));
    func_02046EFC((struct Tagged *)(((struct Obj03652 *)p)->f0));
    func_02046EFC((struct Tagged *)(((struct Obj03652 *)p)->f4));
    func_02046EFC((struct Tagged *)(((struct Obj03652 *)p)->f8));
}


int func_021F3C84(u32 *p)
{
    int r;
    int lim;
    int ret;

    r = func_021F36D4(p[5]);
    lim = p[31] + 0x1000;
    if (r <= lim) {
        ret = 1;
        p[31] = r - 0x1000;
    } else {
        ret = 0;
        p[31] = lim;
    }
    func_0204784C((struct AnmCtl *)p[7], 0, (int *)&p[31]);
    func_0204784C((struct AnmCtl *)p[7], 1, (int *)&p[31]);
    return ret;
}


void func_021F3CC4(u8 *p, int flag)
{
    VecFx32 v;

    if (flag) {
        ((struct Obj01881 *)p)->f5C = 1;
        func_0216DAC8(((struct Obj01881 *)p)->f68, 1);
        return;
    }
    ((struct Obj01881 *)p)->f5C = 0;
    func_0216DAC8(((struct Obj01881 *)p)->f68, 0);
    func_0216E084(((struct Obj01881 *)p)->f68, (s16)(((struct Obj01881 *)p)->f6C), (s16)(((struct Obj01881 *)p)->f70),
                  (s16)(((struct Obj01881 *)p)->f74), ((struct Obj01881 *)p)->f78);
    func_02164010((int)(((struct Obj01881 *)p)->f68));
    func_0216D88C(((struct Obj01881 *)p)->f68, &v);
    func_021A3044(((struct Obj01881 *)p)->f64, &v);
    func_0216DC18(((struct Obj01881 *)p)->f68, 0);
}
