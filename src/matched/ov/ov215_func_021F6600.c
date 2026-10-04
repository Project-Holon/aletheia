/*
 * function: func_021F6600
 * address: 0x021F6600
 * packet: pkt_ov215_021F6600
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two-byte alignment padding follows the body.
 * symbols:
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02082BCC 0x02082BCC arm
 */
#include "../include/Obj25751.h"
struct Bank;
extern void func_0204B1CC(struct Bank *);
extern void func_0204A5AC(void);
extern void func_02082BCC(void *,int,unsigned);
void func_021F6600(char *p){func_0204B1CC(*(struct Bank * *)&((struct Obj25751 *)p)->f0);func_0204A5AC();func_02082BCC(p,0,4);}
