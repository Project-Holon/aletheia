/*
 * function: EVENT_MAPCHANGE_FadeEvent
 * address:  0x02184584
 * packet:   pkt_ov020_02184584
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   EVENT_FIELD_PROCLINK_CreateAnimEvent  0x02161824  thumb  ov010
 *   EVENT_MAPCHANGE_CheckSeasonChange  0x0218403C  thumb  ov020
 *   EVENT_MAPCHANGE_CreateChangeFieldEvent  0x02184360  thumb  ov020
 *   EVENT_FIELDMAP_CONTROL_GetExitEffect  0x021BE89C  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_GetEntranceEffect  0x021BE8B8  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 */
#include "../include/Obj00082.h"

typedef unsigned char  u8;
typedef unsigned short u16;

struct Evt;
extern void *EVENT_FIELD_PROCLINK_CreateAnimEvent(void *a, void *b);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern void EVENT_MAPCHANGE_CheckSeasonChange(u8 *p);
extern void *EVENT_MAPCHANGE_CreateChangeFieldEvent(u8 *p, int value);
typedef unsigned int   u32;
extern int EVENT_FIELDMAP_CONTROL_GetExitEffect(int a, u32 b);
extern int EVENT_FIELDMAP_CONTROL_GetEntranceEffect(int a, int b);
extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *a, int b, int sel, int d);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);

int EVENT_MAPCHANGE_FadeEvent(int ctx, int *state, u8 *p)
{
    int x;
    int z;

    x = *(int *)&((struct Obj00082 *)p)->f0;
    z = *(int *)&((struct Obj00082 *)p)->f8;

    switch (*state) {
    case 0:
        EVENT_MAPCHANGE_CheckSeasonChange(p);
        GAME_EVENT_CallEvent((struct Evt *)ctx, EVENT_FIELD_PROCLINK_CreateAnimEvent((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        if (((struct Obj00082 *)p)->f40 != 0 && ((struct Obj00082 *)p)->f44 != 0) {
            GAME_EVENT_CallEvent((struct Evt *)ctx, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeOut((void *)x, z, 0, 0));
        } else {
            GAME_EVENT_CallEvent((struct Evt *)ctx, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeOut((void *)x, z, EVENT_FIELDMAP_CONTROL_GetExitEffect(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14), 0));
        }
        (*state)++;
        break;
    case 2:
        GAME_EVENT_CallEvent((struct Evt *)ctx, EVENT_MAPCHANGE_CreateChangeFieldEvent(p, ((struct Obj00082 *)p)->f30));
        (*state)++;
        break;
    case 3:
        if (((struct Obj00082 *)p)->f40 != 0 && ((struct Obj00082 *)p)->f44 != 0) {
            GAME_EVENT_CallEvent((struct Evt *)ctx, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)x, z, 3, 0, 0, (u8)((struct Obj00082 *)p)->f48, (u8)((struct Obj00082 *)p)->f4A));
        } else {
            GAME_EVENT_CallEvent((struct Evt *)ctx, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)x, z, EVENT_FIELDMAP_CONTROL_GetEntranceEffect(((struct Obj00082 *)p)->fC, ((struct Obj00082 *)p)->f14), 0, 1, 0, 0));
        }
        (*state)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}
