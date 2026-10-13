/*
 * file:     ringtone_sys.c
 * unit:     yes
 * function: FIELD_SOUND_SYSTEM_UpdateFadingOutToMute, FIELD_SOUND_SYSTEM_UpdateFadingIn, FIELD_SOUND_SYSTEM_UpdateFadingOutToPush, FIELD_SOUND_SYSTEM_UpdateFadingOutToPop, FIELD_SOUND_SYSTEM_UpdateFadingInAfterPop, FIELD_SOUND_SYSTEM_UpdateFadingOutToLoad, FIELD_SOUND_SYSTEM_UpdateLoading, FIELD_SOUND_SYSTEM_UpdateFadingInLoaded, FIELD_SOUND_SYSTEM_UpdateFadingOutToLoadAndPush, FIELD_SOUND_SYSTEM_UpdateLoadingAndPush, FIELD_SOUND_SYSTEM_UpdateFadingOutToReplace, FIELD_SOUND_SYSTEM_UpdateReplacing, FIELD_SOUND_SYSTEM_SetState, FIELD_SOUND_SYSTEM_ClearRequest, FIELD_SOUND_SYSTEM_DiscardRequest, FIELD_SOUND_SYSTEM_FinishRequest, FIELD_SOUND_SYSTEM_FadeInCurrentBgm, FIELD_SOUND_SYSTEM_FadeOutCurrentBgm, FIELD_SOUND_SYSTEM_PushCurrentBgm, FIELD_SOUND_SYSTEM_PopBgm, FIELD_SOUND_SYSTEM_StartLoadingRequestedBgm, FIELD_SOUND_SYSTEM_StepBgmLoading, FIELD_SOUND_SYSTEM_PlayRequestedBgmNow, FIELD_SOUND_SYSTEM_IsSaving, FIELD_SOUND_SYSTEM_FadeInTask, func_020294C0, FIELD_SOUND_SYSTEM_FadeOutTask, func_0202952C, FIELD_SOUND_SYSTEM_PushTask, func_020295A4, FIELD_SOUND_SYSTEM_PopAndWaitTask, func_02029620, FIELD_SOUND_SYSTEM_PopTask, FIELD_SOUND_SYSTEM_StartPopTask, FIELD_SOUND_SYSTEM_PopAllTask, FIELD_SOUND_SYSTEM_StartPopAllTask, FIELD_SOUND_SYSTEM_PushAndChangeTask, FIELD_SOUND_SYSTEM_StartPushAndChangeTask, FIELD_SOUND_SYSTEM_PushAndPlayTask, func_02029830, FIELD_SOUND_SYSTEM_ChangeTask, func_020298A0, FIELD_SOUND_SYSTEM_FadeOutAndResetTask, FIELD_SOUND_SYSTEM_FadeOutAndPlayTask, func_02029984, FIELD_SOUND_SYSTEM_FadeOutAndPlayWithFadeTask, func_02029A04, FIELD_SOUND_SYSTEM_FadeOutAndPlayFixedBgmTask, func_02029A74, FIELD_SOUND_SYSTEM_PushAndPlayWaitTask, func_02029AF4, FIELD_SOUND_SYSTEM_StartFadeOutAndResetTask, FIELD_SOUND_SYSTEM_PushOrFadeOutAndPlayTask, FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask, FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask, FIELD_SOUND_SYSTEM_WaitSettledTask, func_02029C64, FIELD_SOUND_SYSTEM_WaitAcceptRequestTask, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask, func_02029CF0, func_02029D44, func_02029D7C, func_02029D8C, FIELD_SOUND_SYSTEM_LowerVolume, FIELD_SOUND_SYSTEM_RestoreVolume, func_02029DF4, func_02029DFC, func_02029E08, func_02029E20, FIELD_SOUND_SYSTEM_GetPlayerObjectCode, FIELD_SOUND_SYSTEM_GetZoneBgm, FIELD_SOUND_SYSTEM_FindZoneBgmOverride, func_02029EB4, RINGTONE_SYS_Create, RINGTONE_SYS_Delete, RINGTONE_SYS_Update, RINGTONE_SYS_Start, RINGTONE_SYS_Stop, RINGTONE_SYS_RegisterSleepCallbacks, RINGTONE_SYS_TickRing, RINGTONE_SYS_OnSleep, RINGTONE_SYS_OnWake, RINGTONE_SYS_StartRing, RINGTONE_SYS_StopRing, RINGTONE_SYS_SetBgmMuted, RINGTONE_SYS_PostEvent, RINGTONE_SYS_HandleRingTimeout
 * address:  0x0202918C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02012E40  0x02012E40  thumb
 *   FIELD_SOUND_SYSTEM_PostRequest  0x020289F8  thumb
 *   func_020289B8  0x020289B8  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012A30  0x02012A30  thumb
 *   func_02012984  0x02012984  thumb
 *   sTrainerClassBgmTable  0x020A75A8  data
 *   ZONEDATA_GetBgmId  0x02013BDC  thumb
 *   sZoneBgmOverrides  0x0209FE94  data
 *   ZONEDATA_IsRingtoneEnabled  0x02013C30  thumb
 *   func_02030734  0x02030734  arm
 *   sRingtoneSysFileName     0x020A76BC  data
 *   gRingtone     0x02146944  data
 *   func_020307B0  0x020307B0  arm
 *   func_0203508C  0x0203508C  arm
 *   func_02006224  0x02006224  thumb
 *   func_020061F8  0x020061F8  thumb
 *   func_0200616C  0x0200616C  thumb
 *   sRingtoneTransitions   0x0209FED4  data  a1
 *   func_02072788  0x02072788  arm
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_SetBgmPlayerParam  0x02005DE4  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb
 *   GFL_USE_IsBgmFading  0x02005E50  thumb
 *   GFL_USE_PushBgm  0x02005E64  thumb
 *   GFL_USE_PopBgm  0x02005E9C  thumb
 *   GFL_USE_StepBgmLoad  0x020063B4  thumb
 *   PLAYER_VOLUME_FADER_SetMute  0x020287A8  thumb
 *   FIELD_SOUND_SYSTEM_GetQueueDepth  0x020288C4  thumb
 *   FIELD_SOUND_SYSTEM_GetFinalValue  0x02028900  thumb
 *   FIELD_SOUND_SYSTEM_IsStateActive  0x02028988  thumb
 *   FIELD_SOUND_SYSTEM_CanAcceptRequest  0x020289D4  thumb
 *   FIELD_SOUND_SYSTEM_Reset  0x02028A50  thumb
 *   ISS_3DS_SYS_SetVolume  0x0202B914  thumb
 *   NNS_SndPlayerSetPlayerVolume  0x02072D98  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Fader;
struct GameData;
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

/* One queued request: a ring slot of 12 bytes. */
typedef struct FieldSoundRequest {
    u32 kind;
    u32 value;
    u16 lowParam;
    u16 highParam;
} FieldSoundRequest;

