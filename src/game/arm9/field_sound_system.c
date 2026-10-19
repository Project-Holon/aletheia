/*
 * file:     field_sound_system.c
 * unit:     yes
 * function: FIELD_SOUND_SYSTEM_Create, FIELD_SOUND_SYSTEM_Delete, FIELD_SOUND_SYSTEM_GetPendingBgmStackDepth, FIELD_SOUND_SYSTEM_GetFinalValue, FIELD_SOUND_SYSTEM_IsStateActive, FIELD_SOUND_SYSTEM_IsBusy, FIELD_SOUND_SYSTEM_CanAcceptRequest, FIELD_SOUND_SYSTEM_PostRequest, FIELD_SOUND_SYSTEM_Update, FIELD_SOUND_SYSTEM_Reset, FIELD_SOUND_SYSTEM_FadeVolume, FIELD_SOUND_SYSTEM_StartRingtone, FIELD_SOUND_SYSTEM_StopRingtone, FIELD_SOUND_SYSTEM_ClaimSlot, FIELD_SOUND_SYSTEM_ClaimSlotWithOwner, FIELD_SOUND_SYSTEM_TransferSlot, FIELD_SOUND_SYSTEM_ReleaseSlot, FIELD_SOUND_SYSTEM_PauseSlots, FIELD_SOUND_SYSTEM_ResumeSlots, FIELD_SOUND_SYSTEM_IsKnownSoundId, FIELD_SOUND_SYSTEM_IsSoundRecordChainValid, FIELD_SOUND_SYSTEM_IsSoundIdPlayable, FIELD_SOUND_SYSTEM_Init, FIELD_SOUND_SYSTEM_DrainAndInit, FIELD_SOUND_SYSTEM_ProcessNextRequest, FIELD_SOUND_SYSTEM_GetReadSlot, FIELD_SOUND_SYSTEM_GetNewestRequest, FIELD_SOUND_SYSTEM_HasPendingRequest, FIELD_SOUND_SYSTEM_CountRequestsOfKind, FIELD_SOUND_SYSTEM_EnqueueRequest, FIELD_SOUND_SYSTEM_IsRequestKindAccepted, FIELD_SOUND_SYSTEM_DequeueRequest, FIELD_SOUND_SYSTEM_ExecuteRequest, FIELD_SOUND_SYSTEM_SetMode1, FIELD_SOUND_SYSTEM_SetMode2, FIELD_SOUND_SYSTEM_SetMode3, FIELD_SOUND_SYSTEM_SetMode4, FIELD_SOUND_SYSTEM_SetMode5, FIELD_SOUND_SYSTEM_SetMode6, FIELD_SOUND_SYSTEM_SetMode7, FIELD_SOUND_SYSTEM_IsKindAllowedInState, FIELD_SOUND_SYSTEM_HandleModeState0, FIELD_SOUND_SYSTEM_HandleModeState1, FIELD_SOUND_SYSTEM_HandleModeState2, FIELD_SOUND_SYSTEM_HandleModeState3, FIELD_SOUND_SYSTEM_HandleModeState4, FIELD_SOUND_SYSTEM_HandleModeState5, FIELD_SOUND_SYSTEM_HandleModeState6, FIELD_SOUND_SYSTEM_HandleModeState7, FIELD_SOUND_SYSTEM_HandleModeState8, FIELD_SOUND_SYSTEM_HandleModeState9, FIELD_SOUND_SYSTEM_HandleModeState10, FIELD_SOUND_SYSTEM_HandleModeState11, FIELD_SOUND_SYSTEM_HandleModeState12, FIELD_SOUND_SYSTEM_HandleModeState13, FIELD_SOUND_SYSTEM_HandleModeState14, FIELD_SOUND_SYSTEM_HandleModeState15, FIELD_SOUND_SYSTEM_HandleModeState16, FIELD_SOUND_SYSTEM_HandleModeState17, FIELD_SOUND_SYSTEM_UpdateFadingOutToMute, FIELD_SOUND_SYSTEM_UpdateFadingIn, FIELD_SOUND_SYSTEM_UpdateFadingOutToPush, FIELD_SOUND_SYSTEM_UpdateFadingOutToPop, FIELD_SOUND_SYSTEM_UpdateFadingInAfterPop, FIELD_SOUND_SYSTEM_UpdateFadingOutToLoad, FIELD_SOUND_SYSTEM_UpdateLoading, FIELD_SOUND_SYSTEM_UpdateFadingInLoaded, FIELD_SOUND_SYSTEM_UpdateFadingOutToLoadAndPush, FIELD_SOUND_SYSTEM_UpdateLoadingAndPush, FIELD_SOUND_SYSTEM_UpdateFadingOutToReplace, FIELD_SOUND_SYSTEM_UpdateReplacing, FIELD_SOUND_SYSTEM_SetState, FIELD_SOUND_SYSTEM_ClearRequest, FIELD_SOUND_SYSTEM_DiscardRequest, FIELD_SOUND_SYSTEM_FinishRequest, FIELD_SOUND_SYSTEM_FadeInCurrentBgm, FIELD_SOUND_SYSTEM_FadeOutCurrentBgm, FIELD_SOUND_SYSTEM_PushCurrentBgm, FIELD_SOUND_SYSTEM_PopBgm, FIELD_SOUND_SYSTEM_StartLoadingRequestedBgm, FIELD_SOUND_SYSTEM_StepBgmLoading, FIELD_SOUND_SYSTEM_PlayRequestedBgmNow, FIELD_SOUND_SYSTEM_IsSaving, FIELD_SOUND_SYSTEM_FadeInTask, FIELD_SOUND_SYSTEM_StartFadeInTask, FIELD_SOUND_SYSTEM_FadeOutTask, FIELD_SOUND_SYSTEM_StartFadeOutTask, FIELD_SOUND_SYSTEM_PushTask, FIELD_SOUND_SYSTEM_StartPushTask, FIELD_SOUND_SYSTEM_PopAndWaitTask, FIELD_SOUND_SYSTEM_StartPopAndWaitTask, FIELD_SOUND_SYSTEM_PopTask, FIELD_SOUND_SYSTEM_StartPopTask, FIELD_SOUND_SYSTEM_PopAllTask, FIELD_SOUND_SYSTEM_StartPopAllTask, FIELD_SOUND_SYSTEM_PushAndChangeTask, FIELD_SOUND_SYSTEM_StartPushAndChangeTask, FIELD_SOUND_SYSTEM_PushAndPlayTask, FIELD_SOUND_SYSTEM_StartPushAndPlayTask, FIELD_SOUND_SYSTEM_ChangeTask, FIELD_SOUND_SYSTEM_StartChangeTask, FIELD_SOUND_SYSTEM_FadeOutAndResetTask, FIELD_SOUND_SYSTEM_FadeOutAndPlayTask, FIELD_SOUND_SYSTEM_StartFadeOutAndPlayTask, FIELD_SOUND_SYSTEM_FadeOutAndPlayWithFadeTask, FIELD_SOUND_SYSTEM_StartFadeOutAndPlayWithFadeTask, FIELD_SOUND_SYSTEM_FadeOutAndPlayFixedBgmTask, FIELD_SOUND_SYSTEM_StartFadeOutAndPlayFixedBgmTask, FIELD_SOUND_SYSTEM_PushAndPlayWaitTask, FIELD_SOUND_SYSTEM_StartPushAndPlayWaitTask, FIELD_SOUND_SYSTEM_StartFadeOutAndResetTask, FIELD_SOUND_SYSTEM_PushOrFadeOutAndPlayTask, FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask, FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask, FIELD_SOUND_SYSTEM_WaitSettledTask, FIELD_SOUND_SYSTEM_StartWaitSettledTask, FIELD_SOUND_SYSTEM_WaitAcceptRequestTask, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask, FIELD_SOUND_SYSTEM_PostZoneBgmChange, FIELD_SOUND_SYSTEM_PostZoneBgmReplace, FIELD_SOUND_SYSTEM_PostFadeIn, FIELD_SOUND_SYSTEM_PostZoneBgmChangeShortFade, FIELD_SOUND_SYSTEM_LowerVolume, FIELD_SOUND_SYSTEM_RestoreVolume, FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx, FIELD_SOUND_SYSTEM_GetFinalBgm, FIELD_SOUND_SYSTEM_HasZoneBgmOverride, FIELD_SOUND_SYSTEM_GetTrainerClassBgm, FIELD_SOUND_SYSTEM_GetPlayerObjectCode, FIELD_SOUND_SYSTEM_GetZoneBgm, FIELD_SOUND_SYSTEM_FindZoneBgmOverride, FIELD_SOUND_SYSTEM_GetFieldBgmForZone
 * address:  0x02028844
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from field_sound_system.c, field_sound_system_cont.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   PLAYER_VOLUME_FADER_Create  0x02028760  thumb
 *   RINGTONE_SYS_Create  0x02029F14  thumb
 *   GFL_USE_SetSeqStartFilter  0x02005D08  thumb
 *   g_020A7590     0x020A7590  data
 *   PLAYER_VOLUME_FADER_Delete  0x02028784  thumb
 *   RINGTONE_SYS_Delete  0x02029F44  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   g_020A7518  0x020A7518  data
 *   g_020A7554  0x020A7554  data
 *   PLAYER_VOLUME_FADER_SetTarget  0x02028794  thumb
 *   RINGTONE_SYS_Start  0x02029F54  thumb
 *   RINGTONE_SYS_Stop  0x02029F60  thumb
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELD_SOUND_SYSTEM_FindSlotSound  0x021D21C0  thumb ov021
 *   FIELD_SOUND_SYSTEM_IsSlotSoundTracked  0x021D21E0  thumb ov021
 *   GFL_USE_PlaySeWithVolume  0x020061F0  thumb
 *   GFL_USE_SetSeSlotVolume  0x020062BC  thumb
 *   GFL_USE_StopSeSlot  0x020061F8  thumb
 *   sTable_0209FDD0  0x0209FDD0  data
 *   NNS_SndArcGetSeqInfo  0x02074324  arm
 *   NNS_SndArcGetFileAddress  0x0207466C  arm
 *   NNS_SndArcGetBankInfo  0x020743EC  arm
 *   NNS_SndArcGetWaveArcInfo  0x02074450  arm
 *   FIELD_SOUND_SYSTEM_PopBgm  0x020293D8  thumb
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb
 *   g_0209FD90     0x0209FD90  data
 *   g_flagTable_0209FE1C  0x0209FE1C  data
 *   PLAYER_VOLUME_FADER_Update  0x0202878C  thumb
 *   FIELD_SOUND_SYSTEM_SetState  0x02029344  thumb
 *   FIELD_SOUND_SYSTEM_DiscardRequest  0x02029354  thumb
 *   FIELD_SOUND_SYSTEM_FinishRequest  0x02029364  thumb
 *   FIELD_SOUND_SYSTEM_FadeInCurrentBgm  0x02029374  thumb
 *   FIELD_SOUND_SYSTEM_FadeOutCurrentBgm  0x0202938C  thumb
 *   FIELD_SOUND_SYSTEM_PlayRequestedBgmNow  0x0202945C  thumb
 *   RINGTONE_SYS_Update  0x02029F4C  thumb
 *   GAME_DATA_IsSaving  0x02012E40  thumb
 *   FIELD_SOUND_SYSTEM_PostRequest  0x020289F8  thumb
 *   FIELD_SOUND_SYSTEM_IsBusy  0x020289B8  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   sTrainerClassBgmTable  0x020A75A8  data
 *   ZONEDATA_GetBgmId  0x02013BDC  thumb
 *   sZoneBgmOverrides  0x0209FE94  data
 *   ZONEDATA_IsRideBgmEnabled  0x02013C30  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_SetBgmPaused  0x02005DE4  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   GFL_USE_IsBgmFading  0x02005E50  thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   GFL_USE_StepBgmLoad  0x020063B4  thumb
 *   FIELD_SOUND_SYSTEM_GetPendingBgmStackDepth  0x020288C4  thumb
 *   FIELD_SOUND_SYSTEM_GetFinalValue  0x02028900  thumb
 *   FIELD_SOUND_SYSTEM_IsStateActive  0x02028988  thumb
 *   FIELD_SOUND_SYSTEM_CanAcceptRequest  0x020289D4  thumb
 *   FIELD_SOUND_SYSTEM_Reset  0x02028A50  thumb
 *   ISS_3DS_SYS_SetVolume  0x0202B914  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   GAME_DATA_GetPlayerObjectCode  0x02012B28  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   FIELD_SOUND_SYSTEM_FadeVolume  0x02028A58  thumb
 *   FIELD_SOUND_SYSTEM_PauseSlots  0x02028BA0  thumb
 *   FIELD_SOUND_SYSTEM_ResumeSlots  0x02028BDC  thumb
 *   GFL_NET_SetDeviceModeIfRunning  0x0203D12C  arm
 *   ISS_SYS_Get3dsSys  0x0202B57C  thumb
 */
