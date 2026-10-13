/*
 * file:     calender.c
 * unit:     yes
 * function: func_021644F4, func_02164508, func_02164564, func_0216458C, func_0216459C, func_021645C0, func_021645E0, func_02164654, func_02164678, func_021646A0, func_021646C4, func_021646E8, func_02164708, func_02164728, func_0216476C, func_02164778, func_021647A0, func_021647D8, func_021647E8, func_021647F0, func_021647FC, func_0216480C, func_0216481C, func_02164844, func_02164890, func_021648A8, func_021648CC, func_02164910, func_02164978, func_02164994, func_021649C8, func_021649E8, func_02164A2C
 * address:  0x021644F4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_02171504     0x02171504  data
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02012B28  0x02012B28  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A30C8  0x021A30C8  thumb
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021AB4B8  0x021AB4B8  thumb
 *   func_02013C20  0x02013C20  thumb
 *   func_02013E04 0x02013E04 thumb
 *   func_02013C50 0x02013C50 thumb
 *   func_021C5C64  0x021C5C64  thumb  ov021
 *   func_02013D20   0x02013D20  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012138  0x02012138  thumb
 *   func_0215870C  0x0215870C  thumb ov010
 *   func_02188C7C  0x02188C7C  thumb ov021
 *   func_02188BF8  0x02188BF8  thumb ov021
 *   func_021A2F54  0x021A2F54  thumb ov021
 *   func_021A34F8  0x021A34F8  thumb ov021
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02185140 0x02185140 thumb ov020
 *   func_02188CCC 0x02188CCC thumb ov021
 *   func_021A0F90 0x021A0F90 thumb ov021
 *   func_021A0F30 0x021A0F30 thumb ov021
 *   d_02171534     0x02171534  data
 *   ZONEDATA_PopTimeFlagsCleared  0x0201440C  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_0201433C  0x0201433C  thumb
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_02034AC4 0x02034AC4 arm
 *   func_021F3800 0x021F3800 thumb ov047
 *   func_02034A5C 0x02034A5C arm
 *   ov_id_47 0x0000002F data
 *   func_02030734 0x02030734 arm
 *   d_021729B0 0x021729B0 data ov010 a1
 *   func_020307B0  0x020307B0  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 *   func_021690D0 0x021690D0 thumb ov010
 *   func_021690E0 0x021690E0 thumb ov010
 *   ZONEDATA_GetWeatherId  0x02013C10  thumb
 *   func_0204944C  0x0204944C  arm
 *   d_02171C20  0x02171C20  data  ov010  a1
 *   func_0215A5F4  0x0215A5F4  thumb ov010
 *   func_02011330  0x02011330  thumb
 *   func_02159144  0x02159144  thumb ov010
 *   func_021F5260  0x021F5260  thumb ov082
 *   func_0215897C  0x0215897C  thumb ov010
 *   ov_id_52       0x00000052  data
 *   func_021F558C  0x021F558C  thumb
 *   func_021F5578 0x021F5578 thumb ov082
 *   func_02159168 0x02159168 thumb ov010
 *   func_020124E4  0x020124E4  thumb
 *   func_02012374  0x02012374  thumb
 *   func_021F5550  0x021F5550  thumb  ov082
 *   func_020120F4  0x020120F4  thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_SOUND_SYSTEM_StartPushAndChangeTask  0x020297AC  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   FIELD_SOUND_SYSTEM_StartPopTask  0x02029690  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   func_021A0F40  0x021A0F40  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   ov216_id       0x000000D8  data
 *   d_021BDB40     0x021BDB40  data  a1 ov216
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct GameSystem;
struct GameData;
struct PlayerWork;
struct EventWork;
struct GameEvent;
struct FieldMap;
struct FieldPlayer;
struct ArcFile;
struct ScriptVm;
struct ScriptSystem;
struct ScrCmdWork;

/* Overlay ids are linker symbols whose address is the id. */
#define OVERLAY_ID_47 ((int)ov_id_47)
#define OVERLAY_ID_52 ((int)ov_id_52)
#define OVERLAY_ID_216 ((u32)ov216_id)

