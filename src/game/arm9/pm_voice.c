/*
 * file:     pm_voice.c
 * unit:     yes
 * function: PM_VOICE_Init, PM_VOICE_StopAll, PM_VOICE_StopFinished, PM_VOICE_IsAnyActive, PM_VOICE_AllocBuffers, PM_VOICE_FreeBuffers, PM_VOICE_SetMasterVolume, PM_VOICE_ResetMasterVolume, PM_VOICE_ScaleVolume, PM_VOICE_NextSlot, PM_VOICE_ResetParams, PM_VOICE_ClearSlot, PM_VOICE_LoadWave, PM_VOICE_StartChannels, PM_VOICE_Stop, PM_VOICE_Play, PM_VOICE_Prepare, PM_VOICE_Start, PM_VOICE_AddVolume, PM_VOICE_AddFrequency, PM_VOICE_GetVolume, PM_VOICE_GetFrequency, PM_VOICE_GetData, PM_VOICE_GetDataSize, PM_VOICE_GetSampleRate, PM_VOICE_StopSlot, PM_VOICE_IsSlotActive, PM_VOICE_ReverseBytes, PM_VOICE_GetCryIndex, PM_VOICE_PrepareCry, PM_VOICE_GetPerapVoiceSave, SND_MIC_Init, SND_MIC_Exit, SND_MIC_AddElapsed, SND_MIC_IsLimitReached, SND_MIC_StartSampling, SND_MIC_StartRecording, SND_MIC_StoreRecording, SND_MIC_GetBufferAligned
 * address:  0x02006544
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from bgm_info.c at 0x02006E40 (__FILE__ anchor boundary, certain cut).
 * Split at 0x02006544: the GFL_USE_* sound manager head moved to gfl_use.c,
 * which abuts at 0x02005BC0.
 *
 * symbols:
 *   NNS_SndBoot  0x02072758  arm
 *   NNS_SndReadDriverInfo  0x020727B4  arm
 *   NNS_SndHandleReadTrackInfo  0x02073108  arm
 *   NNS_SndHeapDestroy       0x02074758  arm
 *   NNS_SndSetMasterPan  0x02072794  arm
 *   GFL_USE_GetCurrentBgmId  0x020058D0  thumb
 *   GFL_USE_GetCurrentSndHandle  0x0200590C  thumb
 *   OS_IsThreadTerminated       0x0208574C  arm
 *   GFL_USE_UnloadBgmData        0x020059C8  thumb
 *   NNS_SndPlayerSetPlayerVolume       0x02072D98  arm
 *   NNS_SndHandleStopSeq       0x02072E7C  arm
 *   GFL_USE_LoadBgmData   0x02005924  thumb
 *   NNS_SndArcPlayerStartSeqEx  0x020755A8  arm
 *   NNS_SndHandleMoveVolume       0x02072F5C  arm
 *   NNS_SndHandleSetTrackPause  0x02072FA8  arm
 *   NNS_SndHandleSetTrackMute  0x02072FC8  arm
 *   NNS_SndHandleSetTrackPitch  0x02073018  arm
 *   NNS_SndHandleSetTrackPan  0x02073038  arm
 *   NNS_SndHandleStop  0x02073098  arm
 *   NNS_SndHandleSetTrackVolume  0x02072FE8  arm
 *   GFL_USE_StopLoaderThread        0x02006368  thumb
 *   NNS_SndPlayerCountPlayingSeqBySeqNo       0x02072EE0  arm
 *   NNS_SndHandleSetVolume       0x02072F34  arm
 *   GFL_USE_SaveSeqBankState        0x0200597C  thumb
 *   GFL_USE_FinishBgmLoad        0x020059A0  thumb
 *   NNS_SndArcSetReadChunkSize       0x020746B0  arm
 *   NNS_SndHandleInit       0x02072E9C  arm
 *   OS_Sleep       0x02085A38  arm
 *   NNS_SndArcGetSeqParam  0x0207430C  arm
 *   NNS_SndArcPlayerStartSeq       0x02075560  arm
 *   NNS_SndPlayerGetActiveSeqCount  0x02072EC8  arm
 *   OS_CreateThread        0x020853C0  arm
 *   NNS_SndArcLoadSeqEx        0x02074AC4  arm
 *   OS_WakeupThreadDirect        0x02085868  arm
 *   OS_DestroyThread  0x020855BC  arm
 *   NNS_SndArcGetSeqInfo  0x02074324  arm
 *   NNS_SndArcGetBankInfo  0x020743EC  arm
 *   NNS_SndArcLoadWaveArc  0x02074A98  arm
 *   NNS_SndArcSetFileAddress  0x02074694  arm
 *   NNS_SndArcGetWaveArcInfo  0x02074450  arm
 *   NNS_SndArcGetFileAddress  0x0207466C  arm
 *   SND_SetWaveDataAddress  0x0208A640  arm
 *   SND_GetWaveDataAddress  0x0208A674  arm
 *   func_02030734       0x02030734  arm
 *   NNS_SndWaveOutIsPlaying       0x02072CC4  arm
 *   func_020307B0       0x020307B0  arm
 *   NNS_SndWaveOutAllocChannel  0x02072A44  arm
 *   NNS_SndWaveOutStart  0x02072AA0  arm
 *   NNS_SndArcGetFileSize  0x0207457C  arm
 *   NNS_SndArcReadFile  0x020745A4  arm
 *   SNDi_GetBankWaveArcTable  0x0208A638  arm
 *   NNS_SndWaveOutStop  0x02072BDC  arm
 *   NNS_SndWaveOutWaitIdle  0x02072D20  arm
 *   NNSi_SndWaveOutUnlockChannel  0x02072A88  arm
 *   NNS_SndWaveOutSetVolume  0x02072C18  arm
 *   NNS_SndWaveOutSetSpeed  0x02072C40  arm
 *   func_020056EC  0x020056EC  thumb
 *   func_02007B50  0x02007B50  thumb
 *   func_02007B64  0x02007B64  thumb
 *   func_02007B68  0x02007B68  thumb
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   func_020070A4  0x020070A4  thumb
 *   func_02007B44  0x02007B44  thumb
 *   MI_CpuFill8  0x02082BCC  arm
 *   PM_SetAmp  0x0208BEF0  arm
 *   PM_SetAmpGain  0x0208BF38  arm
 *   MIC_Init  0x0208B24C  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   SNDEXi_SetIirFilter  0x027047C0  arm  twl
 *   _SndState           0x020AA260  data
 *   _SndTrackInfo       0x020AA414  data
 *   _SeSlots            0x020AA294  data
 *   _WorkerThread       0x020AA354  data
 *   _SndHeapBuf         0x020AA9B4  data
 *   _VoiceSystem        0x02140484  data
 *   _VoiceBuffer0       0x02140534  data
 *   _VoiceChannelTable  0x0209D8C0  data
 *   _PmVoiceFile        0x020A7024  data
 *   _SndMicFile         0x020A703C  data
 *   _MicIirFilter       0x020A7030  data
 *   _SndMic             0x02146164  data
 *   NNS_SndHandleSetTrackModDepth  0x02073058  arm
 *   NNS_SndHandleSetTrackModSpeed  0x02073078  arm
 *   GFL_USE_GetSndStackDepth  0x02005900  thumb
 *   GFL_USE_PushSndSlot  0x02005A00  thumb
 *   GFL_USE_PopSndSlot  0x02005A4C  thumb
 *   NNS_SndHandlePauseSeq  0x02072E8C  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
typedef signed char    s8;

/* Sound volume range and the player numbers the sequence start call takes. */
#define SND_VOLUME_MAX       0x7F
#define SND_TRACKS_ALL       0xFFFF
#define SND_SE_SLOT_COUNT    5
#define SND_PLAYER_BGM       0
#define SND_PLAYER_FANFARE   6

