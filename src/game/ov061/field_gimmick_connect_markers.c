/*
 * file:     field_gimmick_connect_markers.c
 * unit:     yes
 * function: FIELD_GIMMICK_CONNECT_MARKERS_Init, FIELD_GIMMICK_CONNECT_MARKERS_Exit, FIELD_GIMMICK_CONNECT_MARKERS_Update, FIELD_GIMMICK_CONNECT_MARKERS_IsPlayerStepReady, FIELD_GIMMICK_CONNECT_MARKERS_PlaceMarkers
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
 *   FIELD_GIMMICK_CONNECT_MARKERS_PlaceMarkers  0x021F388C  thumb  ov061
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   gConnectMarkersUnitSetup     0x021F3974  data  a4
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
struct FieldMap;

#include "../ov021/fieldmap.h"
struct FldExpObjCnt;
struct G3dUtilSetup;
struct FldExpObjCnt;
struct FldExpObjAnime;
struct G3dUtilSetup;
#include "../ov021/fld_exp_obj.h"
struct FldExpObjAnime;
struct FieldMap;
struct FieldPlayer;
#include "../arm9/gamesystem.h"
#include "../arm9/game_data.h"
#include "../ov021/field_player.h"
struct EventDataSystem;
#include "../ov010/eventdata_system.h"
#include "field_gimmick_connect_markers.h"
void FIELD_GIMMICK_CONNECT_MARKERS_Init(void *fieldMap);
void FIELD_GIMMICK_CONNECT_MARKERS_Exit(void *fieldMap);
void FIELD_GIMMICK_CONNECT_MARKERS_Update(void *fieldMap);
int FIELD_GIMMICK_CONNECT_MARKERS_IsPlayerStepReady(FieldGimmickConnectMarkersWork *unusedWork, void *player);
extern char gConnectMarkersUnitSetup[];
struct ConnectData;
struct EventDataSystem;

void FIELD_GIMMICK_CONNECT_MARKERS_Init(void *fieldMap)
{
    u16 heapId;
    struct FldExpObjCnt *expObj;
    FieldGimmickConnectMarkersWork *work;
    int model;
    struct FldExpObjAnime *anime;

    heapId = FIELDMAP_GetHeapId(fieldMap);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_AllocCommonWork(fieldMap, 0, heapId, sizeof(FieldGimmickConnectMarkersWork));
    FLD_EXP_OBJ_AddUnitFromArchive(expObj, (struct G3dUtilSetup *)gConnectMarkersUnitSetup, 0);
    for (model = 0; model < FIELD_GIMMICK_CONNECT_MARKERS_MODEL_COUNT; model++) {
        FLD_EXP_OBJ_SetModelHidden(expObj, 0, (u16)model, 1);
    }
    work->effectPos = (VecFx32 *)FLD_EXP_OBJ_GetModelStatus(expObj, 0, FIELD_GIMMICK_CONNECT_MARKERS_EFFECT_MODEL);
    anime = FLD_EXP_OBJ_GetAnime(expObj, 0, FIELD_GIMMICK_CONNECT_MARKERS_EFFECT_MODEL, 0);
    FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, FIELD_GIMMICK_CONNECT_MARKERS_EFFECT_MODEL, 0, 1);
    FLD_EXP_OBJ_SetAnimePaused(anime, 1);
    FLD_EXP_OBJ_SetAnimeLoop(anime, 0);
    FIELD_GIMMICK_CONNECT_MARKERS_PlaceMarkers(work, fieldMap);
    work->zoneId = FIELDMAP_GetZoneId(fieldMap);
}

void FIELD_GIMMICK_CONNECT_MARKERS_Exit(void *fieldMap)
{
    FLD_EXP_OBJ_RemoveUnit(FIELDMAP_GetExpObj(fieldMap), 0);
    FIELDMAP_FreeCommonWork(fieldMap, 0);
}

void FIELD_GIMMICK_CONNECT_MARKERS_Update(void *fieldMap)
{
    FieldGimmickConnectMarkersWork *work;
    struct FldExpObjCnt *expObj;
    void *player;
    struct EventData *eventData;
    int zoneId;
    struct FldExpObjAnime *anime;
    VecFx32 pos;

    expObj = FIELDMAP_GetExpObj(fieldMap);
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    eventData = GAME_DATA_GetEventData(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
    work = FIELDMAP_GetCommonWork(fieldMap, 0);
    zoneId = FIELDMAP_GetZoneId(fieldMap);
    if (work->zoneId != zoneId) {
        FIELD_GIMMICK_CONNECT_MARKERS_PlaceMarkers(work, fieldMap);
        work->zoneId = zoneId;
    }
    anime = FLD_EXP_OBJ_GetAnime(expObj, 0, FIELD_GIMMICK_CONNECT_MARKERS_EFFECT_MODEL, 0);
    FLD_EXP_OBJ_UpdateAnimes(expObj);
    if (work->effectActive != 0 && FLD_EXP_OBJ_IsAnimeStopped(anime) != 0) {
        FLD_EXP_OBJ_SetModelHidden(expObj, 0, FIELD_GIMMICK_CONNECT_MARKERS_EFFECT_MODEL, 1);
        work->effectActive = 0;
    }
    if (FIELD_GIMMICK_CONNECT_MARKERS_IsPlayerStepReady(work, player) == 0) {
        return;
    }
    FIELD_PLAYER_GetPosInDir(player, FIELD_PLAYER_GetDirDisp(player), &pos);
    pos.x -= 0x8000;
    pos.z -= 0x8000;
    if (EVENTDATA_SYSTEM_CheckAutoPosEvent((struct EventDataSystem *)eventData, &pos) == 0) {
        return;
    }
    work->effectActive = 1;
    FLD_EXP_OBJ_SetModelHidden(expObj, 0, FIELD_GIMMICK_CONNECT_MARKERS_EFFECT_MODEL, 0);
    anime = FLD_EXP_OBJ_GetAnime(expObj, 0, FIELD_GIMMICK_CONNECT_MARKERS_EFFECT_MODEL, 0);
    FLD_EXP_OBJ_SetAnimeFrame(expObj, 0, FIELD_GIMMICK_CONNECT_MARKERS_EFFECT_MODEL, 0, 0);
    FLD_EXP_OBJ_SetAnimePaused(anime, 0);
    *work->effectPos = pos;
}

/* Returns 1 while the player is in step phase 3 of step kind 0 (ready for a new step). */
int FIELD_GIMMICK_CONNECT_MARKERS_IsPlayerStepReady(FieldGimmickConnectMarkersWork *unusedWork, void *player)
{
    u32 stepKind = FIELD_PLAYER_GetStepKind(player);

    if (FIELD_PLAYER_GetStepPhase(player) == FIELD_GIMMICK_CONNECT_MARKERS_STEP_PHASE_READY && stepKind == 0) {
        return 1;
    }
    return 0;
}

