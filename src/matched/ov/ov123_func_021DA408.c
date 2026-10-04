/*
 * function: func_021DA408
 * address: 0x021DA408
 * packet: pkt_ov123_021DA408
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_020362DC 0x020362DC arm
 *   func_021D9918 0x021D9918 thumb ov123
 *   func_021DA054 0x021DA054 thumb ov123
 *   func_021DA034 0x021DA034 thumb ov123
 */
#include "../include/Obj22989.h"
typedef unsigned char u8;
extern unsigned int func_020221A4(void);
extern unsigned int func_020362DC(void);
extern void func_021D9918(char *);
extern void func_021DA054(char *);
extern void func_021DA034(char *,int,int);
void func_021DA408(char *p) { if(func_020221A4() && func_020362DC()) { func_021D9918(*(char * *)&((struct Obj22989 *)p)->f10); func_021DA034(p,(int)func_021DA054,0x22c); } }
