/*
 * function: func_0216A3F8
 * address:  0x0216A3F8
 * packet:   pkt_0216A3F8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 40 compiled 38
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F50  0x02012F50  thumb
 *   func_021D096C  0x021D096C  thumb
 */
#include "../include/Obj12054.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;

extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012F50(void *base);
extern void *func_021D096C(void *a);

int func_0216A3F8(int a0, int a1)
{    void *p;
    void *v0;
    void *v1;

a0 = a1 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0216A400:
    p = func_020120F4((const struct Ctx *)v0);
loc_0216A406:
    v1 = func_02012F50(p);
loc_0216A40A:
a0 = *(int *)&((struct Obj12054 *)((char *)v1))->f0;
    if (a0 != 0) goto loc_0216A41A;
loc_0216A412:
    p = func_021D096C(v0);
loc_0216A418:
((struct Obj12054 *)((char *)v1))->f0 = p;
loc_0216A41A:
a0 = 0;
    return a0;}
