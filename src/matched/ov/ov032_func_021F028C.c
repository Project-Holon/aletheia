/*
 * function: BEACON_VIEW_ApplySlideTarget
 * address: 0x021F028C
 * packet: pkt_ov032_021F028C
 * region: ov032
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BEACON_VIEW_ScrollList 0x021F12B8 thumb ov032
 */
#include "../include/Obj20415.h"
extern void BEACON_VIEW_ScrollList(unsigned char *, int);
void BEACON_VIEW_ApplySlideTarget(unsigned char *p) { BEACON_VIEW_ScrollList(p, ((struct Obj20415 *)p)->f84); }