/* Phases of a background music change (SndState.changePhase). */
#define BGM_CHANGE_FADE      0   /* ramp the volume down, or up once the new BGM plays */
#define BGM_CHANGE_LOAD_SEQ  1   /* loader thread reads sequence and bank */
#define BGM_CHANGE_LOAD_WAVE 2   /* loader thread reads the wave archives */

/* Sequence number whose buffers PM sound code installs by hand. */
#define SEQ_PRELOADED_BGM    0x3F2

/* Voice mixer limits. */
#define PM_VOICE_SLOT_COUNT  3
#define PM_VOICE_DEFAULT_SAMPLE_RATE 0x3443
#define PM_VOICE_DEFAULT_FREQUENCY   0x64E1
#define PM_VOICE_BUFFER_SIZE 0x5C30

struct SndHeap;
struct SndSeq;
struct SndChannel;
struct PerapVoice;
struct SaveData;
struct SaveBlock;

/* The driver's per-track status record (26 bytes), read back each frame. */
struct SNDTrackInfo {
    u8 raw[0x1A];
};

/* Handle on a playing sequence; the sound library fills the pointer. */
struct SndHandle {
    struct SndSeq *seq;
};

/*
 * Sound manager state at 0x020AA260. The first 0x1C bytes are the part
 * gfl_use.c sets up; the rest drives the timed change of the background
 * music (fade out, load, fade in).
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

/* Channel pair numbers for one voice slot, from a table in the ROM. */
struct PmVoiceChannelPair {
    u16 channelA;
    u16 channelB;
};

/* Header of a loaded wave file. */
struct PmWaveFile {
    u32 signature;
    u32 version;
    u32 fileSize;
    u8  header[0x30];
    u32 waveOffset;             /* offset of the wave record */
};

/* Wave record (SWAV layout): the sample data follows after 0xC bytes. */
struct PmWave {
    u8  waveType;
    u8  loopFlag;
    u16 sampleRate;
    u16 timer;
};

/* One playing voice (0x34 bytes): a loaded wave and one or two hardware channels. */
struct PmVoice {
    u32 active;                 /* 00: 1 while the voice owns channels */
    void *buffer;               /* 04: loaded wave file */
    u32 dataSize;               /* 08: bytes of sample data */
    u32 sampleRate;             /* 0C */
    u8  *data;                  /* 10: sample data (reversed in place for backwards play) */
    struct SndChannel *channelA; /* 14 */
    struct SndChannel *channelB; /* 18: second channel when dual is set */
    s8  volume;                 /* 1C */
    s8  volumeBiasB;            /* 1D: added to volume for channel B */
    u8  channelNoA : 4;         /* 1E */
    u8  channelNoB : 4;
    u8  pad1F;
    u32 frequency;              /* 20 */
    u32 frequencyOffsetB;       /* 24: added to frequency for channel B */
    u8  pan;                    /* 28 */
    u32 dual;                   /* 2C: 1 when two channels play the wave */
    u32 ownsBuffer;             /* 30: 1 when the buffer was allocated by PM_VOICE_AllocBuffers */
};

/* Voice mixer state at 0x02140484. */
struct PmVoiceSystem {
    u16 heapId;                 /* 00 */
    u16 pad02;
    struct PmVoice voices[PM_VOICE_SLOT_COUNT]; /* 04 */
    u16 current;                /* A0: slot the next voice takes */
    u16 count;                  /* A2: slots in use */
    void (*resolveCallback)(u32 species, u32 form, u32 *waveId); /* A4 */
    u32 (*prepareCallback)(u32 species, u32 form, void **recordedVoice,
                           u8 **data, u32 *dataSize, u32 *sampleRate,
                           u32 *frequency, s8 *volume);          /* A8 */
    u8  masterVolume;           /* AC */
};

