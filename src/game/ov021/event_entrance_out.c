/*
 * file:     event_entrance_out.c
 * unit:     yes
 * function: func_021BD9BC, func_021BDA30, func_021BDA70, func_021BDAA8, func_021BDB1C, func_021BDB5C, func_021BDB9C, func_021BDBF8, func_021BDC0C, func_021BDC2C, func_021BDC80
 * address:  0x021BD9BC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_place_name.c at 0x021BD9BC (lane SP3, __FILE__ anchors, certain cut).
 *
 * symbols:
 *   func_02188C58  0x02188C58  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012374  0x02012374  thumb
 *   d_021D9BC8     0x021D9BC8  data  ov021  a4
 *   func_021A7B20  0x021A7B20  thumb  ov021
 *   func_021618E0  0x021618E0  thumb  ov010
 *   func_021BF644  0x021BF644  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012A30  0x02012A30  thumb
 *   func_02029D7C  0x02029D7C  thumb
 *   func_02188D20  0x02188D20  thumb  ov021
 *   func_021BC550 0x021BC550 thumb ov021
 */

typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef unsigned char u8;

#include "event_entrance_in_types.h"
#include "field_place_name_types.h"

struct BgmInfo;

extern struct FieldCamera *func_02188C58(FieldMap *fieldMap);
extern GameEvent *func_020122C0(GameSystem *gameSystem, GameEvent *parent, EntranceOutEventFunc func, u32 workSize);
extern void *func_020124E8(GameEvent *event);
extern void func_02012374(GameEvent *event, GameEvent *child);
extern struct BgmInfo *func_02012A30(const GameData *gameData);
extern GameEvent *func_021A7B20(EntranceParam *param);
extern GameEvent *func_021618E0(GameSystem *gameSystem, FieldMap *fieldMap);
extern GameEvent *func_021BF644(int unused, GameSystem *gameSystem, FieldMap *fieldMap);
extern GameEvent *func_021BE92C(GameSystem *gameSystem, FieldMap *fieldMap, int effectId, int wait, int initScreen, u8 fromSeason, u8 toSeason);
extern u32 func_02029D7C(struct BgmInfo *bgmInfo, GameData *gameData);
extern GameEvent *func_020294C0(GameSystem *gameSystem, u32 frames);
extern struct FieldPlaceName *func_02188D20(FieldMap *fieldMap);
void func_021BC550(struct FieldPlaceName *placeName, int zoneId);
GameEvent *func_021BD9BC(EntranceParam *param);
u32 func_021BDA30(GameEvent *event, int *seq, EntranceOutWork *work);
u32 func_021BDA70(GameEvent *event, int *seq, EntranceOutWork *work);
u32 func_021BDAA8(GameEvent *event, int *seq, EntranceOutWork *work);
u32 func_021BDB1C(GameEvent *event, int *seq, EntranceOutWork *work);
u32 func_021BDB5C(GameEvent *event, int *seq, EntranceOutWork *work);
u32 func_021BDB9C(GameEvent *event, int *seq, EntranceOutWork *work);
int func_021BDBF8(EntranceOutWork *work);
void func_021BDC0C(EntranceOutWork *work, GameEvent *event);
void func_021BDC2C(EntranceOutWork *work, GameEvent *event);
void func_021BDC80(EntranceOutWork *work);
extern const EntranceOutEventTable d_021D9BC8;

/* Creates the "out" event for the exit type of the destination connection. */
GameEvent *func_021BD9BC(EntranceParam *param)
{
    EntranceOutEventTable table = d_021D9BC8;
    u32 eventKind;
    GameEvent *event;

    switch (param->destExitType) {
    case ENTRANCE_EXIT_TYPE_DEFAULT:
        eventKind = ENTRANCE_EVENT_PLAIN;
        break;
    case ENTRANCE_EXIT_TYPE_PLAIN:
        eventKind = ENTRANCE_EVENT_PLAIN;
        break;
    case ENTRANCE_EXIT_TYPE_OBJECT_ANIME:
        eventKind = ENTRANCE_EVENT_OBJECT_ANIME;
        break;
    case ENTRANCE_EXIT_TYPE_GROUND_ANIME:
        eventKind = ENTRANCE_EVENT_GROUND_ANIME;
        break;
    case ENTRANCE_EXIT_TYPE_OBJECT_ANIME_B:
        eventKind = ENTRANCE_EVENT_OBJECT_ANIME;
        break;
    case ENTRANCE_EXIT_TYPE_APPEAR:
        eventKind = ENTRANCE_EVENT_APPEAR;
        break;
    case ENTRANCE_EXIT_TYPE_FADE_SE:
        eventKind = ENTRANCE_EVENT_FADE_SE;
        break;
    default:
        eventKind = ENTRANCE_EVENT_CAMERA;
        break;
    }
    event = func_020122C0(param->gameSystem, param->event, table.func[eventKind], sizeof(EntranceOutWork));
    ((EntranceOutWork *)func_020124E8(event))->param = param;
    return event;
}

