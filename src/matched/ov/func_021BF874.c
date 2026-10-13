/*
 * function: EVENT_APPEAR_StartPlayerSpin
 * address:  0x021BF874
 * packet:   pkt_021BF874
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_TASK_CreatePlayerSpinEaseOut  0x021C72AC  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01860.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELDMAP_GetTaskManager(u8 *p);
extern u32 FIELD_TASK_MANAGER_AddTask(u32, u32, u32);
extern void *FIELD_TASK_CreatePlayerSpinEaseOut(u32 a, u16 b, int c, int d);

int EVENT_APPEAR_StartPlayerSpin(void **a)
{
return FIELD_TASK_MANAGER_AddTask(FIELDMAP_GetTaskManager((u8 *)(((struct Obj01860 *)((u8 *)(a)))->f4)), (u32)FIELD_TASK_CreatePlayerSpinEaseOut(((struct Obj01860 *)((u8 *)(a)))->f4, 60, 8, 1), 0);
}

