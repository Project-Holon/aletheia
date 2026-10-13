/*
 * function: func_021F3D9C
 * address:  0x021F3D9C
 * packet:   pkt_ov059_021F3D9C
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the event func_021F3CFC starts; the function is 180 bytes, the
 *           rest of the handed 772 is data.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021BE6E8  0x021BE6E8  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216DE94  0x0216DE94  thumb  ov010
 *   func_0216CF2C  0x0216CF2C  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_02162744  0x02162744  thumb  ov010
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02162740  0x02162740  thumb  ov010
 *   func_0216CEE4  0x0216CEE4  thumb  ov010
 *   func_0216DAF8  0x0216DAF8  thumb  ov010
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 */
#include "../sp_poke_gimmick_types.h"

struct MmdlSys;
struct EventData;
struct Mmdl;
struct NpcHeader;
struct PlayerWork;

extern struct MmdlSys *func_02188C7C(struct FieldMap *fieldMap);
extern struct Mmdl *func_0216DE94(struct MmdlSys *mmdlSys, u32 objectId);
extern void func_0216CF2C(struct Mmdl *mmdl);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct EventData *func_02012844(const struct GameData *gameData);
extern u16 func_02162744(struct EventData *eventData);
extern struct PlayerWork *func_020127A4(struct GameData *gameData);
extern u16 func_02012AC8(const struct PlayerWork *playerWork);
extern u32 func_0201296C(const struct GameData *gameData);
extern struct NpcHeader *func_02162740(struct EventData *eventData);
extern struct Mmdl *func_0216CEE4(struct MmdlSys *mmdlSys, struct NpcHeader *headers, u32 zoneId, int count,
                                  u32 eventWork, u32 objectId);
extern void func_0216DAF8(struct Mmdl *mmdl);

/*
 * Event: when the effect model reaches its swap frame, remove the map object
 * with the first stored id and add the one with the second id from the NPC
 * headers of the zone. Ends when the effect animation has stopped.
 */
int func_021F3D9C(struct GameEvent *event, int *seq, void *eventWork)
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
    fieldMap = func_0201210C(gameSystem);
    expObj = func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, 1);
    if (func_021BE6E8(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, 0) == SP_POKE_GIMMICK_SWAP_FRAME) {
        removeObjectId = work->swapObjectIds[0];
        addObjectId = work->swapObjectIds[1];
        mmdlSys = func_02188C7C(fieldMap);
        func_0216CF2C(func_0216DE94(mmdlSys, removeObjectId));
        gameData = func_020120F4(gameSystem);
        eventData = func_02012844(gameData);
        npcCount = func_02162744(eventData);
        zoneId = func_02012AC8(func_020127A4(gameData));
        if (npcCount != 0) {
            eventFlagWork = func_0201296C(gameData);
            mmdl = func_0216CEE4(mmdlSys, func_02162740(eventData), zoneId, npcCount, eventFlagWork, addObjectId);
            if (mmdl != 0)
                func_0216DAF8(mmdl);
        }
    }
    result = 0;
    if (func_021BE6BC(func_021BE674(expObj, 0, SP_POKE_GIMMICK_EFFECT_MODEL, 0)) != 0)
        result = 1;
    return result;
}
