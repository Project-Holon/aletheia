/*
 * function: func_021D6A08
 * address: 0x021D6A08
 * packet: pkt_ov125_021D6A08
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D730C 0x021D730C thumb ov125
 */
#include "../include/Obj02838.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D730C(char *);
int func_021D6A08(char *p,int a,int b) {if(!func_021D730C(p))return 0;((struct Obj02838 *)p)->f3A4=a;((struct Obj02838 *)p)->f3A8=b;((struct Obj02838 *)p)->f3D8=0x55f3;return 1;}
