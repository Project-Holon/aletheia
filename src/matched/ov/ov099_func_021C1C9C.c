/*
 * function: func_021C1C9C
 * address: 0x021C1C9C
 * packet: pkt_ov099_021C1C9C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 */
#include "../include/Obj10213.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_020061E4(u32 a);
void func_021C1C9C(u32 a,int b,u32 p){u32 offset;offset=a+(((struct Obj10213 *)p)->f8EC<<3);if(*(u8 *)(p+offset+0x8cc)==2 && ((struct Obj10213 *)p)->f8ED==0 && b==0){((struct Obj10213 *)p)->f8ED=offset+1;func_020061E4(1356);}}