#define HIDDEN_ITEM_SCRIPT_FIRST 8000
#define HIDDEN_ITEM_SCRIPT_LAST 8799
#define HIDDEN_ITEM_FLAG_BASE 900
#define HIDDEN_ITEM_COUNT 177
#define HIDDEN_ITEM_RESPAWN_PERCENT 20

#define CALENDER_ZONE_MAX 68
#define CALENDER_ARC_ID 0x61

typedef struct GameEvent *(*FieldLinkEventFn)(struct FieldMap *fieldMap, struct GameSystem *gameSystem);

/* One record of the field link event table at d_02171504. */
typedef struct FieldLinkEventEntry {
    FieldLinkEventFn create;
    u32 id;
} FieldLinkEventEntry;

/* One record of the hidden item table at d_02171534. */
typedef struct HiddenItemEntry {
    u16 flagIndex;    /* the event flag is flagIndex + HIDDEN_ITEM_FLAG_BASE */
    u8 isDowsable;
    u8 respawns;      /* takes part in the daily respawn roll */
    u16 zoneId;
    u16 gridX;
    u16 gridZ;
} HiddenItemEntry;

/* Days per month: index 0 is unused, February has 29 days. */
typedef struct DaysPerMonth {
    u8 days[13];
} DaysPerMonth;

typedef struct SubscreenToggleWork {
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
} SubscreenToggleWork;

typedef struct LinkEnterWork {
    struct GameSystem *gameSystem;
    u32 frameCount;
} LinkEnterWork;

typedef struct CalenderZoneEntry {
    u16 zoneId;
    u16 offset;       /* offset of the zone's 366 daily weather bytes in the archive */
} CalenderZoneEntry;

/* Weather calendar, 0x11C bytes. */
typedef struct CalenderWork {
    u16 heapId;
    struct GameData *gameData;
    struct ArcFile *arc;
    CalenderZoneEntry zones[CALENDER_ZONE_MAX];
} CalenderWork;

typedef struct FaceUpEndWork {
    struct GameSystem *gameSystem;
} FaceUpEndWork;

/* Argument block of the overlay 216 process. */
typedef struct BeaconSearchProcArgs {
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    u8 mode;
    u8 resultFlag;
    u8 pad[2];
} BeaconSearchProcArgs;

/* Work of the beacon search event, 0x1C bytes. */
typedef struct BeaconSearchEventWork {
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    void *saveControl;
    BeaconSearchProcArgs procArgs;
    u8 mode;
} BeaconSearchEventWork;

