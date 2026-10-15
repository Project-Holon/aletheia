/*
 * function: func_021D46CC
 * address: 0x021D46CC
 * packet: pkt_ov115_021D46CC
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   WIFILOGIN_COMMON_SetStateHandler 0x021D426C thumb ov115
 *   func_021D5D5C 0x021D5D5C thumb ov115
 *   func_021D456C 0x021D456C thumb ov115
 *   func_021D5D3C 0x021D5D3C thumb ov115
 */
#include "../include/Obj08041.h"
#include "../include/Obj22591.h"
typedef unsigned char u8; typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void); extern int func_021D5C70(int); extern void WIFILOGIN_COMMON_SetStateHandler(u8 *,u32); extern void *func_021D5D5C(u8 *,int,int,int);
extern void func_021D456C(u8 *); extern void func_021D5D3C(int);
void func_021D46CC(u8 *p) { if(WIPE_SYS_EndCheck() && func_021D5C70(*(int *)&((struct Obj08041 *)p)->f38)) { ((struct Obj08041 *)p)->f30=func_021D5D5C(*(u8 * *)&((struct Obj08041 *)p)->f38,0,!((struct Obj22591 *)(*(u8 * *)&((struct Obj08041 *)p)->f40))->f4,0); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D456C); } }
