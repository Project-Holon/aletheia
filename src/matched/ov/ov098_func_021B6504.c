/*
 * function: func_021B6504
 * address:  0x021B6504
 * packet:   pkt_ov098_021B6504
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B694C  0x021B694C  thumb  ov098
 *   func_021B6A3C  0x021B6A3C  thumb  ov098
 *   func_0220270C  0x0220270C  thumb  ov094
 *   func_02202DC4  0x02202DC4  thumb  ov094
 *   func_021B6364  0x021B6364  thumb  ov098
 *   func_021B6750  0x021B6750  thumb  ov098
 *   func_021B6578  0x021B6578  thumb  ov098
 *   d_021B6D98     0x021B6D98  data   ov098  a4
 *   d_021B6DC0     0x021B6DC0  data   ov098  a4
 */
#include "../include/Obj00381.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern char d_021B6D98[];
extern char d_021B6DC0[];
extern void func_021B694C(u8 *p, u8 *q);
extern int func_021B6A3C(u8 *p);
extern void func_0220270C(char *s, int mode, void *arg);
extern int func_02202DC4(int a, char *b, char *c);
extern void func_021B6364(u8 *p, u32 v);
extern int func_021B6750(char *p);
extern int func_021B6578(char *p);

int func_021B6504(char *p)
{
    int r;

    switch (((struct Obj00381 *)p)->f60) {
    case 0:
        func_021B694C((u8 *)(((struct Obj00381 *)p)->f14), (u8 *)(*(int *)&((struct Obj00381 *)p)->f0));
        ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        break;
    case 1:
        if (func_021B6A3C((u8 *)(((struct Obj00381 *)p)->f14)) != 0) {
            func_0220270C((char *)(((struct Obj00381 *)p)->f10), 7, 0);
            ((struct Obj00381 *)p)->f60 = ((struct Obj00381 *)p)->f60 + 1;
        }
        break;
    case 2:
        r = func_02202DC4(((struct Obj00381 *)p)->f10, d_021B6D98, d_021B6DC0);
        if (r != -1) {
            if (r != 0)
                func_021B6364((u8 *)p, (u32)func_021B6750);
            else
                func_021B6364((u8 *)p, (u32)func_021B6578);
        }
        break;
    }
    return 0;
}