typedef void (*MICCallback)(u32 result, void *arg);

/* The microphone sampling request (the SDK's MICAutoParam). */
struct MICAutoParam {
    u32 type;
    void *buffer;
    u32 size;
    u32 rate;
    u32 loop_enable;
    MICCallback full_callback;
    void *full_arg;
};

/* Microphone work area (0x28 bytes) allocated by SND_MIC_Init. */
struct SndMic {
    struct MICAutoParam param;  /* 00 */
    u32 sampling;               /* 1C: set once sampling was requested */
    union {                     /* 20 */
        u32 word;
        struct {
            u32 recording : 1;
            u32 elapsed : 31;   /* ticks recorded so far */
        } bits;
    } status;
    void *sampleBuffer;         /* 24 */
};

/* Calls into the sound library and the sound archive reader (ARM code). */
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
extern void  NNS_SndHandleInit(struct SndHandle *handle);
extern u16   NNS_SndPlayerGetActiveSeqCount(u32 playerNo);
extern void  NNS_SndArcSetReadChunkSize(int loadFlags);
extern void  OS_Sleep(u32 msec);
extern struct SndArcSeqEntry  *NNS_SndArcGetSeqInfo(int seqNo);
extern struct SndArcBankEntry *NNS_SndArcGetBankInfo(int bankNo);
extern struct SndArcWaveArcEntry *NNS_SndArcGetWaveArcInfo(int waveArcNo);
extern u8   *NNS_SndArcGetSeqParam(int seqNo);
extern u32   NNS_SndArcPlayerStartSeq(struct SndHandle *handle, u32 seqNo);
extern u32   NNS_SndArcPlayerStartSeqEx(struct SndHandle *handle, int playerNo, int bankNo, int priority, u32 seqNo);
extern u32   NNS_SndArcLoadSeqEx(u32 seqNo, u32 loadFlags, struct SndHeap *heap);
extern u32   NNS_SndArcLoadWaveArc(u32 waveArcNo, struct SndHeap *heap);
extern void  NNS_SndArcSetFileAddress(u32 fileId, u32 address);
extern u32   NNS_SndArcGetFileAddress(u32 fileId);
extern void  SND_SetWaveDataAddress(u32 *waveArc, u32 waveIndex, u32 address);
extern u32   SND_GetWaveDataAddress(u32 waveArc, u32 waveIndex);
extern void  OS_CreateThread(u32 *thread, void (*entry)(void *), void *arg,
                           u32 *stack, u32 size, u32 prio);
extern void  OS_WakeupThreadDirect(u32 *thread);
extern void  OS_DestroyThread(void *thread);
extern int   OS_IsThreadTerminated(void *thread);

/* Calls into gfl_use.c (sound heap stack). */
extern u16   GFL_USE_GetCurrentBgmId(void);
extern struct SndHandle *GFL_USE_GetCurrentSndHandle(void);
extern int   GFL_USE_LoadBgmData(u32 bgmNo);
extern void  GFL_USE_UnloadBgmData(void);
extern void  GFL_USE_SaveSeqBankState(void);
extern int   GFL_USE_FinishBgmLoad(u32 bgmNo);
extern int   GFL_USE_PushSndSlot(void);
extern int   GFL_USE_GetSndStackDepth(void);
extern int   GFL_USE_PopSndSlot(void);

/* Calls into the voice channel layer and the other data readers. */
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern void  func_020307B0(void *block);
extern int   NNS_SndWaveOutIsPlaying(struct SndChannel *channel);
extern struct SndChannel *NNS_SndWaveOutAllocChannel(u32 channelNo);
extern int   NNS_SndWaveOutStart(struct SndChannel *channel, u32 format, void *data,
                           u32 loopFlag, u32 start, u32 end, u32 sampleRate,
                           u8 volume, u32 frequency, u8 pan);
extern u32   NNS_SndArcGetFileSize(u32 fileId);
extern int   NNS_SndArcReadFile(u32 fileId, void *dst, int length, u32 offset);
extern void *SNDi_GetBankWaveArcTable(char *file);
extern void  NNS_SndWaveOutStop(struct SndChannel *channel);
extern void  NNS_SndWaveOutWaitIdle(struct SndChannel *channel);
extern void  NNSi_SndWaveOutUnlockChannel(struct SndChannel *channel);
extern void  NNS_SndWaveOutSetVolume(struct SndChannel *channel, u32 volume);
extern void  NNS_SndWaveOutSetSpeed(struct SndChannel *channel, u32 frequency);
extern u32   func_020056EC(u32 limit);
extern u32   func_02007B50(void *perapVoice);
extern u8   *func_02007B64(struct PerapVoice *perapVoice);
extern void  func_02007B68(void *dst, const void *src);
extern void  ARC_TOOL_ReadMember(void *dst, u32 archiveId, u32 member);
extern struct SaveData  *func_020070A4(void);
extern struct SaveBlock *func_02007B44(struct SaveData *saveData);
extern void  MI_CpuFill8(void *p, u32 value, u32 size);
extern unsigned int PM_SetAmp(unsigned int on);
extern unsigned int PM_SetAmpGain(unsigned int gain);
extern void  MIC_Init(void);
extern int   OS_IsRunOnTwl(void);
extern void  SNDEXi_SetIirFilter(u32 index, u8 *coefficients);
extern u32   MIC_AdjustLimitedSampling(const struct MICAutoParam *param);
extern void  func_02007BD0(struct PerapVoice *perapVoice, const void *src);


