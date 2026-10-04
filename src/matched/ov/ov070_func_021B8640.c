/*
 * function: func_021B8640
 * address:  0x021B8640
 * packet:   pkt_ov070_021B8640
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201C6B4  0x0201C6B4  thumb
 *   func_0202208C  0x0202208C  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B8688  0x021B8688  thumb  ov070
 */
#include "../include/Obj00002.h"

extern int func_0201C6B4();
typedef unsigned int   u32;
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_020061E4(u32 a);
extern void func_021B6100(char *p, int k);
extern void func_021B8688(int p);

void func_021B8640(int p)
{
    if (func_0201C6B4(*(int *)&((struct Obj00002 *)p)->f50C)) {
        func_0202208C(0, 1, 1, 0, 6, 1, ((struct Obj00002 *)p)->f544);
        func_020061E4(0x79F);
        func_021B6100((char *)p, (int)func_021B8688);
    }
}
