/*
 * file:     trcard_sys.c
 * unit:     yes
 * function: TRCARD_SYS_RunChildProc, TRCARD_SYS_Init, TRCARD_SYS_InitMinimal, TRCARD_SYS_Main, TRCARD_SYS_Exit, TRCARD_SYS_ExitMinimal, TRCARD_SYS_StateChooseScreen, TRCARD_SYS_StateStartCardProc, TRCARD_SYS_StateWaitCardProc, TRCARD_SYS_StateStartEditProc, TRCARD_SYS_StateWaitEditProc, TRCARD_SYS_StateStartBadgeProc, TRCARD_SYS_StateWaitBadgeProc, TRCARD_SYS_SumCappedRecords, TRCARD_SYS_BuildProfile, TRCARD_SYS_CreateViewWork, TRCARD_SYS_CreateEditWork, TRCARD_SYS_CountStars, TRCARD_SYS_ScrCmdSetRecordFlag36, TRCARD_SYS_ScrCmdStartFieldProc, TRCARD_SYS_ScrCmdRunScriptTask, TRCARD_SYS_SetRecordFlag36
 * address:  0x0216F088
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from trcard_sys.c (it held four originals); __FILE__ anchors: event_battle.c 0x0216E95C, trcard_sys.c 0x0216F0AC, waza_oshie.c 0x0216F918.
 *
 * symbols:
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   PROCSYS_Main  0x02031330  arm
 *   PROCSYS_Delete  0x0203133C  arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   d_02172B64     0x02172B64  data  ov010
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_GetTrainerView  0x02008554  thumb
 *   GAME_BEACON_SetTrainerView  0x02027174  thumb
 *   PROCSYS_FreeProcWork  0x020315D4  arm
 *   GFL_HEAP_DeleteChecked  0x020306F0  arm
 *   PROCSYS_Create 0x02031324 arm
 *   PROCSYS_Push 0x02031348 arm
 *   d_021725FC 0x021725FC data a4
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   gPmsInputProcData 0x021C39D4 data ov110 a4
 *   ov110_id 0x0000006E data a1
 *   TRCARD_SYS_RunChildProc  0x0216F088  thumb  ov010
 *   GREETING_SAVEDATA_GetFromSave  0x0200E6F0  thumb
 *   GREETING_SAVEDATA_SetSentence  0x0200E714  thumb
 *   GAME_BEACON_SetPms  0x0202715C  thumb
 *   d_021C892C 0x021C892C data a4 ov111
 *   RECORD_GetCounterClamped  0x02008DFC  thumb
 *   d_02172620     0x02172620  data  a2
 *   TRCARD_SIGN_GetFromSave  0x020089C0  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   CONSOLE_STAMP_GetDailyClock  0x02008B14  thumb
 *   RECORD_GetFromSave  0x02008C58  thumb
 *   GREETING_SAVEDATA_GetFromSaveThunk  0x0200E6E8  thumb
 *   MYSTATUS_IsNameEmpty  0x020084BC  thumb
 *   MYSTATUS_GetName  0x020084F4  thumb
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   MYSTATUS_GetId  0x02008530  thumb
 *   MISC_GetMoney  0x0200C274  thumb
 *   MISC_GetBadge  0x0200C234  thumb
 *   GAME_DATA_GetPlayTime  0x02012FCC  thumb
 *   PLAYTIME_GetHours  0x0200864C  thumb
 *   PLAYTIME_GetMinutes  0x02008650  thumb
 *   TRCARD_SIGN_GetColor  0x02008A0C  thumb
 *   TRCARD_SIGN_GetStyle  0x02008A28  thumb
 *   GREETING_SAVEDATA_GetSentence  0x0200E6FC  thumb
 *   MISC_GetThanksCount  0x0200C1DC  thumb
 *   INTRUDE_GetFromSave  0x0200BE48  thumb
 *   GPOWER_LoadPowerTable  0x02010F7C  thumb
 *   INTRUDE_GetObtainedFlags  0x0200BF54  thumb
 *   GAME_DATA_GetLastBattleRecSlot  0x020127B8  thumb
 *   GPOWER_FreePowerTable  0x02010F8C  thumb
 *   MISC_GetBestScore  0x0200C184  thumb
 *   RECORD_GetTrialScore  0x02008EA0  thumb
 *   RECORD_GetTrialRank  0x02008E78  thumb
 *   BLOCK20_SAVEDATA_GetBlockFromSys  0x0200921C  thumb
 *   CGEAR_SAVE_GetObtained  0x020090E0  thumb
 *   INTRUDE_GetPlaySeconds  0x0200BF94  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   ZUKAN_SAVE_CountSeen  0x0200D0AC  thumb
 *   TRCARD_SIGN_HasAnySignature  0x020089D0  thumb
 *   TRCARD_SIGN_GetBitmap  0x020089CC  thumb
 *   TOWN_MAP_SPOT_CountVisited  0x0216FEAC  thumb  ov010
 *   MIi_CpuCopy16  0x02082A60  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   RTC_ConvertSecondToDateTime  0x020891E0  arm
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   GAME_DATA_GetSaveBlock3A  0x02012EF0  thumb
 *   GAME_DATA_GetSaveBlock2A  0x02012F44  thumb
 *   ZUKAN_SAVE_IsNationalCaughtComplete  0x0200D298  thumb
 *   BSUBWAY_SCOREDATA_AccessFlag  0x0200DBA0  thumb
 *   MUSICAL_SAVE_HasAllProps  0x0200A73C  thumb
 *   INTRUDE_GetMissionScore  0x0200BDF8  thumb
 *   INTRUDE_GetMissionBonusScore  0x0200BDFC  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SP_POKE_GIMMICK_UpdatePairB  0x021F385C  thumb  ov059
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FIELD_GIMMICK_TIME_EFFECT_CallWaitEvent  0x021F38BC  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetWork 0x0200B3A4 thumb
 */