/* voice mixer */
void PM_VOICE_Init(u16 heapId,
                   void (*resolveCallback)(u32 species, u32 form, u32 *waveId),
                   u32 (*prepareCallback)(u32 species, u32 form, void **recordedVoice,
                                          u8 **data, u32 *dataSize, u32 *sampleRate,
                                          u32 *frequency, s8 *volume));
void PM_VOICE_StopAll(void);
void PM_VOICE_StopFinished(void);
int PM_VOICE_IsAnyActive(void);
void PM_VOICE_AllocBuffers(int extraVoices, u32 heapId);
void PM_VOICE_FreeBuffers(void);
void PM_VOICE_SetMasterVolume(u8 volume);
void PM_VOICE_ResetMasterVolume(void);
u8 PM_VOICE_ScaleVolume(u8 volume);
u16 PM_VOICE_NextSlot(void);
void PM_VOICE_ResetParams(struct PmVoice *voice);
void PM_VOICE_ClearSlot(struct PmVoice *voice);
int PM_VOICE_LoadWave(struct PmVoice *voice, u32 waveId);
int PM_VOICE_StartChannels(struct PmVoice *voice);
void PM_VOICE_Stop(struct PmVoice *voice);
u32 PM_VOICE_Play(u32 species, u32 form, u32 pan, u32 dual,
                  u32 volumeBiasB, u32 frequencyOffsetB, u32 reverse, void **recordedVoice);
int PM_VOICE_Prepare(int species, int form, int pan, int dual,
                  int volumeBiasB, int frequencyOffsetB, int reverse, void **recordedVoice);
int PM_VOICE_Start(u32 slot);
void PM_VOICE_AddVolume(u32 slot, int delta);
void PM_VOICE_AddFrequency(u32 slot, u32 delta);
s8 PM_VOICE_GetVolume(u32 slot);
u32 PM_VOICE_GetFrequency(u32 slot);
u8 *PM_VOICE_GetData(u32 slot);
u32 PM_VOICE_GetDataSize(u32 slot);
u32 PM_VOICE_GetSampleRate(u32 slot);
void PM_VOICE_StopSlot(u32 slot);
u32 PM_VOICE_IsSlotActive(u32 slot);
void PM_VOICE_ReverseBytes(u8 *bytes, u32 count);
void PM_VOICE_GetCryIndex(u32 species, u32 form, u32 *cryIndex);
u32 PM_VOICE_PrepareCry(u32 species, u32 form, void **recordedVoice, u8 **data,
                  u32 *dataSize, u32 *sampleRate, u32 *frequency, s8 *volume);
void PM_VOICE_GetPerapVoiceSave(struct SaveBlock **out);

/* microphone (snd_mic.c part of this file) */
void SND_MIC_Init(u16 heapId);
void SND_MIC_Exit(void);
void SND_MIC_AddElapsed(u32 ticks);
u32 SND_MIC_IsLimitReached(void);
u32 SND_MIC_StartSampling(const struct MICAutoParam *param);
u32 SND_MIC_StartRecording(MICCallback callback, void *arg);
void SND_MIC_StoreRecording(struct PerapVoice *perapVoice);
void *SND_MIC_GetBufferAligned(void);

extern struct PmVoiceSystem _VoiceSystem;
extern u8 _VoiceBuffer0[];
extern struct PmVoiceChannelPair _VoiceChannelTable[];
extern const char _PmVoiceFile[];
extern char _SndMicFile[];
extern u8 _MicIirFilter[];
extern struct SndMic *_SndMic;

/*
 * Set up the voice mixer: remember the heap and the two callbacks, put the
 * master volume to maximum, and for each of the three 0x34 byte voices
 * clear the active word, copy the two 4-bit channel numbers out of the
 * halfword table (they are adjacent u8 bitfields, hence the narrowing to 8
 * bits), and reset the voice. Voice 0 also gets the static buffer as its
 * buffer and its sample data pointer. One voice is in use afterwards.
 */
void PM_VOICE_Init(u16 heapId,
                   void (*resolveCallback)(u32 species, u32 form, u32 *waveId),
                   u32 (*prepareCallback)(u32 species, u32 form, void **recordedVoice,
                                          u8 **data, u32 *dataSize, u32 *sampleRate,
                                          u32 *frequency, s8 *volume))
{
    struct PmVoice *voice;
    int i;

    _VoiceSystem.heapId = heapId;
    _VoiceSystem.masterVolume = SND_VOLUME_MAX;
    for (i = 0; i < PM_VOICE_SLOT_COUNT; i++) {
        voice = &_VoiceSystem.voices[i];
        voice->active = 0;
        voice->channelNoA = (u8)_VoiceChannelTable[i].channelA;
        voice->channelNoB = (u8)_VoiceChannelTable[i].channelB;
        PM_VOICE_ClearSlot(voice);
        if (i == 0) {
            voice->buffer = _VoiceBuffer0;
            voice->data = _VoiceBuffer0;
        }
    }
    _VoiceSystem.count = 1;
    _VoiceSystem.current = 0;
    _VoiceSystem.resolveCallback = resolveCallback;
    _VoiceSystem.prepareCallback = prepareCallback;
}

/* Stop every voice that is active. */
void PM_VOICE_StopAll(void)
{
    int i;

    for (i = 0; i < PM_VOICE_SLOT_COUNT; i++) {
        struct PmVoice *voice = &_VoiceSystem.voices[i];

        if (voice->active == 1) {
            PM_VOICE_Stop(voice);
        }
    }
}

/* Stop the voices whose hardware channels have gone silent. */
void PM_VOICE_StopFinished(void)
{
    struct PmVoice *voice;
    int i;
    u32 busyA;
    u32 busyB;

    for (i = 0; i < _VoiceSystem.count; i++) {
        voice = &_VoiceSystem.voices[i];
        if (voice->active == 1) {
            busyA = NNS_SndWaveOutIsPlaying(voice->channelA);
            if (voice->dual == 1) {
                busyB = NNS_SndWaveOutIsPlaying(voice->channelB);
            } else {
                busyB = 0;
            }
            if (busyA == 0 && busyB == 0) {
                PM_VOICE_Stop(voice);
            }
        }
    }
}

