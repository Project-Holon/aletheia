/*
 * function: BR_FADE_SetBlendColor
 * address: 0x021FE7F4
 * packet: pkt_ov186_021FE7F4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj24849.h"
typedef unsigned short u16;
void BR_FADE_SetBlendColor(char *p,u16 value) { ((struct Obj24849 *)p)->f24=value; }