struct ZukanSave;
struct BtlSetup;
struct GameSystem;
struct BtlSetup;
struct RecordBlock;
struct BtlSetup;
struct ProcSys;
struct TrainerCardProfile;
struct MyStatus;
struct ProcSys;
struct PlayerSave;
struct BeaconRecord;
struct BadgeSave;
struct PlayTime;
struct BeaconRecord;
struct BattleRecSave;
struct TrainerCardSignature;
struct SaveClockOwner;
struct GameClearSave;
struct GameClearSave;
struct FlagSave;
struct RecordFlags;
typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef int s32;

typedef struct BtlSetup {
    u32 mode;           /* 0x00 */
    u8 pad04[0x14];
    u16 bgmId;          /* 0x18 */
    u8 pad1A[0x32];
    u32 *result;        /* 0x4C */
    u8 pad50[0x3C];
    u32 outcome;        /* 0x8C */
} BtlSetup;

/* Parameter block of the trainer card proc (24 bytes, copied into the work). */
typedef struct TrainerCardParam {
    struct TrainerCardProfile *profile;/* 0x00: caller's game data on entry, profile buffer in the work copy */
    void *saveData;                 /* 0x04 */
    u32 linkFlag;                   /* 0x08 */
    u32 nextScreen;                 /* 0x0C: set by the card proc, selects the next state */
    u32 result;                     /* 0x10 */
    u32 startScreen;                /* 0x14 */
} TrainerCardParam;

typedef struct TrainerCardWork {
    u32 heapId;                     /* 0x00 */
    u8 pad04[4];
    void *childProc;                /* 0x08 */
    void *playerSave;               /* 0x0C: parameter slot of the edit and badge procs */
    u8 pad10[4];
    u16 *editedBeacon;              /* 0x14 */
    TrainerCardParam *param;        /* 0x18 */
    int outfit;                     /* 0x1C */
} TrainerCardWork;

typedef struct MinimalWork {
    int heapId;                     /* 0x00 */
    u8 pad04[0x14];
    int param;                      /* 0x18 */
    u8 pad1C[4];
} MinimalWork;

typedef long long s64;

typedef struct RTCDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
} RTCDate;

typedef struct RTCTime {
    u32 hour;
    u32 minute;
    u32 second;
} RTCTime;

#include "../version.h"
#include "field_event_types.h"

typedef struct SaveClock {
    u8 pad[0x24];
    s64 firstPlaySec;    /* 0x24 */
    s64 clearSec;        /* 0x2C */
} SaveClock;

typedef struct ViewWork {
    void *bmpWin;                   /* 0x00 */
    void *cardData;                 /* 0x04 */
    void *profile;                  /* 0x08 */
    u32 phase;                      /* 0x0C */
    u32 reserved10;                 /* 0x10 */
    u32 reserved14;                 /* 0x14 */
} ViewWork;

typedef struct EditWork {
    u8 *profile;                    /* 0x00 */
    void *cardData;                 /* 0x04 */
    void *reserved08;               /* 0x08 */
    u32 phase;                      /* 0x0C */
    u32 reserved10;                 /* 0x10 */
    u32 reserved14;                 /* 0x14 */
} EditWork;

