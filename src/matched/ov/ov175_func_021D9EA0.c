/*
 * function: func_021D9EA0
 * address: 0x021D9EA0
 * packet: pkt_ov175_021D9EA0
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   DWC_RAP_SetErrorHookCallback 0x02156DE0 thumb ov009
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj24326.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void DWC_RAP_SetErrorHookCallback(int,int);
extern void DWC_RAP_SetErrorCallback(int,int);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32);
extern u32 func_020307B0(void *p);
void func_021D9EA0(u8 *p) { DWC_RAP_SetErrorHookCallback(0,0); DWC_RAP_SetErrorCallback(0,0); GFL_NET_COMMAND_DeleteCommandTable(0x2400); func_020307B0(((struct Obj24326 *)p)->f190); func_020307B0(p); }
