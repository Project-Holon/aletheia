/*
 * file:     gfl_use.c
 * unit:     yes
 * function: NitroMain, GFL_USE_IsNetQuiet, GFL_USE_HBlankHandler, GFL_USE_VBlankHandler, GFL_USE_PostIrqUpdate, GFL_USE_InitGameSystems, GFL_USE_UpdateFrameSubsystems, GFL_USE_ApplySoundModeFromConfig, GFL_USE_InitSdk, GFL_USE_PollPowerExit, GFL_USE_PollTwlService, GFL_USE_CtrdgDummyInit, GFL_USE_OnPreExit, GFL_USE_InitSystem, GFL_USE_PollFrameInput, GFL_USE_NoOpFrameHook, GFL_USE_RunHBlankTasks, GFL_USE_AddHBlankTask, GFL_USE_CallVBlankHook, GFL_USE_SetVBlankHook, GFL_USE_ClearVBlankHook, GFL_USE_RunMainTasks, GFL_USE_AddMainTask, GFL_USE_GetMainTaskList, GFL_USE_InitRandomState, GFL_USE_InitRandom, GFL_USE_GetRandom, GFL_USE_GetRandomBelow, GFL_USE_GetArcPath, GFL_USE_WaitInputReady, GFL_USE_MuteSound, GFL_USE_UnmuteSound, GFL_USE_SetSleepVolumeHooks, GFL_USE_IsMuteHookActive, GFL_USE_SetSndStackHeap, GFL_USE_InitSndSlot, GFL_USE_BeginSndSlot, GFL_USE_EndSndSlot, GFL_USE_InitSndStack, GFL_USE_GetCurrentBgmId, GFL_USE_GetSndStackDepth, GFL_USE_GetCurrentSndHandle, GFL_USE_LoadBgmData, GFL_USE_SaveSeqBankState, GFL_USE_FinishBgmLoad, GFL_USE_UnloadBgmData, GFL_USE_PushSndSlot, GFL_USE_PopSndSlot, GFL_USE_LoadWaveArcSet, GFL_USE_ReleaseWaveArcSet, GFL_USE_InitSound, GFL_USE_ResetSound, GFL_USE_UpdateSound, GFL_USE_ClearSndHeap, GFL_USE_SetStereoOutput, GFL_USE_GetBgmHandle, GFL_USE_GetBgmNo, GFL_USE_GetTargetBgmNo, GFL_USE_IsLoaderBusy, GFL_USE_IsCardIrqEnabled, GFL_USE_SetPlayersAudible, GFL_USE_SetPlayerVolumes, GFL_USE_IsSeqStartAllowed, GFL_USE_SetSeqStartFilter, GFL_USE_StopBgm, GFL_USE_CancelChangeAndStopBgm, GFL_USE_PlayBgm, GFL_USE_CancelChangeAndPlayBgm, GFL_USE_ChangeBgm, GFL_USE_PlayFanfare, GFL_USE_SetBgmPlayerParam, GFL_USE_FadeInBgmFull, GFL_USE_FadeInBgm, GFL_USE_FadeOutBgm, GFL_USE_IsBgmFading, GFL_USE_PushBgm, GFL_USE_PopBgm, GFL_USE_SetBgmAudibleTracks, GFL_USE_SetBgmTrackParams, GFL_USE_SetBgmTrackVolume, GFL_USE_IsBgmPlaying, GFL_USE_CancelChangeDefaultFade, GFL_USE_BeginBgmChange, GFL_USE_CancelBgmChange, GFL_USE_FlushBgmChange, GFL_USE_UpdateBgmChange, GFL_USE_InitSeSlots, GFL_USE_GetSeHandle, GFL_USE_GetSeSlot, GFL_USE_PlaySeInSlot, GFL_USE_PlaySe, GFL_USE_PlaySeDefaultVolume, GFL_USE_PlaySeWithVolume, GFL_USE_StopSeSlot, GFL_USE_StopAllSe, GFL_USE_IsSeSlotBusy, GFL_USE_IsAnySeBusy, GFL_USE_IsSeqPlaying, GFL_USE_SetSeSlotParams, GFL_USE_SetSeSlotVolume, GFL_USE_LoaderThreadSeqBank, GFL_USE_LoaderThreadWaves, GFL_USE_StartLoaderThread, GFL_USE_StopLoaderThread, GFL_USE_IsLoaderDone, GFL_USE_StepBgmLoad, GFL_USE_InstallBgmBuffers, GFL_USE_ReplaceWaveData, GFL_USE_StartSeq, GFL_USE_StopSeqAndUnload, GFL_USE_ClearPreloadedBgmBuffers
 * address:  0x02005124
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Wave 13 lane A5 moved the GFL_USE_* sound manager (0x02005BC0..0x02006544)
 * here from pm_voice.c, which abuts at 0x02005BC0.
 * The four 8-byte ARM linker veneers (`ldr pc, [pc, #-4]`) are asm functions under
 * `#pragma thumb off` ... `#pragma thumb reset`; their callers are Thumb, so the
 * interworking calls are BLX.
 *
 * symbols:
 *   OS_SetIrqFunction      0x02084774  arm
 *   OS_EnableIrqMask       0x02084968  arm
 *   GX_HBlankIntr          0x0207D3AC  arm
 *   GX_VBlankIntr          0x0207D3E4  arm
 *   OS_EnableInterrupts    0x02087974  arm
 *   G3D_SYSTEM_SwapBuffersMain          0x02047990  arm
 *   OS_IsThreadTerminated  0x0208574C  arm
 *   OS_SleepThreadDirect   0x02085760  arm
 *   OS_WaitIrq             0x0208459C  arm
 *   OS_WakeupThreadDirect  0x02085868  arm
 *   _WorkerThread             0x020AA354  data
 *   GFL_NET_SYSTEM_GetConnectNum  0x020392B8  arm
 *   GFL_NET_IsNetTypeBeacon  0x0203D26C  arm
 *   GFL_NET_IsNetTypeWifi  0x0203D29C  arm
 *   SDK_AUTOLOAD_MAIN_TWL_START  0x02FE0000  data
 *   SAVEDATA_SetFailHook   0x02034704  arm
 *   GFL_NET_ERR_ExitAndHalt   0x0200FB6C  thumb
 *   PM_VOICE_GetCryIndex   0x02006C00  thumb
 *   PM_VOICE_PrepareCry   0x02006C2C  thumb
 *   ov010_id        0x0000000A  data
 *   ov011_id        0x0000000B  data
 *   BRIGHTNESS_ChangeMain  0x02023FD8  thumb
 *   WIPE_SYS_Main  0x02022174  thumb
 *   GFL_NET_ERR_CheckNetError  0x0200F734  thumb
 *   GFL_USE_UpdateSound  0x02005BC0  thumb
 *   PM_VOICE_StopFinished  0x020065FC  thumb
 *   GAME_BEACON_Update  0x02026728  thumb
 *   GPOWER_CountDownTimers  0x02010DCC  thumb
 *   GFL_USE_SetStereoOutput  0x02005C28  thumb
 *   CONFIG_GetSoundMode  0x02008390  thumb
 *   OS_Init       0x02086368  arm
 *   OS_InitTick         0x02086FE8  arm
 *   OS_InitAlarm        0x02087208  arm
 *   RTC_Init            0x02088788  arm
 *   GX_Init             0x0207D204  arm
 *   FX_Init       0x0207D148  arm
 *   OS_GetConsoleType   0x02085CBC  arm
 *   SCFG_SetCpuSpeed    0x0208C988  arm
 *   FS_Init             0x0207AD04  arm
 *   FS_TryLoadTable  0x0207ACB4  arm
 *   OS_AllocFromArenaLo 0x02086788  arm
 *   NNS_GfdInitVramTransferTaskQueue        0x02061C0C  arm
 *   APP_ENV_IsRunOnTwl        0x0202EB0C  thumb
 *   PM_GetAmp           0x0208C030  arm
 *   PM_SetAmp           0x0208BEF0  arm
 *   _TwlServiceBuf          0x020A9E94  data
 *   _PreExitState          0x020A9E80  data
 *   _PreExitCallbackInfo          0x020A9E84  data
 *   UI_TestFlags39Global  0x020351D0  arm
 *   NNS_GfdDoVramTransfer  0x02061C44  arm
 *   CTRDG_DummyInit  0x020911A0  arm
 *   _GflUse      0x020AA194  data
 *   s_gfl_use_c     0x020A7004  data
 *   _ArenaTableTwl      0x0209D8A0  data
 *   _ArenaTableDs      0x0209D8B0  data
 *   _ArcPathTable      0x020A6C58  data
 *   APP_POWER_ClearCallback   0x0202F768  thumb
 *   APP_POWER_SetCallback   0x0202F774  thumb
 *   OS_IsRunOnTwl       0x02085D3C  arm
 *   OS_GetArenaHi       0x0208656C  arm
 *   OS_GetArenaLo       0x02086580  arm
 *   OS_InitAlloc        0x02086A50  arm
 *   OS_SetArenaLo       0x02086774  arm
 *   OS_CreateExtraHeap  0x02086B98  arm
 *   OS_AllocFromHeap    0x020868E0  arm
 *   TCB_Main     0x02030D28  arm
 *   TCB_AddTask     0x02030DA8  arm
 *   GF_STANDARD_RandSeed     0x0203F034  arm
 *   GF_STANDARD_CalcHash     0x0203F258  arm
 *   _ull_mul          0x0209C054  arm
 *   UI_Update       0x02034F5C  arm
 *   KEY_GetCont       0x0203630C  arm
 *   NNS_SndSetMasterVolume  0x02072788  arm
 *   UI_SetResumeAndSuspendHooks    0x0203508C  arm
 *   UI_GetSuspendHookGlobal  0x02035108  arm
 *   _SndStack    0x020AA1AC  data
 *   _SndSlots  0x020AA1B8  data
 *   NNS_SndPlayerSetPlayableSeqCount       0x02072DB0  arm
 *   NNS_SndHandleInit       0x02072E9C  arm
 *   NNS_SndHandleReleaseSeq       0x02072EA8  arm
 *   NNS_SndHeapSaveState       0x02074894  arm
 *   NNS_SndHeapLoadState       0x020748E0  arm
 *   NNS_SndArcLoadSeqEx       0x02074AC4  arm
 *   NNS_SndHeapAlloc       0x0207482C  arm
 *   NNS_SndArcLoadSeq       0x02074A6C  arm
 *   _SndHeapBuf   0x020AA9B4  data
 *   _SndState   0x020AA260  data
 *   _SndArcPath   0x020A7010  data
 *   _SndArc   0x020AA2BC  data
 *   NNS_SndInit  0x020726D0  arm
 *   NNS_SndHeapCreate  0x020746E8  arm
 *   NNS_SndArcInit  0x02073FB8  arm
 *   SNDEXi_Init  0x02704364  arm  twl
 *   PM_ReadyToExit  0x027314F0  arm  twl
 *   PM_SetAutoExit  0x027315C0  arm  twl
 *   PM_AppendPreExitCallback  0x0273154C  arm  twl
 *   GFL_USE_CancelChangeDefaultFade  0x02005F5C  thumb
 *   GFL_USE_InitSeSlots  0x02006118  thumb
 *   PM_VOICE_Init  0x02006544  thumb
 *   SAVE_CONTROL_Create  0x02006F20  thumb
 *   CONFIG_ApplyAppliedFlag  0x02008414  thumb
 *   WIH_DWC_CreateFilterBuffer  0x02010794  thumb
 *   WIH_DWC_ResetFilterState  0x020107CC  thumb
 *   GPOWER_Init  0x02010DB4  thumb
 *   POKE_TOOL_InitSystem  0x020173D0  thumb
 *   PRINTSYS_Init  0x0201C41C  thumb
 *   GAME_BEACON_Create  0x020266E0  thumb
 *   GFL_HEAP_Init  0x02030608  arm
 *   PROCSYS_CreateGlobal  0x0203129C  arm
 *   PROCSYS_MainGlobal  0x020312B4  arm
 *   PROCSYS_PushGlobal  0x020312CC  arm
 *   BACKUP_SYSTEM_Init  0x020316C8  arm
 *   GFL_NET_SetupHeaps  0x0203CB34  arm
 *   ARC_TOOL_SetTable  0x02048CEC  arm
 *   TEXTPRINT_Init  0x0204E130  arm
 *   FADE_Create  0x0204E5E8  arm
 *   FADE_Update  0x0204E638  arm
 *   FADE_SetSpeed  0x0204E6F4  arm
 *   NNS_SndArcGetGroupInfo  0x02074518  arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   GFL_HEAP_RegisterBlockHeap  0x02030678  arm
 *   NNS_SndArcPlayerSetup  0x020754C4  arm
 *   MI_WaitDma  0x02082594  arm
 *   CONFIG_InitKeyControlTable  0x020082DC  thumb
 *   GFL_NET_ERR_PollNetState  0x0200F2D4  thumb
 *   MSG_SPEED_SetSaveControl  0x02012FF0  thumb
 *   GF_STANDARD_Reset  0x0203F3B4  arm
 *   WORDSET_LoadSpeciesNameBank  0x0201F344  thumb
 *   GFL_HEAP_InitSystemHeapChecked  0x02030BA4  arm
 *   GF_STANDARD_Init  0x0203EF5C  arm
 *   GF_STANDARD_Setup  0x0203F3F0  arm
 *   BG_SYS_Update  0x020419E4  arm
 *   DMA_UpdateChannels  0x02050A70  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   TCB_GetTaskOffset  0x02030CB0  arm
 *   TCB_Init  0x02030CBC  arm
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   GFL_NET_ERR_CreateHeap  0x0200F6B8  thumb
 *   GFL_NET_ERR_Init  0x0200F6D8  thumb
 *   SAVEDATA_SetPanicHandlers  0x020346EC  arm
 *   GF_OVERLAY_RegisterPanicHandlers  0x02034978  arm
 *   GF_OVERLAY_Init  0x0203499C  arm
 *   UI_Create  0x02034E24  arm
 *   SNDARC_IsGroupLoaded  0x02074A54  arm
 *   SAVE_CONTROL_Get  0x020070A4  thumb
 *   SYSTEM_DATA_GetConfig  0x0200873C  thumb
 */
#define reg_EXMEMCNT (*(volatile u16 *)0x04000204)
#define reg_IME      (*(volatile u16 *)0x04000208)
struct OSThread;
struct SaveCtrl;
struct SaveData;
struct Config;
struct TcbList;
struct Tcb;
struct SndHeap;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef int            BOOL;

