/*
 * function: EVENT_MAPCHANGE_FadeDetachEvent
 * address:  0x02184AB4
 * packet:   pkt_ov020_02184AB4
 * region:   ov020
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   EVENT_FIELD_PROCLINK_CreateAnimEvent  0x02161824  thumb  ov010
 *   EVENT_MAPCHANGE_DetachedTailEvent  0x02184504  thumb  ov020
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   FIELD_PLACE_NAME_OnZoneChange  0x021BC550  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 */
#include "../include/Obj09424.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short s16;

typedef struct { int f[39]; } S9C;

typedef unsigned int   u32;
struct Desc;
struct Evt;
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern void *EVENT_FIELD_PROCLINK_CreateAnimEvent(void *a, void *b);
extern int EVENT_MAPCHANGE_DetachedTailEvent(int a, int *state, u8 *p);
extern u32 FIELDMAP_GetPlaceName(u8 *p);
extern void FIELD_PLACE_NAME_OnZoneChange(void *p, int v);
extern int EVENT_FIELDMAP_CONTROL_StartFadeOut(void *a, int b, int sel, int d);
extern int EVENT_FIELDMAP_CONTROL_StartFadeIn(void *a, int b, int sel, int d, int e, u8 f, u8 g);

int EVENT_MAPCHANGE_FadeDetachEvent(int ctx, int *state, u8 *p)
{
    int x = ((struct Obj09424 *)p)->f0;
    int z = ((struct Obj09424 *)p)->f8;
    int r;
    S9C *o;

    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent((struct Evt *)ctx, EVENT_FIELD_PROCLINK_CreateAnimEvent((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        GAME_EVENT_CallEvent((struct Evt *)ctx, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeOut((void *)x, z, 0, 0));
        (*state)++;
        break;
    case 2:
        r = (int)func_020122C0((void *)x, 0, EVENT_MAPCHANGE_DetachedTailEvent, 0x9c);
        o = func_020124E8((struct Obj *)r);
        *o = *(S9C *)p;
        GAME_EVENT_CallEvent((struct Evt *)ctx, (struct Evt **)r);
        (*state)++;
        break;
    case 3:
        GAME_EVENT_CallEvent((struct Evt *)ctx, (struct Evt **)EVENT_FIELDMAP_CONTROL_StartFadeIn((void *)x, z, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 4:
        FIELD_PLACE_NAME_OnZoneChange((void *)FIELDMAP_GetPlaceName((u8 *)z), ((struct Obj09424 *)p)->f14);
        return 1;
    }
    return 0;
}
