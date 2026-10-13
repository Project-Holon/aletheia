/*
 * function: IRC_APPBAR_Delete
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
 *   IRC_APPBAR_DeleteActors 0x021B73E8 thumb ov101
 *   IRC_APPBAR_ReleaseResources 0x021B7384 thumb ov101
 */
#include "../include/Obj06364.h"
struct TaskMenuState; extern void APP_TASKMENU_WIN_Delete(unsigned char *); extern void APP_TASKMENU_RES_Delete(struct TaskMenuState *); extern void func_020307B0(void *); extern void IRC_APPBAR_DeleteActors(void *); extern void IRC_APPBAR_ReleaseResources(unsigned);
void IRC_APPBAR_Delete(void *p) { APP_TASKMENU_WIN_Delete(*(unsigned char * *)&((struct Obj06364 *)p)->f0); IRC_APPBAR_DeleteActors(p); APP_TASKMENU_RES_Delete(*(struct TaskMenuState * *)&((struct Obj06364 *)p)->f4); IRC_APPBAR_ReleaseResources((unsigned)p); func_020307B0(p); }
