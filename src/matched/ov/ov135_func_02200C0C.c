/*
 * function: func_02200C0C
 * address: 0x02200C0C
 * packet: pkt_ov135_02200C0C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02200EB0 0x02200EB0 thumb ov135
 *   func_02200CCC 0x02200CCC thumb ov135
 *   func_021FFFE8 0x021FFFE8 thumb ov135
 *   func_02040588 0x02040588 arm
 *   func_02200DD0 0x02200DD0 thumb ov135
 *   func_02200E48 0x02200E48 thumb ov135
 *   func_021FFD44 0x021FFD44 thumb ov135
 *   func_0202208C 0x0202208C thumb
 *   func_021F9254 0x021F9254 thumb ov135
 */
#include "../include/Obj10593.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02200EB0(u8 *),func_02200CCC(void),func_021FFFE8(u8 *,u32,u32),func_02040588(u32,u32),func_02200DD0(u8 *),func_02200E48(u8 *),func_021FFD44(u8 *),func_0202208C(void *,u32,u32,u32,u32,u32,u32),func_021F9254(u8 *);
int func_02200C0C(u8 *p) { func_02200EB0(p); func_02200CCC(); func_021FFFE8(p,0,0); if(((struct Obj10593 *)p)->f20==11) { func_02040588(4,0); func_02040588(6,0); } func_02200DD0(p); func_02200E48(p); func_021FFD44(p); func_0202208C((void *)3,1,1,0,6,1,72); func_021F9254(p); ((struct Obj10593 *)p)->f28=0; ((struct Obj10593 *)p)->f12E4=0; return 1; }
