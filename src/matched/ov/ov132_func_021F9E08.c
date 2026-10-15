/*
 * function: STA_ACTING_SetCameraTarget
 * address: 0x021F9E08
 * packet: pkt_ov132_021F9E08
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj23220.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void STA_ACTING_SetCameraTarget(u8 *p,u16 v) { ((struct Obj23220 *)p)->f6=v; }