extern unsigned short func_02012AC8(const struct PlayerWork *player);
extern u32 func_02012B28(const struct PlayerWork *player);
extern struct FieldPlayer *func_02188CB4(struct FieldMap *fieldMap);
extern void *func_021A30C8(struct FieldPlayer *fieldPlayer);
extern void *func_021AB0F0(void *encountState);
extern int func_021AB4B8(void *effect);
extern u32 func_02013C20(u32 zoneId);
extern u32 func_02013E04(u32 zoneId);
extern u32 func_02013C50(u32 zoneId);
extern int func_021C5C64(struct GameData *gameData, struct FieldMap *fieldMap, u32 *out);
extern u32 func_02013D20(u32 zoneId);
extern struct FieldMap *func_0201210C(const struct GameSystem *gameSystem);
extern void *func_02012138(const struct GameSystem *gameSystem);
extern int func_0215870C(void *gameComm, int frames);
extern void *func_02188C7C(struct FieldMap *fieldMap);
extern u32 func_02188BF8(struct FieldMap *fieldMap);
extern int func_021A2F54(struct FieldPlayer *fieldPlayer);
extern int func_021A34F8(struct FieldPlayer *fieldPlayer);
extern struct GameEvent *func_020122C0(void *gameSystem, void *parent, void *func, u32 size);
extern void *func_020124E8(struct GameEvent *event);
extern void func_02185140(struct GameSystem *gameSystem, int id, const void *position, int flags);
extern void *func_02188CCC(struct FieldMap *fieldMap);
extern u32 func_021A0F90(void *subscreen);
extern int func_021A0F30(void *subscreen, u32 mode);
extern u8 ZONEDATA_PopTimeFlagsCleared(struct EventWork *eventWork);
extern u32 func_020056EC(u32 range);
extern void func_0201433C(struct EventWork *eventWork, int flagId);
extern struct GameSystem *func_0215A5DC(struct ScrCmdWork *work);
extern int func_02034AC4(int overlayId);
extern void func_021F3800(struct GameSystem *gameSystem);
extern void func_02034A5C(int overlayId);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern void func_020307B0(void *ptr);
extern struct ArcFile *func_020490F4(u32 arcId, u32 heapId);
extern void func_02049238(struct ArcFile *arc);
extern int func_021690D0(struct GameData *gameData);
extern int func_021690E0(struct GameData *gameData);
extern u8 ZONEDATA_GetWeatherId(u32 zoneId);
extern void func_0204944C(struct ArcFile *arc, u32 fileId, u32 offset, u32 size, void *dst);
extern struct ScriptSystem *func_0215A5F4(struct ScrCmdWork *work);
extern u16 func_02011330(struct ScriptVm *vm);
extern void func_02159144(int waitState);
extern void *func_021F5260(int type, int variant, int option, struct GameSystem *gameSystem, struct ScrCmdWork *work);
extern void func_0215897C(struct ScriptSystem *scriptSystem, void *task);
extern int func_021F558C(struct FieldMap *fieldMap);
extern void func_021F5578(struct FieldMap *fieldMap);
extern void func_02159168(int waitState);
extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern void func_02012374(struct GameEvent *parent, struct GameEvent *child);
extern struct GameEvent *func_021F5550(struct GameSystem *gameSystem);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct GameEvent *func_021BE8D4(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int mode, int subMode);
extern struct GameEvent *FIELD_STATUS_CreateFieldCloseEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern struct GameEvent *FIELD_SOUND_SYSTEM_StartPushAndChangeTask(struct GameSystem *gameSystem, u32 soundId, u32 mode, u32 flag);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void GAMESYSTEM_CallProc(struct GameSystem *gameSystem, u32 overlayId, void *procData, void *param);
extern u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *gameSystem);
extern struct GameEvent *FIELD_SOUND_SYSTEM_StartPopTask(struct GameSystem *gameSystem, u32 mode, u32 frames);
extern struct GameEvent *FIELD_STATUS_CreateFieldOpenEvent(struct GameSystem *gameSystem);
extern void func_021A0F40(void *subscreen, u32 mode);
extern struct GameEvent *func_021BE92C(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int mode, int subMode, int enable, u8 optionA, u8 optionB);
extern struct GameEvent *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(struct GameSystem *gameSystem);

extern FieldLinkEventEntry d_02171504[];
extern const HiddenItemEntry d_02171534[];
extern u8 ov_id_47[];
extern const char d_021729B0[];
extern const DaysPerMonth d_02171C20;
extern u8 ov_id_52[];
extern u8 ov216_id[];
extern const u8 d_021BDB40[];