int PM_VOICE_IsAnyActive(void)
{
    int i;

    for (i = 0; i < PM_VOICE_SLOT_COUNT; i++) {
        if (_VoiceSystem.voices[i].active == 1) {
            return 1;
        }
    }
    return 0;
}

/*
 * Allocate a 0x5C30 byte buffer for each of up to two extra voices (voice 0
 * keeps the static buffer). The site string passed to the allocator is the
 * file name "pm_voice.c" with line 0x105.
 */
void PM_VOICE_AllocBuffers(int extraVoices, u32 heapId)
{
    struct PmVoice *voice;
    int i;

    PM_VOICE_StopAll();
    if (extraVoices > 2) {
        extraVoices = 2;
    }
    for (i = 1; i < extraVoices + 1; i++) {
        voice = &_VoiceSystem.voices[i];
        if (voice->buffer == 0) {
            void *block = func_02030734(heapId, PM_VOICE_BUFFER_SIZE, 1, _PmVoiceFile, 0x105);

            voice->buffer = block;
            voice->data = block;
            voice->ownsBuffer = 1;
        }
    }
    _VoiceSystem.count = extraVoices + 1;
    _VoiceSystem.current = 0;
}

/* Stop all voices and free the buffers that were allocated. */
void PM_VOICE_FreeBuffers(void)
{
    struct PmVoice *voice;
    int i;

    PM_VOICE_StopAll();
    for (i = 0; i < _VoiceSystem.count; i++) {
        voice = &_VoiceSystem.voices[i];
        if (voice->buffer != 0 && voice->ownsBuffer == 1) {
            func_020307B0(voice->buffer);
            PM_VOICE_ClearSlot(voice);
        }
    }
    _VoiceSystem.count = 1;
    _VoiceSystem.current = 0;
}

void PM_VOICE_SetMasterVolume(u8 volume)
{
    _VoiceSystem.masterVolume = volume;
}

void PM_VOICE_ResetMasterVolume(void)
{
    _VoiceSystem.masterVolume = SND_VOLUME_MAX;
}

/*
 * Scale a volume by the master volume. Both operands promote to int, so the
 * signed division helper (_s32_div_f) is called.
 */
u8 PM_VOICE_ScaleVolume(u8 volume)
{
    return (u8)(volume * _VoiceSystem.masterVolume / SND_VOLUME_MAX);
}

/* Round robin: stop the voice in the current slot, advance, return the slot. */
u16 PM_VOICE_NextSlot(void)
{
    struct PmVoice *voice;
    u16 slot;

    slot = _VoiceSystem.current;
    voice = &_VoiceSystem.voices[slot];
    if (voice->active == 1) {
        PM_VOICE_Stop(voice);
    }
    if (_VoiceSystem.current < _VoiceSystem.count - 1) {
        _VoiceSystem.current = _VoiceSystem.current + 1;
    } else {
        _VoiceSystem.current = 0;
    }
    return slot;
}

/* Back to the idle parameters; the buffer stays. */
void PM_VOICE_ResetParams(struct PmVoice *voice)
{
    voice->dataSize = 0;
    voice->volume = 0;
    voice->volumeBiasB = 0;
    voice->frequencyOffsetB = 0;
    voice->sampleRate = PM_VOICE_DEFAULT_SAMPLE_RATE;
    voice->frequency = PM_VOICE_DEFAULT_FREQUENCY;
    voice->pan = 0x40;
    voice->dual = 0;
    voice->data = voice->buffer;
}

/* Forget the buffer too, then reset the parameters (a two store tail call). */
void PM_VOICE_ClearSlot(struct PmVoice *voice)
{
    voice->buffer = 0;
    voice->ownsBuffer = 0;
    PM_VOICE_ResetParams(voice);
}

/*
 * Load a wave into a voice: look up the wave archive entry for `waveId`,
 * read its file into the voice's buffer (the read must return exactly the
 * file size), then fill in the playback fields from the wave record the file
 * header points at.
 *
 * The frequency is a 64 bit division chained twice, 0x7FD87F8000 /
 * sampleRate / timer (the constant is 16756991 * 0x8000, half the DS system
 * clock times 0x8000); only its low word is in a literal pool because the
 * high word 0x7F fits a movs.
 */
int PM_VOICE_LoadWave(struct PmVoice *voice, u32 waveId)
{
    struct SndArcWaveArcEntry *entry;
    struct PmWaveFile *file;
    struct PmWave *wave;
    u32 fileSize;
    u32 waveBytes;
    int bytesRead;

    entry = NNS_SndArcGetWaveArcInfo(waveId);
    if (entry == 0) {
        return 0;
    }
    fileSize = NNS_SndArcGetFileSize(entry->fileId);
    if (fileSize == 0) {
        return 0;
    }
    bytesRead = NNS_SndArcReadFile(entry->fileId, voice->buffer, fileSize, 0);
    if (bytesRead == -1) {
        return 0;
    }
    if (bytesRead != fileSize) {
        return 0;
    }
    file = voice->buffer;
    wave = (struct PmWave *)((u8 *)file + file->waveOffset);
    SNDi_GetBankWaveArcTable((char *)file);
    waveBytes = file->fileSize - file->waveOffset;
    voice->data = (u8 *)wave + 0xC;
    voice->dataSize = waveBytes - 0xC;
    voice->sampleRate = wave->sampleRate;
    voice->frequency = (u32)(0x7FD87F8000ULL / wave->sampleRate / wave->timer);
    return 1;
}