#include "field_sound_system_shared_types.h"

typedef signed int     s32;

struct GameData;

/* One queued request: a ring slot of 12 bytes. */
typedef struct FieldSoundRequest {
    u32 kind;
    u32 value;
    u16 lowParam;
    u16 highParam;
} FieldSoundRequest;

/*
 * The field sound system object (0xB8 bytes, allocated by the constructor).
 */
typedef struct FieldSoundSystem {
    struct GameData *gameData;      /* 0x00 */
    u32 state;                      /* 0x04 FieldSoundState, index into the two per-state handler tables */
    u32 currentValue;               /* 0x08 BGM number that is playing, 0 = none */
    u32 requestedValue;             /* 0x0C BGM number of the pending request */
    u32 loadingValue;               /* 0x10 BGM number that is being loaded */
    u32 loadStep;                   /* 0x14 step counter of the BGM loader */
    u16 highParam;                  /* 0x18 fade in frames of the pending request */
    u16 lowParam;                   /* 0x1A fade out frames of the pending request */
    u32 mode;                       /* 0x1C latched request kind, 0 = none */
    int stackDepth;                 /* 0x20 */
    u32 valueStack[1];              /* 0x24 suspended BGM numbers */
    FieldSoundRequest queue[10];    /* 0x28 ring of requests */
    u8 readIndex;                   /* 0xA0 */
    u8 writeIndex;                  /* 0xA1 */
    struct Fader *volumeFader;      /* 0xA4 */
    Ringtone *ringtone;             /* 0xA8 */
    u16 slotSoundId[2];             /* 0xAC claimed sound ids, 0xFFFF = free */
    u16 slotOwner[2];               /* 0xB0 */
    u32 pauseMask;                  /* 0xB4 */
} FieldSoundSystem;

/* Records read through the lookup chain of the validity check. */
typedef struct SoundEventRecord {
    u32 checkId;
    u16 groupIndex;
} SoundEventRecord;

typedef struct SoundGroupRecord {
    u32 checkId;
    u16 entryId[4];
} SoundGroupRecord;

typedef struct SoundEntryRecord {
    u32 checkId : 24;
} SoundEntryRecord;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void *PLAYER_VOLUME_FADER_Create(void *a, int v);

extern Ringtone *RINGTONE_SYS_Create(u32 heapId, struct Fader *volumeFader);

extern void GFL_USE_SetSeqStartFilter(int (*hook)(u32 id));

extern void GFL_USE_CancelChangeAndStopBgm(void);

extern void RINGTONE_SYS_Delete(Ringtone *p);

extern void PLAYER_VOLUME_FADER_Delete(struct Fader *p);

extern u32 GFL_HEAP_Free(void *p);

extern void RINGTONE_SYS_Update(Ringtone *p);

extern void PLAYER_VOLUME_FADER_Update(struct Fader *s);

extern void PLAYER_VOLUME_FADER_SetTarget(struct Fader *s, u8 level, u16 frames);

extern void RINGTONE_SYS_Start(Ringtone *p);

extern void RINGTONE_SYS_Stop(Ringtone *p);

extern int FIELD_SOUND_SYSTEM_FindSlotSound(u32 id);

extern int FIELD_SOUND_SYSTEM_IsSlotSoundTracked(u32 id);

extern int GFL_USE_GetSeSlot(u32 seqNo);

extern void GFL_USE_PlaySeDefaultVolume(u32 id);

extern void GFL_USE_PlaySeWithVolume(u32 id, u32 who);

extern void GFL_USE_SetSeSlotVolume(int i, u32 level);

extern void GFL_USE_StopSeSlot(int i);

extern SoundEventRecord *NNS_SndArcGetSeqInfo(int index);

extern u32 NNS_SndArcGetFileAddress(u32 idx);

extern SoundGroupRecord *NNS_SndArcGetBankInfo(int index);

extern SoundEntryRecord *NNS_SndArcGetWaveArcInfo(u32 id);

void FIELD_SOUND_SYSTEM_PopBgm(FieldSoundSystem *fieldSound);

void FIELD_SOUND_SYSTEM_SetState(FieldSoundSystem *fieldSound, u32 state);

void FIELD_SOUND_SYSTEM_FinishRequest(FieldSoundSystem *fieldSound);

void FIELD_SOUND_SYSTEM_FadeInCurrentBgm(FieldSoundSystem *fieldSound);

void FIELD_SOUND_SYSTEM_PlayRequestedBgmNow(FieldSoundSystem *fieldSound);

void FIELD_SOUND_SYSTEM_DiscardRequest(FieldSoundSystem *fieldSound);

void FIELD_SOUND_SYSTEM_FadeOutCurrentBgm(FieldSoundSystem *fieldSound);

FieldSoundSystem *FIELD_SOUND_SYSTEM_Create(struct GameData *gameData, u32 heap);

void FIELD_SOUND_SYSTEM_Delete(FieldSoundSystem *s);

extern s32 FIELD_SOUND_SYSTEM_GetPendingBgmStackDepth(FieldSoundSystem *fieldSound);

extern void *FIELD_SOUND_SYSTEM_GetFinalValue(FieldSoundSystem *fieldSound);

extern u32 FIELD_SOUND_SYSTEM_IsStateActive(FieldSoundSystem *fieldSound);

extern u32 FIELD_SOUND_SYSTEM_IsBusy(FieldSoundSystem *fieldSound);

extern u32 FIELD_SOUND_SYSTEM_CanAcceptRequest(FieldSoundSystem *fieldSound);

extern void FIELD_SOUND_SYSTEM_PostRequest(FieldSoundSystem *fieldSound, u32 kind, u32 value, u16 lowParam, u16 highParam);

void FIELD_SOUND_SYSTEM_Update(FieldSoundSystem *s);

extern void FIELD_SOUND_SYSTEM_Reset(FieldSoundSystem *fieldSound, struct GameData *gameData);

extern void FIELD_SOUND_SYSTEM_FadeVolume(FieldSoundSystem *fieldSound, u8 level, u16 frames);

void FIELD_SOUND_SYSTEM_StartRingtone(FieldSoundSystem *s);

void FIELD_SOUND_SYSTEM_StopRingtone(FieldSoundSystem *s);

void FIELD_SOUND_SYSTEM_ClaimSlot(FieldSoundSystem *s, u32 soundId);

void FIELD_SOUND_SYSTEM_ClaimSlotWithOwner(FieldSoundSystem *s, u32 soundId, u32 owner);

void FIELD_SOUND_SYSTEM_TransferSlot(FieldSoundSystem *s, u32 soundId, u32 owner);

void FIELD_SOUND_SYSTEM_ReleaseSlot(FieldSoundSystem *s, int soundId);

extern void FIELD_SOUND_SYSTEM_PauseSlots(FieldSoundSystem *fieldSound, u32 bits);

extern void FIELD_SOUND_SYSTEM_ResumeSlots(FieldSoundSystem *fieldSound, u32 bits);

int FIELD_SOUND_SYSTEM_IsKnownSoundId(u32 soundId);

u32 FIELD_SOUND_SYSTEM_IsSoundRecordChainValid(int soundIndex);

int FIELD_SOUND_SYSTEM_IsSoundIdPlayable(u32 soundId);

void FIELD_SOUND_SYSTEM_Init(FieldSoundSystem *s, struct GameData *gameData);

void FIELD_SOUND_SYSTEM_DrainAndInit(FieldSoundSystem *s, struct GameData *gameData);

void FIELD_SOUND_SYSTEM_ProcessNextRequest(FieldSoundSystem *s);

FieldSoundRequest *FIELD_SOUND_SYSTEM_GetReadSlot(FieldSoundSystem *s);

FieldSoundRequest *FIELD_SOUND_SYSTEM_GetNewestRequest(FieldSoundSystem *s);

int FIELD_SOUND_SYSTEM_HasPendingRequest(FieldSoundSystem *s);

u8 FIELD_SOUND_SYSTEM_CountRequestsOfKind(FieldSoundSystem *s, u32 kind);

void FIELD_SOUND_SYSTEM_EnqueueRequest(FieldSoundSystem *s, FieldSoundRequest *req);

u32 FIELD_SOUND_SYSTEM_IsRequestKindAccepted(FieldSoundSystem *s, u32 kind);

void FIELD_SOUND_SYSTEM_DequeueRequest(FieldSoundSystem *s);

void FIELD_SOUND_SYSTEM_ExecuteRequest(FieldSoundSystem *s, FieldSoundRequest *req);

void FIELD_SOUND_SYSTEM_SetMode1(FieldSoundSystem *s, u16 highParam);

void FIELD_SOUND_SYSTEM_SetMode2(FieldSoundSystem *s, u16 lowParam);

void FIELD_SOUND_SYSTEM_SetMode3(FieldSoundSystem *s, u16 lowParam);

void FIELD_SOUND_SYSTEM_SetMode4(FieldSoundSystem *s, u16 lowParam, u16 highParam);

void FIELD_SOUND_SYSTEM_SetMode5(FieldSoundSystem *s, u32 value, u16 lowParam, u16 highParam);

void FIELD_SOUND_SYSTEM_SetMode6(FieldSoundSystem *s, u32 value, u16 lowParam);

void FIELD_SOUND_SYSTEM_SetMode7(FieldSoundSystem *s, u32 value);

u32 FIELD_SOUND_SYSTEM_IsKindAllowedInState(FieldSoundSystem *s, u32 kind);

void FIELD_SOUND_SYSTEM_HandleModeState0(FieldSoundSystem *s);

void FIELD_SOUND_SYSTEM_HandleModeState1(FieldSoundSystem *s);

void FIELD_SOUND_SYSTEM_HandleModeState2(FieldSoundSystem *s);

void FIELD_SOUND_SYSTEM_HandleModeState3(FieldSoundSystem *s);

void FIELD_SOUND_SYSTEM_HandleModeState4(FieldSoundSystem *s);

void FIELD_SOUND_SYSTEM_HandleModeState5(FieldSoundSystem *s);

void FIELD_SOUND_SYSTEM_HandleModeState6(FieldSoundSystem *s);

void FIELD_SOUND_SYSTEM_HandleModeState7(FieldSoundSystem *s);

void FIELD_SOUND_SYSTEM_HandleModeState8(FieldSoundSystem *s);

void FIELD_SOUND_SYSTEM_HandleModeState9(FieldSoundSystem *s);

void FIELD_SOUND_SYSTEM_HandleModeState10(FieldSoundSystem *s);

void FIELD_SOUND_SYSTEM_HandleModeState11(FieldSoundSystem *s);

void FIELD_SOUND_SYSTEM_HandleModeState12(FieldSoundSystem *s);

void FIELD_SOUND_SYSTEM_HandleModeState13(FieldSoundSystem *s);

void FIELD_SOUND_SYSTEM_HandleModeState14(FieldSoundSystem *s);

void FIELD_SOUND_SYSTEM_HandleModeState15(FieldSoundSystem *s);

void FIELD_SOUND_SYSTEM_HandleModeState16(FieldSoundSystem *s);

void FIELD_SOUND_SYSTEM_HandleModeState17(FieldSoundSystem *s);

extern const char g_020A7590[];

extern const u16 sTable_0209FDD0[];

extern u8 g_0209FD90[][8];

extern const u8 g_flagTable_0209FE1C[];

extern void (*g_020A7554[])(FieldSoundSystem *);

extern void (*g_020A7518[])(FieldSoundSystem *);

/* Constructor: allocates the system through the debug allocator (file name and line number are arguments). */
FieldSoundSystem *FIELD_SOUND_SYSTEM_Create(struct GameData *gameData, u32 heap)
{
    FieldSoundSystem *s;

    s = GFL_HEAP_Alloc(heap, sizeof(FieldSoundSystem), 1, g_020A7590, 331);
    FIELD_SOUND_SYSTEM_Init(s, gameData);
    s->volumeFader = PLAYER_VOLUME_FADER_Create((void *)heap, 0);
    s->ringtone = RINGTONE_SYS_Create(heap, s->volumeFader);
    GFL_USE_SetSeqStartFilter(FIELD_SOUND_SYSTEM_IsSoundIdPlayable);
    return s;
}

/* Destructor. */
void FIELD_SOUND_SYSTEM_Delete(FieldSoundSystem *s)
{
    GFL_USE_SetSeqStartFilter(0);
    RINGTONE_SYS_Delete(s->ringtone);
    PLAYER_VOLUME_FADER_Delete(s->volumeFader);
    GFL_HEAP_Free(s);
}

