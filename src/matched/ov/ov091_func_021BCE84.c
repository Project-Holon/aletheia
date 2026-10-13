/*
 * function: PLIST_MENU_CreateBank
 * address: 0x021BCE84
 * packet: pkt_ov091_021BCE84
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   CLACT_CreateUnit 0x0204B100 arm
 */
#include "../include/Obj13261.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int,u8,unsigned int);
void PLIST_MENU_CreateBank(char *p) { *(struct Bank * *)&((struct Obj13261 *)p)->f1EC=CLACT_CreateUnit(36,8,((struct Obj13261 *)p)->f0); }
