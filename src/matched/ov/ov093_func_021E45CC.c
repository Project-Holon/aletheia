/*
 * function: func_021E45CC
 * address:  0x021E45CC
 * packet:   pkt_ov093_021E45CC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D67B0  0x021D67B0  thumb  ov093
 *   func_021C8120  0x021C8120  thumb  ov093
 *   func_021D7A9C  0x021D7A9C  thumb  ov093
 *   func_021D5814  0x021D5814  thumb  ov093
 *   func_02082D44  0x02082D44  arm
 *   func_021D78AC  0x021D78AC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021E8CF0  0x021E8CF0  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj13520.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern u8 *func_021C7CF4(u8 *s, int k);
struct QM;
extern u8 func_021D67B0(struct QM *p);
extern u8 *func_021C8120(u8 *s, int k);
extern u8 func_021D7A9C(int a, u8 *out);
extern int func_021D5814(void *p, int k);
extern void func_02082D44(u8 *src, u8 *dst, u32 n);
extern u32 func_021D78AC(u32 n);
extern u8 *func_021C88A4(u8 *p, int a, int b);
extern u16 func_021E8CF0(int c);
extern void func_021C88C8(void *a, void *b);

void func_021E45CC(int a0, u8 *s, int k)
{
    int t;
    u8 *p;
    u32 n;
    u8 *q;
    u32 i;
    int c;
    u8 *e;

    if (k == func_021D775C(3)) {
        t = func_021D67B0((struct QM *)func_021C7CF4(s, (u8)func_021D775C(6)));
        if (t != 0x11) {
            p = func_021C8120(s, 0x11);
            n = func_021D7A9C(t, p);
            if (n != 0) {
                q = func_021C7CF4(s, k);
                i = 0;
                while (i < n) {
                    if (func_021D5814(q, p[i]) != 0) {
                        if ((int)(n - 1 - i) > 0)
                            func_02082D44(p + (i + 1), p + i, n - 1 - i);
                        n--;
                    } else {
                        i++;
                    }
                }
                if (n != 0) {
                    c = p[func_021D78AC(n)];
                    e = func_021C88A4(s, 0x14, k);
                    ((struct Obj13520 *)e)->f4 = func_021E8CF0(c);
                    e[6] = k;
                    func_021C88C8(s, e);
                }
            }
        }
    }
}
