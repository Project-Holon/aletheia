/*
 * function: func_021D4240
 * address: 0x021D4240
 * packet: pkt_ov115_021D4240
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: Two zero bytes of alignment padding follow the return.
 * symbols:
 *   func_020362DC 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 */
#include "../include/Obj22580.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020362DC(void);
extern int TOUCHPANEL_GetTrg(void);
int func_021D4240(u8 *p) { if(func_020362DC()&3) return 1; if(*(int *)(((struct Obj22580 *)p)->f40+4) && TOUCHPANEL_GetTrg()) return 1; return 0; }
