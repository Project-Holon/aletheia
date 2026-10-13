/*
 * function: POKELIST_HasBackButton
 * address: 0x021B9AB4
 * packet: pkt_ov091_021B9AB4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
#include "../include/Obj00009.h"
#include "../include/Obj20862.h"
typedef unsigned char u8;
int POKELIST_HasBackButton(u8 *p) { return ((struct Obj20862 *)(*(u8 * *)&((struct Obj00009 *)p)->f280))->f34 != 21; }
