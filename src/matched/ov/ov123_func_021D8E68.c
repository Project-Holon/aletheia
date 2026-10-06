/*
 * function: func_021D8E68
 * address: 0x021D8E68
 * packet: pkt_ov123_021D8E68
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D62A8 0x021D62A8 thumb ov123
 *   func_021D651C 0x021D651C thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D8E28 0x021D8E28 thumb ov123
 */
#include "../include/Obj08114.h"
typedef unsigned char  u8;
extern void func_021D62A8(u8 *p);
extern void func_021D651C(unsigned char *);
typedef unsigned int   u32;
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D8E28(char *p);
void func_021D8E68(char *p) { if(--((struct Obj08114 *)p)->f60==0) { func_021D62A8(((struct Obj08114 *)p)->f14); func_021D651C(((struct Obj08114 *)p)->f14); ((struct Obj08114 *)p)->f60=70; func_021D6EE0((u8 *)p,(int)func_021D8E28,0x9e4); } }
