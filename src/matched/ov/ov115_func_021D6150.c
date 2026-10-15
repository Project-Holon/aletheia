/*
 * function: WIFILOGIN_MSG_StepWipe
 * address: 0x021D6150
 * packet: pkt_ov115_021D6150
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFILOGIN_MSG_RunStep 0x021D6134 thumb ov115
 *   WIFILOGIN_MSG_StepWaitWipe 0x021D6198 thumb ov115
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 */
#include "../include/Obj13855.h"
#include "../include/Obj22605.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void WIFILOGIN_MSG_RunStep(void *a0, int a1, int a2);
extern void WIFILOGIN_MSG_StepWaitWipe(u8 *p);
void WIFILOGIN_MSG_StepWipe(u8 *p) {
    int color;
    if (((struct Obj22605 *)(*(u8 * *)&((struct Obj13855 *)p)->f10))->f10 & 8) color = 0x7fff;
    else color = 0;
    WIPE_SYS_Start(0, 1, 1, (u16)color, 6, 1, ((struct Obj13855 *)p)->f14);
    WIFILOGIN_MSG_RunStep(p, (int)((void (*)(void))WIFILOGIN_MSG_StepWaitWipe), 0x15b);
}
