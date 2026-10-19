/*
 * file:     game_beacon.c
 * unit:     yes
 * function: GAME_BEACON_Create, GAME_BEACON_Update, GAME_BEACON_Setup, GAME_BEACON_GetMyInfo, GAME_BEACON_SendIfRequested, GAME_BEACON_UpdateActionTime, GAME_BEACON_AddLog, GAME_BEACON_ReceiveInfo, GAME_BEACON_GetLogFromWork, GAME_BEACON_GetLog, GAME_BEACON_GetLogByReceiveNoFromWork, GAME_BEACON_GetLogByReceiveNo, GAME_BEACON_GetReceiveCount, GAME_BEACON_GetNextNewLogIndex, GAME_BEACON_ClearNewFlag, GAME_BEACON_SetNewFlagByTrainerId, GAME_BEACON_GetReceivedFramesByTrainerId, GAME_BEACON_BuildMyInfo, GAME_BEACON_RequestSend, GAME_BEACON_CheckActionPriority, GAME_BEACON_IsSpecialPokemon, GAME_BEACON_CopyStrbufCodes, GAME_BEACON_PopQuestionnaireUpdated, GAME_BEACON_SetQuestionnaire, GAME_BEACON_SetNationArea, GAME_BEACON_SetResearchTeamRank, GAME_BEACON_SetPms, GAME_BEACON_SetTrainerView, GAME_BEACON_UpdateGreeting, GAME_BEACON_SetPokeCapture, GAME_BEACON_SetPokeGet, GAME_BEACON_SetSpecialPokeGet, GAME_BEACON_SetPokeLevelUp, GAME_BEACON_SetPokeEvolution, GAME_BEACON_SetPlayTime, GAME_BEACON_SetItemUse, GAME_BEACON_SetZone, GAME_BEACON_SetInfoZone, GAME_BEACON_SetDetailsBattleWildPoke, GAME_BEACON_SetDetailsBattleSpecialPoke, GAME_BEACON_SetDetailsBattleTrainer, GAME_BEACON_SetDetailsBattleLeader, GAME_BEACON_SetDetailsBattleBigFour, GAME_BEACON_ResetDetails, GAME_BEACON_WritePms, GAME_BEACON_SetMyPms, GAME_BEACON_RegisterClearCallback, GAME_BEACON_ClearFlags
 * address:  0x020266E0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from game_beacon.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC  arm
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   GF_PANIC_Fail  0x02034714  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GAME_BEACON_Work     0x02146940  data
 *   GAME_BEACON_AssertText     0x020A74BC  data
 *   GAME_BEACON_FileName     0x020A74C0  data
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GAME_DATA_GetPlayTime  0x02012FCC  thumb
 *   PLAYTIME_GetHours  0x0200864C  thumb
 *   MI_CpuCopy8    0x02082D44  arm
 *   NET_WHPIPE_PublishBeacon  0x0217778C  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SYMBOL_SAVE_GetBitBlock  0x0200E394  thumb
 *   MISC_SAVEDATA_GetStatusByte  0x0200E44C  thumb
 *   QUESTIONNAIRE_GetAnswerMax  0x02167394  thumb
 *   SYMBOL_SAVE_ReadBitField  0x0200E3A4  thumb
 *   MISC_SAVEDATA_IsTallyFull  0x0200E49C  thumb
 *   MISC_SAVEDATA_AddHalfwordClamped  0x0200E460  thumb
 *   MISC_SAVEDATA_AddTallyValue  0x0200E4CC  thumb
 *   MISC_GetBlock  0x0200C0F0  thumb
 *   MISC_GetRecentId  0x0200C33C  thumb
 *   MISC_AddRecentValue  0x0200C364  thumb
 *   GREETING_SAVEDATA_GetFromSaveThunk    0x0200E6E8  thumb
 *   OS_GetOwnerInfo  0x02087C88  arm
 *   GAME_DATA_GetMyPlayerWork    0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId    0x02012AC8  thumb
 *   ZONEDATA_IsUnionRoom    0x02013CC8  thumb
 *   ZONEDATA_IsZone96Pair    0x02013CE0  thumb
 *   GAME_DATA_GetSpecialLocation    0x02012894  thumb
 *   SYMBOL_MAP_ResolveZoneId    0x02166C7C  thumb
 *   MYSTATUS_GetIdLow16    0x02008534  thumb
 *   MYSTATUS_GetTrainerView    0x02008554  thumb
 *   MYSTATUS_GetNation    0x0200856C  thumb
 *   MYSTATUS_GetArea    0x02008570  thumb
 *   MISC_GetResearchRank    0x0200C224  thumb
 *   MISC_GetGreetCount    0x0200C1C4  thumb
 *   MISC_GetThanksCount    0x0200C1DC  thumb
 *   PLAYTIME_GetMinutes    0x02008650  thumb
 *   SYMBOL_SAVE_GetQuestionnaireBits    0x0200E3A0  thumb
 *   GREETING_SAVEDATA_GetSentence    0x0200E6FC  thumb
 *   STRBUF_GetEosChar    0x02045A98  arm
 *   MYSTATUS_GetName    0x020084F4  thumb
 *   MISC_GetGreetMessage    0x0200C1F4  thumb
 *   GAME_BEACON_ActionTable    0x0209FC20  data
 *   GAME_BEACON_SpecialPokemonTable  0x0209FC04  data
 *   STRBUF_ToChars       0x02045A38  arm
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   CARD_SPI_CheckCardId  0x021809D8  thumb ov231
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   GFL_USE_AddHBlankTask  0x02005624  thumb
 *   ov231_id       0x000000E7  data
 */
#include "game_beacon_types.h"
#include "game_comm_shared_types.h"

struct PlayerWork;

struct PlayTime;

struct SaveControl;

struct MiscSave;

struct QuestionnaireSave;

struct PmsSave;

typedef signed int     s32;

/* Per-action priority and display time. */
typedef struct GameBeaconActionInfo {
    u32 priority : 8;
    u32 frames : 24;
} GameBeaconActionInfo;

/* Only the zone id of the location GAME_DATA_GetSpecialLocation answers is read here. */
struct WarpLocation {
    u32 locationType;
    s16 zoneId;
};

typedef struct {
    u8  language;
    u8  favoriteColor;
    u8  month;
    u8  day;
    u16 nickName[11];
    u16 nickNameLength;
    u16 comment[27];
    u16 commentLength;
} OSOwnerInfo;

extern void MI_CpuFill8(void *dst, u8 value, u32 size);