/* Queue depth callers poll: stack depth plus pending pushes (kind 3) less pops (kind 4), with two mode corrections. */
int FIELD_SOUND_SYSTEM_GetPendingBgmStackDepth(FieldSoundSystem *s)
{
    int depth = s->stackDepth;
    u32 mode;

    depth = depth + FIELD_SOUND_SYSTEM_CountRequestsOfKind(s, 3);
    depth = depth - FIELD_SOUND_SYSTEM_CountRequestsOfKind(s, 4);
    mode = s->mode;
    if (mode == 3) {
        if (s->state == 5 || s->state - 0xB <= 1) {
            depth++;
        }
    }
    if (mode == 4) {
        if (s->state == 6) {
            depth--;
        }
    }
    return depth;
}

/*
 * Replays the queued requests (kind 3 push, 4 pop, 5 to 7 set) over the
 * current values and returns the value the system will end up with.
 *
 * stand-in: the write index is read through a volatile cast. Without it the
 * compiler hoists the load out of the loop (the divide helper call in the
 * loop is not treated as a memory barrier) and the function is 8 bytes shorter.
 */
void *FIELD_SOUND_SYSTEM_GetFinalValue(FieldSoundSystem *s)
{
    void *value;
    int depth;
    int i;
    int cursor;
    FieldSoundRequest *req;
    void *stack[1];

    value = (void *)s->currentValue;
    if (s->requestedValue != 0) {
        value = (void *)s->requestedValue;
    }
    if (s->loadingValue != 0) {
        value = (void *)s->loadingValue;
    }
    depth = s->stackDepth;
    cursor = s->readIndex;
    for (i = 0; i < depth; i++) {
        stack[i] = (void *)s->valueStack[i];
    }
    while (cursor != *(volatile u8 *)&s->writeIndex) {
        req = &s->queue[cursor];
        if (req->kind == 3) {
            stack[depth++] = value;
        } else if (req->kind == 4) {
            depth--;
            value = stack[depth];
        } else if (req->kind - 5 <= 2) {
            value = (void *)req->value;
        }
        cursor = (cursor + 1) % 10;
    }
    return value;
}

/*
 * Predicate over the state word: nine accepted values in one disjunction (they share one exit).
 * The order of the tests is the order of the compares in the original.
 */
u32 FIELD_SOUND_SYSTEM_IsStateActive(FieldSoundSystem *s)
{
    u32 state = s->state;

    if (state == 4 || state == 3 || state == 6 || state == 7 || state == 5 || state == 8 || state == 10 ||
        state == 11 || state == 13) {
        return 1;
    }
    return 0;
}

/* Busy: the queue helper says so or the mode is non zero. Written as a negated conjunction (its `return 0` is the block emitted first). */
u32 FIELD_SOUND_SYSTEM_IsBusy(FieldSoundSystem *s)
{
    if (FIELD_SOUND_SYSTEM_HasPendingRequest(s) == 0 && s->mode == 0) {
        return 0;
    }
    return 1;
}

/* Can take another request: two separate rejections, each with its own epilogue. */
u32 FIELD_SOUND_SYSTEM_CanAcceptRequest(FieldSoundSystem *s)
{
    if (s->mode == 4 && s->state == 6) {
        return 0;
    }
    if (FIELD_SOUND_SYSTEM_CountRequestsOfKind(s, 4) != 0) {
        return 0;
    }
    return 1;
}

/* Builds a request record on the stack and enqueues it; every caller in the region goes through here. */
void FIELD_SOUND_SYSTEM_PostRequest(FieldSoundSystem *s, u32 kind, u32 value, u16 lowParam, u16 highParam)
{
    FieldSoundRequest req;

    req.kind = kind;
    req.value = value;
    req.lowParam = lowParam;
    req.highParam = highParam;
    FIELD_SOUND_SYSTEM_EnqueueRequest(s, &req);
}

/* Per-frame update: process one request, run the per-state handlers, then update ringtone and fader. */
void FIELD_SOUND_SYSTEM_Update(FieldSoundSystem *s)
{
    FIELD_SOUND_SYSTEM_ProcessNextRequest(s);
    g_020A7554[s->state](s);
    g_020A7518[s->state](s);
    RINGTONE_SYS_Update(s->ringtone);
    PLAYER_VOLUME_FADER_Update(s->volumeFader);
}

/*
 * Forwarding thunks (a pool word and a bx). The reset thunk is the only caller of
 * the drain-and-init function reachable from ringtone_sys.c. The three after it
 * first fetch a sub-object (fader at +0xA4, ringtone at +0xA8); the offsets are
 * past the Thumb ldr immediate, which costs an adds, not a second pointer.
 */
void FIELD_SOUND_SYSTEM_Reset(FieldSoundSystem *s, struct GameData *gameData)
{
    FIELD_SOUND_SYSTEM_DrainAndInit(s, gameData);
}

void FIELD_SOUND_SYSTEM_FadeVolume(FieldSoundSystem *s, u8 level, u16 frames)
{
    PLAYER_VOLUME_FADER_SetTarget(s->volumeFader, level, frames);
}

void FIELD_SOUND_SYSTEM_StartRingtone(FieldSoundSystem *s)
{
    RINGTONE_SYS_Start(s->ringtone);
}

void FIELD_SOUND_SYSTEM_StopRingtone(FieldSoundSystem *s)
{
    RINGTONE_SYS_Stop(s->ringtone);
}

/*
 * Sound slot functions: the two tables at +0xAC and +0xB0 hold two halfwords
 * each (the loop in the transfer function fixes the count at two). Both are
 * past the Thumb halfword immediate, so each access recomputes base + index*2.
 */

/* Claims a slot for a caller that gives no owner; marks the owner 0xFFFF. */
void FIELD_SOUND_SYSTEM_ClaimSlot(FieldSoundSystem *s, u32 soundId)
{
    u32 slotIndex;

    if (FIELD_SOUND_SYSTEM_FindSlotSound(soundId) == 0) {
        GFL_USE_PlaySeDefaultVolume(soundId);
        return;
    }
    if (FIELD_SOUND_SYSTEM_IsSlotSoundTracked(soundId) != 0) {
        slotIndex = GFL_USE_GetSeSlot(soundId) - 1;
        s->slotSoundId[slotIndex] = soundId;
        s->slotOwner[slotIndex] = 0xFFFF;
    }
    if (s->pauseMask == 0) {
        GFL_USE_PlaySeDefaultVolume(soundId);
    }
}

/* The same claim with an owner supplied by the caller. */
void FIELD_SOUND_SYSTEM_ClaimSlotWithOwner(FieldSoundSystem *s, u32 soundId, u32 owner)
{
    u32 slotIndex;

    if (FIELD_SOUND_SYSTEM_FindSlotSound(soundId) == 0) {
        GFL_USE_PlaySeDefaultVolume(soundId);
        return;
    }
    if (FIELD_SOUND_SYSTEM_IsSlotSoundTracked(soundId) != 0) {
        slotIndex = GFL_USE_GetSeSlot(soundId) - 1;
        s->slotSoundId[slotIndex] = soundId;
        s->slotOwner[slotIndex] = owner;
    }
    if (s->pauseMask == 0) {
        GFL_USE_PlaySeWithVolume(soundId, owner);
    }
}

/* Hands a claimed slot to a new owner. */
void FIELD_SOUND_SYSTEM_TransferSlot(FieldSoundSystem *s, u32 soundId, u32 owner)
{
    int i;

    if (FIELD_SOUND_SYSTEM_FindSlotSound(soundId) != 0) {
        for (i = 0; i < 2; i++) {
            if (s->slotSoundId[i] == soundId) {
                GFL_USE_SetSeSlotVolume(i + 1, owner);
                s->slotOwner[i] = owner;
                return;
            }
        }
    }
}

/* Releases the slot that holds the sound. Both halfword cells are cleared through one scaled index (separate u16 pointers cost two bytes of frame). */
void FIELD_SOUND_SYSTEM_ReleaseSlot(FieldSoundSystem *s, int soundId)
{
    u32 slotNumber;

    slotNumber = GFL_USE_GetSeSlot(soundId);
    if (FIELD_SOUND_SYSTEM_FindSlotSound(soundId) == 0) {
        GFL_USE_StopSeSlot(slotNumber);
        return;
    }
    if (FIELD_SOUND_SYSTEM_IsSlotSoundTracked(soundId) != 0) {
        if (soundId == s->slotSoundId[slotNumber - 1]) {
            s->slotSoundId[slotNumber - 1] = 0xffff;
            s->slotOwner[slotNumber - 1] = 0xffff;
        }
    }
    GFL_USE_StopSeSlot(slotNumber);
}

/* Adds bits to the pause set; on the first bit, stops the sounds in both slots. */
void FIELD_SOUND_SYSTEM_PauseSlots(FieldSoundSystem *s, u32 bits)
{
    int i;

    if (s->pauseMask == 0) {
        for (i = 0; i < 2; i++) {
            if (s->slotSoundId[i] != 0xffff) {
                GFL_USE_StopSeSlot(i + 1);
            }
        }
    }
    s->pauseMask |= bits;
}

/* Drops bits from the pause set; when the set empties, replays the two stored sounds. */
void FIELD_SOUND_SYSTEM_ResumeSlots(FieldSoundSystem *s, u32 bits)
{
    int i;

    if ((s->pauseMask & bits) == 0)
        return;

    s->pauseMask = s->pauseMask & ~bits;

    if (s->pauseMask != 0)
        return;

    for (i = 0; i < 2; i++) {
        if (s->slotSoundId[i] != 0xffff) {
            if (s->slotOwner[i] == 0xffff)
                GFL_USE_PlaySeDefaultVolume(s->slotSoundId[i]);
            else
                GFL_USE_PlaySeWithVolume(s->slotSoundId[i], s->slotOwner[i]);
        }
    }
}

/* Is the id one of the 0x26 ids in sTable_0209FDD0. */
int FIELD_SOUND_SYSTEM_IsKnownSoundId(u32 soundId)
{
    u32 i;

    for (i = 0; i < 0x26; i++) {
        if (soundId == sTable_0209FDD0[i]) {
            return 1;
        }
    }
    return 0;
}

/* Walks the record chain (event, group, entries) of the index and checks each link. */
u32 FIELD_SOUND_SYSTEM_IsSoundRecordChainValid(int soundIndex)
{
    SoundEventRecord *eventRec;
    int i;
    SoundGroupRecord *groupRec;

    eventRec = NNS_SndArcGetSeqInfo(soundIndex);
    if (NNS_SndArcGetFileAddress(eventRec->checkId) == 0) {
        return 0;
    }

    groupRec = NNS_SndArcGetBankInfo(eventRec->groupIndex);
    if (NNS_SndArcGetFileAddress(groupRec->checkId) == 0) {
        return 0;
    }

    for (i = 0; i < 4; i++) {
        if (groupRec->entryId[i] != 0xffff) {
            if (NNS_SndArcGetFileAddress(NNS_SndArcGetWaveArcInfo(groupRec->entryId[i])->checkId) == 0) {
                return 0;
            }
        }
    }

    return 1;
}

/* Hook registered with GFL_USE_SetSeqStartFilter: accepts an id that is in the table and whose record chain is valid. */
int FIELD_SOUND_SYSTEM_IsSoundIdPlayable(u32 soundId)
{
    if (FIELD_SOUND_SYSTEM_IsKnownSoundId(soundId) == 0) {
        return 0;
    }
    if (FIELD_SOUND_SYSTEM_IsSoundRecordChainValid(soundId) != 0) {
        return 1;
    }
    return 0;
}

/* Initialises the system from the descriptor (shared by the constructor and the drain-and-init function). */
void FIELD_SOUND_SYSTEM_Init(FieldSoundSystem *s, struct GameData *gameData)
{
    int i;

    s->gameData = gameData;
    s->state = 0;
    s->mode = 0;
    s->currentValue = 0;
    s->requestedValue = 0;
    s->loadingValue = 0;
    s->loadStep = 0;
    s->highParam = 0;
    s->lowParam = 0;
    s->stackDepth = 0;
    s->valueStack[0] = 0;

    for (i = 0; i < 10; i++)
        s->queue[i].kind = 0;

    s->readIndex = 0;
    s->writeIndex = 0;

    for (i = 0; i < 2; i++)
        s->slotSoundId[i] = 0xffff;

    s->pauseMask = 0;
}

/*
 * Drains the stack through FIELD_SOUND_SYSTEM_PopBgm, closes the frame and re-initialises
 * from gameData. Nothing branches to it; its only reference is the pool word of
 * the reset thunk.
 */
