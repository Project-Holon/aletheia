/*
 * file:     unit_021F36C0.c
 * unit:     yes
 * function: func_021F36C0, func_021F3724, func_021F374C, func_021F37B8, func_021F37D8, func_021F37E4, func_021F3850, func_021F3870, func_021F3880, func_021F3938, func_021F3950, func_021F399C
 * address:  0x021F36C0
 * region:   ov060
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
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02189764  0x02189764  thumb  ov021
 *   func_021BE310  0x021BE310  thumb  ov021
 *   d_021F3A34     0x021F3A34  data  a4
 *   func_021BE418  0x021BE418  thumb  ov021
 *   func_021897A0  0x021897A0  thumb  ov021
 *   func_021897BC  0x021897BC  thumb  ov021
 *   func_021BE580  0x021BE580  thumb  ov021
 *   func_021F39F4  0x021F39F4  thumb  ov060
 *   func_021BE480  0x021BE480  thumb  ov021
 *   func_021BE4A4  0x021BE4A4  thumb  ov021
 *   func_021BE4B4  0x021BE4B4  thumb  ov021
 *   _s32_div_f  0x0209C0A4  arm
 *   func_02012B80  0x02012B80  thumb
 *   func_02012B58  0x02012B58  thumb
 *   GAME_DATA_GetEnterMode  0x02012B40  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_020127AC  0x020127AC  thumb
 *   func_0200BDF8  0x0200BDF8  thumb
 *   func_0200BDFC  0x0200BDFC  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_021BE700  0x021BE700  thumb  ov021
 *   func_021BE674  0x021BE674  thumb  ov021
 *   func_021BE6B8  0x021BE6B8  thumb  ov021
 *   func_021BE6B0  0x021BE6B0  thumb  ov021
 *   func_021BE6CC  0x021BE6CC  thumb  ov021
 */
#include "unit_021F36C0_types.h"
#include "../ov011/intrude_comm_types.h"

struct GameData;
struct GameSystem;
struct GameComm;
struct BattleRec;

extern u16 func_02188C84(void *fieldMap);
extern void *func_02188D2C(void *fieldMap);
extern struct GameSystem *func_02188C80(void *fieldMap);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern u8 *func_02012EC4(struct GameData *gameData);
extern struct GameComm *func_02012138(const struct GameSystem *gameSystem);
extern Gimmick60Work *func_02189764(void *fieldMap, int id, int heapId, int size);
extern void func_021BE310(void *expObj, void *unitDesc, int b);
extern void func_021BE418(void *expObj, unsigned short unit);
extern void func_021897A0(void *fieldMap, int id);
extern Gimmick60Work *func_021897BC(void *fieldMap, int idx);
extern void func_021BE580(void *expObj);
extern void func_021F39F4(Gimmick60Work *work, void *expObj);
extern VecFx32 *func_021BE480(void *expObj, int unit, u16 model);
extern void func_021BE4A4(void *expObj, int unit, int model, int visible);
extern void func_021BE4B4(void *expObj, int unit, u16 model, int hidden);
extern u8 func_02012B80(const struct GameData *gameData);
extern u8 func_02012B58(const struct GameData *gameData);
extern u8 GAME_DATA_GetEnterMode(const struct GameData *gameData);
extern void *func_020127B8(struct GameData *gameData);
extern void *func_020127AC(struct GameData *gameData, u32 slot);
extern u16 func_0200BDF8(struct BattleRec *record);
extern u16 func_0200BDFC(struct BattleRec *record);
extern unsigned int func_02026454(struct GameComm *gameComm);
extern IntrudeCommSys *func_02026474(struct GameComm *gameComm);
extern void func_021BE700(void *expObj, int unit, int model, int animeIdx, int enabled);
extern u8 *func_021BE674(void *expObj, int unit, int model, u16 animeIdx);
extern void func_021BE6B8(u8 *anime, int loop);
extern void func_021BE6B0(u8 *anime, int paused);
extern void func_021BE6CC(void *expObj, int unit, int model, int animeIdx, int frame);
void func_021F36C0(void *fieldMap);
void func_021F3724(void *fieldMap);
void func_021F374C(void *fieldMap);
void func_021F37B8(void *fieldMap, VecFx32 *pos);
int func_021F37D8(void *fieldMap);
void func_021F37E4(Gimmick60Work *work, void *fieldMap, struct GameData *gameData, IntrudeCommSys *commSys);
void func_021F3850(void *expObj);
int func_021F3870(int count);
u8 func_021F3880(struct GameData *gameData, void *expObj, IntrudeCommSys *unusedCommSys);
IntrudeCommSys *func_021F3938(struct GameComm *gameComm);
void func_021F3950(void *unused, void *expObj);
void func_021F399C(Gimmick60Work *work, void *expObj, VecFx32 *pos);
extern char d_021F3A34[];

void func_021F36C0(void *fieldMap)
{
    u32 heapId;
    void *expObj;
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    IntrudeCommSys *commSys;
    Gimmick60Work *work;

    heapId = func_02188C84(fieldMap);
    expObj = func_02188D2C(fieldMap);
    gameSystem = func_02188C80(fieldMap);
    gameData = func_020120F4(gameSystem);
    func_02012EC4(gameData);
    commSys = func_021F3938(func_02012138(gameSystem));
    work = func_02189764(fieldMap, 0, heapId, 4);
    func_021BE310(expObj, d_021F3A34, 0);
    func_021F37E4(work, fieldMap, gameData, commSys);
    func_021F3950(work, expObj);
}

void func_021F3724(void *fieldMap)
{
    func_02012EC4(func_020120F4(func_02188C80(fieldMap)));
    func_021BE418(func_02188D2C(fieldMap), 0);
    func_021897A0(fieldMap, 0);
}

