/*
 * function: PLIST_MENU_DeleteBank
 * address: 0x021BCE9C
 * packet: pkt_ov091_021BCE9C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_DeleteUnit 0x0204B1CC arm
 */
#include "../include/Obj20919.h"
struct Bank;
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
void PLIST_MENU_DeleteBank(unsigned int p) { CLACT_DeleteUnit((struct Bank *)(((struct Obj20919 *)p)->f1EC)); }
