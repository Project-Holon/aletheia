/*
 * function: func_021D698C
 * address: 0x021D698C
 * packet: pkt_ov125_021D698C
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D730C 0x021D730C thumb ov125
 */
#include "../include/Obj14005.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D730C(char *);
int func_021D698C(char *p) {if(!func_021D730C(p))return 0;((struct Obj14005 *)p)->f3E0=2;((struct Obj14005 *)p)->f3D8=0x55f1;return 1;}
