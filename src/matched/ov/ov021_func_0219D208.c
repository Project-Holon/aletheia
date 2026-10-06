/*
 * function: func_0219D208
 * address:  0x0219D208
 * packet:   pkt_ov021_0219D208
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216E204  0x0216E204  thumb  ov010
 *   func_0219CBD4  0x0219CBD4  thumb  ov021
 *   func_0219C880  0x0219C880  thumb  ov021
 *   func_02050468  0x02050468  arm
 */
#include "../include/Obj03119.h"

typedef unsigned short u16;
typedef unsigned int   u32;
struct BbActSys;
extern void *func_0216D67C(void *a0);
extern u32 func_0216D520(void *p);
extern int func_0216D7A8(void *p, unsigned int v);
extern u16 func_0216D598(void *p);
extern void func_0216E204(char *a, u32 v);
extern int func_0219CBD4(u32 a, u32 b, u32 c, u32 d);
typedef unsigned char  u8;
extern void func_0219C880(u8 *o, u32 a, u32 b, u32 c);
extern void func_02050468(struct BbActSys *o, u32 first, u32 count);

void func_0219D208(int a, unsigned int id)
{
    int *ctx;
    int i;
    unsigned char *r;
    unsigned short h;
    unsigned short v[2];

    ctx = (int *)func_0216D520(func_0216D67C((void *)a));
    r = (unsigned char *)ctx[8];
    func_0219CBD4((u32)ctx, id, (u32)(&v[1]), (u32)(&v[0]));
    if (v[1] != 0xFFFF && !(v[0] & 2)) {
        func_0216E204((char *)a, id);
        return;
    }
    i = 0;
    h = func_0216D7A8((void *)a, 0);
    if (h == 0xFFFF) {
        func_0216E204((char *)a, id);
        return;
    }
    for (; i < 4; i++) {
        if (((struct Obj03119 *)r)->f0 == 0) {
            break;
        }
    }
    if (i >= 4) {
        func_0216E204((char *)a, id);
        return;
    }
    ((struct Obj03119 *)r)->f0 = a;
    ((struct Obj03119 *)r)->f4 = h;
    ((struct Obj03119 *)r)->f6 = func_0216D598((void *)a);
    ((struct Obj03119 *)r)->f8 = id;
    func_0216E204((char *)a, id);
    i = 0;
    if (func_0216D7A8((void *)a, 0) != 0xFFFF) {
        func_0219C880((u8 *)ctx, a, ((struct Obj03119 *)r)->f4, ((struct Obj03119 *)r)->f6);
        func_02050468((struct BbActSys *)ctx[1], ((struct Obj03119 *)r)->f4, 1);
        ((struct Obj03119 *)r)->f0 = i;
    }
}