/*
 * Open one or two hardware channels for the voice and mark it active.
 * Channel A plays at the voice volume, channel B (when dual is 1) at
 * volume + volumeBiasB clamped to 0..0x7F and frequency + frequencyOffsetB.
 * The two channel numbers are the two 4-bit fields of the byte at +0x1E,
 * read with lsls #0x1C / lsrs #0x1C and lsls #0x18 / lsrs #0x1C.
 */
int PM_VOICE_StartChannels(struct PmVoice *voice)
{
    int volumeB;

    if (voice->buffer == 0) {
        return 0;
    }
    if (voice->dataSize == 0) {
        return 0;
    }
    voice->channelA = NNS_SndWaveOutAllocChannel(voice->channelNoA);
    if (voice->channelA == 0) {
        return 0;
    }
    if (NNS_SndWaveOutStart(voice->channelA, 0, voice->data, 0, 0, voice->dataSize,
                      voice->sampleRate, PM_VOICE_ScaleVolume(voice->volume),
                      voice->frequency, voice->pan) == 0) {
        return 0;
    }
    if (voice->dual == 1) {
        voice->channelB = NNS_SndWaveOutAllocChannel(voice->channelNoB);
        if (voice->channelB == 0) {
            return 0;
        }
        volumeB = voice->volume + voice->volumeBiasB;
        if (volumeB < 0) {
            volumeB = 0;
        }
        if (volumeB > SND_VOLUME_MAX) {
            volumeB = SND_VOLUME_MAX;
        }
        if (NNS_SndWaveOutStart(voice->channelB, 0, voice->data, 0, 0, voice->dataSize,
                          voice->sampleRate, PM_VOICE_ScaleVolume((u8)volumeB),
                          voice->frequency + voice->frequencyOffsetB,
                          voice->pan) == 0) {
            return 0;
        }
    }
    voice->active = 1;
    return 1;
}

/*
 * Stop a voice: stop the channel timer, wait for the channel to go idle and
 * free it, the same three calls on channel B when dual, then clear the active
 * word and reset the parameters. The channel field is read again before each
 * call because the callees are extern and may write it back.
 */
void PM_VOICE_Stop(struct PmVoice *voice)
{
    NNS_SndWaveOutStop(voice->channelA);
    NNS_SndWaveOutWaitIdle(voice->channelA);
    NNSi_SndWaveOutUnlockChannel(voice->channelA);
    if (voice->dual == 1) {
        NNS_SndWaveOutStop(voice->channelB);
        NNS_SndWaveOutWaitIdle(voice->channelB);
        NNSi_SndWaveOutUnlockChannel(voice->channelB);
    }
    voice->active = 0;
    PM_VOICE_ResetParams(voice);
}

/*
 * Prepare and start a voice. Eight parameters: four in registers and four in
 * the caller's frame, which are copied down into the outgoing argument area.
 * While the BGM loader thread runs the call sleeps 2 ms at a time; the wait
 * loop is an `if` around a `do`/`while` because `v = 2` is emitted after the
 * first test and the back edge skips it. The sleep time and the slot share
 * one local.
 */
u32 PM_VOICE_Play(u32 species, u32 form, u32 pan, u32 dual,
                  u32 volumeBiasB, u32 frequencyOffsetB, u32 reverse,
                  void **recordedVoice)
{
    u32 slot;

    if (GFL_USE_IsLoaderBusy() == 1) {
        slot = 2;
        do {
            OS_Sleep(slot);
        } while (GFL_USE_IsLoaderBusy() == 1);
    }
    slot = (u16)PM_VOICE_Prepare(species, form, pan, dual, volumeBiasB,
                              frequencyOffsetB, reverse, recordedVoice);
    PM_VOICE_Start(slot);
    return slot;
}

/*
 * Take the next voice slot and load a wave into it. The resolve callback
 * turns (species, form) into a wave id; the prepare callback may supply the
 * sample data itself (returning nonzero), otherwise the wave file is loaded.
 * `reverse` reverses the sample bytes in place (backwards playback). The
 * remaining parameters are stored in the voice.
 *
 * The state is an extern struct whose callback slots are called through the
 * fields. The index goes through a stack slot because it is the return value.
 */
int PM_VOICE_Prepare(int species, int form, int pan, int dual,
                  int volumeBiasB, int frequencyOffsetB, int reverse,
                  void **recordedVoice)
{
    u32 waveId;
    int slot;
    struct PmVoice *voice;

    _VoiceSystem.resolveCallback(species, form, &waveId);
    slot = PM_VOICE_NextSlot();
    voice = &_VoiceSystem.voices[slot];
    if (voice->active == 1)
        PM_VOICE_Stop(voice);
    if (_VoiceSystem.prepareCallback(species, form, recordedVoice, &voice->data,
                                     &voice->dataSize, &voice->sampleRate,
                                     &voice->frequency, &voice->volume) == 0)
        PM_VOICE_LoadWave(voice, waveId);
    if (reverse != 0)
        PM_VOICE_ReverseBytes(voice->data, voice->dataSize);
    voice->pan = pan;
    voice->dual = dual;
    voice->volumeBiasB = volumeBiasB;
    voice->frequencyOffsetB = frequencyOffsetB;
    return slot;
}

/*
 * Start the voice in `slot`; when the channels cannot be opened free the
 * slot and return 0. The slot address is spelled twice, once per call.
 */
int PM_VOICE_Start(u32 slot)
{
    if (PM_VOICE_StartChannels(&_VoiceSystem.voices[slot]) == 0) {
        PM_VOICE_Stop(&_VoiceSystem.voices[slot]);
        return 0;
    }
    return 1;
}

