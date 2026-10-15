/*
 * function: BR_POKESEARCH_DestroyBackButton
 * address: 0x021FFF1C
 * packet: pkt_ov186_021FFF1C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_BTN_DeleteObject 0x021FB494 thumb ov186
 */
#include "../include/Obj24877.h"
extern void BR_BTN_DeleteObject(char *p);
void BR_POKESEARCH_DestroyBackButton(char *p) {BR_BTN_DeleteObject(((struct Obj24877 *)p)->f2C);}