extern void *ZUKAN_SAVE_GetFromGameData(void *a);
struct GameData;
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *p);
extern void *GAMESYSTEM_GetFieldMap(const struct GameSystem *p);
extern void *GFL_HEAP_Alloc(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern u32 GFL_HEAP_Free(void *p);
extern unsigned int PROCSYS_Main(void *p);
extern int PROCSYS_Delete();
extern void GFL_HEAP_CreateChildHeap(unsigned int a, unsigned int b, unsigned int c);
struct Proc;
extern void *PROCSYS_AllocProcWork(struct Proc *proc, u32 size, u32 heapId);
extern void MI_CpuFill8(void *p, int v, int n);
extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gd);
extern u8 MYSTATUS_GetTrainerView(const struct MyStatus *obj);
extern int GAME_BEACON_SetTrainerView();
extern void PROCSYS_FreeProcWork(struct Proc *proc);
extern void GFL_HEAP_DeleteChecked(unsigned int heapId);
extern void *PROCSYS_Create(int heapId);
extern void PROCSYS_Push(void *,u32,const void *,void *);
int TRCARD_SYS_RunChildProc(void **childSlot);
int TRCARD_SYS_Init(void *proc, int state, TrainerCardParam *param);
int TRCARD_SYS_InitMinimal(void *proc, int state, int param);
int TRCARD_SYS_Main(int proc, int *state, int param, int work);
int TRCARD_SYS_Exit(int proc, int state, TrainerCardParam *param, TrainerCardWork *work);
int TRCARD_SYS_ExitMinimal(void *proc, int state, int param, MinimalWork *work);
int TRCARD_SYS_StateChooseScreen(TrainerCardWork *work, TrainerCardParam *param);
int TRCARD_SYS_StateStartCardProc(TrainerCardWork *work);
int TRCARD_SYS_StateWaitCardProc(TrainerCardWork *work);
struct SaveControl;
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gd);
extern void *GREETING_SAVEDATA_GetFromSave(u32 saveData);
struct QuadRecord;
extern void GREETING_SAVEDATA_SetSentence(struct QuadRecord *dst, s32 idx, struct QuadRecord *src);
struct GameBeaconPms;
extern void GAME_BEACON_SetPms(struct GameBeaconPms *pms);
extern u32 RECORD_GetCounterClamped(struct RecordBlock *obj, int i);
extern struct TrainerCardSignature *TRCARD_SIGN_GetFromSave(struct SaveControl *control);
extern void *GAME_DATA_GetMiscSave(struct GameData *gd);
struct DailyClock;
extern struct DailyClock *CONSOLE_STAMP_GetDailyClock(struct SaveControl *control);
extern struct RecordBlock *RECORD_GetFromSave(void *gameSystem);
extern void *GREETING_SAVEDATA_GetFromSaveThunk(u32 a);
extern int MYSTATUS_IsNameEmpty(struct MyStatus *mystatus);
extern const void *MYSTATUS_GetName(const void *p);
extern u8 MYSTATUS_GetSex(const struct MyStatus *obj);
extern u32 MYSTATUS_GetId(const struct MyStatus *obj);
struct MiscSave;
extern u32 MISC_GetMoney(struct MiscSave *beacon);
extern u32 MISC_GetBadge(struct MiscSave *beacon, u32 bit);
extern struct PlayTime *GAME_DATA_GetPlayTime(struct GameData *gd);
extern u16 PLAYTIME_GetHours(const struct PlayTime *p);
extern u8 PLAYTIME_GetMinutes(const struct PlayTime *p);
extern u16 TRCARD_SIGN_GetColor(const struct TrainerCardSignature *obj);
extern u8 TRCARD_SIGN_GetStyle(const struct TrainerCardSignature *obj);
extern void GREETING_SAVEDATA_GetSentence(struct QuadRecord *src, s32 idx, struct QuadRecord *dst);
extern u32 MISC_GetThanksCount(struct MiscSave *beacon);
struct IntrudeSave;
extern struct IntrudeSave *INTRUDE_GetFromSave(struct SaveControl *save);
struct GPowerData;
extern struct GPowerData *GPOWER_LoadPowerTable(u32 heapId);
extern void INTRUDE_GetObtainedFlags(struct IntrudeSave *intrude, u8 *dest, u32 size);
extern void *GAME_DATA_GetLastBattleRecSlot(struct GameData *gameData);
extern void GPOWER_FreePowerTable(struct GPowerData *table);
extern u32 MISC_GetBestScore(struct MiscSave *beacon);
extern u32 RECORD_GetTrialScore(struct RecordBlock *obj);
extern u8 RECORD_GetTrialRank(struct RecordBlock *obj);
struct CgearSaveBlock;
extern struct CgearSaveBlock *BLOCK20_SAVEDATA_GetBlockFromSys(void *p);
struct CGearSave;
extern u8 CGEAR_SAVE_GetObtained(struct CGearSave *save);
extern unsigned long long INTRUDE_GetPlaySeconds(struct IntrudeSave *intrude);
extern void *GAME_DATA_GetEventWork(struct GameData *gd);
struct EventWork;
extern u32 ZONEDATA_CheckEventFlag(struct EventWork *ev, s32 flagId);
extern u32 ZUKAN_SAVE_CountSeen(struct ZukanSave *p, u32 heapId);
extern int TRCARD_SIGN_HasAnySignature(const struct TrainerCardSignature *obj);
extern u32 *TRCARD_SIGN_GetBitmap(struct TrainerCardSignature *card);
extern int TOWN_MAP_SPOT_CountVisited(void *tbl, void *pos, u8 *flags);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void RTC_ConvertSecondToDateTime(RTCDate *date, RTCTime *time, s64 sec);
extern u16 STRBUF_GetEosChar(void);
extern void *GAME_DATA_GetSaveBlock3A(struct GameData *gd);
extern void *GAME_DATA_GetSaveBlock2A(struct GameData *gd);
extern int ZUKAN_SAVE_IsNationalCaughtComplete(struct ZukanSave *pZukan);
struct BsubwayScoreData;
extern u32 BSUBWAY_SCOREDATA_AccessFlag(struct BsubwayScoreData *p, s32 i, u32 op);
struct MusicalSave;
extern u32 MUSICAL_SAVE_HasAllProps(struct MusicalSave *musical);
extern u16 INTRUDE_GetMissionScore(struct IntrudeSave *intrude);
extern u16 INTRUDE_GetMissionBonusScore(struct IntrudeSave *intrude);
struct ScrcmdWork;
extern struct GameSystem *SCRCMD_WORK_GetGameSystem(struct ScrcmdWork *work);
struct FieldMap;
extern void SP_POKE_GIMMICK_UpdatePairB(struct FieldMap *fieldMap);
struct ScriptWork;
extern struct ScriptWork *SCRCMD_WORK_GetScriptWork(struct ScrcmdWork *work);
extern void *FIELD_GIMMICK_TIME_EFFECT_CallWaitEvent(void *gameSystem);
extern void SCRIPT_SYS_CallEvent(void *scriptWork, void *task);
extern u8 *GAME_DATA_GetFieldSave(struct GameData *gd);
struct GimmickWork;
extern s32 *GIMMICK_WORK_GetWork(struct GimmickWork *gimmick, u32 id);
int TRCARD_SYS_StateStartEditProc(TrainerCardWork *work);
int TRCARD_SYS_StateWaitEditProc(TrainerCardWork *work);
int TRCARD_SYS_StateStartBadgeProc(TrainerCardWork *work);
int TRCARD_SYS_StateWaitBadgeProc(TrainerCardWork *work);
u32 TRCARD_SYS_SumCappedRecords(void *records, int group, u32 cap);
void TRCARD_SYS_BuildProfile(TrainerCardProfile *out, void *save, int mode, int flag, volatile u16 heapId);
ViewWork *TRCARD_SYS_CreateViewWork(void *cardData, u32 heapId, void *profile);
EditWork *TRCARD_SYS_CreateEditWork(void *cardData, u8 *profile, u32 heapId);
int TRCARD_SYS_CountStars(void *save);
int TRCARD_SYS_ScrCmdSetRecordFlag36(void *unused, void *scriptCtx);
int TRCARD_SYS_ScrCmdStartFieldProc(void *unused, void *scriptCtx);
int TRCARD_SYS_ScrCmdRunScriptTask(void *unused, void *scriptCtx);
void TRCARD_SYS_SetRecordFlag36(void *gameSystem);
extern char d_02172B64[];
extern char d_021725FC[];
extern const u32 gPmsInputProcData[];
extern char ov110_id[];
extern const u32 d_021C892C[];
extern u16 d_02172620[][7];


