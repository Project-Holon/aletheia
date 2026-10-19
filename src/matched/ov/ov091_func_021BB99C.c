/*
 * function: PLIST_MESSAGE_SetWordSetPokemon
 * address: 0x021BB99C
 * packet: pkt_ov091_021BB99C
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORDSET_SetSlotMonNickname 0x0201EEF4 thumb
 */
#include "../include/Obj20890.h"
typedef unsigned int u32;
struct WordSet;
extern void WORDSET_SetSlotMonNickname(struct WordSet *p, u32 i, void *mon);
void PLIST_MESSAGE_SetWordSetPokemon(int a,int b,int c,int d) {WORDSET_SetSlotMonNickname(((struct Obj20890 *)b)->f2C,c,(void *)d);}
