/*
 * function: func_021E2C88
 * address:  0x021E2C88
 * packet:   pkt_ov093_021E2C88
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5B48  0x021D5B48  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021D7B74  0x021D7B74  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj13512.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5B48(u8 *p);
extern u8 *func_021C88A4(void *a, int k, int b);
extern int func_021D7B74(u8 *p, u32 k);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *a, void *b);

void func_021E2C88(int u, void *p, int k, int *out)
{
    u8 b;
    u8 *m;
    void *q;
    if (k == func_021D775C(3) && *out != 0) {
        b = func_021D775C(4);
        q = func_021C7CF4(p, b);
        if (func_021D5B48(q) == 0) {
            m = func_021C88A4(p, 5, k);
            m[6] = b;
            ((struct Obj13512 *)m)->f4 = func_021D7B74(q, 4);
            func_021C8838(m + 8, 2, 0x183);
            func_021C8860((struct S *)(m + 8), b);
            func_021C88C8(p, m);
        } else {
            m = func_021C88A4(p, 4, k);
            func_021C8838(m + 4, 2, 0xd2);
            func_021C8860((struct S *)(m + 4), b);
            func_021C88C8(p, m);
        }
    }
}