/* The ringtone state machine object (12 bytes), created by the field sound system. */
typedef struct Ringtone {
    u32 state;                      /* 0x00 RingtoneState: bit 0 = ringing, bit 1 = asleep */
    u16 ringFramesLeft;             /* 0x04 */
    u16 reserved;                   /* 0x06 */
    struct Fader *volumeFader;      /* 0x08 */
} Ringtone;

/*
 * The field sound system object (0xB8 bytes). The functions of this file up to
 * func_02029EB4 drive it (they belong to field_sound_system.c, see misplaced.tsv).
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

/* Ringtone states: the sum of the two flags. */
enum RingtoneState {
    RINGTONE_STATE_IDLE = 0,
    RINGTONE_STATE_RINGING = 1,
    RINGTONE_STATE_ASLEEP = 2,
    RINGTONE_STATE_RINGING_ASLEEP = 3
};

enum RingtoneEvent {
    RINGTONE_EVENT_STOP = 0,
    RINGTONE_EVENT_START = 1,
    RINGTONE_EVENT_WAKE = 2,
    RINGTONE_EVENT_SLEEP = 3
};

extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void GFL_USE_FadeInBgmFull(u32 frames);
extern void GFL_USE_SetBgmPlayerParam(u32 value);
extern void GFL_USE_FadeOutBgm(u32 frames);
extern void func_02028BA0(FieldSoundSystem *fieldSound, u32 bits);
extern int GFL_USE_PushBgm(void);
extern int GFL_USE_PopBgm(void);
extern void func_02028BDC(FieldSoundSystem *fieldSound, u32 bits);
extern u32 GFL_USE_StepBgmLoad(u32 bgmNo, u32 *step, u32 abort);
extern void func_0203D12C(int a);
extern void GFL_USE_CancelChangeAndPlayBgm(u32 bgmNo, u32 frames);
extern u8 func_02012E40(const struct GameData *gameData);
extern void FIELD_SOUND_SYSTEM_PostRequest(FieldSoundSystem *fieldSound, u32 kind, u32 value, u16 lowParam, u16 highParam);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, FieldSoundTaskFunc func, u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
extern u32 func_02012A30(const struct GameData *gameData);
extern u32 func_020289B8(FieldSoundSystem *fieldSound);
extern s32 FIELD_SOUND_SYSTEM_GetQueueDepth(FieldSoundSystem *fieldSound);
extern void FIELD_SOUND_SYSTEM_Reset(FieldSoundSystem *fieldSound, struct GameData *gameData);
extern u32 FIELD_SOUND_SYSTEM_IsStateActive(FieldSoundSystem *fieldSound);
extern u32 FIELD_SOUND_SYSTEM_CanAcceptRequest(FieldSoundSystem *fieldSound);
extern u8 func_02012984(const struct GameData *gameData);
extern struct Iss3dsSys *func_0202B57C(struct IssSys *iss);
extern void ISS_3DS_SYS_SetVolume(struct Iss3dsSys *iss3ds, u32 volume);
extern void func_02028A58(FieldSoundSystem *fieldSound, u8 level, u16 frames);
extern void *FIELD_SOUND_SYSTEM_GetFinalValue(FieldSoundSystem *fieldSound);
extern u32 ZONEDATA_GetBgmId(u32 zoneId, u32 season);
extern void *func_0201296C(const struct GameData *gameData);
extern u32 func_020142E8(void *eventFlags, s32 flagId);
extern u32 ZONEDATA_IsRingtoneEnabled(u32 zoneId);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void func_0203508C(void (*onSleep)(void), void (*onWake)(void), Ringtone *arg);
extern int func_02006224(u32 slot);
extern void func_020061F8(int slot);
extern void func_0200616C(u32 seqNo, int slot);
extern struct PlayerWork *func_020127A4(struct GameData *gameData);
extern int func_02012B28(const struct PlayerWork *player);
extern void func_02072788(int volume);
extern void NNS_SndPlayerSetPlayerVolume(int playerNo, int volume);
extern void PLAYER_VOLUME_FADER_SetMute(struct Fader *fader, int mute);

