/*
 * function: PMS_INPUT_VIEW_VBlankTask
 * address: 0x021B9BD0
 * packet: pkt_ov110_021B9BD0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_Update 0x020419E4 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
#include "../include/Obj13768.h"
extern void BG_SYS_Update(void);
extern void CLACT_VBlankSystem(void);
void PMS_INPUT_VIEW_VBlankTask(int a,unsigned char *b) { if(((struct Obj13768 *)b)->f84) ((struct Obj13768 *)b)->f84=0; BG_SYS_Update(); CLACT_VBlankSystem(); }
