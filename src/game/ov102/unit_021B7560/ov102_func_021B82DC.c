/*
 * function: func_021B82DC
 * address: 0x021B82DC
 * packet: pkt_ov102_021B82DC
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7F18 0x021B7F18 thumb ov102
 */
#include "../../../matched/include/Obj10235.h"
#include "../../../matched/include/Obj22151.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B7F18(u8 *);
void func_021B82DC(u8 *p, u16 *state)
{
    switch (*state) {
    case 0:
        if (((struct Obj22151 *)(*(u8 * *)&((struct Obj10235 *)p)->f48C))->fC == 1) {
            if ((((struct Obj10235 *)p)->f486)++ > 10) {
                ((struct Obj10235 *)p)->f486 = 0;
                *state = 1;
            }
        } else {
            *state = 1;
        }
        break;
    case 1:
        func_021B7F18(p);
        break;
    }
}
