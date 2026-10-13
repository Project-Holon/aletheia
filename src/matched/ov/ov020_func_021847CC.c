/*
 * function: EVENT_MAPCHANGE_SeasonEffectAEvent
 * address:  0x021847CC
 * packet:   pkt_ov020_021847CC
 * region:   ov020
 * compiler: dsi/1.1p1
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
 *   EVENT_MAPCHANGE_CheckSeasonChange  0x0218403C  thumb  ov020
 *   EVENT_MAPCHANGE_CreateChangeFieldEvent  0x02184360  thumb  ov020
 *   EVENT_MAPCHANGE_ResetPlayerObjectCode  0x02185F48  thumb  ov020
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   FIELD_PLACE_NAME_OnZoneChange  0x021BC550  thumb  ov021
 *   EVENT_APPEAR_CreateSpinZoom  0x021BF5B4  thumb  ov021
 *   EVENT_DISAPPEAR_CreateSpinZoom  0x021BFD70  thumb  ov021
 */
#include "../include/Obj00082.h"

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
extern void EVENT_MAPCHANGE_CheckSeasonChange(u8 *p);
extern void *EVENT_MAPCHANGE_CreateChangeFieldEvent(u8 *p, int value);
extern void EVENT_MAPCHANGE_ResetPlayerObjectCode(void *p);
extern u32 FIELDMAP_GetPlaceName(u8 *p);
extern void FIELD_PLACE_NAME_OnZoneChange(void *p, int v);
extern void *EVENT_APPEAR_CreateSpinZoom(int a, int b, int c, int d, int e, int f);
extern void *EVENT_DISAPPEAR_CreateSpinZoom(int a0, void *p, int a2, int a3);

int EVENT_MAPCHANGE_SeasonEffectAEvent(int ctx, int *state, u8 *p)
{
    int v;
    int x;
    int z;
    int y;

    x = *(int *)&((struct Obj00082 *)p)->f0;
    y = ((struct Obj00082 *)p)->f4;
    z = *(int *)&((struct Obj00082 *)p)->f8;
    v = GAME_DATA_GetBgmInfo((const struct BigObj *)y);

    switch (*state) {
    case 0:
        EVENT_MAPCHANGE_CheckSeasonChange(p);
        GAME_EVENT_CallEvent((struct Evt *)ctx, EVENT_FIELD_PROCLINK_CreateAnimEvent((void *)x, (void *)z));
        (*state)++;
        break;
    case 1:
        GAME_EVENT_CallEvent((struct Evt *)ctx, EVENT_DISAPPEAR_CreateSpinZoom(ctx, (void *)x, z, ((struct Obj00082 *)p)->f44));
        (*state)++;
        break;
    case 2:
        EVENT_MAPCHANGE_ResetPlayerObjectCode((void *)y);
        FIELD_SOUND_SYSTEM_PostZoneBgmReplace(v, y, ((struct Obj00082 *)p)->f14, (u8)((struct Obj00082 *)p)->f4A);
        FIELD_SOUND_SYSTEM_PostFadeIn(v, y);
        (*state)++;
        break;
    case 3:
        GAME_EVENT_CallEvent((struct Evt *)ctx, EVENT_MAPCHANGE_CreateChangeFieldEvent(p, 2));
        (*state)++;
        break;
    case 4:
        GAME_EVENT_CallEvent((struct Evt *)ctx, EVENT_APPEAR_CreateSpinZoom(ctx, x, z, ((struct Obj00082 *)p)->f44,
                                         ((struct Obj00082 *)p)->f48, ((struct Obj00082 *)p)->f4A));
        (*state)++;
        break;
    case 5:
        FIELD_PLACE_NAME_OnZoneChange((void *)FIELDMAP_GetPlaceName((u8 *)z), *(s16 *)&((struct Obj00082 *)p)->f14);
        return 1;
    }
    return 0;
}