typedef unsigned char  u8;

typedef unsigned long long u64;

/* 64 bit linear congruential generator: seed = mul * seed + add. */
struct GflRandom {
    u64 seed;
    u64 mul;
    u64 add;
};

/* Random state plus the two task lists (HBlank, main loop) with their buffers. */
struct GflRuntime {
    struct GflRandom rand;
    struct TcbList *hblankTasks;
    void *hblankTaskBuf;
    struct TcbList *mainTasks;
    void *mainTaskBuf;
};

/* The record the boot code and the frame loop reach their state through. */
struct GflUseState {
    void *vblankHookArg;
    u32 extraHeap;
    void (*vblankHook)(void *);
    u32 frameCount;
    struct GflRuntime *runtime;
    void *extraHeapBlock;
};

typedef signed int     s32;

/* Sound-manager declarations carried over from pm_voice.c with the GFL_USE_*
 * block. */
#define SND_VOLUME_MAX       0x7F
#define SND_TRACKS_ALL       0xFFFF
#define SND_SE_SLOT_COUNT    5
#define SND_PLAYER_BGM       0
#define SND_PLAYER_FANFARE   6

/* Phases of a background music change (SndState.changePhase). */
#define BGM_CHANGE_FADE      0
#define BGM_CHANGE_LOAD_SEQ  1
#define BGM_CHANGE_LOAD_WAVE 2

/* Sequence number whose buffers the sound code installs by hand. */
#define SEQ_PRELOADED_BGM    0x3F2

struct SndSeq;

/* The driver's per-track status record (26 bytes), read back each frame. */
struct SNDTrackInfo {
    u8 raw[0x1A];
};

/* Handle on a playing sequence; the sound library fills the pointer. */
struct SndHandle {
    struct SndSeq *seq;
};

/* One sound effect slot: the sequence started there and its handle. */
struct SeSlot {
    u32 seqNo;
    struct SndHandle handle;
};

/* Entries of the sound archive info tables (only the parts read here). */
struct SndArcSeqEntry {
    u32 fileId;
    u16 bankNo;
};

struct SndArcBankEntry {
    u32 fileId;
    u16 waveArc[4];             /* 0xFFFF: unused */
};

struct SndArcWaveArcEntry {
    u32 fileId : 24;
    u32 flags : 8;
};

/* One level of the sound heap stack (BGM data loaded on top of the level below). */
struct SndSlot {
    u32 inUse;
    u16 bgmId;                  /* 0xFFFF: no BGM loaded */
    u16 pad06;
    struct SndHandle handle;    /* sound handle of the BGM playing in this level */
    u32 baseState;              /* heap state when the level was opened */
    u32 preBgmState;            /* heap state before the BGM data was loaded */
    u32 seqBankState;           /* heap state after sequence and bank were loaded */
    u32 waveState;              /* heap state after the wave archives were loaded */
};

struct SndStack {
    u16 playerNo;
    u16 pad02;
    int top;                    /* index of the current level in _SndSlots */
    struct SndHeap **heapPtr;   /* points at SndState.heap */
};

/*
 * Sound system state, 0x020AA260. The first 0x1C bytes are the part this file
 * sets up; the rest drives the timed change of the background music (fade out,
 * load, fade in) and is used by the GFL_USE_* sound manager carried over from
 * pm_voice.c.
 */
struct SndState {
    u16 activeMask;             /* 00: bit n set when track n reported a record */
    u16 pad02;
    int (*startFilter)(u32 seqNo); /* 04: may veto the start of a sequence */
    u32 countdown;              /* 08: frames left of the running fade */
    u32 loaderSeqNo;            /* 0C: sequence the loader thread works on; its address is the thread argument */
    struct SndHeap *heap;       /* 10: sound heap */
    u32 loaderThread;           /* 14: nonzero once the loader thread was started */
    u32 currentBgm;             /* 18 */
    u32 changeActive;           /* 1C: 1 while a BGM change is pending */
    u32 changePhase;            /* 20: BGM_CHANGE_* */
    u16 fadeCounter;            /* 24: steps into the current fade */
    u16 changeTrackMask;        /* 26: tracks left audible after the change (0xFFFF: all) */
    u32 changeBgm;              /* 28: BGM to switch to */
    int fadeInFrames;           /* 2C */
    int fadeOutFrames;          /* 30 */
};

struct SndWaveSetHeader {
    u32 count;
    u32 savedState;
};


extern void OS_SetIrqFunction(u32 mask, void (*fn)(void));
extern u32  OS_EnableIrqMask(u32 mask);
extern void GX_HBlankIntr(BOOL enable);
extern void GX_VBlankIntr(BOOL enable);
extern u32  OS_EnableInterrupts(void);
extern void G3D_SYSTEM_SwapBuffersMain(void);
extern BOOL OS_IsThreadTerminated(struct OSThread *thread);
extern void OS_SleepThreadDirect(struct OSThread *thread, void *queue);
extern void OS_WaitIrq(BOOL clear, u32 mask);
extern void OS_WakeupThreadDirect(struct OSThread *thread);
extern int GFL_NET_SYSTEM_GetConnectNum(void);
extern u32 GFL_NET_IsNetTypeBeacon(void);
extern u32 GFL_NET_IsNetTypeWifi(void);
extern void MI_WaitDma(u32 mode);
extern int GF_OVERLAY_Load(int overlayId);
extern void PRINTSYS_Init(void *arg);
extern void GFL_NET_SetupHeaps(u32 netType, u32 flagB, u32 flagC, u32 heapId);
extern void WIH_DWC_CreateFilterBuffer(u32 heapId);
extern void WIH_DWC_ResetFilterState(void);
extern void PROCSYS_PushGlobal(int mode, u32 table, u32 option);
extern struct SaveCtrl *SAVE_CONTROL_Create(int heapId);
extern struct SaveData *SAVE_CONTROL_Get(void);
extern struct Config *SYSTEM_DATA_GetConfig(struct SaveData *save);
extern u8 CONFIG_ApplyAppliedFlag(const struct Config *config);
extern void MSG_SPEED_SetSaveControl(struct SaveData *save);
extern void GFL_NET_ERR_CreateHeap(void);
extern void GFL_NET_ERR_Init(u32 kind);
extern void SAVEDATA_SetFailHook(u32 handler);
extern void WORDSET_LoadSpeciesNameBank(u16 heapId);
extern void POKE_TOOL_InitSystem(u32 heapId);
extern void PM_VOICE_Init(u16 heapId, u32 loadVoiceFn, u32 getVoiceFn);
extern void CONFIG_InitKeyControlTable(void);
extern void GAME_BEACON_Create(u32 heapId);
extern void GPOWER_Init(void);
extern void GFL_NET_ERR_ExitAndHalt(void);
extern void PM_VOICE_GetCryIndex(u32 species, u32 form, u32 *out);
extern u32 PM_VOICE_PrepareCry(u32 species, u32 form, void **rec, void **owner, u32 *rate1, u32 *rate2, u32 *addr, u8 *cryPitch);
extern void BRIGHTNESS_ChangeMain(void);
extern void WIPE_SYS_Main(void);
extern void GFL_NET_ERR_CheckNetError(void);
extern void GFL_USE_UpdateSound(void);
extern void PM_VOICE_StopFinished(void);
extern void GAME_BEACON_Update(void);
extern void GPOWER_CountDownTimers(void);
extern unsigned int CONFIG_GetSoundMode(const struct Config *config);
extern void GFL_USE_SetStereoOutput(u32 stereo);
extern void OS_Init(void);
extern void OS_InitTick(void);
extern void OS_InitAlarm(void);
extern void RTC_Init(void);
extern void GX_Init(void);
extern void FX_Init(void);
extern u32  OS_GetConsoleType(void);
extern void SCFG_SetCpuSpeed(int speed);
extern void FS_Init(int dma);
extern void *FS_TryLoadTable(int a, void *b);
extern void *OS_AllocFromArenaLo(int id, void *size, int align);
extern void NNS_GfdInitVramTransferTaskQueue(void *buf, u32 capacity);
extern u32 APP_ENV_IsRunOnTwl(void);
extern void PM_AppendPreExitCallback(void *info);
extern void PM_GetAmp(u32 *out);
extern void PM_SetAmp(int on);
extern int UI_TestFlags39Global(u32 mode);
extern int PM_GetAutoExit(void);
extern int PM_ReadyToExit(void);
/* ARM, and attested by a branch to it from an overlay. */
extern void NNS_GfdDoVramTransfer(void);
extern void CTRDG_DummyInit(void);
extern void PM_SetAutoExit(int v);
extern u32   OS_IsRunOnTwl(void);
extern void *OS_GetArenaHi(u32 id);
extern void *OS_GetArenaLo(u32 id);
extern void *OS_InitAlloc(u32 id, void *lo, void *hi, u32 n);
extern void  OS_SetArenaLo(u32 id, void *lo);
extern u32   OS_CreateExtraHeap(u32 id);
extern void *OS_AllocFromHeap(u32 id, u32 heap, u32 size);
extern void GFL_HEAP_Init(u32 arenaTable, u32 arenaCount, u32 heapCount, u32 flags);
extern void  GFL_HEAP_InitSystemHeapChecked(u32 size);
extern void  GFL_HEAP_CreateChildHeap(u32 arenaId, u32 heapId, u32 size);
extern void  GFL_HEAP_RegisterBlockHeap(void *block, u32 size, u32 heapId);
extern void  GF_STANDARD_Init(u32 mode);
extern void ARC_TOOL_SetTable(u32 table, u32 count);
extern void UI_Create(u32 heapId, u8 mode);
extern void  GF_OVERLAY_RegisterPanicHandlers(void);
extern void SAVEDATA_SetPanicHandlers(u32 mode, u32 flags, u32 waitCallback);
extern void GF_OVERLAY_Init(u32 heapId, int n0, int n1, int n2);
extern void  PROCSYS_CreateGlobal(u32 heapId);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, unsigned short line);
extern u32   TCB_GetTaskOffset(u32 capacity);
extern struct TcbList *TCB_Init(u32 capacity, void *buf);
extern void  FADE_Create(u32 heapId);
extern void BACKUP_SYSTEM_Init(u32 kind, u32 callbackA, u32 callbackB);
extern void  TEXTPRINT_Init(u32 heapId);
extern void  GF_STANDARD_Reset(void);
extern void FADE_SetSpeed(s32 speed);
extern void  APP_POWER_ClearCallback(void);
extern void APP_POWER_SetCallback(u32 on);
extern void UI_Update(void);
extern int GFL_NET_ERR_PollNetState(void);
extern int PROCSYS_MainGlobal(void);
extern void GF_STANDARD_Setup(void);
extern int TCB_Main(struct TcbList *list);
extern struct Tcb *TCB_AddTask(struct TcbList *list, void (*callback)(struct Tcb *, void *), void *work, u32 priority);
extern int BG_SYS_Update(int);
extern int DMA_UpdateChannels(int);
extern int FADE_Update(int);
extern void  GF_STANDARD_RandSeed(u32 seed);
extern void GF_STANDARD_CalcHash(struct GflRandom *out);
extern unsigned int KEY_GetCont(void);
/* The linker veneer in front of SND_SetMasterVolume; ARM. */
extern void NNS_SndSetMasterVolume(u32 volume);
/* Registers a pair of callbacks.  ARM, and in another packet's territory. */
extern void UI_SetResumeAndSuspendHooks(u32 onCallback, u32 offCallback, u32 arg);
extern u32  UI_GetSuspendHookGlobal(void);
extern void NNS_SndPlayerSetPlayableSeqCount(int playerNo, int count);
extern void NNS_SndHandleInit(struct SndHandle *handle);
extern void NNS_SndHandleReleaseSeq(struct SndHandle *handle);
extern int   NNS_SndHeapSaveState(struct SndHeap *heap);
extern void  NNS_SndHeapLoadState(struct SndHeap *heap, u32 state);
extern u32 NNS_SndArcLoadSeqEx(u32 seqNo, u32 loadFlags, struct SndHeap *heap);
extern struct SndWaveSetHeader *NNS_SndHeapAlloc(struct SndHeap *heap, u32 size, u32 flagA, u32 flagB, u32 flagC);
extern u32   NNS_SndArcLoadSeq(u32 waveArcNo, struct SndHeap *heap);
extern void NNS_SndInit(void);
extern struct SndHeap *NNS_SndHeapCreate(char *buf, u32 size);
extern void NNS_SndArcInit(char *arc, char *path, struct SndHeap *heap, u32 riskCheck);
extern void SNDEXi_Init(void);
extern u32 NNS_SndArcPlayerSetup(struct SndHeap *heap);
extern void *NNS_SndArcGetGroupInfo(int index);
extern void SNDARC_IsGroupLoaded(int index, struct SndHeap *heap);
/* Sound manager calls carried over from pm_voice.c. */
extern void  NNS_SndBoot(void);
extern u32   NNS_SndReadDriverInfo(void);
extern int   NNS_SndHandleReadTrackInfo(struct SndHandle *handle, int trackNo, struct SNDTrackInfo *trackInfo);
extern void  NNS_SndHeapDestroy(struct SndHeap *heap);
extern void  NNS_SndSetMasterPan(u32 monoFlag);
extern void  NNS_SndPlayerSetPlayerVolume(u32 playerNo, u32 volume);
extern void  NNS_SndHandleStopSeq(struct SndHandle *handle, int fadeFrames);
extern void  NNS_SndHandlePauseSeq(struct SndHandle *handle, u32 value);
extern void  NNS_SndHandleMoveVolume(struct SndHandle *handle, u32 volume, u32 frames);
extern void  NNS_SndHandleSetVolume(struct SndHandle *handle, int volume);
extern void  NNS_SndHandleSetTrackPause(struct SndHandle *handle, u32 trackMask, u32 mute);
extern void  NNS_SndHandleSetTrackMute(struct SndHandle *handle, u32 trackMask, u32 mute);
extern void  NNS_SndHandleSetTrackVolume(struct SndHandle *handle, u32 trackMask, int volumeIndex);
extern void  NNS_SndHandleSetTrackPitch(struct SndHandle *handle, u32 trackMask, u32 pitch);
extern void  NNS_SndHandleSetTrackPan(struct SndHandle *handle, u32 trackMask, u32 pan);
extern void  NNS_SndHandleSetTrackModDepth(struct SndHandle *handle, u32 trackMask, u32 depth);
extern void  NNS_SndHandleSetTrackModSpeed(struct SndHandle *handle, u32 trackMask, u32 speed);
extern void  NNS_SndHandleStop(struct SndHandle *handle, u32 tempoRatio);
extern s32   NNS_SndPlayerCountPlayingSeqBySeqNo(u32 seqNo);
extern u16   NNS_SndPlayerGetActiveSeqCount(u32 playerNo);
extern void  NNS_SndArcSetReadChunkSize(int loadFlags);
extern void  OS_Sleep(u32 msec);
extern struct SndArcSeqEntry  *NNS_SndArcGetSeqInfo(int seqNo);
extern struct SndArcBankEntry *NNS_SndArcGetBankInfo(int bankNo);
extern struct SndArcWaveArcEntry *NNS_SndArcGetWaveArcInfo(int waveArcNo);
extern u8   *NNS_SndArcGetSeqParam(int seqNo);
extern u32   NNS_SndArcPlayerStartSeq(struct SndHandle *handle, u32 seqNo);
extern u32   NNS_SndArcPlayerStartSeqEx(struct SndHandle *handle, int playerNo, int bankNo, int priority, u32 seqNo);
extern u32   NNS_SndArcLoadWaveArc(u32 waveArcNo, struct SndHeap *heap);
extern void  NNS_SndArcSetFileAddress(u32 fileId, u32 address);
extern u32   NNS_SndArcGetFileAddress(u32 fileId);
extern void  SND_SetWaveDataAddress(u32 *waveArc, u32 waveIndex, u32 address);
extern u32   SND_GetWaveDataAddress(u32 waveArc, u32 waveIndex);
extern void  OS_CreateThread(struct OSThread *thread, void (*entry)(void *), void *arg,
                           void *stack, u32 size, u32 prio);
