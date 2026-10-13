/*
 * file:     field_gimmick_connect_markers.c
 * unit:     yes
 * function: func_021F36C0, GIMMICK61_Exit, GIMMICK61_Update, GIMMICK61_IsPlayerStepReady, GIMMICK61_PlaceMarkers
 * address:  0x021F36C0
 * region:   ov061
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   GIMMICK61_PlaceMarkers  0x021F388C  thumb  ov061
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   d_021F3974     0x021F3974  data  a4
 *   FLD_EXP_OBJ_RemoveUnit  0x021BE418  thumb  ov021
 *   FIELDMAP_FreeCommonWork  0x021897A0  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FLD_EXP_OBJ_UpdateAnimes  0x021BE580  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   FIELD_PLAYER_GetPosInDir  0x021A3364  thumb  ov021
 *   EVENTDATA_SYSTEM_CheckAutoPosEvent  0x02162478  thumb  ov010
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   FIELD_PLAYER_GetStepKind  0x021A3080  thumb
 *   FIELD_PLAYER_GetStepPhase  0x021A308C  thumb
 *   EVENTDATA_SYSTEM_GetConnectCount  0x02162560  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectData  0x021625CC  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectExitType  0x021626E8  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectCenterPosThunk  0x02162A64  thumb  ov010
 */
#include "field_gimmick_connect_markers_types.h"

struct GameSystem;
struct GameData;
struct EventData;

extern u16 FIELDMAP_GetHeapId(void *fieldMap);
extern void *FIELDMAP_GetExpObj(void *fieldMap);
extern Gimmick61Work *FIELDMAP_AllocCommonWork(void *fieldMap, int id, int heapId, int size);
extern void FLD_EXP_OBJ_AddUnitFromArchive(void *expObj, void *unitDesc, int b);
extern void FLD_EXP_OBJ_SetModelHidden(void *expObj, int unit, int model, int hidden);
extern VecFx32 *FLD_EXP_OBJ_GetModelStatus(void *expObj, unsigned unit, u16 model);
extern void *FLD_EXP_OBJ_GetAnime(void *expObj, int unit, unsigned int model, int animeIdx);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *expObj, int unit, u16 model, u16 animeIdx, int enabled);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *anime, int paused);
extern void FLD_EXP_OBJ_SetAnimeLoop(u8 *anime, int loop);
extern void GIMMICK61_PlaceMarkers(Gimmick61Work *work, void *fieldMap);
extern u16 FIELDMAP_GetZoneId(void *fieldMap);
extern void FLD_EXP_OBJ_RemoveUnit(void *expObj, unsigned short unit);
extern void FIELDMAP_FreeCommonWork(void *fieldMap, int id);
extern void *FIELDMAP_GetFieldPlayer(void *fieldMap);
extern struct GameSystem *FIELDMAP_GetGameSystem(void *fieldMap);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct EventData *GAME_DATA_GetEventData(const struct GameData *gameData);
extern Gimmick61Work *FIELDMAP_GetCommonWork(void *fieldMap, int idx);
extern void FLD_EXP_OBJ_UpdateAnimes(void *expObj);
extern int FLD_EXP_OBJ_IsAnimeStopped(u8 *anime);
extern u16 FIELD_PLAYER_GetDirDisp(void *player);
extern void FIELD_PLAYER_GetPosInDir(void *player, int dir, VecFx32 *out);
extern int EVENTDATA_SYSTEM_CheckAutoPosEvent(struct EventData *eventData, VecFx32 *pos);
extern void FLD_EXP_OBJ_SetAnimeFrame(void *expObj, int unit, int model, int animeIdx, int frame);
extern u32 FIELD_PLAYER_GetStepKind(void *player);
extern u32 FIELD_PLAYER_GetStepPhase(void *player);
void func_021F36C0(void *fieldMap);
void GIMMICK61_Exit(void *fieldMap);
void GIMMICK61_Update(void *fieldMap);
int GIMMICK61_IsPlayerStepReady(Gimmick61Work *unusedWork, void *player);
extern char d_021F3974[];
struct ConnectData;
extern u16 EVENTDATA_SYSTEM_GetConnectCount(struct EventData *eventData);
extern struct ConnectData *EVENTDATA_SYSTEM_GetConnectData(struct EventData *eventData, unsigned index);
extern u8 EVENTDATA_SYSTEM_GetConnectExitType(struct ConnectData *connect);
extern void EVENTDATA_SYSTEM_GetConnectCenterPosThunk(struct ConnectData *connect, VecFx32 *out);

