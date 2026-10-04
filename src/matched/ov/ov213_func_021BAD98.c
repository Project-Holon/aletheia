/*
 * function: func_021BAD98
 * address: 0x021BAD98
 * packet: pkt_ov213_021BAD98
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Tail: two zero alignment bytes at 021BADB2.
 * symbols:
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj25716.h"
struct Bank;
extern void func_0204B1CC(struct Bank *),func_0204A5AC(void),func_02082BCC(void *,unsigned,unsigned);
void func_021BAD98(void *p){func_0204B1CC(*(struct Bank * *)&((struct Obj25716 *)p)->f0);func_0204A5AC();func_02082BCC(p,0,4);}
