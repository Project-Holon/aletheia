/*
 * file:     event_entrance_in.c
 * unit:     yes
 * function: func_021BD648, func_021BD6C0, func_021BD704, func_021BD734, func_021BD7A8, func_021BD7E0, func_021BD874, func_021BD8C0, func_021BD904, func_021BD93C, func_021BD94C, func_021BD96C, func_021BD988
 * address:  0x021BD648
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_place_name.c at 0x021BD648 (lane SP3, __FILE__ anchors, certain cut).
 *
 * symbols:
 *   func_02188C58  0x02188C58  thumb  ov021
 *   d_021D9BB0     0x021D9BB0  data  ov021  a4
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021A7E3C  0x021A7E3C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_02161B1C  0x02161B1C  thumb  ov010
 *   func_02161B74  0x02161B74  thumb  ov010
 *   func_021BFE00  0x021BFE00  thumb  ov021
 *   func_0218F0F8  0x0218F0F8  thumb  ov021
 *   func_0218F0E8  0x0218F0E8  thumb  ov021
 *   func_0218F0A8  0x0218F0A8  thumb  ov021
 *   func_0218EC54  0x0218EC54  thumb  ov021
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_02029E08  0x02029E08  thumb
 *   func_02029DFC  0x02029DFC  thumb
 *   func_02012134  0x02012134  thumb
 *   func_0202B580  0x0202B580  thumb
 *   func_0202B434  0x0202B434  thumb
 *   func_0202B438  0x0202B438  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3098  0x021A3098  thumb  ov021
 *   func_02012A30  0x02012A30  thumb
 */

typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef unsigned char u8;

#include "event_entrance_in_types.h"

struct FieldCamera;
struct FieldPlayer;
struct IssSystem;
struct IssDungeonSys;
struct BgmInfo;

extern struct FieldCamera *func_02188C58(FieldMap *fieldMap);
extern GameEvent *func_020122C0(GameSystem *gameSystem, GameEvent *parent, EntranceInEventFunc func, u32 workSize);
extern void *func_020124E8(GameEvent *event);
extern void func_020061E4(u32 seId);
extern GameEvent *func_021A7E3C(EntranceParam *param);
extern void func_02012374(GameEvent *event, GameEvent *child);
extern int func_02161B1C(FieldMap *fieldMap);
extern int func_02161B74(int animHandle);
extern GameEvent *func_021BFE00(int unused, GameSystem *gameSystem, FieldMap *fieldMap);
extern int func_0218F0F8(struct FieldCamera *camera);
extern u32 func_0218F0E8(struct FieldCamera *camera);
extern void func_0218F0A8(struct FieldCamera *camera);
extern void func_0218EC54(struct FieldCamera *camera);
extern GameEvent *func_021BE8D4(GameSystem *gameSystem, FieldMap *fieldMap, int effectId, int wait);
extern int func_02029E08(GameData *gameData, int zoneId);
extern int func_02029DFC(const GameData *gameData);
extern struct IssSystem *func_02012134(GameSystem *gameSystem);
extern struct IssDungeonSys *func_0202B580(struct IssSystem *issSystem);
extern u32 func_0202B434(struct IssDungeonSys *dungeon);
extern u32 func_0202B438(struct IssDungeonSys *dungeon, u32 zoneId);
extern struct FieldPlayer *func_02188CB4(FieldMap *fieldMap);
extern u32 func_021A3098(struct FieldPlayer *player);
extern struct BgmInfo *func_02012A30(const GameData *gameData);
extern void func_02029D44(struct BgmInfo *bgmInfo, GameData *gameData, u16 zoneId, u8 season);
extern GameEvent *func_0202952C(GameSystem *gameSystem, u32 frames);
GameEvent *func_021BD648(EntranceParam *param);
u32 func_021BD6C0(GameEvent *event, int *seq, EntranceInWork *work);
u32 func_021BD704(GameEvent *event, int *seq, EntranceInWork *work);
u32 func_021BD734(GameEvent *event, int *seq, EntranceInWork *work);
u32 func_021BD7A8(GameEvent *event, int *seq, EntranceInWork *work);
u32 func_021BD7E0(GameEvent *event, int *seq, EntranceInWork *work);
u32 func_021BD874(GameEvent *event, int *seq, EntranceInWork *work);
u32 func_021BD8C0(EntranceInWork *work);
int func_021BD904(EntranceInWork *work);
u32 func_021BD93C(EntranceInWork *work);
void func_021BD94C(EntranceInWork *work);
void func_021BD96C(EntranceInWork *work, GameEvent *event);
void func_021BD988(EntranceInWork *work, GameEvent *event);
extern EntranceInEventTable d_021D9BB0;

