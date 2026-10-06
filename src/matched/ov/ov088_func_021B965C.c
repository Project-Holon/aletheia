/*
 * function: func_021B965C
 * address:  0x021B965C
 * packet:   pkt_ov088_021B965C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020362DC  0x020362DC  arm
 *   func_0203630C  0x0203630C  arm
 *   func_0204E720  0x0204E720  arm
 *   func_0204363C  0x0204363C  arm
 *   func_02040588  0x02040588  arm
 *   func_02043598  0x02043598  arm
 *   func_02006984  0x02006984  thumb
 *   func_02005E30  0x02005E30  thumb
 *   func_021B9E7C  0x021B9E7C  thumb  ov088
 *   func_021B9A14  0x021B9A14  thumb  ov088
 */
#include "../include/Obj00462.h"

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32   func_020362DC(void);
extern unsigned int func_0203630C(void);
typedef signed int     s32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern void func_0204363C(u32 swap);
extern void func_02040588(u32 which, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern u32 func_02006984(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern void func_02005E30(u32 a);
extern void func_021B9E7C(int *p, int x);
extern void  func_021B9A14(u16 *p, u16 a, u16 b);

void func_021B965C(char *p)
{
    if ((func_020362DC() & 0xB) && ((struct Obj00462 *)p)->f94 == 1) {
        func_0204363C(0);
        func_02040588(6, 1);
        func_02040588(3, 1);
        func_02043598(0x10, 1);
        func_021B9E7C((int *)(p + 0x40), 0x14B5);
        ((struct Obj00462 *)p)->f94 = 2;
        return;
    }
    if (func_020362DC() & 9) {
        ((struct Obj00462 *)p)->f4 = 0;
        ((struct Obj00462 *)p)->f0 = 4;
        ((struct Obj00462 *)p)->f90 = (void *)func_02006984(0x283, 0, 0x40, 0, 0, 0, 0, 0);
        func_021B9E7C((int *)(p + 0x40), 0x1389);
        func_0204363C(0);
        func_02040588(6, 1);
        func_02043598(0x10, 0);
        func_0204E720(0xC, 0x10, 0, 3);
        func_02005E30(4);
        func_021B9A14((u16 *)(p + 8), 8, 8);
        return;
    }
    if (func_0203630C() == 0x46) {
        ((struct Obj00462 *)p)->f4 = 2;
        ((struct Obj00462 *)p)->f0 = 5;
    } else if (func_0203630C() == 0xC80) {
        ((struct Obj00462 *)p)->f4 = 3;
        ((struct Obj00462 *)p)->f0 = 5;
    }
}
