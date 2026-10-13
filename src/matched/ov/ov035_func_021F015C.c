/*
 * function: C_GEAR_POWER_ONOFF_DeleteTaskMenuRes
 * address:  0x021F015C
 * packet:   pkt_021F015C
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_POWER_ONOFF_DeleteTaskMenuRes 0x021F015C thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 */
#include "../include/Obj20481.h"

struct TaskMenuState;
typedef unsigned int   u32;
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);

void C_GEAR_POWER_ONOFF_DeleteTaskMenuRes(char *p)
{
    APP_TASKMENU_RES_Delete((struct TaskMenuState *)(((struct Obj20481 *)p)->f40));
}
