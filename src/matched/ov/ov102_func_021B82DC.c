/*
 * function: IRC_COMPATIBLE_MENU_HandleFinish
 * address: 0x021B82DC
 * packet: pkt_ov102_021B82DC
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_COMPATIBLE_MENU_SetFinished 0x021B7F18 thumb ov102
 */
#include "../include/Obj10235.h"
#include "../include/Obj22151.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void IRC_COMPATIBLE_MENU_SetFinished(u8 *);
void IRC_COMPATIBLE_MENU_HandleFinish(u8 *p, u16 *state)
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
        IRC_COMPATIBLE_MENU_SetFinished(p);
        break;
    }
}
