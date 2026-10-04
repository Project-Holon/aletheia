/*
 * function: func_021BA150
 * address: 0x021BA150
 * packet: pkt_ov110_021BA150
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
#include "../include/Obj10265.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
extern u32 func_020221A4(void);
extern void func_021B9CBC(u8 *);
void func_021BA150(int unused, u8 *p) {
    switch (((struct Obj10265 *)p)->f14) {
    case 0:
        func_0202208C(0, 1, 1, 0, 5, 1, 42);
        ++((struct Obj10265 *)p)->f14;
        break;
    case 1:
        if (func_020221A4()) ++((struct Obj10265 *)p)->f14;
        break;
    default:
        func_021B9CBC(p);
        break;
    }
}
