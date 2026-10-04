/*
 * function: func_021E57E0
 * address:  0x021E57E0
 * packet:   pkt_021E57E0
 * region:   ov178
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012EBC   0x02012EBC  thumb
 *   func_02012944   0x02012944  thumb
 *   func_0200CA1C   0x0200CA1C  thumb
 *   func_0200873C   0x0200873C  thumb
 *   func_0201AA18   0x0201AA18  thumb
 *   func_0200CA38   0x0200CA38  thumb
 *
 * Populate the 0x28-byte record from the two source objects.
 */
#include "../include/Obj01763.h"


typedef unsigned int   u32;
typedef unsigned char  u8;
struct Big;
struct Blk37;
struct Sub02008700Obj;
extern void *func_02012EBC(struct Big *p);
extern u8 *func_02012944(void *p);
extern void *func_0200CA1C(void *a);
extern struct Sub02008700Obj *func_0200873C(void *sys);
extern unsigned int func_0201AA18(void *p);
extern u32 func_0200CA38(struct Blk37 *p);

void func_021E57E0(int *r5, int *r6, char *r4)
{
    int a;
    int b;
    a = (int)func_02012EBC((struct Big *)r5[5]);
    func_02012944((void *)r5[5]);
    b = (int)func_0200CA1C((void *)r5[5]);
    ((struct Obj01763 *)r4)->f0 = r6[1];
    ((struct Obj01763 *)r4)->f8 = r5[5];
    ((struct Obj01763 *)r4)->f4 = (int)func_0200873C((void *)a);
    ((struct Obj01763 *)r4)->fC = 1;
    ((struct Obj01763 *)r4)->fD = 1;
    ((struct Obj01763 *)r4)->fE = func_0201AA18((void *)r6[1]);
    ((struct Obj01763 *)r4)->fF = 0;
    ((struct Obj01763 *)r4)->f10 = 0;
    ((struct Obj01763 *)r4)->f11 = 0;
    ((struct Obj01763 *)r4)->f12 = 0;
    ((struct Obj01763 *)r4)->f14 = 0;
    ((struct Obj01763 *)r4)->f18 = func_0200CA38((struct Blk37 *)b);
    ((struct Obj01763 *)r4)->f20 = 0;
    ((struct Obj01763 *)r4)->f24 = 0;
}
