/*
 * file:     field_skill_check.c
 * unit:     yes
 * function: FIELD_SKILL_CHECK_FillUseFlags, FIELD_SKILL_CHECK_CallHandler, FIELD_LINK_EVENT_Create, FIELD_SKILL_CHECK_Bicycle, FIELD_SKILL_CHECK_WeatherZone, FIELD_SKILL_CHECK_NormalFieldZone, FIELD_SKILL_CHECK_FrontTile, FIELD_SKILL_CHECK_NormalFieldZoneNotZone34, FIELD_LINK_EVENT_EnterEventMain, FIELD_LINK_EVENT_CreateEnterEvent, FIELD_LINK_EVENT_CreateIntrudeWarpEvent, FIELD_LINK_EVENT_ToggleSubscreenEventMain, FIELD_LINK_EVENT_CreateToggleSubscreenEvent
 * address:  0x02164480
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from field_skill_check.c, calender.c, game_beacon_search.c, game_beacon_accessor.c by tools/splitfile.py.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   FIELD_SKILL_USE_FLAGS_SetSkill  0x02028748  thumb
 *   GAME_DATA_GetPlayerObjectCode  0x02012B28  thumb
 *   d_021714DC     0x021714DC  data
 *   FieldLinkEventTable     0x02171504  data
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetNowAttribute  0x021A30C8  thumb
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb
 *   MAP_ATTR_IsRoughGround  0x021AB4B8  thumb
 *   ZONEDATA_IsBikeEnabled  0x02013C20  thumb
 *   ZONEDATA_IsNormalFieldZone 0x02013E04 thumb
 *   ZONEDATA_IsWeatherEnabled 0x02013C50 thumb
 *   FISHING_CheckFacingWater  0x021C5C64  thumb  ov021
 *   ZONEDATA_IsZone34   0x02013D20  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   INTRUDE_COMM_IsSessionEndPending  0x0215870C  thumb ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb ov021
 *   FIELDMAP_ApplyPlayerFormRequest  0x02188BF8  thumb ov021
 *   FIELD_PLAYER_StepFormChange  0x021A2F54  thumb ov021
 *   FIELD_PLAYER_WaitModelReady  0x021A34F8  thumb ov021
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   GAME_EVENT_GetWork 0x020124E8 thumb
 *   EVENT_MAPCHANGE_CreateIntrudeWarpEvent 0x02185140 thumb ov020
 *   FIELDMAP_GetSubscreen 0x02188CCC thumb ov021
 *   FIELD_SUBSCREEN_GetMode 0x021A0F90 thumb ov021
 *   FIELD_SUBSCREEN_RequestMode 0x021A0F30 thumb ov021
 */
#include "../ov021/fldmmdl_rail_types.h"
#include "field_skill_check_shared_types.h"

/* Field skill use flags (0x18 bytes): bit i of usableMask set when field
 * skill i can be used now (FIELD_SKILL_CHECK_CallHandler). FIELD_SKILL_USE_FLAGS_SetSkill
 * ORs the bit into the word at +0x14 and FIELD_SKILL_USE_FLAGS_IsSkillUsable tests it there. */
typedef struct FieldSkillUseFlags {
    u32 reserved00;     /* 0x00: cleared, never read here */
    u32 playerObjCode;  /* 0x04 */
    u8 reserved08[0xC]; /* 0x08: cleared, never read here */
    u32 usableMask;     /* 0x14 */
} FieldSkillUseFlags;

typedef int (*SkillCheckHandler)(struct GameData *gameData, void *fieldMap, struct PlayerWork *player);

extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);

extern struct PlayerWork *GAME_DATA_GetMyPlayerWork(struct GameData *gameData);

extern void MI_CpuFill8(void *dst, u8 val, u32 size);

extern void FIELD_SKILL_USE_FLAGS_SetSkill(FieldSkillUseFlags *flags, int skillIndex, int usable);

extern u32 GAME_DATA_GetPlayerObjectCode(const struct PlayerWork *player);

