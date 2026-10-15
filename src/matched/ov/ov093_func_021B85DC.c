/*
 * function: BTL_MAIN_GetTextSpeedFrames
 * address: 0x021B85DC
 * packet: pkt_ov093_021B85DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSG_SPEED_GetWaitForSpeed 0x02013080 thumb
 */
#include "../include/Obj20952.h"
typedef unsigned int   u32;
extern signed char MSG_SPEED_GetWaitForSpeed(u32 idx);
int BTL_MAIN_GetTextSpeedFrames(unsigned char *p) { return MSG_SPEED_GetWaitForSpeed(((struct Obj20952 *)p)->f43C); }
