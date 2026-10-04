/*
 * function: func_021F8140
 * address: 0x021F8140
 * packet: pkt_ov112_021F8140
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F5414 0x021F5414 thumb ov112
 */
#include "../include/Obj10327.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021F5414(int a, int b);
void func_021F8140(int a,u8 *p,int b) { ((struct Obj10327 *)p)->f8=b; func_021F5414((int)(((struct Obj10327 *)p)->f58),b); ((struct Obj10327 *)p)->f4=1; }
