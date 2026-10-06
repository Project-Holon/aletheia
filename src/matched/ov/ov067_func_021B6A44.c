/*
 * function: func_021B6A44
 * address:  0x021B6A44
 * packet:   pkt_ov067_021B6A44
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B69F8  0x021B69F8  thumb
 *   func_021B69D8  0x021B69D8  thumb
 *   func_020061E4  0x020061E4  thumb
 */
#include "../include/Obj13132.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_021B69F8(u32 p);
struct S;
extern void func_021B69D8(struct S *p, u32 v);
extern void func_020061E4(u32 a);

void func_021B6A44(u8 *p)
{
    u32 a = func_021B69F8((u32)p);
    int b = 1;

    if (a != 0) {
        b = 0;
    }
    func_021B69D8((struct S *)p, b);
    if (((struct Obj13132 *)p)->f34 != 0) {
        func_020061E4(((struct Obj13132 *)p)->f34);
    }
}
