/*
 * function: WORLDTRADE_SERVER_StateWaitMessageOrTouch
 * address: 0x022021C0
 * packet: pkt_ov135_022021C0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_ADAPTER_IsStreamBusy 0x02202840 thumb ov135
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj14179.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 WORLDTRADE_ADAPTER_IsStreamBusy(u8 *p);
extern int TOUCHPANEL_GetTrg(void);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32);
int WORLDTRADE_SERVER_StateWaitMessageOrTouch(u8 *p) { if((WORLDTRADE_ADAPTER_IsStreamBusy(p+0xfa0)==0 && (KEY_GetTrg()&1)) || TOUCHPANEL_GetTrg()) { GFL_USE_PlaySeDefaultVolume(0x547); ((struct Obj14179 *)p)->f28=((struct Obj14179 *)p)->f2C; } return 2; }
