/*
 * function: func_021E7420
 * address:  0x021E7420
 * packet:   pkt_ov093_021E7420
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The narrowed scan key is a `u8` local assigned from the call, then passed:
 * the inline cast `(u8)func_021D775C(i + 6)` adds an `adds r1, r0` copy the
 * image does not have.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021E74C8  0x021E74C8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj07836.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int func_021E74C8(u16 k);
extern u8 *func_021C88A4(int a, int k, int c);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);

void func_021E7420(int a, int b, int c)
{
    u16 k;
    u32 i;
    u32 n;
    u8 *p;
    u8 t;

    if (c == func_021D775C(3)) {
        k = func_021D59B4(func_021C7CF4((int *)b, c), 0x10);
        if (func_021E74C8(k) == 0) {
            n = func_021D775C(5);
            for (i = 0; i < n; i++) {
                t = func_021D775C(i + 6);
                if (func_021D59B4(func_021C7CF4((int *)b, t), 0x10) != 0x36) {
                    p = func_021C88A4(b, 0x1f, c);
                    ((struct Obj07836 *)p)->f6 = func_021D775C(i + 6);
                    ((struct Obj07836 *)p)->f4 = k;
                    func_021C8838(p + 0xc, 2, 0x195);
                    func_021C8860((struct S *)(p + 0xc), ((struct Obj07836 *)p)->f6);
                    func_021C8860((struct S *)(p + 0xc), ((struct Obj07836 *)p)->f4);
                    func_021C88C8((void *)b, p);
                }
            }
        }
    }
}
