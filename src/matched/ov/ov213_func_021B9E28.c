/*
 * function: COMM_BTL_DEMO_MAIN_GetModeIndex
 * address: 0x021B9E28
 * packet: pkt_ov213_021B9E28
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
#include "../include/Obj25692.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
int COMM_BTL_DEMO_MAIN_GetModeIndex(const char *p) {switch(((struct Obj25692 *)p)->f44){case 1:case 3:return 0;case 2:case 4:return 1;case 0:default:return 0;}}