extern void  OS_DestroyThread(struct OSThread *thread);
extern struct SNDTrackInfo _SndTrackInfo[];
extern struct SeSlot _SeSlots[];
extern void GFL_USE_InitSeSlots(void);
extern void GFL_USE_CancelChangeDefaultFade(void);
void NitroMain(void);
int GFL_USE_IsNetQuiet(void);
void GFL_USE_HBlankHandler(void);
void GFL_USE_VBlankHandler(void);
void GFL_USE_PostIrqUpdate(void);
void GFL_USE_InitGameSystems(void);
void GFL_USE_UpdateFrameSubsystems(void);
void GFL_USE_ApplySoundModeFromConfig(const struct Config *config);
void GFL_USE_InitSdk(void);
void GFL_USE_PollPowerExit(void);
void GFL_USE_PollTwlService(void);
void GFL_USE_CtrdgDummyInit(void);
void GFL_USE_OnPreExit(void);
void GFL_USE_InitSystem(void);
void GFL_USE_PollFrameInput(void);
void GFL_USE_NoOpFrameHook(void);
void GFL_USE_RunHBlankTasks(void);
struct Tcb *GFL_USE_AddHBlankTask(void (*callback)(struct Tcb *, void *), void *work, u32 priority);
void GFL_USE_CallVBlankHook(void);
u32 GFL_USE_SetVBlankHook(void (*hook)(void *), void *hookArg);
void GFL_USE_ClearVBlankHook(void);
void GFL_USE_RunMainTasks(void);
struct Tcb *GFL_USE_AddMainTask(void (*callback)(struct Tcb *, void *), void *work, u32 priority);
struct TcbList *GFL_USE_GetMainTaskList(void);
void GFL_USE_InitRandomState(struct GflRandom *rand);
void GFL_USE_InitRandom(void);
u32 GFL_USE_GetRandom(u32 range);
u32 GFL_USE_GetRandomBelow(u32 range);
void *GFL_USE_GetArcPath(u32 index);
void GFL_USE_WaitInputReady(void);
void GFL_USE_MuteSound(void);
void GFL_USE_UnmuteSound(void);
void GFL_USE_SetSleepVolumeHooks(void);
int GFL_USE_IsMuteHookActive(void);
void GFL_USE_SetSndStackHeap(struct SndHeap **heapPtr);
void GFL_USE_InitSndSlot(u32 level);
void GFL_USE_BeginSndSlot(u32 state);
void GFL_USE_EndSndSlot(void);
void GFL_USE_InitSndStack(u16 playerNo);
u16 GFL_USE_GetCurrentBgmId(void);
u32 GFL_USE_GetSndStackDepth(void);
struct SndHandle *GFL_USE_GetCurrentSndHandle(void);
int GFL_USE_LoadBgmData(u32 bgmId);
void GFL_USE_SaveSeqBankState(void);
int GFL_USE_FinishBgmLoad(u32 bgmId);
void GFL_USE_UnloadBgmData(void);
int GFL_USE_PushSndSlot(void);
int GFL_USE_PopSndSlot(void);
struct SndWaveSetHeader *GFL_USE_LoadWaveArcSet(const u32 *waveArcIds, u32 count);
void GFL_USE_ReleaseWaveArcSet(const struct SndWaveSetHeader *header);
void GFL_USE_InitSound(void);
void GFL_USE_ResetSound(int clearHeap);
extern struct OSThread _WorkerThread;
extern u32  SDK_AUTOLOAD_MAIN_TWL_START[];
extern u8 ov010_id[];
extern u8 ov011_id[];
extern u32 _TwlServiceBuf[];
extern u32 _PreExitState[];
extern u32 _PreExitCallbackInfo[];
extern struct GflUseState _GflUse;
extern u8 s_gfl_use_c[];
extern u8 _ArenaTableTwl[];
extern u8 _ArenaTableDs[];
extern void *_ArcPathTable[];
extern struct SndStack _SndStack;
extern struct SndSlot _SndSlots[];
extern char _SndHeapBuf[];
extern struct SndState _SndState;
extern char _SndArcPath[];
extern char _SndArc[];


static inline u16 OS_EnableIrq(void)
{
    u16 prep = reg_IME;
    reg_IME = 1;
    return prep;
}


static inline void MI_SetMainMemoryPriority(u32 proc)
{
    reg_EXMEMCNT = (u16)((reg_EXMEMCNT & ~0x8000) | (proc << 15));
}


void NitroMain(void)
{
    BOOL isNetQuiet;

    GFL_USE_InitSdk();
    GFL_USE_InitSystem();
    OS_SetIrqFunction(2, GFL_USE_HBlankHandler);
    OS_SetIrqFunction(1, GFL_USE_VBlankHandler);
    (void)OS_EnableIrqMask(3);
    (void)OS_EnableIrq();
    GX_HBlankIntr(1);
    GX_VBlankIntr(1);
    (void)OS_EnableInterrupts();
    GFL_USE_InitGameSystems();
    for (;;) {
        GFL_USE_PollPowerExit();
        GFL_USE_PollFrameInput();
        GFL_USE_UpdateFrameSubsystems();
        GFL_USE_NoOpFrameHook();
        G3D_SYSTEM_SwapBuffersMain();
        isNetQuiet = GFL_USE_IsNetQuiet();
        if (isNetQuiet)
            MI_SetMainMemoryPriority(0);
        if (!OS_IsThreadTerminated(&_WorkerThread))
            OS_SleepThreadDirect(&_WorkerThread, 0);
        OS_WaitIrq(1, 1);
        GFL_USE_PostIrqUpdate();
        if (!OS_IsThreadTerminated(&_WorkerThread))
            OS_WakeupThreadDirect(&_WorkerThread);
        if (isNetQuiet)
            MI_SetMainMemoryPriority(1);
    }
}


/*
 * Boot path, 0x020051D8..0x0200520C: a three-step readiness test (each
 * step its own early `return 0`, per the image's four epilogues) and the
 * unlabelled forwarding thunk GFL_USE_HBlankHandler to GFL_USE_RunHBlankTasks
 * (src/matched/unit_0200560C.c), a pool-word tail call.
 *
 * Rewritten wave 16 from src/pending/GFL_USE_IsNetQuiet.c, a one-line generated
 * body with implicit declarations that was EXACT* on its own.
 * Integrator: seed 0x02005204 (unlabelled follower, member of this unit).
 */
int GFL_USE_IsNetQuiet(void)
{
    if (GFL_NET_SYSTEM_GetConnectNum() > 1)
        return 0;
    if (GFL_NET_IsNetTypeBeacon() != 0)
        return 0;
    if (GFL_NET_IsNetTypeWifi() == 0)
        return 1;
    return 0;
}


void GFL_USE_HBlankHandler(void)
{
    GFL_USE_RunHBlankTasks();
}


/*
 * One of the three callers of the boot path's scene switch (.text init
 * helpers): run GFL_USE_CallVBlankHook, set bit 0 of the word at the end of the
 * arm9_autoload1_main_twl region, then enter mode 3.
 *
 * The address is *two* pool words, not one: the listing writes
 * 0x02FE0000 (`arm9_autoload1_main_twl+0x0`) and the plain literal 0x3FF8,
 * and the load is a register-offset `ldr r2, [r3, r1]`.  That split is the
 * tell that the source named the linker-defined region symbol and added a
 * byte offset to it rather than writing the absolute address: a constant
 * 0x02FE3FF8 pools as a single word with no relocation at all (47 other
 * sites in the image hold 0x02FE3000 outright).  Same finding as
 * src/pending/GFL_HEAP_InitSystemHeap.c's header, where the base is 0x02FE0000 and the
 * offset 0x3000 fits an `add`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_USE_VBlankHandler.c \
 *       --func GFL_USE_VBlankHandler --addr 0x0200520C --cc 1.1p1 --thumb
 */
void GFL_USE_VBlankHandler(void)
{
    GFL_USE_CallVBlankHook();
    *(u32 *)((u8 *)SDK_AUTOLOAD_MAIN_TWL_START + 0x3FF8) |= 1;
    MI_WaitDma(3);
}


void GFL_USE_PostIrqUpdate(void)
{
    GFL_USE_PollTwlService();
    GFL_USE_RunMainTasks();
}


/*
 * Blocking class: label. Seven `bl` sites in this range have no branch witness
 * anywhere else in the image, so their relocation fields stay wildcarded:
 *   0x02006F20 (row of this lane, still unfiled), 0x02034704, 0x02005B24,
 *   0x02006544, 0x020082DC, 0x020266E0, 0x02010DB4.
 * Every other site resolves (label / matched) and every concrete byte in the
 * 152-byte body plus its 24-byte pool reproduces: compiled 176 bytes against
 * the original's 176, 0 concrete differences.
 *
 * Two spellings the original needs and that are not guessable from the bytes:
 *   * the first two calls pass FS_OVERLAY_ID-style absolute symbols, not the
 *     numbers 10 and 11. `GF_OVERLAY_Load(10)` compiles `movs r0, #0xa` (2 bytes,
 *     no pool word) where the original has `ldr r0, [pc, #0x94]` over a pool
 *     word 0x0000000A; declaring `extern u8 ov010_id[]` at 0x0000000A in the
 *     symbols block is what puts the pool word back. Same for 0x0000000B.
 *     (docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md)
 *   * 0x02006C01 and 0x02006C2D are two Thumb function pointers. Written as
 *     plain integers mwcc folds the second to `adds r2, r1, #0x2c` off the
 *     first; written as `&PM_VOICE_GetCryIndex` / `&PM_VOICE_PrepareCry` the two ABS32
 *     relocations keep both pool words, which is the original's shape.
 */
void GFL_USE_InitGameSystems(void)
{
    int netHeapId = 0xC;

    GF_OVERLAY_Load((int)ov010_id);
    GF_OVERLAY_Load((int)ov011_id);
    PRINTSYS_Init(0);
    GFL_NET_SetupHeaps(1, 0, 1, netHeapId);
    WIH_DWC_CreateFilterBuffer(netHeapId);
    WIH_DWC_ResetFilterState();
    PROCSYS_PushGlobal(netHeapId - 0xD, (u32)(void *)0x020A0480, 0);
    SAVE_CONTROL_Create(7);
    CONFIG_ApplyAppliedFlag(SYSTEM_DATA_GetConfig(SAVE_CONTROL_Get()));
    MSG_SPEED_SetSaveControl(SAVE_CONTROL_Get());
    GFL_NET_ERR_CreateHeap();
    GFL_NET_ERR_Init(8);
    SAVEDATA_SetFailHook((u32)&GFL_NET_ERR_ExitAndHalt);
    WORDSET_LoadSpeciesNameBank(0);
    POKE_TOOL_InitSystem(0);
    GFL_USE_InitSound();
    PM_VOICE_Init(1, (u32)&PM_VOICE_GetCryIndex, (u32)&PM_VOICE_PrepareCry);
    GFL_USE_ApplySoundModeFromConfig(SYSTEM_DATA_GetConfig(SAVE_CONTROL_Get()));
    CONFIG_InitKeyControlTable();
    GAME_BEACON_Create(1);
    GPOWER_Init();
}


/*
 * Seven unconditional calls in a row, no arguments and no return value: the
 * tail of the boot sequence, run immediately after GFL_USE_VBlankHandler.  Every
 * callee is an ordinary Thumb `bl` (the second halfword's bit 12 is set in
 * all seven encodings, so none of them is a BLX to ARM code).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_USE_UpdateFrameSubsystems.c \
 *       --func GFL_USE_UpdateFrameSubsystems --addr 0x020052EC --cc 1.1p1 --thumb
 */
