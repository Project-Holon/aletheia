/*
 * function: EVENT_MAPCHANGE_FadeWaitEvent
 * address:  0x02184A14
 * packet:   pkt_ov020_02184A14
 * region:   ov020
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   EVENT_FIELD_PROCLINK_CreateAnimEvent  0x02161824  thumb  ov010
 *   EVENT_MAPCHANGE_CreateChangeFieldEvent  0x02184360  thumb  ov020
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_PLACE_NAME_OnZoneChange  0x021BC550  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb  ov021
 */
#include "../include/Obj00082.h"

typedef unsigned char  u8;
typedef short s16;

typedef unsigned int   u32;
struct Evt;
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void *EVENT_FIELD_PROCLINK_CreateAnimEvent(void *a, void *b);
extern void *EVENT_MAPCHANGE_CreateChangeFieldEvent(u8 *p, int value);
extern u32 FIELDMAP_GetPlaceName(u8 *p);
extern u32 FIELDMAP_GetTaskManager(u8 *p);
extern void FIELD_PLACE_NAME_OnZoneChange(void *p, int v);
extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *a, int b, int sel, int d);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern int FIELD_TASK_MANAGER_IsEmpty(int a);

int EVENT_MAPCHANGE_FadeWaitEvent(int ctx, int *state, u8 *p)
{
    int x = *(int *)&((struct Obj00082 *)p)->f0;
    int z = *(int *)&((struct Obj00082 *)p)->f8;
    int t = FIELDMAP_GetTaskManager((u8 *)z);

    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent((struct Evt *)ctx, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeOut((void *)x, z, 1, 0));
        (*state)++;
        break;
    case 1:
        if (FIELD_TASK_MANAGER_IsEmpty(t)) {
            GAME_EVENT_CallEvent((struct Evt *)ctx, EVENT_FIELD_PROCLINK_CreateAnimEvent((void *)x, (void *)z));
            (*state)++;
        }
        break;
    case 2:
        GAME_EVENT_CallEvent((struct Evt *)ctx, EVENT_MAPCHANGE_CreateChangeFieldEvent(p, 0));
        (*state)++;
        break;
    case 3:
        GAME_EVENT_CallEvent((struct Evt *)ctx, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)x, z, 1, 0, 1, 0, 0));
        (*state)++;
        break;
    case 4:
        FIELD_PLACE_NAME_OnZoneChange((void *)FIELDMAP_GetPlaceName((u8 *)z), *(s16 *)&((struct Obj00082 *)p)->f14);
        return 1;
    }
    return 0;
}