void FIELD_SOUND_SYSTEM_DrainAndInit(FieldSoundSystem *s, struct GameData *gameData)
{
    while (s->stackDepth != 0) {
        FIELD_SOUND_SYSTEM_PopBgm(s);
    }
    GFL_USE_CancelChangeAndStopBgm();
    FIELD_SOUND_SYSTEM_Init(s, gameData);
}

/* Takes the request at the read index if its class is allowed in the current state, runs it and removes it. */
void FIELD_SOUND_SYSTEM_ProcessNextRequest(FieldSoundSystem *s)
{
    FieldSoundRequest *req = FIELD_SOUND_SYSTEM_GetReadSlot(s);
    if (FIELD_SOUND_SYSTEM_IsKindAllowedInState(s, req->kind)) {
        FIELD_SOUND_SYSTEM_ExecuteRequest(s, req);
        FIELD_SOUND_SYSTEM_DequeueRequest(s);
    }
}

/* Slot at the read index. */
FieldSoundRequest *FIELD_SOUND_SYSTEM_GetReadSlot(FieldSoundSystem *s)
{
    u8 index = s->readIndex;
    return &s->queue[index];
}

/*
 * The slot the caller should look at: the read index while the ring is idle,
 * else the slot before the write index. (writeIndex + 9) % 10 and not
 * writeIndex - 1, because the subtraction has to wrap; the modulo is a call to
 * the signed divide helper.
 */
FieldSoundRequest *FIELD_SOUND_SYSTEM_GetNewestRequest(FieldSoundSystem *s)
{
    int index;

    if (FIELD_SOUND_SYSTEM_HasPendingRequest(s) == 0) {
        index = s->readIndex;
    } else {
        index = (s->writeIndex + 9) % 10;
    }
    return &s->queue[index];
}

/* Is the slot at the read index occupied. */
int FIELD_SOUND_SYSTEM_HasPendingRequest(FieldSoundSystem *s)
{
    return FIELD_SOUND_SYSTEM_GetReadSlot(s)->kind != 0;
}

/*
 * Counts queued requests of the given kind.
 *
 * stand-in: the write index is read through a volatile cast, as in the replay
 * function above (same hoisting, 8 bytes shorter without it).
 */
u8 FIELD_SOUND_SYSTEM_CountRequestsOfKind(FieldSoundSystem *s, u32 kind)
{
    int cursor = s->readIndex;
    u32 count = 0;

    if (cursor != *(volatile u8 *)&s->writeIndex) {
        do {
            if (s->queue[cursor].kind == kind) {
                count++;
            }
            cursor = (cursor + 1) % 10;
        } while (cursor != *(volatile u8 *)&s->writeIndex);
    }
    return count;
}

/*
 * Enqueues one request. A slot whose first word is non zero is still occupied
 * and the request is dropped. The write index is read into a local before the
 * filter call (puts the ldrb above the bl); the advance is a real %.
 */
void FIELD_SOUND_SYSTEM_EnqueueRequest(FieldSoundSystem *s, FieldSoundRequest *req)
{
    int writeIndex;

    writeIndex = s->writeIndex;
    if (FIELD_SOUND_SYSTEM_IsRequestKindAccepted(s, req->kind) == 0) {
        return;
    }
    if (s->queue[writeIndex].kind != 0) {
        return;
    }
    s->queue[writeIndex] = *req;
    s->writeIndex = (writeIndex + 1) % 10;
}

/*
 * Decides whether a request of class kind is accepted. The class of the
 * request at the ring (FIELD_SOUND_SYSTEM_GetNewestRequest) is consulted first, then the latched
 * mode; the first non zero one indexes the 8-wide table at 0x0209FD90 by
 * (row, kind). With neither set, FIELD_SOUND_SYSTEM_IsKindAllowedInState decides. The table base is
 * loaded in each arm (siblings, not a dominator).
 */
u32 FIELD_SOUND_SYSTEM_IsRequestKindAccepted(FieldSoundSystem *s, u32 kind)
{
    u32 row;

    row = FIELD_SOUND_SYSTEM_GetNewestRequest(s)->kind;
    if (row != 0) {
        return g_0209FD90[row][kind];
    }
    row = s->mode;
    if (row != 0) {
        return g_0209FD90[row][kind];
    }
    return FIELD_SOUND_SYSTEM_IsKindAllowedInState(s, kind);
}

/* Removes the request at the read index. */
void FIELD_SOUND_SYSTEM_DequeueRequest(FieldSoundSystem *s)
{
    int readIndex = s->readIndex;

    if (FIELD_SOUND_SYSTEM_HasPendingRequest(s) != 0) {
        s->queue[readIndex].kind = 0;
        s->readIndex = (readIndex + 1) % 10;
    }
}

/* Runs one request: kind n latches mode n. */
void FIELD_SOUND_SYSTEM_ExecuteRequest(FieldSoundSystem *s, FieldSoundRequest *req)
{
    switch (req->kind) {
    case 1:
        FIELD_SOUND_SYSTEM_SetMode1(s, req->highParam);
        break;
    case 2:
        FIELD_SOUND_SYSTEM_SetMode2(s, req->lowParam);
        break;
    case 3:
        FIELD_SOUND_SYSTEM_SetMode3(s, req->lowParam);
        break;
    case 4:
        FIELD_SOUND_SYSTEM_SetMode4(s, req->lowParam, req->highParam);
        break;
    case 5:
        FIELD_SOUND_SYSTEM_SetMode5(s, req->value, req->lowParam, req->highParam);
        break;
    case 6:
        FIELD_SOUND_SYSTEM_SetMode6(s, req->value, req->lowParam);
        break;
    case 7:
        FIELD_SOUND_SYSTEM_SetMode7(s, (u16)req->value);
        break;
    default:
        break;
    }
}

void FIELD_SOUND_SYSTEM_SetMode1(FieldSoundSystem *s, u16 highParam)
{
    if (FIELD_SOUND_SYSTEM_IsKindAllowedInState(s, 1)) {
        s->mode = 1;
        s->highParam = highParam;
    }
}

void FIELD_SOUND_SYSTEM_SetMode2(FieldSoundSystem *s, u16 lowParam)
{
    if (FIELD_SOUND_SYSTEM_IsKindAllowedInState(s, 2)) {
        s->mode = 2;
        s->lowParam = lowParam;
    }
}

void FIELD_SOUND_SYSTEM_SetMode3(FieldSoundSystem *s, u16 lowParam)
{
    if (FIELD_SOUND_SYSTEM_IsKindAllowedInState(s, 3)) {
        s->mode = 3;
        s->lowParam = lowParam;
    }
}

void FIELD_SOUND_SYSTEM_SetMode4(FieldSoundSystem *s, u16 lowParam, u16 highParam)
{
    if (FIELD_SOUND_SYSTEM_IsKindAllowedInState(s, 4)) {
        s->mode = 4;
        s->highParam = highParam;
        s->lowParam = lowParam;
    }
}

void FIELD_SOUND_SYSTEM_SetMode5(FieldSoundSystem *s, u32 value, u16 lowParam, u16 highParam)
{
    if (FIELD_SOUND_SYSTEM_IsKindAllowedInState(s, 5)) {
        s->mode = 5;
        s->requestedValue = value;
        s->highParam = highParam;
        s->lowParam = lowParam;
    }
}

void FIELD_SOUND_SYSTEM_SetMode6(FieldSoundSystem *s, u32 value, u16 lowParam)
{
    if (FIELD_SOUND_SYSTEM_IsKindAllowedInState(s, 6)) {
        s->mode = 6;
        s->requestedValue = value;
        s->lowParam = lowParam;
    }
}

void FIELD_SOUND_SYSTEM_SetMode7(FieldSoundSystem *s, u32 value)
{
    if (FIELD_SOUND_SYSTEM_IsKindAllowedInState(s, 7)) {
        s->mode = 7;
        s->requestedValue = value;
    }
}

/* Is a request of class kind allowed in the current state (8 flags per state in g_flagTable_0209FE1C). */
u32 FIELD_SOUND_SYSTEM_IsKindAllowedInState(FieldSoundSystem *s, u32 kind)
{
    const u8 *flags = g_flagTable_0209FE1C + s->state * 8;
    return flags[kind];
}

/* Entry 0 of the mode handler table g_020A7554: a Thumb switch on the latched mode. */
void FIELD_SOUND_SYSTEM_HandleModeState0(FieldSoundSystem *s)
{
    switch (s->mode) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4:
        FIELD_SOUND_SYSTEM_PopBgm(s);
        FIELD_SOUND_SYSTEM_FadeInCurrentBgm(s);
        FIELD_SOUND_SYSTEM_SetState(s, 7);
        break;
    case 5:
        FIELD_SOUND_SYSTEM_SetState(s, 8);
        break;
    case 6:
        FIELD_SOUND_SYSTEM_SetState(s, 0xd);
        break;
    case 7:
        FIELD_SOUND_SYSTEM_PlayRequestedBgmNow(s);
        FIELD_SOUND_SYSTEM_SetState(s, 1);
        FIELD_SOUND_SYSTEM_FinishRequest(s);
        break;
    }
}

/* Entry 1 of g_020A7554: an eight arm switch (add pc, r0) on the mode. Every callee takes the object, so the index lives in r1. */
void FIELD_SOUND_SYSTEM_HandleModeState1(FieldSoundSystem *s)
{
    switch (s->mode) {
    case 0:
        break;
    case 1:
        FIELD_SOUND_SYSTEM_DiscardRequest(s);
        break;
    case 2:
        FIELD_SOUND_SYSTEM_FadeOutCurrentBgm(s);
        FIELD_SOUND_SYSTEM_SetState(s, 3);
        break;
    case 3:
        FIELD_SOUND_SYSTEM_FadeOutCurrentBgm(s);
        FIELD_SOUND_SYSTEM_SetState(s, 5);
        break;
    case 4:
        FIELD_SOUND_SYSTEM_FadeOutCurrentBgm(s);
        FIELD_SOUND_SYSTEM_SetState(s, 6);
        break;
    case 5:
        if (s->requestedValue == s->currentValue) {
            FIELD_SOUND_SYSTEM_DiscardRequest(s);
        } else {
            FIELD_SOUND_SYSTEM_FadeOutCurrentBgm(s);
            FIELD_SOUND_SYSTEM_SetState(s, 8);
        }
        break;
    case 6:
        if (s->requestedValue == s->currentValue) {
            FIELD_SOUND_SYSTEM_DiscardRequest(s);
        } else {
            FIELD_SOUND_SYSTEM_FadeOutCurrentBgm(s);
            FIELD_SOUND_SYSTEM_SetState(s, 0xd);
        }
        break;
    case 7:
        if (s->requestedValue == s->currentValue) {
            FIELD_SOUND_SYSTEM_DiscardRequest(s);
        } else {
            FIELD_SOUND_SYSTEM_PlayRequestedBgmNow(s);
            FIELD_SOUND_SYSTEM_SetState(s, 1);
            FIELD_SOUND_SYSTEM_FinishRequest(s);
        }
        break;
    }
}

/* Entry 2 of g_020A7554. */
void FIELD_SOUND_SYSTEM_HandleModeState2(FieldSoundSystem *s)
{
    switch (s->mode) {
    case 0:
        break;
    case 1:
        FIELD_SOUND_SYSTEM_FadeInCurrentBgm(s);
        FIELD_SOUND_SYSTEM_SetState(s, 4);
        break;
    case 7:
        FIELD_SOUND_SYSTEM_PlayRequestedBgmNow(s);
        FIELD_SOUND_SYSTEM_SetState(s, 1);
        FIELD_SOUND_SYSTEM_FinishRequest(s);
        break;
    }
}

/* Entries 3 to 7 of g_020A7554: states with no mode handling. */
void FIELD_SOUND_SYSTEM_HandleModeState3(FieldSoundSystem *s)
{
}

void FIELD_SOUND_SYSTEM_HandleModeState4(FieldSoundSystem *s)
{
}

void FIELD_SOUND_SYSTEM_HandleModeState5(FieldSoundSystem *s)
{
}

void FIELD_SOUND_SYSTEM_HandleModeState6(FieldSoundSystem *s)
{
}

void FIELD_SOUND_SYSTEM_HandleModeState7(FieldSoundSystem *s)
{
}

void FIELD_SOUND_SYSTEM_HandleModeState8(FieldSoundSystem *s)
{
    switch (s->mode) {
    case 0:
    case 5:
        break;
    case 3:
        FIELD_SOUND_SYSTEM_SetState(s, 11);
        break;
    }
}

void FIELD_SOUND_SYSTEM_HandleModeState9(FieldSoundSystem *s)
{
    switch (s->mode) {
    case 0:
    case 5:
        break;
    case 3:
        FIELD_SOUND_SYSTEM_SetState(s, 12);
        break;
    }
}

