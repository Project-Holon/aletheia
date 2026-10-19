/*
 * file:     event_gsync.c
 * unit:     yes
 * function: EVENT_GSYNC_Main, EVENT_GSYNC_Entry, EVENT_GSYNC_Create
 * address:  0x021542C0
 * region:   ov000
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Straight-line constructor wrapper over the ARM9 object/service helpers.
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   GFL_USE_ClearSndHeap  0x02005C18  thumb
 *   GFL_USE_InitSound  0x02005B24  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   GFL_USE_SetBgmPaused  0x02005DE4  thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAME_SYNC_GetBlock  0x02009448  thumb
 *   BLOCK20_SAVEDATA_GetActive  0x02009304  thumb
 *   GAME_DATA_GetBoxManager  0x0201293C  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   BOX_SAVEDATA_CountNonEggPokemon  0x020079A0  thumb
 *   SYSTEM_DATA_GetConfig  0x0200873C  thumb
 *   GAME_EVENT_CallProc  0x02012444  thumb
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   GFL_NET_ERR_RequestScreen  0x0200FB38  thumb
 *   GFL_NET_ERR_ShowScreen  0x0200F7B8  thumb
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 *   ov123_id       0x0000007B  data   a1
 *   ov016_id       0x00000010  data   a1
 *   ov115_id       0x00000073  data   a1
 *   ov170_id       0x000000AA  data   a1
 *   d_021DA674     0x021DA674  data   ov123  a4
 *   d_021DA838     0x021DA838  data   ov123  a4
 *   d_021D77B8     0x021D77B8  data   ov016  a4
 *   gNetSaveMainProc     0x021D6338  data   ov115  a4
 *   gNetSaveRetryProc     0x021D654C  data   ov115  a4
 *   d_021EF78C     0x021EF78C  data   ov170  a4
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 */
struct GameSystem;
struct GameEvent;
struct GameData;
struct SaveControl;
struct BoxManager;
struct Party;
struct MyItem;
struct MyStatus;
struct Config;
struct WifiList;
struct FieldMap;
#include "../types.h"

/* Parameter block read by the WiFi login overlay (ov115). */
typedef struct WifiLoginParam {
    struct GameData *gameData;
    u32 loginType;
    u32 loginOption;
    u32 messageId;
    u8 *saveData;
    u32 useSaveData;
    u32 allowCancel;
    u32 result;
    u32 reserved[2];
} WifiLoginParam;

/* Parameter block of the second ov115 call (session confirm). */
typedef struct WifiConfirmParam {
    struct GameData *gameData;
    u32 loginType;
    u32 loginOption;
    u32 messageId;
    u8 *saveData;
    u32 useSaveData;
    u32 allowCancel;
} WifiConfirmParam;

/* Parameter block read by the box overlay (ov170) when the player picks a Pokemon to sync. */
typedef struct GsyncBoxParam {
    struct GameData *gameData;
    struct BoxManager *boxManager;
    struct Party *party;
    struct MyItem *myItem;
    u8 *myStatus;
    u32 reserved;
    struct Config *config;
    u32 result;
    u8 *pickerBuffer;
    u32 mode;
    u16 reserved2;
    u8 pickedBox;
    u8 pickedSlot;
} GsyncBoxParam;

/* Work of the game-sync event (0x2CC bytes). The first bytes are also the parameter block of the ov123 sync screen. */
typedef struct GsyncEventWork {
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct SaveControl *saveControl;
    u8 syncParam[0x44];
    u32 syncResult;
    u8 loginSaveData[0x174];
    u32 menuResult;
    u32 bgmPushed;
    u16 selectedBox;
    u16 selectedSlot;
    u32 savedBgmNo;
    u8 pickerBuffer[0x80];
    WifiLoginParam login;
    WifiConfirmParam confirm;
    GsyncBoxParam box;
    u32 returnToMenu;
} GsyncEventWork;

/* Same layout as GsyncEventWork in event_gsync.c: only the fields set here are listed. */
typedef struct GsyncEventWorkInit {
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct SaveControl *saveControl;
    u8 reserved[0x24C];
    struct GameData *loginGameData;
    u32 loginType;
    u32 loginOption;
    u32 loginMessageId;
} GsyncEventWorkInit;