extern void MI_CpuCopy8(const void *src, void *dst, unsigned int size);

extern void OS_GetOwnerInfo(OSOwnerInfo *info);

extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gameData);

extern u32 MYSTATUS_GetSex(const struct MyStatus *status);

extern void GF_PANIC_Fail(const char *expr, u32 line, const char *file);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);

extern int  GFL_NET_GetRunState(void);

extern struct PlayTime *GAME_DATA_GetPlayTime(struct GameData *gameData);

extern u16 PLAYTIME_GetHours(const struct PlayTime *playTime);

extern u8 PLAYTIME_GetMinutes(const struct PlayTime *playTime);

extern void NET_WHPIPE_PublishBeacon(void);

extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);

extern struct QuestionnaireSave *SYMBOL_SAVE_GetBitBlock(struct SaveControl *save);

extern int   MISC_SAVEDATA_GetStatusByte(struct QuestionnaireSave *questionnaire, int slot);

extern u32   QUESTIONNAIRE_GetAnswerMax(u8 questionId);

extern u32   SYMBOL_SAVE_ReadBitField(const u8 *answers, u8 questionId);

extern u32 MISC_SAVEDATA_IsTallyFull(struct QuestionnaireSave *questionnaire, u32 questionId, u32 answer);

extern void MISC_SAVEDATA_AddHalfwordClamped(struct QuestionnaireSave *questionnaire, int questionId, int counted);

extern void MISC_SAVEDATA_AddTallyValue(struct QuestionnaireSave *questionnaire, u32 questionId, u32 answer, int count);

extern const u8 *SYMBOL_SAVE_GetQuestionnaireBits(struct QuestionnaireSave *questionnaire);

extern struct MiscSave *MISC_GetBlock(struct SaveControl *save);

extern int MISC_GetRecentId(struct MiscSave *misc, u8 slot);

extern void MISC_AddRecentValue(struct MiscSave *misc, u8 slot, int value);

extern u8 MISC_GetResearchRank(struct MiscSave *misc);

extern u32 MISC_GetGreetCount(struct MiscSave *misc);

extern u32 MISC_GetThanksCount(struct MiscSave *misc);

extern u16 *MISC_GetGreetMessage(struct MiscSave *misc);

extern struct PmsSave *GREETING_SAVEDATA_GetFromSaveThunk(struct SaveControl *save);

extern void GREETING_SAVEDATA_GetSentence(struct PmsSave *pmsSave, int index, GameBeaconPms *dst);

extern struct PlayerWork *GAME_DATA_GetMyPlayerWork(struct GameData *gameData);

extern u16 GAME_DATA_GetPlayerZoneId(const struct PlayerWork *player);

extern u32 ZONEDATA_IsUnionRoom(u16 zoneId);

extern u32 ZONEDATA_IsZone96Pair(u16 zoneId);

extern struct WarpLocation *GAME_DATA_GetSpecialLocation(const struct GameData *gameData);

extern u32 SYMBOL_MAP_ResolveZoneId();

extern u16 MYSTATUS_GetIdLow16(const struct MyStatus *status);

extern u8 MYSTATUS_GetTrainerView(const struct MyStatus *status);

extern u8 MYSTATUS_GetNation(const struct MyStatus *status);

extern u8 MYSTATUS_GetArea(const struct MyStatus *status);

extern u16 *MYSTATUS_GetName(const struct MyStatus *status);

extern u16   STRBUF_GetEosChar(void);

extern void STRBUF_ToChars(const struct Strbuf *str, u16 *codes, u32 count);

extern int   GF_OVERLAY_Load(signed int overlayId);

extern int   CARD_SPI_CheckCardId(void);

extern void  GF_OVERLAY_Unload(int overlayId);

extern void *GFL_USE_AddHBlankTask(void (*func)(void), u32 arg, u32 priority);

void GAME_BEACON_Create(u32 heapId);

void GAME_BEACON_Update(void);

void GAME_BEACON_Setup(struct GameData *gameData);

void GAME_BEACON_GetMyInfo(GameBeaconInfo *dst);

void GAME_BEACON_SendIfRequested(void);

void GAME_BEACON_UpdateActionTime(GameBeaconRecord *own);

void GAME_BEACON_AddLog(GameBeaconWork *work, const GameBeaconInfo *info);

int GAME_BEACON_ReceiveInfo(const GameBeaconInfo *info);

GameBeaconRecord *GAME_BEACON_GetLogFromWork(GameBeaconWork *work, int index);

GameBeaconRecord *GAME_BEACON_GetLog(int index);

GameBeaconRecord *GAME_BEACON_GetLogByReceiveNoFromWork(GameBeaconWork *work, int receiveNo);

GameBeaconRecord *GAME_BEACON_GetLogByReceiveNo(int receiveNo);

u32 GAME_BEACON_GetReceiveCount(void);

int GAME_BEACON_GetNextNewLogIndex(int *cursor);

void GAME_BEACON_ClearNewFlag(u32 index);

int GAME_BEACON_SetNewFlagByTrainerId(const GameBeaconInfo *info);

u16 GAME_BEACON_GetReceivedFramesByTrainerId(u16 trainerId);

void GAME_BEACON_BuildMyInfo(GameBeaconInfo *info, struct GameData *gameData);

void GAME_BEACON_RequestSend(GameBeaconRecord *record);

u32 GAME_BEACON_CheckActionPriority(u32 action);

int GAME_BEACON_IsSpecialPokemon(u16 monsNo);

void GAME_BEACON_CopyStrbufCodes(const struct Strbuf *str, u16 *dest);

u8 GAME_BEACON_PopQuestionnaireUpdated(void);

void GAME_BEACON_SetQuestionnaire(const u8 *answers);

void GAME_BEACON_SetNationArea(u8 nation, u8 area);

void GAME_BEACON_SetResearchTeamRank(u32 rank);

void GAME_BEACON_SetPms(const GameBeaconPms *pms);

void GAME_BEACON_SetTrainerView(u32 trainerView);

void GAME_BEACON_UpdateGreeting(void);

void GAME_BEACON_SetPokeCapture(u16 monsNo);

void GAME_BEACON_SetPokeGet(u16 monsNo);

void GAME_BEACON_SetSpecialPokeGet(u16 monsNo);

void GAME_BEACON_SetPokeLevelUp(u16 nickname);

void GAME_BEACON_SetPokeEvolution(u16 monsNo, u16 nickname);

void GAME_BEACON_SetPlayTime(u32 playHours);