struct GameEvent *func_021644F4(int index, struct GameSystem *gameSystem, struct FieldMap *fieldMap);
int func_02164508(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player);
int func_02164564(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player);
int func_0216458C(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player);
int func_0216459C(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player);
int func_021645C0(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player);
int func_021645E0(struct GameEvent *event, int *seq, LinkEnterWork *work);
struct GameEvent *func_02164654(struct FieldMap *fieldMap, struct GameSystem *gameSystem);
void func_02164678(struct FieldMap *fieldMap, struct GameSystem *gameSystem);
int func_021646A0(struct GameEvent *event, u32 *seq, SubscreenToggleWork *work);
struct GameEvent *func_021646C4(struct FieldMap *fieldMap, struct GameSystem *gameSystem);
u16 func_021646E8(u32 scriptId);
u16 func_02164708(u16 scriptId);
void func_02164728(struct EventWork *eventWork);
const HiddenItemEntry *func_0216476C(unsigned short *count);
int func_02164778(struct ScriptVm *vm, struct ScrCmdWork *work);
CalenderWork *func_021647A0(struct GameData *gameData, u32 heapId);
void func_021647D8(CalenderWork *calender);
u32 func_021647E8(CalenderWork *calender, unsigned int zoneId);
void func_021647F0(CalenderWork *calender);
struct ArcFile *func_021647FC(CalenderWork *calender);
void func_0216480C(CalenderWork *calender);
u8 func_0216481C(CalenderWork *calender, u32 zoneId);
u8 func_02164844(CalenderWork *calender, u32 zoneId, u8 month, u8 day);
void func_02164890(CalenderWork *calender);
u32 func_021648A8(CalenderWork *calender, u32 zoneId);
u16 func_021648CC(int month, int day);
int func_02164910(struct ScriptVm *vm, struct ScrCmdWork *work);
int func_02164978(struct ScriptVm *vm, struct ScrCmdWork *work);
int func_02164994(struct ScriptVm *vm, struct ScrCmdWork *work);
int func_021649C8(FaceUpEndWork *work);
int func_021649E8(struct GameEvent *event, int *seq);
int func_02164A2C(struct GameEvent *event, u32 *seq, BeaconSearchEventWork *work);

/*
 * Creates the event of entry index in the field link event table and
 * returns it.
 */
struct GameEvent *func_021644F4(int index, struct GameSystem *gameSystem, struct FieldMap *fieldMap)
{
    return d_02171504[index].create(fieldMap, gameSystem);
}

/*
 * Field skill check, slot 0: whether the bicycle can be used here. Only
 * allowed while no encounter effect is active; getting on also needs a
 * bicycle zone and the walking body.
 */