void func_021F36C0(void *fieldMap)
{
    u16 heapId;
    void *expObj;
    Gimmick61Work *work;
    int model;
    u8 *anime;

    heapId = FIELDMAP_GetHeapId(fieldMap);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_AllocCommonWork(fieldMap, 0, heapId, sizeof(Gimmick61Work));
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, d_021F3974, 0);
    for (model = 0; model < GIMMICK61_MODEL_COUNT; model++) {
        FLD_EXP_OBJ_SetModelHidden(expObj, 0, (u16)model, 1);
    }
    work->effectPos = FLD_EXP_OBJ_GetModelStatus(expObj, 0, GIMMICK61_EFFECT_MODEL);
    anime = FLD_EXP_OBJ_GetAnime(expObj, 0, GIMMICK61_EFFECT_MODEL, 0);
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, GIMMICK61_EFFECT_MODEL, 0, 1);
    FLD_EXP_OBJ_SetAnimePaused(anime, 1);
    FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
    GIMMICK61_PlaceMarkers(work, fieldMap);
    work->zoneId = FIELDMAP_GetZoneId(fieldMap);
}

void GIMMICK61_Exit(void *fieldMap)
{
    FLD_EXP_OBJ_RemoveUnit(FIELDMAP_GetExpObj(fieldMap), 0);
    FIELDMAP_FreeCommonWork(fieldMap, 0);
}

void GIMMICK61_Update(void *fieldMap)
{
    Gimmick61Work *work;
    void *expObj;
    void *player;
    struct EventData *eventData;
    int zoneId;
    u8 *anime;
    VecFx32 pos;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    eventData = GAME_DATA_GetEventData(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
    work = FIELDMAP_GetCommonWork(fieldMap, 0);
    zoneId = FIELDMAP_GetZoneId(fieldMap);
    if (work->zoneId != zoneId) {
        GIMMICK61_PlaceMarkers(work, fieldMap);
        work->zoneId = zoneId;
    }
    anime = FLD_EXP_OBJ_GetAnime(expObj, 0, GIMMICK61_EFFECT_MODEL, 0);
    FLD_EXP_OBJ_UpdateAnimes(expObj);
    if (work->effectActive != 0 && FLD_EXP_OBJ_IsAnimeStopped(anime) != 0) {
        FLD_EXP_OBJ_SetModelHidden(expObj, 0, GIMMICK61_EFFECT_MODEL, 1);
        work->effectActive = 0;
    }
    if (GIMMICK61_IsPlayerStepReady(work, player) == 0) {
        return;
    }
    FIELD_PLAYER_GetPosInDir(player, FIELD_PLAYER_GetDirDisp(player), &pos);
    pos.x -= 0x8000;
    pos.z -= 0x8000;
    if (EVENTDATA_SYSTEM_CheckAutoPosEvent(eventData, &pos) == 0) {
        return;
    }
    work->effectActive = 1;
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, GIMMICK61_EFFECT_MODEL, 0);
    anime = FLD_EXP_OBJ_GetAnime(expObj, 0, GIMMICK61_EFFECT_MODEL, 0);
    FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, GIMMICK61_EFFECT_MODEL, 0, 0);
    FLD_EXP_OBJ_SetAnimePaused(anime, 0);
    *work->effectPos = pos;
}

/* Returns 1 while the player is in step phase 3 of step kind 0 (ready for a new step). */
int GIMMICK61_IsPlayerStepReady(Gimmick61Work *unusedWork, void *player)
{
    u32 stepKind = FIELD_PLAYER_GetStepKind(player);

    if (FIELD_PLAYER_GetStepPhase(player) == GIMMICK61_STEP_PHASE_READY && stepKind == 0) {
        return 1;
    }
    return 0;
}

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
