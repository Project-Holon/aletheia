/*
 * function: PLIST_MESSAGE_SetWordSetValue
 * address: 0x021BB9DC
 * packet: pkt_ov091_021BB9DC
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORDSET_SetSlotFromMsgB4 0x0201F140 thumb
 */
#include "../include/Obj20894.h"
typedef unsigned int   u32;
struct WordSet;
extern void WORDSET_SetSlotFromMsgB4(struct WordSet *p, u32 i, u32 v);
void PLIST_MESSAGE_SetWordSetValue(int a,int b,int c,int d) {WORDSET_SetSlotFromMsgB4((struct WordSet *)(((struct Obj20894 *)b)->f2C),c,(unsigned char)d);}
