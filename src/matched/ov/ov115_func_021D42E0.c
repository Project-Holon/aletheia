/*
 * function: func_021D42E0
 * address: 0x021D42E0
 * packet: pkt_ov115_021D42E0
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
 *   WIFILOGIN_COMMON_IsCancelInput 0x021D4240 thumb ov115
 *   func_021D4AB0 0x021D4AB0 thumb ov115
 */
#include "../include/Obj22585.h"
typedef unsigned char u8; typedef unsigned int u32;
extern u32 WIPE_SYS_EndCheck(void); extern int func_021D5C70(int); extern void WIFILOGIN_COMMON_SetStateHandler(u8 *,u32); extern void *func_021D5D5C(u8 *,int,int,int);
extern int WIFILOGIN_COMMON_IsCancelInput(u8 *); extern void func_021D4AB0(u8 *);
void func_021D42E0(u8 *p) { if(WIPE_SYS_EndCheck() && func_021D5C70(((struct Obj22585 *)p)->f38) && WIFILOGIN_COMMON_IsCancelInput(p)) WIFILOGIN_COMMON_SetStateHandler(p,(u32)func_021D4AB0); }
