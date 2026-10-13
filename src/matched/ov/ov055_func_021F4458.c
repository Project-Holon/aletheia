/*
 * function: CROWD_CloseAllChatterSlots
 * address: 0x021F4458
 * packet: pkt_ov055_021F4458
 * region: ov055
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CROWD_CloseChatterSlot 0x021F45A4 thumb ov055
 */
#include "../include/Obj20580.h"
extern void CROWD_CloseChatterSlot(unsigned short *,unsigned int);
void CROWD_CloseAllChatterSlots(unsigned char *p) { int i; for (i=0;i<16;i++) CROWD_CloseChatterSlot((unsigned short *)(p+16+i*8),((struct Obj20580 *)p)->fC); }
