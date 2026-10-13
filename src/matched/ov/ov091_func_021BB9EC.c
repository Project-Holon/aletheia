/*
 * function: PLIST_MESSAGE_SetWordSetNumber
 * address: 0x021BB9EC
 * packet: pkt_ov091_021BB9EC
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201EFA4 0x0201EFA4 thumb
 */
#include "../include/Obj20895.h"
typedef unsigned int   u32;
struct WordSet;
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
void PLIST_MESSAGE_SetWordSetNumber(int a,int b,int c,int d,unsigned char e) {func_0201EFA4((struct WordSet *)(((struct Obj20895 *)b)->f2C),c,d,e,0,1);}