int TRCARD_SYS_RunChildProc(void **childSlot)
{
    if (*childSlot != 0 && PROCSYS_Main(*childSlot) == 0) {
        PROCSYS_Delete(*childSlot);
        *childSlot = 0;
        return 1;
    }
    return 0;
}




int TRCARD_SYS_Init(void *proc, int state, TrainerCardParam *param)
{
    TrainerCardWork *work;

    GFL_HEAP_CreateChildHeap(1, 0x26, 0x18000);
    work = PROCSYS_AllocProcWork(proc, 0x20, 0x26);
    MI_CpuFill8(work, 0, 0x20);
    work->heapId = 0x26;
    work->param = GFL_HEAP_Alloc((u16)work->heapId, 0x18, 1, d_02172B64, 0x9f);
    *work->param = *param;
    work->param->profile = GFL_HEAP_Alloc((u16)work->heapId, 0x678, 1, d_02172B64, 0xa1);
    TRCARD_SYS_BuildProfile(work->param->profile, param->saveData, 0, work->param->linkFlag, (u16)work->heapId);
    work->outfit = work->param->profile->outfit;
    return 1;
}



int TRCARD_SYS_InitMinimal(void *proc, int state, int param)
{
    MinimalWork *work;

    GFL_HEAP_CreateChildHeap(1, 38, 0x18000);
    work = PROCSYS_AllocProcWork(proc, 32, 38);
    MI_CpuFill8(work, 0, 32);
    work->heapId = 38;
    work->param = param;
    return 1;
}




