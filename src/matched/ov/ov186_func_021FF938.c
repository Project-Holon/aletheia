/*
 * function: func_021FF938
 * address: 0x021FF938
 * packet: pkt_ov186_021FF938
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6814 0x021D6814 thumb ov125
 *   func_02034714 0x02034714 arm
 *   func_021FFB68 0x021FFB68 thumb ov186
 *   func_021FF8E4 0x021FF8E4 thumb ov186
 *   d_02200D98 0x02200D98 data a1
 */
#include "../include/Obj24865.h"
extern int func_021D6814(char *,int);extern void func_02034714(const char *,unsigned,const char *);extern void func_021FFB68(char *,int);extern void func_021FF8E4(void *,int,int);extern const char d_02200D98[];
void func_021FF938(char *p,int unused,char *q) {if(!func_021D6814(q,((struct Obj24865 *)q)->f5B0))func_02034714(d_02200D98,0,d_02200D98);func_021FFB68(p,(int)func_021FF8E4);}
