/*
 * function: HAND_ITEM_WhiteHerbUseWhenForced, HAND_ITEM_GetMentalHerbHandlers
 * address: 0x021DE300
 * packet: pkt_ov093_021DE300
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
 *   HAND_ITEM_WhiteHerbRestoreStats 0x021DE2A0 thumb ov093
 *   gMentalHerbHandlers 0x021F1A84 data a4
 */
#include "../include/Obj21385.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void HAND_ITEM_WhiteHerbRestoreStats(void *, void *, int, u8 *);
void HAND_ITEM_WhiteHerbUseWhenForced(void *a, void *b, int c, u8 *d) { if (((struct Obj21385 *)d)->f18) HAND_ITEM_WhiteHerbRestoreStats(a,b,c,d); }
extern u8 gMentalHerbHandlers[];
void *HAND_ITEM_GetMentalHerbHandlers(int *p) { *p=4; return gMentalHerbHandlers; }
