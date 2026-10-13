/*
 * function: EVENT_MAPCHANGE_EffectCEvent
 * address:  0x02184B54
 * packet:   pkt_ov020_02184B54
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
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   FIELD_PLACE_NAME_OnZoneChange  0x021BC550  thumb  ov021
 *   EVENT_DISAPPEAR_CreateRisingSpin  0x021BFE00  thumb  ov021
 *   EVENT_APPEAR_CreateDescendingSpin  0x021BF644  thumb  ov021
 */
#include "../include/Obj04978.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short s16;

struct BigObj;
extern unsigned int GAME_DATA_GetBgmInfo(const struct BigObj *p);
struct Evt;
extern void *EVENT_FIELD_PROCLINK_CreateAnimEvent(void *a, void *b);
extern void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
typedef unsigned int   u32;
extern void FIELD_SOUND_SYSTEM_PostZoneBgmReplace(u32 a, u32 b, u16 c, u8 d);
extern void FIELD_SOUND_SYSTEM_PostFadeIn(int a, int b);
extern void *EVENT_MAPCHANGE_CreateChangeFieldEvent(u8 *p, int value);
extern u32 FIELDMAP_GetPlaceName(u8 *p);
extern void FIELD_PLACE_NAME_OnZoneChange(void *p, int v);
extern void *EVENT_DISAPPEAR_CreateRisingSpin(int a0, void *p, int a2);
extern int EVENT_APPEAR_CreateDescendingSpin(int a, int b, int c);

int EVENT_MAPCHANGE_EffectCEvent(int ctx, int *state, u8 *p)
{
    int v;
    int x;
    int z;
    int y;

    x = ((struct Obj04978 *)p)->f0;
    y = ((struct Obj04978 *)p)->f4;
    z = ((struct Obj04978 *)p)->f8;
    v = GAME_DATA_GetBgmInfo((const struct BigObj *)y);

    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent((struct Evt *)ctx, EVENT_FIELD_PROCLINK_CreateAnimEvent((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        GAME_EVENT_CallEvent((struct Evt *)ctx, EVENT_DISAPPEAR_CreateRisingSpin(ctx, (void *)x, z));
        (*state)++;
        break;
    case 2:
        FIELD_SOUND_SYSTEM_PostZoneBgmReplace(v, y, ((struct Obj04978 *)p)->f14, (u8)((struct Obj04978 *)p)->f4A);
        FIELD_SOUND_SYSTEM_PostFadeIn(v, y);
        GAME_EVENT_CallEvent((struct Evt *)ctx, EVENT_MAPCHANGE_CreateChangeFieldEvent(p, 0));
        (*state)++;
        break;
    case 3:
        GAME_EVENT_CallEvent((struct Evt *)ctx, (struct Evt **)EVENT_APPEAR_CreateDescendingSpin(ctx, x, z));
        (*state)++;
        break;
    case 4:
        FIELD_PLACE_NAME_OnZoneChange((void *)FIELDMAP_GetPlaceName((u8 *)z), *(s16 *)&((struct Obj04978 *)p)->f14);
        return 1;
    }
    return 0;
}
