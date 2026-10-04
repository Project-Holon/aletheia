/*
 * function: func_0216A594
 * address:  0x0216A594
 * packet:   pkt_0216A594
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocked:  
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F50  0x02012F50  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_021D0AB8  0x021D0AB8  thumb
 */
#include "../include/Obj17758.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012F50(void *base);
extern unsigned int func_02159B10(void *, void *);
extern int func_021D0AB8();

int func_0216A594(int a0, int a1)
{    int t5;
    int t6;
    void *p;
    void *v0;
    void *v1;
    void *v2;

t6 = a1 + 0;
t5 = a0 + 0;
a0 = t6 + 0;
    v0 = func_0215A5F4((void *)a0);
loc_0216A5A0:
a0 = t6 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0216A5A6:
    p = func_020120F4((const struct Ctx *)v1);
loc_0216A5AA:
    v2 = func_02012F50(p);
loc_0216A5AE:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = func_02159B10((void *)a0, (void *)a1);
loc_0216A5B8:
a1 = a0 + 0;
a0 = ((struct Obj17758 *)((char *)v2))->f0;
    a0 = func_021D0AB8(a0, a1);
loc_0216A5C0:
a0 = 0;
    return a0;}
