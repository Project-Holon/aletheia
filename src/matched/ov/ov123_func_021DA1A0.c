/*
 * function: func_021DA1A0
 * address: 0x021DA1A0
 * packet: pkt_ov123_021DA1A0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9844 0x021D9844 thumb ov123
 *   func_021D9730 0x021D9730 thumb ov123
 *   func_021DA16C 0x021DA16C thumb ov123
 *   func_021DA034 0x021DA034 thumb ov123
 */
#include "../include/Obj08117.h"
typedef unsigned char u8;
extern void func_021D9844(char *,int,int);
extern void func_021D9730(char *,int);
extern void func_021DA16C(char *);
extern void func_021DA034(char *,int,int);
void func_021DA1A0(char *p) { func_021D9844(*(char * *)&((struct Obj08117 *)p)->f10,((struct Obj08117 *)p)->f28,((struct Obj08117 *)p)->f28); func_021D9730(*(char * *)&((struct Obj08117 *)p)->f10,8); func_021DA034(p,(int)func_021DA16C,0x13c); }