void GAME_BEACON_SetItemUse(u16 itemNo);

void GAME_BEACON_SetZone(u32 zoneId, u32 zoneSource);

void GAME_BEACON_SetInfoZone(GameBeaconInfo *info, u32 zoneId, u32 zoneSource);

void GAME_BEACON_SetDetailsBattleWildPoke(GameBeaconInfo *info, u16 monsNo);

void GAME_BEACON_SetDetailsBattleSpecialPoke(GameBeaconInfo *info, u16 monsNo);

void GAME_BEACON_SetDetailsBattleTrainer(GameBeaconInfo *info, u16 trainerId);

void GAME_BEACON_SetDetailsBattleLeader(GameBeaconInfo *info, u16 trainerId);

void GAME_BEACON_SetDetailsBattleBigFour(GameBeaconInfo *info, u16 trainerId);

void GAME_BEACON_ResetDetails(GameBeaconInfo *info);

void GAME_BEACON_WritePms(GameBeaconInfo *info, const GameBeaconPms *pms);

void GAME_BEACON_SetMyPms(const GameBeaconPms *pms);

void GAME_BEACON_RegisterClearCallback(void);

void GAME_BEACON_ClearFlags(void);

extern GameBeaconWork *GAME_BEACON_Work;

extern char   GAME_BEACON_AssertText[];

extern char   GAME_BEACON_FileName[];

extern const GameBeaconActionInfo GAME_BEACON_ActionTable[];

extern const u16 GAME_BEACON_SpecialPokemonTable[];

extern char  ov231_id[];

/*
 * Allocates the 0xbb4-byte beacon system block on the caller's heap and
 * publishes it through GAME_BEACON_Work, after releasing any previous one.
 *
 * The two spellings that decided it:
 *   - the third argument (1) is bound to a NAMED local `one`, which keeps
 *     it alive in the callee-saved r4 across the call to GFL_HEAP_Alloc;
 *     the trailing -1 store is then derived from it as `subs r2, r4, #2`.
 *     Written as a plain -1 / 0xff / (u8)-1, the compiler folds it to
 *     `movs r2, #0xff` before the call and the r4/r5 assignment flips.
 *   - 0xbb4 stays a plain integer literal: the compiler pools it of its
 *     own accord, so no absolute linker symbol is needed (an earlier
 *     attempt that declared it as `extern char sBeaconSize[]` produced
 *     the same 72 bytes but capped at MATCH on that unattestable ABS32).
 *
 * 0x020A74BC resolves through sole-ref; 0x020A74C0 is the __FILE__ string.
 */
void GAME_BEACON_Create(u32 heapId)
{
    u32 one = 1;

    if (GAME_BEACON_Work != 0) {
        GF_PANIC_Fail(GAME_BEACON_AssertText, 0, GAME_BEACON_AssertText);
    }
    GAME_BEACON_Work = GFL_HEAP_Alloc(heapId, sizeof(GameBeaconWork), one, GAME_BEACON_FileName, 0x5a);
    GAME_BEACON_Work->newestIndex = (u8)(one - 2);
}

void GAME_BEACON_Update(void)
{
    GameBeaconWork *work;
    s32 playHours;
    s32 i;

    work = GAME_BEACON_Work;
    if (work == 0) {
        return;
    }
    if (GFL_NET_GetRunState() == 0) {
        return;
    }
    if (work->gameData != 0) {
        playHours = PLAYTIME_GetHours(GAME_DATA_GetPlayTime(work->gameData));
        if (work->lastPlayHours != playHours) {
            switch (playHours) {
            case 10:
            case 30:
            case 50:
            case 100:
                GAME_BEACON_SetPlayTime(playHours);
                break;
            }
        }
        work->lastPlayHours = (u16)playHours;
    }
    GAME_BEACON_UpdateActionTime(&work->own);
    for (i = 0; i < 30; i++) {
        if (work->log[i].info.versionBit != 0) {
            if (work->log[i].elapsed.receivedFrames < 0xffff) {
                work->log[i].elapsed.receivedFrames += 1;
            }
        }
    }
}

void GAME_BEACON_Setup(struct GameData *gameData)
{
    GameBeaconWork *work = GAME_BEACON_Work;

    work->gameData = gameData;
    GAME_BEACON_BuildMyInfo(&work->own.info, gameData);
    GAME_BEACON_Work->lastPlayHours = PLAYTIME_GetHours(GAME_DATA_GetPlayTime(gameData));
}

void GAME_BEACON_GetMyInfo(GameBeaconInfo *dst)
{
    MI_CpuCopy8(&GAME_BEACON_Work->own.info, dst, sizeof(GameBeaconInfo));
}

void GAME_BEACON_SendIfRequested(void)
{
    if (GAME_BEACON_Work->own.sendRequest == 1) {
        if (GFL_NET_GetRunState() == 1) {
            NET_WHPIPE_PublishBeacon();
            GAME_BEACON_Work->own.sendRequest = 0;
        }
    }
}

void GAME_BEACON_UpdateActionTime(GameBeaconRecord *own)
{
    u16 action = own->info.action;

    if (action == 1) {
        return;
    }
    own->elapsed.actionFrames += 1;
    if ((u32)own->elapsed.actionFrames > GAME_BEACON_ActionTable[action].frames) {
        own->elapsed.actionFrames = 0;
        own->info.action = 1;
    }
}

static inline u32 GAME_BEACON_GetAnswer(const GameBeaconInfo *info, int questionId)
{
    u32 answer;

    if (questionId == 0x1d) {
        answer = info->playHours / 10 + 1;
        if (answer > QUESTIONNAIRE_GetAnswerMax(questionId))
            answer = QUESTIONNAIRE_GetAnswerMax(questionId);
    } else {
        answer = SYMBOL_SAVE_ReadBitField(info->questionnaire, questionId);
    }
    return answer;
}

/*
 * The ring insert: advance hi with a wrap at 30 (pushing lo along when the
 * ring is full), grant the record's items through the bag (0x0200E394
 * family), mark matching entries in the 0x0200C0F0 table, then clear the
 * slot, struct-copy the 92-byte payload in, zero +0x5c, set the live bit
 * and bump the +0xBAE fill count.
 *
 * `bl 0x02167394` sites are the only references to that address in the
 * whole image, all inside this range, and no overlay listing labels a
 * function there (ov009 and ov010 both cover the address, interior to
 * code), so no class attests it and no cut helps (--suggest-split).
 *
 * Two spellings the bytes need: the item-amount helper takes an INT id
 * (the `cmp r,#0x1d` is on the untruncated value; the callees' u8
 * parameters produce the lsls/lsrs at each call), and the slot is one
 * pointer `&slots[hi]` which the compiler keeps as base+0x64 and
 * hi*0x60 in two stack slots.
 */
