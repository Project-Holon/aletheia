/*
 * function: HAND_ITEM_MentalHerbUseWhenForced, HAND_ITEM_GetBrightPowderHandlers
 * address: 0x021DE358
 * packet: pkt_ov093_021DE358
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: r3 is untouched before bl; forward its incoming fourth argument.
 * lever: fourth argument keeps r3 live; three arguments give ldr/cmp r3.
 * unit: yes
 * symbols:
 *   HAND_ITEM_MentalHerbCureCondition 0x021DE34C thumb ov093
 *   gBrightPowderHandlers 0x021F1564 data a4
 */
#include "../include/Obj21387.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void HAND_ITEM_MentalHerbCureCondition(int, int, int, u8 *);
void HAND_ITEM_MentalHerbUseWhenForced(int a, int b, int c, u8 *d) { if (((struct Obj21387 *)d)->f18) HAND_ITEM_MentalHerbCureCondition(a,b,c,d); }
extern u8 gBrightPowderHandlers[];
void *HAND_ITEM_GetBrightPowderHandlers(int *p) { *p=1; return gBrightPowderHandlers; }