void FIELD_SKILL_CHECK_FillUseFlags(FieldSkillUseFlags *flags, struct GameSystem *gameSystem, void *fieldMap);

int FIELD_SKILL_CHECK_CallHandler(int skillIndex, struct GameSystem *gameSystem, void *fieldMap);

extern SkillCheckHandler d_021714DC[];

void FIELD_SKILL_CHECK_FillUseFlags(FieldSkillUseFlags *flags, struct GameSystem *gameSystem, void *fieldMap)
{
    struct PlayerWork *player;
    int i;

    player = GAME_DATA_GetMyPlayerWork(GAMESYSTEM_GetGameData(gameSystem));
    MI_CpuFill8(flags, 0, sizeof(FieldSkillUseFlags));
    for (i = 0; i < 10; i++)
        FIELD_SKILL_USE_FLAGS_SetSkill(flags, i, FIELD_SKILL_CHECK_CallHandler(i, gameSystem, fieldMap));
    flags->playerObjCode = GAME_DATA_GetPlayerObjectCode(player);
}

/*
 * Calls entry i of the handler table at 0x021714DC, or returns 1 when the
 * slot is empty.
 */
int FIELD_SKILL_CHECK_CallHandler(int skillIndex, struct GameSystem *gameSystem, void *fieldMap)
{
    struct GameData *gameData;
    struct PlayerWork *player;
    SkillCheckHandler handler;

    gameData = GAMESYSTEM_GetGameData(gameSystem);
    player = GAME_DATA_GetMyPlayerWork(gameData);
    handler = d_021714DC[skillIndex];
    if (handler == 0)
        return 1;
    return handler(gameData, fieldMap, player);
}

struct FieldPlayer;

/* One record of the field link event table at FieldLinkEventTable. */
typedef struct FieldLinkEventEntry {
    FieldLinkEventFn create;
    u32 id;
} FieldLinkEventEntry;

typedef struct SubscreenToggleWork {
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
} SubscreenToggleWork;

typedef struct LinkEnterWork {
    struct GameSystem *gameSystem;
    u32 frameCount;
} LinkEnterWork;

extern unsigned short GAME_DATA_GetPlayerZoneId(const struct PlayerWork *player);

extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(struct FieldMap *fieldMap);

extern u32 FIELD_PLAYER_GetNowAttribute(struct FieldPlayer *fieldPlayer);

extern unsigned short MAP_ATTR_GetTerrainId(unsigned int attr);

extern int MAP_ATTR_IsRoughGround(int terrainId);

extern u32 ZONEDATA_IsBikeEnabled(u32 zoneId);

extern u32 ZONEDATA_IsNormalFieldZone(u32 zoneId);

extern u32 ZONEDATA_IsWeatherEnabled(u32 zoneId);

extern int FISHING_CheckFacingWater(struct GameData *gameData, struct FieldMap *fieldMap, u32 *out);

extern u32 ZONEDATA_IsZone34(u32 zoneId);

extern void *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
struct GameComm;

extern struct GameComm *GAMESYSTEM_GetGameComm(const struct GameSystem *gameSystem);

extern int INTRUDE_COMM_IsSessionEndPending(struct GameComm *comm, int unused);
struct MmdlSys;

extern struct MmdlSys *FIELDMAP_GetMmdlSys(struct FieldMap *fieldMap);

extern u32 FIELDMAP_ApplyPlayerFormRequest(struct FieldMap *fieldMap);

extern int FIELD_PLAYER_StepFormChange(struct FieldPlayer *fieldPlayer);

extern int FIELD_PLAYER_WaitModelReady(struct FieldPlayer *fieldPlayer);

extern struct GameEvent *GAME_EVENT_Create(void *gameSystem, void *parent, void *func, u32 size);

extern void *GAME_EVENT_GetWork(struct GameEvent *event);

extern void EVENT_MAPCHANGE_CreateIntrudeWarpEvent(struct GameSystem *gameSystem, int id, const void *position, int flags);
struct FieldSubscreen;

