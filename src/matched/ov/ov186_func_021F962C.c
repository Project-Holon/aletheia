/*
 * function: func_021F962C
 * address:  0x021F962C
 * packet:   pkt_021F962C
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012EBC   0x02012EBC  thumb
 *   func_021FC4DC   0x021FC4DC  thumb
 *   func_020071CC   0x020071CC  thumb
 *
 * Fill the output record from the source object and its nested handle.
 */
#include "../include/Obj05492.h"
#include "../include/Obj05493.h"


typedef unsigned int   u32;
typedef unsigned char  u8;
struct Big;
extern void *func_02012EBC(struct Big *p);
extern u32 func_021FC4DC(u8 *p);
struct Sub020071CCCtrl;
extern void *func_020071CC(struct Sub020071CCCtrl *, unsigned int);

void func_021F962C(char *r5, int *r4)
{
    int x;
    x = (int)func_02012EBC((struct Big *)(*(int *)(*(int *)(((struct Obj05493 *)r4)->f18 + 0xC) + 4)));
    ((struct Obj05492 *)r5)->f8 = r4[1];
    ((struct Obj05492 *)r5)->f0 = r4[3];
    ((struct Obj05492 *)r5)->fC = r4[2];
    ((struct Obj05492 *)r5)->f4 = func_021FC4DC((u8 *)r4[0]);
    ((struct Obj05492 *)r5)->f10 = (int)func_020071CC((struct Sub020071CCCtrl *)x, 0x3a);
    ((struct Obj05492 *)r5)->f14 = *(int *)(*(int *)(((struct Obj05493 *)r4)->f18 + 0xC) + 4);
}
