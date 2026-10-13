/*
 * function: func_021E4958
 * address:  0x021E4958
 * packet:   pkt_ov093_021E4958
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7FCC  0x021C7FCC  thumb  ov093
 *   func_021C7FE0  0x021C7FE0  thumb  ov093
 *   func_021C8120  0x021C8120  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021E4A08  0x021E4A08  thumb  ov093
 */
#include "../include/Obj10091.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern u8 *func_021C7FCC(u8 *s, int k);
extern char *func_021C7FE0(u8 *p, int v);
extern u8 *func_021C8120(u8 *s, int k);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern u8 func_021E4A08(u8 *x, u8 idx, u8 lim, u8 *buf);

void func_021E4958(int a0, u8 *s, int k, int a3, u16 x)
{
    u8 *a;
    int b;
    u8 *p;
    u8 *e;
    u8 *e2;
    u8 n;
    u8 i;

    if (k == BTL_EVENT_GetVar(3)) {
        a = func_021C7FCC(s, k);
        b = (int)func_021C7FE0(s, k);
        p = func_021C8120(s, 12);
        e = func_021C88A4((char *)s, 4, k);
        func_021C8838(e + 4, 1, x);
        func_021C88C8(s, e);
        n = func_021E4A08(a, 0, 12, p);
        if (b != 0)
            n = n + func_021E4A08((u8 *)b, n, 12, p);
        if (n != 0) {
            if (n > 12)
                n = 12;
            e2 = func_021C88A4((char *)s, 0xb, k);
            e2[0x14] = n;
            for (i = 0; i < n; i++)
                e2[8 + i] = p[i];
            ((struct Obj10091 *)e2)->f4 = 0x24;
            func_021C88C8(s, e2);
        }
    }
}
