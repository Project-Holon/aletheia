/*
 * unit: yes
 * function: PLIST_MESSAGE_SetWordSetItem,PLIST_MESSAGE_SetWordSetHeldItem
 * address: 0x021BB9AC
 * packet: pkt_ov091_021BB9AC
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201EF40 0x0201EF40 thumb
 *   func_0201EF4C 0x0201EF4C thumb
 */
#include "../include/Obj20891.h"
#include "../include/Obj20892.h"
typedef unsigned int   u32;
struct WordSet;
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern void func_0201EF4C(struct WordSet *p, u32 i, u32 v);
void PLIST_MESSAGE_SetWordSetItem(int a,int b,int c,int d) {func_0201EF40((struct WordSet *)(((struct Obj20891 *)b)->f2C),c,d);}
void PLIST_MESSAGE_SetWordSetHeldItem(int a, u32 b, u32 c, int d) {func_0201EF4C((struct WordSet *)(((struct Obj20892 *)b)->f2C),c,d);}