/*
 * Add a signed delta to the volume of a voice. The volume is an s8 (ldrsb
 * loads), clamped to [0, 0x7F] by two separate ifs on the int sum. With
 * dual channels the second volume is the sum with volumeBiasB, clamped the
 * same way and re-narrowed to a byte for the call. Both volume updates go to
 * channelA (as in the original).
 */
void PM_VOICE_AddVolume(u32 slot, int delta)
{
    struct PmVoice *voice;
    int volume;

    voice = &_VoiceSystem.voices[slot];
    if (voice->active == 0) {
        return;
    }
    volume = voice->volume + delta;
    if (volume < 0) {
        volume = 0;
    }
    if (volume > SND_VOLUME_MAX) {
        volume = SND_VOLUME_MAX;
    }
    voice->volume = volume;
    NNS_SndWaveOutSetVolume(voice->channelA, PM_VOICE_ScaleVolume(voice->volume));
    if (voice->dual == 1) {
        volume = voice->volume + voice->volumeBiasB;
        if (volume < 0) {
            volume = 0;
        }
        if (volume > SND_VOLUME_MAX) {
            volume = SND_VOLUME_MAX;
        }
        NNS_SndWaveOutSetVolume(voice->channelA, PM_VOICE_ScaleVolume((u8)volume));
    }
}

/*
 * Add `delta` to the frequency of a voice. The sum is stored first and the
 * stored value is passed to the first call; the second call re-reads the
 * frequency and adds the channel B offset.
 */
void PM_VOICE_AddFrequency(u32 slot, u32 delta)
{
    struct PmVoice *voice;
    u32 frequency;

    voice = &_VoiceSystem.voices[slot];
    if (voice->active == 0) {
        return;
    }
    frequency = voice->frequency + delta;
    voice->frequency = frequency;
    NNS_SndWaveOutSetSpeed(voice->channelA, frequency);
    if (voice->dual == 1) {
        NNS_SndWaveOutSetSpeed(voice->channelB, voice->frequency + voice->frequencyOffsetB);
    }
}

/*
 * Getters over the 0x34 byte voice records; most return an idle value for a
 * voice that is not active. None of them saves a register, so the listing
 * does not label them. The index arithmetic is a `muls` by 0x34 (not a
 * power of two). PM_VOICE_GetVolume reads the s8 volume with a register offset
 * ldrsb, the evidence that the field is signed. PM_VOICE_StopSlot computes the
 * slot address only inside the if, where the other functions compute it
 * before the test.
 */
s8 PM_VOICE_GetVolume(u32 slot)
{
    struct PmVoice *voice = &_VoiceSystem.voices[slot];

    if (voice->active == 0) {
        return 0;
    }
    return voice->volume;
}

u32 PM_VOICE_GetFrequency(u32 slot)
{
    struct PmVoice *voice = &_VoiceSystem.voices[slot];

    if (voice->active == 0) {
        return PM_VOICE_DEFAULT_FREQUENCY;
    }
    return voice->frequency;
}

u8 *PM_VOICE_GetData(u32 slot)
{
    struct PmVoice *voice = &_VoiceSystem.voices[slot];

    if (voice->active == 0) {
        return 0;
    }
    return voice->data;
}

u32 PM_VOICE_GetDataSize(u32 slot)
{
    struct PmVoice *voice = &_VoiceSystem.voices[slot];

    if (voice->active == 0) {
        return 0;
    }
    return voice->dataSize;
}

u32 PM_VOICE_GetSampleRate(u32 slot)
{
    struct PmVoice *voice = &_VoiceSystem.voices[slot];

    if (voice->active == 0) {
        return PM_VOICE_DEFAULT_SAMPLE_RATE;
    }
    return voice->sampleRate;
}

void PM_VOICE_StopSlot(u32 slot)
{
    if (_VoiceSystem.voices[slot].active == 1) {
        PM_VOICE_Stop(&_VoiceSystem.voices[slot]);
    }
}

u32 PM_VOICE_IsSlotActive(u32 slot)
{
    return _VoiceSystem.voices[slot].active;
}

/* Reverse `count` bytes in place. */
void PM_VOICE_ReverseBytes(u8 *bytes, u32 count)
{
    u32 i;

    for (i = 0; i < count / 2; i++) {
        u8 tmp = bytes[i];

        bytes[i] = bytes[count - 1 - i];
        bytes[count - 1 - i] = tmp;
    }
}

/*
 * Index of the cry for a species and form: the species itself, except
 * species 492 form 1 which uses index 650. The first guard is
 * `species < 1 && species > 649`, a conjunction: for unsigned operands it
 * can never be true, so the `*cryIndex = 1` arm is dead code, but the bytes
 * say so (`cmp r0, #1` / `bhs` and `cmp r0, r3` / `bls` both branch past
 * it). Written with `||` the two branches invert.
 */
void PM_VOICE_GetCryIndex(u32 species, u32 form, u32 *cryIndex)
{
    if (species < 1 && species > 649) {
        *cryIndex = 1;
        return;
    }
    if (species == 492 && form == 1) {
        *cryIndex = 650;
        return;
    }
    *cryIndex = species;
}

/*
 * Cry parameters for a species. ARC_TOOL_ReadMember copies one 4-byte record of
 * archive 194 (a/1/9/4, 652 records) into `record`; its second halfword's
 * low byte is the cry volume (97 to 127). Species 441 (Chatot) is the one
 * cry that is a recorded sample: when the recording exists, its 8180 bytes
 * are copied into the voice's sample data, the sample rate is 0x1FF4, the
 * volume 120 and the frequency a random value in 0x8000..0xA000. Returns 1
 * when the sample was supplied, otherwise 0 and the wave file is loaded.
 * The literal 441 is rematerialised as 194 + 247 off the register that
 * holds the archive id. Content constants (441, 652) are Black-image values.
 */
