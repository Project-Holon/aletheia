/*
 * file:     event_entrance_out.c
 * unit:     yes
 * function: EVENT_ENTRANCE_OUT_Create, EVENT_ENTRANCE_OUT_RunPlain, EVENT_ENTRANCE_OUT_RunGroundAnime, EVENT_ENTRANCE_OUT_RunObjectAnime, EVENT_ENTRANCE_OUT_RunAppear, EVENT_ENTRANCE_OUT_RunCamera, EVENT_ENTRANCE_OUT_RunFadeSe, EVENT_ENTRANCE_OUT_PostBgmFadeIn, EVENT_ENTRANCE_OUT_StartBgmFadeIn, EVENT_ENTRANCE_OUT_CallFadeIn, EVENT_ENTRANCE_OUT_ShowPlaceName
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
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   gEntranceOutEventTable     0x021D9BC8  data  ov021  a4
 *   FIELD_GROUND_ANIME_CreateA  0x021A7B20  thumb  ov021
 *   EVENT_FIELD_PROCLINK_StartObjAnim  0x021618E0  thumb  ov010
 *   EVENT_APPEAR_CreateDescendingSpin  0x021BF644  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   FIELD_SOUND_SYSTEM_PostFadeIn  0x02029D7C  thumb
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   FIELD_PLACE_NAME_OnZoneChange 0x021BC550 thumb ov021
 *   FIELD_SOUND_SYSTEM_StartFadeInTask  0x020294C0  thumb  arm9
 */

#include "../types.h"

#include "event_entrance_in_types.h"
#include "field_place_name_types.h"

struct BgmInfo;

#include "fieldmap.h"
#include "../arm9/game_event.h"
#include "../arm9/game_data.h"
struct GroundAnimeArgs;
#include "field_ground_anime.h"
struct GameSystem;
struct GameEvent;
typedef int Bool;
#include "../ov010/event_field_proclink.h"
struct FieldMap;
#include "event_appear.h"
#include "event_fieldmap_control.h"
#include "../arm9/field_sound_system.h"
#include "field_place_name.h"
GameEvent *EVENT_ENTRANCE_OUT_Create(EntranceParam *param);
u32 EVENT_ENTRANCE_OUT_RunPlain(GameEvent *event, int *seq, EntranceOutWork *work);
u32 EVENT_ENTRANCE_OUT_RunGroundAnime(GameEvent *event, int *seq, EntranceOutWork *work);
u32 EVENT_ENTRANCE_OUT_RunObjectAnime(GameEvent *event, int *seq, EntranceOutWork *work);
u32 EVENT_ENTRANCE_OUT_RunAppear(GameEvent *event, int *seq, EntranceOutWork *work);
u32 EVENT_ENTRANCE_OUT_RunCamera(GameEvent *event, int *seq, EntranceOutWork *work);
u32 EVENT_ENTRANCE_OUT_RunFadeSe(GameEvent *event, int *seq, EntranceOutWork *work);
void EVENT_ENTRANCE_OUT_PostBgmFadeIn(EntranceOutWork *work);
void EVENT_ENTRANCE_OUT_StartBgmFadeIn(EntranceOutWork *work, GameEvent *event);
void EVENT_ENTRANCE_OUT_CallFadeIn(EntranceOutWork *work, GameEvent *event);
void EVENT_ENTRANCE_OUT_ShowPlaceName(EntranceOutWork *work);
extern const EntranceOutEventTable gEntranceOutEventTable;

/* Creates the "out" event for the exit type of the destination connection. */
GameEvent *EVENT_ENTRANCE_OUT_Create(EntranceParam *param)
{
    EntranceOutEventTable table = gEntranceOutEventTable;
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
    event = GAME_EVENT_Create(param->gameSystem, param->event, (GameEventFunc)table.func[eventKind], sizeof(EntranceOutWork));
    ((EntranceOutWork *)GAME_EVENT_GetWork(event))->param = param;
    return event;
}

