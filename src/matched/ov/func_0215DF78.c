/*
 * function: func_0215DF78
 * address:  0x0215DF78
 * packet:   pkt_0215DF78
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012138  0x02012138  thumb
 *   func_021FC81C  0x021FC81C  thumb
 */
#include "../include/Obj00005.h"
#include "../include/Obj09156.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
struct Ctx;
extern u32 func_02012138(const struct Ctx *p);
extern int func_021FC81C();

void func_0215DF78(int a0, int a1, int a2)
{
    int t4;
    void *v0;
    void *v1;

t4 = a0 + 0;
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
    v0 = func_0215A5DC((void *)a0);
loc_0215DF82:
a0 = *(int *)&((struct Obj00005 *)((char *)t4))->f0;
    v1 = func_0215A5E4((void *)a0);
loc_0215DF8A:
    a0 = func_02012138(v0);
loc_0215DF90:
a2 = *(int *)&((struct Obj00005 *)t4)->f4;
a0 = ((struct Obj09156 *)a2)->f28;
    if (a0 == 0xc) goto loc_0215DFAC;
loc_0215DF98:
    if (a0 == 0xd) goto loc_0215DFAC;
loc_0215DF9C:
a0 = ((struct Obj09156 *)a2)->f30;
a1 = 1;
*(u16 *)&((struct Obj00005 *)((char *)a0))->f0 = a1;
a0 = *(int *)&((struct Obj00005 *)t4)->f4;
a0 = *(int *)&((struct Obj00005 *)a0)->f4;
    a0 = func_021FC81C(a0, a1);
loc_0215DFAA:
    return;
loc_0215DFAC:
a0 = ((struct Obj09156 *)a2)->f30;
a1 = 0;
*(u16 *)&((struct Obj00005 *)((char *)a0))->f0 = a1;
    return;}
