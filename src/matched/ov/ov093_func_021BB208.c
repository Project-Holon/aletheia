/*
 * function: func_021BB208
 * address:  0x021BB208
 * packet:   pkt_ov093_021BB208
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EE9A4  0x021EE9A4  thumb  ov093
 *   func_021BB724  0x021BB724  thumb  ov093
 *   func_021BB718  0x021BB718  thumb  ov093
 *   func_021BB798  0x021BB798  thumb  ov093
 *   func_021BB7D0  0x021BB7D0  thumb  ov093
 *   func_021C84D8  0x021C84D8  thumb  ov093
 *   func_021B916C  0x021B916C  thumb  ov093
 *   func_021BABEC  0x021BABEC  thumb  ov093
 *   func_021BB280  0x021BB280  thumb  ov093
 */
#include "../include/Obj13292.h"

typedef unsigned char u8;

extern u8 *func_021EE9A4(u8 *p, unsigned int *out);
typedef unsigned int   u32;
extern void func_021BB724(u8 *p, int a, int b, int c);
extern void func_021BB718(int a, int b);
extern int func_021BB798(u8 *);
extern void func_021BB7D0(const u8 *p);
extern int func_021C84D8(u8 *p);
extern void func_021B916C(u8 *p, u32 x);
extern void func_021BABEC(int *p, void *f);
extern int func_021BB280(u8 *);

int func_021BB208(u8 *p, int *s)
{
    int n;

    switch (*s) {
    case 0: {
        u8 *r = func_021EE9A4(p + 0x68, (unsigned int *)(&n));
        func_021BB724(p, 0xa, (int)r, n);
        (*s)++;
        break;
    }
    case 1:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            func_021BB718((int)p, 0x10);
            (*s)++;
        }
        break;
    case 2:
        if (func_021BB798(p) != 0) {
            func_021BB7D0(p);
            func_021B916C((u8 *)(((struct Obj13292 *)p)->fC), func_021C84D8((u8 *)(((struct Obj13292 *)p)->f44)));
            func_021BABEC((int *)p, (void *)func_021BB280);
        }
        break;
    }
    return 0;
}
