/*
 * function: func_06899900
 * address:  0x06899900
 * packet:   pkt_ov095_06899900
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_068999B0  0x068999B0  thumb
 *   func_068999C0  0x068999C0  thumb
 *   func_068999D0  0x068999D0  thumb
 *   func_068999E0  0x068999E0  thumb
 *   func_068999F0  0x068999F0  thumb
 *   func_06899A00  0x06899A00  thumb
 *   func_06899A10  0x06899A10  thumb
 *   func_06899A20  0x06899A20  thumb
 *   func_06899A30  0x06899A30  thumb
 *   func_06899A40  0x06899A40  thumb
 *   func_06899A50  0x06899A50  thumb
 *   func_06899A60  0x06899A60  thumb
 *   func_06899A70  0x06899A70  thumb
 *   func_06899A80  0x06899A80  thumb
 */
#include "../include/Obj06335.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_068999B0(int a);
extern int func_068999C0(int a, int b);
extern int func_068999D0(int a);
extern int func_068999E0(int a);
extern int func_068999F0(int a, int b);
extern int func_06899A00(int a, int b);
extern u8 *func_06899A10(int a, int b, int c);
extern int func_06899A20(int a, int b);
extern void func_06899A30(int a, u8 *q);
extern u8 *func_06899A40(int a, int b, int c);
extern int func_06899A50(int a, int b);
extern void func_06899A60(u8 *p, int n, int c);
extern void func_06899A70(u8 *p, int v);
extern void func_06899A80(int a, u8 *q);

void func_06899900(int a0, int p, int x)
{
    u8 v;
    int w;
    u8 *t;

    v = func_068999B0(2);
    if (v != 0x1f && func_068999C0(p, v) != 0 && func_068999D0(p) == 0
        && x == func_068999E0(v)) {
        w = func_068999F0(p, v);
        if (func_06899A00(w, 9) == 0) {
            t = func_06899A10(p, 0x37, v);
            t[6] = func_06899A20(p, v);
            t[7] = 6;
            ((struct Obj06335 *)t)->f4 = 0x28e;
            func_06899A30(p, t);
            t = func_06899A40(p, 7, 0x1f);
            t[6] = v;
            ((struct Obj06335 *)t)->f4 = func_06899A50(w, 8);
            func_06899A60(t + 0xc, 2, 0x484);
            func_06899A70(t + 0xc, v);
            func_06899A80(p, t);
        }
    }
}
