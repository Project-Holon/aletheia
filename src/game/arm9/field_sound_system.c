/*
 * file:     field_sound_system.c
 * unit:     yes
 * function: FIELD_SOUND_SYSTEM_Create, FIELD_SOUND_SYSTEM_Delete, FIELD_SOUND_SYSTEM_GetQueueDepth, FIELD_SOUND_SYSTEM_GetFinalValue, FIELD_SOUND_SYSTEM_IsStateActive, FIELD_SOUND_SYSTEM_IsBusy, FIELD_SOUND_SYSTEM_CanAcceptRequest, FIELD_SOUND_SYSTEM_PostRequest, FIELD_SOUND_SYSTEM_Update, FIELD_SOUND_SYSTEM_Reset, FIELD_SOUND_SYSTEM_FadeVolume, FIELD_SOUND_SYSTEM_StartRingtone, FIELD_SOUND_SYSTEM_StopRingtone, FIELD_SOUND_SYSTEM_ClaimSlot, FIELD_SOUND_SYSTEM_ClaimSlotWithOwner, FIELD_SOUND_SYSTEM_TransferSlot, FIELD_SOUND_SYSTEM_ReleaseSlot, FIELD_SOUND_SYSTEM_PauseSlots, FIELD_SOUND_SYSTEM_ResumeSlots, FIELD_SOUND_SYSTEM_IsKnownSoundId, FIELD_SOUND_SYSTEM_IsSoundRecordChainValid, FIELD_SOUND_SYSTEM_IsSoundIdPlayable, FIELD_SOUND_SYSTEM_Init, FIELD_SOUND_SYSTEM_DrainAndInit, FIELD_SOUND_SYSTEM_ProcessNextRequest, FIELD_SOUND_SYSTEM_GetReadSlot, FIELD_SOUND_SYSTEM_GetCurrentRequest, FIELD_SOUND_SYSTEM_HasPendingRequest, FIELD_SOUND_SYSTEM_CountRequestsOfKind, FIELD_SOUND_SYSTEM_EnqueueRequest, FIELD_SOUND_SYSTEM_IsRequestKindAccepted, FIELD_SOUND_SYSTEM_DequeueRequest, FIELD_SOUND_SYSTEM_ExecuteRequest, FIELD_SOUND_SYSTEM_SetMode1, FIELD_SOUND_SYSTEM_IsKindAllowedInState, FIELD_SOUND_SYSTEM_HandleModeState0, FIELD_SOUND_SYSTEM_HandleModeState1, FIELD_SOUND_SYSTEM_HandleModeState2, FIELD_SOUND_SYSTEM_HandleModeState3, FIELD_SOUND_SYSTEM_HandleModeState4, FIELD_SOUND_SYSTEM_HandleModeState5, FIELD_SOUND_SYSTEM_HandleModeState6, FIELD_SOUND_SYSTEM_HandleModeState7, FIELD_SOUND_SYSTEM_HandleModeState8, FIELD_SOUND_SYSTEM_HandleModeState9, FIELD_SOUND_SYSTEM_HandleModeState10, FIELD_SOUND_SYSTEM_HandleModeState11, FIELD_SOUND_SYSTEM_HandleModeState12, FIELD_SOUND_SYSTEM_HandleModeState13, FIELD_SOUND_SYSTEM_HandleModeState14, FIELD_SOUND_SYSTEM_HandleModeState15, FIELD_SOUND_SYSTEM_HandleModeState16, FIELD_SOUND_SYSTEM_HandleModeState17
 * address:  0x02028844
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
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   PLAYER_VOLUME_FADER_Create  0x02028760  thumb
 *   RINGTONE_SYS_Create  0x02029F14  thumb
 *   GFL_USE_SetSeqStartFilter  0x02005D08  thumb
 *   g_020A7590     0x020A7590  data
 *   PLAYER_VOLUME_FADER_Delete  0x02028784  thumb
 *   RINGTONE_SYS_Delete  0x02029F44  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   _s32_div_f  0x0209C0A4  arm
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
 */
struct Fader;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

/* One queued request: a ring slot of 12 bytes. */
typedef struct FieldSoundRequest {
    u32 kind;
    u32 value;
    u16 lowParam;
    u16 highParam;
} FieldSoundRequest;

/*
 * The field sound system object (0xB8 bytes, allocated by the constructor).
 * The functions of ringtone_sys.c drive the same object.
 */
