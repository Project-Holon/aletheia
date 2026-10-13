/*
 * function: CROWD_ExitChatter
 * address: 0x021F4430
 * packet: pkt_ov055_021F4430
 * region: ov055
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CROWD_CloseChatterSlot 0x021F45A4 thumb ov055
 *   MSGDATA_Delete 0x02045C04 arm
 */
#include "../include/Obj07667.h"
extern void CROWD_CloseChatterSlot(unsigned short *,unsigned int);
struct Rec;
typedef unsigned int   u32;
extern u32 MSGDATA_Delete(struct Rec *rec);
void CROWD_ExitChatter(unsigned char *p) { int i; for (i=0;i<16;i++) CROWD_CloseChatterSlot((unsigned short *)(p+16+i*8),((struct Obj07667 *)p)->fC); ((struct Obj07667 *)p)->fC=0; MSGDATA_Delete(((struct Obj07667 *)p)->f8); ((struct Obj07667 *)p)->f8=0; }
