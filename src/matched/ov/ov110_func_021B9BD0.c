/*
 * function: func_021B9BD0
 * address: 0x021B9BD0
 * packet: pkt_ov110_021B9BD0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020419E4 0x020419E4 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
#include "../include/Obj13768.h"
extern void func_020419E4(void);
extern void CLACT_VBlankSystem(void);
void func_021B9BD0(int a,unsigned char *b) { if(((struct Obj13768 *)b)->f84) ((struct Obj13768 *)b)->f84=0; func_020419E4(); CLACT_VBlankSystem(); }