typedef struct FieldSoundSystem {
    void *desc;                     /* 0x00 descriptor given by the caller */
    u32 state;                      /* 0x04 index into the two per-state handler tables */
    u32 currentValue;               /* 0x08 */
    u32 requestedValue;             /* 0x0C set by modes 5 to 7 */
    u32 overrideValue;              /* 0x10 */
    u32 reserved;                   /* 0x14 cleared by the init, never read */
    u16 highParam;                  /* 0x18 */
    u16 lowParam;                   /* 0x1A */
    u32 mode;                       /* 0x1C latched request class, 0 = none */
    int stackDepth;                 /* 0x20 */
    u32 valueStack[1];              /* 0x24 */
    FieldSoundRequest queue[10];    /* 0x28 ring of requests */
    u8 readIndex;                   /* 0xA0 */
    u8 writeIndex;                  /* 0xA1 */
    struct Fader *volumeFader;      /* 0xA4 */
    void *ringtone;                 /* 0xA8 */
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
extern u32 *RINGTONE_SYS_Create(u32 a0, u32 a1);
extern void GFL_USE_SetSeqStartFilter(int (*hook)(u32 id));
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void RINGTONE_SYS_Delete(void *p);
extern void PLAYER_VOLUME_FADER_Delete(struct Fader *p);
extern u32 GFL_HEAP_Free(void *p);
extern void RINGTONE_SYS_Update(void *p);
extern void PLAYER_VOLUME_FADER_Update(struct Fader *s);
extern void PLAYER_VOLUME_FADER_SetTarget(struct Fader *s, u8 level, u16 frames);
extern void RINGTONE_SYS_Start(void *p);
extern void RINGTONE_SYS_Stop(void *p);
extern int FIELD_SOUND_SYSTEM_FindSlotSound(u32 id);
extern int FIELD_SOUND_SYSTEM_IsSlotSoundTracked(u32 id);
extern int GFL_USE_GetSeSlot(u32 a0);
extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern void GFL_USE_PlaySeWithVolume(u32 id, u32 who);
extern void GFL_USE_SetSeSlotVolume(int i, u32 level);
extern void GFL_USE_StopSeSlot(int i);
extern SoundEventRecord *NNS_SndArcGetSeqInfo(int index);
extern u32 NNS_SndArcGetFileAddress(u32 idx);
extern SoundGroupRecord *NNS_SndArcGetBankInfo(int index);
extern SoundEntryRecord *NNS_SndArcGetWaveArcInfo(u32 id);
extern void FIELD_SOUND_SYSTEM_PopBgm(FieldSoundSystem *s);
extern void FIELD_SOUND_SYSTEM_SetState(FieldSoundSystem *s, u32 value);
extern void FIELD_SOUND_SYSTEM_FinishRequest(FieldSoundSystem *s);
extern void FIELD_SOUND_SYSTEM_FadeInCurrentBgm(FieldSoundSystem *s);
extern void FIELD_SOUND_SYSTEM_PlayRequestedBgmNow(FieldSoundSystem *s);
extern void FIELD_SOUND_SYSTEM_DiscardRequest(FieldSoundSystem *s);
extern void FIELD_SOUND_SYSTEM_FadeOutCurrentBgm(FieldSoundSystem *s);
FieldSoundSystem *FIELD_SOUND_SYSTEM_Create(void *desc, u32 heap);
void FIELD_SOUND_SYSTEM_Delete(FieldSoundSystem *s);
int FIELD_SOUND_SYSTEM_GetQueueDepth(FieldSoundSystem *s);
void *FIELD_SOUND_SYSTEM_GetFinalValue(FieldSoundSystem *s);
u32 FIELD_SOUND_SYSTEM_IsStateActive(FieldSoundSystem *s);
u32 FIELD_SOUND_SYSTEM_IsBusy(FieldSoundSystem *s);
u32 FIELD_SOUND_SYSTEM_CanAcceptRequest(FieldSoundSystem *s);
void FIELD_SOUND_SYSTEM_PostRequest(FieldSoundSystem *s, u32 kind, u32 value, u16 lowParam, u16 highParam);
void FIELD_SOUND_SYSTEM_Update(FieldSoundSystem *s);
void FIELD_SOUND_SYSTEM_Reset(FieldSoundSystem *s, void *desc);
void FIELD_SOUND_SYSTEM_FadeVolume(FieldSoundSystem *s, u8 level, u16 frames);
void FIELD_SOUND_SYSTEM_StartRingtone(FieldSoundSystem *s);
void FIELD_SOUND_SYSTEM_StopRingtone(FieldSoundSystem *s);
void FIELD_SOUND_SYSTEM_ClaimSlot(FieldSoundSystem *s, u32 soundId);
void FIELD_SOUND_SYSTEM_ClaimSlotWithOwner(FieldSoundSystem *s, u32 soundId, u32 owner);
void FIELD_SOUND_SYSTEM_TransferSlot(FieldSoundSystem *s, u32 soundId, u32 owner);
void FIELD_SOUND_SYSTEM_ReleaseSlot(FieldSoundSystem *s, int soundId);
void FIELD_SOUND_SYSTEM_PauseSlots(FieldSoundSystem *s, u32 bits);
void FIELD_SOUND_SYSTEM_ResumeSlots(FieldSoundSystem *s, u32 bits);
int FIELD_SOUND_SYSTEM_IsKnownSoundId(u32 soundId);
u32 FIELD_SOUND_SYSTEM_IsSoundRecordChainValid(int soundIndex);
int FIELD_SOUND_SYSTEM_IsSoundIdPlayable(u32 soundId);
void FIELD_SOUND_SYSTEM_Init(FieldSoundSystem *s, void *desc);
void FIELD_SOUND_SYSTEM_DrainAndInit(FieldSoundSystem *s, void *desc);
void FIELD_SOUND_SYSTEM_ProcessNextRequest(FieldSoundSystem *s);
FieldSoundRequest *FIELD_SOUND_SYSTEM_GetReadSlot(FieldSoundSystem *s);
FieldSoundRequest *FIELD_SOUND_SYSTEM_GetCurrentRequest(FieldSoundSystem *s);
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
FieldSoundSystem *FIELD_SOUND_SYSTEM_Create(void *desc, u32 heap)
{
    FieldSoundSystem *s;

    s = GFL_HEAP_Alloc(heap, sizeof(FieldSoundSystem), 1, g_020A7590, 331);
    FIELD_SOUND_SYSTEM_Init(s, desc);
    s->volumeFader = PLAYER_VOLUME_FADER_Create((void *)heap, 0);
    s->ringtone = RINGTONE_SYS_Create(heap, (u32)s->volumeFader);
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
int FIELD_SOUND_SYSTEM_GetQueueDepth(FieldSoundSystem *s)
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
    if (s->overrideValue != 0) {
        value = (void *)s->overrideValue;
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
void FIELD_SOUND_SYSTEM_Reset(FieldSoundSystem *s, void *desc)
{
    FIELD_SOUND_SYSTEM_DrainAndInit(s, desc);
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
void FIELD_SOUND_SYSTEM_Init(FieldSoundSystem *s, void *desc)
{
    int i;

    s->desc = desc;
    s->state = 0;
    s->mode = 0;
    s->currentValue = 0;
    s->requestedValue = 0;
    s->overrideValue = 0;
    s->reserved = 0;
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
 * from desc. Nothing branches to it; its only reference is the pool word of
 * the reset thunk.
 */
void FIELD_SOUND_SYSTEM_DrainAndInit(FieldSoundSystem *s, void *desc)
{
    while (s->stackDepth != 0) {
        FIELD_SOUND_SYSTEM_PopBgm(s);
    }
    GFL_USE_CancelChangeAndStopBgm();
    FIELD_SOUND_SYSTEM_Init(s, desc);
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
FieldSoundRequest *FIELD_SOUND_SYSTEM_GetCurrentRequest(FieldSoundSystem *s)
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
 * request at the ring (FIELD_SOUND_SYSTEM_GetCurrentRequest) is consulted first, then the latched
 * mode; the first non zero one indexes the 8-wide table at 0x0209FD90 by
 * (row, kind). With neither set, FIELD_SOUND_SYSTEM_IsKindAllowedInState decides. The table base is
 * loaded in each arm (siblings, not a dominator).
 */
u32 FIELD_SOUND_SYSTEM_IsRequestKindAccepted(FieldSoundSystem *s, u32 kind)
{
    u32 row;

    row = FIELD_SOUND_SYSTEM_GetCurrentRequest(s)->kind;
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