/* Creates the "in" event for the exit type of the connection. */
GameEvent *func_021BD648(EntranceParam *param)
{
    EntranceInEventTable table = d_021D9BB0;
    int eventKind;
    GameEvent *event;
    EntranceInWork *work;

    switch (param->exitType) {
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
    event = func_020122C0(param->gameSystem, param->event, table.func[eventKind], sizeof(EntranceInWork));
    work = func_020124E8(event);
    work->animHandle = 0;
    work->param = param;
    return event;
}

/* Plain "in" event: music change, door sound, fade out. */
u32 func_021BD6C0(GameEvent *event, int *seq, EntranceInWork *work)
{
    EntranceParam *param = work->param;

    switch (*seq) {
    case 0:
        func_021BD94C(work);
        if (param->exitEffectId != ENTRANCE_EFFECT_NO_DOOR_SE)
            func_020061E4(ENTRANCE_IN_SE_DOOR);
        func_021BD988(work, event);
        (*seq)++;
        break;
    case 1:
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Ground animation "in" event. */
u32 func_021BD704(GameEvent *event, int *seq, EntranceInWork *work)
{
    EntranceParam *param = work->param;

    switch (*seq) {
    case 0:
        func_02012374(event, func_021A7E3C(param));
        (*seq)++;
        break;
    case 1:
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Object animation "in" event: music, the object animation, then the door sound and the fade out. */
u32 func_021BD734(GameEvent *event, int *seq, EntranceInWork *work)
{
    EntranceParam *param = work->param;
    FieldMap *fieldMap = param->fieldMap;

    switch (*seq) {
    case 0:
        if (func_021BD8C0(work))
            func_021BD96C(work, event);
        else
            func_021BD94C(work);
        work->animHandle = func_02161B1C(fieldMap);
        (*seq)++;
        break;
    case 1:
        if (func_02161B74(work->animHandle)) {
            if (param->exitEffectId != ENTRANCE_EFFECT_NO_DOOR_SE)
                func_020061E4(ENTRANCE_IN_SE_DOOR);
            func_021BD988(work, event);
            (*seq)++;
        }
        break;
    case 2:
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Appear "in" event. */
u32 func_021BD7A8(GameEvent *event, int *seq, EntranceInWork *work)
{
    EntranceParam *param = work->param;
    GameSystem *gameSystem = param->gameSystem;
    FieldMap *fieldMap = param->fieldMap;

    switch (*seq) {
    case 0:
        func_02012374(event, func_021BFE00(0, gameSystem, fieldMap));
        (*seq)++;
        break;
    case 1:
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Camera "in" event: waits for the camera move, then the ground animation. */
u32 func_021BD7E0(GameEvent *event, int *seq, EntranceInWork *work)
{
    EntranceParam *param = work->param;
    struct FieldCamera *camera = func_02188C58(param->fieldMap);

    switch (*seq) {
    case 0:
        if (func_0218F0F8(camera) && func_0218F0E8(camera)) {
            func_0218F0A8(camera);
            *seq = 1;
        } else {
            *seq = 2;
        }
        return ENTRANCE_EVENT_YIELD;
    case 1:
        if (!func_0218F0F8(camera)) {
            *seq = 2;
            return ENTRANCE_EVENT_YIELD;
        }
        if (func_0218F0E8(camera))
            break;
        func_0218EC54(camera);
        *seq = 2;
        return ENTRANCE_EVENT_YIELD;
    case 2:
        func_02012374(event, func_021A7E3C(param));
        *seq = 3;
        return ENTRANCE_EVENT_YIELD;
    case 3:
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Fade and sound "in" event: music change, sound effect, fade out. */
u32 func_021BD874(GameEvent *event, int *seq, EntranceInWork *work)
{
    EntranceParam *param = work->param;
    GameSystem *gameSystem = param->gameSystem;
    FieldMap *fieldMap = param->fieldMap;

    switch (*seq) {
    case 0:
        func_021BD94C(work);
        func_020061E4(ENTRANCE_IN_SE_FADE);
        func_02012374(event, func_021BE8D4(gameSystem, fieldMap, 2, 0));
        (*seq)++;
        break;
    case 1:
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Returns 1 when the zone music fades out, 0 when the destination zone music replaces it. */
u32 func_021BD8C0(EntranceInWork *work)
{
    EntranceParam *param = work->param;
    GameData *gameData = param->gameData;

    if (!func_021BD904(work))
        return 0;
    if (func_02029E08(gameData, param->destination.zoneId))
        return 0;
    if (func_021BD93C(work) == 1 && func_02029DFC(gameData) == ENTRANCE_IN_BGM_KEPT)
        return 0;
    return 1;
}

/* Returns 1 when both the old and the new zone have a dungeon sound record. */
int func_021BD904(EntranceInWork *work)
{
    EntranceParam *param = work->param;
    struct IssDungeonSys *dungeon = func_0202B580(func_02012134(param->gameSystem));

    if (func_0202B434(dungeon) && func_0202B438(dungeon, param->currentZoneId) && func_0202B438(dungeon, param->destination.zoneId)) {
        return 1;
    }
    return 0;
}

/* Returns the movement form of the field player. */
u32 func_021BD93C(EntranceInWork *work)
{
    return func_021A3098(func_02188CB4(work->param->fieldMap));
}

/* Posts the zone music of the destination and notes that it was replaced. */
void func_021BD94C(EntranceInWork *work)
{
    EntranceParam *param = work->param;
    GameData *gameData = param->gameData;

    func_02029D44(func_02012A30(gameData), gameData, param->destination.zoneId, param->toSeason);
    param->bgmReplaced = 1;
}

/* Starts the music fade out and notes that it started. */
void func_021BD96C(EntranceInWork *work, GameEvent *event)
{
    EntranceParam *param = work->param;

    func_02012374(event, func_0202952C(param->gameSystem, ENTRANCE_IN_BGM_FADE_FRAMES));
    param->bgmFadeStarted = 1;
}

/* Calls the fade out: the season fade when the season changes, else the fade of the exit effect. */
void func_021BD988(EntranceInWork *work, GameEvent *event)
{
    EntranceParam *param = work->param;
    int seasonChanged = param->seasonChanged;
    GameSystem *gameSystem = param->gameSystem;
    FieldMap *fieldMap = param->fieldMap;

    if (seasonChanged != 0) {
        func_02012374(event, func_021BE8D4(gameSystem, fieldMap, 0, 0));
    } else {
        func_02012374(event, func_021BE8D4(gameSystem, fieldMap, param->exitEffectId, 0));
    }
}
