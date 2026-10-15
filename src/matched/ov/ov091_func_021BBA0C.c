/*
 * function: PLIST_MESSAGE_SetWordSetString
 * address: 0x021BBA0C
 * packet: pkt_ov091_021BBA0C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORDSET_SetSlotTag 0x0201EE0C thumb
 */
#include "../include/Obj20896.h"
typedef unsigned int   u32;
struct WordSet;
extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
void PLIST_MESSAGE_SetWordSetString(int a,int b,int c,const void *d,int e) {WORDSET_SetSlotTag((struct WordSet *)(((struct Obj20896 *)b)->f2C),c,d,e,1,2);}
