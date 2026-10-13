/*
 * function: BTL_SERVER_FLOW_GetFrontPosOfPoke
 * address: 0x021C7D00
 * packet: pkt_ov093_021C7D00
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C7D24 0x021C7D24 thumb ov093
 *   BTL_MAIN_CheckFrontPos 0x021B86A0 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
extern int func_021C7D24(u8 *);
extern int BTL_MAIN_CheckFrontPos(unsigned int **, unsigned int);
int BTL_SERVER_FLOW_GetFrontPosOfPoke(u8 *p, int b) { int i = func_021C7D24(p + 0x1ab8); if (!BTL_MAIN_CheckFrontPos(*(unsigned int ** *)&((struct Obj00003 *)p)->f4, i)) i = 6; return i; }
