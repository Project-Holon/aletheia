/*
 * function: func_021E20E0
 * address:  0x021E20E0
 * packet:   pkt_ov093_021E20E0
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
 *   func_021D5B68  0x021D5B68  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
#include "../include/Obj05220.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5B68(void *p);
extern void *func_021C88A4(int a, int k, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *a, void *b);

void func_021E20E0(int u, int a, int b)
{
    u8 *r;

    if (b == func_021D775C(4) && func_021D775C(0x46) == 0 && func_021D5B68(func_021C7CF4((int *)a, b)) == 0) {
        r = func_021C88A4(a, 0xe, b);
        ((struct Obj05220 *)r)->f4 = 1;
        r[0xc] = 1;
        r[0xe] = 0;
        r[0xf] = 1;
        r[0x10] = b;
        r[0xd] = 1;
        func_021C8838(r + 0x18, 2, 0x214);
        func_021C8860((struct S *)(r + 0x18), b);
        func_021C88C8((void *)a, r);
    }
}
