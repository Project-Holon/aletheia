/*
 * function: func_021DA0B8
 * address: 0x021DA0B8
 * packet: pkt_ov123_021DA0B8
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Unsigned result-minus-two range test emits subs/cmp/bhi.
 * symbols:
 *   GAME_DATA_SaveMain 0x02012DD0 thumb
 *   func_021D9514 0x021D9514 thumb ov123
 *   func_021DA034 0x021DA034 thumb ov123
 *   func_021DA090 0x021DA090 thumb ov123
 */
#include "../include/Obj10455.h"
extern int GAME_DATA_SaveMain(unsigned char *);
extern void func_021D9514(char *,int);
extern void func_021DA034(char *,int,int);
extern void func_021DA090(char *p);
void func_021DA0B8(char *p) { if((unsigned int)(GAME_DATA_SaveMain(((struct Obj10455 *)p)->f20)-2)<=1) { ((struct Obj10455 *)p)->f6C=0; func_021D9514(*(char * *)&((struct Obj10455 *)p)->f10,11); func_021DA034(p,(int)func_021DA090,0xfe); } }