void GAME_BEACON_AddLog(GameBeaconWork *work, const GameBeaconInfo *info)
{
    struct QuestionnaireSave *questionnaire;
    struct SaveControl *save;
    struct QuestionnaireSave *researchQuestionnaire;
    struct MiscSave *misc;
    int i;
    int j;
    int questionId;
    u32 answer;
    GameBeaconRecord *record;

    work->newestIndex++;
    if (work->newestIndex >= 30)
        work->newestIndex = 0;
    record = &work->log[work->newestIndex];
    if (work->logCount > 0 && work->newestIndex == work->oldestIndex) {
        work->oldestIndex++;
        if (work->oldestIndex >= 30)
            work->oldestIndex = 0;
    }
    questionnaire = SYMBOL_SAVE_GetBitBlock(GAME_DATA_GetSaveControl(work->gameData));
    for (i = 0; i < 3; i++) {
        questionId = MISC_SAVEDATA_GetStatusByte(questionnaire, i);
        if (questionId != 0xff) {
            answer = GAME_BEACON_GetAnswer(info, questionId);
            if (answer != 0 && MISC_SAVEDATA_IsTallyFull(questionnaire, questionId, answer) == 0) {
                MISC_SAVEDATA_AddHalfwordClamped(questionnaire, questionId, 1);
                MISC_SAVEDATA_AddTallyValue(questionnaire, questionId, answer, 1);
                work->questionnaireUpdated = 1;
            }
        }
    }
    save = GAME_DATA_GetSaveControl(work->gameData);
    researchQuestionnaire = SYMBOL_SAVE_GetBitBlock(save);
    misc = MISC_GetBlock(save);
    for (i = 0; i < 3; i++) {
        questionId = MISC_GetRecentId(misc, i);
        if (questionId != 0xff) {
            for (j = 0; j < 3; j++) {
                if (questionId == MISC_SAVEDATA_GetStatusByte(researchQuestionnaire, j)) {
                    if (GAME_BEACON_GetAnswer(info, questionId) != 0)
                        MISC_AddRecentValue(misc, i, 1);
                }
            }
        }
    }
    MI_CpuFill8(record, 0, sizeof(GameBeaconRecord));
    record->info = *info;
    record->elapsed.receivedFrames = 0;
    work->newMask |= 1 << work->newestIndex;
    if (work->logCount < 30)
        work->logCount++;
}

/*
 * The duplicate/accept scan over the receive ring.  Closed 2026-09-23 by
 * writing the ring walk as the plain two-case shape: `if (lo <= hi)` one
 * loop over lo..hi, `else` a loop over lo..29 THEN a loop over 0..hi, each
 * hit doing `hit = 1; break;`.  The compiler itself cross-jumps loop 3's hit
 * block into loop 1's (both continue at the tail) and keeps loop 2's, whose
 * break lands on loop 3's `i = 0`; the earlier goto/label construction in
 * docs/notes/GAME_BEACON_ReceiveInfo.c.txt only imitated that and left a duplicated
 * `blt`.  EXACT* because the follower at 0x02026BFC has no label.
 */
int GAME_BEACON_ReceiveInfo(const GameBeaconInfo *info)
{
    GameBeaconWork *work = GAME_BEACON_Work;
    int hit = 0;
    int i;
    u16 action;
    signed char newest;
    signed char oldest;

    if ((info->versionBit & 2) == 0) {
        return hit;
    }
    action = info->action;
    if (action == 0 || action >= 0x33) {
        return 0;
    }
    if (action == 0x18) {
        if (work->own.info.trainerId != info->actionData.special.targetTrainerId) {
            return hit;
        }
    }
    newest = work->newestIndex;
    oldest = work->oldestIndex;
    if (oldest <= newest) {
        for (i = oldest; i <= newest; i++) {
            if (info->trainerId == work->log[i].info.trainerId) {
                if (action == 1 || info->serialNo == work->log[i].info.serialNo) {
                    return 0;
                }
                hit = 1;
                break;
            }
        }
    } else {
        for (i = oldest; i < 30; i++) {
            if (info->trainerId == work->log[i].info.trainerId) {
                if (action == 1 || info->serialNo == work->log[i].info.serialNo) {
                    return 0;
                }
                hit = 1;
                break;
            }
        }
        for (i = 0; i <= newest; i++) {
            if (info->trainerId == work->log[i].info.trainerId) {
                if (action == 1 || info->serialNo == work->log[i].info.serialNo) {
                    return 0;
                }
                hit = 1;
                break;
            }
        }
    }
    if (action == 0x19) {
        if (info->actionData.special.eventKey != 0x2932013A) return 0;
    } else if (action == 0x1A) {
        if (info->actionData.special.eventKey != 0x48841DC1) return 0;
    } else if (action == 0x1B) {
        if (info->actionData.special.eventKey != 0x701DDC92) return 0;
    } else if (action == 0x32) {
        if (info->actionData.special.eventKey != 0xFEE48201) return 0;
    }
    if (hit == 1) {
        work->log[i].info = *info;
        work->log[i].elapsed.receivedFrames = 0;
        work->newMask |= (u32)(1 << i);
    } else {
        GAME_BEACON_AddLog(work, info);
        work->receiveCount = work->receiveCount + 1;
    }
    return 1;
}

/*
 * Five unlabelled leaves between GAME_BEACON_ReceiveInfo and GAME_BEACON_GetNextNewLogIndex
 * (0x02026BFC..0x02026CA0), tu-verified: two ring-slot accessors, their
 * GAME_BEACON_Work tail-call wrappers, and the +0xBA8 count getter.
 *   GAME_BEACON_GetLogFromWork  slot n of the ring if n is below the s8 at +0xBAE
 *   GAME_BEACON_GetLog  GAME_BEACON_GetLogFromWork(GAME_BEACON_Work, n)
 *   GAME_BEACON_GetLogByReceiveNoFromWork  the slot n records back from the hi cursor, wrapped at 30;
 *                 the zero test on count - n is `c - n == 0` (a `subs`),
 *                 not `c == n` (a `cmp`)
 *   GAME_BEACON_GetLogByReceiveNo  GAME_BEACON_GetLogByReceiveNoFromWork(GAME_BEACON_Work, n)
 *   GAME_BEACON_GetReceiveCount  the +0xBA8 insert count
 * None has an lr save, so the integrator should seed all five starts.
 */
