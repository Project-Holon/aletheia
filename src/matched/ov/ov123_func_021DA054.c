/*
 * function: func_021DA054
 * address: 0x021DA054
 * packet: pkt_ov123_021DA054
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202208C 0x0202208C thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   func_021DA034 0x021DA034 thumb ov123
 *   func_021DA03C 0x021DA03C thumb ov123
 */
#include "../include/Obj22985.h"
extern void func_0202208C(void *,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int);
typedef unsigned int   u32;
extern void GFL_USE_FadeOutBgm(u32 a);
extern void func_021DA034(char *,int,int);
extern void func_021DA03C(char *p);
void func_021DA054(char *p) { func_0202208C(0,0,0,0x7fff,6,1,((struct Obj22985 *)p)->f0); GFL_USE_FadeOutBgm(6); func_021DA034(p,(int)func_021DA03C,0xe7); }
