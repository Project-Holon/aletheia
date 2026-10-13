/*
 * function: HAND_SIDE_StealthRockHurtOnEnter
 * address:  0x0689926C
 * packet:   pkt_ov095_0689926C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_06899304  0x06899304  thumb
 *   func_06899314  0x06899314  thumb
 *   func_06899324  0x06899324  thumb
 *   func_06899334  0x06899334  thumb
 *   func_06899344  0x06899344  thumb
 *   func_06899354  0x06899354  thumb
 *   func_06899364  0x06899364  thumb
 *   func_06899374  0x06899374  thumb
 *   func_06899384  0x06899384  thumb
 *   func_06899394  0x06899394  thumb
 */
#include "../include/Obj13632.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_06899304(int a);
extern int func_06899314(int a);
extern int func_06899324(int p, int a);
extern int func_06899334(void);
extern int func_06899344(int a, int b);
extern u8 *func_06899354(int p, int n, int m);
extern int func_06899364(int a, int b);
extern void func_06899374(u8 *p, int n, int c);
extern void func_06899384(u8 *p, int v);
extern void func_06899394(int p, u8 *q);

void HAND_SIDE_StealthRockHurtOnEnter(int a0, int p, int x)
{
    int n;
    u8 v;
    int w;
    u8 *t;

    n = 2;
    v = func_06899304(2);
    if (x == func_06899314(v)) {
        w = func_06899324(p, v);
        switch (func_06899344(5, func_06899334())) {
        default:
            n = 0x20;
            break;
        case 2:
            n = 0x10;
            break;
        case 3:
            n = 8;
            break;
        case 4:
            n = 4;
            break;
        case 5:
            break;
        }
        t = func_06899354(p, 7, 0x1f);
        t[6] = v;
        ((struct Obj13632 *)t)->f4 = func_06899364(w, n);
        func_06899374(t + 0xc, 2, 0x356);
        func_06899384(t + 0xc, v);
        func_06899394(p, t);
    }
}
