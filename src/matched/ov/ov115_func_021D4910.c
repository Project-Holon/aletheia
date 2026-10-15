/*
 * function: func_021D4910
 * address: 0x021D4910
 * packet: pkt_ov115_021D4910
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
 *   func_021D48A4 0x021D48A4 thumb ov115
 *   func_021D5D3C 0x021D5D3C thumb ov115
 */
#include "../include/Obj10332.h"
#include "../include/Obj22594.h"
typedef unsigned char u8; typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void); extern int func_021D5C70(int); extern void WIFILOGIN_COMMON_SetStateHandler(u8 *,u32); extern void *func_021D5D5C(u8 *,int,int,int);
extern void func_021D48A4(u8 *); extern void func_021D5D3C(int);
void func_021D4910(u8 *p) { ((struct Obj10332 *)p)->f30=func_021D5D5C(*(u8 * *)&((struct Obj10332 *)p)->f38,1,!((struct Obj22594 *)(*(u8 * *)&((struct Obj10332 *)p)->f40))->f4,1); WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D48A4);  }
