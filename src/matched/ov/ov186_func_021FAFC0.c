/*
 * function: BR_BTN_SetSelected
 * address: 0x021FAFC0
 * packet: pkt_ov186_021FAFC0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_BTN_SetObjectPalette 0x021FB5C4 thumb ov186
 */
#include "../include/Obj24822.h"
extern void BR_BTN_SetObjectPalette(char *p, int n);
void BR_BTN_SetSelected(char *p, unsigned value) { BR_BTN_SetObjectPalette(((struct Obj24822 *)p)->f8,value); }