void FIELD_SOUND_SYSTEM_HandleModeState10(FieldSoundSystem *s)
{
}

void FIELD_SOUND_SYSTEM_HandleModeState11(FieldSoundSystem *s)
{
}

void FIELD_SOUND_SYSTEM_HandleModeState12(FieldSoundSystem *s)
{
}

void FIELD_SOUND_SYSTEM_HandleModeState13(FieldSoundSystem *s)
{
}

void FIELD_SOUND_SYSTEM_HandleModeState14(FieldSoundSystem *s)
{
}

void FIELD_SOUND_SYSTEM_HandleModeState15(FieldSoundSystem *s)
{
}

void FIELD_SOUND_SYSTEM_HandleModeState16(FieldSoundSystem *s)
{
}

void FIELD_SOUND_SYSTEM_HandleModeState17(FieldSoundSystem *s)
{
}

struct GameSystem;

struct GameEvent;

struct IssSys;

struct Iss3dsSys;

struct PlayerWork;

/* Request kinds the field sound system accepts (also the latched mode of the system). */
enum FieldSoundRequestKind {
    FIELD_SOUND_REQUEST_FADE_IN = 1,    /* highParam: fade in frames, from the muted state */
    FIELD_SOUND_REQUEST_FADE_OUT = 2,   /* lowParam: fade out frames, the BGM stays loaded and silent */
    FIELD_SOUND_REQUEST_PUSH = 3,       /* lowParam: fade out, then suspend the BGM on the stack */
    FIELD_SOUND_REQUEST_POP = 4,        /* lowParam: fade out, restore the suspended BGM, highParam: fade in */
    FIELD_SOUND_REQUEST_CHANGE = 5,     /* value: new BGM, lowParam: fade out, highParam: fade in (loaded in the background) */
    FIELD_SOUND_REQUEST_REPLACE = 6,    /* value: new BGM, lowParam: fade out, starts silent without loading */
    FIELD_SOUND_REQUEST_PLAY_NOW = 7    /* value: new BGM, started at once */
};

/* States of the field sound system. */
enum FieldSoundState {
    FIELD_SOUND_STATE_NO_BGM = 0,
    FIELD_SOUND_STATE_PLAYING = 1,
    FIELD_SOUND_STATE_MUTED = 2,
    FIELD_SOUND_STATE_FADING_OUT_TO_MUTE = 3,
    FIELD_SOUND_STATE_FADING_IN = 4,
    FIELD_SOUND_STATE_FADING_OUT_TO_PUSH = 5,
    FIELD_SOUND_STATE_FADING_OUT_TO_POP = 6,
    FIELD_SOUND_STATE_FADING_IN_AFTER_POP = 7,
    FIELD_SOUND_STATE_FADING_OUT_TO_LOAD = 8,
    FIELD_SOUND_STATE_LOADING = 9,
    FIELD_SOUND_STATE_FADING_IN_LOADED = 10,
    FIELD_SOUND_STATE_FADING_OUT_TO_LOAD_AND_PUSH = 11,
    FIELD_SOUND_STATE_LOADING_AND_PUSH = 12,
    FIELD_SOUND_STATE_FADING_OUT_TO_REPLACE = 13,
    FIELD_SOUND_STATE_REPLACING = 14
};

/* Work block (0x10 bytes) of the field sound tasks started below. */
typedef struct FieldSoundTaskWork {
    struct GameSystem *gameSystem;  /* 0x00 */
    FieldSoundSystem *fieldSound;   /* 0x04 */
    u32 value;                      /* 0x08 BGM number */
    u16 highParam;                  /* 0x0C fade in frames */
    u16 lowParam;                   /* 0x0E fade out frames */
} FieldSoundTaskWork;

typedef int (*FieldSoundTaskFunc)(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);

/* BGM played when a trainer of a class spots the player. */
typedef struct TrainerClassBgm {
    u16 trainerClass;
    u16 bgmNo;
} TrainerClassBgm;

/* One entry of the zone BGM override table: applies in the zone while the event flag is set. */
typedef struct ZoneBgmOverride {
    u16 eventFlag;
    u16 zoneId;
    u32 bgmNo;
} ZoneBgmOverride;

extern int GFL_USE_IsBgmFading(void);

extern void GFL_USE_FadeInBgmFull(u32 frames);

extern void GFL_USE_SetBgmPaused(u32 value);

extern void GFL_USE_FadeOutBgm(u32 frames);

extern int GFL_USE_PushBgm(void);

extern int GFL_USE_PopBgm(void);

extern u32 GFL_USE_StepBgmLoad(u32 bgmNo, u32 *step, u32 abort);

extern void GFL_NET_SetDeviceModeIfRunning(int a);

extern void GFL_USE_CancelChangeAndPlayBgm(u32 bgmNo, u32 frames);

extern u8 GAME_DATA_IsSaving(const struct GameData *gameData);

extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);

extern struct GameEvent *GAME_EVENT_Create(struct GameSystem *gameSystem, struct GameEvent *parent, FieldSoundTaskFunc func, u32 workSize);

extern void *GAME_EVENT_GetWork(struct GameEvent *event);

extern u32 GAME_DATA_GetBgmInfo(const struct GameData *gameData);

extern u8 GAME_DATA_GetSeason(const struct GameData *gameData);

extern struct Iss3dsSys *ISS_SYS_Get3dsSys(struct IssSys *iss);

extern void ISS_3DS_SYS_SetVolume(struct Iss3dsSys *iss3ds, u32 volume);

extern u32 ZONEDATA_GetBgmId(u32 zoneId, u32 season);

extern void *GAME_DATA_GetEventWork(const struct GameData *gameData);

extern u32 ZONEDATA_CheckEventFlag(void *eventFlags, s32 flagId);

extern u32 ZONEDATA_IsRideBgmEnabled(u32 zoneId);

extern struct PlayerWork *GAME_DATA_GetMyPlayerWork(struct GameData *gameData);

extern int GAME_DATA_GetPlayerObjectCode(const struct PlayerWork *player);

extern const TrainerClassBgm sTrainerClassBgmTable[];

extern const ZoneBgmOverride sZoneBgmOverrides[8];

void FIELD_SOUND_SYSTEM_UpdateFadingOutToMute(FieldSoundSystem *fieldSound);

void FIELD_SOUND_SYSTEM_UpdateFadingIn(FieldSoundSystem *fieldSound);

void FIELD_SOUND_SYSTEM_UpdateFadingOutToPush(FieldSoundSystem *fieldSound);

void FIELD_SOUND_SYSTEM_UpdateFadingOutToPop(FieldSoundSystem *fieldSound);

void FIELD_SOUND_SYSTEM_UpdateFadingInAfterPop(FieldSoundSystem *fieldSound);

void FIELD_SOUND_SYSTEM_UpdateFadingOutToLoad(FieldSoundSystem *fieldSound);

void FIELD_SOUND_SYSTEM_UpdateLoading(FieldSoundSystem *fieldSound);

void FIELD_SOUND_SYSTEM_UpdateFadingInLoaded(FieldSoundSystem *fieldSound);

void FIELD_SOUND_SYSTEM_UpdateFadingOutToLoadAndPush(FieldSoundSystem *fieldSound);

void FIELD_SOUND_SYSTEM_UpdateLoadingAndPush(FieldSoundSystem *fieldSound);

void FIELD_SOUND_SYSTEM_UpdateFadingOutToReplace(FieldSoundSystem *fieldSound);

void FIELD_SOUND_SYSTEM_UpdateReplacing(FieldSoundSystem *fieldSound);

void FIELD_SOUND_SYSTEM_ClearRequest(FieldSoundSystem *fieldSound);

void FIELD_SOUND_SYSTEM_PushCurrentBgm(FieldSoundSystem *fieldSound);

u32 FIELD_SOUND_SYSTEM_StartLoadingRequestedBgm(FieldSoundSystem *fieldSound);

u32 FIELD_SOUND_SYSTEM_StepBgmLoading(FieldSoundSystem *fieldSound);

u32 FIELD_SOUND_SYSTEM_IsSaving(FieldSoundSystem *fieldSound);

int FIELD_SOUND_SYSTEM_FadeInTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);

struct GameEvent *FIELD_SOUND_SYSTEM_StartFadeInTask(struct GameSystem *gameSystem, u32 fadeInFrames);

int FIELD_SOUND_SYSTEM_FadeOutTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);

struct GameEvent *FIELD_SOUND_SYSTEM_StartFadeOutTask(struct GameSystem *gameSystem, u32 fadeOutFrames);

int FIELD_SOUND_SYSTEM_PushTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);

struct GameEvent *FIELD_SOUND_SYSTEM_StartPushTask(struct GameSystem *gameSystem, u32 fadeOutFrames);

int FIELD_SOUND_SYSTEM_PopAndWaitTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);

struct GameEvent *FIELD_SOUND_SYSTEM_StartPopAndWaitTask(struct GameSystem *gameSystem, u32 fadeOutFrames, u32 fadeInFrames);

int FIELD_SOUND_SYSTEM_PopTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);

struct GameEvent *FIELD_SOUND_SYSTEM_StartPopTask(struct GameSystem *gameSystem, u32 fadeOutFrames, u32 fadeInFrames);

int FIELD_SOUND_SYSTEM_PopAllTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);

struct GameEvent *FIELD_SOUND_SYSTEM_StartPopAllTask(struct GameSystem *gameSystem, u16 fadeInFrames);

int FIELD_SOUND_SYSTEM_PushAndChangeTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);

struct GameEvent *FIELD_SOUND_SYSTEM_StartPushAndChangeTask(struct GameSystem *gameSystem, u32 bgmNo, u32 fadeOutFrames, u32 fadeInFrames);

int FIELD_SOUND_SYSTEM_PushAndPlayTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);

struct GameEvent *FIELD_SOUND_SYSTEM_StartPushAndPlayTask(struct GameSystem *gameSystem, u32 bgmNo);

int FIELD_SOUND_SYSTEM_ChangeTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);

struct GameEvent *FIELD_SOUND_SYSTEM_StartChangeTask(struct GameSystem *gameSystem, u32 bgmNo, u32 fadeOutFrames, u32 fadeInFrames);

int FIELD_SOUND_SYSTEM_FadeOutAndResetTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);

int FIELD_SOUND_SYSTEM_FadeOutAndPlayTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);

struct GameEvent *FIELD_SOUND_SYSTEM_StartFadeOutAndPlayTask(struct GameSystem *gameSystem, u32 bgmNo);

int FIELD_SOUND_SYSTEM_FadeOutAndPlayWithFadeTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);

struct GameEvent *FIELD_SOUND_SYSTEM_StartFadeOutAndPlayWithFadeTask(struct GameSystem *gameSystem, u32 bgmNo, u16 fadeOutFrames);

int FIELD_SOUND_SYSTEM_FadeOutAndPlayFixedBgmTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);

struct GameEvent *FIELD_SOUND_SYSTEM_StartFadeOutAndPlayFixedBgmTask(struct GameSystem *gameSystem, u16 fadeOutFrames);

int FIELD_SOUND_SYSTEM_PushAndPlayWaitTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);

struct GameEvent *FIELD_SOUND_SYSTEM_StartPushAndPlayWaitTask(struct GameSystem *gameSystem, u32 bgmNo);

struct GameEvent *FIELD_SOUND_SYSTEM_StartFadeOutAndResetTask(struct GameSystem *gameSystem, u16 fadeOutFrames);

int FIELD_SOUND_SYSTEM_PushOrFadeOutAndPlayTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);

struct GameEvent *FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(struct GameSystem *gameSystem, u32 bgmNo);

struct GameEvent *FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(struct GameSystem *gameSystem);

int FIELD_SOUND_SYSTEM_WaitSettledTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);

struct GameEvent *FIELD_SOUND_SYSTEM_StartWaitSettledTask(struct GameSystem *gameSystem);

int FIELD_SOUND_SYSTEM_WaitAcceptRequestTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);

struct GameEvent *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(struct GameSystem *gameSystem);

void FIELD_SOUND_SYSTEM_PostZoneBgmChange(FieldSoundSystem *fieldSound, struct GameData *gameData, u32 zoneId);

void FIELD_SOUND_SYSTEM_PostZoneBgmReplace(FieldSoundSystem *fieldSound, struct GameData *gameData, u16 zoneId, u8 season);

void FIELD_SOUND_SYSTEM_PostFadeIn(FieldSoundSystem *fieldSound);

void FIELD_SOUND_SYSTEM_PostZoneBgmChangeShortFade(FieldSoundSystem *fieldSound, struct GameData *gameData, u32 zoneId);