void func_021F374C(void *fieldMap)
{
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    void *expObj;
    Gimmick60Work *work;
    IntrudeCommSys *commSys;

    gameSystem = func_02188C80(fieldMap);
    gameData = func_020120F4(gameSystem);
    func_02012EC4(gameData);
    expObj = func_02188D2C(fieldMap);
    work = func_021897BC(fieldMap, 0);
    commSys = func_021F3938(func_02012138(gameSystem));
    if (commSys != 0) {
        if (commSys->localPeer.intrudeId != work->shownIntrudeId) {
            func_021F3850(expObj);
            work->shownIntrudeId = func_021F3880(gameData, expObj, commSys);
        }
    }
    func_021BE580(expObj);
    if (work->effectActive != 0) {
        func_021F39F4(work, expObj);
    }
}

/* Shows the effect model at pos; the sub display polls func_021F37D8 until it ends. */
void func_021F37B8(void *fieldMap, VecFx32 *pos)
{
    Gimmick60Work *work;
    void *expObj;

    work = func_021897BC(fieldMap, 0);
    expObj = func_02188D2C(fieldMap);
    func_021F399C(work, expObj, pos);
}

/* Returns nonzero while the effect model plays. */
int func_021F37D8(void *fieldMap)
{
    return func_021897BC(fieldMap, 0)->effectActive;
}

/* Hides every model, then shows the gauges of the visited player. */
void func_021F37E4(Gimmick60Work *work, void *fieldMap, struct GameData *gameData, IntrudeCommSys *commSys)
{
    void *expObj;
    int model;
    VecFx32 *pos;

    expObj = func_02188D2C(fieldMap);
    for (model = 0; model < GIMMICK60_MODEL_COUNT; model++) {
        pos = func_021BE480(expObj, 0, model);
        pos->x = 0x1F8000;
        pos->y = 0x20000;
        pos->z = 0x1B8000;
        func_021BE4A4(expObj, 0, (u16)model, 1);
        func_021BE4B4(expObj, 0, model, 1);
    }
    work->shownIntrudeId = func_021F3880(gameData, expObj, commSys);
}

void func_021F3850(void *expObj)
{
    int model;

    for (model = 0; model < GIMMICK60_GAUGE_MODEL_COUNT; model++) {
        func_021BE4B4(expObj, 0, (u16)model, 1);
    }
}

/* One gauge step per three counts, at most the last step. */
int func_021F3870(int count)
{
    int step = count / 3;

    if (step > GIMMICK60_GAUGE_STEP_COUNT - 1) {
        step = GIMMICK60_GAUGE_STEP_COUNT - 1;
    }
    return step;
}

/* Shows one step of each gauge row in the column of the visited player.
 * Returns the intrude ID that is shown. */
u8 func_021F3880(struct GameData *gameData, void *expObj, IntrudeCommSys *unusedCommSys)
{
    int intrudeId;
    int column;
    int highStep;
    int lowStep;
    struct BattleRec *record;
    VecFx32 *pos;

    intrudeId = func_02012B80(gameData);
    column = intrudeId - func_02012B58(gameData);
    if (column < 0) {
        column += GAME_DATA_GetEnterMode(gameData);
    }
    if (intrudeId == func_02012B58(gameData)) {
        record = func_020127B8(gameData);
    } else {
        record = func_020127AC(gameData, intrudeId);
    }
    highStep = func_021F3870(func_0200BDF8(record));
    lowStep = func_021F3870(func_0200BDFC(record));
    pos = func_021BE480(expObj, 0, highStep + GIMMICK60_GAUGE_STEP_COUNT);
    column = (column << 22) + 0x1F8000;
    pos->x = column;
    pos->y = 0x20000;
    pos->z = 0x1B8000;
    pos = func_021BE480(expObj, 0, lowStep);
    pos->x = column;
    pos->y = 0x20000;
    pos->z = 0x1B8000;
    func_021BE4B4(expObj, 0, (u16)(highStep + GIMMICK60_GAUGE_STEP_COUNT), 0);
    func_021BE4B4(expObj, 0, (u16)lowStep, 0);
    return intrudeId;
}

/* The intrude communication work, or 0 when the game comm is of another kind. */
IntrudeCommSys *func_021F3938(struct GameComm *gameComm)
{
    if (func_02026454(gameComm) == 2) {
        return func_02026474(gameComm);
    }
    return 0;
}

/* Hides the effect model and sets its animes to run once. */
void func_021F3950(void *unused, void *expObj)
{
    int animeIdx;
    u8 *anime;

    func_021BE4B4(expObj, 0, GIMMICK60_EFFECT_MODEL, 1);
    for (animeIdx = 0; animeIdx < GIMMICK60_EFFECT_ANIME_COUNT; animeIdx++) {
        func_021BE700(expObj, 0, GIMMICK60_EFFECT_MODEL, (u16)animeIdx, 1);
        anime = func_021BE674(expObj, 0, GIMMICK60_EFFECT_MODEL, (u16)animeIdx);
        func_021BE6B8(anime, 0);
        func_021BE6B0(anime, 0);
    }
}

/* Moves the effect model to pos, restarts its animes and shows it. */
void func_021F399C(Gimmick60Work *work, void *expObj, VecFx32 *pos)
{
    int animeIdx;

    func_021BE4B4(expObj, 0, GIMMICK60_EFFECT_MODEL, 0);
    for (animeIdx = 0; animeIdx < GIMMICK60_EFFECT_ANIME_COUNT; animeIdx++) {
        func_021BE6CC(expObj, 0, GIMMICK60_EFFECT_MODEL, (u16)animeIdx, 0);
    }
    *func_021BE480(expObj, 0, GIMMICK60_EFFECT_MODEL) = *pos;
    work->effectActive = 1;
}
