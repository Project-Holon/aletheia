/*
 * function: func_021DA2DC
 * address: 0x021DA2DC
 * packet: pkt_ov123_021DA2DC
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D95F0 0x021D95F0 thumb ov123
 *   func_021D9670 0x021D9670 thumb ov123
 *   func_021DA290 0x021DA290 thumb ov123
 *   func_021DA034 0x021DA034 thumb ov123
 */
#include "../include/Obj10457.h"
typedef unsigned char u8;
extern int func_021D95F0(char *);
extern int func_021D9670(char *,int);
extern void func_021DA290(char *);
extern void func_021DA034(char *,int,int);
void func_021DA2DC(char *p) { if(func_021D95F0(*(char * *)&((struct Obj10457 *)p)->f10)) { ((struct Obj10457 *)p)->f14=func_021D9670(*(char * *)&((struct Obj10457 *)p)->f10,0); func_021DA034(p,(int)func_021DA290,0x1a6); } }