/* Plain "out" event: fade in, then the place name. */
u32 func_021BDA30(GameEvent *event, int *seq, EntranceOutWork *work)
{
    EntranceParam *param = work->param;

    switch (*seq) {
    case 0:
        if (param->bgmReplaced != 0)
            func_021BDBF8(work);
        func_021BDC2C(work, event);
        (*seq)++;
        break;
    case 1:
        func_021BDC80(work);
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Ground animation "out" event. */
u32 func_021BDA70(GameEvent *event, int *seq, EntranceOutWork *work)
{
    EntranceParam *param = work->param;

    switch (*seq) {
    case 0:
        func_02012374(event, func_021A7B20(param));
        (*seq)++;
        break;
    case 1:
        func_021BDC80(work);
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Object animation "out" event: fade in, music, the object animation, then the place name. */
u32 func_021BDAA8(GameEvent *event, int *seq, EntranceOutWork *work)
{
    EntranceParam *param = work->param;
    GameSystem *gameSystem = param->gameSystem;
    FieldMap *fieldMap = param->fieldMap;

    switch (*seq) {
    case 0:
        func_021BDC2C(work, event);
        (*seq)++;
        break;
    case 1:
        if (param->bgmReplaced != 0)
            func_021BDBF8(work);
        else if (param->bgmFadeStarted != 0)
            func_021BDC0C(work, event);
        (*seq)++;
        break;
    case 2:
        func_02012374(event, func_021618E0(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 3:
        func_021BDC80(work);
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Appear "out" event. */
u32 func_021BDB1C(GameEvent *event, int *seq, EntranceOutWork *work)
{
    EntranceParam *param = work->param;
    GameSystem *gameSystem = param->gameSystem;
    FieldMap *fieldMap = param->fieldMap;

    switch (*seq) {
    case 0:
        func_02012374(event, func_021BF644(0, gameSystem, fieldMap));
        (*seq)++;
        break;
    case 1:
        func_021BDC80(work);
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Camera "out" event: the ground animation, then the place name. */
u32 func_021BDB5C(GameEvent *event, int *seq, EntranceOutWork *work)
{
    EntranceParam *param = work->param;

    func_02188C58(param->fieldMap);
    switch (*seq) {
    case 0:
        func_02012374(event, func_021A7B20(param));
        (*seq)++;
        break;
    case 1:
        func_021BDC80(work);
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Fade and sound "out" event: music, then the fade in. */
u32 func_021BDB9C(GameEvent *event, int *seq, EntranceOutWork *work)
{
    EntranceParam *param = work->param;
    GameSystem *gameSystem = param->gameSystem;
    FieldMap *fieldMap = param->fieldMap;

    switch (*seq) {
    case 0:
        if (param->bgmReplaced != 0)
            func_021BDBF8(work);
        (*seq)++;
        break;
    case 1:
        func_02012374(event, func_021BE92C(gameSystem, fieldMap, 2, 0, 0, 0, 0));
        (*seq)++;
        break;
    case 2:
        func_021BDC80(work);
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Posts the fade in of the zone music replaced by the "in" event. */
int func_021BDBF8(EntranceOutWork *work)
{
    return func_02029D7C(func_02012A30(work->param->gameData), work->param->gameData);
}

/* Starts the music fade in. */
void func_021BDC0C(EntranceOutWork *work, GameEvent *event)
{
    EntranceParam *param = work->param;
    GameSystem *gameSystem = param->gameSystem;

    func_02012A30(param->gameData);
    func_02012374(event, func_020294C0(gameSystem, ENTRANCE_OUT_BGM_FADE_FRAMES));
}

/* Calls the fade in: the season fade when the season changes, else the fade of the entrance effect. */
void func_021BDC2C(EntranceOutWork *work, GameEvent *event)
{
    EntranceParam *param = work->param;
    GameSystem *gameSystem = param->gameSystem;
    FieldMap *fieldMap = param->fieldMap;

    if (param->seasonChanged != 0)
        func_02012374(event, func_021BE92C(gameSystem, fieldMap, 3, 0, 0, param->fromSeasonIndex, param->toSeason));
    else
        func_02012374(event, func_021BE92C(gameSystem, fieldMap, param->entranceEffectId, 0, 1, 0, 0));
}

/* Shows the place name of the destination zone. */
void func_021BDC80(EntranceOutWork *work)
{
    EntranceParam *param = work->param;

    func_021BC550(func_02188D20(param->fieldMap), (s16)param->destination.zoneId);
}
