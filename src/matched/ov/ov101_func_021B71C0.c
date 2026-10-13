/*
 * function: func_021B71C0
 * address: 0x021B71C0
 * packet: pkt_ov101_021B71C0
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_021B73E8 0x021B73E8 thumb ov101
 *   func_021B7384 0x021B7384 thumb ov101
 */
#include "../include/Obj06364.h"
struct TaskMenuState; extern void APP_TASKMENU_WIN_Delete(unsigned char *); extern void APP_TASKMENU_RES_Delete(struct TaskMenuState *); extern void func_020307B0(void *); extern void func_021B73E8(void *); extern void func_021B7384(unsigned);
void func_021B71C0(void *p) { APP_TASKMENU_WIN_Delete(*(unsigned char * *)&((struct Obj06364 *)p)->f0); func_021B73E8(p); APP_TASKMENU_RES_Delete(*(struct TaskMenuState * *)&((struct Obj06364 *)p)->f4); func_021B7384((unsigned)p); func_020307B0(p); }
