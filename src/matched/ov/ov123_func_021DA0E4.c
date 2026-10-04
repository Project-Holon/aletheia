/*
 * function: func_021DA0E4
 * address: 0x021DA0E4
 * packet: pkt_ov123_021DA0E4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D95F0 0x021D95F0 thumb ov123
 *   func_02012DAC 0x02012DAC thumb
 *   func_021DA034 0x021DA034 thumb ov123
 *   func_021DA0B8 0x021DA0B8 thumb ov123
 */
#include "../include/Obj10456.h"
extern int func_021D95F0(char *);
extern int func_02012DAC(int);
extern void func_021DA034(char *,int,int);
extern void func_021DA0B8(char *p);
void func_021DA0E4(char *p) { if(func_021D95F0(*(char * *)&((struct Obj10456 *)p)->f10)) { ((struct Obj10456 *)p)->f6C=1; func_02012DAC(((struct Obj10456 *)p)->f20); func_021DA034(p,(int)func_021DA0B8,0x109); } }
