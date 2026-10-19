/*
 * function: FIELD_EVENT_CHECK_RunGrid
 * address:  0x0218A074
 * packet:   pkt_ov021_0218A074
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   EFFECT_ENCOUNT_UpdateOccupiedSpot  0x021AA8F8  thumb  ov021
 *   FIELD_EVENT_CHECK_CheckGridEvents  0x02189BD0  thumb  ov021
 *   EFFECT_ENCOUNT_Reset  0x021AA8EC  thumb  ov021
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   FIELD_PLACE_NAME_Cancel  0x021BC5BC  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_ResetGridHold  0x021A3550  thumb  ov021
 *   FIELD_PLAYER_StopGridForcedMove  0x021A356C  thumb  ov021
 *   FIELDMAP_GetZoneEffectWork  0x02189A70  thumb  ov021
 *   FIELD_GIMMICK_SOUND_OBJS_RaiseBgmVolume  0x021F3B10  thumb  ov053
 *   FIELD_EVENT_CHECK_StopSoundAfterEvent  0x0218A6E8  thumb  ov021
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 FIELDMAP_GetEncount(u8 *p);
extern void EFFECT_ENCOUNT_UpdateOccupiedSpot(void);
struct Obj00020;
extern int FIELD_EVENT_CHECK_CheckGridEvents(void *sys, struct Obj00020 *pos, int *outA, int *outB);
extern void EFFECT_ENCOUNT_Reset(u8 *p);
extern u32 FIELDMAP_GetPlaceName(u8 *p);
extern int FIELD_PLACE_NAME_Cancel(u8 *a);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void FIELD_PLAYER_ResetGridHold(u32 *p, int a);
extern void FIELD_PLAYER_StopGridForcedMove(void **p);
extern u32 FIELDMAP_GetZoneEffectWork(u8 *p);
extern void FIELD_GIMMICK_SOUND_OBJS_RaiseBgmVolume(void);
extern void FIELD_EVENT_CHECK_StopSoundAfterEvent(void *a, void *b);

int FIELD_EVENT_CHECK_RunGrid(void *a, int b)
{
    int u;
    int v;
    int r;
    void *p;
    void *q;

    p = GAMESYSTEM_GetFieldMap(a);
    q = (void *)FIELDMAP_GetEncount(p);
    EFFECT_ENCOUNT_UpdateOccupiedSpot();
    r = FIELD_EVENT_CHECK_CheckGridEvents(a, (struct Obj00020 *)b, &u, &v);
    if (r != 0) {
        if (u != 0)
            EFFECT_ENCOUNT_Reset(q);
        FIELD_PLACE_NAME_Cancel((u8 *)((void *)FIELDMAP_GetPlaceName(p)));
        FIELD_PLAYER_ResetGridHold(FIELDMAP_GetFieldPlayer(p), v);
        FIELD_PLAYER_StopGridForcedMove(FIELDMAP_GetFieldPlayer(p));
        if (FIELDMAP_GetZoneEffectWork(p) != 0)
            FIELD_GIMMICK_SOUND_OBJS_RaiseBgmVolume();
        FIELD_EVENT_CHECK_StopSoundAfterEvent(a, p);
    }
    return r;
}
