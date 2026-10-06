/*
 * function: func_021D8E98
 * address: 0x021D8E98
 * packet: pkt_ov123_021D8E98
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020185F0 0x020185F0 thumb
 *   func_021D6458 0x021D6458 thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8E68 0x021D8E68 thumb ov123
 */
#include "../include/Obj10452.h"
extern int func_020185F0(void *);
extern void func_021D6458(unsigned char *,int,int);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D8E68(char *p);
void func_021D8E98(char *p) { func_021D6458(((struct Obj10452 *)p)->f14,func_020185F0(((struct Obj10452 *)p)->fC),1); ((struct Obj10452 *)p)->f60=10; func_021D6EE0((u8 *)p,(int)func_021D8E68,0x9f6); }
