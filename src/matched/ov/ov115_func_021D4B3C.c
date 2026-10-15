/*
 * function: WIFILOGIN_DISP_StepStartWipe
 * address: 0x021D4B3C
 * packet: pkt_ov115_021D4B3C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_Start 0x0202208C thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   WIFILOGIN_COMMON_SetStateHandler 0x021D426C thumb ov115
 *   WIFILOGIN_DISP_StepFinish 0x021D4A98 thumb ov115
 */
#include "../include/Obj22595.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void GFL_USE_FadeOutBgm(u32 a);
extern void WIFILOGIN_COMMON_SetStateHandler(u8 *,u32);
extern void WIFILOGIN_DISP_StepFinish(u8 *);
#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
void WIFILOGIN_DISP_StepStartWipe(u8 *p) {
 WIPE_SYS_Start(0,0,0,0,6,1,((struct Obj22595 *)p)->fC); if(!*(int *)(P(0x40)+4) && !*(int *)(P(0x40)+0x18)) GFL_USE_FadeOutBgm(8); WIFILOGIN_COMMON_SetStateHandler(p,(u32)WIFILOGIN_DISP_StepFinish);
}