extern const TrainerClassBgm sTrainerClassBgmTable[];
extern const ZoneBgmOverride sZoneBgmOverrides[8];
extern const char sRingtoneSysFileName[];
extern Ringtone *gRingtone;
extern const u8 sRingtoneTransitions[][4];

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
void FIELD_SOUND_SYSTEM_SetState(FieldSoundSystem *fieldSound, u32 state);
void FIELD_SOUND_SYSTEM_ClearRequest(FieldSoundSystem *fieldSound);
void FIELD_SOUND_SYSTEM_DiscardRequest(FieldSoundSystem *fieldSound);
void FIELD_SOUND_SYSTEM_FinishRequest(FieldSoundSystem *fieldSound);
void FIELD_SOUND_SYSTEM_FadeInCurrentBgm(FieldSoundSystem *fieldSound);
void FIELD_SOUND_SYSTEM_FadeOutCurrentBgm(FieldSoundSystem *fieldSound);
void FIELD_SOUND_SYSTEM_PushCurrentBgm(FieldSoundSystem *fieldSound);
void FIELD_SOUND_SYSTEM_PopBgm(FieldSoundSystem *fieldSound);
u32 FIELD_SOUND_SYSTEM_StartLoadingRequestedBgm(FieldSoundSystem *fieldSound);
u32 FIELD_SOUND_SYSTEM_StepBgmLoading(FieldSoundSystem *fieldSound);
void FIELD_SOUND_SYSTEM_PlayRequestedBgmNow(FieldSoundSystem *fieldSound);
u32 FIELD_SOUND_SYSTEM_IsSaving(FieldSoundSystem *fieldSound);
int FIELD_SOUND_SYSTEM_FadeInTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);
struct GameEvent *func_020294C0(struct GameSystem *gameSystem, u32 fadeInFrames);
int FIELD_SOUND_SYSTEM_FadeOutTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);
struct GameEvent *func_0202952C(struct GameSystem *gameSystem, u32 fadeOutFrames);
int FIELD_SOUND_SYSTEM_PushTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);
struct GameEvent *func_020295A4(struct GameSystem *gameSystem, u32 fadeOutFrames);
int FIELD_SOUND_SYSTEM_PopAndWaitTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);
struct GameEvent *func_02029620(struct GameSystem *gameSystem, u32 fadeOutFrames, u32 fadeInFrames);
int FIELD_SOUND_SYSTEM_PopTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);
struct GameEvent *FIELD_SOUND_SYSTEM_StartPopTask(struct GameSystem *gameSystem, u32 fadeOutFrames, u32 fadeInFrames);
int FIELD_SOUND_SYSTEM_PopAllTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);
struct GameEvent *FIELD_SOUND_SYSTEM_StartPopAllTask(struct GameSystem *gameSystem, u16 fadeInFrames);
int FIELD_SOUND_SYSTEM_PushAndChangeTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);
struct GameEvent *FIELD_SOUND_SYSTEM_StartPushAndChangeTask(struct GameSystem *gameSystem, u32 bgmNo, u32 fadeOutFrames, u32 fadeInFrames);
int FIELD_SOUND_SYSTEM_PushAndPlayTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);
struct GameEvent *func_02029830(struct GameSystem *gameSystem, u32 bgmNo);
int FIELD_SOUND_SYSTEM_ChangeTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);
struct GameEvent *func_020298A0(struct GameSystem *gameSystem, u32 bgmNo, u32 fadeOutFrames, u32 fadeInFrames);
int FIELD_SOUND_SYSTEM_FadeOutAndResetTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);
int FIELD_SOUND_SYSTEM_FadeOutAndPlayTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);
struct GameEvent *func_02029984(struct GameSystem *gameSystem, u32 bgmNo);
int FIELD_SOUND_SYSTEM_FadeOutAndPlayWithFadeTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);
struct GameEvent *func_02029A04(struct GameSystem *gameSystem, u32 bgmNo, u16 fadeOutFrames);
int FIELD_SOUND_SYSTEM_FadeOutAndPlayFixedBgmTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);
struct GameEvent *func_02029A74(struct GameSystem *gameSystem, u16 fadeOutFrames);
int FIELD_SOUND_SYSTEM_PushAndPlayWaitTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);
struct GameEvent *func_02029AF4(struct GameSystem *gameSystem, u32 bgmNo);
struct GameEvent *FIELD_SOUND_SYSTEM_StartFadeOutAndResetTask(struct GameSystem *gameSystem, u16 fadeOutFrames);
int FIELD_SOUND_SYSTEM_PushOrFadeOutAndPlayTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);
struct GameEvent *FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(struct GameSystem *gameSystem, u32 bgmNo);
struct GameEvent *FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(struct GameSystem *gameSystem);
int FIELD_SOUND_SYSTEM_WaitSettledTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);
struct GameEvent *func_02029C64(struct GameSystem *gameSystem);
int FIELD_SOUND_SYSTEM_WaitAcceptRequestTask(struct GameEvent *event, u32 *seq, FieldSoundTaskWork *work);
struct GameEvent *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(struct GameSystem *gameSystem);
void func_02029CF0(FieldSoundSystem *fieldSound, struct GameData *gameData, u32 zoneId);
void func_02029D44(FieldSoundSystem *fieldSound, struct GameData *gameData, u16 zoneId, u8 season);
void func_02029D7C(FieldSoundSystem *fieldSound);
void func_02029D8C(FieldSoundSystem *fieldSound, struct GameData *gameData, u32 zoneId);
void FIELD_SOUND_SYSTEM_LowerVolume(FieldSoundSystem *fieldSound, struct IssSys *iss);
void FIELD_SOUND_SYSTEM_RestoreVolume(FieldSoundSystem *fieldSound, struct IssSys *iss);
unsigned int func_02029DF4(struct GameData *gameData, unsigned int zoneId, unsigned int season);
void *func_02029DFC(const struct GameData *gameData);
int func_02029E08(struct GameData *gameData, u32 zoneId);
u16 func_02029E20(u32 trainerClass);
int FIELD_SOUND_SYSTEM_GetPlayerObjectCode(struct GameData *gameData);
u32 FIELD_SOUND_SYSTEM_GetZoneBgm(struct GameData *gameData, u32 zoneId, u32 season);
u32 FIELD_SOUND_SYSTEM_FindZoneBgmOverride(struct GameData *gameData, u32 zoneId);
u32 func_02029EB4(struct GameData *gameData, u32 zoneId, u32 season);
Ringtone *RINGTONE_SYS_Create(u32 heapId, struct Fader *volumeFader);
void RINGTONE_SYS_Delete(Ringtone *ringtone);
void RINGTONE_SYS_Update(Ringtone *ringtone);
void RINGTONE_SYS_Start(Ringtone *ringtone);
void RINGTONE_SYS_Stop(Ringtone *ringtone);
void RINGTONE_SYS_RegisterSleepCallbacks(void);
int RINGTONE_SYS_TickRing(Ringtone *ringtone);
void RINGTONE_SYS_OnSleep(void);
void RINGTONE_SYS_OnWake(void);
void RINGTONE_SYS_StartRing(Ringtone *ringtone);
void RINGTONE_SYS_StopRing(Ringtone *ringtone);
void RINGTONE_SYS_SetBgmMuted(Ringtone *ringtone, u32 muted);
void RINGTONE_SYS_PostEvent(Ringtone *ringtone, int event);
void RINGTONE_SYS_HandleRingTimeout(Ringtone *ringtone);

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
    GFL_USE_SetBgmPlayerParam(1);
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
    GFL_USE_SetBgmPlayerParam(0);
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
        func_02028BA0(fieldSound, 1);
    }
    GFL_USE_SetBgmPlayerParam(1);
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
    GFL_USE_SetBgmPlayerParam(0);
    depth = fieldSound->stackDepth - 1;
    fieldSound->stackDepth = depth;
    fieldSound->currentValue = fieldSound->valueStack[depth];
    if (depth == 0) {
        func_02028BDC(fieldSound, 1);
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
    func_0203D12C(2);
    return 1;
}

