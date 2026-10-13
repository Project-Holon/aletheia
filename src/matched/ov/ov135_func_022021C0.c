/*
 * function: func_022021C0
 * address: 0x022021C0
 * packet: pkt_ov135_022021C0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02202840 0x02202840 thumb ov135
 *   func_020362DC 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_020061E4 0x020061E4 thumb
 */
#include "../include/Obj14179.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_02202840(u8 *p);
extern int TOUCHPANEL_GetTrg(void);
extern u32 func_020362DC(void);
extern void func_020061E4(u32);
int func_022021C0(u8 *p) { if((func_02202840(p+0xfa0)==0 && (func_020362DC()&1)) || TOUCHPANEL_GetTrg()) { func_020061E4(0x547); ((struct Obj14179 *)p)->f28=((struct Obj14179 *)p)->f2C; } return 2; }
