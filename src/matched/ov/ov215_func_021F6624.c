/*
 * unit: yes
 * function: EGG_DEMO_GRAPHIC_VBlankClact,EGG_DEMO_GRAPHIC_GetClactBank
 * address: 0x021F6624
 * packet: pkt_ov215_021F6624
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * extent: includes cleared tiny follower EGG_DEMO_GRAPHIC_GetClactBank; no further code included.
 * symbols:
 *   CLACT_VBlankSystem 0x0204A648 arm
 */
#include "../include/Obj25752.h"
extern void CLACT_VBlankSystem(void);
void EGG_DEMO_GRAPHIC_VBlankClact(void *a0){CLACT_VBlankSystem();}
int EGG_DEMO_GRAPHIC_GetClactBank(void *p){return ((struct Obj25752 *)p)->f0;}