int TRCARD_SYS_Main(int proc, int *state, int param, int work)
{
    switch (*state) {
    case 0:
        *state = TRCARD_SYS_StateChooseScreen((TrainerCardWork *)work, (TrainerCardParam *)param);
        break;
    case 1:
        *state = TRCARD_SYS_StateStartCardProc((TrainerCardWork *)work);
        break;
    case 2:
        *state = TRCARD_SYS_StateWaitCardProc((TrainerCardWork *)work);
        break;
    case 3:
        *state = TRCARD_SYS_StateStartEditProc((TrainerCardWork *)work);
        break;
    case 4:
        *state = TRCARD_SYS_StateWaitEditProc((TrainerCardWork *)work);
        break;
    case 5:
        *state = TRCARD_SYS_StateStartBadgeProc((TrainerCardWork *)work);
        break;
    case 6:
        *state = TRCARD_SYS_StateWaitBadgeProc((TrainerCardWork *)work);
        break;
    case 7:
    default:
        return 1;
    }
    return 0;
}




/*
 * blocked:  listing 72 compiled 70
 */
int TRCARD_SYS_Exit(int proc, int state, TrainerCardParam *param, TrainerCardWork *work)
{
    u8 *myStatus;
    int outfit;

    if (param->linkFlag != 0) {
        myStatus = (u8 *)GAME_DATA_GetMyStatus(param->saveData);
        outfit = MYSTATUS_GetTrainerView((const struct MyStatus *)myStatus);
        if (work->outfit != outfit)
            outfit = GAME_BEACON_SetTrainerView(outfit);
    }
    param->result = work->param->result;
    GFL_HEAP_Free(work->param->profile);
    GFL_HEAP_Free(work->param);
    PROCSYS_FreeProcWork((struct Proc *)proc);
    GFL_HEAP_DeleteChecked(0x26);
    return 1;
}




int TRCARD_SYS_ExitMinimal(void *proc, int state, int param, MinimalWork *work)
{
    GFL_HEAP_Free((void *)work->param);
    PROCSYS_FreeProcWork(proc);
    GFL_HEAP_DeleteChecked(0x26);
    return 1;
}




int TRCARD_SYS_StateChooseScreen(TrainerCardWork *work, TrainerCardParam *param)
{
    struct TrainerCardProfile *profile;

    switch (param->startScreen) {
    case 1:
        return 1;
    case 2:
        return 1;
    case 3:
        return 5;
    case 0:
    default:
        profile = work->param->profile;
        if (profile->clearMonth == 0 && profile->playTimeSource != 0)
            return 5;
        return 1;
    }
}



/*
 * PROCSYS_Create forwards r0 to 02031354, which reads the heap input
 * and returns the allocation in r0. PROCSYS_Push forwards all four
 * inputs to 020314F4, which reads/stores r0-r3. Legacy void(void)
 * prototypes omit these live inputs and the observed return value.
 */
int TRCARD_SYS_StateStartCardProc(TrainerCardWork *work)
{
    if (work->childProc == 0)
        work->childProc = PROCSYS_Create((u16)work->heapId);
    PROCSYS_Push(work->childProc, -1, d_021725FC, work->param);
    return 2;
}



/*
 * Extent: two-byte zero alignment padding at 0216F2DE.
 */
int TRCARD_SYS_StateWaitCardProc(TrainerCardWork *work)
{
    int screen;

    if (!TRCARD_SYS_RunChildProc(&work->childProc))
        return 2;
    screen = work->param->nextScreen;
    if (screen == 1)
        return 3;
    if (screen == 2)
        return 5;
    return 7;
}





/*
 * Interface: 02031324 veneer forwards heap in r0 and returns allocation from
 * 02031354; 02031348 forwards all four arguments to 020314F4.
 */
int TRCARD_SYS_StateStartEditProc(TrainerCardWork *work)
{
    if (work->childProc == 0)
        work->childProc = PROCSYS_Create((u16)work->heapId);
    work->playerSave = GAME_DATA_GetSaveControl(work->param->saveData);
    PROCSYS_Push(work->childProc, (u32)ov110_id, gPmsInputProcData, &work->playerSave);
    return 4;
}






/*
 * Byte-correct. Blocker: GREETING_SAVEDATA_SetSentence (site +004C) is an unlabelled ARM9 Thumb
 * leaf (copies four halfwords to dst[idx*4]) whose only caller is this
 * function; no witness. Its C is parked: docs/notes/pkt_ov010_0200E714.c.txt
 * (register naming r3/r4 swapped).
 */