/* Plain "out" event: fade in, then the place name. */
u32 EVENT_ENTRANCE_OUT_RunPlain(GameEvent *event, int *seq, EntranceOutWork *work)
{
    EntranceParam *param = work->param;

    switch (*seq) {
    case 0:
        if (param->bgmReplaced != 0)
            EVENT_ENTRANCE_OUT_PostBgmFadeIn(work);
        EVENT_ENTRANCE_OUT_CallFadeIn(work, event);
        (*seq)++;
        break;
    case 1:
        EVENT_ENTRANCE_OUT_ShowPlaceName(work);
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Ground animation "out" event. */
u32 EVENT_ENTRANCE_OUT_RunGroundAnime(GameEvent *event, int *seq, EntranceOutWork *work)
{
    EntranceParam *param = work->param;

    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, FIELD_GROUND_ANIME_CreateA((struct GroundAnimeArgs *)param));
        (*seq)++;
        break;
    case 1:
        EVENT_ENTRANCE_OUT_ShowPlaceName(work);
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Object animation "out" event: fade in, music, the object animation, then the place name. */
u32 EVENT_ENTRANCE_OUT_RunObjectAnime(GameEvent *event, int *seq, EntranceOutWork *work)
{
    EntranceParam *param = work->param;
    GameSystem *gameSystem = param->gameSystem;
    FieldMap *fieldMap = param->fieldMap;

    switch (*seq) {
    case 0:
        EVENT_ENTRANCE_OUT_CallFadeIn(work, event);
        (*seq)++;
        break;
    case 1:
        if (param->bgmReplaced != 0)
            EVENT_ENTRANCE_OUT_PostBgmFadeIn(work);
        else if (param->bgmFadeStarted != 0)
            EVENT_ENTRANCE_OUT_StartBgmFadeIn(work, event);
        (*seq)++;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, EVENT_FIELD_PROCLINK_StartObjAnim(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 3:
        EVENT_ENTRANCE_OUT_ShowPlaceName(work);
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Appear "out" event. */
u32 EVENT_ENTRANCE_OUT_RunAppear(GameEvent *event, int *seq, EntranceOutWork *work)
{
    EntranceParam *param = work->param;
    GameSystem *gameSystem = param->gameSystem;
    FieldMap *fieldMap = param->fieldMap;

    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_APPEAR_CreateDescendingSpin(0, gameSystem, fieldMap));
        (*seq)++;
        break;
    case 1:
        EVENT_ENTRANCE_OUT_ShowPlaceName(work);
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Camera "out" event: the ground animation, then the place name. */
u32 EVENT_ENTRANCE_OUT_RunCamera(GameEvent *event, int *seq, EntranceOutWork *work)
{
    EntranceParam *param = work->param;

    FIELDMAP_GetCamera(param->fieldMap);
    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, FIELD_GROUND_ANIME_CreateA((struct GroundAnimeArgs *)param));
        (*seq)++;
        break;
    case 1:
        EVENT_ENTRANCE_OUT_ShowPlaceName(work);
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Fade and sound "out" event: music, then the fade in. */
u32 EVENT_ENTRANCE_OUT_RunFadeSe(GameEvent *event, int *seq, EntranceOutWork *work)
{
    EntranceParam *param = work->param;
    GameSystem *gameSystem = param->gameSystem;
    FieldMap *fieldMap = param->fieldMap;

    switch (*seq) {
    case 0:
        if (param->bgmReplaced != 0)
            EVENT_ENTRANCE_OUT_PostBgmFadeIn(work);
        (*seq)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 2, 0, 0, 0, 0));
        (*seq)++;
        break;
    case 2:
        EVENT_ENTRANCE_OUT_ShowPlaceName(work);
        return ENTRANCE_EVENT_FINISHED;
    }
    return ENTRANCE_EVENT_CONTINUE;
}

/* Posts the fade in of the zone music replaced by the "in" event. */
void EVENT_ENTRANCE_OUT_PostBgmFadeIn(EntranceOutWork *work)
{
    FIELD_SOUND_SYSTEM_PostFadeIn((struct FieldSoundSystem *)GAME_DATA_GetBgmInfo(work->param->gameData), work->param->gameData);
}

/* Starts the music fade in. */
void EVENT_ENTRANCE_OUT_StartBgmFadeIn(EntranceOutWork *work, GameEvent *event)
{
    EntranceParam *param = work->param;
    GameSystem *gameSystem = param->gameSystem;

    GAME_DATA_GetBgmInfo(param->gameData);
    GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartFadeInTask(gameSystem, ENTRANCE_OUT_BGM_FADE_FRAMES));
}

/* Calls the fade in: the season fade when the season changes, else the fade of the entrance effect. */
void EVENT_ENTRANCE_OUT_CallFadeIn(EntranceOutWork *work, GameEvent *event)
{
    EntranceParam *param = work->param;
    GameSystem *gameSystem = param->gameSystem;
    FieldMap *fieldMap = param->fieldMap;

    if (param->seasonChanged != 0)
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 3, 0, 0, param->fromSeasonIndex, param->toSeason));
    else
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, param->entranceEffectId, 0, 1, 0, 0));
}

/* Shows the place name of the destination zone. */
void EVENT_ENTRANCE_OUT_ShowPlaceName(EntranceOutWork *work)
{
    EntranceParam *param = work->param;

    FIELD_PLACE_NAME_OnZoneChange(FIELDMAP_GetPlaceName(param->fieldMap), (s16)param->destination.zoneId);
}