void FIELD_SOUND_SYSTEM_LowerVolume(FieldSoundSystem *fieldSound, struct IssSys *iss);

void FIELD_SOUND_SYSTEM_RestoreVolume(FieldSoundSystem *fieldSound, struct IssSys *iss);

unsigned int FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx(struct GameData *gameData, unsigned int zoneId, unsigned int season);

void *FIELD_SOUND_SYSTEM_GetFinalBgm(const struct GameData *gameData);

int FIELD_SOUND_SYSTEM_HasZoneBgmOverride(struct GameData *gameData, u32 zoneId);

u16 FIELD_SOUND_SYSTEM_GetTrainerClassBgm(u32 trainerClass);

int FIELD_SOUND_SYSTEM_GetPlayerObjectCode(struct GameData *gameData);

u32 FIELD_SOUND_SYSTEM_GetZoneBgm(struct GameData *gameData, u32 zoneId, u32 season);

u32 FIELD_SOUND_SYSTEM_FindZoneBgmOverride(struct GameData *gameData, u32 zoneId);

u32 FIELD_SOUND_SYSTEM_GetFieldBgmForZone(struct GameData *gameData, u32 zoneId, u32 season);

/* State FADING_OUT_TO_MUTE: when the fade is over the BGM stays loaded and silent. */
void FIELD_SOUND_SYSTEM_UpdateFadingOutToMute(FieldSoundSystem *fieldSound)
{
    if (GFL_USE_IsBgmFading() != 0) {
        return;
    }
    FIELD_SOUND_SYSTEM_SetState(fieldSound, FIELD_SOUND_STATE_MUTED);
    FIELD_SOUND_SYSTEM_FinishRequest(fieldSound);
}

/* State FADING_IN: when the fade is over the BGM plays at full volume. */
void FIELD_SOUND_SYSTEM_UpdateFadingIn(FieldSoundSystem *fieldSound)
{
    if (GFL_USE_IsBgmFading() != 0) {
        return;
    }
    FIELD_SOUND_SYSTEM_SetState(fieldSound, FIELD_SOUND_STATE_PLAYING);
    FIELD_SOUND_SYSTEM_FinishRequest(fieldSound);
}

/* State FADING_OUT_TO_PUSH: when the fade is over the BGM goes onto the stack. */
void FIELD_SOUND_SYSTEM_UpdateFadingOutToPush(FieldSoundSystem *fieldSound)
{
    if (GFL_USE_IsBgmFading() != 0) {
        return;
    }
    FIELD_SOUND_SYSTEM_PushCurrentBgm(fieldSound);
    FIELD_SOUND_SYSTEM_SetState(fieldSound, FIELD_SOUND_STATE_NO_BGM);
    FIELD_SOUND_SYSTEM_FinishRequest(fieldSound);
}

/* State FADING_OUT_TO_POP: when the fade is over the suspended BGM comes back and fades in. */
void FIELD_SOUND_SYSTEM_UpdateFadingOutToPop(FieldSoundSystem *fieldSound)
{
    if (GFL_USE_IsBgmFading() != 0) {
        return;
    }
    FIELD_SOUND_SYSTEM_PopBgm(fieldSound);
    FIELD_SOUND_SYSTEM_FadeInCurrentBgm(fieldSound);
    FIELD_SOUND_SYSTEM_SetState(fieldSound, FIELD_SOUND_STATE_FADING_IN_AFTER_POP);
}

/* State FADING_IN_AFTER_POP: when the fade is over the BGM plays at full volume. */
void FIELD_SOUND_SYSTEM_UpdateFadingInAfterPop(FieldSoundSystem *fieldSound)
{
    if (GFL_USE_IsBgmFading() != 0) {
        return;
    }
    FIELD_SOUND_SYSTEM_SetState(fieldSound, FIELD_SOUND_STATE_PLAYING);
    FIELD_SOUND_SYSTEM_FinishRequest(fieldSound);
}

/* State FADING_OUT_TO_LOAD: when the fade is over and no save runs, start loading the requested BGM. */
void FIELD_SOUND_SYSTEM_UpdateFadingOutToLoad(FieldSoundSystem *fieldSound)
{
    if (GFL_USE_IsBgmFading() != 0) {
        return;
    }
    if (FIELD_SOUND_SYSTEM_IsSaving(fieldSound) != 0) {
        return;
    }
    FIELD_SOUND_SYSTEM_StartLoadingRequestedBgm(fieldSound);
    FIELD_SOUND_SYSTEM_SetState(fieldSound, FIELD_SOUND_STATE_LOADING);
}

/* State LOADING: when the load is over, fade the new BGM in, or start over if another BGM was requested. */
void FIELD_SOUND_SYSTEM_UpdateLoading(FieldSoundSystem *fieldSound)
{
    if (FIELD_SOUND_SYSTEM_StepBgmLoading(fieldSound) == 0) {
        return;
    }
    if (fieldSound->requestedValue != 0 && fieldSound->requestedValue != fieldSound->currentValue) {
        GFL_USE_CancelChangeAndStopBgm();
        FIELD_SOUND_SYSTEM_SetState(fieldSound, FIELD_SOUND_STATE_FADING_OUT_TO_LOAD);
        return;
    }
    FIELD_SOUND_SYSTEM_FadeInCurrentBgm(fieldSound);
    FIELD_SOUND_SYSTEM_SetState(fieldSound, FIELD_SOUND_STATE_FADING_IN_LOADED);
}

/* State FADING_IN_LOADED: when the fade is over the BGM plays, unless another BGM was requested meanwhile. */
void FIELD_SOUND_SYSTEM_UpdateFadingInLoaded(FieldSoundSystem *fieldSound)
{
    if (GFL_USE_IsBgmFading() != 0) {
        return;
    }
    if (fieldSound->requestedValue != 0 && fieldSound->requestedValue != fieldSound->currentValue) {
        FIELD_SOUND_SYSTEM_FadeOutCurrentBgm(fieldSound);
        FIELD_SOUND_SYSTEM_SetState(fieldSound, FIELD_SOUND_STATE_FADING_OUT_TO_LOAD);
        return;
    }
    FIELD_SOUND_SYSTEM_SetState(fieldSound, FIELD_SOUND_STATE_PLAYING);
    FIELD_SOUND_SYSTEM_FinishRequest(fieldSound);
}

/* State FADING_OUT_TO_LOAD_AND_PUSH: like FADING_OUT_TO_LOAD, then the loaded BGM is pushed. */
void FIELD_SOUND_SYSTEM_UpdateFadingOutToLoadAndPush(FieldSoundSystem *fieldSound)
{
    if (GFL_USE_IsBgmFading() != 0) {
        return;
    }
    if (FIELD_SOUND_SYSTEM_IsSaving(fieldSound) != 0) {
        return;
    }
    FIELD_SOUND_SYSTEM_StartLoadingRequestedBgm(fieldSound);
    FIELD_SOUND_SYSTEM_SetState(fieldSound, FIELD_SOUND_STATE_LOADING_AND_PUSH);
}

/* State LOADING_AND_PUSH: when the load is over the BGM goes onto the stack. */
void FIELD_SOUND_SYSTEM_UpdateLoadingAndPush(FieldSoundSystem *fieldSound)
{
    if (FIELD_SOUND_SYSTEM_StepBgmLoading(fieldSound) == 0) {
        return;
    }
    FIELD_SOUND_SYSTEM_PushCurrentBgm(fieldSound);
    FIELD_SOUND_SYSTEM_SetState(fieldSound, FIELD_SOUND_STATE_NO_BGM);
    FIELD_SOUND_SYSTEM_FinishRequest(fieldSound);
}

/* State FADING_OUT_TO_REPLACE: when the fade is over, go on to start the replacement. */
void FIELD_SOUND_SYSTEM_UpdateFadingOutToReplace(FieldSoundSystem *fieldSound)
{
    if (GFL_USE_IsBgmFading() != 0) {
        return;
    }
    FIELD_SOUND_SYSTEM_SetState(fieldSound, FIELD_SOUND_STATE_REPLACING);
}

/* State REPLACING: start the requested BGM silent, so that a fade in request can bring it up. */
void FIELD_SOUND_SYSTEM_UpdateReplacing(FieldSoundSystem *fieldSound)
{
    FIELD_SOUND_SYSTEM_PlayRequestedBgmNow(fieldSound);
    GFL_USE_SetBgmPaused(1);
    FIELD_SOUND_SYSTEM_SetState(fieldSound, FIELD_SOUND_STATE_MUTED);
    FIELD_SOUND_SYSTEM_FinishRequest(fieldSound);
}

/* Sets the state. */
void FIELD_SOUND_SYSTEM_SetState(FieldSoundSystem *fieldSound, u32 state)
{
    fieldSound->state = state;
}

/* Drops the pending request: mode, BGM number and both fade lengths. */
void FIELD_SOUND_SYSTEM_ClearRequest(FieldSoundSystem *fieldSound)
{
    fieldSound->mode = 0;
    fieldSound->requestedValue = 0;
    fieldSound->highParam = 0;
    fieldSound->lowParam = 0;
}

/* Drops the pending request if there is one (used by the mode handlers). */
void FIELD_SOUND_SYSTEM_DiscardRequest(FieldSoundSystem *fieldSound)
{
    if (fieldSound->mode != 0) {
        FIELD_SOUND_SYSTEM_ClearRequest(fieldSound);
    }
}

/* Same body as FIELD_SOUND_SYSTEM_DiscardRequest (used by the state update handlers): the request is done. */
void FIELD_SOUND_SYSTEM_FinishRequest(FieldSoundSystem *fieldSound)
{
    if (fieldSound->mode != 0) {
        FIELD_SOUND_SYSTEM_ClearRequest(fieldSound);
    }
}

/* Fades the current BGM in over the pending fade in frames and unmutes the player. */
void FIELD_SOUND_SYSTEM_FadeInCurrentBgm(FieldSoundSystem *fieldSound)
{
    if (fieldSound->currentValue == 0) {
        return;
    }
    GFL_USE_FadeInBgmFull(fieldSound->highParam);
    GFL_USE_SetBgmPaused(0);
}

/* Fades the current BGM out over the pending fade out frames. */
void FIELD_SOUND_SYSTEM_FadeOutCurrentBgm(FieldSoundSystem *fieldSound)
{
    if (fieldSound->currentValue != 0) {
        GFL_USE_FadeOutBgm(fieldSound->lowParam);
    }
}

/* Suspends the current BGM on the (one entry) stack. The first push also pauses the sound slots. */
void FIELD_SOUND_SYSTEM_PushCurrentBgm(FieldSoundSystem *fieldSound)
{
    if (fieldSound->currentValue == 0) {
        return;
    }
    if (fieldSound->stackDepth >= 1) {
        return;
    }
    if (fieldSound->stackDepth == 0) {
        FIELD_SOUND_SYSTEM_PauseSlots(fieldSound, 1);
    }
    GFL_USE_SetBgmPaused(1);
    GFL_USE_PushBgm();
    fieldSound->valueStack[fieldSound->stackDepth] = fieldSound->currentValue;
    fieldSound->stackDepth = fieldSound->stackDepth + 1;
    fieldSound->currentValue = 0;
}

/* Takes the suspended BGM back from the stack. Popping the last entry resumes the sound slots. */
void FIELD_SOUND_SYSTEM_PopBgm(FieldSoundSystem *fieldSound)
{
    u32 depth;

    if (fieldSound->stackDepth <= 0) {
        return;
    }
    GFL_USE_PopBgm();
    GFL_USE_SetBgmPaused(0);
    depth = fieldSound->stackDepth - 1;
    fieldSound->stackDepth = depth;
    fieldSound->currentValue = fieldSound->valueStack[depth];
    if (depth == 0) {
        FIELD_SOUND_SYSTEM_ResumeSlots(fieldSound, 1);
    }
}

/*
 * Stops the playing BGM and the loader (abort), and makes the requested BGM the
 * one that is loading. Returns 0 when nothing was requested.
 */
u32 FIELD_SOUND_SYSTEM_StartLoadingRequestedBgm(FieldSoundSystem *fieldSound)
{
    if (fieldSound->requestedValue == 0) {
        return 0;
    }
    GFL_USE_StepBgmLoad(fieldSound->requestedValue, &fieldSound->loadStep, 1);
    fieldSound->loadingValue = fieldSound->requestedValue;
    fieldSound->requestedValue = 0;
    fieldSound->currentValue = 0;
    GFL_NET_SetDeviceModeIfRunning(2);
    return 1;
}

