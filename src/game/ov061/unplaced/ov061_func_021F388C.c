/*
 * function: GIMMICK61_PlaceMarkers
 * address:  0x021F388C
 * packet:   pkt_ov061_021F388C
 * region:   ov061
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * EVENTDATA_SYSTEM_GetConnectCount, EVENTDATA_SYSTEM_GetConnectCenterPosThunk (a thunk) and EVENTDATA_SYSTEM_GetConnectCenterPos behind it are
 * unlabelled ov010 leaves filed alongside this function.
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   EVENTDATA_SYSTEM_GetConnectCount  0x02162560  thumb  ov010
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   EVENTDATA_SYSTEM_GetConnectData  0x021625CC  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectExitType  0x021626E8  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectCenterPosThunk  0x02162A64  thumb  ov010
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 */

#include "../unit_021F36C0_types.h"

struct GameSystem;
struct GameData;
struct EventData;
struct ConnectData;

extern struct GameSystem *FIELDMAP_GetGameSystem(void *fieldMap);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct EventData *GAME_DATA_GetEventData(const struct GameData *gameData);
extern u16 EVENTDATA_SYSTEM_GetConnectCount(struct EventData *eventData);
extern u16 FIELDMAP_GetHeapId(void *fieldMap);
extern void *FIELDMAP_GetExpObj(void *fieldMap);
extern void FLD_EXP_OBJ_SetModelHidden(void *expObj, int unit, int model, int hidden);
extern struct ConnectData *EVENTDATA_SYSTEM_GetConnectData(struct EventData *eventData, unsigned index);
extern u8 EVENTDATA_SYSTEM_GetConnectExitType(struct ConnectData *connect);
extern void EVENTDATA_SYSTEM_GetConnectCenterPosThunk(struct ConnectData *connect, VecFx32 *out);
extern u16 FIELDMAP_GetZoneId(void *fieldMap);
extern VecFx32 *FLD_EXP_OBJ_GetModelStatus(void *expObj, int unit, u16 model);
extern void *FLD_EXP_OBJ_GetAnime(void *expObj, int unit, unsigned int model, int animeIdx);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *expObj, int unit, u16 model, u16 animeIdx, int enabled);

/* Shows a marker model (1..8) at the center of each map connection of exit type 6 and hides the others. */
void GIMMICK61_PlaceMarkers(Gimmick61Work *unusedWork, void *fieldMap)
{
    struct EventData *eventData;
    int connectCount;
    void *expObj;
    int i;
    struct ConnectData *connect;
    VecFx32 pos;

    eventData = GAME_DATA_GetEventData(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
    connectCount = EVENTDATA_SYSTEM_GetConnectCount(eventData);
    FIELDMAP_GetHeapId(fieldMap);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    for (i = 0; i < GIMMICK61_MARKER_MAX; i++) {
        FLD_EXP_OBJ_SetModelHidden(expObj, 0, (u16)(i + 1), 1);
    }
    for (i = 0; i < connectCount; i++) {
        connect = EVENTDATA_SYSTEM_GetConnectData(eventData, (u16)i);
        if (connect != 0 && EVENTDATA_SYSTEM_GetConnectExitType(connect) == GIMMICK61_MARKER_EXIT_TYPE) {
            EVENTDATA_SYSTEM_GetConnectCenterPosThunk(connect, &pos);
            if (FIELDMAP_GetZoneId(fieldMap) == GIMMICK61_LOWERED_ZONE_ID) {
                pos.y -= 0x2000;
            }
            FLD_EXP_OBJ_SetModelHidden(expObj, 0, (u16)(i + 1), 0);
            *FLD_EXP_OBJ_GetModelStatus(expObj, 0, i + 1) = pos;
            FLD_EXP_OBJ_GetAnime(expObj, 0, (u16)(i + 1), (u16)0);
            FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, i + 1, 0, 1);
        }
    }
}