extern struct FieldSubscreen *FIELDMAP_GetSubscreen(struct FieldMap *fieldMap);

extern u32 FIELD_SUBSCREEN_GetMode(struct FieldSubscreen *work);

extern int FIELD_SUBSCREEN_RequestMode(struct FieldSubscreen *work, u32 mode);

extern FieldLinkEventEntry FieldLinkEventTable[];

struct GameEvent *FIELD_LINK_EVENT_Create(int index, struct GameSystem *gameSystem, struct FieldMap *fieldMap);

int FIELD_SKILL_CHECK_Bicycle(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player);

int FIELD_SKILL_CHECK_WeatherZone(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player);

int FIELD_SKILL_CHECK_NormalFieldZone(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player);

int FIELD_SKILL_CHECK_FrontTile(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player);

int FIELD_SKILL_CHECK_NormalFieldZoneNotZone34(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player);

int FIELD_LINK_EVENT_EnterEventMain(struct GameEvent *event, int *seq, LinkEnterWork *work);

struct GameEvent *FIELD_LINK_EVENT_CreateEnterEvent(struct FieldMap *fieldMap, struct GameSystem *gameSystem);

void FIELD_LINK_EVENT_CreateIntrudeWarpEvent(struct FieldMap *fieldMap, struct GameSystem *gameSystem);

int FIELD_LINK_EVENT_ToggleSubscreenEventMain(struct GameEvent *event, u32 *seq, SubscreenToggleWork *work);

struct GameEvent *FIELD_LINK_EVENT_CreateToggleSubscreenEvent(struct FieldMap *fieldMap, struct GameSystem *gameSystem);

/*
 * Creates the event of entry index in the field link event table and
 * returns it.
 */
struct GameEvent *FIELD_LINK_EVENT_Create(int index, struct GameSystem *gameSystem, struct FieldMap *fieldMap)
{
    return FieldLinkEventTable[index].create(fieldMap, gameSystem);
}

/*
 * Field skill check, slot 0: whether the bicycle can be used here. Only
 * allowed while no encounter effect is active; getting on also needs a
 * bicycle zone and the walking body.
 */
int FIELD_SKILL_CHECK_Bicycle(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player)
{
    u16 zoneId;
    u8 objectCode;
    int encountEffect;

    zoneId = GAME_DATA_GetPlayerZoneId(player);
    objectCode = GAME_DATA_GetPlayerObjectCode(player);
    encountEffect = MAP_ATTR_IsRoughGround(MAP_ATTR_GetTerrainId((unsigned int)FIELD_PLAYER_GetNowAttribute(FIELDMAP_GetFieldPlayer(fieldMap))));
    if (objectCode == 1) {
        if (encountEffect == 0) {
            return 1;
        }
        return 0;
    }
    if (ZONEDATA_IsBikeEnabled(zoneId) == 0) {
        return 0;
    }
    if (objectCode != 0) {
        return 0;
    }
    if (encountEffect == 0) {
        return 1;
    }
    return 0;
}

/* Field skill check: normal field zone that has weather. */
int FIELD_SKILL_CHECK_WeatherZone(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player)
{
    u16 zoneId = GAME_DATA_GetPlayerZoneId(player);

    if (!ZONEDATA_IsNormalFieldZone(zoneId)) {
        return 0;
    }
    if (ZONEDATA_IsWeatherEnabled(zoneId)) {
        return 1;
    }
    return 0;
}

/* Field skill check: normal field zone (2-byte zero padding follows at 0x0216459A). */
int FIELD_SKILL_CHECK_NormalFieldZone(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player)
{
    return ZONEDATA_IsNormalFieldZone(GAME_DATA_GetPlayerZoneId(player));
}

/*
 * Field skill check: normal field zone and the tile in front passes the
 * check of FISHING_CheckFacingWater (overlay 21, defined in the co-resident ov021).
 */
