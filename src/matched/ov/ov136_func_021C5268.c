/*
 * function: MAILVIEW_CreateButtons
 * address: 0x021C5268
 * packet: pkt_ov136_021C5268
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   APP_TASKMENU_WIN_Create  0x02027FEC  thumb  arm9
 */
#include "../include/Obj00160.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 APP_TASKMENU_WIN_Create(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5);
void MAILVIEW_CreateButtons(u8 *p)
{
    if (p[0xB] == 1) {
        ((struct Obj00160 *)p)->f130 = (u32)func_02045EC0(((struct Obj00160 *)p)->f20, 0);
        ((struct Obj00160 *)p)->f134 = 0x39E3;
        ((struct Obj00160 *)p)->f138 = 0;
        ((struct Obj00160 *)p)->f13C = (u32)func_02045EC0(((struct Obj00160 *)p)->f20, 1);
        ((struct Obj00160 *)p)->f140 = 0x39E3;
        ((struct Obj00160 *)p)->f144 = 1;
        ((struct Obj00160 *)p)->f128 = APP_TASKMENU_WIN_Create(*(u32 *)&((struct Obj00160 *)p)->f108, (u32)(p + 0x130), 21, 18, 10, (u16)((struct Obj00160 *)p)->f0);
        ((struct Obj00160 *)p)->f12C = APP_TASKMENU_WIN_Create(*(u32 *)&((struct Obj00160 *)p)->f108, (u32)(p + 0x13C), 21, 21, 10, (u16)((struct Obj00160 *)p)->f0);
    }
}
