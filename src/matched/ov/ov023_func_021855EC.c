/*
 * function: func_021855EC
 * address:  0x021855EC
 * packet:   pkt_021855EC
 * region:   ov023
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02185354  0x02185354  thumb  ov023
 *   func_02186444  0x02186444  thumb  ov023
 */
#include "../include/Obj09769.h"

extern void func_02185354(char *p);
typedef unsigned int   u32;
extern void func_02186444(char *p, u32 v);

struct bf4210 {
    unsigned char a : 3;
    unsigned char b : 3;
    unsigned char c : 2;
};

int func_021855EC(unsigned char *p, int a1)
{
    ((struct bf4210 *)(p + 0x4210))->b = 0;
    ((struct Obj09769 *)p)->f9286 += 1;
    if (((struct Obj09769 *)p)->f9286 > 0x1e) {
        func_02186444((char *)p, 0xa);
        ((struct Obj09769 *)p)->f9286 = 0;
    }
    func_02185354((char *)p);
    return a1;
}
