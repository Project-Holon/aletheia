/*
 * function: PLIST_BATTLE_RefreshOpponentMessage
 * address: 0x021BD4EC
 * packet: pkt_ov091_021BD4EC
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PLIST_BATTLE_PrintOpponentMessage 0x021BD504 thumb ov091
 */
#include "../include/Obj00009.h"
#include "../include/Obj20921.h"
extern void PLIST_BATTLE_PrintOpponentMessage(char *);
void PLIST_BATTLE_RefreshOpponentMessage(char *p) { PLIST_BATTLE_PrintOpponentMessage(p); ((struct Obj00009 *)p)->f20C=((struct Obj20921 *)(*(char * *)&((struct Obj00009 *)p)->f280))->f94; }
