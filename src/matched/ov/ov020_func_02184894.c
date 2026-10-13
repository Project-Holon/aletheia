/*
 * function: EVENT_MAPCHANGE_SeasonEffectBEvent
 * address:  0x02184894
 * packet:   pkt_ov020_02184894
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_SOUND_SYSTEM_PostZoneBgmReplace  0x02029D44  thumb
 *   FIELD_SOUND_SYSTEM_PostFadeIn  0x02029D7C  thumb
 *   EVENT_MAPCHANGE_CheckSeasonChange  0x0218403C  thumb  ov020
 *   EVENT_MAPCHANGE_CreateChangeFieldEvent  0x02184360  thumb  ov020
 *   EVENT_MAPCHANGE_ResetPlayerObjectCode  0x02185F48  thumb  ov020
 *   EVENT_FIELD_PROCLINK_CreateAnimEvent  0x02161824  thumb  ov010
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   FIELD_PLACE_NAME_OnZoneChange  0x021BC550  thumb  ov021
 *   EVENT_APPEAR_CreateSpinZoomAlt  0x021BF5E8  thumb  ov021
 *   EVENT_DISAPPEAR_CreateSpinZoomEffect  0x021BFDA0  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;

typedef struct Obj {
    int f00;
    int f04;
    int f08;
    char pad0c[0x14 - 0x0c];
    s16 f14;
    char pad16[0x44 - 0x16];
    int f44;
    u16 f48;
    u16 f4a;
} Obj;

typedef unsigned int   u32;
struct BigObj;
u32 GAME_DATA_GetBgmInfo(const struct BigObj *p);
struct Evt;
void GAME_EVENT_CallEvent(struct Evt *evt, struct Evt **out);
void FIELD_SOUND_SYSTEM_PostZoneBgmReplace(u32 a, u32 b, u16 c, u8 d);
void FIELD_SOUND_SYSTEM_PostFadeIn(int a, int b);
void EVENT_MAPCHANGE_CheckSeasonChange(u8 *p);
void *EVENT_MAPCHANGE_CreateChangeFieldEvent(u8 *p, int value);
void EVENT_MAPCHANGE_ResetPlayerObjectCode(void *p);
void *EVENT_FIELD_PROCLINK_CreateAnimEvent(void *a, void *b);
u32 FIELDMAP_GetPlaceName(u8 *p);
void FIELD_PLACE_NAME_OnZoneChange(void *p, int v);
u32 EVENT_APPEAR_CreateSpinZoomAlt(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
void *EVENT_DISAPPEAR_CreateSpinZoomEffect(int a0, void *p, int a2, int a3);

int EVENT_MAPCHANGE_SeasonEffectBEvent(void *a, int *state, Obj *o)
{
    int f0 = o->f00;
    int f4 = o->f04;
    int f8 = o->f08;
    int h = GAME_DATA_GetBgmInfo((const void *)f4);

    switch (*state) {
    case 0:
        EVENT_MAPCHANGE_CheckSeasonChange((u8 *)o);
        GAME_EVENT_CallEvent(a, EVENT_FIELD_PROCLINK_CreateAnimEvent((void *)f0, (void *)f8));
        (*state)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(a, EVENT_DISAPPEAR_CreateSpinZoomEffect((int)a, (void *)f0, f8, o->f44));
        (*state)++;
        break;
    case 2:
        EVENT_MAPCHANGE_ResetPlayerObjectCode((void *)f4);
        FIELD_SOUND_SYSTEM_PostZoneBgmReplace((int)h, (int)f4, (u16)o->f14, (u8)o->f4a);
        FIELD_SOUND_SYSTEM_PostFadeIn(h, f4);
        (*state)++;
        break;
    case 3:
        GAME_EVENT_CallEvent(a, EVENT_MAPCHANGE_CreateChangeFieldEvent((u8 *)o, 2));
        (*state)++;
        break;
    case 4:
        GAME_EVENT_CallEvent(a, (struct Evt **)EVENT_APPEAR_CreateSpinZoomAlt((u32)a, f0, f8, o->f44, o->f48, o->f4a));
        (*state)++;
        break;
    case 5:
        FIELD_PLACE_NAME_OnZoneChange((void *)FIELDMAP_GetPlaceName((u8 *)f8), o->f14);
        return 1;
    }
    return 0;
}
