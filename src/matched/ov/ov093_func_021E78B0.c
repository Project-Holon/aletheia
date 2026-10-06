/*
 * unit:     yes
 * function: func_021E78B0, func_021E7918
 * address:  0x021E78B0
 * packet:   pkt_ov093_021E78B0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * d_021F26D4: the ov093 hint is contested at this address; the plain
 * `data a4` line resolves it as sole-ref/data.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D67E8  0x021D67E8  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   d_021F26D4     0x021F26D4  data   a4
 */
#include "../include/Obj13544.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D67E8(u8 *p);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
struct S;
extern void func_021C8860(struct S *p, u32 v);
extern void func_021C88C8(void *a, void *b);
extern int d_021F26D4[];

void func_021E78B0(int a, int b, int c)
{
    u32 n, v;
    u8 *p;

    if (c == func_021D775C(3)) {
        n = func_021D67E8(func_021C7CF4((int *)b, c));
        if (n > 1) {
            p = func_021C88A4((char *)b, 0x2d, c);
            v = (n > 0x3e9) ? n - 0x3e8 : 1;
            p[4] = c;
            ((struct Obj13544 *)p)->f6 = v;
            func_021C8838(p + 8, 2, 0x44e);
            func_021C8860((struct S *)(p + 8), c);
            func_021C88C8((void *)b, p);
        }
    }
}

int *func_021E7918(int *p)
{
    *p = 1;
    return d_021F26D4;
}
