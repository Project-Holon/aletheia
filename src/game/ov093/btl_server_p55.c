/*
 * file:     btl_server_p55.c
 * unit:     yes
 * function: func_021C3FDC, func_021C4034
 * address:  0x021C3FDC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021BD2B4  0x021BD2B4  thumb  ov093
 *   func_021BD34C  0x021BD34C  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021C195C  0x021C195C  thumb  ov093
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021C40F4  0x021C40F4  thumb  ov093
 *   func_021C5B74  0x021C5B74  thumb  ov093
 *   func_021D6D5C  0x021D6D5C  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 *   func_021C5DAC  0x021C5DAC  thumb  ov093
 *   func_021C5D88  0x021C5D88  thumb  ov093
 */
#include "../../matched/include/Obj00003.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

extern u8 func_021D5440(u8 *p);
extern void func_021BD2B4(u8 *it, u8 **q);
extern int func_021BD34C(u8 *it, u8 **q, u8 **x);
extern int func_021B9A24(unsigned int a, unsigned int b);
extern void func_021C195C(u8 *p, u8 *q, u32 n);
extern u32 func_021D6D7C(u8 *p);
extern int func_021D7B74(u8 *p, u32 k);
extern int func_021D59B4(u8 *p, int k);
extern int func_021C40F4(u8 *p, int i);
extern void func_021C5B74(u8 *p, u8 *a, int c, int k);
extern void func_021D6D5C(u8 *a, u16 v);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
extern void func_021CD64C(void *w, u8 id, ...);
extern void func_021C5DAC(u8 *p, u32 a, int n, const int *v);
extern void func_021C5D88(u8 *p, u8 *a, int b);
void func_021C3FDC(u8 *p, u8 *a);
int func_021C4034(u8 *p, u8 *a);


void func_021C3FDC(u8 *p, u8 *a)
{
    u32 it;
    u8 *cur;
    int k = func_021D5440(a);
    func_021BD2B4((u8 *)&it, (u8 **)p);
    while (func_021BD34C((u8 *)&it, (u8 **)p, &cur)) {
        if (func_021B9A24(k, func_021D5440(cur)) == 0)
            func_021C195C(p, cur, 0);
    }
}


int func_021C4034(u8 *p, u8 *a)
{
    int n;
    int r;
    if (func_021D6D7C(a) == 0) {
        n = func_021D7B74(a, 4);
        if (func_021D59B4(a, 0xd) > n) {
            r = func_021C40F4(p + 0x1ab8, func_021D5440(a));
            if (r != 6) {
                func_021C5B74(p, a, -n, 1);
                func_021C195C(p, a, 1);
                func_021D6D5C(a, n);
                func_021CD4B0(((struct Obj00003 *)p)->fC, 0x27, func_021D5440(a), (u16)n);
                func_021CD4B0(((struct Obj00003 *)p)->fC, 0x51, r);
                func_021CD64C(((struct Obj00003 *)p)->fC, 0x5b, 0x311, func_021D5440(a), 0xffff0000);
                return 1;
            }
        }
        func_021C5DAC(p, 0x7b, 0, 0);
    } else {
        func_021C5D88(p, a, 0x314);
    }
    return 0;
}