extern void *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
extern struct GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeOut(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int effect, int skipWait);
extern struct GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeIn(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int effect, int skipWait, int restoreBg, unsigned char seasonShown, unsigned char seasonTarget);
extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);
extern struct GameEvent *FIELD_STATUS_CreateFieldCloseEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern void  MI_CpuFill8(void *dst, int value, int size);
extern void GAMESYSTEM_CallProc(struct GameSystem *gameSystem, u32 overlayId, void *procData, void *param);
extern u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *gameSystem);
extern u16 GFL_USE_GetBgmNo(void);
extern void  GFL_USE_ClearSndHeap(void);
extern void  GFL_USE_InitSound(void);
extern void  GFL_USE_CancelChangeAndPlayBgm(u32 bgmNo, u32 fadeTarget);
extern void GFL_USE_FadeInBgmFull(u32 frames);
extern struct GameEvent *FIELD_STATUS_CreateFieldOpenEvent(struct GameSystem *gameSystem);
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_SetBgmPaused(u32 value);
extern int GFL_USE_PushBgm(void);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
struct GameSyncData;
extern struct GameSyncData *GAME_SYNC_GetBlock(struct SaveControl *saveControl);
struct CgearSaveBlock;
extern u8 BLOCK20_SAVEDATA_GetActive(struct CgearSaveBlock *block);
extern u32 GAME_DATA_GetBoxManager(const struct GameData *gameData);
extern void *GAME_DATA_GetMyParty(const struct GameData *gameData);
extern void *GAME_DATA_GetMyItem(const struct GameData *gameData);
extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gd);
extern int BOX_SAVEDATA_CountNonEggPokemon(struct GameData *gameData);
extern struct Config *SYSTEM_DATA_GetConfig(void *saveControl);
extern void GAME_EVENT_CallProc(struct GameEvent *parent, u32 overlayId, void *procData, void *param);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern void  GFL_NET_ERR_RequestScreen(void);
extern u32 GFL_NET_ERR_ShowScreen(u32 isFatal);
extern u32 GAMESYSTEM_TryStartAutoComm(struct GameSystem *gameSystem);
struct GameEvent *GAME_EVENT_Create(void *gameSystem, void *a, void *callback, u32 workSize);
void *GAME_EVENT_GetWork(struct GameEvent *event);
u32 EVENT_GSYNC_Main(struct GameEvent *event, u32 *seq, GsyncEventWork *work);
void *EVENT_GSYNC_Entry(void *gameSystem);
void *EVENT_GSYNC_Create(void *gameSystem);
extern char ov123_id[];
extern char ov016_id[];
extern char ov115_id[];
extern char ov170_id[];
extern char d_021DA674[];
extern char d_021DA838[];
extern char d_021D77B8[];
extern char gNetSaveMainProc[];
extern char gNetSaveRetryProc[];
extern char d_021EF78C[];