int TRCARD_SYS_StateWaitEditProc(TrainerCardWork *work)
{
    TrainerCardProfile *profile;
    u16 *beacon;
    int beaconSave;

    if (TRCARD_SYS_RunChildProc(&work->childProc) == 0)
        return 4;
    if (work->editedBeacon != 0) {
        beaconSave = (s32)GREETING_SAVEDATA_GetFromSave((u32)GAME_DATA_GetSaveControl(work->param->saveData));
        profile = work->param->profile;
        beacon = work->editedBeacon;
        profile->beaconRecord[0] = beacon[0];
        profile->beaconRecord[1] = beacon[1];
        profile->beaconRecord[2] = beacon[2];
        profile->beaconRecord[3] = beacon[3];
        GREETING_SAVEDATA_SetSentence((struct QuadRecord *)beaconSave, 0, (struct QuadRecord *)work->editedBeacon);
        GAME_BEACON_SetPms((struct GameBeaconPms *)work->editedBeacon);
    }
    return 1;
}





/*
 * hint. Pooled request ID is 110, so no proven ov111 loading path yet.
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 *
 * Interface: veneers preserve arguments and result as shown by their full
 * forwarding targets 02031354 and 020314F4.
 */
int TRCARD_SYS_StateStartBadgeProc(TrainerCardWork *work)
{
    if (work->childProc == 0)
        work->childProc = PROCSYS_Create((u16)work->heapId);
    work->playerSave = GAME_DATA_GetSaveControl(work->param->saveData);
    PROCSYS_Push(work->childProc, (u32)ov110_id, d_021C892C, work->param);
    return 6;
}





/*
 * Extent: two-byte zero alignment padding at 0216F3D2.
 */
int TRCARD_SYS_StateWaitBadgeProc(TrainerCardWork *work)
{
    if (!TRCARD_SYS_RunChildProc(&work->childProc))
        return 6;
    if (work->param->nextScreen == 3)
        return 1;
    return 7;
}






/*
 * Sums RECORD_GetCounterClamped over one seven-entry row of a u16 table (rows of 14
 * bytes at 0x02172620), stopping at the first zero entry and clamping the
 * running sum to cap.
 */
u32 TRCARD_SYS_SumCappedRecords(void *records, int group, u32 cap)
{
    u32 sum;
    int i;

    sum = 0;
    for (i = 0; i < 7; i++) {
        if (d_02172620[group][i] == 0)
            break;
        sum += RECORD_GetCounterClamped(records, d_02172620[group][i]);
        if (sum > cap)
            sum = cap;
    }
    return sum;
}






/*
 * Fills a 0x674-byte profile record from the save (name, flags, two RTC
 * dates, seven capped counters, a 0x600-byte blob). Byte-correct: 944/944,
 * every concrete byte right.
 *
 * Levers: the fifth (stack) parameter is `volatile u16`, which is what makes
 * the image re-read it from its stack home at both uses (0x0216F66C and
 * 0x0216F760); held in a register it takes r6 and the constant 1 that the
 * image keeps in r7 from 0x0216F608 to the fl0 insert at 0x0216F6E2 is
 * rematerialised instead. `out->f08 = 0` is written before `out->kind`.
 *
 * Blocker (MATCH, two sites): 0x02010F7C and 0x02010F8C are unlabelled ARM9
 * Thumb thunks whose only caller is this function, so neither call has a
 * witness. 0x02010F7C is `ldr r3, =0x02048F61; adds r2, r0, #0; movs r0,
 * #0x26; movs r1, #0; bx r3` (a heap-id forwarder, `return
 * ARC_TOOL_LoadMember(0x26, 0, heap);`), 0x02010F8C is `ldr r3, =0x020307B1;
 * bx r3` (`GFL_HEAP_Free(p);`). Matching either thunk (ARM9 territory)
 * closes that site.
 */