/* Runs one step of the BGM loader; when the BGM is ready it becomes the current one. */
u32 FIELD_SOUND_SYSTEM_StepBgmLoading(FieldSoundSystem *fieldSound)
{
    u32 isLoaded = GFL_USE_StepBgmLoad(fieldSound->loadingValue, &fieldSound->loadStep, 0);

    func_0203D12C(2);
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
    return func_02012E40(fieldSound->gameData);
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

struct GameEvent *func_020294C0(struct GameSystem *gameSystem, u32 fadeInFrames)
{
    struct GameData *gameData = func_020120F4(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, FIELD_SOUND_SYSTEM_FadeInTask, 0x10);
    FieldSoundTaskWork *work = func_020124E8(event);

    work->fieldSound = (FieldSoundSystem *)func_02012A30(gameData);
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

struct GameEvent *func_0202952C(struct GameSystem *gameSystem, u32 fadeOutFrames)
{
    struct GameData *gameData = func_020120F4(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, FIELD_SOUND_SYSTEM_FadeOutTask, 0x10);
    FieldSoundTaskWork *work = func_020124E8(event);

    work->fieldSound = (FieldSoundSystem *)func_02012A30(gameData);
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
        if (func_020289B8(fieldSound) == 0) {
            (*seq)++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}

struct GameEvent *func_020295A4(struct GameSystem *gameSystem, u32 fadeOutFrames)
{
    struct GameData *gameData = func_020120F4(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, FIELD_SOUND_SYSTEM_PushTask, 0x10);
    FieldSoundTaskWork *work = func_020124E8(event);

    work->fieldSound = (FieldSoundSystem *)func_02012A30(gameData);
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
        if (func_020289B8(fieldSound) == 0) {
            (*seq)++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}

struct GameEvent *func_02029620(struct GameSystem *gameSystem, u32 fadeOutFrames, u32 fadeInFrames)
{
    struct GameData *gameData = func_020120F4(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, FIELD_SOUND_SYSTEM_PopAndWaitTask, 0x10);
    FieldSoundTaskWork *work = func_020124E8(event);

    work->fieldSound = (FieldSoundSystem *)func_02012A30(gameData);
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
    struct GameData *gameData = func_020120F4(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, FIELD_SOUND_SYSTEM_PopTask, 0x10);
    FieldSoundTaskWork *work = func_020124E8(event);

    work->fieldSound = (FieldSoundSystem *)func_02012A30(gameData);
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
        depth = FIELD_SOUND_SYSTEM_GetQueueDepth(fieldSound);
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
    struct GameData *gameData = func_020120F4(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, FIELD_SOUND_SYSTEM_PopAllTask, 0x10);
    FieldSoundTaskWork *work = func_020124E8(event);

    work->fieldSound = (FieldSoundSystem *)func_02012A30(gameData);
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
    struct GameData *gameData = func_020120F4(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, FIELD_SOUND_SYSTEM_PushAndChangeTask, 0x10);
    FieldSoundTaskWork *work = func_020124E8(event);

    work->fieldSound = (FieldSoundSystem *)func_02012A30(gameData);
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

struct GameEvent *func_02029830(struct GameSystem *gameSystem, u32 bgmNo)
{
    struct GameData *gameData = func_020120F4(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, FIELD_SOUND_SYSTEM_PushAndPlayTask, 0x10);
    FieldSoundTaskWork *work = func_020124E8(event);

    work->fieldSound = (FieldSoundSystem *)func_02012A30(gameData);
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

struct GameEvent *func_020298A0(struct GameSystem *gameSystem, u32 bgmNo, u32 fadeOutFrames, u32 fadeInFrames)
{
    struct GameData *gameData = func_020120F4(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, FIELD_SOUND_SYSTEM_ChangeTask, 0x10);
    FieldSoundTaskWork *work = func_020124E8(event);

    work->fieldSound = (FieldSoundSystem *)func_02012A30(gameData);
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
    struct GameData *gameData = func_020120F4(work->gameSystem);
    FieldSoundSystem *fieldSound = work->fieldSound;

    switch (*seq) {
    case 0:
        FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_FADE_OUT, 0, work->lowParam, 0);
        (*seq)++;
        break;
    case 1:
        if (func_020289B8(fieldSound) == 0) {
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
        if (func_020289B8(fieldSound) == 0) {
            return 1;
        }
        break;
    }
    return 0;
}

struct GameEvent *func_02029984(struct GameSystem *gameSystem, u32 bgmNo)
{
    struct GameData *gameData = func_020120F4(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, FIELD_SOUND_SYSTEM_FadeOutAndPlayTask, 0x10);
    FieldSoundTaskWork *work = func_020124E8(event);

    work->fieldSound = (FieldSoundSystem *)func_02012A30(gameData);
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
        if (func_020289B8(fieldSound) == 0) {
            return 1;
        }
        break;
    }
    return 0;
}

struct GameEvent *func_02029A04(struct GameSystem *gameSystem, u32 bgmNo, u16 fadeOutFrames)
{
    struct GameData *gameData = func_020120F4(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, FIELD_SOUND_SYSTEM_FadeOutAndPlayWithFadeTask, 0x10);
    FieldSoundTaskWork *work = func_020124E8(event);

    work->fieldSound = (FieldSoundSystem *)func_02012A30(gameData);
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

struct GameEvent *func_02029A74(struct GameSystem *gameSystem, u16 fadeOutFrames)
{
    struct GameData *gameData = func_020120F4(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, FIELD_SOUND_SYSTEM_FadeOutAndPlayFixedBgmTask, 0x10);
    FieldSoundTaskWork *work = func_020124E8(event);

    work->fieldSound = (FieldSoundSystem *)func_02012A30(gameData);
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
        if (func_020289B8(fieldSound) == 0) {
            return 1;
        }
        break;
    }
    return 0;
}

struct GameEvent *func_02029AF4(struct GameSystem *gameSystem, u32 bgmNo)
{
    struct GameData *gameData = func_020120F4(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, FIELD_SOUND_SYSTEM_PushAndPlayWaitTask, 0x10);
    FieldSoundTaskWork *work = func_020124E8(event);

    work->fieldSound = (FieldSoundSystem *)func_02012A30(gameData);
    work->value = bgmNo;
    return event;
}

/* Starter for the body at FIELD_SOUND_SYSTEM_FadeOutAndResetTask; it sits too far away to share a file with it in the matched split. */
struct GameEvent *FIELD_SOUND_SYSTEM_StartFadeOutAndResetTask(struct GameSystem *gameSystem, u16 fadeOutFrames)
{
    struct GameData *gameData = func_020120F4(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, FIELD_SOUND_SYSTEM_FadeOutAndResetTask, 0x10);
    FieldSoundTaskWork *work = func_020124E8(event);

    work->gameSystem = gameSystem;
    work->fieldSound = (FieldSoundSystem *)func_02012A30(gameData);
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
        if (FIELD_SOUND_SYSTEM_GetQueueDepth(fieldSound) == 0) {
            FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_PUSH, 0, 6, 0);
        } else {
            FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_FADE_OUT, 0, 6, 0);
        }
        (*seq)++;
        break;
    case 1:
        if (func_020289B8(fieldSound) == 0) {
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
    struct GameData *gameData = func_020120F4(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, FIELD_SOUND_SYSTEM_PushOrFadeOutAndPlayTask, 0x10);
    FieldSoundTaskWork *work = func_020124E8(event);

    work->fieldSound = (FieldSoundSystem *)func_02012A30(gameData);
    work->value = bgmNo;
    return event;
}

/* Second starter for the pop task body at FIELD_SOUND_SYSTEM_PopTask, with fixed fades: 30 frames out, 60 frames in. */
struct GameEvent *FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(struct GameSystem *gameSystem)
{
    struct GameData *gameData = func_020120F4(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, FIELD_SOUND_SYSTEM_PopTask, 0x10);
    FieldSoundTaskWork *work = func_020124E8(event);

    work->fieldSound = (FieldSoundSystem *)func_02012A30(gameData);
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

struct GameEvent *func_02029C64(struct GameSystem *gameSystem)
{
    struct GameData *gameData = func_020120F4(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, FIELD_SOUND_SYSTEM_WaitSettledTask, 0x10);
    FieldSoundTaskWork *work = func_020124E8(event);

    work->fieldSound = (FieldSoundSystem *)func_02012A30(gameData);
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
    struct GameData *gameData = func_020120F4(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, FIELD_SOUND_SYSTEM_WaitAcceptRequestTask, 0x10);
    FieldSoundTaskWork *work = func_020124E8(event);

    work->fieldSound = (FieldSoundSystem *)func_02012A30(gameData);
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
void func_02029CF0(FieldSoundSystem *fieldSound, struct GameData *gameData, u32 zoneId)
{
    u32 season = func_02012984(gameData);
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
void func_02029D44(FieldSoundSystem *fieldSound, struct GameData *gameData, u16 zoneId, u8 season)
{
    u32 bgmNo = FIELD_SOUND_SYSTEM_FindZoneBgmOverride(gameData, zoneId);

    if (bgmNo == ~0u) {
        bgmNo = FIELD_SOUND_SYSTEM_GetZoneBgm(gameData, zoneId, season);
    }
    FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_REPLACE, bgmNo, 0x3C, 0);
}

/* Posts a fade in request with no fade. */
void func_02029D7C(FieldSoundSystem *fieldSound)
{
    FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_FADE_IN, 0, 0, 0);
}

/* Posts a BGM change (fade out 30 frames) for a zone, with the full lookup including the player form. */
void func_02029D8C(FieldSoundSystem *fieldSound, struct GameData *gameData, u32 zoneId)
{
    u32 season = func_02012984(gameData);
    u32 bgmNo = func_02029EB4(gameData, zoneId, season);

    FIELD_SOUND_SYSTEM_PostRequest(fieldSound, FIELD_SOUND_REQUEST_CHANGE, bgmNo, 0x1e, 0);
}

/* Lowers the volume: the 3D sound system goes silent, the fader goes to 0x40 over 6 frames. */
void FIELD_SOUND_SYSTEM_LowerVolume(FieldSoundSystem *fieldSound, struct IssSys *iss)
{
    struct Iss3dsSys *iss3ds = func_0202B57C(iss);

    ISS_3DS_SYS_SetVolume(iss3ds, 0);
    func_02028A58(fieldSound, 0x40, 6);
}

/* Restores the volume: the 3D sound system and the fader go to 0x7f (6 frame fade). */
void FIELD_SOUND_SYSTEM_RestoreVolume(FieldSoundSystem *fieldSound, struct IssSys *iss)
{
    struct Iss3dsSys *iss3ds = func_0202B57C(iss);

    ISS_3DS_SYS_SetVolume(iss3ds, 0x7f);
    func_02028A58(fieldSound, 0x7f, 6);
}

/* Plain forwarder to func_02029EB4 (a pool word and a bx), seeded from the bl sites in ov020 and ov021. */
unsigned int func_02029DF4(struct GameData *gameData, unsigned int zoneId, unsigned int season)
{
    return func_02029EB4(gameData, zoneId, season);
}

/* The BGM the sound system of the game data will end up with once its queue is done. */
void *func_02029DFC(const struct GameData *gameData)
{
    return FIELD_SOUND_SYSTEM_GetFinalValue((FieldSoundSystem *)func_02012A30(gameData));
}

/* Does the zone have an override BGM. */
int func_02029E08(struct GameData *gameData, u32 zoneId)
{
    if (FIELD_SOUND_SYSTEM_FindZoneBgmOverride(gameData, zoneId) != 0xffffffff) {
        return 1;
    }
    return 0;
}

/* Looks up the BGM of a trainer class (0x45A when the class has none). The table ends with key 0x69. */
u16 func_02029E20(u32 trainerClass)
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
    return func_02012B28(func_020127A4(gameData));
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
    void *eventFlags = func_0201296C(gameData);
    u32 i;

    for (i = 0; i < 8; i++) {
        if (zoneId == sZoneBgmOverrides[i].zoneId) {
            if (func_020142E8(eventFlags, sZoneBgmOverrides[i].eventFlag) == 1) {
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
u32 func_02029EB4(struct GameData *gameData, u32 zoneId, u32 season)
{
    int playerObjectCode;
    u32 bgmNo;

    playerObjectCode = FIELD_SOUND_SYSTEM_GetPlayerObjectCode(gameData);
    func_02012A30(gameData);
    bgmNo = FIELD_SOUND_SYSTEM_FindZoneBgmOverride(gameData, zoneId);
    if (bgmNo == (u32)-1) {
        if (playerObjectCode == 2) {
            if (ZONEDATA_IsRingtoneEnabled((u16)zoneId)) {
                return 0x3f5;
            }
        }
        if (playerObjectCode == 1) {
            if (ZONEDATA_IsRingtoneEnabled((u16)zoneId)) {
                return 0x3f4;
            }
        }
        return FIELD_SOUND_SYSTEM_GetZoneBgm(gameData, zoneId, season);
    }
    return bgmNo;
}

/*
 * Creates the ringtone object (the ringtone of the Xtransceiver call), keeps
 * it in the global and registers the sleep callbacks.
 */
Ringtone *RINGTONE_SYS_Create(u32 heapId, struct Fader *volumeFader)
{
    Ringtone *ringtone = func_02030734(heapId, 0xc, 1, sRingtoneSysFileName, 0x72);

    ringtone->ringFramesLeft = 0;
    ringtone->volumeFader = volumeFader;
    gRingtone = ringtone;
    RINGTONE_SYS_RegisterSleepCallbacks();
    return ringtone;
}

void RINGTONE_SYS_Delete(Ringtone *ringtone)
{
    func_020307B0(ringtone);
}

/* Per frame update. */
void RINGTONE_SYS_Update(Ringtone *ringtone)
{
    RINGTONE_SYS_HandleRingTimeout(ringtone);
}

/*
 * Start and stop are twelve byte forwarding thunks that pin the event
 * argument (a pool word and a bx); each sits in its own file so that the pool
 * word of the other stays outside its range.
 */
void RINGTONE_SYS_Start(Ringtone *ringtone)
{
    RINGTONE_SYS_PostEvent(ringtone, RINGTONE_EVENT_START);
}

void RINGTONE_SYS_Stop(Ringtone *ringtone)
{
    RINGTONE_SYS_PostEvent(ringtone, RINGTONE_EVENT_STOP);
}

/* Registers the sleep and wake callbacks for the global ringtone. */
void RINGTONE_SYS_RegisterSleepCallbacks(void)
{
    if (gRingtone != 0) {
        func_0203508C(RINGTONE_SYS_OnSleep, RINGTONE_SYS_OnWake, gRingtone);
    }
}

/* Counts the ring time down and keeps the ring sound (slot 4) playing. Returns 1 while the ring time lasts. */
int RINGTONE_SYS_TickRing(Ringtone *ringtone)
{
    if (ringtone->ringFramesLeft != 0) {
        ringtone->ringFramesLeft = ringtone->ringFramesLeft - 1;
    }
    if (ringtone->ringFramesLeft == 0) {
        if (func_02006224(4) == 1) {
            func_020061F8(4);
        }
        return 0;
    }
    if (func_02006224(4) == 0) {
        func_0200616C(0x662, 4);
    }
    return 1;
}

/* Sleep callback: posts the sleep event to the global ringtone (a pool word tail call). */
void RINGTONE_SYS_OnSleep(void)
{
    RINGTONE_SYS_PostEvent(gRingtone, RINGTONE_EVENT_SLEEP);
}

/* Wake callback: posts the wake event to the global ringtone (a pool word tail call). */
void RINGTONE_SYS_OnWake(void)
{
    RINGTONE_SYS_PostEvent(gRingtone, RINGTONE_EVENT_WAKE);
}

/* Starts the ring sound (slot 4) if it is not playing and loads the ring time, 0x384 frames (15 seconds). */
void RINGTONE_SYS_StartRing(Ringtone *ringtone)
{
    if (func_02006224(4) == 0) {
        func_0200616C(0x662, 4);
    }
    ringtone->ringFramesLeft = 0x384;
}

/* Stops the ring sound. */
void RINGTONE_SYS_StopRing(Ringtone *ringtone)
{
    func_020061F8(4);
    ringtone->ringFramesLeft = 0;
}

/* Mutes (muted == 1) or restores the BGM sound players, and the volume fader. */
void RINGTONE_SYS_SetBgmMuted(Ringtone *ringtone, u32 muted)
{
    if (muted == 1) {
        NNS_SndPlayerSetPlayerVolume(1, 0);
        NNS_SndPlayerSetPlayerVolume(2, 0);
        NNS_SndPlayerSetPlayerVolume(3, 0);
        NNS_SndPlayerSetPlayerVolume(4, 0);
    } else {
        NNS_SndPlayerSetPlayerVolume(1, 0x7f);
        NNS_SndPlayerSetPlayerVolume(2, 0x7f);
        NNS_SndPlayerSetPlayerVolume(3, 0x7f);
        NNS_SndPlayerSetPlayerVolume(4, 0x7f);
    }
    PLAYER_VOLUME_FADER_SetMute(ringtone->volumeFader, muted);
}

/*
 * The ringtone state machine. The next state is a byte of the 4-column
 * transition table at 0x0209FED4, table[state][event]; a plain 2D subscript is
 * the addressing the image has (base + state * 4, then ldrb [event, base]).
 * State 1 and state 3 are written out separately with the same body: the image
 * has a lone b from case 1 into case 3 (cross-jumped), not a shared label.
 */
void RINGTONE_SYS_PostEvent(Ringtone *ringtone, int event)
{
    u8 nextState = sRingtoneTransitions[ringtone->state][event];

    switch (nextState) {
    case RINGTONE_STATE_IDLE:
        func_02072788(0x7f);
        RINGTONE_SYS_SetBgmMuted(ringtone, 0);
        RINGTONE_SYS_StopRing(ringtone);
        break;
    case RINGTONE_STATE_RINGING:
        func_02072788(0x7f);
        RINGTONE_SYS_SetBgmMuted(ringtone, 1);
        RINGTONE_SYS_StartRing(ringtone);
        break;
    case RINGTONE_STATE_ASLEEP:
        func_02072788(0);
        RINGTONE_SYS_StopRing(ringtone);
        break;
    case RINGTONE_STATE_RINGING_ASLEEP:
        func_02072788(0x7f);
        RINGTONE_SYS_SetBgmMuted(ringtone, 1);
        RINGTONE_SYS_StartRing(ringtone);
        break;
    }
    ringtone->state = nextState;
}

/* Per frame: when the ring time of a ringing ringtone has run out, post stop (awake) or wake (asleep). */
void RINGTONE_SYS_HandleRingTimeout(Ringtone *ringtone)
{
    int isRinging = RINGTONE_SYS_TickRing(ringtone);

    switch (ringtone->state) {
    case RINGTONE_STATE_IDLE:
        break;
    case RINGTONE_STATE_RINGING:
        if (isRinging == 0) {
            RINGTONE_SYS_PostEvent(ringtone, RINGTONE_EVENT_STOP);
        }
        break;
    case RINGTONE_STATE_ASLEEP:
        break;
    case RINGTONE_STATE_RINGING_ASLEEP:
        if (isRinging == 0) {
            RINGTONE_SYS_PostEvent(ringtone, RINGTONE_EVENT_WAKE);
        }
        break;
    }
}