/* Runs one step of the BGM loader; when the BGM is ready it becomes the current one. */
u32 FIELD_SOUND_SYSTEM_StepBgmLoading(FieldSoundSystem *fieldSound)
{
    u32 isLoaded = GFL_USE_StepBgmLoad(fieldSound->loadingValue, &fieldSound->loadStep, 0);

    GFL_NET_SetDeviceModeIfRunning(2);
    if (isLoaded != 0) {
        fieldSound->currentValue = fieldSound->loadingValue;
        fieldSound->loadingValue = 0;
    }
    return isLoaded;
}

/* Starts the requested BGM at once (default fade) and makes it the current one. */
void FIELD_SOUND_SYSTEM_PlayRequestedBgmNow(FieldSoundSystem *fieldSound)
{
    if (fieldSound->requestedValue != 0) {
        GFL_USE_CancelChangeAndPlayBgm(fieldSound->requestedValue, 0xffff);
        fieldSound->currentValue = fieldSound->requestedValue;
        fieldSound->requestedValue = 0;
        fieldSound->loadingValue = 0;
    }
}

/* Is a save running (BGM loading waits for it). */
u32 FIELD_SOUND_SYSTEM_IsSaving(FieldSoundSystem *fieldSound)
{
    return GAME_DATA_IsSaving(fieldSound->gameData);
}

/*
 * The functions from here to FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask are tasks (a body that runs once
 * per tick and a function that starts it) which post requests to the field
 * sound system and wait for it. The body is a state machine driven by the
 * sequence counter the task system hands it. Each starter allocates the 0x10
 * byte work block, stores the sound system and the parameters in it.
 *
 * A starter and its body stay in one file: the starter only reaches the body
 * through a pool word, so a separate file would not let the body be a local
 * symbol.
 */

/* Task body: post a fade in request, then finish. */
int FIELD_SOUND_SYSTEM_FadeInTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work)
{
    FieldSoundSystem *fieldSound = work->fieldSound;

    switch (*seq) {
    case 0:
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_FADE_IN, 0, 0, work->highParam);
        (*seq)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

struct GameEvent *FIELD_SOUND_SYSTEM_StartFadeInTask(struct GameSystem *gameSystem, u32 fadeInFrames)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_SOUND_SYSTEM_FadeInTask, 0x10);
    FieldSoundTaskWork *work = GAME_EVENT_GetWork(event);

    work->fieldSound = (FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);
    work->highParam = (u16)fadeInFrames;
    return event;
}

/* Task body: post a fade out request, then finish. */
int FIELD_SOUND_SYSTEM_FadeOutTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work)
{
    FieldSoundSystem *fieldSound = work->fieldSound;

    switch (*seq) {
    case 0:
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_FADE_OUT, 0, work->lowParam, 0);
        (*seq)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

struct GameEvent *FIELD_SOUND_SYSTEM_StartFadeOutTask(struct GameSystem *gameSystem, u32 fadeOutFrames)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_SOUND_SYSTEM_FadeOutTask, 0x10);
    FieldSoundTaskWork *work = GAME_EVENT_GetWork(event);

    work->fieldSound = (FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);
    work->lowParam = (u16)fadeOutFrames;
    return event;
}

/* Task body: post a push request, wait until the sound system has handled it, then finish. */
int FIELD_SOUND_SYSTEM_PushTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work)
{
    FieldSoundSystem *fieldSound = work->fieldSound;

    switch (*seq) {
    case 0:
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_PUSH, 0, work->lowParam, 0);
        (*seq)++;
        break;
    case 1:
        if (FIELD_SOUND_SYSTEM_IsBusy(fieldSound) == 0) {
            (*seq)++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}

struct GameEvent *FIELD_SOUND_SYSTEM_StartPushTask(struct GameSystem *gameSystem, u32 fadeOutFrames)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_SOUND_SYSTEM_PushTask, 0x10);
    FieldSoundTaskWork *work = GAME_EVENT_GetWork(event);

    work->fieldSound = (FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);
    work->lowParam = (u16)fadeOutFrames;
    return event;
}

/* Task body: post a pop request, wait until the sound system has handled it, then finish. */
int FIELD_SOUND_SYSTEM_PopAndWaitTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work)
{
    FieldSoundSystem *fieldSound = work->fieldSound;

    switch (*seq) {
    case 0:
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_POP, 0, work->lowParam, work->highParam);
        (*seq)++;
        break;
    case 1:
        if (FIELD_SOUND_SYSTEM_IsBusy(fieldSound) == 0) {
            (*seq)++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}

struct GameEvent *FIELD_SOUND_SYSTEM_StartPopAndWaitTask(struct GameSystem *gameSystem, u32 fadeOutFrames, u32 fadeInFrames)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_SOUND_SYSTEM_PopAndWaitTask, 0x10);
    FieldSoundTaskWork *work = GAME_EVENT_GetWork(event);

    work->fieldSound = (FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);
    work->highParam = fadeInFrames;
    work->lowParam = fadeOutFrames;
    return event;
}

/* Task body: post a pop request and finish on the next tick. */
int FIELD_SOUND_SYSTEM_PopTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work)
{
    FieldSoundSystem *fieldSound = work->fieldSound;

    switch (*seq) {
    case 0:
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_POP, 0, work->lowParam, work->highParam);
        (*seq)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

struct GameEvent *FIELD_SOUND_SYSTEM_StartPopTask(struct GameSystem *gameSystem, u32 fadeOutFrames, u32 fadeInFrames)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_SOUND_SYSTEM_PopTask, 0x10);
    FieldSoundTaskWork *work = GAME_EVENT_GetWork(event);

    work->fieldSound = (FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);
    work->highParam = fadeInFrames;
    work->lowParam = fadeOutFrames;
    return event;
}

/*
 * Task body: pop every suspended BGM. Asks the sound system how many are on the
 * stack (counting the queued requests) and posts one pop for each, the last one
 * with the fade in.
 */
int FIELD_SOUND_SYSTEM_PopAllTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work)
{
    FieldSoundSystem *fieldSound = work->fieldSound;
    s32 depth;
    s32 lastIndex;
    s32 i;

    switch (*seq) {
    case 0:
        depth = FIELD_SOUND_SYSTEM_GetPendingBgmStackDepth(fieldSound);
        if (depth > 0) {
            lastIndex = depth - 1;
            for (i = 0; i < lastIndex; i++) {
                FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_POP, 0, 0, 0);
            }
            FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_POP, 0, 0, work->highParam);
        }
        (*seq)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

struct GameEvent *FIELD_SOUND_SYSTEM_StartPopAllTask(struct GameSystem *gameSystem, u16 fadeInFrames)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_SOUND_SYSTEM_PopAllTask, 0x10);
    FieldSoundTaskWork *work = GAME_EVENT_GetWork(event);

    work->fieldSound = (FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);
    work->highParam = fadeInFrames;
    return event;
}

/* Task body: push the current BGM, then change to a new one (fade out, load, fade in), in the same tick. */
int FIELD_SOUND_SYSTEM_PushAndChangeTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work)
{
    FieldSoundSystem *fieldSound = work->fieldSound;

    switch (*seq) {
    case 0:
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_PUSH, 0, work->lowParam, 0);
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_CHANGE, work->value, 0, work->highParam);
        (*seq)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

struct GameEvent *FIELD_SOUND_SYSTEM_StartPushAndChangeTask(struct GameSystem *gameSystem, u32 bgmNo, u32 fadeOutFrames, u32 fadeInFrames)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_SOUND_SYSTEM_PushAndChangeTask, 0x10);
    FieldSoundTaskWork *work = GAME_EVENT_GetWork(event);

    work->fieldSound = (FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);
    work->value = bgmNo;
    work->highParam = fadeInFrames;
    work->lowParam = fadeOutFrames;
    return event;
}

/* Task body: push the current BGM (6 frame fade out), then play a new one at once, in the same tick. */
int FIELD_SOUND_SYSTEM_PushAndPlayTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work)
{
    FieldSoundSystem *fieldSound = work->fieldSound;

    switch (*seq) {
    case 0:
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_PUSH, 0, 6, 0);
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_PLAY_NOW, work->value, 0, 0);
        (*seq)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

struct GameEvent *FIELD_SOUND_SYSTEM_StartPushAndPlayTask(struct GameSystem *gameSystem, u32 bgmNo)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_SOUND_SYSTEM_PushAndPlayTask, 0x10);
    FieldSoundTaskWork *work = GAME_EVENT_GetWork(event);

    work->fieldSound = (FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);
    work->value = bgmNo;
    work->lowParam = 0;
    return event;
}

/* Task body: post one change request (fade out, load, fade in) with all three stored parameters. */
int FIELD_SOUND_SYSTEM_ChangeTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work)
{
    FieldSoundSystem *fieldSound = work->fieldSound;

    switch (*seq) {
    case 0:
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_CHANGE, work->value, work->lowParam, work->highParam);
        (*seq)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}

struct GameEvent *FIELD_SOUND_SYSTEM_StartChangeTask(struct GameSystem *gameSystem, u32 bgmNo, u32 fadeOutFrames, u32 fadeInFrames)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_SOUND_SYSTEM_ChangeTask, 0x10);
    FieldSoundTaskWork *work = GAME_EVENT_GetWork(event);

    work->fieldSound = (FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);
    work->value = bgmNo;
    work->highParam = fadeInFrames;
    work->lowParam = fadeOutFrames;
    return event;
}

/*
 * Task body: fade out, wait until the sound system is idle, reset it with the
 * game data (drains the queue and starts over), then finish. The game data is
 * looked up before the switch although only the third step uses it.
 */
int FIELD_SOUND_SYSTEM_FadeOutAndResetTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(work->gameSystem);
    FieldSoundSystem *fieldSound = work->fieldSound;

    switch (*seq) {
    case 0:
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_FADE_OUT, 0, work->lowParam, 0);
        (*seq)++;
        break;
    case 1:
        if (FIELD_SOUND_SYSTEM_IsBusy(fieldSound) == 0) {
            (*seq)++;
        }
        break;
    case 2:
        FIELD_SOUND_SYSTEM_Reset(fieldSound, gameData);
        (*seq)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}

/* Task body: fade out (6 frames), play a new BGM at once, finish when the sound system is idle. */
int FIELD_SOUND_SYSTEM_FadeOutAndPlayTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work)
{
    FieldSoundSystem *fieldSound = work->fieldSound;

    switch (*seq) {
    case 0:
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_FADE_OUT, 0, 6, 0);
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_PLAY_NOW, work->value, 0, 0);
        (*seq)++;
        break;
    case 1:
        if (FIELD_SOUND_SYSTEM_IsBusy(fieldSound) == 0) {
            return 1;
        }
        break;
    }
    return 0;
}

struct GameEvent *FIELD_SOUND_SYSTEM_StartFadeOutAndPlayTask(struct GameSystem *gameSystem, u32 bgmNo)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_SOUND_SYSTEM_FadeOutAndPlayTask, 0x10);
    FieldSoundTaskWork *work = GAME_EVENT_GetWork(event);

    work->fieldSound = (FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);
    work->value = bgmNo;
    return event;
}

/* Task body: like FIELD_SOUND_SYSTEM_FadeOutAndPlayTask with the fade out length taken from the work block. */
int FIELD_SOUND_SYSTEM_FadeOutAndPlayWithFadeTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work)
{
    FieldSoundSystem *fieldSound = work->fieldSound;

    switch (*seq) {
    case 0:
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_FADE_OUT, 0, work->lowParam, 0);
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_PLAY_NOW, work->value, 0, 0);
        (*seq)++;
        break;
    case 1:
        if (FIELD_SOUND_SYSTEM_IsBusy(fieldSound) == 0) {
            return 1;
        }
        break;
    }
    return 0;
}

struct GameEvent *FIELD_SOUND_SYSTEM_StartFadeOutAndPlayWithFadeTask(struct GameSystem *gameSystem, u32 bgmNo, u16 fadeOutFrames)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_SOUND_SYSTEM_FadeOutAndPlayWithFadeTask, 0x10);
    FieldSoundTaskWork *work = GAME_EVENT_GetWork(event);

    work->fieldSound = (FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);
    work->value = bgmNo;
    work->lowParam = fadeOutFrames;
    return event;
}

/*
 * Task body: fade out, then play BGM 1001 at once; one shot, finishes on the
 * first tick. 1001 does not fit a Thumb immediate, so it is a pool word.
 * It is a BGM number, so it may differ in the White version.
 */
int FIELD_SOUND_SYSTEM_FadeOutAndPlayFixedBgmTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work)
{
    FieldSoundSystem *fieldSound = work->fieldSound;

    if (*seq == 0) {
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_FADE_OUT, 0, work->lowParam, 0);
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_PLAY_NOW, 1001, 0, 0);
        return 1;
    }
    return 0;
}

