/*
 * function: func_021DA308
 * address: 0x021DA308
 * packet: pkt_ov123_021DA308
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9514 0x021D9514 thumb ov123
 *   func_021DA2DC 0x021DA2DC thumb ov123
 *   func_021DA034 0x021DA034 thumb ov123
 */
#include "../include/Obj22988.h"
typedef unsigned char u8;
extern void func_021D9514(char *,int);
extern void func_021DA2DC(char *);
extern void func_021DA034(char *,int,int);
void func_021DA308(char *p) { func_021D9514(*(char * *)&((struct Obj22988 *)p)->f10,2); func_021DA034(p,(int)func_021DA2DC,0x1b7); }
