/*
 * function: CROWD_FreeConfig
 * address: 0x021F3F20
 * packet: pkt_ov055_021F3F20
 * region: ov055
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj13123.h"
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void CROWD_FreeConfig(unsigned char *p) { func_020307B0(((struct Obj13123 *)p)->f38); ((struct Obj13123 *)p)->f38=0; }
