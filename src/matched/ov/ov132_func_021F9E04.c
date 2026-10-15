/*
 * function: STA_ACTING_GetCameraTarget
 * address: 0x021F9E04
 * packet: pkt_ov132_021F9E04
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj23219.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
u16 STA_ACTING_GetCameraTarget(u8 *p) { return ((struct Obj23219 *)p)->f4; }
