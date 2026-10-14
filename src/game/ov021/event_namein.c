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
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200C0F0  0x0200C0F0  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GAME_DATA_GetItemUseWork  0x02012A54  thumb
 *   func_02008550  0x02008550  thumb
 *   func_0200C1F4  0x0200C1F4  thumb
 *   func_0200C20C  0x0200C20C  thumb
 *   STRBUF_SetString  0x02045924  arm
 *   gNameInMaxLength     0x021DB44C  data  a1
 *   FIELD_STATUS_CreateSubProcEvent  0x020146F8  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   abs_id_C2      0x000000C2  data
 *   gNameInProcData     0x021F5580  data  ov194  a4
 *   func_0200C1F8  0x0200C1F8  thumb
 *   GAME_BEACON_UpdateGreeting  0x02027198  thumb
 *   func_0200C210  0x0200C210  thumb
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

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

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

extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_Delete(struct Strbuf *vec);
extern struct GameEvent *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct GameEvent *event);
extern void *GAMESYSTEM_GetGameData(const struct GameSystem *p);
extern void *GAME_DATA_GetSaveControl(struct SaveControl *p);
extern void *func_0200C0F0(void *sys);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *GAME_DATA_GetItemUseWork(const struct GameData *p);
extern u8 func_02008550(const struct MyStatus *obj);
extern u16 *func_0200C1F4(struct NameSave *p);
extern u16 *func_0200C20C(struct NameSave *p);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern void *FIELD_STATUS_CreateSubProcEvent(char *a0, int a1, int a2, int a3, int a4);
extern void GAME_EVENT_CallEvent(struct GameEvent *evt, struct GameEvent **out);
extern void func_0200C1F8(struct NameSave *p, const u16 *src);
extern void GAME_BEACON_UpdateGreeting(void);
extern void func_0200C210(struct NameSave *p, const u16 *src);
extern int BEACON_STATUS_GetMessage(void *p);
extern void STRBUF_Copy(struct Strbuf *dst, struct Strbuf *src);
extern void GAME_BEACON_SEARCH_SetFreeText(void *v);

struct GameEvent *EVENT_NAMEIN_Create(void *gameSystem, void *fieldMap, void *parentEvent, u32 mode, u16 *resultVar);
int EVENT_NAMEIN_Main(struct GameEvent *event, int *seq, NameInEvent *work);
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

    event = func_020122C0(gameSystem, parentEvent, EVENT_NAMEIN_Main, 0x50);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->gameData = GAMESYSTEM_GetGameData(gameSystem);
    work->fieldMap = fieldMap;
    work->resultVar = resultVar;
    work->mode = mode;
    work->param.heapId = 4;
    work->nameSave = func_0200C0F0(GAME_DATA_GetSaveControl(work->gameData));
    work->myStatus = GAME_DATA_GetMyStatus(work->gameData);
    work->beaconSave = GAME_DATA_GetItemUseWork(work->gameData);
    work->param.mode = mode;
    work->param.gender = func_02008550(work->myStatus);
    work->param.nameSave = work->nameSave;
    work->param.maxLength = gNameInMaxLength[mode - 5];
    work->param.name = (struct Strbuf *)STRBUF_Create(work->param.maxLength + 1, work->param.heapId);
    switch (mode) {
    case 5:
        STRBUF_SetString(work->param.name, func_0200C1F4(work->nameSave));
        break;
    case 6:
        STRBUF_SetString(work->param.name, func_0200C20C(work->nameSave));
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
int EVENT_NAMEIN_Main(struct GameEvent *event, int *seq, NameInEvent *work)
{
    int proc;

    switch (*seq) {
    case 0:
        proc = (int)FIELD_STATUS_CreateSubProcEvent(work->gameSystem, (int)work->fieldMap, (int)abs_id_C2, (int)(&gNameInProcData), (int)&work->param);
        GAME_EVENT_CallEvent(event, (struct GameEvent **)proc);
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
        func_0200C1F8(work->nameSave, (const u16 *)param->name);
        GAME_BEACON_UpdateGreeting();
        return;
    case 6:
        func_0200C210(work->nameSave, (const u16 *)param->name);
        return;
    case 7:
        STRBUF_Copy((struct Strbuf *)BEACON_STATUS_GetMessage(work->beaconSave), (struct Strbuf *)work->param.name);
        GAME_BEACON_SEARCH_SetFreeText(param->name);
        return;
    }
}