GameBeaconRecord *GAME_BEACON_GetLogFromWork(GameBeaconWork *work, int index)
{
    int count = work->logCount;
    if (count == 0 || count - index <= 0)
        return 0;
    return &work->log[index];
}

GameBeaconRecord *GAME_BEACON_GetLog(int index)
{
    return GAME_BEACON_GetLogFromWork(GAME_BEACON_Work, index);
}

GameBeaconRecord *GAME_BEACON_GetLogByReceiveNoFromWork(GameBeaconWork *work, int receiveNo)
{
    u32 count = work->receiveCount;
    int index;
    if (count == 0 || count - receiveNo == 0)
        return 0;
    index = work->newestIndex - (int)(count - 1 - receiveNo);
    if ((index < 0 ? -index : index) >= 30)
        return 0;
    if (index < 0)
        index += 30;
    return &work->log[index];
}

GameBeaconRecord *GAME_BEACON_GetLogByReceiveNo(int receiveNo)
{
    return GAME_BEACON_GetLogByReceiveNoFromWork(GAME_BEACON_Work, receiveNo);
}

u32 GAME_BEACON_GetReceiveCount(void)
{
    return GAME_BEACON_Work->receiveCount;
}

int GAME_BEACON_GetNextNewLogIndex(int *cursor)
{
    int index = *cursor;
    while (index < 30) {
        if (GAME_BEACON_Work->newMask & (1 << index)) {
            *cursor = *cursor + 1;
            return *cursor - 1;
        }
        index = *cursor + 1;
        *cursor = index;
    }
    return 30;
}

/*
 * Clears bit `n` of the ring live mask at +0xba4 of the game beacon block.
 * The earlier MATCH park read the pool word as 0x02021440; the word at
 * 0x02026CFC is 0x02146940, GAME_BEACON_Work, attested by 77 other pools.
 * EXACT* because the follower at 0x02026D04 is an unlabelled leaf.
 */
void GAME_BEACON_ClearNewFlag(u32 index)
{
    GAME_BEACON_Work->newMask = ((1 << index) ^ 0xffffffff) & GAME_BEACON_Work->newMask;
}

/*
 * Finds the ring slot whose +0x10 id equals the record's, sets its live-mask
 * bit and answers 1; 0 when none does.
 * Unlabelled leaf (no lr save): the integrator should seed 0x02026D04 into
 * layout/function_starts.txt.
 */
int GAME_BEACON_SetNewFlagByTrainerId(const GameBeaconInfo *info)
{
    GameBeaconWork *work = GAME_BEACON_Work;
    int i;
    for (i = 0; i < 30; i++) {
        if (info->trainerId == work->log[i].info.trainerId) {
            work->newMask |= 1 << i;
            return 1;
        }
    }
    return 0;
}

/*
 * Answers the +0x5c halfword of the first live ring slot whose +0x10 id
 * equals v, or 0xffff.
 * Unlabelled leaf (no lr save): the integrator should seed 0x02026D48 into
 * layout/function_starts.txt.
 */
u16 GAME_BEACON_GetReceivedFramesByTrainerId(u16 trainerId)
{
    GameBeaconWork *work = GAME_BEACON_Work;
    int i;
    for (i = 0; i < 30; i++) {
        if (work->log[i].info.versionBit != 0 && work->log[i].info.trainerId == trainerId)
            return work->log[i].elapsed.receivedFrames;
    }
    return 0xffff;
}

/*
 * The own-beacon builder: fills a GameBeaconInfo from the player profile, the
 * save blocks and the DS owner info.  Layout it proves beyond the family
 * header: word +0 is four BYTES (+0 = 0xff, +1/+2 from 0x0200856C and
 * 0x02008570, +3 split 7:1 as u8 bitfields -- strb/ldrb, not word RMW);
 * word +0xC is 6:3:3:4:10:6 (bits 0..5 = 0x15, 6..8 from 0x02008554,
 * 9..11 from 0x0200C224, 12..15 the owner's favoriteColor, then the
 * trainer and top fields); +0x12 is seven halfwords filled like +0x20;
 * +0x50 takes ten bytes via MI_CpuCopy8; the scratch at sp+0x14 is the
 * 0x54-byte OSOwnerInfo.  Levers that mattered: stack order (save, tbl,
 * bag declared in that order) and MYSTATUS_GetSex answering a word that is
 * narrowed with an explicit (u8) before the 1-bit store.
 */
void GAME_BEACON_BuildMyInfo(GameBeaconInfo *info, struct GameData *gameData)
{
    struct SaveControl *save;
    struct MiscSave *misc;
    struct PmsSave *pmsSave;
    struct MyStatus *myStatus;
    struct PlayTime *playTime;
    GameBeaconPms pms;
    OSOwnerInfo ownerInfo;
    u16 *codes;
    u16 eomCode;
    int i;

    myStatus = GAME_DATA_GetMyStatus(gameData);
    save = GAME_DATA_GetSaveControl(gameData);
    misc = MISC_GetBlock(save);
    pmsSave = GREETING_SAVEDATA_GetFromSaveThunk(save);
    OS_GetOwnerInfo(&ownerInfo);
    info->versionBit = 0xff;
    info->zoneId = GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(gameData));
    if (ZONEDATA_IsUnionRoom(info->zoneId) == 1 || ZONEDATA_IsZone96Pair(info->zoneId) == 1) {
        info->zoneId = GAME_DATA_GetSpecialLocation(gameData)->zoneId;
    }
    info->townmapRootZoneId = SYMBOL_MAP_ResolveZoneId(gameData, (u16)info->zoneId);
    info->infoVersion = 0x30;
    info->trainerId = MYSTATUS_GetIdLow16(myStatus);
    info->favoriteColor = ownerInfo.favoriteColor;
    info->sex = (u8)MYSTATUS_GetSex(myStatus);
    if (info->sex == 0) {
        info->trainerView = MYSTATUS_GetTrainerView(myStatus);
    } else {
        info->trainerView = MYSTATUS_GetTrainerView(myStatus) - 8;
    }
    info->pmVersion = 0x15;
    info->language = 2;
    info->nation = MYSTATUS_GetNation(myStatus);
    info->area = MYSTATUS_GetArea(myStatus);
    info->researchTeamRank = MISC_GetResearchRank(misc);
    info->passCount = MISC_GetGreetCount(misc);
    info->thanksCount = MISC_GetThanksCount(misc);
    playTime = GAME_DATA_GetPlayTime(gameData);
    info->playHours = PLAYTIME_GetHours(playTime);
    info->playMinutes = PLAYTIME_GetMinutes(playTime);
    MI_CpuCopy8(SYMBOL_SAVE_GetQuestionnaireBits(SYMBOL_SAVE_GetBitBlock(save)), info->questionnaire, sizeof(info->questionnaire));
    GREETING_SAVEDATA_GetSentence(pmsSave, 0, &pms);
    GAME_BEACON_SetMyPms(&pms);
    eomCode = STRBUF_GetEosChar();
    codes = MYSTATUS_GetName(myStatus);
    for (i = 0; i < 7; i++) {
        info->name[i] = codes[i];
        if (eomCode == codes[i])
            break;
    }
    codes = MISC_GetGreetMessage(misc);
    for (i = 0; i < 8; i++) {
        info->greeting[i] = codes[i];
        if (eomCode == codes[i])
            break;
    }
    GAME_BEACON_ResetDetails(info);
    info->action = 0;
}

