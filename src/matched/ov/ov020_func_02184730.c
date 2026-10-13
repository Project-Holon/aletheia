/*
 * function: EVENT_MAPCHANGE_TargetPositionEvent
 * address:  0x02184730
 * packet:   pkt_ov020_02184730
 * region:   ov020
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_PostZoneBgmReplace  0x02029D44  thumb
 *   FIELD_SOUND_SYSTEM_PostFadeIn  0x02029D7C  thumb
 *   EVENT_FIELD_PROCLINK_CreateAnimEvent  0x02161824  thumb  ov010
 *   EVENT_MAPCHANGE_CreateChangeFieldEvent  0x02184360  thumb  ov020
 *   EVENT_APPEAR_CreatePlayerDrop  0x021BF58C  thumb  ov021
 *   EVENT_DISAPPEAR_CreateWalkFall  0x021BFD34  thumb  ov021
 */
#include "../include/Obj05964.h"

typedef unsigned char  u8;
typedef unsigned short u16;

struct BigObj;
extern unsigned int GAME_DATA_GetBgmInfo(const struct BigObj *p);
struct Evt;
extern void *EVENT_FIELD_PROCLINK_CreateAnimEvent(void *a, void *b);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
typedef unsigned int   u32;
extern void FIELD_SOUND_SYSTEM_PostZoneBgmReplace(u32 a, u32 b, u16 c, u8 d);
extern void FIELD_SOUND_SYSTEM_PostFadeIn(int a, int b);
extern void *EVENT_MAPCHANGE_CreateChangeFieldEvent(u8 *p, int value);
extern void *EVENT_APPEAR_CreatePlayerDrop(int a, void *p, int c);
extern int EVENT_DISAPPEAR_CreateWalkFall(int ctx, int a, int b, u8 *p);

int EVENT_MAPCHANGE_TargetPositionEvent(int ctx, int *state, u8 *p)
{
    int v;
    int x;
    int z;
    int y;

    x = ((struct Obj05964 *)p)->f0;
    y = ((struct Obj05964 *)p)->f4;
    z = ((struct Obj05964 *)p)->f8;
    v = GAME_DATA_GetBgmInfo((const struct BigObj *)y);

    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent((struct Evt *)ctx, EVENT_FIELD_PROCLINK_CreateAnimEvent((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        GAME_EVENT_CallEvent((struct Evt *)ctx, (struct Evt **)EVENT_DISAPPEAR_CreateWalkFall(ctx, x, z, p + 0x34));
        (*state)++;
        break;
    case 2:
        FIELD_SOUND_SYSTEM_PostZoneBgmReplace(v, y, ((struct Obj05964 *)p)->f14, (u8)((struct Obj05964 *)p)->f4A);
        FIELD_SOUND_SYSTEM_PostFadeIn(v, y);
        (*state)++;
        break;
    case 3:
        GAME_EVENT_CallEvent((struct Evt *)ctx, EVENT_MAPCHANGE_CreateChangeFieldEvent(p, 0));
        (*state)++;
        break;
    case 4:
        GAME_EVENT_CallEvent((struct Evt *)ctx, (struct Evt **)EVENT_APPEAR_CreatePlayerDrop(ctx, (void *)x, z));
        (*state)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}