/* Shows a marker model (1..8) at the center of each map connection of exit type 6 and hides the others. */
void FIELD_GIMMICK_CONNECT_MARKERS_PlaceMarkers(FieldGimmickConnectMarkersWork *unusedWork, void *fieldMap)
{
    struct EventData *eventData;
    int connectCount;
    struct FldExpObjCnt *expObj;
    int i;
    struct ConnectData *connect;
    VecFx32 pos;

    eventData = GAME_DATA_GetEventData(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(fieldMap)));
    connectCount = EVENTDATA_SYSTEM_GetConnectCount((struct EventDataSystem *)eventData);
    FIELDMAP_GetHeapId(fieldMap);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    for (i = 0; i < FIELD_GIMMICK_CONNECT_MARKERS_MARKER_MAX; i++) {
        FLD_EXP_OBJ_SetModelHidden(expObj, 0, (u16)(i + 1), 1);
    }
    for (i = 0; i < connectCount; i++) {
        connect = EVENTDATA_SYSTEM_GetConnectData((struct EventDataSystem *)eventData, (u16)i);
        if (connect != 0 && EVENTDATA_SYSTEM_GetConnectExitType(connect) == FIELD_GIMMICK_CONNECT_MARKERS_MARKER_EXIT_TYPE) {
            EVENTDATA_SYSTEM_GetConnectCenterPosThunk(connect, &pos);
            if (FIELDMAP_GetZoneId(fieldMap) == FIELD_GIMMICK_CONNECT_MARKERS_LOWERED_ZONE_ID) {
                pos.y -= 0x2000;
            }
            FLD_EXP_OBJ_SetModelHidden(expObj, 0, (u16)(i + 1), 0);
            *(VecFx32 *)FLD_EXP_OBJ_GetModelStatus(expObj, 0, i + 1) = pos;
            FLD_EXP_OBJ_GetAnime(expObj, 0, (u16)(i + 1), (u16)0);
            FLD_EXP_OBJ_SetAnimeEnabled(expObj, 0, i + 1, 0, 1);
        }
    }
}
