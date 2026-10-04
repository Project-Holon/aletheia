/*
 * function: func_021BDD5C
 * address: 0x021BDD5C
 * packet: pkt_ov209_021BDD5C
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BDD40 0x021BDD40 thumb ov209
 *   func_0204B1CC 0x0204B1CC arm
 */
#include "../include/Obj25575.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Bank; extern void func_021BDD40(char *,u32);extern void func_0204B1CC(struct Bank *);
void func_021BDD5C(char *p) {u32 i;for(i=0;i<60;i++) func_021BDD40(p,i);func_0204B1CC(*(struct Bank * *)&((struct Obj25575 *)p)->fA70);}