void GAME_BEACON_RequestSend(GameBeaconRecord *record)
{
    struct SaveControl *save;
    struct PlayTime *playTime;
    struct MiscSave *misc;

    save = GAME_DATA_GetSaveControl(GAME_BEACON_Work->gameData);
    playTime = GAME_DATA_GetPlayTime(GAME_BEACON_Work->gameData);
    misc = MISC_GetBlock(save);
    record->info.playHours = PLAYTIME_GetHours(playTime);
    record->info.playMinutes = PLAYTIME_GetMinutes(playTime);
    record->info.passCount = MISC_GetGreetCount(misc);
    record->info.thanksCount = MISC_GetThanksCount(misc);
    record->info.serialNo = record->info.serialNo + 1;
    record->elapsed.actionFrames = 0;
    record->sendRequest = 1;
}

/*
 * The priority gate: answers 1 when id `a`'s priority is at least that of
 * the current mode at +0x34 of the block.  The table at 0x0209FC20 is a
 * word of BITFIELDS, { prio : 8; frames : 24; } -- GAME_BEACON_UpdateActionTime reads the
 * same word `>> 8`.  Spelled as `(u8)tbl[i]` on a u32 array the compiler
 * ties the lsrs order to the cmp order and stays 4 bytes out (see
 * docs/notes/pkt_02027060.GAME_BEACON_CheckActionPriority.c.txt); the bitfield read frees
 * the schedule.  Also EXACT under ../2.0/sp2.
 */
u32 GAME_BEACON_CheckActionPriority(u32 action)
{
    if (GAME_BEACON_ActionTable[action].priority >= GAME_BEACON_ActionTable[GAME_BEACON_Work->own.info.action].priority)
        return 1;
    return 0;
}

int GAME_BEACON_IsSpecialPokemon(u16 monsNo)
{
    u32 i = 0;

    while (i < 14) {
        if (monsNo == GAME_BEACON_SpecialPokemonTable[i]) {
            return 1;
        }
        i++;
    }
    return 0;
}

void GAME_BEACON_CopyStrbufCodes(const struct Strbuf *str, u16 *dest)
{
    u16 codes[12];
    u16 eomCode;
    int i;

    eomCode = STRBUF_GetEosChar();
    STRBUF_ToChars(str, codes, 12);
    for (i = 0; i < 10; i++) {
        dest[i] = codes[i];
        if (eomCode == codes[i]) {
            break;
        }
    }
}

u8 GAME_BEACON_PopQuestionnaireUpdated(void)
{
    GameBeaconWork *work = GAME_BEACON_Work;
    u8 updated;

    if (work == 0) {
        return 0;
    }
    updated = work->questionnaireUpdated;
    work->questionnaireUpdated = 0;
    return updated;
}

void GAME_BEACON_SetQuestionnaire(const u8 *answers)
{
    GameBeaconRecord *own = &GAME_BEACON_Work->own;

    MI_CpuCopy8(answers, own->info.questionnaire, sizeof(own->info.questionnaire));
    own->sendRequest = 1;
}

/*
 * 20 bytes. Stores two bytes at +5 and +6 of the block that GAME_BEACON_Work points
 * to and sets the flag byte at +0x62 (reached as +4 then +0x5E: a nested
 * record at +4, written through a pointer local `q = &s->sub`; direct
 * `s->sub.flag` folds to +0x62). Filed in wave D6 as the unlabelled leaf that ov219
 * BEACON_DETAIL_Update calls.
 */
