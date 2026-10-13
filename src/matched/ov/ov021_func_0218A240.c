/*
 * function: FIELD_EVENT_CHECK_RunRail
 * address:  0x0218A240
 * packet:   pkt_ov021_0218A240
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_EVENT_CHECK_CheckRailEvents  0x0218A278  thumb  ov021
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   FIELD_PLACE_NAME_Cancel  0x021BC5BC  thumb  ov021
 *   FIELDMAP_GetZoneEffectWork  0x02189A70  thumb  ov021
 *   FIELD_GIMMICK_SOUND_OBJS_RaiseBgmVolume  0x021F3B10  thumb  ov053
 *   FIELD_EVENT_CHECK_StopSoundAfterEvent  0x0218A6E8  thumb  ov021
 */

struct Obj00020;
int FIELD_EVENT_CHECK_CheckRailEvents(void *sys, struct Obj00020 *pos);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Ctx;
void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
u32 FIELDMAP_GetPlaceName(u8 *p);
int FIELD_PLACE_NAME_Cancel(u8 *a);
u32 FIELDMAP_GetZoneEffectWork(u8 *p);
void FIELD_GIMMICK_SOUND_OBJS_RaiseBgmVolume(void);
void FIELD_EVENT_CHECK_StopSoundAfterEvent(void *p, void *h);

int FIELD_EVENT_CHECK_RunRail(void *p, struct Obj00020 *pos)
{
    void *h;
    int r = FIELD_EVENT_CHECK_CheckRailEvents(p, pos);
    if (r != 0) {
        h = GAMESYSTEM_GetFieldMap(p);
        FIELD_PLACE_NAME_Cancel((u8 *)FIELDMAP_GetPlaceName(h));
        if (FIELDMAP_GetZoneEffectWork(h) != 0)
            FIELD_GIMMICK_SOUND_OBJS_RaiseBgmVolume();
        FIELD_EVENT_CHECK_StopSoundAfterEvent(p, h);
    }
    return r;
}
