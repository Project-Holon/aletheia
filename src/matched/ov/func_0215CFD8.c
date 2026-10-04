/*
 * function: func_0215CFD8
 * address:  0x0215CFD8
 * packet:   pkt_0215CFD8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D50  0x02188D50  thumb
 *   func_021C34C4  0x021C34C4  thumb
 */
#include "../include/Obj17695.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern unsigned short *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5DC(void *a0);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188D50(void *a0);
extern u8 func_021C34C4(void **p);

int func_0215CFD8(int a0, int a1)
{    int t5;
    unsigned short *v0;
    void *v1;
    void *v2;

t5 = a1 + 0;
    v0 = func_02159AE8((void *)a0, (void *)a1);
loc_0215CFE0:
a0 = t5 + 0;
    v1 = func_0215A5DC((void *)a0);
loc_0215CFE8:
    v2 = func_0201210C(v1);
loc_0215CFEC:
    a0 = func_021C34C4((void **)func_02188D50(v2));
loc_0215CFF0:
loc_0215CFF4:
((struct Obj17695 *)((char *)v0))->f0 = a0;
a0 = 0;
    return a0;}
