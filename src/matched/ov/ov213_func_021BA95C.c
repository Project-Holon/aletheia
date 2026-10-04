/*
 * function: func_021BA95C
 * address: 0x021BA95C
 * packet: pkt_ov213_021BA95C
 * region: ov213
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA9AC 0x021BA9AC thumb ov213
 *   func_02047E88 0x02047E88 arm
 *   func_02048A18 0x02048A18 arm
 *   func_0204779C 0x0204779C arm
 *   func_020477A4 0x020477A4 arm
 *   d_021BB0F8 0x021BB0F8 data a4
 * width: 477A4 index u16: original narrows at 021BA994-021BA998.
 */
#include "../include/Obj02551.h"
typedef unsigned short u16;
typedef struct Util Util;
typedef struct { void *resTbl; u16 resCount; void *objTbl; u16 objCount; } Setup;
struct G3dSys;
extern const Setup d_021BB0F8[];
extern void func_021BA9AC(unsigned char *p);
extern u16 func_02047E88(Util *util, const Setup *setup);
extern int *func_02048A18(Util *util, unsigned index);
extern int func_0204779C(int *p);
extern unsigned func_020477A4(struct G3dSys *sys, u16 idx);
void func_021BA95C(unsigned char *p, int index)
{
    int *object;
    int i, count;
    if (p[15]) func_021BA9AC(p);
    ((struct Obj02551 *)p)->fC=func_02047E88(*(Util * *)&((struct Obj02551 *)p)->f8, &d_021BB0F8[index]);
    p[15]=1;
    object=func_02048A18(*(Util * *)&((struct Obj02551 *)p)->f8, ((struct Obj02551 *)p)->fC);
    count=func_0204779C(object);
    for(i=0;i<count;i++) func_020477A4((struct G3dSys *)object,i);
}