void TRCARD_SYS_BuildProfile(TrainerCardProfile *out, void *save, int mode, int flag, volatile u16 heap)
{
    RTCDate date;
    RTCTime time;
    u8 work[4];
    void *playerSave;
    void *signature;
    void *myStatus;
    void *badges;
    SaveClock *saveClock;
    void *records;
    void *beaconData;
    void *zukan;
    void *scratch;
    void *battleRec;
    u8 badgeIndex;
    u8 badgeBit;

    playerSave = GAME_DATA_GetSaveControl(save);
    signature = TRCARD_SIGN_GetFromSave(playerSave);
    myStatus = GAME_DATA_GetMyStatus(save);
    badges = GAME_DATA_GetMiscSave(save);
    saveClock = (SaveClock *)CONSOLE_STAMP_GetDailyClock(playerSave);
    records = RECORD_GetFromSave(playerSave);
    beaconData = GREETING_SAVEDATA_GetFromSaveThunk((u32)playerSave);
    zukan = ZUKAN_SAVE_GetFromGameData(save);

    if (MYSTATUS_IsNameEmpty(myStatus) == 0) {
        MIi_CpuCopy16(MYSTATUS_GetName(myStatus), out->name, 16);
    } else {
        out->name[0] = 'N';
        out->name[1] = 'o';
        out->name[2] = 'N';
        out->name[3] = 'a';
        out->name[4] = 'm';
        out->name[5] = 'e';
        out->name[6] = STRBUF_GetEosChar();
    }
    out->starCount = (u32)TRCARD_SYS_CountStars(save);
    out->outfitVariant = (u32)MYSTATUS_GetSex(myStatus);
    out->trainerId = MYSTATUS_GetId(myStatus);
    out->money = MISC_GetMoney(badges);
    out->badgeMask = 0;
    out->formatVersion = PM_VERSION_ID;
    for (badgeIndex = 0, badgeBit = 1; badgeIndex < 8; badgeIndex++) {
        if (MISC_GetBadge(badges, badgeIndex) == 1)
            out->badgeMask |= badgeBit;
        badgeBit <<= 1;
    }

    if (mode == 1) {
        scratch = (void *)GAME_DATA_GetPlayTime((struct GameData *)save);
        out->outfit = (u32)MYSTATUS_GetTrainerView(myStatus);
        out->isLinkMode = 0;
        out->playTimeSource = 0;
        out->playHours = (u32)PLAYTIME_GetHours(scratch);
        out->playMinutes = (u32)PLAYTIME_GetMinutes(scratch);
    } else {
        out->outfit = (u32)MYSTATUS_GetTrainerView(myStatus);
        out->isLinkMode = 1;
        out->playTimeSource = (u32)GAME_DATA_GetPlayTime((struct GameData *)save);
    }
    out->signatureColor = (u32)TRCARD_SIGN_GetColor(signature);
    out->signatureStyle = (u32)TRCARD_SIGN_GetStyle(signature);
    GREETING_SAVEDATA_GetSentence((struct QuadRecord *)beaconData, (u32)0, (struct QuadRecord *)out->beaconRecord);

    RTC_ConvertSecondToDateTime(&date, &time, saveClock->firstPlaySec);
    out->startYear = date.year;
    out->startMonth = date.month;
    out->startDay = date.day;
    if (saveClock->clearSec == 0) {
        out->clearYear = 0;
        out->clearMonth = 0;
        out->clearDay = 0;
        out->clearHour = 0;
        out->clearMinute = 0;
    } else {
        RTC_ConvertSecondToDateTime(&date, &time, saveClock->clearSec);
        out->clearYear = date.year;
        out->clearMonth = date.month;
        out->clearDay = date.day;
        out->clearHour = time.hour;
        out->clearMinute = time.minute;
    }

    out->recordSum0 = TRCARD_SYS_SumCappedRecords(records, 0, 999999999);
    out->recordSum1 = TRCARD_SYS_SumCappedRecords(records, 1, 999999999);
    out->recordSum2 = TRCARD_SYS_SumCappedRecords(records, 2, 999999999);
    out->recordSum3 = TRCARD_SYS_SumCappedRecords(records, 3, 999999999);
    out->recordSum4 = TRCARD_SYS_SumCappedRecords(records, 4, 999999999);
    out->recordSum5 = TRCARD_SYS_SumCappedRecords(records, 5, 999999999);
    out->recordSum6 = TRCARD_SYS_SumCappedRecords(records, 6, 999999999);
    out->badgeTotal = MISC_GetThanksCount(badges);
    out->recordSum7 = TRCARD_SYS_SumCappedRecords(records, 7, 9999);

    battleRec = INTRUDE_GetFromSave(playerSave);
    scratch = GPOWER_LoadPowerTable(heap);
    INTRUDE_GetObtainedFlags(battleRec, work, 2);
    out->visitedSpotCount = TOWN_MAP_SPOT_CountVisited(scratch, GAME_DATA_GetLastBattleRecSlot(save), work);
    GPOWER_FreePowerTable(scratch);

    out->recordSum8 = TRCARD_SYS_SumCappedRecords(records, 8, 9999);
    out->badgeExtraCount = MISC_GetBestScore(badges);
    out->recordTopValue = RECORD_GetTrialScore(records);
    out->recordTopFlag = (u32)RECORD_GetTrialRank(records);
    out->isGameCleared = (u32)CGEAR_SAVE_GetObtained((struct CGearSave *)BLOCK20_SAVEDATA_GetBlockFromSys(save));
    if (INTRUDE_GetPlaySeconds((struct IntrudeSave *)INTRUDE_GetFromSave(playerSave)) != 0)
        out->hasBattleRecord = 1;
    if (out->recordSum8 != 0)
        out->hasRecordSum8 = 1;
    if (RECORD_GetCounterClamped(records, (u16)0x78))
        out->hasRecordFlag78 = 1;
    if (RECORD_GetCounterClamped(records, (u16)0x79))
        out->hasRecordFlag79 = 1;
    if (ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(save), 2402) == 1)
        out->hasEventFlag2402 = 1;
    else
        out->hasEventFlag2402 = 0;
    out->pokedexCount = ZUKAN_SAVE_CountSeen(zukan, heap);
    out->hasSignature = (u32)TRCARD_SIGN_HasAnySignature(signature);
    MI_CpuCopy8(TRCARD_SIGN_GetBitmap(signature), out->signatureBitmap, 0x600);
    out->flagFromParam = flag;
}





