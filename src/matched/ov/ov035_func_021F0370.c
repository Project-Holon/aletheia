/*
 * function: C_GEAR_POWER_ONOFF_IsMenuDecided
 * address:  0x021F0370
 * packet:   pkt_ov035_021F0370
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call leaf of C_GEAR_POWER_ONOFF_StepTurnOff (reads the menu handle at +0x44).
 *
 * symbols:
 *   C_GEAR_POWER_ONOFF_IsMenuDecided 0x021F0370 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 */
#include "../include/Obj20483.h"

typedef unsigned int u32;

struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);

u32 C_GEAR_POWER_ONOFF_IsMenuDecided(char *p)
{
    return APP_TASKMENU_IsFinish(((struct Obj20483 *)p)->f44);
}