u32 PM_VOICE_PrepareCry(u32 species, u32 form, void **recordedVoice, u8 **data,
                  u32 *dataSize, u32 *sampleRate, u32 *frequency, s8 *volume)
{
    u16 record[2];

    ARC_TOOL_ReadMember(record, 194, species);
    *volume = (s8)record[1];
    if (recordedVoice == 0) {
        return 0;
    }
    if (species == 441 && form == 0 && func_02007B50(recordedVoice[0]) == 1) {
        func_02007B68(data[0], func_02007B64(recordedVoice[0]));
        *dataSize = 0x1FF4;
        *sampleRate = 0x1FF4;
        *volume = 0x78;
        *frequency = func_020056EC(0x2000) + 0x8000;
        return 1;
    }
    return 0;
}

/*
 * Save block with the recorded voice. func_020070A4 is a lazily initialised
 * singleton getter, never reading r0, so the call is nested and the result
 * of func_02007B44 is stored through the argument.
 */
void PM_VOICE_GetPerapVoiceSave(struct SaveBlock **out)
{
    *out = func_02007B44(func_020070A4());
}

/*
 * Allocate the microphone work area (0x28 bytes) and its 0x2014 byte sample
 * buffer, both with the file name "snd_mic.c" as the site (lines 0x59 and
 * 0x5f). The buffer is linked in at +0x24 before the hardware is set up:
 * amplifier on with gain 2, microphone init, and on a DSi the IIR filter
 * table. The recording bit is cleared and set again (bics for the clear).
 */
void SND_MIC_Init(u16 heapId)
{
    struct SndMic *mic;
    void *sampleBuffer;

    mic = func_02030734(heapId, 0x28, 0, _SndMicFile, 0x59);
    MI_CpuFill8(mic, 0, 0x28);
    sampleBuffer = func_02030734(heapId, 0x2014, 0, _SndMicFile, 0x5f);
    MI_CpuFill8(sampleBuffer, 0, 0x2014);
    mic->sampleBuffer = sampleBuffer;
    PM_SetAmp(1);
    PM_SetAmpGain(2);
    mic->status.word = (mic->status.word & ~1u) | 1u;
    MIC_Init();
    if (OS_IsRunOnTwl() == 1) {
        SNDEXi_SetIirFilter(0, _MicIirFilter);
    }
    _SndMic = mic;
}

/*
 * Tail of the microphone code. The word at +0x20 is two bitfields (bit 0 and
 * a 31 bit counter), and all of D44..D94 turn on that declaration: the
 * counter is read with a bare `lsrs r0, r0, #1` (correct only because the
 * field runs to the top of the word) and written back with a read modify
 * write that keeps bit 0; the one bit is tested with lsls #0x1f / lsrs #0x1f.
 * The range starts at 0x02006D44 because 0x02006D3C is a linker veneer
 * (ldr pc, [pc, #-4]) over 0x027047C0.
 */
void SND_MIC_Exit(void)
{
    PM_SetAmp(0);
    func_020307B0(_SndMic->sampleBuffer);
    func_020307B0(_SndMic);
}

/* Add `ticks` to the recorded time while recording and below the limit. */
void SND_MIC_AddElapsed(u32 ticks)
{
    struct SndMic *mic = _SndMic;

    if (mic->status.bits.recording) {
        if (SND_MIC_IsLimitReached() == 0) {
            mic->status.bits.elapsed += ticks;
        }
    }
}

/* 1 once more than 180 ticks were recorded. */
u32 SND_MIC_IsLimitReached(void)
{
    if (_SndMic->status.bits.elapsed > 0xB4) {
        return 1;
    }
    return 0;
}

/*
 * Start sampling with a request (the SDK call is MIC_StartLimitedSampling)
 * and keep a copy of the request. The global pointer is read twice, once for
 * the flag word and once for the copy, because the store through the first
 * load can alias the pointer itself. The copy is the unrolled aggregate
 * assignment of the seven word request (three ldm/stm pairs and a trailing
 * ldr/str).
 */
u32 SND_MIC_StartSampling(const struct MICAutoParam *param)
{
    u32 result = MIC_AdjustLimitedSampling(param);

    _SndMic->sampling = 1;
    _SndMic->param = *param;
    return result;
}

/*
 * Record into the work buffer with a full-buffer callback. The size is
 * rounded down to a multiple of 32 by a live test and mask (movs r0, #0x1f;
 * tst r0, r1; beq; movs r0, #0x1f; bics r1, r0): the mask is materialised
 * twice because Thumb has no immediate bic, and the compiler does not fold
 * it, so the guard is in the source.
 */
u32 SND_MIC_StartRecording(MICCallback callback, void *arg)
{
    struct MICAutoParam param;

    param.type = 2;
    param.buffer = SND_MIC_GetBufferAligned();
    param.size = 0x1FF4;
    if (param.size & 0x1F) {
        param.size &= ~0x1Fu;
    }
    param.rate = 0x1001;
    param.loop_enable = 0;
    param.full_callback = callback;
    param.full_arg = arg;
    return SND_MIC_StartSampling(&param);
}

/* Copy the recorded buffer into a Perap voice (Chatot) record. */
void SND_MIC_StoreRecording(struct PerapVoice *perapVoice)
{
    void *buffer = SND_MIC_GetBufferAligned();

    func_02007BD0(perapVoice, buffer);
}

/*
 * The sample buffer address rounded up to a multiple of 32. The mask is
 * materialised in r1 and applied with bics (Thumb has no immediate bic);
 * the compiler hoists the movs above both loads.
 */
void *SND_MIC_GetBufferAligned(void)
{
    return (void *)(((u32)_SndMic->sampleBuffer + 0x1F) & ~0x1Fu);
}