int FIELD_SKILL_CHECK_FrontTile(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player)
{
    if (ZONEDATA_IsNormalFieldZone(GAME_DATA_GetPlayerZoneId(player)) == 0) {
        return 0;
    }
    return FISHING_CheckFacingWater(gameData, fieldMap, 0);
}

/* Field skill check: normal field zone, except the zone of ZONEDATA_IsZone34. */
int FIELD_SKILL_CHECK_NormalFieldZoneNotZone34(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player)
{
    int zoneId = GAME_DATA_GetPlayerZoneId(player);

    if (ZONEDATA_IsZone34(zoneId) != 0) {
        return 0;
    }
    return ZONEDATA_IsNormalFieldZone(zoneId);
}

/*
 * Event: waits up to 30 frames for the comm check, then runs two field
 * player steps in turn.
 */
int FIELD_LINK_EVENT_EnterEventMain(struct GameEvent *event, int *seq, LinkEnterWork *work)
{
    void *gameComm;
    struct FieldMap *fieldMap;

    fieldMap = GAMESYSTEM_GetFieldMap(work->gameSystem);
    FIELDMAP_GetMmdlSys(fieldMap);
    switch (*seq) {
    case 0:
        gameComm = GAMESYSTEM_GetGameComm(work->gameSystem);
        work->frameCount++;
        if (INTRUDE_COMM_IsSessionEndPending(gameComm, work->frameCount) == 1 && work->frameCount < 30) {
            break;
        }
        FIELDMAP_ApplyPlayerFormRequest(fieldMap);
        (*seq)++;
        /* fall through */
    case 1:
        if (FIELD_PLAYER_StepFormChange(FIELDMAP_GetFieldPlayer(fieldMap)) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        if (FIELD_PLAYER_WaitModelReady(FIELDMAP_GetFieldPlayer(fieldMap)) == 1) {
            return 1;
        }
        break;
    }
    return 0;
}

/* Creates the event of FIELD_LINK_EVENT_EnterEventMain (field link entry 0). */
struct GameEvent *FIELD_LINK_EVENT_CreateEnterEvent(struct FieldMap *fieldMap, struct GameSystem *gameSystem)
{
    struct GameEvent *event;
    LinkEnterWork *work;

    event = GAME_EVENT_Create(gameSystem, 0, (void *)FIELD_LINK_EVENT_EnterEventMain, sizeof(LinkEnterWork));
    work = GAME_EVENT_GetWork(event);
    work->gameSystem = gameSystem;
    work->frameCount = 0;
    return event;
}

/*
 * Field link entry 1: adds the object 279 of overlay 20 at a fixed
 * position (2-byte zero padding follows at 0x0216469E).
 */
void FIELD_LINK_EVENT_CreateIntrudeWarpEvent(struct FieldMap *fieldMap, struct GameSystem *gameSystem)
{
    struct {
        int x;
        int y;
        int z;
    } position;

    position.x = 0x200000;
    position.y = 32;
    position.z = 0x1E8000;
    EVENT_MAPCHANGE_CreateIntrudeWarpEvent(gameSystem, 279, &position, 0);
}

/* Event: switches the subscreen between mode 6 and mode 0. */
int FIELD_LINK_EVENT_ToggleSubscreenEventMain(struct GameEvent *event, u32 *seq, SubscreenToggleWork *work)
{
    void *subscreen = FIELDMAP_GetSubscreen(work->fieldMap);

    if (FIELD_SUBSCREEN_GetMode(subscreen) == 6) {
        FIELD_SUBSCREEN_RequestMode(subscreen, 0);
    } else {
        FIELD_SUBSCREEN_RequestMode(subscreen, 6);
    }
    return 1;
}

/* Creates the event of FIELD_LINK_EVENT_ToggleSubscreenEventMain (field link entry 5). */
struct GameEvent *FIELD_LINK_EVENT_CreateToggleSubscreenEvent(struct FieldMap *fieldMap, struct GameSystem *gameSystem)
{
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, (void *)FIELD_LINK_EVENT_ToggleSubscreenEventMain, sizeof(SubscreenToggleWork));
    SubscreenToggleWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    return event;
}
