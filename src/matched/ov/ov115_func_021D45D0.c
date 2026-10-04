/*
 * function: func_021D45D0
 * address: 0x021D45D0
 * packet: pkt_ov115_021D45D0
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D5D5C 0x021D5D5C thumb ov115
 *   func_021D4510 0x021D4510 thumb ov115
 *   func_021D5D3C 0x021D5D3C thumb ov115
 */
#include "../include/Obj08039.h"
#include "../include/Obj22589.h"
typedef unsigned char u8; typedef unsigned int u32;
extern u32 func_020221A4(void); extern int func_021D5C70(int); extern void func_021D426C(u8 *,u32); extern void *func_021D5D5C(u8 *,int,int,int);
extern void func_021D4510(u8 *); extern void func_021D5D3C(int);
void func_021D45D0(u8 *p) { if(func_020221A4() && func_021D5C70(*(int *)&((struct Obj08039 *)p)->f38)) { ((struct Obj08039 *)p)->f30=func_021D5D5C(*(u8 * *)&((struct Obj08039 *)p)->f38,1,!((struct Obj22589 *)(*(u8 * *)&((struct Obj08039 *)p)->f40))->f4,0); func_021D426C(p,(u32)func_021D4510); } }
