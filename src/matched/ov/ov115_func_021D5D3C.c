/*
 * function: func_021D5D3C
 * address: 0x021D5D3C
 * packet: pkt_ov115_021D5D3C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020456F8 0x020456F8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj08043.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Descriptor;
extern void func_020456F8(struct Descriptor *d);
extern void func_020452E8(struct Descriptor *d);
extern void func_02041B6C(u32);
void func_021D5D3C(u8 *p) { if(((struct Obj08043 *)p)->f34) { func_020456F8(((struct Obj08043 *)p)->f34); func_020452E8(((struct Obj08043 *)p)->f34); ((struct Obj08043 *)p)->f34=0; func_02041B6C(1); } }
