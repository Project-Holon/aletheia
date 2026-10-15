/*
 * function: WIFI_BSUBWAY_GRAPHIC_GetSaveState
 * address: 0x021D73D4
 * packet: pkt_ov116_021D73D4
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * leaf: sole blocker of WIFI_BSUBWAY_Step.
 */
#include "../include/Obj22628.h"
typedef unsigned char u8;
int WIFI_BSUBWAY_GRAPHIC_GetSaveState(u8 *p) { return ((struct Obj22628 *)p)->f9CC; }
