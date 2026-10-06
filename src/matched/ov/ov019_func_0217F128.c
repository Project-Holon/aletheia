/*
 * function: func_0217F128
 * address:  0x0217F128
 * packet:   pkt_ov019_0217F128
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219160C  0x0219160C  thumb  ov021
 *   func_021915B4  0x021915B4  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_0217F044  0x0217F044  thumb  ov019
 *   func_021904C8  0x021904C8  thumb  ov021
 */
#include "../include/Obj00033.h"

struct U16Vec;
extern void func_0219160C(int *p);
typedef unsigned int   u32;
struct Rec;
extern int func_021915B4(void *a);
extern void func_02045808(struct U16Vec *vec);
extern void func_0217F044(unsigned char *p);
extern u32 func_021904C8(struct Rec *a0);

void func_0217F128(unsigned char *base)
{
    if (*(int *)&((struct Obj00033 *)base)->f280C != 0) {
        func_0219160C((int *)(*(int *)&((struct Obj00033 *)base)->f280C));
        func_021915B4((void *)(*(int *)&((struct Obj00033 *)base)->f280C));
        *(int *)&((struct Obj00033 *)base)->f280C = 0;
        *(base + 0x2828) = 0;
        func_02045808((struct U16Vec *)(((struct Obj00033 *)base)->f2820));
        func_02045808((struct U16Vec *)(((struct Obj00033 *)base)->f2824));
        ((struct Obj00033 *)base)->f2820 = 0;
        ((struct Obj00033 *)base)->f2824 = 0;
    }
    if (((struct Obj00033 *)base)->f2808 != 0) {
        func_0217F044(base);
        func_021904C8((struct Rec *)(((struct Obj00033 *)base)->f2808));
        ((struct Obj00033 *)base)->f2808 = 0;
    }
}
