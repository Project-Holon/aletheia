/*
 * file:     event_namein.c
 * unit:     yes
 * function: EVENT_NAMEIN_Create, EVENT_NAMEIN_Main, EVENT_NAMEIN_StoreResult
 * address:  0x021CD2A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fld_trade_p01.c and fld_trade_p02.c (lane CL125b): no __FILE__ anchor, original unknown: the name-input event (0x50 work, launches overlay 0xC2) called by scrcmd_proc_fld.c and ov032 beacon_view.c.
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   MISC_GetBlock  0x0200C0F0  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GAME_DATA_GetItemUseWork  0x02012A54  thumb
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   MISC_GetGreetMessage  0x0200C1F4  thumb
 *   MISC_GetThanksMessage  0x0200C20C  thumb
 *   STRBUF_SetString  0x02045924  arm
 *   gNameInMaxLength     0x021DB44C  data  a1
 *   FIELD_STATUS_CreateSubProcEvent  0x020146F8  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   abs_id_C2      0x000000C2  data
 *   gNameInProcData     0x021F5580  data  ov194  a4
 *   MISC_SetGreetMessage  0x0200C1F8  thumb
 *   GAME_BEACON_UpdateGreeting  0x02027198  thumb
 *   MISC_SetThanksMessage  0x0200C210  thumb
 *   BEACON_STATUS_GetMessage  0x020275C4  thumb
 *   STRBUF_Copy  0x02045838  arm
 *   GAME_BEACON_SEARCH_SetFreeText  0x02165844  thumb  ov010
 */
struct Strbuf;
struct SaveControl;
struct GameData;
struct NameSave;
struct GameSystem;
struct GameEvent;
struct MyStatus;

#include "../types.h"

/* Parameter block of the name-input process (overlay 0xC2). */
typedef struct NameInParam {
    u32 mode;               /* 0x00 */
    u16 gender;             /* 0x04 */
    u8 pad06[0x18 - 0x06];
    u32 maxLength;          /* 0x18 */
    u32 cancelled;          /* 0x1C */
    struct Strbuf *name;    /* 0x20 */
    u8 pad24[0x28 - 0x24];
    struct NameSave *nameSave; /* 0x28 */
    u16 heapId;             /* 0x2C */
} NameInParam;

/* Event work (0x50 bytes). */
typedef struct NameInEvent {
    void *gameSystem;
    void *gameData;
    struct NameSave *nameSave;         /* 0x08 */
    void *myStatus;                 /* 0x0C */
    void *fieldMap;                 /* 0x10 */
    void *beaconSave;               /* 0x14 */
    u16 *resultVar;                 /* 0x18 */
    NameInParam param;              /* 0x1C */
    u32 mode;                       /* 0x4C */
} NameInEvent;

#include "../arm9/strbuf.h"
#include "../arm9/game_event.h"
#include "../arm9/gamesystem.h"
#include "../arm9/game_data.h"
struct MiscSave;
#include "../arm9/beacon.h"
#include "../arm9/mystatus.h"
struct FieldMap;
#include "../arm9/field_status.h"
struct Strbuf;
#include "../arm9/game_beacon.h"
struct BeaconStatus;
#include "../arm9/beacon_status.h"
#include "../ov010/game_beacon_set.h"

struct GameEvent *EVENT_NAMEIN_Create(void *gameSystem, void *fieldMap, void *parentEvent, u32 mode, u16 *resultVar);
int EVENT_NAMEIN_Main(struct GameEvent *event, int *seq, void *work);
void EVENT_NAMEIN_StoreResult(NameInEvent *work, NameInParam *param);

/* Maximum name length per mode 5..7. */
extern const u8 gNameInMaxLength[];
extern char gNameInProcData;
extern unsigned char abs_id_C2[];

/*
 * Creates the name-input event. Modes 5 and 6 edit one of two names of a
 * save block, mode 7 the beacon message (ov032 beacon_view.c).
 */
struct GameEvent *EVENT_NAMEIN_Create(void *gameSystem, void *fieldMap, void *parentEvent, u32 mode, u16 *resultVar)
{
    struct GameEvent *event;
    NameInEvent *work;

    event = GAME_EVENT_Create(gameSystem, parentEvent, EVENT_NAMEIN_Main, sizeof(NameInEvent));
    work = GAME_EVENT_GetWork(event);
    work->gameSystem = gameSystem;
    work->gameData = GAMESYSTEM_GetGameData(gameSystem);
    work->fieldMap = fieldMap;
    work->resultVar = resultVar;
    work->mode = mode;
    work->param.heapId = 4;
    work->nameSave = (struct NameSave *)MISC_GetBlock(GAME_DATA_GetSaveControl(work->gameData));
    work->myStatus = GAME_DATA_GetMyStatus(work->gameData);
    work->beaconSave = GAME_DATA_GetItemUseWork(work->gameData);
    work->param.mode = mode;
    work->param.gender = MYSTATUS_GetSex(work->myStatus);
    work->param.nameSave = work->nameSave;
    work->param.maxLength = gNameInMaxLength[mode - 5];
    work->param.name = (struct Strbuf *)STRBUF_Create(work->param.maxLength + 1, work->param.heapId);
    switch (mode) {
    case 5:
        STRBUF_SetString(work->param.name, MISC_GetGreetMessage((struct MiscSave *)work->nameSave));
        break;
    case 6:
        STRBUF_SetString(work->param.name, MISC_GetThanksMessage((struct MiscSave *)work->nameSave));
        break;
    case 7:
        break;
    }
    return event;
}

/*
 * Event: runs the name-input process (overlay 0xC2, abs_id_C2), then stores
 * the result.
 */
int EVENT_NAMEIN_Main(struct GameEvent *event, int *seq, void *workPtr)
{
    NameInEvent *work = workPtr;
    sptr proc;

    switch (*seq) {
    case 0:
        proc = (sptr)FIELD_STATUS_CreateSubProcEvent(work->gameSystem, (struct FieldMap *)work->fieldMap, (sptr)abs_id_C2, (void *)(&gNameInProcData), (void *)&work->param);
        GAME_EVENT_CallEvent((struct GameEvent *)event, (struct GameEvent *)proc);
        (*seq)++;
        break;
    case 1:
        EVENT_NAMEIN_StoreResult(work, &work->param);
        STRBUF_Delete((struct Strbuf *)work->param.name);
        return 1;
    }
    return 0;
}

/* Writes 1 to the result variable when a name was entered, then stores the name. */
void EVENT_NAMEIN_StoreResult(NameInEvent *work, NameInParam *param)
{
    u16 *resultVar = work->resultVar;

    if (resultVar) {
        if (param->cancelled == 0)
            *resultVar = 1;
        else
            *resultVar = 0;
    }
    if (param->cancelled == 1)
        return;
    switch (work->mode) {
    case 5:
        MISC_SetGreetMessage((struct MiscSave *)work->nameSave, (struct Strbuf *)param->name);
        GAME_BEACON_UpdateGreeting();
        return;
    case 6:
        MISC_SetThanksMessage((struct MiscSave *)work->nameSave, (struct Strbuf *)param->name);
        return;
    case 7:
        STRBUF_Copy((struct Strbuf *)BEACON_STATUS_GetMessage(work->beaconSave), (struct Strbuf *)work->param.name);
        GAME_BEACON_SEARCH_SetFreeText(param->name);
        return;
    }
}