ViewWork *TRCARD_SYS_CreateViewWork(void *cardData, u32 heapId, void *profile)
{
    ViewWork *view;

    view = GFL_HEAP_Alloc(heapId, 24, 1, d_02172B64, 0x321);
    MI_CpuFill8(view, 0, 24);
    view->bmpWin = 0;
    view->cardData = cardData;
    view->phase = 0;
    view->profile = profile;
    return view;
}




EditWork *TRCARD_SYS_CreateEditWork(void *cardData, u8 *profile, u32 heapId)
{
    EditWork *edit;

    edit = GFL_HEAP_Alloc(heapId, 24, 1, d_02172B64, 0x33a);
    edit->profile = profile;
    edit->cardData = cardData;
    edit->phase = 0;
    profile[4] = profile[4] & ~0x40;
    edit->profile[4] |= 0x80;
    return edit;
}





/*
 * Counts how many of five save-data conditions hold.
 *
 * Byte-correct (MATCH*, the 136-byte extent includes two bytes of pad).
 * unlabelled ARM9 Thumb thunk (`ldr r0, [r0]; ldr r3, =0x020071CD;
 * movs r1, #0x3a; bx r3`, i.e. `return SAVE_CONTROL_GetBlock(*p, 0x3A);`, with the
 * sibling at 0x02012F00 passing 0x3B) whose only caller is this function.
 * Matching that thunk (ARM9 territory) or seeding its start closes this file.
 */
int TRCARD_SYS_CountStars(void *save)
{
    int n;
    void *a;
    void *b;
    void *c;

    n = 0;
    a = GAME_DATA_GetSaveBlock3A(save);
    b = GAME_DATA_GetSaveBlock2A(save);
    c = GAME_DATA_GetLastBattleRecSlot(save);
    if (ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(save), 0x960))
        n++;
    if (ZUKAN_SAVE_IsNationalCaughtComplete(ZUKAN_SAVE_GetFromGameData(save)))
        n++;
    if (BSUBWAY_SCOREDATA_AccessFlag(a, 7, 0) && BSUBWAY_SCOREDATA_AccessFlag(a, 8, 0))
        n++;
    if (MUSICAL_SAVE_HasAllProps(b))
        n++;
    if (INTRUDE_GetMissionScore(c) >= 30 && INTRUDE_GetMissionBonusScore(c) >= 30)
        n++;
    return n;
}





int TRCARD_SYS_ScrCmdSetRecordFlag36(void *unused, void *scriptCtx)
{
    void *gameSystem;

    gameSystem = SCRCMD_WORK_GetGameSystem(scriptCtx);
    TRCARD_SYS_SetRecordFlag36(gameSystem);
    return 0;
}





/*
 * blocked:
 */
int TRCARD_SYS_ScrCmdStartFieldProc(void *unused, void *scriptCtx)
{
    SP_POKE_GIMMICK_UpdatePairB(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(scriptCtx)));
    return 0;
}





int TRCARD_SYS_ScrCmdRunScriptTask(void *unused, void *scriptCtx)
{
    void *scriptWork;
    void *gameSystem;
    void *task;

    scriptWork = SCRCMD_WORK_GetScriptWork(scriptCtx);
    gameSystem = SCRCMD_WORK_GetGameSystem(scriptCtx);
    task = FIELD_GIMMICK_TIME_EFFECT_CallWaitEvent(gameSystem);
    SCRIPT_SYS_CallEvent(scriptWork, task);
    return 1;
}




/*
 * Extent: two-byte zero alignment padding at 0216F916.
 * Interface: the call explicitly supplies r1=0x36 even though the leaf reads only r0.
 */
void TRCARD_SYS_SetRecordFlag36(void *gameSystem)
{
    *GIMMICK_WORK_GetWork((struct GimmickWork *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(gameSystem)), 0x36) = 1;
}
