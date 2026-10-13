/*
 * file:     event_entrance_in.c
 * unit:     yes
 * function: EVENT_ENTRANCE_IN_Create, EVENT_ENTRANCE_IN_RunPlain, EVENT_ENTRANCE_IN_RunGroundAnime, EVENT_ENTRANCE_IN_RunObjectAnime, EVENT_ENTRANCE_IN_RunAppear, EVENT_ENTRANCE_IN_RunCamera, EVENT_ENTRANCE_IN_RunFadeSe, EVENT_ENTRANCE_IN_ShouldFadeBgm, EVENT_ENTRANCE_IN_IsDungeonTransition, EVENT_ENTRANCE_IN_GetPlayerForm, EVENT_ENTRANCE_IN_ReplaceBgm, EVENT_ENTRANCE_IN_StartBgmFadeOut, EVENT_ENTRANCE_IN_CallFadeOut
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
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   gEntranceInEventTable     0x021D9BB0  data  ov021  a4
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021A7E3C  0x021A7E3C  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   EVENT_FIELD_PROCLINK_IsHopDone  0x02161B1C  thumb  ov010
 *   EVENT_FIELD_PROCLINK_IsAnimFlagSet  0x02161B74  thumb  ov010
 *   EVENT_DISAPPEAR_CreateRisingSpin  0x021BFE00  thumb  ov021
 *   FIELD_CAMERA_HasDelay  0x0218F0F8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   FIELD_SOUND_SYSTEM_HasZoneBgmOverride  0x02029E08  thumb
 *   FIELD_SOUND_SYSTEM_GetFinalBgm  0x02029DFC  thumb
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   func_0202B580  0x0202B580  thumb
 *   ISS_DUNGEON_SYS_IsActive  0x0202B434  thumb
 *   ISS_DUNGEON_SYS_HasRecord  0x0202B438  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetFormCode  0x021A3098  thumb  ov021
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_StartFadeOutTask  0x0202952C  thumb  arm9
 *   FIELD_SOUND_SYSTEM_PostZoneBgmReplace  0x02029D44  thumb  arm9
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

extern struct FieldCamera *FIELDMAP_GetCamera(FieldMap *fieldMap);
extern GameEvent *func_020122C0(GameSystem *gameSystem, GameEvent *parent, EntranceInEventFunc func, u32 workSize);
extern void *func_020124E8(GameEvent *event);
extern void func_020061E4(u32 seId);
extern GameEvent *func_021A7E3C(EntranceParam *param);
extern void GAME_EVENT_CallEvent(GameEvent *event, GameEvent *child);
extern int EVENT_FIELD_PROCLINK_IsHopDone(FieldMap *fieldMap);
extern int EVENT_FIELD_PROCLINK_IsAnimFlagSet(int animHandle);
extern GameEvent *EVENT_DISAPPEAR_CreateRisingSpin(int unused, GameSystem *gameSystem, FieldMap *fieldMap);
extern int FIELD_CAMERA_HasDelay(struct FieldCamera *camera);
extern u32 FIELD_CAMERA_IsDelayEnabled(struct FieldCamera *camera);
extern void FIELD_CAMERA_EndDelay(struct FieldCamera *camera);
extern void FIELD_CAMERA_StopTargetTrace(struct FieldCamera *camera);
extern GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeOut(GameSystem *gameSystem, FieldMap *fieldMap, int effectId, int wait);
extern int FIELD_SOUND_SYSTEM_HasZoneBgmOverride(GameData *gameData, int zoneId);
extern int FIELD_SOUND_SYSTEM_GetFinalBgm(const GameData *gameData);
extern struct IssSystem *GAMESYSTEM_GetIssSystem(GameSystem *gameSystem);
extern struct IssDungeonSys *func_0202B580(struct IssSystem *issSystem);
extern u32 ISS_DUNGEON_SYS_IsActive(struct IssDungeonSys *dungeon);
extern u32 ISS_DUNGEON_SYS_HasRecord(struct IssDungeonSys *dungeon, u32 zoneId);
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(FieldMap *fieldMap);
extern u32 FIELD_PLAYER_GetFormCode(struct FieldPlayer *player);
extern struct BgmInfo *GAME_DATA_GetBgmInfo(const GameData *gameData);
extern void FIELD_SOUND_SYSTEM_PostZoneBgmReplace(struct BgmInfo *bgmInfo, GameData *gameData, u16 zoneId, u8 season);
extern GameEvent *FIELD_SOUND_SYSTEM_StartFadeOutTask(GameSystem *gameSystem, u32 frames);
GameEvent *EVENT_ENTRANCE_IN_Create(EntranceParam *param);
u32 EVENT_ENTRANCE_IN_RunPlain(GameEvent *event, int *seq, EntranceInWork *work);
u32 EVENT_ENTRANCE_IN_RunGroundAnime(GameEvent *event, int *seq, EntranceInWork *work);
u32 EVENT_ENTRANCE_IN_RunObjectAnime(GameEvent *event, int *seq, EntranceInWork *work);
u32 EVENT_ENTRANCE_IN_RunAppear(GameEvent *event, int *seq, EntranceInWork *work);
u32 EVENT_ENTRANCE_IN_RunCamera(GameEvent *event, int *seq, EntranceInWork *work);
u32 EVENT_ENTRANCE_IN_RunFadeSe(GameEvent *event, int *seq, EntranceInWork *work);
u32 EVENT_ENTRANCE_IN_ShouldFadeBgm(EntranceInWork *work);
int EVENT_ENTRANCE_IN_IsDungeonTransition(EntranceInWork *work);
u32 EVENT_ENTRANCE_IN_GetPlayerForm(EntranceInWork *work);
void EVENT_ENTRANCE_IN_ReplaceBgm(EntranceInWork *work);
void EVENT_ENTRANCE_IN_StartBgmFadeOut(EntranceInWork *work, GameEvent *event);
void EVENT_ENTRANCE_IN_CallFadeOut(EntranceInWork *work, GameEvent *event);
extern EntranceInEventTable gEntranceInEventTable;

/* Creates the "in" event for the exit type of the connection. */
GameEvent *EVENT_ENTRANCE_IN_Create(EntranceParam *param)
{
    EntranceInEventTable table = gEntranceInEventTable;
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
u32 EVENT_ENTRANCE_IN_RunPlain(GameEvent *event, int *seq, EntranceInWork *work)
{
    EntranceParam *param = work->param;

    switch (*seq) {
    case 0:
        EVENT_ENTRANCE_IN_ReplaceBgm(work);
        if (param->exitEffectId != ENTRANCE_EFFECT_NO_DOOR_SE)
            func_020061E4(ENTRANCE_IN_SE_DOOR);
        EVENT_ENTRANCE_IN_CallFadeOut(work, event);
        (*seq)++;
        break;
    case 1:
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Ground animation "in" event. */
u32 EVENT_ENTRANCE_IN_RunGroundAnime(GameEvent *event, int *seq, EntranceInWork *work)
{
    EntranceParam *param = work->param;

    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, func_021A7E3C(param));
        (*seq)++;
        break;
    case 1:
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Object animation "in" event: music, the object animation, then the door sound and the fade out. */
u32 EVENT_ENTRANCE_IN_RunObjectAnime(GameEvent *event, int *seq, EntranceInWork *work)
{
    EntranceParam *param = work->param;
    FieldMap *fieldMap = param->fieldMap;

    switch (*seq) {
    case 0:
        if (EVENT_ENTRANCE_IN_ShouldFadeBgm(work))
            EVENT_ENTRANCE_IN_StartBgmFadeOut(work, event);
        else
            EVENT_ENTRANCE_IN_ReplaceBgm(work);
        work->animHandle = EVENT_FIELD_PROCLINK_IsHopDone(fieldMap);
        (*seq)++;
        break;
    case 1:
        if (EVENT_FIELD_PROCLINK_IsAnimFlagSet(work->animHandle)) {
            if (param->exitEffectId != ENTRANCE_EFFECT_NO_DOOR_SE)
                func_020061E4(ENTRANCE_IN_SE_DOOR);
            EVENT_ENTRANCE_IN_CallFadeOut(work, event);
            (*seq)++;
        }
        break;
    case 2:
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Appear "in" event. */
u32 EVENT_ENTRANCE_IN_RunAppear(GameEvent *event, int *seq, EntranceInWork *work)
{
    EntranceParam *param = work->param;
    GameSystem *gameSystem = param->gameSystem;
    FieldMap *fieldMap = param->fieldMap;

    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_DISAPPEAR_CreateRisingSpin(0, gameSystem, fieldMap));
        (*seq)++;
        break;
    case 1:
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Camera "in" event: waits for the camera move, then the ground animation. */
u32 EVENT_ENTRANCE_IN_RunCamera(GameEvent *event, int *seq, EntranceInWork *work)
{
    EntranceParam *param = work->param;
    struct FieldCamera *camera = FIELDMAP_GetCamera(param->fieldMap);

    switch (*seq) {
    case 0:
        if (FIELD_CAMERA_HasDelay(camera) && FIELD_CAMERA_IsDelayEnabled(camera)) {
            FIELD_CAMERA_EndDelay(camera);
            *seq = 1;
        } else {
            *seq = 2;
        }
        return ENTRANCE_EVENT_YIELD;
    case 1:
        if (!FIELD_CAMERA_HasDelay(camera)) {
            *seq = 2;
            return ENTRANCE_EVENT_YIELD;
        }
        if (FIELD_CAMERA_IsDelayEnabled(camera))
            break;
        FIELD_CAMERA_StopTargetTrace(camera);
        *seq = 2;
        return ENTRANCE_EVENT_YIELD;
    case 2:
        GAME_EVENT_CallEvent(event, func_021A7E3C(param));
        *seq = 3;
        return ENTRANCE_EVENT_YIELD;
    case 3:
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Fade and sound "in" event: music change, sound effect, fade out. */
u32 EVENT_ENTRANCE_IN_RunFadeSe(GameEvent *event, int *seq, EntranceInWork *work)
{
    EntranceParam *param = work->param;
    GameSystem *gameSystem = param->gameSystem;
    FieldMap *fieldMap = param->fieldMap;

    switch (*seq) {
    case 0:
        EVENT_ENTRANCE_IN_ReplaceBgm(work);
        func_020061E4(ENTRANCE_IN_SE_FADE);
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 2, 0));
        (*seq)++;
        break;
    case 1:
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Returns 1 when the zone music fades out, 0 when the destination zone music replaces it. */
u32 EVENT_ENTRANCE_IN_ShouldFadeBgm(EntranceInWork *work)
{
    EntranceParam *param = work->param;
    GameData *gameData = param->gameData;

    if (!EVENT_ENTRANCE_IN_IsDungeonTransition(work))
        return 0;
    if (FIELD_SOUND_SYSTEM_HasZoneBgmOverride(gameData, param->destination.zoneId))
        return 0;
    if (EVENT_ENTRANCE_IN_GetPlayerForm(work) == 1 && FIELD_SOUND_SYSTEM_GetFinalBgm(gameData) == ENTRANCE_IN_BGM_KEPT)
        return 0;
    return 1;
}

/* Returns 1 when both the old and the new zone have a dungeon sound record. */
int EVENT_ENTRANCE_IN_IsDungeonTransition(EntranceInWork *work)
{
    EntranceParam *param = work->param;
    struct IssDungeonSys *dungeon = func_0202B580(GAMESYSTEM_GetIssSystem(param->gameSystem));

    if (ISS_DUNGEON_SYS_IsActive(dungeon) && ISS_DUNGEON_SYS_HasRecord(dungeon, param->currentZoneId) && ISS_DUNGEON_SYS_HasRecord(dungeon, param->destination.zoneId)) {
        return 1;
    }
    return 0;
}

/* Returns the movement form of the field player. */
u32 EVENT_ENTRANCE_IN_GetPlayerForm(EntranceInWork *work)
{
    return FIELD_PLAYER_GetFormCode(FIELDMAP_GetFieldPlayer(work->param->fieldMap));
}

/* Posts the zone music of the destination and notes that it was replaced. */
void EVENT_ENTRANCE_IN_ReplaceBgm(EntranceInWork *work)
{
    EntranceParam *param = work->param;
    GameData *gameData = param->gameData;

    FIELD_SOUND_SYSTEM_PostZoneBgmReplace(GAME_DATA_GetBgmInfo(gameData), gameData, param->destination.zoneId, param->toSeason);
    param->bgmReplaced = 1;
}

/* Starts the music fade out and notes that it started. */
void EVENT_ENTRANCE_IN_StartBgmFadeOut(EntranceInWork *work, GameEvent *event)
{
    EntranceParam *param = work->param;

    GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartFadeOutTask(param->gameSystem, ENTRANCE_IN_BGM_FADE_FRAMES));
    param->bgmFadeStarted = 1;
}

/* Calls the fade out: the season fade when the season changes, else the fade of the exit effect. */
void EVENT_ENTRANCE_IN_CallFadeOut(EntranceInWork *work, GameEvent *event)
{
    EntranceParam *param = work->param;
    int seasonChanged = param->seasonChanged;
    GameSystem *gameSystem = param->gameSystem;
    FieldMap *fieldMap = param->fieldMap;

    if (seasonChanged != 0) {
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 0, 0));
    } else {
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, param->exitEffectId, 0));
    }
}
