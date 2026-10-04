/*
 * function: func_021DA434
 * address: 0x021DA434
 * packet: pkt_ov123_021DA434
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9844 0x021D9844 thumb ov123
 *   func_021D9730 0x021D9730 thumb ov123
 *   func_021DA408 0x021DA408 thumb ov123
 *   func_021DA034 0x021DA034 thumb ov123
 */
#include "../include/Obj08118.h"
typedef unsigned char u8;
extern void func_021D9844(char *,int,int);
extern void func_021D9730(char *,int);
extern void func_021DA408(char *);
extern void func_021DA034(char *,int,int);
void func_021DA434(char *p) { func_021D9844(*(char * *)&((struct Obj08118 *)p)->f10,((struct Obj08118 *)p)->f28,((struct Obj08118 *)p)->f28); func_021D9730(*(char * *)&((struct Obj08118 *)p)->f10,7); func_021DA034(p,(int)func_021DA408,0x23c); }
