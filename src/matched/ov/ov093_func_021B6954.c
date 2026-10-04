/*
 * function: func_021B6954
 * address:  0x021B6954
 * packet:   pkt_ov093_021B6954
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA710  0x021BA710  thumb  ov093
 *   func_021B9E7C  0x021B9E7C  thumb  ov093
 *   func_021B9E38  0x021B9E38  thumb  ov093
 */
#include "../include/Obj06216.h"
#include "../include/Obj13266.h"

typedef unsigned char  u8;
extern u8 func_021BA710(int a, int b);
struct A;
struct B;
extern void func_021B9E7C(struct A *p, struct B *src);
extern void func_021B9E38(char *p, int a, int b);

void func_021B6954(int a, int b)
{
    char *p = (char *)a;
    int base = ((struct Obj06216 *)p)->f0;
    int idx = func_021BA710(((struct Obj06216 *)p)->f46C, b);
    char *q = (char *)(a + 0x20) + b * 0x28;
    char *e = (char *)base + idx * 4;
    int *r = (int *)((struct Obj13266 *)e)->f48;
    if (*r != 0)
        func_021B9E7C((struct A *)((int)q), (struct B *)((int)r));
    else
        func_021B9E38((char *)((int)q), ((struct Obj06216 *)p)->f468, ((struct Obj13266 *)e)->f34);
}
