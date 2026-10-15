/*
 * function: WIFILOGIN_MSG_StepWipe2
 * address: 0x021D62B4
 * packet: pkt_ov115_021D62B4
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIFILOGIN_MSG_RunStep 0x021D6134 thumb ov115
 *   WIFILOGIN_MSG_StepFinish 0x021D630C thumb ov115
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb  arm9
 *   WIPE_SYS_Start  0x0202208C  thumb  arm9
 */
#include "../include/Obj13856.h"
#include "../include/Obj13857.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void GFL_USE_FadeOutBgm(u32);
extern void WIFILOGIN_MSG_RunStep(void *a0, int a1, int a2);
extern void WIFILOGIN_MSG_StepFinish(void *a0);
void WIFILOGIN_MSG_StepWipe2(u8 *p) {
    int color;
    u8 *q = *(u8 * *)&((struct Obj13856 *)p)->f10;
    if (((struct Obj13857 *)q)->f10 & 16) color = 0x7fff;
    else color = 0;
    if (((struct Obj13857 *)q)->fC == 0) GFL_USE_FadeOutBgm(6);
    WIPE_SYS_Start(0, 0, 0, (u16)color, 6, 1, ((struct Obj13856 *)p)->f14);
    WIFILOGIN_MSG_RunStep(p, (int)((void (*)(void))WIFILOGIN_MSG_StepFinish), 0x213);
}