int func_02164508(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player)
{
    u16 zoneId;
    u8 objectCode;
    int encountEffect;

    zoneId = func_02012AC8(player);
    objectCode = func_02012B28(player);
    encountEffect = func_021AB4B8(func_021AB0F0(func_021A30C8(func_02188CB4(fieldMap))));
    if (objectCode == 1) {
        if (encountEffect == 0) {
            return 1;
        }
        return 0;
    }
    if (func_02013C20(zoneId) == 0) {
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
int func_02164564(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player)
{
    u16 zoneId = func_02012AC8(player);

    if (!func_02013E04(zoneId)) {
        return 0;
    }
    if (func_02013C50(zoneId)) {
        return 1;
    }
    return 0;
}

/* Field skill check: normal field zone (2-byte zero padding follows at 0x0216459A). */
int func_0216458C(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player)
{
    return func_02013E04(func_02012AC8(player));
}

/*
 * Field skill check: normal field zone and the tile in front passes the
 * check of func_021C5C64 (overlay 21, defined in the co-resident ov021).
 */
int func_0216459C(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player)
{
    if (func_02013E04(func_02012AC8(player)) == 0) {
        return 0;
    }
    return func_021C5C64(gameData, fieldMap, 0);
}

/* Field skill check: normal field zone, except the zone of func_02013D20. */
int func_021645C0(struct GameData *gameData, struct FieldMap *fieldMap, struct PlayerWork *player)
{
    int zoneId = func_02012AC8(player);

    if (func_02013D20(zoneId) != 0) {
        return 0;
    }
    return func_02013E04(zoneId);
}

/*
 * Event: waits up to 30 frames for the comm check, then runs two field
 * player steps in turn.
 */
int func_021645E0(struct GameEvent *event, int *seq, LinkEnterWork *work)
{
    void *gameComm;
    struct FieldMap *fieldMap;

    fieldMap = func_0201210C(work->gameSystem);
    func_02188C7C(fieldMap);
    switch (*seq) {
    case 0:
        gameComm = func_02012138(work->gameSystem);
        work->frameCount++;
        if (func_0215870C(gameComm, work->frameCount) == 1 && work->frameCount < 30) {
            break;
        }
        func_02188BF8(fieldMap);
        (*seq)++;
        /* fall through */
    case 1:
        if (func_021A2F54(func_02188CB4(fieldMap)) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        if (func_021A34F8(func_02188CB4(fieldMap)) == 1) {
            return 1;
        }
        break;
    }
    return 0;
}

/* Creates the event of func_021645E0 (field link entry 0). */
struct GameEvent *func_02164654(struct FieldMap *fieldMap, struct GameSystem *gameSystem)
{
    struct GameEvent *event;
    LinkEnterWork *work;

    event = func_020122C0(gameSystem, 0, (void *)func_021645E0, sizeof(LinkEnterWork));
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->frameCount = 0;
    return event;
}

/*
 * Field link entry 1: adds the object 279 of overlay 20 at a fixed
 * position (2-byte zero padding follows at 0x0216469E).
 */
void func_02164678(struct FieldMap *fieldMap, struct GameSystem *gameSystem)
{
    struct {
        int x;
        int y;
        int z;
    } position;

    position.x = 0x200000;
    position.y = 32;
    position.z = 0x1E8000;
    func_02185140(gameSystem, 279, &position, 0);
}

/* Event: switches the subscreen between mode 6 and mode 0. */
int func_021646A0(struct GameEvent *event, u32 *seq, SubscreenToggleWork *work)
{
    void *subscreen = func_02188CCC(work->fieldMap);

    if (func_021A0F90(subscreen) == 6) {
        func_021A0F30(subscreen, 0);
    } else {
        func_021A0F30(subscreen, 6);
    }
    return 1;
}

/* Creates the event of func_021646A0 (field link entry 5). */
struct GameEvent *func_021646C4(struct FieldMap *fieldMap, struct GameSystem *gameSystem)
{
    struct GameEvent *event = func_020122C0(gameSystem, 0, (void *)func_021646A0, sizeof(SubscreenToggleWork));
    SubscreenToggleWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    return event;
}

/*
 * Hidden item index of a script id, or 0 when the id is outside the
 * hidden item script range.
 */
u16 func_021646E8(u32 scriptId)
{
    if (scriptId < HIDDEN_ITEM_SCRIPT_FIRST || scriptId > HIDDEN_ITEM_SCRIPT_LAST) {
        return 0;
    }
    return scriptId - HIDDEN_ITEM_SCRIPT_FIRST;
}

/* Event flag of the hidden item that a script id stands for. */
u16 func_02164708(u16 scriptId)
{
    return d_02171534[func_021646E8(scriptId)].flagIndex + HIDDEN_ITEM_FLAG_BASE;
}

/*
 * Daily hidden item respawn: when the time flags were cleared, every
 * respawning entry has a 20% chance to reset its event flag.
 */
void func_02164728(struct EventWork *eventWork)
{
    u32 i;

    if (ZONEDATA_PopTimeFlagsCleared(eventWork) != 0) {
        for (i = 0; i < HIDDEN_ITEM_COUNT; i++) {
            const HiddenItemEntry *entry = d_02171534 + i;

            if (entry->respawns != 0) {
                if (func_020056EC(100) < HIDDEN_ITEM_RESPAWN_PERCENT) {
                    func_0201433C(eventWork, (u16)(entry->flagIndex + HIDDEN_ITEM_FLAG_BASE));
                }
            }
        }
    }
}

/* Returns the hidden item table and stores its entry count. */
const HiddenItemEntry *func_0216476C(unsigned short *count)
{
    *count = HIDDEN_ITEM_COUNT;
    return d_02171534;
}

/* Script command: loads overlay 47 and runs its entry on the game system. */
int func_02164778(struct ScriptVm *vm, struct ScrCmdWork *work)
{
    struct GameSystem *gameSystem = func_0215A5DC(work);

    func_02034AC4(OVERLAY_ID_47);
    func_021F3800(gameSystem);
    func_02034A5C(OVERLAY_ID_47);
    return 0;
}

/*
 * Allocates the weather calendar and loads its archive and zone table.
 * The file name and line (0x53) given to the allocator are those of the
 * original call site.
 */
CalenderWork *func_021647A0(struct GameData *gameData, u32 heapId)
{
    CalenderWork *calender;

    calender = func_02030734(heapId, sizeof(CalenderWork), 0, d_021729B0, 0x53);
    func_021647F0(calender);
    calender->heapId = heapId;
    calender->gameData = gameData;
    func_021647FC(calender);
    func_02164890(calender);
    return calender;
}

/* Closes the archive and frees the weather calendar. */
void func_021647D8(CalenderWork *calender)
{
    func_0216480C(calender);
    func_020307B0(calender);
}

/*
 * Tail call to func_0216481C through a pool word and `bx r3`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md). Unlabelled in the
 * listing: no prologue, and its only caller is func_0202C794 in arm9.
 */
u32 func_021647E8(CalenderWork *calender, unsigned int zoneId)
{
    return func_0216481C(calender, zoneId);
}

/* Clears the calendar fields that hold resources. */
void func_021647F0(CalenderWork *calender)
{

    calender->heapId = 0;
    calender->gameData = 0;
    calender->arc = 0;
}

/* Opens the calendar archive. */
struct ArcFile *func_021647FC(CalenderWork *calender)
{
    struct ArcFile *arc;

    arc = func_020490F4(CALENDER_ARC_ID, calender->heapId);
    calender->arc = arc;
    return arc;
}

/* Closes the calendar archive. */
void func_0216480C(CalenderWork *calender)
{
    func_02049238(calender->arc);
    calender->arc = 0;
}

/* Weather of a zone on the current date. */
u8 func_0216481C(CalenderWork *calender, u32 zoneId)
{
    int month = func_021690D0(calender->gameData);
    int day = func_021690E0(calender->gameData);

    return func_02164844(calender, zoneId, month, day);
}

/*
 * Weather of a zone on a date: reads the byte at the zone's offset plus
 * the day of the year. A zone without a calendar entry takes its default
 * weather.
 */
u8 func_02164844(CalenderWork *calender, u32 zoneId, u8 month, u8 day)
{
    u32 zoneOffset = func_021648A8(calender, zoneId);
    u8 weather;
    u16 position;

    if (zoneOffset == 0xffff) {
        return ZONEDATA_GetWeatherId(zoneId);
    }
    position = zoneOffset + func_021648CC(month, day);
    func_0204944C(calender->arc, 0, position, 1, &weather);
    return weather;
}

/* Loads the zone offset table (archive file 1, from byte 2). */
void func_02164890(CalenderWork *calender)
{
    func_0204944C(calender->arc, 1, 2, sizeof(calender->zones), calender->zones);
}

/* Archive offset of a zone's calendar, or 0xFFFF when the zone has none. */
u32 func_021648A8(CalenderWork *calender, u32 zoneId)
{
    int i;
    u32 zoneOffset = 0xffff;

    for (i = 0; i < CALENDER_ZONE_MAX; i++) {
        if (zoneId == calender->zones[i].zoneId) {
            zoneOffset = calender->zones[i].offset;
            break;
        }
    }
    return zoneOffset;
}

/*
 * Zero-based day of the year (leap year layout): the days of the months
 * before `month`, plus day - 1. The month table is copied to the stack
 * from the pool copy at d_02171C20.
 */
u16 func_021648CC(int month, int day)
{
    DaysPerMonth daysPerMonth = d_02171C20;
    int i;
    u16 sum = 0;

    for (i = 0; i < month; i++) {
        sum = sum + daysPerMonth.days[i];
    }
    return sum + (u16)(day - 1);
}

/*
 * Script command: reads three values off the script, loads overlay 82 and
 * starts the face-up scene; waits for it when a task was created.
 */
int func_02164910(struct ScriptVm *vm, struct ScrCmdWork *work)
{
    struct ScriptSystem *scriptSystem = func_0215A5F4(work);
    struct GameSystem *gameSystem = func_0215A5DC(work);
    u8 type = func_02011330(vm);
    u8 variant = func_02011330(vm);
    u32 option = func_02011330(vm);
    void *task;

    func_02159144(7);
    func_02034AC4(OVERLAY_ID_52);
    task = func_021F5260(type, variant, option, gameSystem, work);
    if (task == 0) {
        return 1;
    }
    func_0215897C(scriptSystem, task);
    return 1;
}

/* Script command: finishes the face-up scene on the field map. */
int func_02164978(struct ScriptVm *vm, struct ScrCmdWork *work)
{
    struct GameSystem *gameSystem;

    func_0215A5F4(work);
    gameSystem = func_0215A5DC(work);
    func_021F558C(func_0201210C(gameSystem));
    return 0;
}

/* Script command: creates the face-up wait event and waits for it. */
int func_02164994(struct ScriptVm *vm, struct ScrCmdWork *work)
{
    struct ScriptSystem *scriptSystem = func_0215A5F4(work);
    struct GameEvent *event = func_020122C0(func_0215A5DC(work), 0, (void *)func_021649E8, 0);

    if (event == 0) {
        return 1;
    }
    func_0215897C(scriptSystem, event);
    return 1;
}

/* Ends the face-up scene: releases the field map part, the script state and overlay 82. */
int func_021649C8(FaceUpEndWork *work)
{
    func_021F5578(func_0201210C(work->gameSystem));
    func_02159168(7);
    func_02034A5C(OVERLAY_ID_52);
    return 1;
}

/* Event: step 0 starts the face-up end request, step 1 releases it and the overlay. */
int func_021649E8(struct GameEvent *event, int *seq)
{
    struct GameSystem *gameSystem = func_020124E4(event);

    switch (*seq) {
    case 0:
        func_02012374(event, func_021F5550(gameSystem));
        (*seq)++;
        break;
    case 1:
        func_02159168(7);
        func_02034A5C(OVERLAY_ID_52);
        return 1;
    }
    return 0;
}

/*
 * Beacon search event: eight steps, each starting one child event or
 * process (the overlay 216 one through GAMESYSTEM_CallProc with a 12-byte
 * argument block), then done. Step 2 falls through into step 3.
 * d_021BDB40 is the process template and lives in overlay 216.
 */
int func_02164A2C(struct GameEvent *event, u32 *seq, BeaconSearchEventWork *work)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;

    gameSystem = work->gameSystem;
    func_020120F4(gameSystem);
    fieldMap = func_0201210C(gameSystem);
    switch (*seq) {
    case 0:
        func_02012374(event, func_021BE8D4(gameSystem, fieldMap, 0, 0));
        (*seq)++;
        break;
    case 1:
        func_02012374(event, FIELD_STATUS_CreateFieldCloseEvent(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 2:
        func_02012374(event, FIELD_SOUND_SYSTEM_StartPushAndChangeTask(gameSystem, 0x483, 6, 0));
        (*seq)++;
        /* fall through */
    case 3:
        MI_CpuFill8(&work->procArgs, 0, sizeof(BeaconSearchProcArgs));
        work->procArgs.gameSystem = work->gameSystem;
        work->procArgs.gameData = work->gameData;
        work->procArgs.mode = work->mode;
        GAMESYSTEM_CallProc(gameSystem, OVERLAY_ID_216, (void *)d_021BDB40, &work->procArgs);
        (*seq)++;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0) {
            func_02012374(event, FIELD_SOUND_SYSTEM_StartPopTask(gameSystem, 6, 0x3C));
            (*seq)++;
        }
        break;
    case 5:
        func_02012374(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*seq)++;
        break;
    case 6:
        if (work->procArgs.resultFlag != 0) {
            func_021A0F40(func_02188CCC(fieldMap), 0);
        }
        func_02012374(event, func_021BE92C(gameSystem, fieldMap, 0, 0, 1, 0, 0));
        (*seq)++;
        break;
    case 7:
        func_02012374(event, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(gameSystem));
        (*seq)++;
        break;
    case 8:
        return 1;
    }
    return 0;
}
