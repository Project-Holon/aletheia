/*
 * function: POKELIST_UpdateMessagePhase
 * address: 0x021B9750
 * packet: pkt_ov091_021B9750
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PLIST_MESSAGE_IsIdle 0x021BB8FC thumb ov091
 *   func_020362DC 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 */
#include "../include/Obj09925.h"
typedef unsigned int   u32;
extern int PLIST_MESSAGE_IsIdle(void *unused, u32 p);
extern unsigned func_020362DC(void);
extern int TOUCHPANEL_GetTrg(void);
void POKELIST_UpdateMessagePhase(unsigned p) { if(PLIST_MESSAGE_IsIdle((void *)p,((struct Obj09925 *)p)->f150)==1) { if(func_020362DC()&1) ((struct Obj09925 *)p)->f8=0; if(TOUCHPANEL_GetTrg()==1) ((struct Obj09925 *)p)->f8=1; (*(void (**)(unsigned))(p+328))(p); } }
