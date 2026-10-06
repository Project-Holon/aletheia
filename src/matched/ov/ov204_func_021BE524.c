/*
 * unit: yes
 * function: func_021BE524, func_021BE53C
 * address: 0x021BE524
 * packet: pkt_ov204_021BE524
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: tail-call stub 0x021BE53C included; function_starts seed.
 * symbols:
 *   func_021BF744 0x021BF744 thumb ov204
 *   func_021BF77C 0x021BF77C thumb ov204
 */
#include "../include/Obj25354.h"
#include "../include/Obj25355.h"
extern void func_021BF744(char *p, unsigned int i, unsigned int flag, unsigned int v);
extern unsigned func_021BF77C(char *,unsigned char);
int func_021BE524(char *p,int *state,unsigned *q){func_021BF744(*(char * *)&((struct Obj25354 *)p)->f8,(unsigned char)q[0],q[1],q[2]);return 1;}
unsigned func_021BE53C(char *p,int *state,unsigned *q){return func_021BF77C(*(char * *)&((struct Obj25355 *)p)->f8,q[0]);}