void GFL_USE_UpdateFrameSubsystems(void)
{
    BRIGHTNESS_ChangeMain();
    WIPE_SYS_Main();
    GFL_NET_ERR_CheckNetError();
    GFL_USE_UpdateSound();
    PM_VOICE_StopFinished();
    GAME_BEACON_Update();
    GPOWER_CountDownTimers();
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * One function of the boot path, 26 bytes: a test on a two-bit field of the
 * object passed in r0 (CONFIG_GetSoundMode reads it), whose two arms pass 1 and 0
 * to the same one argument routine.  Both arms keep their own call and their
 * own `pop`, which is what an `if`/`else` with a call in each arm compiles to;
 * they are not tail merged, so the call is inside the arms in the source and
 * not written once after the test.
 *
 * The polarity is fixed by the fall through, per
 * docs/idioms/the-fall-through-arm-is-the-source-order.md: the branch is
 * `bne`, so the `== 0` arm is the one the source wrote first and it is the arm
 * that passes 1.
 *
 * It is a range of one function because both of its neighbours are held open
 * by attestation, not because the original file stops here.  See the near miss
 * register in the header of src/matched/unit_020056A0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200530C.c \
 *       --addr 0x0200530C --thumb
 */
void GFL_USE_ApplySoundModeFromConfig(const struct Config *config)
{
    if (CONFIG_GetSoundMode(config) == 0) {
        GFL_USE_SetStereoOutput(1);
    } else {
        GFL_USE_SetStereoOutput(0);
    }
}


/*
 *           nine relocation sites stay wildcarded because this function is
 *           the ONLY branch anywhere in the image to GX_Init (0x0207D204),
 *           SCFG_SetCpuSpeed (0x0208C988), FS_TryLoadTable (0x0207ACB4,
 *           two sites, both here), PM_GetAmp (0x0208C030) and the veneer at
 *           0x020053E4, and the only pool reference to _TwlServiceBuf,
 *           GFL_USE_OnPreExit and _PreExitCallbackInfo.  --suggest-split reports
 *           "0 piece(s), 1 function left out": no cut frees any site,
 *           because the single witness for each is the call inside this
 *           function.  Unblocks only when a second caller of any of these
 *           is filed EXACT, or when 0x02005440 leaves src/pending/.
 *
 * The ARM9 entry's hardware bring-up: SDK init sequence, then the TWL-only
 * clock bump (OS_GetConsoleType & 0x03000000 selects the DSi consoles), two
 * SCFG register masks, the IME reset, FS_Init, the heap arena grab, and the
 * amplifier check.
 *
 * 0x020053E4 is a four-byte ARM long-branch veneer (ldr pc,[pc,#-4]; .word
 * 0x0273154C), not compiled C, so it is declared as an ordinary extern at
 * the stub's address, marked arm; see
 * docs/idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GFL_USE_InitSdk.c \
 *       --func GFL_USE_InitSdk --addr 0x02005328 --cc 1.1p1 --thumb
 */
void GFL_USE_InitSdk(void)
{
    u32 amp;
    void *tableSize;

    OS_Init();
    OS_InitTick();
    OS_InitAlarm();
    RTC_Init();
    GX_Init();
    FX_Init();
    if (OS_GetConsoleType() & 0x03000000) {
        SCFG_SetCpuSpeed(1);
        *(volatile u32 *)0x04004008 &= 0xFFFFDFFF;
        *(volatile u32 *)0x02FFFDF0 &= 0xFFFFDFFF;
    }
    *(volatile u16 *)0x04000208;
    *(volatile u16 *)0x04000208 = 1;
    FS_Init(1);
    tableSize = FS_TryLoadTable(0, 0);
    FS_TryLoadTable((int)OS_AllocFromArenaLo(0, tableSize, 4), tableSize);
    NNS_GfdInitVramTransferTaskQueue(_TwlServiceBuf, 0x30);
    if (APP_ENV_IsRunOnTwl()) {
        _PreExitState[0] = 0;
        _PreExitState[1] = (u32)GFL_USE_OnPreExit;
        _PreExitState[2] = 0;
        PM_AppendPreExitCallback(_PreExitCallbackInfo);
    }
    PM_GetAmp(&amp);
    if (amp == 1)
        PM_SetAmp(0);
}


void GFL_USE_PollPowerExit(void)
{
    if (_PreExitState[0] == 0) {
        return;
    }
    if (UI_TestFlags39Global(2) != 0) {
        return;
    }
    if (PM_GetAutoExit() != 0) {
        return;
    }
    *(volatile u16 *)0x04000204 |= 0x8000;
    PM_ReadyToExit();
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * One eight byte tail call, the shape
 * docs/idioms/tail-call-is-a-pool-word-and-bx.md describes: a pool word and a
 * `bx`, no prologue, no argument set up.  GFL_USE_PostIrqUpdate calls it as the first
 * half of its two step init.
 *
 * The range is one function wide because of its neighbours rather than
 * because of itself.  Immediately before it is the linker veneer at
 * 0x02005428, which is not compiled code at all and cannot be inside any
 * unit.  Immediately after it, GFL_USE_CtrdgDummyInit is the same eight byte shape
 * around CTRDG_DummyInit at 0x020911A0, and the only word in the image that
 * holds 0x020911A0 is that function's own pool word, so the `literal` class
 * discards its only witness and no cut can help.  See the near miss register
 * in the header of src/matched/unit_020056A0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02005430.c \
 *       --addr 0x02005430 --thumb
 */
void GFL_USE_PollTwlService(void)
{
    NNS_GfdDoVramTransfer();
}


/*
 *           r2 sweep: still capped -- no EXACT manifest entry covers the site; the matched class has no witness to offer.
 *
 * A one-instruction forwarder: `ldr r3, [pc, #0]; bx r3` with the pool word
 * holding the callee.  The word is even, so the callee is ARM - the Thumb
 * tail call of the tail-call idiom, crossing the interworking boundary.  It
 * is four bytes of code plus its own two-word literal pool.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GFL_USE_CtrdgDummyInit.c \
 *       --func GFL_USE_CtrdgDummyInit --addr 0x02005438 --cc 1.1p1 --thumb
 */
void GFL_USE_CtrdgDummyInit(void)
{
    CTRDG_DummyInit();
}


void GFL_USE_OnPreExit(void)
{
    PM_SetAutoExit(0);
    _PreExitState[0] = 1;
}


/*
 * gfl_use.c, the file's __FILE__ anchor function: system boot set-up.  On a
 * non-TWL console, carve the main arena into the OS heap (Hi read before Lo,
 * hence the named local), create the extra heap and take a 0x3F00 block
 * from it; then the heap system on the console's arena table, the graphics,
 * card and sound bring-up, the three heap-tracked allocations at lines
 * 0x117 / 0x119 / 0x11C of gfl_use.c (s_gfl_use_c is the __FILE__ pointer),
 * and the task/callback installs.
 *
 * Closed in wave 14.  The pool was misread by one word in the older note
 * (docs/notes/GFL_USE_InitSystem.c.txt): 0x020A6C58 is ARC_TOOL_SetTable's argument
 * and 0x02005769 (GFL_USE_WaitInputReady, src/matched/unit_0200575C.c) is
 * SAVEDATA_SetPanicHandlers's third, and the two words 0x0202F769 / 0x0202F775 are
 * Thumb pointers to two unlabelled callback leaves of time_icon.c, filed
 * EXACT this wave as src/matched/APP_POWER_ClearCallback.c and APP_POWER_SetCallback.c, which
 * is what attests them (`matched`).  _ArenaTableTwl / _ArenaTableDs now resolve on
 * sole-ref.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_USE_InitSystem.c \
 *       --func GFL_USE_InitSystem --addr 0x0200545C --cc 1.1p1 --thumb
 */
void GFL_USE_InitSystem(void)
{
    if (OS_IsRunOnTwl() == 0) {
        void *hi = OS_GetArenaHi(0);
        OS_SetArenaLo(0, OS_InitAlloc(0, OS_GetArenaLo(0), hi, 1));
        _GflUse.extraHeap = OS_CreateExtraHeap(0);
        _GflUse.extraHeapBlock = OS_AllocFromHeap(0, _GflUse.extraHeap, 0x3F00);
    }

    if (OS_IsRunOnTwl() != 0) {
        GFL_HEAP_Init((u32)_ArenaTableTwl, 2, 0xAD, 0);
    } else {
        GFL_HEAP_Init((u32)_ArenaTableDs, 2, 0xAD, 0);
    }

    GFL_HEAP_InitSystemHeapChecked(0x2000);
    GFL_HEAP_CreateChildHeap(1, 7, 0x25000);

    if (OS_IsRunOnTwl() == 0) {
        GFL_HEAP_RegisterBlockHeap(_GflUse.extraHeapBlock, 0x3F00, 9);
    } else {
        GFL_HEAP_CreateChildHeap(1, 9, 0x3F00);
    }

    GF_STANDARD_Init(0);
    ARC_TOOL_SetTable((u32)_ArcPathTable, 0xEB);
    UI_Create(0, 0);

    if (OS_GetConsoleType() & 0x81000000) {
        GF_OVERLAY_RegisterPanicHandlers();
    } else {
        SAVEDATA_SetPanicHandlers(0, 0, (u32)GFL_USE_WaitInputReady);
    }

    GF_OVERLAY_Init(0, 0x10, 4, 4);
    PROCSYS_CreateGlobal(0);

    _GflUse.runtime = GFL_HEAP_Alloc(0, 0x28, 0, (const char *)s_gfl_use_c, 0x117);
    _GflUse.runtime->hblankTaskBuf = GFL_HEAP_Alloc(0, TCB_GetTaskOffset(4), 0, (const char *)s_gfl_use_c, 0x119);
    _GflUse.runtime->hblankTasks = TCB_Init(4, _GflUse.runtime->hblankTaskBuf);
    _GflUse.runtime->mainTaskBuf = GFL_HEAP_Alloc(0, TCB_GetTaskOffset(0x10), 0, (const char *)s_gfl_use_c, 0x11C);
    _GflUse.runtime->mainTasks = TCB_Init(0x10, _GflUse.runtime->mainTaskBuf);

    GFL_USE_InitRandom();
    FADE_Create(0);
    BACKUP_SYSTEM_Init(7, (u32)APP_POWER_ClearCallback, (u32)APP_POWER_SetCallback);
    TEXTPRINT_Init(0);
    GF_STANDARD_Reset();
    _GflUse.frameCount = 0;
    GFL_USE_ClearVBlankHook();
    GFL_USE_SetSleepVolumeHooks();
    FADE_SetSpeed(2);
}


void GFL_USE_PollFrameInput(void)
{
    UI_Update();
    GFL_NET_ERR_PollNetState();
    PROCSYS_MainGlobal();
    GF_STANDARD_Setup();
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 *           GFL_USE_SetVBlankHook, GFL_USE_ClearVBlankHook
 *
 * Six functions on the one system record at 0x020AA194 that the whole of this
 * packet reaches its state through.  Three of the six carry no label, because
 * they save nothing: GFL_USE_NoOpFrameHook is two bytes of `bx lr` padded to four, the
 * empty hook shape
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md records;
 * GFL_USE_RunHBlankTasks is a tail call through a pool word; and GFL_USE_SetVBlankHook is a two
 * arm register-and-return.
 *
 * GFL_USE_CallVBlankHook calls the hook at +8 with the argument at +0 when the hook is
 * present, GFL_USE_SetVBlankHook installs the pair only when the slot is free, and
 * GFL_USE_ClearVBlankHook clears both.  In all three the store to +8 comes before the
 * store to +0, which is the source order.
 *
 * The record's +0x10 is the object src/matched/unit_020056A0.c calls its
 * heaps; the two files name it separately because each pins its own address
 * block.  The range stops at 0x0200567C because GFL_USE_RunMainTasks is held open by
 * one unresolved call site; see the near miss register in the header of
 * src/matched/unit_020056A0.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0200560C.c \
 *       --addr 0x0200560C --thumb
 */
void GFL_USE_NoOpFrameHook(void)
{
}


void GFL_USE_RunHBlankTasks(void)
{
    TCB_Main(_GflUse.runtime->hblankTasks);
}


struct Tcb *GFL_USE_AddHBlankTask(void (*callback)(struct Tcb *, void *), void *work, u32 priority)
{
    return TCB_AddTask(_GflUse.runtime->hblankTasks, callback, work, priority);
}


void GFL_USE_CallVBlankHook(void)
{
    if (_GflUse.vblankHook != 0) {
        _GflUse.vblankHook(_GflUse.vblankHookArg);
    }
}


u32 GFL_USE_SetVBlankHook(void (*hook)(void *), void *hookArg)
{
    if (_GflUse.vblankHook != 0) {
        return 0;
    }
    _GflUse.vblankHook = hook;
    _GflUse.vblankHookArg = hookArg;
    return 1;
}


void GFL_USE_ClearVBlankHook(void)
{
    _GflUse.vblankHook = 0;
    _GflUse.vblankHookArg = 0;
}


void GFL_USE_RunMainTasks(void)
{
    FADE_Update(DMA_UpdateChannels(BG_SYS_Update(TCB_Main(_GflUse.runtime->mainTasks))));
    _GflUse.frameCount++;
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * The tail of the packet: the second heap's allocator wrapper, the shutdown
 * pair, and the two random number draws.  0x020AA194 is the same system
 * record src/matched/unit_0200560C.c reaches, and the pointer at its +0x10 is
 * the same object; the two files name it separately because each pins its own
 * address block.
 *
 * The two draws are a 64 bit linear congruential generator.  0x0209C054 is
 * mwccarm's own `_ull_mul` runtime helper (`umull` plus two `mla`, ARM, at the
 * near end of the helper block that also holds `_u32_div_f`), so the pair of
 * calls in each function is one 64 bit multiply each and not an SDK call:
 *
 *   seed = mul * seed + add;
 *   return (u32)(((seed >> 32) * range) >> 32);
 *
 * The second multiply is what makes the shape readable.  `range` is a u32 and
 * so is the high half of the seed, but the helper is called with r1 and r3
 * both zeroed, which is two operands already widened to 64 bits; that is
 * `(seed >> 32) * range` on a `u64` seed and not a `umull` of two words, and
 * taking the returned r1 is the `>> 32`.  GFL_USE_GetRandom is the same draw with
 * a range of zero meaning "the whole word", and its two arms merge on r1,
 * which is why the zero arm loads the high half into r1 and moves rather than
 * loading it into r0.
 *
 * GFL_USE_GetRandom reloads the high half from memory after the step and
 * GFL_USE_GetRandomBelow keeps it in the register the `adcs` left it in.  That is not a
 * difference in the source: it falls out of the branch in the first one, and
 * both come from the same expression.
 *
 * Three of the six carry no label, all because they save nothing.
 * GFL_USE_GetMainTaskList is a two load getter and GFL_USE_InitRandomState is a tail call through a
 * pool word.  GFL_USE_InitRandomState is in this range rather than a range of its own
 * because GFL_USE_InitRandom is its only caller anywhere in the image, so the call
 * has to be the `local` class; splitting them leaves it with no witness at
 * all.
 *
 * ------------------------------------------------------------------------
 * The near miss register for pkt_020051D8
 *
 * This packet is the system boot path, and that is exactly the shape of code
 * the honesty rule is hardest on: it calls each subsystem's initialiser once
 * and nothing else in the 3.9 MB image calls it again, so the only witness
 * for the target address is the call under test.  Of the packet's 1160 code
 * bytes, 334 are matched in four files (0x0200530C, 0x02005430, 0x0200560C,
 * 0x020056A0) and the rest is listed here with the class and the census that
 * blocks it.  None of it is a codegen failure; nothing below was written and
 * then rejected for wrong bytes.
 *
 *   0x020051D8..0x02005202, 42 bytes.  `label`, 0x0203D26C has one witness
 *       image wide and it is the `blx` at 0x020051E6 inside the function.
 *   0x02005204..0x0200520C, 8 bytes.  A tail call whose pool word holds
 *       0x02005611.  0x02005610 has no `func_` label, because it saves
 *       nothing, and the word appears in exactly one literal pool in the
 *       image, its own at 0x02005208, so `label` has no label and `literal`
 *       discards its only witness.  Seeding the label would not help: nothing
 *       in the image branches to 0x02005610 either.
 *   0x0200520C..0x02005230, 36 bytes.  `label`, the only caller of
 *       GFL_USE_CallVBlankHook is the `bl` at 0x0200520E.  GFL_USE_CallVBlankHook is matched, in
 *       src/matched/unit_0200560C.c, but it is 0x434 bytes away with two
 *       blocked functions and three linker veneers in between, so no
 *       contiguous range makes the site `local`.
 *   0x02005230..0x0200523C, 12 bytes.  `label` twice: the only caller of
 *       GFL_USE_PollTwlService is the `bl` at 0x02005232 and the only caller of
 *       GFL_USE_RunMainTasks is the `bl` at 0x02005236.  Same obstruction as above in
 *       both directions at once.
 *   0x0200523C..0x020052EC, 176 bytes.  19 unresolved sites, 18 of them
 *       `label` with a census of one, plus 0x020A0480 whose only literal
 *       witness is the pool word at 0x020052DC.  This is the once-per-boot
 *       call sequence itself.
 *   0x020052EC..0x0200530C, 32 bytes.  5 unresolved sites, all `label` with a
 *       census of one.
 *   0x02005328..0x020053E4, 188 bytes.  11 unresolved sites.  Two are
 *       structural rather than merely rare: the veneer at 0x020053E4, whose
 *       only witness is the `blx` at 0x020053AA, and the pool word at
 *       0x020053DC naming GFL_USE_OnPreExit, an address no other word or branch in
 *       the image mentions.
 *   0x020053EC..0x02005420, 52 bytes.  The veneers at 0x02005420 and
 *       0x02005428, each witnessed only by its own call site at 0x02005400
 *       and 0x02005412, plus EL_Export at 0x020351D0 with a census of one.
 *   0x02005438..0x02005440, 8 bytes.  `literal`, CTRDG_DummyInit at
 *       0x020911A0 is named by exactly one word in the image and it is this
 *       function's own pool word at 0x0200543C.  It is a labelled SDK symbol,
 *       but no branch anywhere reaches it, so the `label` class has nothing.
 *   0x02005440..0x02005454, 20 bytes.  The veneer at 0x02005454, witnessed
 *       only by the `blx` at 0x02005444.
 *   0x0200545C..0x020055F8, 412 bytes.  19 unresolved sites; the packet's
 *       largest function and its arena, heap and DWC set up.
 *   0x020055F8..0x0200560C, 20 bytes.  3 unresolved sites, all with a census
 *       of one.
 *   0x0200567C..0x020056A0, 36 bytes.  One unresolved site: 0x02050A70,
 *       `label`, one witness image wide and it is the `blx` at 0x0200568C
 *       inside the function.  This is the single function that keeps
 *       src/matched/unit_0200560C.c and this file apart; the day anything
 *       else in the image calls 0x02050A70, the two files and it become one
 *       336 byte range.
 *
 * The four ARM stubs at 0x020053E4, 0x02005420, 0x02005428 and 0x02005454 are
 * not functions and are in no file here.  Each is `ldr pc, [pc, #-4]` and a
 * pointer word, and each pointer (0x0273154C, 0x027315D0, 0x027314F0,
 * 0x027315C0) lies outside every region of layout/layout.json, which is why
 * the `veneer` attestation class cannot carry them: its fourth condition
 * wants the pointer to name code in a known region.  See
 * docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md
 * for what they are and why they force the unit boundaries in this packet.
 * ------------------------------------------------------------------------
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020056A0.c \
 *       --addr 0x020056A0 --thumb
 */
struct Tcb *GFL_USE_AddMainTask(void (*callback)(struct Tcb *, void *), void *work, u32 priority)
{
    return TCB_AddTask(_GflUse.runtime->mainTasks, callback, work, priority);
}


struct TcbList *GFL_USE_GetMainTaskList(void)
{
    return _GflUse.runtime->mainTasks;
}


void GFL_USE_InitRandomState(struct GflRandom *rand)
{
    GF_STANDARD_CalcHash(rand);
}


void GFL_USE_InitRandom(void)
{
    GFL_USE_InitRandomState(&_GflUse.runtime->rand);
    GF_STANDARD_RandSeed(GFL_USE_GetRandom(0));
}


u32 GFL_USE_GetRandom(u32 range)
{
    struct GflRandom *rand = &_GflUse.runtime->rand;
    u32 value;

    rand->seed = rand->mul * rand->seed + rand->add;
    if (range == 0) {
        value = (u32)(rand->seed >> 32);
    } else {
        value = (u32)(((rand->seed >> 32) * range) >> 32);
    }
    return value;
}


u32 GFL_USE_GetRandomBelow(u32 range)
{
    struct GflRandom *rand = &_GflUse.runtime->rand;

    rand->seed = rand->mul * rand->seed + rand->add;
    return (u32)(((rand->seed >> 32) * range) >> 32);
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * A pointer table lookup and a spin loop.  GFL_USE_GetArcPath was already matched
 * as a single function in arm9/legacy.json; it is the first function of this
 * range and is absorbed here.
 *
 * GFL_USE_WaitInputReady waits until four bits of KEY_GetCont's result are all set,
 * pumping UI_Update once per turn.  The four masks are 0x200, 0x100,
 * 0x400 and 0x800 and none of them is materialised with a literal pool word:
 * the compiler builds 0x100 with `movs`/`lsls` and then derives the other
 * three from it with one `lsls` each, hoisted out of the loop.  Testing them
 * as one combined `(x & 0xF00) == 0xF00` gives a single `ldr` from a pool and
 * a different loop, so the four separate short circuited tests are in the
 * source, and their order in the source is 0x200, 0x100, 0x400, 0x800, not
 * the ascending order the hoisted constants suggest.
 */
void *GFL_USE_GetArcPath(u32 index)
{
    return _ArcPathTable[index];
}


void GFL_USE_WaitInputReady(void)
{
    u32 keyState;

    do {
        UI_Update();
        keyState = KEY_GetCont();
    } while (!(keyState & 0x200) || !(keyState & 0x100) || !(keyState & 0x400) || !(keyState & 0x800));
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * Two twelve byte thunks that set the master volume to its two extremes, and
 * the function that hands both of them to UI_SetResumeAndSuspendHooks as a pair of
 * callbacks.  48 bytes, three sections, three literal pools.
 *
 * This range was the near miss recorded in the header of
 * src/matched/unit_020057DC.c, and what closes it is the `veneer` attestation
 * class.  Both thunks tail call 0x02072788, and the bytes there are not a
 * function the analysis can see:
 *
 *   02072788  E59FC000   ldr ip, [pc, #0]
 *   0207278C  E12FFF1C   bx  ip
 *   02072790  0208970C   .word SND_SetMasterVolume
 *
 * a linker veneer.  It has no prologue, so disasm.py's sweep never fires on
 * it and the listing prints the twelve bytes as data; nothing in the image
 * branches to it, so the `label` class has nothing to offer; and the only two
 * words in the 3.9 MB image that hold its address are the two pool words
 * inside this very range, so the `literal` class discards both.  The stub
 * itself is the evidence: a fixed twelve byte encoding that loads a constant
 * into ip and branches to it, with the constant naming SND_SetMasterVolume in
 * layout/symbols_sdk.txt, read entirely from outside the compared range.  See
 * "The veneer class" in docs/MATCHING.md and
 * docs/idioms/a-veneer-call-is-an-ordinary-extern-at-the-veneer-address.md.
 *
 * The extern is declared at the veneer's address rather than at
 * SND_SetMasterVolume's, because that is the address the pool word holds and
 * a matched file has to reproduce the word the linker wrote.  It is declared
 * `arm`, which is what a veneer body is, so the ABS32 resolves with the Thumb
 * bit clear and the `bx r3` lands in ARM state.
 *
 * The function at 0x020057C4 immediately after this range stays open and is
 * not part of this file: it is the only caller of 0x02035108 anywhere in the
 * image, so the one witness for that call is the call itself and no cut can
 * put it outside the range under test.  It also needs GFL_USE_MuteSound local, for
 * the pool word at 0x020057D8, which is why it cannot simply be given a range
 * of its own either.  `python tools/match.py tu --src ... --suggest-split`
 * reports both constraints.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02005794.c \
 *       --addr 0x02005794 --thumb
 */
void GFL_USE_MuteSound(void)
{
    NNS_SndSetMasterVolume(0);
}


void GFL_USE_UnmuteSound(void)
{
    NNS_SndSetMasterVolume(0x7F);
}


void GFL_USE_SetSleepVolumeHooks(void)
{
    UI_SetResumeAndSuspendHooks((u32)GFL_USE_MuteSound, (u32)GFL_USE_UnmuteSound, 0);
}


/*
 * Promoted from src/pending/ in the third 0-64 byte band pass (lane 1).  It
 * was parked there on its one call site only - 0x02035108 is reached by the
 * `blx` inside this function and by nothing else in the image, so `label` had
 * no witness - and it needed no change to its C: 0x02035108 now has an EXACT
 * entry of its own (pkt_0203508C), the site resolves through the `matched`
 * class, and the file printed EXACT on the first re-run.  This is the chain
 * class of the band brief working exactly as described, one pass later than
 * the target list expected, because the callee is another lane's row.
 *
 * "Is the master volume callback still the initial one": the pool word is
 * GFL_USE_MuteSound with its Thumb bit set (0x02005795) and is compared against the
 * word UI_GetSuspendHookGlobal hands back, so the C compares the call's result with the
 * *address* of the thunk - which is why the constant is a relocation and not a
 * plain literal.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_USE_IsMuteHookActive.c \
 *       --func GFL_USE_IsMuteHookActive --addr 0x020057C4 --cc 1.1p1 --thumb
 */
int GFL_USE_IsMuteHookActive(void)
{
    u32 hook;

    hook = UI_GetSuspendHookGlobal();
    return hook == (u32)GFL_USE_MuteSound;
}


/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 *           GFL_USE_InitSndStack, GFL_USE_GetCurrentBgmId, GFL_USE_GetSndStackDepth, GFL_USE_GetCurrentSndHandle,
 *           GFL_USE_LoadBgmData, GFL_USE_SaveSeqBankState, GFL_USE_FinishBgmLoad, GFL_USE_UnloadBgmData,
 *           GFL_USE_PushSndSlot
 *
 * The accessors of a six element table of 0x1C byte connection slots at
 * 0x020AA1B8 and of the one word "which slot is current" record at
 * 0x020AA1AC.  GFL_USE_GetCurrentSndHandle, which returns the address of the current
 * slot's payload, was already matched as a single function in
 * arm9/legacy.json; it is the last function of this range and is absorbed
 * here.  NNS_SndHandleInit is NHTTPi_InitRequestInfo in layout/symbols_sdk.txt,
 * which is what the payload at offset 8 of a slot is.
 *
 * What the range teaches:
 *
 *  - a field of `table[i]` with a run time `i` puts the field offset in the
 *    relocation addend rather than in the instruction.  GFL_USE_InitSndSlot stores
 *    to five different fields of one slot and loads five different pool
 *    words, 0x020AA1B8, 0x020AA1BC, 0x020AA1C4, 0x020AA1C8, 0x020AA1CC and
 *    0x020AA1D0, which are the table's address plus 0, 4, 0xC, 0x10, 0x14
 *    and 0x18.  Thumb's register-offset `str` has no immediate to spare, so
 *    the compiler folds the member offset into the symbol instead.  Reading
 *    those pool words as six separate objects would be the wrong conclusion.
 *  - the constant -1 is never materialised on its own.  GFL_USE_InitSndSlot needs
 *    a 0 for the first store and derives the -1 for the next four from it
 *    with `subs r1, r4, #1`.
 *
 * The near miss this header used to record, the run
 * 0x02005794..0x020057D8, is now closed as far as the evidence allows.  The
 * `veneer` attestation class carries 0x02072788, so the two twelve byte
 * thunks and the function at 0x020057AC that passes both of their addresses
 * to UI_SetResumeAndSuspendHooks are src/matched/unit_02005794.c and are EXACT.
 *
 * What is left open is 0x020057C4 alone, 20 bytes, and the reason is
 * unchanged and structural: UI_GetSuspendHookGlobal has exactly one caller anywhere in
 * the 3.9 MB image and it is the `blx` at 0x020057C6 inside that very
 * function.  Shrinking the range cannot help, because the witness is the call
 * itself, and the target is ARM library code that cannot be made `local`.
 * The function also needs GFL_USE_MuteSound `local`, for the pool word at
 * 0x020057D8 that holds its address.  It closes the day anything else in the
 * image calls 0x02035108.
 */
void GFL_USE_SetSndStackHeap(struct SndHeap **heapPtr)
{
    _SndStack.heapPtr = heapPtr;
}


void GFL_USE_InitSndSlot(u32 level)
{
    _SndSlots[level].inUse = 0;
    _SndSlots[level].bgmId = 0xFFFF;
    NNS_SndHandleReleaseSeq(&_SndSlots[level].handle);
    _SndSlots[level].baseState = -1;
    _SndSlots[level].preBgmState = -1;
    _SndSlots[level].seqBankState = -1;
    _SndSlots[level].waveState = -1;
}


void GFL_USE_BeginSndSlot(u32 state)
{
    struct SndSlot *slot =
        &_SndSlots[_SndStack.top];

    slot->baseState = state;
    slot->preBgmState = state;
    slot->seqBankState = state;
    slot->waveState = state;
    slot->inUse = 1;
}


void GFL_USE_EndSndSlot(void)
{
    struct SndSlot *slot =
        &_SndSlots[_SndStack.top];

    NNS_SndHandleReleaseSeq(&slot->handle);
    NNS_SndHeapLoadState(*_SndStack.heapPtr, slot->baseState);
    GFL_USE_InitSndSlot(_SndStack.top);
}


void GFL_USE_InitSndStack(u16 playerNo)
{
    int i;

    _SndStack.playerNo = playerNo;
    _SndStack.top = 0;
    for (i = 0; i < 6; i++) {
        GFL_USE_InitSndSlot(i);
        NNS_SndHandleInit(&_SndSlots[i].handle);
    }
    NNS_SndPlayerSetPlayableSeqCount(_SndStack.playerNo, 6);
    GFL_USE_BeginSndSlot(NNS_SndHeapSaveState(*_SndStack.heapPtr));
}


u16 GFL_USE_GetCurrentBgmId(void)
{
    struct SndSlot *slot =
        &_SndSlots[_SndStack.top];
    u16 bgmId;

    if (slot->inUse == 0) {
        return 0;
    }
    bgmId = slot->bgmId;
    if (bgmId == 0xFFFF) {
        bgmId = 0;
    }
    return bgmId;
}


u32 GFL_USE_GetSndStackDepth(void)
{
    return _SndStack.top;
}


struct SndHandle *GFL_USE_GetCurrentSndHandle(void)
{
    return &_SndSlots[_SndStack.top].handle;
}


int GFL_USE_LoadBgmData(u32 bgmId)
{
    struct SndSlot *slot =
        &_SndSlots[_SndStack.top];
    int result;

    if (NNS_SndArcLoadSeqEx(bgmId, 3, *_SndStack.heapPtr) == 0) {
        return 0;
    }
    slot->seqBankState = NNS_SndHeapSaveState(*_SndStack.heapPtr);
    result = NNS_SndArcLoadSeqEx(bgmId, 4, *_SndStack.heapPtr);
    if (result == 0) {
        return 0;
    }
    slot->waveState = NNS_SndHeapSaveState(*_SndStack.heapPtr);
    slot->bgmId = bgmId;
    return result;
}


void GFL_USE_SaveSeqBankState(void)
{
    struct SndSlot *slot =
        &_SndSlots[_SndStack.top];

    slot->seqBankState = NNS_SndHeapSaveState(*_SndStack.heapPtr);
}


int GFL_USE_FinishBgmLoad(u32 bgmId)
{
    struct SndSlot *slot =
        &_SndSlots[_SndStack.top];

    slot->waveState = NNS_SndHeapSaveState(*_SndStack.heapPtr);
    slot->bgmId = bgmId;
    return 1;
}


void GFL_USE_UnloadBgmData(void)
{
    struct SndSlot *slot =
        &_SndSlots[_SndStack.top];

    if (slot->inUse == 0) {
        return;
    }
    slot->bgmId = 0xFFFF;
    NNS_SndHeapLoadState(*_SndStack.heapPtr, slot->preBgmState);
    slot->seqBankState = slot->preBgmState;
    slot->waveState = slot->preBgmState;
}


int GFL_USE_PushSndSlot(void)
{
    struct SndSlot *slot =
        &_SndSlots[_SndStack.top];
    u32 state;

    if (_SndStack.top >= 5) {
        return 0;
    }
    if (slot->seqBankState != -1) {
        NNS_SndHeapLoadState(*_SndStack.heapPtr, slot->seqBankState);
        slot->waveState = -1;
        state = slot->seqBankState;
    } else {
        state = slot->preBgmState;
    }
    _SndStack.top++;
    GFL_USE_BeginSndSlot(state);
    return 1;
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * Pop one slot off the stack of connection slots that src/matched/
 * unit_020057DC.c pushes onto.  It is its own byte range rather than part
 * of that unit for an evidence reason and not a source one: NNS_SndArcLoadSeqEx
 * is reached from exactly three `blx` sites image wide, 0x0200593A,
 * 0x02005958 and 0x02005A7A, and the first two are inside
 * unit_020057DC.c's range.  Splitting here leaves each file a witness for
 * the other's calls, which is what the honesty rule in docs/MATCHING.md
 * asks for.
 *
 * `Cur.index` is signed: the guard is `cmp r0, #0` / `bgt`, and written
 * against an unsigned field this compiler emits `bne` instead.
 */
int GFL_USE_PopSndSlot(void)
{
    struct SndSlot *slot;
    int level;
    u16 bgmId;

    if (_SndStack.top <= 0) {
        return 0;
    }
    GFL_USE_EndSndSlot();
    level = _SndStack.top - 1;
    slot = &_SndSlots[level];
    bgmId = slot->bgmId;
    _SndStack.top = level;
    if (bgmId != 0xFFFF) {
        NNS_SndArcLoadSeqEx(bgmId, 6, *_SndStack.heapPtr);
        slot->waveState = NNS_SndHeapSaveState(*_SndStack.heapPtr);
    }
    return 1;
}


/*
 * promoted: from src/pending 2026-09-19, no C change: blocker 0x02074A6C is filed in layout/matched/arm9/pkt_02074A6C.json and every site resolves (gate: manifest --verify --shard layout/matched/arm9/pkt_02005A98.json, then 0 rewritten).
 * blocker (RESOLVED 2026-09-19):  02074A6C - the `blx` inside this function is the only branch to
 *           it anywhere in the image, so `label` has no witness outside the
 *           compared range and the callee is not matched.  Closes when
 *           0x02074A6C's own shard is written.  All 100 concrete bytes and
 *           every other site are right.
 *
 * Push one connection slot onto the stack unit_02005A4C.c pops from: take
 * the current slot's field at +0xC as the saved status word, close the
 * current slot, allocate an 8-byte-plus header block, copy `a1` handles in,
 * stamp the count and the saved word, and finally reset the current index.
 * The loop is a `for` rotated by the compiler (the entry test is on the
 * bound, the back edge on the counter), and `a1` is unsigned because the
 * skid test is `bls`.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GFL_USE_LoadWaveArcSet.c \
 *       --func GFL_USE_LoadWaveArcSet --addr 0x02005A98 --cc 1.1p1 --thumb
 */
struct SndWaveSetHeader *GFL_USE_LoadWaveArcSet(const u32 *waveArcIds, u32 count)
{
    struct SndSlot *slot;
    struct SndWaveSetHeader *header;
    u32 savedState;
    u32 i;

    slot = &_SndSlots[_SndStack.top];
    savedState = slot->baseState;
    GFL_USE_EndSndSlot();
    i = 0;
    header = NNS_SndHeapAlloc(*_SndStack.heapPtr, 8, 0, 0, 0);
    for (i = 0; i < count; i++) {
        NNS_SndArcLoadSeq(waveArcIds[i], *_SndStack.heapPtr);
    }
    header->count = count;
    header->savedState = savedState;
    GFL_USE_BeginSndSlot(NNS_SndHeapSaveState(*_SndStack.heapPtr));
    return header;
}


/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * Close the current connection slot with a status word taken from the
 * second word of the argument block.  Its own byte range because the
 * function immediately before it, 0x02005A98, cannot be attested: the only
 * `blx` to NNS_SndArcLoadSeq anywhere in the image is the one inside it.
 */
void GFL_USE_ReleaseWaveArcSet(const struct SndWaveSetHeader *header)
{
    u32 savedState = header->savedState;

    GFL_USE_EndSndSlot();
    NNS_SndHeapLoadState(*_SndStack.heapPtr, savedState);
    GFL_USE_BeginSndSlot(savedState);
}


/*
 *           and its pointer word 0x02704364, which lies outside every region
 *           of layout/layout.json, so `veneer_at()`'s `names_known_code()`
 *           refuses it and the `veneer` class cannot attest the call.
 *
 * Network bring-up: take a block out of the static buffer at 0x020AA9B4
 * (0x95AD0 bytes, a pool word and not a `movs`-able constant), publish the
 * handle at +0x10 of the connection-slot global and hand the pair to the
 * handler installer, then run the console-type-specific tail.  The function
 * takes no arguments: its first call, NNS_SndInit (sound init), is
 * `void (void)` and reads neither r0 nor r1, so the r0/r1 the caller
 * GFL_USE_InitGameSystems leaves behind are dead
 * (docs/idioms/an-argument-passed-through-a-register-must-be-named-in-the-c.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GFL_USE_InitSound.c \
 *       --func GFL_USE_InitSound --addr 0x02005B24 --cc 1.1p1 --thumb
 */
void GFL_USE_InitSound(void)
{
    struct SndHeap *heap;

    NNS_SndInit();
    heap = NNS_SndHeapCreate(_SndHeapBuf, 0x95AD0);
    _SndState.heap = heap;
    NNS_SndArcInit(_SndArc, _SndArcPath, heap, 0);
    GFL_USE_ResetSound(1);
    if (OS_IsRunOnTwl() == 1) {
        SNDEXi_Init();
    }
}


void GFL_USE_ResetSound(int clearHeap)
{
    NNS_SndArcPlayerSetup(_SndState.heap);
    GFL_USE_SetSndStackHeap(&_SndState.heap);
    if (clearHeap != 0) {
        NNS_SndArcGetGroupInfo(0);
        SNDARC_IsGroupLoaded(0, _SndState.heap);
        _SndState.currentBgm = 0;
    }
    GFL_USE_InitSeSlots();
    GFL_USE_InitSndStack(0);
    GFL_USE_CancelChangeDefaultFade();
    _SndState.activeMask = 0;
    _SndState.countdown = 0;
    _SndState.loaderThread = 0;
    _SndState.startFilter = 0;
}


void GFL_USE_UpdateSound(void);
void GFL_USE_ClearSndHeap(void);
void GFL_USE_SetStereoOutput(u32 mode);
struct SndHandle *GFL_USE_GetBgmHandle(void);
u16 GFL_USE_GetBgmNo(void);
u32 GFL_USE_GetTargetBgmNo(void);
int GFL_USE_IsLoaderBusy(void);
int GFL_USE_IsCardIrqEnabled(void);
void GFL_USE_SetPlayersAudible(int enable, u32 playerMask);
void GFL_USE_SetPlayerVolumes(u32 volume, u32 playerMask);
int GFL_USE_IsSeqStartAllowed(u32 seqNo);
void GFL_USE_SetSeqStartFilter(int (*filter)(u32 seqNo));
void GFL_USE_StopBgm(void);
void GFL_USE_CancelChangeAndStopBgm(void);
u32 GFL_USE_PlayBgm(u32 bgmNo, u32 trackMask);
void GFL_USE_CancelChangeAndPlayBgm(u32 bgmNo, u32 trackMask);
void GFL_USE_ChangeBgm(unsigned int bgmNo, unsigned short trackMask, int fadeOutFrames, int fadeInFrames);
void GFL_USE_PlayFanfare(u32 seqNo);
void GFL_USE_SetBgmPlayerParam(u32 value);
void GFL_USE_FadeInBgmFull(u32 frames);
void GFL_USE_FadeInBgm(u32 frames, u32 volume);
void GFL_USE_FadeOutBgm(u32 frames);
int GFL_USE_IsBgmFading(void);
int GFL_USE_PushBgm(void);
int GFL_USE_PopBgm(void);
void GFL_USE_SetBgmAudibleTracks(u32 trackMask);
void GFL_USE_SetBgmTrackParams(u32 trackMask, u32 tempoRatio, u32 pitch, u32 pan);
void GFL_USE_SetBgmTrackVolume(u32 trackMask, u32 volumeIndex);
int GFL_USE_IsBgmPlaying(void);
void GFL_USE_CancelChangeDefaultFade(void);
void GFL_USE_BeginBgmChange(u32 bgmNo, u16 trackMask, int fadeOutFrames, int fadeInFrames);
void GFL_USE_CancelBgmChange(void);
void GFL_USE_FlushBgmChange(void);
void GFL_USE_UpdateBgmChange(void);
void GFL_USE_InitSeSlots(void);
struct SndHandle *GFL_USE_GetSeHandle(int slot);
int GFL_USE_GetSeSlot(u32 seqNo);
void GFL_USE_PlaySeInSlot(u32 seqNo, int slot);
void GFL_USE_PlaySe(u32 seqNo, u32 volume);
void GFL_USE_PlaySeDefaultVolume(u32 seqNo);
void GFL_USE_PlaySeWithVolume(u32 seqNo, u32 volume);
void GFL_USE_StopSeSlot(int slot);
void GFL_USE_StopAllSe(void);
int GFL_USE_IsSeSlotBusy(u32 slot);
int GFL_USE_IsAnySeBusy(void);
int GFL_USE_IsSeqPlaying(u32 seqNo);
void GFL_USE_SetSeSlotParams(int slot, u32 tempoRatio, u32 pitch, u32 pan);
void GFL_USE_SetSeSlotVolume(int slot, u32 volume);
void GFL_USE_LoaderThreadSeqBank(void *arg);
void GFL_USE_LoaderThreadWaves(void *arg);
void GFL_USE_StartLoaderThread(u32 bgmNo, int mode);
void GFL_USE_StopLoaderThread(void);
int GFL_USE_IsLoaderDone(void);
u32 GFL_USE_StepBgmLoad(u32 bgmNo, u32 *step, u32 abort);
int GFL_USE_InstallBgmBuffers(u32 seqAddr, u32 bankAddr, u32 bgmNo);
int GFL_USE_ReplaceWaveData(u32 waveArcNo, u32 waveIndex, u32 srcWaveArc, u32 srcWaveIndex);
void GFL_USE_StartSeq(u32 seqNo);
void GFL_USE_StopSeqAndUnload(void);
void GFL_USE_ClearPreloadedBgmBuffers(void);


/*
 * Per-frame sound update: finish a pending BGM change step, let the sound
 * library exchange commands with the sound processor, then ask the driver for
 * the record of each of the 16 tracks and keep one bit per track that
 * answered. The fade countdown ticks down by one.
 *
 * The state is spelled in full at every use rather than held in a pointer
 * local: the image reloads its address from the literal pool for the tail,
 * which a named local suppresses. The delay counter is read into a local so
 * the load is reused by the store.
 */
void GFL_USE_UpdateSound(void)
{
    struct SndHandle *handle;
    int trackNo;
    u32 remaining;

    GFL_USE_UpdateBgmChange();
    NNS_SndBoot();
    NNS_SndReadDriverInfo();
    handle = GFL_USE_GetBgmHandle();
    _SndState.activeMask = 0;
    for (trackNo = 0; trackNo < 0x10; trackNo++) {
        if (NNS_SndHandleReadTrackInfo(handle, trackNo, &_SndTrackInfo[trackNo]) == 1) {
            _SndState.activeMask |= (u16)(1 << trackNo);
        }
    }
    remaining = _SndState.countdown;
    if (remaining != 0) {
        _SndState.countdown = remaining - 1;
    }
}

/*
 * Tail call into an ARM routine: the Thumb code loads the address from the
 * literal pool and branches with bx, because a direct branch cannot change
 * instruction set or reach another section.
 */
void GFL_USE_ClearSndHeap(void)
{
    NNS_SndHeapDestroy(_SndState.heap);
}

/*
 * The boolean replaces the parameter in r0, so the fall-through arm carries
 * the literal 1. A `v = 1; if (mode == 1) v = 0;` form allocates a second
 * register and moves every byte.
 */
void GFL_USE_SetStereoOutput(u32 mode)
{
    NNS_SndSetMasterPan(mode != 1);
}

/* Two eight byte forwarders (ldr r3, [pc]; bx r3). */
struct SndHandle *GFL_USE_GetBgmHandle(void)
{
    return GFL_USE_GetCurrentSndHandle();
}

u16 GFL_USE_GetBgmNo(void)
{
    return GFL_USE_GetCurrentBgmId();
}

/* BGM that is playing, or the one a pending change will start. */
u32 GFL_USE_GetTargetBgmNo(void)
{
    if (_SndState.changeActive == 0) {
        return GFL_USE_GetCurrentBgmId();
    }
    return _SndState.changeBgm;
}

/* 1 while the loader thread was started and still runs. */
int GFL_USE_IsLoaderBusy(void)
{
    if (_SndState.loaderThread == 0) {
        return 0;
    }
    if (OS_IsThreadTerminated(&_WorkerThread) != 0) {
        return 0;
    }
    return 1;
}

/*
 * Reads the interrupt enable register (0x04000210) and reports bit 19, the
 * card transfer interrupt. The mask is built with movs/lsls, not loaded.
 */
int GFL_USE_IsCardIrqEnabled(void)
{
    if (*(volatile u32 *)0x04000210 & 0x80000) {
        return 1;
    }
    return 0;
}

/*
 * Full or zero volume for a set of the five players. GFL_USE_SetPlayersAudible forwards
 * its second argument without touching it, and both arms call the same
 * function with a different first argument; computing the argument first
 * would fold the two calls into one and make the function shorter.
 */
void GFL_USE_SetPlayersAudible(int enable, u32 playerMask)
{
    if (enable == 1) {
        GFL_USE_SetPlayerVolumes(SND_VOLUME_MAX, playerMask);
    } else {
        GFL_USE_SetPlayerVolumes(0, playerMask);
    }
}

void GFL_USE_SetPlayerVolumes(u32 volume, u32 playerMask)
{
    int playerNo;

    for (playerNo = 0; playerNo < 5; playerNo++) {
        if ((1 << playerNo) & playerMask) {
            NNS_SndPlayerSetPlayerVolume(playerNo, volume);
        }
    }
}

/* Asks the start filter (when one is set) whether a sequence may start. */
int GFL_USE_IsSeqStartAllowed(u32 seqNo)
{
    if (GFL_USE_IsLoaderBusy() == 0) {
        return 1;
    }
    if (_SndState.startFilter == 0) {
        return 0;
    }
    return _SndState.startFilter(seqNo);
}

void GFL_USE_SetSeqStartFilter(int (*filter)(u32 seqNo))
{
    _SndState.startFilter = filter;
}

/* Stop the BGM at once and drop its data from the sound heap. */
void GFL_USE_StopBgm(void)
{
    NNS_SndHandleStopSeq(GFL_USE_GetCurrentSndHandle(), 0);
    GFL_USE_UnloadBgmData();
}

void GFL_USE_CancelChangeAndStopBgm(void)
{
    GFL_USE_CancelBgmChange();
    GFL_USE_StopBgm();
}

/*
 * Start a BGM now: three guards, each with its own `return 0` epilogue (so
 * they are separate ifs, not a shared exit), then the start call on the
 * current handle with the BGM player and the sequence's own bank and
 * priority (-1). Tracks outside trackMask are muted afterwards.
 *
 * The third failure return reads the zero local that the two -1 arguments
 * were derived from instead of rematerialising `movs r0, #0`.
 */
u32 GFL_USE_PlayBgm(u32 bgmNo, u32 trackMask)
{
    u32 started;
    int zero;

    zero = 0;
    if (GFL_USE_IsSeqStartAllowed(bgmNo) == 0) {
        return 0;
    }
    GFL_USE_StopBgm();
    if (GFL_USE_LoadBgmData(bgmNo) == 0) {
        return 0;
    }
    started = NNS_SndArcPlayerStartSeqEx(GFL_USE_GetCurrentSndHandle(), SND_PLAYER_BGM, -1, -1, bgmNo);
    if (started == 0) {
        return zero;
    }
    if (trackMask != 0xFFFF) {
        GFL_USE_SetBgmAudibleTracks(trackMask);
    }
    return started;
}

void GFL_USE_CancelChangeAndPlayBgm(u32 bgmNo, u32 trackMask)
{
    GFL_USE_CancelBgmChange();
    GFL_USE_PlayBgm(bgmNo, trackMask);
}

/* Starts a timed BGM change: the same four arguments as GFL_USE_BeginBgmChange. */
void GFL_USE_ChangeBgm(unsigned int bgmNo, unsigned short trackMask,
                   int fadeOutFrames, int fadeInFrames)
{
    GFL_USE_BeginBgmChange(bgmNo, trackMask, fadeOutFrames, fadeInFrames);
}

/*
 * Play a sequence on the sixth player (fanfares) after dropping the BGM
 * data. Five-argument call whose fifth argument goes on the stack. The two
 * -1 arguments are derived from the 6 that was just materialised
 * (movs r1, #6; subs r2, r1, #7; adds r3, r2, #0), a peephole that says
 * nothing about the source.
 */
void GFL_USE_PlayFanfare(u32 seqNo)
{
    GFL_USE_CancelBgmChange();
    if (GFL_USE_IsSeqStartAllowed(seqNo) == 0) {
        return;
    }
    GFL_USE_StopBgm();
    if (GFL_USE_LoadBgmData(seqNo) == 0) {
        return;
    }
    NNS_SndArcPlayerStartSeqEx(GFL_USE_GetCurrentSndHandle(), SND_PLAYER_FANFARE, -1, -1, seqNo);
}

void GFL_USE_SetBgmPlayerParam(u32 value)
{
    GFL_USE_FlushBgmChange();
    NNS_SndHandlePauseSeq(GFL_USE_GetCurrentSndHandle(), value);
}

/* Fade in to full volume over `frames`. */
void GFL_USE_FadeInBgmFull(u32 frames)
{
    GFL_USE_FadeInBgm(frames, SND_VOLUME_MAX);
}

/* Set the volume to zero, then fade up to `volume` over `frames`. */
void GFL_USE_FadeInBgm(u32 frames, u32 volume)
{
    GFL_USE_FlushBgmChange();
    NNS_SndHandleMoveVolume(GFL_USE_GetCurrentSndHandle(), 0, 0);
    NNS_SndHandleMoveVolume(GFL_USE_GetCurrentSndHandle(), volume, frames);
    _SndState.countdown = frames;
}

/* Fade out to zero over `frames`. */
void GFL_USE_FadeOutBgm(u32 frames)
{
    GFL_USE_FlushBgmChange();
    NNS_SndHandleMoveVolume(GFL_USE_GetCurrentSndHandle(), 0, frames);
    _SndState.countdown = frames;
}

/*
 * Boolean for `countdown != 0`: in Thumb a two exit branch shape, since
 * there is no conditional move.
 */
int GFL_USE_IsBgmFading(void)
{
    return _SndState.countdown != 0;
}

/* Reset track mute and modulation, then push a level on the sound heap stack. */
int GFL_USE_PushBgm(void)
{
    GFL_USE_FlushBgmChange();
    NNS_SndHandleSetTrackPause(GFL_USE_GetCurrentSndHandle(), SND_TRACKS_ALL, 0);
    NNS_SndHandleSetTrackModDepth(GFL_USE_GetCurrentSndHandle(), SND_TRACKS_ALL, 0);
    NNS_SndHandleSetTrackModSpeed(GFL_USE_GetCurrentSndHandle(), SND_TRACKS_ALL, 0x10);
    return GFL_USE_PushSndSlot();
}

/* Pop a level (stopping the BGM first) when the stack holds more than one. */
int GFL_USE_PopBgm(void)
{
    int depth;

    GFL_USE_FlushBgmChange();
    depth = GFL_USE_GetSndStackDepth();
    if (depth != 0) {
        GFL_USE_StopBgm();
        return GFL_USE_PopSndSlot();
    }
    return depth;
}

/*
 * Leave only the tracks in `trackMask` audible: unmute everything, then mute
 * the complement. The complement is the one's complement truncated to 16
 * bits (lsls #16 / lsrs #16). 0xFFFF is a pool word, loaded once into a
 * callee-saved register and reused as the first call's second argument.
 */
void GFL_USE_SetBgmAudibleTracks(u32 trackMask)
{
    u16 muteMask = (u16)(trackMask ^ 0xFFFF);

    NNS_SndHandleSetTrackPause(GFL_USE_GetCurrentSndHandle(), 0xFFFF, 0);
    if (muteMask != 0) {
        NNS_SndHandleSetTrackMute(GFL_USE_GetCurrentSndHandle(), muteMask, 1);
    }
}

/*
 * Three optional settings, each skipped when the caller passes -1. The -1 is
 * rebuilt before each test (movs/mvns) rather than held in a register, as an
 * inline constant in three comparisons would be.
 */
void GFL_USE_SetBgmTrackParams(u32 trackMask, u32 tempoRatio, u32 pitch, u32 pan)
{
    struct SndHandle *handle = GFL_USE_GetCurrentSndHandle();

    if (tempoRatio != -1) {
        NNS_SndHandleStop(handle, tempoRatio);
    }
    if (pitch != -1) {
        NNS_SndHandleSetTrackPitch(handle, trackMask, pitch);
    }
    if (pan != -1) {
        NNS_SndHandleSetTrackPan(handle, trackMask, pan);
    }
}

/*
 * The handle from GFL_USE_GetCurrentSndHandle stays in r0 across the two parameter moves,
 * which is why the two `adds rN, rN, #0` copies come after the call.
 */
void GFL_USE_SetBgmTrackVolume(u32 trackMask, u32 volumeIndex)
{
    NNS_SndHandleSetTrackVolume(GFL_USE_GetCurrentSndHandle(), trackMask, (int)volumeIndex);
}

/*
 * Nonzero when a BGM is current and the sound library counts the sequence
 * as playing.
 */
int GFL_USE_IsBgmPlaying(void)
{
    if (GFL_USE_GetCurrentBgmId() == 0) {
        return 0;
    }
    if (NNS_SndPlayerCountPlayingSeqBySeqNo(GFL_USE_GetCurrentBgmId()) != 0) {
        return 1;
    }
    return 0;
}

/*
 * Cancel the pending change and restore the default 60 frame fades. The tail
 * call to GFL_USE_CancelBgmChange goes through a pool word and bx even though the
 * target is in the same file: one section per function.
 */
void GFL_USE_CancelChangeDefaultFade(void)
{
    _SndState.fadeInFrames = 60;
    _SndState.fadeOutFrames = 60;
    GFL_USE_CancelBgmChange();
}

/* Queue a change to `bgmNo`: fade the current BGM out, load, fade the new one in. */
void GFL_USE_BeginBgmChange(u32 bgmNo, u16 trackMask, int fadeOutFrames, int fadeInFrames)
{
    _SndState.changeTrackMask = trackMask;
    _SndState.changeBgm = bgmNo;
    _SndState.fadeInFrames = fadeInFrames;
    _SndState.fadeOutFrames = fadeOutFrames;
    _SndState.fadeCounter = fadeOutFrames;
    GFL_USE_StopLoaderThread();
    _SndState.changePhase = BGM_CHANGE_FADE;
    _SndState.changeActive = 1;
}

/* Drop any pending change and put the volume back to maximum. */
void GFL_USE_CancelBgmChange(void)
{
    _SndState.changeActive = 0;
    _SndState.changeTrackMask = 0xFFFF;
    _SndState.changeBgm = 0;
    _SndState.fadeCounter = 0;
    NNS_SndHandleSetVolume(GFL_USE_GetCurrentSndHandle(), SND_VOLUME_MAX);
    _SndState.changePhase = BGM_CHANGE_FADE;
    GFL_USE_StopLoaderThread();
}

/* Finish a pending change at once: wait for the loader, start the BGM, clear the request. */
void GFL_USE_FlushBgmChange(void)
{
    u32 bgmNo;

    if (_SndState.changeActive != 1) {
        return;
    }
    bgmNo = GFL_USE_GetCurrentBgmId();
    if (bgmNo != _SndState.changeBgm) {
        while (_SndState.changePhase != BGM_CHANGE_FADE) {
            GFL_USE_UpdateBgmChange();
        }
        GFL_USE_CancelChangeAndPlayBgm(_SndState.changeBgm, _SndState.changeTrackMask);
    }
    GFL_USE_CancelBgmChange();
}

/*
 * Advance the BGM change by one step per call (the state machine that
 * GFL_USE_UpdateSound runs every frame).
 *
 * BGM_CHANGE_FADE: when another BGM is playing, ramp the volume down over
 * fadeOutFrames (fadeCounter * 0x7F / fadeOutFrames); at zero, stop it,
 * start the loader thread on sequence and bank, and enter LOAD_SEQ. When the
 * wanted BGM is already current, ramp the volume up over fadeInFrames and
 * clear the request at the top. Both divisions are signed, so the compiler's
 * own _s32_div_f helper is called, not _u32_div_f: fadeCounter is a u16
 * promoted to int and both limits are int.
 *
 * BGM_CHANGE_LOAD_SEQ: when the loader is done, save the heap state and start
 * the loader again for the wave archives.
 * BGM_CHANGE_LOAD_WAVE: when it is done, record the BGM, start playing it
 * (volume stays zero) and return to the fade phase for the fade in.
 */
void GFL_USE_UpdateBgmChange(void)
{
    struct SndHandle *handle = GFL_USE_GetCurrentSndHandle();
    u16 bgmNo = GFL_USE_GetCurrentBgmId();

    if (_SndState.changeActive == 0) {
        return;
    }
    switch (_SndState.changePhase) {
    case BGM_CHANGE_FADE:
        if (bgmNo != 0) {
            if (bgmNo != _SndState.changeBgm) {
                if (_SndState.fadeCounter != 0) {
                    _SndState.fadeCounter--;
                    NNS_SndHandleSetVolume(handle, _SndState.fadeCounter * SND_VOLUME_MAX /
                                          _SndState.fadeOutFrames);
                    return;
                }
                NNS_SndHandleSetVolume(handle, 0);
            } else {
                if (_SndState.fadeCounter < _SndState.fadeInFrames) {
                    _SndState.fadeCounter++;
                    NNS_SndHandleSetVolume(handle, _SndState.fadeCounter * SND_VOLUME_MAX /
                                          _SndState.fadeInFrames);
                    return;
                }
                GFL_USE_CancelBgmChange();
                return;
            }
        }
        GFL_USE_StopBgm();
        if (_SndState.changeBgm == 0) {
            GFL_USE_CancelBgmChange();
            return;
        }
        NNS_SndArcSetReadChunkSize(0x1300);
        GFL_USE_StartLoaderThread(_SndState.changeBgm, 0);
        _SndState.fadeCounter = 0;
        _SndState.changePhase = BGM_CHANGE_LOAD_SEQ;
        return;
    case BGM_CHANGE_LOAD_SEQ:
        if (GFL_USE_IsLoaderDone() == 1) {
            GFL_USE_SaveSeqBankState();
            GFL_USE_StartLoaderThread(_SndState.changeBgm, 1);
            _SndState.changePhase = BGM_CHANGE_LOAD_WAVE;
            return;
        }
        OS_Sleep(1);
        return;
    case BGM_CHANGE_LOAD_WAVE:
        if (GFL_USE_IsLoaderDone() == 1) {
            NNS_SndArcSetReadChunkSize(0);
            GFL_USE_FinishBgmLoad(_SndState.changeBgm);
            NNS_SndArcPlayerStartSeqEx(GFL_USE_GetCurrentSndHandle(), SND_PLAYER_BGM, -1, -1, _SndState.changeBgm);
            NNS_SndHandleSetVolume(handle, 0);
            _SndState.changePhase = BGM_CHANGE_FADE;
            return;
        }
        OS_Sleep(1);
        return;
    }
}

/* Clear the five sound effect slots. */
void GFL_USE_InitSeSlots(void)
{
    int slot;

    for (slot = 0; slot < SND_SE_SLOT_COUNT; slot++) {
        _SeSlots[slot].seqNo = 0;
        NNS_SndHandleInit(&_SeSlots[slot].handle);
    }
}

/* No prologue: lsls, adds, adds, bx lr. */
struct SndHandle *GFL_USE_GetSeHandle(int slot)
{
    return &_SeSlots[slot].handle;
}

/*
 * Sound effect slot (0 to 4) for a sequence: the sequence's own player
 * number minus one. Numbers outside the sound effect range map to slot 1.
 * Two `return 1`s cross-jump into one block, and the block lands between the
 * second test and the body, which is what makes the second branch `blo`
 * rather than the `bhs` a conjunction emits; the source has the two guards
 * in this order, each with its own return.
 */
int GFL_USE_GetSeSlot(u32 seqNo)
{
    if (seqNo < 0x546) {
        goto fail;
    }
    if (seqNo < 0x81B) {
        goto ok;
    }
fail:
    return 1;
ok:
    return NNS_SndArcGetSeqParam(seqNo)[5] - 1;
}

/*
 * Start a sound effect in a given slot (player slot + 1) and remember the
 * sequence number on success.
 */
void GFL_USE_PlaySeInSlot(u32 seqNo, int slot)
{
    if (GFL_USE_IsSeqStartAllowed(seqNo) == 0) {
        return;
    }
    _SeSlots[slot].seqNo = 0;
    if (NNS_SndArcPlayerStartSeqEx(&_SeSlots[slot].handle, slot + 1, -1, -1, seqNo) == 1) {
        _SeSlots[slot].seqNo = seqNo;
    }
}

/* Start a sound effect in its own slot; a volume below 0x80 is applied after the start. */
void GFL_USE_PlaySe(u32 seqNo, u32 volume)
{
    int slot;

    if (GFL_USE_IsSeqStartAllowed(seqNo) == 0) {
        return;
    }
    slot = GFL_USE_GetSeSlot(seqNo);
    _SeSlots[slot].seqNo = 0;
    if (NNS_SndArcPlayerStartSeq(&_SeSlots[slot].handle, seqNo) != 1) {
        return;
    }
    _SeSlots[slot].seqNo = seqNo;
    if (volume < 0x80) {
        GFL_USE_SetSeSlotVolume(slot, volume);
    }
}

/*
 * GFL_USE_PlaySeDefaultVolume and GFL_USE_PlaySeWithVolume both tail call GFL_USE_PlaySe through the same
 * pool word: the first supplies -1 as the volume, the second passes both of
 * its arguments through.
 */
void GFL_USE_PlaySeDefaultVolume(u32 seqNo)
{
    GFL_USE_PlaySe(seqNo, -1);
}

void GFL_USE_PlaySeWithVolume(u32 seqNo, u32 volume)
{
    GFL_USE_PlaySe(seqNo, volume);
}

void GFL_USE_StopSeSlot(int slot)
{
    NNS_SndHandleStopSeq(&_SeSlots[slot].handle, 0);
}

void GFL_USE_StopAllSe(void)
{
    int slot;

    for (slot = 0; slot < SND_SE_SLOT_COUNT; slot++) {
        GFL_USE_StopSeSlot(slot);
    }
}

/*
 * The player number is incremented in place before the call, so the source
 * added one to the parameter rather than passing a computed local.
 */
int GFL_USE_IsSeSlotBusy(u32 slot)
{
    return NNS_SndPlayerGetActiveSeqCount(slot + 1) != 0;
}

int GFL_USE_IsAnySeBusy(void)
{
    int slot;

    for (slot = 0; slot < SND_SE_SLOT_COUNT; slot++) {
        if (GFL_USE_IsSeSlotBusy(slot) == 1) {
            return 1;
        }
    }
    return 0;
}

int GFL_USE_IsSeqPlaying(u32 seqNo)
{
    if (NNS_SndPlayerCountPlayingSeqBySeqNo(seqNo) != 0) {
        return 1;
    }
    return 0;
}

/* Optional tempo, pitch and pan of a sound effect slot; -1 leaves a setting alone. */
void GFL_USE_SetSeSlotParams(int slot, u32 tempoRatio, u32 pitch, u32 pan)
{
    if (tempoRatio != -1) {
        NNS_SndHandleStop(&_SeSlots[slot].handle, tempoRatio);
    }
    if (pitch != -1) {
        NNS_SndHandleSetTrackPitch(&_SeSlots[slot].handle, 0xFFFF, pitch);
    }
    if (pan != -1) {
        NNS_SndHandleSetTrackPan(&_SeSlots[slot].handle, 0xFFFF, pan);
    }
}

void GFL_USE_SetSeSlotVolume(int slot, u32 volume)
{
    if (volume > SND_VOLUME_MAX) {
        volume = SND_VOLUME_MAX;
    }
    NNS_SndHandleSetVolume(&_SeSlots[slot].handle, volume);
}

/*
 * The two loader thread bodies and the routine that starts one. Both bodies
 * are six instructions: read the sequence number the argument points at and
 * tail call the archive load with load flags 3 (sequence and bank) or 4
 * (wave archives). Their only references are the two pool words of
 * GFL_USE_StartLoaderThread below.
 */
void GFL_USE_LoaderThreadSeqBank(void *arg)
{
    NNS_SndArcLoadSeqEx(*(u32 *)arg, 3, _SndState.heap);
}

void GFL_USE_LoaderThreadWaves(void *arg)
{
    NNS_SndArcLoadSeqEx(*(u32 *)arg, 4, _SndState.heap);
}

/*
 * Start the loader thread for `bgmNo`: mode 0 loads sequence and bank, mode 1
 * the wave archives. The thread object is at 0x020AA354, its stack ends at
 * 0x020AA9B4 (0x400 bytes), the priority is 0x11. The thread argument is the
 * address of loaderSeqNo, the word just written.
 */
void GFL_USE_StartLoaderThread(u32 bgmNo, int mode)
{
    _SndState.loaderSeqNo = bgmNo;
    GFL_USE_StopLoaderThread();
    switch (mode) {
    case 0:
        OS_CreateThread(&_WorkerThread, GFL_USE_LoaderThreadSeqBank, &_SndState.loaderSeqNo,
                      _SndHeapBuf, 0x400, 0x11);
        break;
    case 1:
        OS_CreateThread(&_WorkerThread, GFL_USE_LoaderThreadWaves, &_SndState.loaderSeqNo,
                      _SndHeapBuf, 0x400, 0x11);
        break;
    }
    OS_WakeupThreadDirect(&_WorkerThread);
    _SndState.loaderThread = (u32)&_WorkerThread;
}

/* Destroy the loader thread when it was started and has not finished. */
void GFL_USE_StopLoaderThread(void)
{
    if (_SndState.loaderThread != 0) {
        if (OS_IsThreadTerminated(&_WorkerThread) == 0) {
            OS_DestroyThread(&_WorkerThread);
            _SndState.loaderThread = 0;
        }
    }
}

/* 1 when the loader thread finished; a thread that was never started counts as finished. */
int GFL_USE_IsLoaderDone(void)
{
    if (_SndState.loaderThread == 0) {
        return 1;
    }
    return OS_IsThreadTerminated(&_WorkerThread);
}

/*
 * Caller driven version of the BGM change: `*step` is the state, advancing
 * at most one step per call; every arm reports 0 except the step out of
 * state 2, which reports 1. abort == 1 stops the BGM and resets the step.
 *
 * The abort arm is deliberately not an early `return 0`: written that way
 * the compiler duplicates the `str r0, [r4]` and emits its own epilogue;
 * with the arm falling through to one shared `return 0` the stores
 * cross-jump into the single `str` at +0x3C. That `str` is the merge point
 * of three paths (abort storing 0, state 0 and state 1 storing *step + 1).
 * The `bne` at +0x0A jumps past the whole abort arm into the switch.
 *
 * In state 2 the two -1 arguments come from `zero - 1` (the compiler keeps
 * the zero in r6), and the second argument of the start call is the
 * leftover result of GFL_USE_GetCurrentSndHandle, which takes none.
 */
u32 GFL_USE_StepBgmLoad(u32 bgmNo, u32 *step, u32 abort)
{
    if (abort == 1) {
        GFL_USE_StopBgm();
        GFL_USE_StopLoaderThread();
        *step = 0;
    } else {
        switch (*step) {
        case 0:
            NNS_SndArcSetReadChunkSize(0x1300);
            GFL_USE_StartLoaderThread(bgmNo, 0);
            (*step)++;
            break;
        case 1:
            if (GFL_USE_IsLoaderDone() == 1) {
                GFL_USE_SaveSeqBankState();
                GFL_USE_StartLoaderThread(bgmNo, 1);
                (*step)++;
            } else {
                OS_Sleep(2);
            }
            break;
        case 2:
            if (GFL_USE_IsLoaderDone() == 1) {
                s32 zero = 0;

                NNS_SndArcSetReadChunkSize(0);
                GFL_USE_FinishBgmLoad(bgmNo);
                NNS_SndArcPlayerStartSeqEx(GFL_USE_GetCurrentSndHandle(), 0, zero - 1, zero - 1, bgmNo);
                (*step)++;
                return 1;
            }
            OS_Sleep(2);
            break;
        default:
            break;
        }
    }
    return 0;
}

/*
 * Start a BGM whose sequence and bank files the caller already loaded:
 * look up the sequence entry (file id, bank number) and the bank entry (file
 * id, up to four wave archives), load every wave archive into the sound
 * heap, bail out with 0 the first time one fails, then install the two
 * buffers under their file ids.
 *
 * The sequence entry is read in two loads before the bank lookup: the file
 * id word first, the bank number halfword second, and the bank number is
 * passed to the bank lookup. The first member of the bank entry is a full
 * 32 bit load.
 */
int GFL_USE_InstallBgmBuffers(u32 seqAddr, u32 bankAddr, u32 bgmNo)
{
    struct SndArcSeqEntry *seq;
    struct SndArcBankEntry *bank;
    u32 seqFileId;
    u16 bankNo;
    u32 bankFileId;
    int i;

    seq = NNS_SndArcGetSeqInfo(bgmNo);
    seqFileId = seq->fileId;
    bankNo = seq->bankNo;
    bank = NNS_SndArcGetBankInfo(bankNo);
    bankFileId = bank->fileId;
    GFL_USE_SaveSeqBankState();
    for (i = 0; i < 4; i++) {
        if (bank->waveArc[i] != 0xFFFF) {
            if (NNS_SndArcLoadWaveArc(bank->waveArc[i], _SndState.heap) == 0) {
                return 0;
            }
        }
    }
    NNS_SndArcSetFileAddress(bankFileId, bankAddr);
    NNS_SndArcSetFileAddress(seqFileId, seqAddr);
    GFL_USE_FinishBgmLoad(bgmNo);
    return 1;
}

/*
 * Replace wave `waveIndex` of a wave archive by wave `srcWaveIndex` of
 * another archive's data. The file id is a 24 bit unsigned bitfield (a
 * lsls #8 / lsrs #8 pair); `& 0xFFFFFF` would load a pool word instead.
 */
int GFL_USE_ReplaceWaveData(u32 waveArcNo, u32 waveIndex, u32 srcWaveArc, u32 srcWaveIndex)
{
    struct SndArcWaveArcEntry *entry;
    u32 *waveArcData;

    entry = NNS_SndArcGetWaveArcInfo(waveArcNo);
    if (entry == 0) {
        return 0;
    }
    waveArcData = (u32 *)NNS_SndArcGetFileAddress(entry->fileId);
    if (waveArcData == 0) {
        return 0;
    }
    SND_SetWaveDataAddress(waveArcData, waveIndex, SND_GetWaveDataAddress(srcWaveArc, srcWaveIndex));
    return 1;
}

/* Start a sequence on the current handle. */
void GFL_USE_StartSeq(u32 seqNo)
{
    NNS_SndArcPlayerStartSeq(GFL_USE_GetCurrentSndHandle(), seqNo);
}

/* Same body as GFL_USE_StopBgm: stop the current sequence and drop its data. */
void GFL_USE_StopSeqAndUnload(void)
{
    NNS_SndHandleStopSeq(GFL_USE_GetCurrentSndHandle(), 0);
    GFL_USE_UnloadBgmData();
}

/*
 * Forget the buffers that GFL_USE_InstallBgmBuffers installed for SEQ_PRELOADED_BGM:
 * the bank file's data address and the sequence file's data address are
 * set to zero. 0x3F2 is past the Thumb movs immediate range, so it arrives
 * in r4 through a pool word and is used twice from there.
 */
void GFL_USE_ClearPreloadedBgmBuffers(void)
{
    u32 bankFileId = NNS_SndArcGetBankInfo(SEQ_PRELOADED_BGM)->fileId;
    u32 seqFileId = NNS_SndArcGetSeqInfo(SEQ_PRELOADED_BGM)->fileId;

    NNS_SndArcSetFileAddress(bankFileId, 0);
    NNS_SndArcSetFileAddress(seqFileId, 0);
}