void GAME_BEACON_SetNationArea(u8 nation, u8 area)
{
    GameBeaconRecord *own = &GAME_BEACON_Work->own;

    own->info.nation = nation;
    own->info.area = area;
    own->sendRequest = 1;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module: inserts three bits (9..11) into
 * the word at +0x10 of the nested object at +4, then sets the byte at +0x62.
 * The inner-object pointer is what pins the two-step `adds r0, r1, #4` /
 * `adds r0, #0x5e` address form (see GAME_BEACON_SetPms).
 *
 * Addresses are Black-image addresses.
 */
void GAME_BEACON_SetResearchTeamRank(u32 rank)
{
    GameBeaconRecord *own = &GAME_BEACON_Work->own;

    own->info.researchTeamRank = rank;
    own->sendRequest = 1;
}

/*
 * EXACT*: the listing extent runs 60 bytes to the next label; only the
 * first 24 bytes belong to this function (the follower at 0x02027174 is
 * an unlabelled leaf).
 *
 * The original splits the address arithmetic into `adds r0, r4, #4` then
 * `adds r0, #0x5e`, which a flat `*(u8 *)(p + 0x62)` folds into one
 * `adds r4, #0x62`.  Taking a pointer to a NESTED struct member (the
 * inner object starts at +4) before the call is what pins the two-step
 * form: `&g->own` is its own value, materialised at +0x0A, and the field
 * offset is added separately at +0x0E.
 */
void GAME_BEACON_SetPms(const GameBeaconPms *pms)
{
    GameBeaconRecord *own = &GAME_BEACON_Work->own;

    GAME_BEACON_SetMyPms(pms);
    own->sendRequest = 1;
}

/*
 * Unlabelled Thumb leaf in the ARM9 module: inserts three bits (6..8) into the
 * word at +0x10 of the nested object at +4, then sets the byte at +0x62.
 * Pairs with GAME_BEACON_SetResearchTeamRank; the inner-object pointer pins the two-step
 * address form (see GAME_BEACON_SetPms).
 *
 * Addresses are Black-image addresses.
 */
void GAME_BEACON_SetTrainerView(u32 trainerView)
{
    GameBeaconRecord *own = &GAME_BEACON_Work->own;

    own->info.trainerView = trainerView;
    own->sendRequest = 1;
}

void GAME_BEACON_UpdateGreeting(void)
{
    GameBeaconWork *work = GAME_BEACON_Work;
    GameBeaconRecord *own;
    u16 *codes;
    u32 eomCode;
    struct MiscSave *misc;
    int i;

    own = &work->own;
    misc = MISC_GetBlock(GAME_DATA_GetSaveControl(work->gameData));
    eomCode = STRBUF_GetEosChar();
    codes = MISC_GetGreetMessage(misc);
    for (i = 0; i < 8; i++) {
        own->info.greeting[i] = codes[i];
        if (codes[i] == eomCode) {
            break;
        }
    }
    own->sendRequest = 1;
}

void GAME_BEACON_SetPokeCapture(u16 monsNo)
{
    if (GAME_BEACON_IsSpecialPokemon(monsNo)) {
        GAME_BEACON_SetSpecialPokeGet(monsNo);
    } else {
        GAME_BEACON_SetPokeGet(monsNo);
    }
}

static void GAME_BEACON_WritePokeGet(GameBeaconRecord *own, u16 monsNo);

/*
 * A whole translation unit, matched as one byte range.
 *
 *           GAME_BEACON_SetPokeLevelUp, GAME_BEACON_WritePokeLevelUp, GAME_BEACON_SetPokeEvolution, GAME_BEACON_WritePokeEvolution,
 *           GAME_BEACON_SetPlayTime, GAME_BEACON_WritePlayTime, GAME_BEACON_SetItemUse, GAME_BEACON_WriteItemUse
 *
 * Six checker/writer pairs, one per beacon action (0xe pokemon caught,
 * 0xf special pokemon caught, 0x10 level up, 0x11 evolution, 0x14 play
 * time, 0x23 item used), all writing the console's own beacon record.
 * Every checker asks GAME_BEACON_CheckActionPriority(action) (the priority gate against the
 * action now shown) whether the action may replace it, and if so writes
 * the action through the matching static writer and hands the record to
 * GAME_BEACON_RequestSend, which refreshes the counters and requests a send.
 *
 * The record address is written out twice, `&GAME_BEACON_Work->own`, once for
 * the writer and once for the send: the global is re-read across the
 * writer call.  (An earlier version reached this only with a second,
 * volatile name for the global; the plain repeated expression gives the
 * same bytes.)
 *
 * The writers store the action number at +0x30 and, for 0xe, 0xf, 0x14
 * and 0x23, one 16-bit argument at +0x32 or +0x34, then tail-call
 * GAME_BEACON_ResetDetails (details type back to 5).  The 0x10 writer instead
 * tail-calls GAME_BEACON_CopyStrbufCodes(nickname, +0x34) and skips GAME_BEACON_ResetDetails; the
 * 0x11 writer does both.  The nickname argument is declared u16 although
 * it is a string pointer; the caller's narrowing is in the bytes, so the
 * cast stays.  The play time setter takes a u32: GAME_BEACON_Update passes its
 * s32 without narrowing.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020271F8.c \
 *       --addr 0x020271F8 --thumb
 */
void GAME_BEACON_SetPokeGet(u16 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0xe)) {
        GAME_BEACON_WritePokeGet(&GAME_BEACON_Work->own, monsNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

static void GAME_BEACON_WritePokeGet(GameBeaconRecord *own, u16 monsNo)
{
    own->info.action = 0xe;
    own->info.actionArg = monsNo;
    GAME_BEACON_ResetDetails(&own->info);
}

static void GAME_BEACON_WriteSpecialPokeGet(GameBeaconRecord *own, u16 monsNo);

void GAME_BEACON_SetSpecialPokeGet(u16 monsNo)
{
    if (GAME_BEACON_CheckActionPriority(0xf)) {
        GAME_BEACON_WriteSpecialPokeGet(&GAME_BEACON_Work->own, monsNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

static void GAME_BEACON_WriteSpecialPokeGet(GameBeaconRecord *own, u16 monsNo)
{
    own->info.action = 0xf;
    own->info.actionArg = monsNo;
    GAME_BEACON_ResetDetails(&own->info);
}

static void GAME_BEACON_WritePokeLevelUp(GameBeaconRecord *own, u16 nickname);

void GAME_BEACON_SetPokeLevelUp(u16 nickname)
{
    if (GAME_BEACON_CheckActionPriority(0x10)) {
        GAME_BEACON_WritePokeLevelUp(&GAME_BEACON_Work->own, nickname);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

static void GAME_BEACON_WritePokeLevelUp(GameBeaconRecord *own, u16 nickname)
{
    own->info.action = 0x10;
    GAME_BEACON_CopyStrbufCodes((const struct Strbuf *)nickname, own->info.actionData.nickname);
}

static void GAME_BEACON_WritePokeEvolution(GameBeaconRecord *own, u16 monsNo, u16 nickname);

void GAME_BEACON_SetPokeEvolution(u16 monsNo, u16 nickname)
{
    if (GAME_BEACON_CheckActionPriority(0x11)) {
        GAME_BEACON_WritePokeEvolution(&GAME_BEACON_Work->own, monsNo, nickname);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

static void GAME_BEACON_WritePokeEvolution(GameBeaconRecord *own, u16 monsNo, u16 nickname)
{
    own->info.action = 0x11;
    own->info.actionArg = monsNo;
    GAME_BEACON_CopyStrbufCodes((const struct Strbuf *)nickname, own->info.actionData.nickname);
    GAME_BEACON_ResetDetails(&own->info);
}

static void GAME_BEACON_WritePlayTime(GameBeaconRecord *own, u32 playHours);

void GAME_BEACON_SetPlayTime(u32 playHours)
{
    if (GAME_BEACON_CheckActionPriority(0x14)) {
        GAME_BEACON_WritePlayTime(&GAME_BEACON_Work->own, playHours);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

static void GAME_BEACON_WritePlayTime(GameBeaconRecord *own, u32 playHours)
{
    own->info.action = 0x14;
    own->info.actionData.value = playHours;
    GAME_BEACON_ResetDetails(&own->info);
}

static void GAME_BEACON_WriteItemUse(GameBeaconRecord *own, u16 itemNo);

void GAME_BEACON_SetItemUse(u16 itemNo)
{
    if (GAME_BEACON_CheckActionPriority(0x23)) {
        GAME_BEACON_WriteItemUse(&GAME_BEACON_Work->own, itemNo);
        GAME_BEACON_RequestSend(&GAME_BEACON_Work->own);
    }
}

static void GAME_BEACON_WriteItemUse(GameBeaconRecord *own, u16 itemNo)
{
    own->info.action = 0x23;
    own->info.actionData.value = itemNo;
    GAME_BEACON_ResetDetails(&own->info);
}

void GAME_BEACON_SetZone(u32 zoneId, u32 zoneSource)
{
    GAME_BEACON_SetInfoZone(&GAME_BEACON_Work->own.info, zoneId, zoneSource);
    GAME_BEACON_Work->own.sendRequest = 1;
}

void GAME_BEACON_SetInfoZone(GameBeaconInfo *info, u32 zoneId, u32 zoneSource)
{
    info->zoneId = zoneId;
    info->townmapRootZoneId = SYMBOL_MAP_ResolveZoneId(zoneSource);
    info->detailsPms.word = (info->detailsPms.word & ~0xff) | 5;
    GAME_BEACON_ResetDetails(info);
}

/*
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 */
void GAME_BEACON_SetDetailsBattleWildPoke(GameBeaconInfo *info, u16 monsNo)
{
    info->detailsPms.bits.detailsType = 0;
    info->detailsValue = monsNo;
}

void GAME_BEACON_SetDetailsBattleSpecialPoke(GameBeaconInfo *info, u16 monsNo)
{
    info->detailsPms.word = (info->detailsPms.word & ~0xff) | 1;
    info->detailsValue = monsNo;
}

void GAME_BEACON_SetDetailsBattleTrainer(GameBeaconInfo *info, u16 trainerId)
{
    info->detailsPms.word = (info->detailsPms.word & ~0xff) | 2;
    info->detailsValue = trainerId;
}

void GAME_BEACON_SetDetailsBattleLeader(GameBeaconInfo *info, u16 trainerId)
{
    info->detailsPms.word = (info->detailsPms.word & ~0xff) | 3;
    info->detailsValue = trainerId;
}

void GAME_BEACON_SetDetailsBattleBigFour(GameBeaconInfo *info, u16 trainerId)
{
    info->detailsPms.word = (info->detailsPms.word & ~0xff) | 4;
    info->detailsValue = trainerId;
}

/*
 * Sets the low byte of the halfword at +0x48 of its argument to the
 * constant 5, leaving the high byte untouched. Called from every
 * trampoline of src/matched/unit_020271F8.c as a shared "mark this event
 * object pending" step, independent of which event id was just written.
 *
 * `disasm.py` measures this function's extent to the next label at
 * 0x020274B4, 104 bytes away, but only the first 20 bytes belong to it;
 * what follows is a second, unlabelled function (the same
 * "half the accessors are printed as .word data" gap
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md describes)
 * that packs several bitfields of the same object from a small argument
 * struct. It is out of scope for this file and still open. The mismatched
 * extent is why this entry is EXACT* rather than EXACT.
 *
 * Writing the mask as `~0xffu` rather than building 0xff00 directly is
 * what keeps the mask in the `movs r1, #0xff` / `bics r2, r1` shape the
 * original uses; the equivalent `& 0xff00` immediate has no Thumb
 * encoding and this compiler rematerialises it as `lsls`/`ands` instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_BEACON_ResetDetails.c \
 *       --func GAME_BEACON_ResetDetails --addr 0x0202744C --cc 1.1p1 --thumb
 */
void GAME_BEACON_ResetDetails(GameBeaconInfo *info)
{
    u16 word = info->detailsPms.word;
    word = (word & ~0xffu) | 5;
    info->detailsPms.word = word;
}

/*
 * Copies four halfwords into the console's own beacon record (+4 of the
 * block): two BITFIELDS of the u16 at rec+0x48 (bits 8..10 and 11..15,
 * masks 0xF8FF / 0x07FF, the low byte being the one GAME_BEACON_ResetDetails sets),
 * then rec+0x4a and rec+0x4c.  The caller GAME_BEACON_SetMyPms passes &own in r0
 * but this body ignores it and recomputes; the two-step `adds r,r0,#4;
 * adds r,#0x48` at every access is a pointer local `o = &g->own`, not a
 * held `g` (which folds to one `adds #0x4c`).
 * Unlabelled leaf (no lr save): the integrator should seed 0x02027460.
 */
void GAME_BEACON_WritePms(GameBeaconInfo *info, const GameBeaconPms *pms)
{
    GameBeaconInfo *own = &GAME_BEACON_Work->own.info;

    own->detailsPms.bits.pmsSentenceType = pms->sentenceType;
    own->detailsPms.bits.pmsSentenceId = pms->sentenceId;
    own->pmsWord[0] = pms->word[0];
    own->pmsWord[1] = pms->word[1];
}

void GAME_BEACON_SetMyPms(const GameBeaconPms *pms)
{
    GAME_BEACON_WritePms(&GAME_BEACON_Work->own.info, pms);
}

/*
 * note:     wave 17 (overlay_id class): EXACT*. The pooled overlay-id site
 *           ov231_id (231) resolves as `overlay_id` (a layout overlay index,
 *           loaded by a pc-relative load of this function, reaching the id
 *           register of a known overlay loader), which was the last blocker.
 *
 * The ABS32 pool word 0x000000E7 is an absolute overlay-id symbol (ov231,
 * matching the bl into CARD_SPI_CheckCardId in asm/overlays/ov231.s), per
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 * EXACT* because the listing extent (84 bytes) runs over the follower
 * GAME_BEACON_ClearFlags.
 */
void GAME_BEACON_RegisterClearCallback(void)
{
    int result;

    GF_OVERLAY_Load((int)ov231_id);
    result = CARD_SPI_CheckCardId();
    GF_OVERLAY_Unload((int)ov231_id);
    if (result == 0) {
        GFL_USE_AddHBlankTask(GAME_BEACON_ClearFlags, 0, 3);
    }
}

void GAME_BEACON_ClearFlags(void)
{
    if (GAME_BEACON_Work != 0) {
        GAME_BEACON_Work->newMask = 0;
        GAME_BEACON_Work->own.sendRequest = 0;
        GAME_BEACON_Work->newMask = 0;
    }
}
