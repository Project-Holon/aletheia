/*
 * function: WIFILOGIN_MSG_SetExitFlag
 * address: 0x021D6328
 * packet: pkt_ov115_021D6328
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: single store-and-return callback; following bytes are rodata.
 */
#include "../include/Obj22611.h"
typedef unsigned char u8;
void WIFILOGIN_MSG_SetExitFlag(u8 *p) { ((struct Obj22611 *)p)->f18=1; }
