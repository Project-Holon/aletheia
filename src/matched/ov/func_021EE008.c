/*
 * function: func_021EE008
 * address:  0x021EE008
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021EB85C  0x021EB85C  thumb  ov170
 *   func_021EDFC4  0x021EDFC4  thumb  ov170
 *   func_021EC000  0x021EC000  thumb  ov170
 *   BMP_OAM_SetEnabled  0x02025774  thumb  arm9
 *
 * Two-way: with flag 1 run the pair update, otherwise release slot 3
 *   and post 0 to the p+0x2c+4 object.
 */
#include "../include/Obj00000.h"


extern void func_021EB85C(unsigned char *p, int i);
extern void func_021EDFC4(char *, int);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021EC000(char *p, int i, int v);
extern void BMP_OAM_SetEnabled(u8 *g, u32 a);
void func_021EE008(char *p, int a, int b)
{
    if (b == 1) {
        func_021EB85C((unsigned char *)p, a);
        func_021EDFC4(p, a);
        return;
    }
    func_021EC000((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 3, 0);
    BMP_OAM_SetEnabled((u8 *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 4)), 0);
}
