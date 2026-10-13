/*
 * function: func_021BCD44
 * address: 0x021BCD44
 * packet: pkt_ov110_021BCD44
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Reads r0 after BF824 and supplies p+4; preserve return and visible argument.
 * symbols:
 *   func_021BF824 0x021BF824 thumb ov110
 *   APP_TASKMENU_WIN_ChangePalette 0x020282AC thumb
 */
#include "../include/Obj06389.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int func_021BF824(u8 *);
struct T;
extern void APP_TASKMENU_WIN_ChangePalette(struct T *p, u16 *a1, u32 a2, u32 a3, u16 a4);
void func_021BCD44(u8 *p)
{
    if (func_021BF824(*(u8 * *)&((struct Obj06389 *)p)->f4) != 0) {
        APP_TASKMENU_WIN_ChangePalette(((struct Obj06389 *)p)->f64, *(u16 * *)&((struct Obj06389 *)p)->f34, 8, 0x3545, 0x7b2c);
    } else {
        APP_TASKMENU_WIN_ChangePalette(((struct Obj06389 *)p)->f64, *(u16 * *)&((struct Obj06389 *)p)->f34, 14, 0x3545, 0x7b2c);
    }
}