u32 EVENT_GSYNC_Main(struct GameEvent *event, u32 *seq, GsyncEventWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;
    u32 fieldMap = (u32)GAMESYSTEM_GetFieldMap(gameSystem);
    int wifiFlag;

    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent((struct GameEvent *)event, (struct GameEvent *)EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, (struct FieldMap *)fieldMap, 0, 0));
        (*seq)++;
        break;
    case 1:
        GAME_EVENT_CallEvent((struct GameEvent *)event, (struct GameEvent *)FIELD_STATUS_CreateFieldCloseEvent((struct GameSystem *)gameSystem, (struct FieldMap *)fieldMap));
        work->returnToMenu = 0;
        *seq = 2;
        break;
    case 2:
        MI_CpuFill8(work->syncParam, 0, 0x44);
        work->syncResult = 0;
        GAMESYSTEM_CallProc(gameSystem, (u32)ov123_id, d_021DA674, work);
        (*seq)++;
        break;
    case 3:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0) {
            if (work->menuResult == 2)
                *seq = 16;
            else if (work->menuResult == 3)
                *seq = 5;
            else
                *seq = 10;
        }
        break;
    case 5:
        (*seq)++;
        break;
    case 6:
        work->savedBgmNo = GFL_USE_GetBgmNo();
        GFL_USE_ClearSndHeap();
        GAMESYSTEM_CallProc(gameSystem, (u32)ov016_id, d_021D77B8, work);
        (*seq)++;
        break;
    case 7:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0)
            *seq = 14;
        break;
    case 14:
        {
            vu16 *regIme = (vu16 *)0x04000208;
            u16 prevIme = *regIme;
            *regIme = 1;
            (void)prevIme;
        }
        GFL_USE_InitSound();
        GFL_USE_CancelChangeAndPlayBgm(work->savedBgmNo, 0xFFFF);
        GFL_USE_FadeInBgmFull(0x3C);
        *seq = 15;
        break;
    case 15:
        work->returnToMenu = 1;
        *seq = 2;
        break;
    case 10:
        GAME_EVENT_CallEvent((struct GameEvent *)event, (struct GameEvent *)FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*seq)++;
        break;
    case 11:
        GAME_EVENT_CallEvent((struct GameEvent *)event, (struct GameEvent *)EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, (struct FieldMap *)fieldMap, 0, 0, 1, 0, 0));
        (*seq)++;
        break;
    case 12:
        if (work->bgmPushed) {
            GFL_USE_PopBgm();
            GFL_USE_SetBgmPaused(0);
            GFL_USE_FadeInBgmFull(0x3C);
            work->bgmPushed = 0;
        }
        (*seq)++;
        break;
    case 13:
        return 1;
    case 16:
        wifiFlag = BLOCK20_SAVEDATA_GetActive((struct CgearSaveBlock *)GAME_SYNC_GetBlock(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(gameSystem))));
        if (BOX_SAVEDATA_CountNonEggPokemon((struct GameData *)GAME_DATA_GetBoxManager(GAMESYSTEM_GetGameData(gameSystem))) == 0 && wifiFlag == 0) {
            work->menuResult = 4;
            *seq = 19;
        } else {
            work->login.useSaveData = 0;
            GFL_USE_SetBgmPaused((u32)1);
            GFL_USE_PushBgm();
            work->bgmPushed = 1;
            (*seq)++;
        }
        break;
    case 17:
        work->login.saveData = work->loginSaveData;
        GAMESYSTEM_CallProc(gameSystem, (u32)ov115_id, gNetSaveMainProc, &work->login);
        (*seq)++;
        break;
    case 18:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0) {
            if (work->login.result == 1) {
                *seq = 10;
            } else {
                if (BLOCK20_SAVEDATA_GetActive((struct CgearSaveBlock *)GAME_SYNC_GetBlock(work->saveControl)) == 0) {
                    work->menuResult = 3;
                    *seq = 19;
                } else {
                    work->menuResult = 0;
                    *seq = 19;
                }
            }
        }
        break;
    case 19:
        GAMESYSTEM_CallProc(gameSystem, (u32)ov123_id, d_021DA838, work);
        (*seq)++;
        break;
    case 20:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0) {
            if (work->menuResult == 1) {
                work->returnToMenu = 0;
                *seq = 2;
            } else if (work->menuResult == 5) {
                *seq = 21;
            } else if (work->menuResult == 4) {
                *seq = 21;
            } else if (work->menuResult == 7) {
                work->login.useSaveData = 1;
                *seq = 17;
            } else {
                *seq = 23;
            }
        }
        break;
    case 21:
        work->box.gameData = GAMESYSTEM_GetGameData(gameSystem);
        work->box.boxManager = (struct BoxManager *)GAME_DATA_GetBoxManager(work->box.gameData);
        work->box.party = GAME_DATA_GetMyParty(work->box.gameData);
        work->box.myItem = GAME_DATA_GetMyItem(work->box.gameData);
        work->box.myStatus = (u8 *)GAME_DATA_GetMyStatus(work->box.gameData);
        work->box.config = SYSTEM_DATA_GetConfig(GAME_DATA_GetSaveControl(work->box.gameData));
        work->box.pickerBuffer = work->pickerBuffer;
        work->box.result = 0;
        work->box.mode = 5;
        GAME_EVENT_CallProc(event, (u32)ov170_id, (void *)d_021EF78C, (void *)&work->box);
        (*seq)++;
        break;
    case 22:
        if (GFL_NET_ERR_GetErrorLevel()) {
            GFL_NET_ERR_RequestScreen();
            GFL_NET_ERR_ShowScreen(0);
            work->login.useSaveData = 1;
            *seq = 17;
        } else {
            u8 box, slot;
            box = work->box.pickedBox;
            work->selectedBox = box;
            slot = work->box.pickedSlot;
            work->selectedSlot = slot;
            if (box == 0xff && slot == 0xff) {
                *seq = 23;
            } else {
                if (work->menuResult == 4)
                    work->menuResult = 2;
                else
                    work->menuResult = 1;
                *seq = 19;
            }
        }
        break;
    case 23:
        work->confirm.gameData = GAMESYSTEM_GetGameData(gameSystem);
        work->confirm.loginType = 1;
        work->confirm.loginOption = 0;
        GAMESYSTEM_CallProc(gameSystem, (u32)ov115_id, gNetSaveRetryProc, &work->confirm);
        (*seq)++;
        break;
    case 24:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0) {
            GAMESYSTEM_TryStartAutoComm(gameSystem);
            *(vu16 *)0x04000304 |= 0x8000;  /* POWCNT1: swap the two screens */
            work->returnToMenu = 0;
            *seq = 2;
            if (work->bgmPushed) {
                GFL_USE_PopBgm();
                GFL_USE_SetBgmPaused(0);
                GFL_USE_FadeInBgmFull(0x3C);
                work->bgmPushed = 0;
            }
        }
        break;
    }
    return 0;
}

/*
 * Thumb tail call through r3 (ldr r3, =target; bx r3). Labelled in wave D8.
 * Overlay entry point: forwards to the event constructor.
 */
void *EVENT_GSYNC_Entry(void *gameSystem)
{
    return EVENT_GSYNC_Create(gameSystem);
}

void *EVENT_GSYNC_Create(void *gameSystem)
{
    struct GameEvent *event;
    GsyncEventWorkInit *work;
    struct GameData *gameData;

    event = GAME_EVENT_Create(gameSystem, 0, EVENT_GSYNC_Main, 0x2CC);
    work = GAME_EVENT_GetWork(event);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    work->gameData = gameData;
    work->saveControl = GAME_DATA_GetSaveControl(gameData);
    work->gameSystem = gameSystem;
    work->loginGameData = GAMESYSTEM_GetGameData(gameSystem);
    work->loginType = 1;
    work->loginOption = 0;
    work->loginMessageId = 0x31;
    return event;
}
