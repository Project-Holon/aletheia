/*
 * function: EVENT_DISAPPEAR_StartSpin
 * address:  0x021C0140
 * packet:   pkt_ov021_021C0140
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Links two sub-objects of the owner (EXACT*: 2 bytes of trailing padding).
 *
 * symbols:
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_TASK_CreatePlayerSpinEaseIn  0x021C7260  thumb  ov021
 *   FIELD_TASK_CreatePlayerSpinLinear  0x021C71D4  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 */

typedef unsigned int u32;

typedef unsigned short u16;
typedef unsigned char  u8;
extern u32 FIELDMAP_GetTaskManager(u8 *p);
extern void *FIELD_TASK_CreatePlayerSpinEaseIn(u32 a, u16 b, int c);
extern void *FIELD_TASK_CreatePlayerSpinLinear(u32 a, u32 b, u32 c);
extern void FIELD_TASK_MANAGER_AddTask(u8 *p, u32 *a, u32 b);

void EVENT_DISAPPEAR_StartSpin(u32 *p)
{
    u32 o = p[1];
    u32 r = FIELDMAP_GetTaskManager((u8 *)o);
    u32 a = (u32)FIELD_TASK_CreatePlayerSpinEaseIn(o, 0x14, 3);
    u32 b = (u32)FIELD_TASK_CreatePlayerSpinLinear(o, 0x14, 5);

    FIELD_TASK_MANAGER_AddTask((u8 *)r, (u32 *)a, 0);
    FIELD_TASK_MANAGER_AddTask((u8 *)r, (u32 *)b, a);
}
