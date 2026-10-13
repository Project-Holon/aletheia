/*
 * function: func_021BCD80
 * address: 0x021BCD80
 * packet: pkt_ov110_021BCD80
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF7FC 0x021BF7FC thumb ov110
 *   func_021BF808 0x021BF808 thumb ov110
 *   APP_TASKMENU_WIN_ChangePalette 0x020282AC thumb
 */
#include "../include/Obj01144.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 func_021BF7FC(u8 *p);
extern int func_021BF808(u8 *);
typedef unsigned int   u32;
struct T;
extern void APP_TASKMENU_WIN_ChangePalette(struct T *p, u16 *a1, u32 a2, u32 a3, u16 a4);
void func_021BCD80(u8 *p) {
    if (func_021BF7FC(*(u8 * *)&((struct Obj01144 *)p)->f4))
        APP_TASKMENU_WIN_ChangePalette(((struct Obj01144 *)p)->f64,((struct Obj01144 *)p)->f34,8,0x3545,0x7b2c);
    else
        APP_TASKMENU_WIN_ChangePalette(((struct Obj01144 *)p)->f64,((struct Obj01144 *)p)->f34,14,0x3545,0x7b2c);
    if (func_021BF808(*(u8 * *)&((struct Obj01144 *)p)->f4))
        APP_TASKMENU_WIN_ChangePalette(((struct Obj01144 *)p)->f68,((struct Obj01144 *)p)->f38,8,0x3545,0x7b2c);
    else
        APP_TASKMENU_WIN_ChangePalette(((struct Obj01144 *)p)->f68,((struct Obj01144 *)p)->f38,14,0x3545,0x7b2c);
}
