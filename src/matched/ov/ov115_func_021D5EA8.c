/*
 * function: WIFILOGIN_MSG_GetTaskCursor
 * address: 0x021D5EA8
 * packet: pkt_ov115_021D5EA8
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   func_02034714 0x02034714 arm
 *   d_021D663C 0x021D663C data a1
 */
#include "../include/Obj10335.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern const char d_021D663C[];
extern u8 APP_TASKMENU_GetCursorPos(const u8 *);
extern void func_02034714(const char *expr, u32 line, const char *file);
u8 WIFILOGIN_MSG_GetTaskCursor(u8 *p) { switch(((struct Obj10335 *)p)->f0) { case 0: return APP_TASKMENU_GetCursorPos(*(const u8 * *)&((struct Obj10335 *)p)->f20); case 1: return (u8)((struct Obj10335 *)p)->f28; default: func_02034714(d_021D663C,0,d_021D663C); return 0; } }
