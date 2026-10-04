/*
 * function: func_021BDC88
 * address: 0x021BDC88
 * packet: pkt_ov203_021BDC88
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_020362DC 0x020362DC arm
 */
#include "../include/Obj14585.h"
#include "../include/Obj25305.h"
#include "../include/Obj25306.h"
extern unsigned func_020221A4(void);
extern unsigned func_020362DC(void);
int func_021BDC88(char *p){if(((struct Obj25305 *)(*(char * *)&((struct Obj14585 *)p)->f4))->f14!=0||!func_020221A4())return 0;if(((struct Obj25306 *)(*(char * *)&((struct Obj14585 *)p)->f1C))->f14!=0){if(func_020362DC()&0xcf3)return 1;}return 0;}
