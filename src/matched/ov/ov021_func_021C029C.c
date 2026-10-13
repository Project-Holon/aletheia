/*
 * function: EVENT_DISAPPEAR_StartSpinAndEffect
 * address:  0x021C029C
 * packet:   pkt_ov021_021C029C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELD_TASK_CreateRepeatPlayerEffect  0x021C7D28  thumb  ov021
 *   FIELD_TASK_CreatePlayerSpinEaseIn  0x021C7260  thumb  ov021
 *   FIELD_TASK_CreatePlayerSpinLinear  0x021C71D4  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 */
#include "../include/Obj20154.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef unsigned short u16;
extern u32 FIELDMAP_GetTaskManager(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern int FIELD_TASK_CreateRepeatPlayerEffect(int a, int b, u16 c, u16 d);
extern void *FIELD_TASK_CreatePlayerSpinEaseIn(u32 a, u16 b, int c);
extern void *FIELD_TASK_CreatePlayerSpinLinear(u32 a, u32 b, u32 c);
extern void FIELD_TASK_MANAGER_AddTask(u8 *p, u32 *a, u32 b);

void EVENT_DISAPPEAR_StartSpinAndEffect(u8 *p)
{
    u32 s;
    u32 a;
    u32 b;
    u32 c;
    u32 d;

    s = ((struct Obj20154 *)p)->f4;
    a = FIELDMAP_GetTaskManager((u8 *)s);
    b = FIELD_TASK_CreateRepeatPlayerEffect(s, (int)FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer((void *)s)), 0x28, 6);
    c = (u32)FIELD_TASK_CreatePlayerSpinEaseIn(s, 0x14, 4);
    d = (u32)FIELD_TASK_CreatePlayerSpinLinear(s, 0x14, 5);
    FIELD_TASK_MANAGER_AddTask((u8 *)a, (u32 *)b, 0);
    FIELD_TASK_MANAGER_AddTask((u8 *)a, (u32 *)c, 0);
    FIELD_TASK_MANAGER_AddTask((u8 *)a, (u32 *)d, c);
}
