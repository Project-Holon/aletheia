/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F3754, func_021F376C, func_021F3868
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
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188D2C  0x02188D2C  thumb  ov021
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE760  0x021BE760  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021F388C  0x021F388C  thumb  ov061
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   d_021F3974     0x021F3974  data  a4
 *   func_021BE418  0x021BE418  thumb  ov021
 *   func_021897A0  0x021897A0  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_021BE6BC  0x021BE6BC  thumb  ov021
 *   func_021A3050  0x021A3050  thumb  ov021
 *   func_021A3364  0x021A3364  thumb  ov021
 *   func_02162478  0x02162478  thumb  ov010
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 *   func_021A3080  0x021A3080  thumb
 *   func_021A308C  0x021A308C  thumb
 */
#include "unit_021F36C0_types.h"

struct GameSystem;
struct GameData;
struct EventData;

extern u16 func_02188C84(void *fieldMap);
extern void *func_02188D2C(void *fieldMap);
extern Gimmick61Work *func_02189764(void *fieldMap, int id, int heapId, int size);
extern void func_021BE760(void *expObj, void *unitDesc, int b);
extern void func_021BE4B4(void *expObj, int unit, int model, int hidden);
extern VecFx32 *func_021BE480(void *expObj, unsigned unit, int model);
extern void *func_021BE674(void *expObj, int unit, unsigned int model, int animeIdx);
extern void func_021BE700(void *expObj, int unit, int model, int animeIdx, int enabled);
extern void func_021BE6B0(u8 *anime, int paused);
extern void func_021BE6B8(u8 *anime, int loop);
extern void func_021F388C(Gimmick61Work *work, void *fieldMap);
extern u16 func_02188C9C(void *fieldMap);
extern void func_021BE418(void *expObj, unsigned short unit);
extern void func_021897A0(void *fieldMap, int id);
extern void *func_02188CB4(void *fieldMap);
extern struct GameSystem *func_02188C80(void *fieldMap);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct EventData *func_02012844(const struct GameData *gameData);
extern Gimmick61Work *func_021897BC(void *fieldMap, int idx);
extern void func_021BE580(void *expObj);
extern int func_021BE6BC(u8 *anime);
extern u16 func_021A3050(void *player);
extern void func_021A3364(void *player, int dir, VecFx32 *out);
extern int func_02162478(struct EventData *eventData, VecFx32 *pos);
extern void func_021BE6CC(void *expObj, int unit, int model, int animeIdx, int frame);
extern u32 func_021A3080(void *player);
extern u32 func_021A308C(void *player);
void func_021F36C0(void *fieldMap);
void func_021F3754(void *fieldMap);
void func_021F376C(void *fieldMap);
int func_021F3868(Gimmick61Work *unusedWork, void *player);
extern char d_021F3974[];

void func_021F36C0(void *fieldMap)
{
    u16 heapId;
    void *expObj;
    Gimmick61Work *work;
    int model;
    u8 *anime;

    heapId = func_02188C84(fieldMap);
    expObj = func_02188D2C(fieldMap);
    work = func_02189764(fieldMap, 0, heapId, sizeof(Gimmick61Work));
    func_021BE760(expObj, d_021F3974, 0);
    for (model = 0; model < GIMMICK61_MODEL_COUNT; model++) {
        func_021BE4B4(expObj, 0, (u16)model, 1);
    }
    work->effectPos = func_021BE480(expObj, 0, GIMMICK61_EFFECT_MODEL);
    anime = func_021BE674(expObj, 0, GIMMICK61_EFFECT_MODEL, 0);
    func_021BE700(expObj, 0, GIMMICK61_EFFECT_MODEL, 0, 1);
    func_021BE6B0(anime, 1);
    func_021BE6B8(anime, 0);
    func_021F388C(work, fieldMap);
    work->zoneId = func_02188C9C(fieldMap);
}

void func_021F3754(void *fieldMap)
{
    func_021BE418(func_02188D2C(fieldMap), 0);
    func_021897A0(fieldMap, 0);
}

void func_021F376C(void *fieldMap)
{
    Gimmick61Work *work;
    void *expObj;
    void *player;
    struct EventData *eventData;
    int zoneId;
    u8 *anime;
    VecFx32 pos;

    expObj = func_02188D2C(fieldMap);
    player = func_02188CB4(fieldMap);
    eventData = func_02012844(func_020120F4(func_02188C80(fieldMap)));
    work = func_021897BC(fieldMap, 0);
    zoneId = func_02188C9C(fieldMap);
    if (work->zoneId != zoneId) {
        func_021F388C(work, fieldMap);
        work->zoneId = zoneId;
    }
    anime = func_021BE674(expObj, 0, GIMMICK61_EFFECT_MODEL, 0);
    func_021BE580(expObj);
    if (work->effectActive != 0 && func_021BE6BC(anime) != 0) {
        func_021BE4B4(expObj, 0, GIMMICK61_EFFECT_MODEL, 1);
        work->effectActive = 0;
    }
    if (func_021F3868(work, player) == 0) {
        return;
    }
    func_021A3364(player, func_021A3050(player), &pos);
    pos.x -= 0x8000;
    pos.z -= 0x8000;
    if (func_02162478(eventData, &pos) == 0) {
        return;
    }
    work->effectActive = 1;
    func_021BE4B4(expObj, 0, GIMMICK61_EFFECT_MODEL, 0);
    anime = func_021BE674(expObj, 0, GIMMICK61_EFFECT_MODEL, 0);
    func_021BE6CC(expObj, 0, GIMMICK61_EFFECT_MODEL, 0, 0);
    func_021BE6B0(anime, 0);
    *work->effectPos = pos;
}

/* Returns 1 while the player is in step phase 3 of step kind 0 (ready for a new step). */
int func_021F3868(Gimmick61Work *unusedWork, void *player)
{
    u32 stepKind = func_021A3080(player);

    if (func_021A308C(player) == GIMMICK61_STEP_PHASE_READY && stepKind == 0) {
        return 1;
    }
    return 0;
}
