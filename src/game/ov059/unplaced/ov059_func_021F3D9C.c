/*
 * function: SP_POKE_GIMMICK_SwapNpcEventMain
 * address:  0x021F3D9C
 * packet:   pkt_ov059_021F3D9C
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the event SP_POKE_GIMMICK_StartSwapNpc starts; the function is 180 bytes, the
 *           rest of the handed 772 is data.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeFrame  0x021BE6E8  thumb  ov021
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_DeleteMmdl  0x0216CF2C  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   EVENTDATA_SYSTEM_GetNpcCount  0x02162744  thumb  ov010
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   EVENTDATA_SYSTEM_GetNpcHeaders  0x02162740  thumb  ov010
 *   FLDMMDL_AddMmdlHeaderById  0x0216CEE4  thumb  ov010
 *   FLDMMDL_OnMoveBitMovePause  0x0216DAF8  thumb  ov010
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_IsAnimeStopped  0x021BE6BC  thumb  ov021
 */
#include "../sp_poke_gimmick_types.h"

struct MmdlSys;
struct EventData;
struct Mmdl;
struct NpcHeader;
struct PlayerWork;

extern struct MmdlSys *FIELDMAP_GetMmdlSys(struct FieldMap *fieldMap);
extern struct Mmdl *FLDMMDL_SysSearchObjId(struct MmdlSys *mmdlSys, u32 objectId);
extern void FLDMMDL_DeleteMmdl(struct Mmdl *mmdl);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct EventData *GAME_DATA_GetEventData(const struct GameData *gameData);
extern u16 EVENTDATA_SYSTEM_GetNpcCount(struct EventData *eventData);
extern struct PlayerWork *GAME_DATA_GetMyPlayerWork(struct GameData *gameData);
extern u16 GAME_DATA_GetPlayerZoneId(const struct PlayerWork *playerWork);
extern u32 GAME_DATA_GetEventWork(const struct GameData *gameData);
extern struct NpcHeader *EVENTDATA_SYSTEM_GetNpcHeaders(struct EventData *eventData);
extern struct Mmdl *FLDMMDL_AddMmdlHeaderById(struct MmdlSys *mmdlSys, struct NpcHeader *headers, u32 zoneId, int count,
                                  u32 eventWork, u32 objectId);
extern void FLDMMDL_OnMoveBitMovePause(struct Mmdl *mmdl);

/*
 * Event: when the effect model reaches its swap frame, remove the map object
 * with the first stored id and add the one with the second id from the NPC
 * headers of the zone. Ends when the effect animation has stopped.
 */
int SP_POKE_GIMMICK_SwapNpcEventMain(struct GameEvent *event, int *seq, void *eventWork)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    FldExpObjCnt *expObj;
    SpPokeGimmickWork *work;
    u16 removeObjectId;
    u16 addObjectId;
    struct MmdlSys *mmdlSys;
    struct GameData *gameData;
    struct EventData *eventData;
    u16 npcCount;
    u32 zoneId;
    u32 eventFlagWork;
    struct Mmdl *mmdl;
    int result;

    gameSystem = func_020124E4(event);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    expObj = FIELDMAP_GetExpObj(fieldMap);
    work = FIELDMAP_GetCommonWork(fieldMap, 1);
    if (FLD_EXP_OBJ_GetAnimeFrame(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, 0) == SP_POKE_GIMMICK_SWAP_FRAME) {
        removeObjectId = work->swapObjectIds[0];
        addObjectId = work->swapObjectIds[1];
        mmdlSys = FIELDMAP_GetMmdlSys(fieldMap);
        FLDMMDL_DeleteMmdl(FLDMMDL_SysSearchObjId(mmdlSys, removeObjectId));
        gameData = GAMESYSTEM_GetGameData(gameSystem);
        eventData = GAME_DATA_GetEventData(gameData);
        npcCount = EVENTDATA_SYSTEM_GetNpcCount(eventData);
        zoneId = GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(gameData));
        if (npcCount != 0) {
            eventFlagWork = GAME_DATA_GetEventWork(gameData);
            mmdl = FLDMMDL_AddMmdlHeaderById(mmdlSys, EVENTDATA_SYSTEM_GetNpcHeaders(eventData), zoneId, npcCount, eventFlagWork, addObjectId);
            if (mmdl != 0)
                FLDMMDL_OnMoveBitMovePause(mmdl);
        }
    }
    result = 0;
    if (FLD_EXP_OBJ_IsAnimeStopped(FLD_EXP_OBJ_GetAnime(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, 0)) != 0)
        result = 1;
    return result;
}