struct GameEvent *FIELD_SOUND_SYSTEM_StartFadeOutAndPlayFixedBgmTask(struct GameSystem *gameSystem, u16 fadeOutFrames)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_SOUND_SYSTEM_FadeOutAndPlayFixedBgmTask, 0x10);
    FieldSoundTaskWork *work = GAME_EVENT_GetWork(event);

    work->fieldSound = (FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);
    work->lowParam = fadeOutFrames;
    return event;
}

/* Task body: push the current BGM (6 frame fade out), play a new one at once, finish when the sound system is idle. */
int FIELD_SOUND_SYSTEM_PushAndPlayWaitTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work)
{
    FieldSoundSystem *fieldSound = work->fieldSound;

    switch (*seq) {
    case 0:
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_PUSH, 0, 6, 0);
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_PLAY_NOW, work->value, 0, 0);
        (*seq)++;
        break;
    case 1:
        if (FIELD_SOUND_SYSTEM_IsBusy(fieldSound) == 0) {
            return 1;
        }
        break;
    }
    return 0;
}

struct GameEvent *FIELD_SOUND_SYSTEM_StartPushAndPlayWaitTask(struct GameSystem *gameSystem, u32 bgmNo)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_SOUND_SYSTEM_PushAndPlayWaitTask, 0x10);
    FieldSoundTaskWork *work = GAME_EVENT_GetWork(event);

    work->fieldSound = (FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);
    work->value = bgmNo;
    return event;
}

/* Starter for the body at FIELD_SOUND_SYSTEM_FadeOutAndResetTask; it sits too far away to share a file with it in the matched split. */
struct GameEvent *FIELD_SOUND_SYSTEM_StartFadeOutAndResetTask(struct GameSystem *gameSystem, u16 fadeOutFrames)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_SOUND_SYSTEM_FadeOutAndResetTask, 0x10);
    FieldSoundTaskWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->fieldSound = (FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);
    work->lowParam = fadeOutFrames;
    return event;
}

/*
 * Task body: suspend the current BGM and play a new one at once. When the stack
 * already holds a BGM (the stack has one entry), only fade out instead of
 * pushing. Then wait until the sound system is idle, post the play request, finish.
 */
int FIELD_SOUND_SYSTEM_PushOrFadeOutAndPlayTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work)
{
    FieldSoundSystem *fieldSound = work->fieldSound;

    switch (*seq) {
    case 0:
        if (FIELD_SOUND_SYSTEM_GetPendingBgmStackDepth(fieldSound) == 0) {
            FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_PUSH, 0, 6, 0);
        } else {
            FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_FADE_OUT, 0, 6, 0);
        }
        (*seq)++;
        break;
    case 1:
        if (FIELD_SOUND_SYSTEM_IsBusy(fieldSound) == 0) {
            (*seq)++;
        }
        break;
    case 2:
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_PLAY_NOW, work->value, 0, 0);
        (*seq)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}

struct GameEvent *FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(struct GameSystem *gameSystem, u32 bgmNo)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_SOUND_SYSTEM_PushOrFadeOutAndPlayTask, 0x10);
    FieldSoundTaskWork *work = GAME_EVENT_GetWork(event);

    work->fieldSound = (FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);
    work->value = bgmNo;
    return event;
}

/* Second starter for the pop task body at FIELD_SOUND_SYSTEM_PopTask, with fixed fades: 30 frames out, 60 frames in. */
struct GameEvent *FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(struct GameSystem *gameSystem)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_SOUND_SYSTEM_PopTask, 0x10);
    FieldSoundTaskWork *work = GAME_EVENT_GetWork(event);

    work->fieldSound = (FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);
    work->highParam = 0x3C;
    work->lowParam = 0x1E;
    return event;
}

/* Task body: wait until the sound system has left its transitional states. */
int FIELD_SOUND_SYSTEM_WaitSettledTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work)
{
    FieldSoundSystem *fieldSound = work->fieldSound;

    switch (*seq) {
    case 0:
        if (FIELD_SOUND_SYSTEM_IsStateActive(fieldSound) == 0) {
            (*seq)++;
        }
        break;
    case 1:
        return 1;
    }
    return 0;
}

struct GameEvent *FIELD_SOUND_SYSTEM_StartWaitSettledTask(struct GameSystem *gameSystem)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_SOUND_SYSTEM_WaitSettledTask, 0x10);
    FieldSoundTaskWork *work = GAME_EVENT_GetWork(event);

    work->fieldSound = (FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);
    return event;
}

/* Task body: wait until the sound system takes another request. */
int FIELD_SOUND_SYSTEM_WaitAcceptRequestTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work)
{
    FieldSoundSystem *fieldSound = work->fieldSound;

    switch (*seq) {
    case 0:
        if (FIELD_SOUND_SYSTEM_CanAcceptRequest(fieldSound) == 1) {
            (*seq)++;
        }
        break;
    case 1:
        return 1;
    }
    return 0;
}

struct GameEvent *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(struct GameSystem *gameSystem)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, FIELD_SOUND_SYSTEM_WaitAcceptRequestTask, 0x10);
    FieldSoundTaskWork *work = GAME_EVENT_GetWork(event);

    work->fieldSound = (FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);
    return event;
}

/*
 * Posts a BGM change (fade out 60 frames) for a zone. The BGM comes from the
 * zone override table, else from the zone record for the season. The fade in is
 * 60 frames when the player object code is 1, else none.
 *
 * Both arms of the player test leave "movs r3, #0x3c" duplicated and cross-jump
 * everything after it: fadeOut and fadeIn are locals assigned in each arm
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md).
 */
void FIELD_SOUND_SYSTEM_PostZoneBgmChange(FieldSoundSystem *fieldSound, struct GameData *gameData, u32 zoneId)
{
    u32 season = GAME_DATA_GetSeason(gameData);
    u32 bgmNo = FIELD_SOUND_SYSTEM_FindZoneBgmOverride(gameData, zoneId);
    u16 fadeOut;
    u16 fadeIn;

    if (bgmNo == 0xFFFFFFFF) {
        bgmNo = FIELD_SOUND_SYSTEM_GetZoneBgm(gameData, zoneId, season);
    }
    if (FIELD_SOUND_SYSTEM_GetPlayerObjectCode(gameData) == 1) {
        fadeOut = 0x3C;
        fadeIn = 0x3C;
    } else {
        fadeOut = 0x3C;
        fadeIn = 0;
    }
    FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_CHANGE, bgmNo, fadeOut, fadeIn);
}

/* Posts a BGM replace request (fade out 60 frames) for a zone and season. */
void FIELD_SOUND_SYSTEM_PostZoneBgmReplace(FieldSoundSystem *fieldSound, struct GameData *gameData, u16 zoneId, u8 season)
{
    u32 bgmNo = FIELD_SOUND_SYSTEM_FindZoneBgmOverride(gameData, zoneId);

    if (bgmNo == ~0u) {
        bgmNo = FIELD_SOUND_SYSTEM_GetZoneBgm(gameData, zoneId, season);
    }
    FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_REPLACE, bgmNo, 0x3C, 0);
}

/* Posts a fade in request with no fade. */
void FIELD_SOUND_SYSTEM_PostFadeIn(FieldSoundSystem *fieldSound)
{
    FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_FADE_IN, 0, 0, 0);
}

/* Posts a BGM change (fade out 30 frames) for a zone, with the full lookup including the player form. */
void FIELD_SOUND_SYSTEM_PostZoneBgmChangeShortFade(FieldSoundSystem *fieldSound, struct GameData *gameData, u32 zoneId)
{
    u32 season = GAME_DATA_GetSeason(gameData);
    u32 bgmNo = FIELD_SOUND_SYSTEM_GetFieldBgmForZone(gameData, zoneId, season);

    FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_CHANGE, bgmNo, 0x1e, 0);
}

/* Lowers the volume: the 3D sound system goes silent, the fader goes to 0x40 over 6 frames. */
void FIELD_SOUND_SYSTEM_LowerVolume(FieldSoundSystem *fieldSound, struct IssSys *iss)
{
    struct Iss3dsSys *iss3ds = ISS_SYS_Get3dsSys(iss);

    ISS_3DS_SYS_SetVolume(iss3ds, 0);
    FIELD_SOUND_SYSTEM_FadeVolume(fieldSound, 0x40, 6);
}

/* Restores the volume: the 3D sound system and the fader go to 0x7f (6 frame fade). */
void FIELD_SOUND_SYSTEM_RestoreVolume(FieldSoundSystem *fieldSound, struct IssSys *iss)
{
    struct Iss3dsSys *iss3ds = ISS_SYS_Get3dsSys(iss);

    ISS_3DS_SYS_SetVolume(iss3ds, 0x7f);
    FIELD_SOUND_SYSTEM_FadeVolume(fieldSound, 0x7f, 6);
}

/* Plain forwarder to FIELD_SOUND_SYSTEM_GetFieldBgmForZone (a pool word and a bx), seeded from the bl sites in ov020 and ov021. */
unsigned int FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx(struct GameData *gameData, unsigned int zoneId, unsigned int season)
{
    return FIELD_SOUND_SYSTEM_GetFieldBgmForZone(gameData, zoneId, season);
}

/* The BGM the sound system of the game data will end up with once its queue is done. */
void *FIELD_SOUND_SYSTEM_GetFinalBgm(const struct GameData *gameData)
{
    return FIELD_SOUND_SYSTEM_GetFinalValue((FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData));
}

/* Does the zone have an override BGM. */
int FIELD_SOUND_SYSTEM_HasZoneBgmOverride(struct GameData *gameData, u32 zoneId)
{
    if (FIELD_SOUND_SYSTEM_FindZoneBgmOverride(gameData, zoneId) != 0xffffffff) {
        return 1;
    }
    return 0;
}

/* Looks up the BGM of a trainer class (0x45A when the class has none). The table ends with key 0x69. */
u16 FIELD_SOUND_SYSTEM_GetTrainerClassBgm(u32 trainerClass)
{
    int i;

    for (i = 0; sTrainerClassBgmTable[i].trainerClass != 0x69; i++) {
        if (trainerClass == sTrainerClassBgmTable[i].trainerClass)
            return sTrainerClassBgmTable[i].bgmNo;
    }
    return 0x45A;
}

/* Object code of the player (1 and 2 are the forms that change the field BGM). */
int FIELD_SOUND_SYSTEM_GetPlayerObjectCode(struct GameData *gameData)
{
    return GAME_DATA_GetPlayerObjectCode(GAME_DATA_GetMyPlayerWork(gameData));
}

/* The BGM of a zone for a season, from the zone record. */
u32 FIELD_SOUND_SYSTEM_GetZoneBgm(struct GameData *gameData, u32 zoneId, u32 season)
{
    return ZONEDATA_GetBgmId((u16)zoneId, season);
}

/*
 * Looks up an override BGM for a zone in the table of 8 entries (event flag,
 * zone, BGM number): the entry applies when its zone matches and its event flag
 * is set. Returns 0xFFFFFFFF when there is none.
 *
 */
u32 FIELD_SOUND_SYSTEM_FindZoneBgmOverride(struct GameData *gameData, u32 zoneId)
{
    void *eventFlags = GAME_DATA_GetEventWork(gameData);
    u32 i;

    for (i = 0; i < 8; i++) {
        if (zoneId == sZoneBgmOverrides[i].zoneId) {
            if (ZONEDATA_CheckEventFlag(eventFlags, sZoneBgmOverrides[i].eventFlag) == 1) {
                return sZoneBgmOverrides[i].bgmNo;
            }
        }
    }
    return 0xffffffff;
}

/*
 * The BGM of a zone for a season: the zone override first, then the
 * special BGMs for the player forms 1 and 2 (0x3F4, 0x3F5) when the zone allows
 * them, else the zone record.
 */
u32 FIELD_SOUND_SYSTEM_GetFieldBgmForZone(struct GameData *gameData, u32 zoneId, u32 season)
{
    int playerObjectCode;
    u32 bgmNo;

    playerObjectCode = FIELD_SOUND_SYSTEM_GetPlayerObjectCode(gameData);
    GAME_DATA_GetBgmInfo(gameData);
    bgmNo = FIELD_SOUND_SYSTEM_FindZoneBgmOverride(gameData, zoneId);
    if (bgmNo == (u32)-1) {
        if (playerObjectCode == 2) {
            if (ZONEDATA_IsRideBgmEnabled((u16)zoneId)) {
                return 0x3f5;
            }
        }
        if (playerObjectCode == 1) {
            if (ZONEDATA_IsRideBgmEnabled((u16)zoneId)) {
                return 0x3f4;
            }
        }
        return FIELD_SOUND_SYSTEM_GetZoneBgm(gameData, zoneId, season);
    }
    return bgmNo;
}
