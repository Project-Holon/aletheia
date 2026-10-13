/*
 * unit: yes
 * function: func_021BDF98, func_021BDFA0
 * address: 0x021BDF98
 * packet: pkt_ov204_021BDF98
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
#include "../include/Obj25336.h"
extern void CLACT_VBlankSystem(void);
void func_021BDF98(void *a0){CLACT_VBlankSystem();}
unsigned func_021BDFA0(char *p){return ((struct Obj25336 *)p)->f0;}
