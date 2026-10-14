/*
 * function: OPTION_MENU_InitRunner
 * address: 0x021BB0F8
 * packet: pkt_ov068_021BB0F8
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   OPTION_MENU_SetRunnerState 0x021BB138 thumb ov068
 */
#include "../include/Obj20650.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void MI_CpuFill8(void *, u32, u32);
extern void OPTION_MENU_SetRunnerState(void *, int);
void OPTION_MENU_InitRunner(u8 *p, int value, int callback)
{
    MI_CpuFill8(p, 0, 16);
    ((struct Obj20650 *)p)->fC = value;
    OPTION_MENU_SetRunnerState(p, callback);
}
