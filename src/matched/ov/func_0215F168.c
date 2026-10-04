/*
 * function: func_0215F168
 * address:  0x0215F168
 * packet:   pkt_0215F168
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02158FB4  0x02158FB4  thumb  ov010
 *   func_02189734  0x02189734  thumb
 *   func_020307B0  0x020307B0  arm
 */
#include "../include/Obj00005.h"
#include "../include/Obj17702.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5F4(void *p);
struct Ctx;
extern u32 func_02012138(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02158FB4(void *p);
extern int func_02189734();
extern int func_020307B0();

int func_0215F168(int a0, int a1)
{
    int t4;
    int t6;
    void *p;
    void *v0;
    void *v1;
    void *v2;

t4 = a1 + 0;
a0 = t4 + 0;
    v0 = func_0215A5DC((void *)a0);
loc_0215F172:
a0 = t4 + 0;
    v1 = func_0215A5F4((void *)a0);
loc_0215F17A:
    a0 = func_02012138(v0);
loc_0215F182:
t6 = a0 + 0;
    v2 = func_0201210C(v0);
loc_0215F18A:
    p = func_02158FB4(v1);
loc_0215F190:
t4 = ((struct Obj17702 *)((char *)p))->f0;
a0 = t6 + 0;
    a0 = func_02189734(a0);
loc_0215F198:
    if (a0 == 0) goto loc_0215F1A6;
loc_0215F19C:
    if (a0 == 1) goto loc_0215F1AA;
loc_0215F1A0:
    if (a0 == 2) goto loc_0215F1B4;
loc_0215F1A4:
    goto loc_0215F1C4;
loc_0215F1A6:
a0 = 0;
    return a0;
loc_0215F1AA:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_0215F1B0:
a0 = 1;
    return a0;
loc_0215F1B4:
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
a1 = 2;
*(u16 *)&((struct Obj00005 *)((char *)a0))->f0 = a1;
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_0215F1C0:
a0 = 1;
    return a0;
loc_0215F1C4:
a0 = 0;
    return a0;}
