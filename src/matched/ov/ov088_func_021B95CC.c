/*
 * function: func_021B95CC
 * address:  0x021B95CC
 * packet:   pkt_ov088_021B95CC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204E720  0x0204E720  arm
 *   func_0204363C  0x0204363C  arm
 *   func_02040588  0x02040588  arm
 *   func_02043598  0x02043598  arm
 *   func_020434DC  0x020434DC  arm
 *   func_0201160C  0x0201160C  thumb
 *   func_021B9E7C  0x021B9E7C  thumb  ov088
 */
#include "../include/Obj00462.h"

typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern void func_0204363C(u32 swap);
extern void func_02040588(u32 which, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_020434DC(u32 mask, u32 enable);
extern u32  func_0201160C(int a);
extern void func_021B9E7C(void *a, int b);

void func_021B95CC(char *p)
{
    if (((struct Obj00462 *)p)->f8C == 0x29A) {
        func_0204E720(12, 16, 0, 3);
        func_0204363C(1);
        func_02040588(6, 0);
        func_02043598(16, 0);
        func_020434DC(8, 0);
        ((struct Obj00462 *)p)->f94 = 1;
    }
    if (((struct Obj00462 *)p)->f94 == 2 && func_0201160C(((struct Obj00462 *)p)->f4C) == 0x015F3000)
        func_021B9E7C(p + 0x40, 0x14B5);
    ((struct Obj00462 *)p)->f8C += 1;
    if (((struct Obj00462 *)p)->f8C > 0x1248) {
        ((struct Obj00462 *)p)->f4 = 1;
        ((struct Obj00462 *)p)->f0 = 5;
    }
}
