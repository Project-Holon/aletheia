/*
 * file:     pm_voice.c
 * unit:     yes
 * function: func_02005BC0, sub_02005C18, func_02005C28, func_02005C3C, func_02005C44, func_02005C4C, func_02005C64, func_02005C8C, func_02005CA4, func_02005CBC, func_02005CE0, func_02005D08, func_02005D14, func_02005D28, func_02005D34, func_02005D90, func_02005DA4, func_02005DAC, func_02005DE4, func_02005DF8, func_02005E04, func_02005E30, func_02005E50, func_02005E64, func_02005E9C, func_02005EB4, func_02005EE0, func_02005F24, sub_02005F38, sub_02005F5C, sub_02005F70, sub_02005F90, func_02005FF4, func_02006118, func_02006138, func_02006148, func_0200616C, func_020061A4, func_020061E4, func_020061F0, func_020061F8, func_02006210, func_02006224, func_02006238, func_02006254, func_02006268, func_020062BC, func_02006300, func_02006368, func_02006394, func_020063B4, func_02006448, func_020064B8, func_020064F4, func_02006504, func_02006518, func_02006544, func_020065D8, func_020065FC, func_02006650, func_02006674, func_020066E8, func_02006734, func_02006740, func_0200674C, func_02006768, func_020067A4, func_020067D0, func_020067E0, func_02006868, func_02006948, func_02006984, func_020069D4, func_02006A64, func_02006A8C, func_02006AEC, func_02006B20, func_02006BB4, func_02006BD0, func_02006BE0, func_02006C00, func_02006C2C, func_02006CAC, func_02006CBC, sub_02006D44, sub_02006D64, sub_02006D94, func_02006DAC, func_02006DD8, func_02006E18, func_02006E2C
 * address:  0x02005BC0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from bgm_info.c at 0x02006E40 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   func_02072758  0x02072758  arm
 *   func_020727B4  0x020727B4  arm
 *   func_02073108  0x02073108  arm
 *   func_02074758       0x02074758  arm
 *   func_02072794  0x02072794  arm
 *   sub_020058D0  0x020058D0  thumb
 *   sub_0200590C  0x0200590C  thumb
 *   func_0208574C       0x0208574C  arm
 *   sub_020059C8        0x020059C8  thumb
 *   func_02072D98       0x02072D98  arm
 *   func_02072E7C       0x02072E7C  arm
 *   sub_02005924   0x02005924  thumb
 *   func_020755A8  0x020755A8  arm
 *   func_02072F5C       0x02072F5C  arm
 *   func_02072FA8  0x02072FA8  arm
 *   func_02072FC8  0x02072FC8  arm
 *   func_02073018  0x02073018  arm
 *   func_02073038  0x02073038  arm
 *   func_02073098  0x02073098  arm
 *   func_02072FE8  0x02072FE8  arm
 *   sub_02006368        0x02006368  thumb
 *   func_02072EE0       0x02072EE0  arm
 *   func_02072F34       0x02072F34  arm
 *   sub_0200597C        0x0200597C  thumb
 *   sub_020059A0        0x020059A0  thumb
 *   func_020746B0       0x020746B0  arm
 *   func_02072E9C       0x02072E9C  arm
 *   func_02085A38       0x02085A38  arm
 *   func_0207430C  0x0207430C  arm
 *   func_02075560       0x02075560  arm
 *   func_02072EC8  0x02072EC8  arm
 *   func_020853C0        0x020853C0  arm
 *   func_02074AC4        0x02074AC4  arm
 *   func_02085868        0x02085868  arm
 *   func_020855BC  0x020855BC  arm
 *   func_02074324  0x02074324  arm
 *   func_020743EC  0x020743EC  arm
 *   func_02074A98  0x02074A98  arm
 *   func_02074694  0x02074694  arm
 *   func_02074450  0x02074450  arm
 *   func_0207466C  0x0207466C  arm
 *   func_0208A640  0x0208A640  arm
 *   func_0208A674  0x0208A674  arm
 *   func_02030734       0x02030734  arm
 *   func_02072CC4       0x02072CC4  arm
 *   func_020307B0       0x020307B0  arm
 *   func_02072A44  0x02072A44  arm
 *   func_02072AA0  0x02072AA0  arm
 *   func_0207457C  0x0207457C  arm
 *   func_020745A4  0x020745A4  arm
 *   func_0208A638  0x0208A638  arm
 *   func_02072BDC  0x02072BDC  arm
 *   func_02072D20  0x02072D20  arm
 *   func_02072A88  0x02072A88  arm
 *   func_02072C18  0x02072C18  arm
 *   func_02072C40  0x02072C40  arm
 *   func_020056EC  0x020056EC  thumb
 *   func_02007B50  0x02007B50  thumb
 *   func_02007B64  0x02007B64  thumb
 *   func_02007B68  0x02007B68  thumb
 *   func_02048F4C  0x02048F4C  arm
 *   func_020070A4  0x020070A4  thumb
 *   func_02007B44  0x02007B44  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_0208BEF0  0x0208BEF0  arm
 *   func_0208BF38  0x0208BF38  arm
 *   func_0208B24C  0x0208B24C  arm
 *   func_02085D3C  0x02085D3C  arm
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
extern void  func_02072758(void);
extern u32   func_020727B4(void);
extern int   func_02073108(struct SndHandle *handle, int trackNo, struct SNDTrackInfo *trackInfo);
extern void  func_02074758(struct SndHeap *heap);
extern void  func_02072794(u32 monoFlag);
extern void  func_02072D98(u32 playerNo, u32 volume);
extern void  func_02072E7C(struct SndHandle *handle, int fadeFrames);
extern void  func_02072E8C(struct SndHandle *handle, u32 value);
extern void  func_02072F5C(struct SndHandle *handle, u32 volume, u32 frames);
extern void  func_02072F34(struct SndHandle *handle, int volume);
extern void  func_02072FA8(struct SndHandle *handle, u32 trackMask, u32 mute);
extern void  func_02072FC8(struct SndHandle *handle, u32 trackMask, u32 mute);
extern void  func_02072FE8(struct SndHandle *handle, u32 trackMask, int volumeIndex);
extern void  func_02073018(struct SndHandle *handle, u32 trackMask, u32 pitch);
extern void  func_02073038(struct SndHandle *handle, u32 trackMask, u32 pan);
extern void  func_02073058(struct SndHandle *handle, u32 trackMask, u32 depth);
extern void  func_02073078(struct SndHandle *handle, u32 trackMask, u32 speed);
extern void  func_02073098(struct SndHandle *handle, u32 tempoRatio);
extern s32   func_02072EE0(u32 seqNo);
extern void  func_02072E9C(struct SndHandle *handle);
extern u16   func_02072EC8(u32 playerNo);
extern void  func_020746B0(int loadFlags);
extern void  func_02085A38(u32 msec);
extern struct SndArcSeqEntry  *func_02074324(int seqNo);
extern struct SndArcBankEntry *func_020743EC(int bankNo);
extern struct SndArcWaveArcEntry *func_02074450(int waveArcNo);
extern u8   *func_0207430C(int seqNo);
extern u32   func_02075560(struct SndHandle *handle, u32 seqNo);
extern u32   func_020755A8(struct SndHandle *handle, int playerNo, int bankNo, int priority, u32 seqNo);
extern u32   func_02074AC4(u32 seqNo, u32 loadFlags, struct SndHeap *heap);
extern u32   func_02074A98(u32 waveArcNo, struct SndHeap *heap);
extern void  func_02074694(u32 fileId, u32 address);
extern u32   func_0207466C(u32 fileId);
extern void  func_0208A640(u32 *waveArc, u32 waveIndex, u32 address);
extern u32   func_0208A674(u32 waveArc, u32 waveIndex);
extern void  func_020853C0(u32 *thread, void (*entry)(void *), void *arg,
                           u32 *stack, u32 size, u32 prio);
extern void  func_02085868(u32 *thread);
extern void  func_020855BC(void *thread);
extern int   func_0208574C(void *thread);

/* Calls into gfl_use.c (sound heap stack). */
extern u16   sub_020058D0(void);
extern struct SndHandle *sub_0200590C(void);
extern int   sub_02005924(u32 bgmNo);
extern void  sub_020059C8(void);
extern void  sub_0200597C(void);
extern int   sub_020059A0(u32 bgmNo);
extern int   sub_02005A00(void);
extern int   sub_02005900(void);
extern int   sub_02005A4C(void);

/* Calls into the voice channel layer and the other data readers. */
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern void  func_020307B0(void *block);
extern int   func_02072CC4(struct SndChannel *channel);
extern struct SndChannel *func_02072A44(u32 channelNo);
extern int   func_02072AA0(struct SndChannel *channel, u32 format, void *data,
                           u32 loopFlag, u32 start, u32 end, u32 sampleRate,
                           u8 volume, u32 frequency, u8 pan);
extern u32   func_0207457C(u32 fileId);
extern int   func_020745A4(u32 fileId, void *dst, int length, u32 offset);
extern void *func_0208A638(char *file);
extern void  func_02072BDC(struct SndChannel *channel);
extern void  func_02072D20(struct SndChannel *channel);
extern void  func_02072A88(struct SndChannel *channel);
extern void  func_02072C18(struct SndChannel *channel, u32 volume);
extern void  func_02072C40(struct SndChannel *channel, u32 frequency);
extern u32   func_020056EC(u32 limit);
extern u32   func_02007B50(void *perapVoice);
extern u8   *func_02007B64(struct PerapVoice *perapVoice);
extern void  func_02007B68(void *dst, const void *src);
extern void  func_02048F4C(void *dst, u32 archiveId, u32 member);
extern struct SaveData  *func_020070A4(void);
extern struct SaveBlock *func_02007B44(struct SaveData *saveData);
extern void  func_02082BCC(void *p, u32 value, u32 size);
extern unsigned int func_0208BEF0(unsigned int on);
extern unsigned int func_0208BF38(unsigned int gain);
extern void  func_0208B24C(void);
extern int   func_02085D3C(void);
extern void  SNDEXi_SetIirFilter(u32 index, u8 *coefficients);
extern void  PM_SetAmp(u32 on);
extern u32   MIC_AdjustLimitedSampling(const struct MICAutoParam *param);
extern void  func_02007BD0(struct PerapVoice *perapVoice, const void *src);

/* sound manager (continues the code of gfl_use.c) */
void func_02005BC0(void);
void sub_02005C18(void);
void func_02005C28(u32 mode);
struct SndHandle *sub_02005C3C(void);
u16 sub_02005C44(void);
u32 sub_02005C4C(void);
int sub_02005C64(void);
int sub_02005C8C(void);
void sub_02005CA4(int enable, u32 playerMask);
void sub_02005CBC(u32 volume, u32 playerMask);
int sub_02005CE0(u32 seqNo);
void sub_02005D08(int (*filter)(u32 seqNo));
void sub_02005D14(void);
void sub_02005D28(void);
u32 func_02005D34(u32 bgmNo, u32 trackMask);
void ArrayDeleteAt(u32 bgmNo, u32 trackMask);
void func_02005DA4(unsigned int bgmNo, unsigned short trackMask, int fadeOutFrames, int fadeInFrames);
void sub_02005DAC(u32 seqNo);
void func_02005DE4(u32 value);
void sub_02005DF8(u32 frames);
void sub_02005E04(u32 frames, u32 volume);
void sub_02005E30(u32 frames);
int sub_02005E50(void);
int func_02005E64(void);
int func_02005E9C(void);
void func_02005EB4(u32 trackMask);
void sub_02005EE0(u32 trackMask, u32 tempoRatio, u32 pitch, u32 pan);
void func_02005F24(u32 trackMask, u32 volumeIndex);
int sub_02005F38(void);
void sub_02005F5C(void);
void sub_02005F70(u32 bgmNo, u16 trackMask, int fadeOutFrames, int fadeInFrames);
void sub_02005F90(void);
void sub_02005FBC(void);
void sub_02005FF4(void);
void sub_02006118(void);
struct SndHandle *sub_02006138(int slot);
int func_02006148(u32 seqNo);
void sub_0200616C(u32 seqNo, int slot);
void sub_020061A4(u32 seqNo, u32 volume);
void sub_020061E4(u32 seqNo);
void sub_020061F0(u32 seqNo, u32 volume);
void sub_020061F8(int slot);
void sub_02006210(void);
int func_02006224(u32 slot);
int sub_02006238(void);
int sub_02006254(u32 seqNo);
void sub_02006268(int slot, u32 tempoRatio, u32 pitch, u32 pan);
void sub_020062BC(int slot, u32 volume);
void sub_020062D8(void *arg);
void sub_020062EC(void *arg);
void sub_02006300(u32 bgmNo, int mode);
void func_02006368(void);
int sub_02006394(void);
u32 func_020063B4(u32 bgmNo, u32 *step, u32 abort);
int func_02006448(u32 seqAddr, u32 bankAddr, u32 bgmNo);
int sub_020064B8(u32 waveArcNo, u32 waveIndex, u32 srcWaveArc, u32 srcWaveIndex);
void sub_020064F4(u32 seqNo);
void sub_02006504(void);
void sub_02006518(void);

/* voice mixer */
void func_02006544(u16 heapId,
                   void (*resolveCallback)(u32 species, u32 form, u32 *waveId),
                   u32 (*prepareCallback)(u32 species, u32 form, void **recordedVoice,
                                          u8 **data, u32 *dataSize, u32 *sampleRate,
                                          u32 *frequency, s8 *volume));
void sub_020065D8(void);
void sub_020065FC(void);
int sub_02006650(void);
void sub_02006674(int extraVoices, u32 heapId);
void sub_020066E8(void);
void sub_02006734(u8 volume);
void sub_02006740(void);
u8 sub_0200674C(u8 volume);
u16 sub_02006768(void);
void sub_020067A4(struct PmVoice *voice);
void sub_020067D0(struct PmVoice *voice);
int sub_020067E0(struct PmVoice *voice, u32 waveId);
int sub_02006868(struct PmVoice *voice);
void func_02006948(struct PmVoice *voice);
u32 func_02006984(u32 species, u32 form, u32 pan, u32 dual,
                  u32 volumeBiasB, u32 frequencyOffsetB, u32 reverse, void **recordedVoice);
int func_020069D4(int species, int form, int pan, int dual,
                  int volumeBiasB, int frequencyOffsetB, int reverse, void **recordedVoice);
int func_02006A64(u32 slot);
void func_02006A8C(u32 slot, int delta);
void func_02006AEC(u32 slot, u32 delta);
s8 sub_02006B20(u32 slot);
u32 sub_02006B3C(u32 slot);
u8 *sub_02006B5C(u32 slot);
u32 sub_02006B78(u32 slot);
u32 sub_02006B94(u32 slot);
void sub_02006BB4(u32 slot);
u32 sub_02006BD0(u32 slot);
void sub_02006BE0(u8 *bytes, u32 count);
void sub_02006C00(u32 species, u32 form, u32 *cryIndex);
u32 func_02006C2C(u32 species, u32 form, void **recordedVoice, u8 **data,
                  u32 *dataSize, u32 *sampleRate, u32 *frequency, s8 *volume);
void sub_02006CAC(struct SaveBlock **out);

/* microphone (snd_mic.c part of this file) */
void func_02006CBC(u16 heapId);
void sub_02006D44(void);
void sub_02006D64(u32 ticks);
u32 sub_02006D94(void);
u32 sub_02006DAC(const struct MICAutoParam *param);
u32 sub_02006DD8(MICCallback callback, void *arg);
void func_02006E18(struct PerapVoice *perapVoice);
void *sub_02006E2C(void);

extern struct SndState _SndState;
extern struct SNDTrackInfo _SndTrackInfo[];
extern struct SeSlot _SeSlots[];
extern u32 _WorkerThread[];
extern u32 _SndHeapBuf[];
extern struct PmVoiceSystem _VoiceSystem;
extern u8 _VoiceBuffer0[];
extern struct PmVoiceChannelPair _VoiceChannelTable[];
extern const char _PmVoiceFile[];
extern char _SndMicFile[];
extern u8 _MicIirFilter[];
extern struct SndMic *_SndMic;

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
void func_02005BC0(void)
{
    struct SndHandle *handle;
    int trackNo;
    u32 remaining;

    sub_02005FF4();
    func_02072758();
    func_020727B4();
    handle = sub_02005C3C();
    _SndState.activeMask = 0;
    for (trackNo = 0; trackNo < 0x10; trackNo++) {
        if (func_02073108(handle, trackNo, &_SndTrackInfo[trackNo]) == 1) {
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
void sub_02005C18(void)
{
    func_02074758(_SndState.heap);
}

/*
 * The boolean replaces the parameter in r0, so the fall-through arm carries
 * the literal 1. A `v = 1; if (mode == 1) v = 0;` form allocates a second
 * register and moves every byte.
 */
void func_02005C28(u32 mode)
{
    func_02072794(mode != 1);
}

/* Two eight byte forwarders (ldr r3, [pc]; bx r3). */
struct SndHandle *sub_02005C3C(void)
{
    return sub_0200590C();
}

u16 sub_02005C44(void)
{
    return sub_020058D0();
}

/* BGM that is playing, or the one a pending change will start. */
u32 sub_02005C4C(void)
{
    if (_SndState.changeActive == 0) {
        return sub_020058D0();
    }
    return _SndState.changeBgm;
}

/* 1 while the loader thread was started and still runs. */
int sub_02005C64(void)
{
    if (_SndState.loaderThread == 0) {
        return 0;
    }
    if (func_0208574C(_WorkerThread) != 0) {
        return 0;
    }
    return 1;
}

/*
 * Reads the interrupt enable register (0x04000210) and reports bit 19, the
 * card transfer interrupt. The mask is built with movs/lsls, not loaded.
 */
int sub_02005C8C(void)
{
    if (*(volatile u32 *)0x04000210 & 0x80000) {
        return 1;
    }
    return 0;
}

/*
 * Full or zero volume for a set of the five players. sub_02005CA4 forwards
 * its second argument without touching it, and both arms call the same
 * function with a different first argument; computing the argument first
 * would fold the two calls into one and make the function shorter.
 */
void sub_02005CA4(int enable, u32 playerMask)
{
    if (enable == 1) {
        sub_02005CBC(SND_VOLUME_MAX, playerMask);
    } else {
        sub_02005CBC(0, playerMask);
    }
}

void sub_02005CBC(u32 volume, u32 playerMask)
{
    int playerNo;

    for (playerNo = 0; playerNo < 5; playerNo++) {
        if ((1 << playerNo) & playerMask) {
            func_02072D98(playerNo, volume);
        }
    }
}

/* Asks the start filter (when one is set) whether a sequence may start. */
int sub_02005CE0(u32 seqNo)
{
    if (sub_02005C64() == 0) {
        return 1;
    }
    if (_SndState.startFilter == 0) {
        return 0;
    }
    return _SndState.startFilter(seqNo);
}

void sub_02005D08(int (*filter)(u32 seqNo))
{
    _SndState.startFilter = filter;
}

/* Stop the BGM at once and drop its data from the sound heap. */
void sub_02005D14(void)
{
    func_02072E7C(sub_0200590C(), 0);
    sub_020059C8();
}

void sub_02005D28(void)
{
    sub_02005F90();
    sub_02005D14();
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
u32 func_02005D34(u32 bgmNo, u32 trackMask)
{
    u32 started;
    int zero;

    zero = 0;
    if (sub_02005CE0(bgmNo) == 0) {
        return 0;
    }
    sub_02005D14();
    if (sub_02005924(bgmNo) == 0) {
        return 0;
    }
    started = func_020755A8(sub_0200590C(), SND_PLAYER_BGM, -1, -1, bgmNo);
    if (started == 0) {
        return zero;
    }
    if (trackMask != 0xFFFF) {
        func_02005EB4(trackMask);
    }
    return started;
}

void ArrayDeleteAt(u32 bgmNo, u32 trackMask)
{
    sub_02005F90();
    func_02005D34(bgmNo, trackMask);
}

/* Starts a timed BGM change: the same four arguments as sub_02005F70. */
void func_02005DA4(unsigned int bgmNo, unsigned short trackMask,
                   int fadeOutFrames, int fadeInFrames)
{
    sub_02005F70(bgmNo, trackMask, fadeOutFrames, fadeInFrames);
}

/*
 * Play a sequence on the sixth player (fanfares) after dropping the BGM
 * data. Five-argument call whose fifth argument goes on the stack. The two
 * -1 arguments are derived from the 6 that was just materialised
 * (movs r1, #6; subs r2, r1, #7; adds r3, r2, #0), a peephole that says
 * nothing about the source.
 */
void sub_02005DAC(u32 seqNo)
{
    sub_02005F90();
    if (sub_02005CE0(seqNo) == 0) {
        return;
    }
    sub_02005D14();
    if (sub_02005924(seqNo) == 0) {
        return;
    }
    func_020755A8(sub_0200590C(), SND_PLAYER_FANFARE, -1, -1, seqNo);
}

void func_02005DE4(u32 value)
{
    sub_02005FBC();
    func_02072E8C(sub_0200590C(), value);
}

/* Fade in to full volume over `frames`. */
void sub_02005DF8(u32 frames)
{
    sub_02005E04(frames, SND_VOLUME_MAX);
}

/* Set the volume to zero, then fade up to `volume` over `frames`. */
void sub_02005E04(u32 frames, u32 volume)
{
    sub_02005FBC();
    func_02072F5C(sub_0200590C(), 0, 0);
    func_02072F5C(sub_0200590C(), volume, frames);
    _SndState.countdown = frames;
}

/* Fade out to zero over `frames`. */
void sub_02005E30(u32 frames)
{
    sub_02005FBC();
    func_02072F5C(sub_0200590C(), 0, frames);
    _SndState.countdown = frames;
}

/*
 * Boolean for `countdown != 0`: in Thumb a two exit branch shape, since
 * there is no conditional move.
 */
int sub_02005E50(void)
{
    return _SndState.countdown != 0;
}

/* Reset track mute and modulation, then push a level on the sound heap stack. */
int func_02005E64(void)
{
    sub_02005FBC();
    func_02072FA8(sub_0200590C(), SND_TRACKS_ALL, 0);
    func_02073058(sub_0200590C(), SND_TRACKS_ALL, 0);
    func_02073078(sub_0200590C(), SND_TRACKS_ALL, 0x10);
    return sub_02005A00();
}

/* Pop a level (stopping the BGM first) when the stack holds more than one. */
int func_02005E9C(void)
{
    int depth;

    sub_02005FBC();
    depth = sub_02005900();
    if (depth != 0) {
        sub_02005D14();
        return sub_02005A4C();
    }
    return depth;
}

/*
 * Leave only the tracks in `trackMask` audible: unmute everything, then mute
 * the complement. The complement is the one's complement truncated to 16
 * bits (lsls #16 / lsrs #16). 0xFFFF is a pool word, loaded once into a
 * callee-saved register and reused as the first call's second argument.
 */
void func_02005EB4(u32 trackMask)
{
    u16 muteMask = (u16)(trackMask ^ 0xFFFF);

    func_02072FA8(sub_0200590C(), 0xFFFF, 0);
    if (muteMask != 0) {
        func_02072FC8(sub_0200590C(), muteMask, 1);
    }
}

/*
 * Three optional settings, each skipped when the caller passes -1. The -1 is
 * rebuilt before each test (movs/mvns) rather than held in a register, as an
 * inline constant in three comparisons would be.
 */
void sub_02005EE0(u32 trackMask, u32 tempoRatio, u32 pitch, u32 pan)
{
    struct SndHandle *handle = sub_0200590C();

    if (tempoRatio != -1) {
        func_02073098(handle, tempoRatio);
    }
    if (pitch != -1) {
        func_02073018(handle, trackMask, pitch);
    }
    if (pan != -1) {
        func_02073038(handle, trackMask, pan);
    }
}

/*
 * The handle from sub_0200590C stays in r0 across the two parameter moves,
 * which is why the two `adds rN, rN, #0` copies come after the call.
 */
void func_02005F24(u32 trackMask, u32 volumeIndex)
{
    func_02072FE8(sub_0200590C(), trackMask, (int)volumeIndex);
}

/*
 * Nonzero when a BGM is current and the sound library counts the sequence
 * as playing.
 */
int sub_02005F38(void)
{
    if (sub_020058D0() == 0) {
        return 0;
    }
    if (func_02072EE0(sub_020058D0()) != 0) {
        return 1;
    }
    return 0;
}

/*
 * Cancel the pending change and restore the default 60 frame fades. The tail
 * call to sub_02005F90 goes through a pool word and bx even though the
 * target is in the same file: one section per function.
 */
void sub_02005F5C(void)
{
    _SndState.fadeInFrames = 60;
    _SndState.fadeOutFrames = 60;
    sub_02005F90();
}

/* Queue a change to `bgmNo`: fade the current BGM out, load, fade the new one in. */
void sub_02005F70(u32 bgmNo, u16 trackMask, int fadeOutFrames, int fadeInFrames)
{
    _SndState.changeTrackMask = trackMask;
    _SndState.changeBgm = bgmNo;
    _SndState.fadeInFrames = fadeInFrames;
    _SndState.fadeOutFrames = fadeOutFrames;
    _SndState.fadeCounter = fadeOutFrames;
    sub_02006368();
    _SndState.changePhase = BGM_CHANGE_FADE;
    _SndState.changeActive = 1;
}

/* Drop any pending change and put the volume back to maximum. */
void sub_02005F90(void)
{
    _SndState.changeActive = 0;
    _SndState.changeTrackMask = 0xFFFF;
    _SndState.changeBgm = 0;
    _SndState.fadeCounter = 0;
    func_02072F34(sub_0200590C(), SND_VOLUME_MAX);
    _SndState.changePhase = BGM_CHANGE_FADE;
    sub_02006368();
}

/* Finish a pending change at once: wait for the loader, start the BGM, clear the request. */
void sub_02005FBC(void)
{
    u32 bgmNo;

    if (_SndState.changeActive != 1) {
        return;
    }
    bgmNo = sub_020058D0();
    if (bgmNo != _SndState.changeBgm) {
        while (_SndState.changePhase != BGM_CHANGE_FADE) {
            sub_02005FF4();
        }
        ArrayDeleteAt(_SndState.changeBgm, _SndState.changeTrackMask);
    }
    sub_02005F90();
}

/*
 * Advance the BGM change by one step per call (the state machine that
 * func_02005BC0 runs every frame).
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
void sub_02005FF4(void)
{
    struct SndHandle *handle = sub_0200590C();
    u16 bgmNo = sub_020058D0();

    if (_SndState.changeActive == 0) {
        return;
    }
    switch (_SndState.changePhase) {
    case BGM_CHANGE_FADE:
        if (bgmNo != 0) {
            if (bgmNo != _SndState.changeBgm) {
                if (_SndState.fadeCounter != 0) {
                    _SndState.fadeCounter--;
                    func_02072F34(handle, _SndState.fadeCounter * SND_VOLUME_MAX /
                                          _SndState.fadeOutFrames);
                    return;
                }
                func_02072F34(handle, 0);
            } else {
                if (_SndState.fadeCounter < _SndState.fadeInFrames) {
                    _SndState.fadeCounter++;
                    func_02072F34(handle, _SndState.fadeCounter * SND_VOLUME_MAX /
                                          _SndState.fadeInFrames);
                    return;
                }
                sub_02005F90();
                return;
            }
        }
        sub_02005D14();
        if (_SndState.changeBgm == 0) {
            sub_02005F90();
            return;
        }
        func_020746B0(0x1300);
        sub_02006300(_SndState.changeBgm, 0);
        _SndState.fadeCounter = 0;
        _SndState.changePhase = BGM_CHANGE_LOAD_SEQ;
        return;
    case BGM_CHANGE_LOAD_SEQ:
        if (sub_02006394() == 1) {
            sub_0200597C();
            sub_02006300(_SndState.changeBgm, 1);
            _SndState.changePhase = BGM_CHANGE_LOAD_WAVE;
            return;
        }
        func_02085A38(1);
        return;
    case BGM_CHANGE_LOAD_WAVE:
        if (sub_02006394() == 1) {
            func_020746B0(0);
            sub_020059A0(_SndState.changeBgm);
            func_020755A8(sub_0200590C(), SND_PLAYER_BGM, -1, -1, _SndState.changeBgm);
            func_02072F34(handle, 0);
            _SndState.changePhase = BGM_CHANGE_FADE;
            return;
        }
        func_02085A38(1);
        return;
    }
}

/* Clear the five sound effect slots. */
void sub_02006118(void)
{
    int slot;

    for (slot = 0; slot < SND_SE_SLOT_COUNT; slot++) {
        _SeSlots[slot].seqNo = 0;
        func_02072E9C(&_SeSlots[slot].handle);
    }
}

/* No prologue: lsls, adds, adds, bx lr. */
struct SndHandle *sub_02006138(int slot)
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
int func_02006148(u32 seqNo)
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
    return func_0207430C(seqNo)[5] - 1;
}

/*
 * Start a sound effect in a given slot (player slot + 1) and remember the
 * sequence number on success.
 */
void sub_0200616C(u32 seqNo, int slot)
{
    if (sub_02005CE0(seqNo) == 0) {
        return;
    }
    _SeSlots[slot].seqNo = 0;
    if (func_020755A8(&_SeSlots[slot].handle, slot + 1, -1, -1, seqNo) == 1) {
        _SeSlots[slot].seqNo = seqNo;
    }
}

/* Start a sound effect in its own slot; a volume below 0x80 is applied after the start. */
void sub_020061A4(u32 seqNo, u32 volume)
{
    int slot;

    if (sub_02005CE0(seqNo) == 0) {
        return;
    }
    slot = func_02006148(seqNo);
    _SeSlots[slot].seqNo = 0;
    if (func_02075560(&_SeSlots[slot].handle, seqNo) != 1) {
        return;
    }
    _SeSlots[slot].seqNo = seqNo;
    if (volume < 0x80) {
        sub_020062BC(slot, volume);
    }
}

/*
 * sub_020061E4 and sub_020061F0 both tail call sub_020061A4 through the same
 * pool word: the first supplies -1 as the volume, the second passes both of
 * its arguments through.
 */
void sub_020061E4(u32 seqNo)
{
    sub_020061A4(seqNo, -1);
}

void sub_020061F0(u32 seqNo, u32 volume)
{
    sub_020061A4(seqNo, volume);
}

void sub_020061F8(int slot)
{
    func_02072E7C(&_SeSlots[slot].handle, 0);
}

void sub_02006210(void)
{
    int slot;

    for (slot = 0; slot < SND_SE_SLOT_COUNT; slot++) {
        sub_020061F8(slot);
    }
}

/*
 * The player number is incremented in place before the call, so the source
 * added one to the parameter rather than passing a computed local.
 */
int func_02006224(u32 slot)
{
    return func_02072EC8(slot + 1) != 0;
}

int sub_02006238(void)
{
    int slot;

    for (slot = 0; slot < SND_SE_SLOT_COUNT; slot++) {
        if (func_02006224(slot) == 1) {
            return 1;
        }
    }
    return 0;
}

int sub_02006254(u32 seqNo)
{
    if (func_02072EE0(seqNo) != 0) {
        return 1;
    }
    return 0;
}

/* Optional tempo, pitch and pan of a sound effect slot; -1 leaves a setting alone. */
void sub_02006268(int slot, u32 tempoRatio, u32 pitch, u32 pan)
{
    if (tempoRatio != -1) {
        func_02073098(&_SeSlots[slot].handle, tempoRatio);
    }
    if (pitch != -1) {
        func_02073018(&_SeSlots[slot].handle, 0xFFFF, pitch);
    }
    if (pan != -1) {
        func_02073038(&_SeSlots[slot].handle, 0xFFFF, pan);
    }
}

void sub_020062BC(int slot, u32 volume)
{
    if (volume > SND_VOLUME_MAX) {
        volume = SND_VOLUME_MAX;
    }
    func_02072F34(&_SeSlots[slot].handle, volume);
}

/*
 * The two loader thread bodies and the routine that starts one. Both bodies
 * are six instructions: read the sequence number the argument points at and
 * tail call the archive load with load flags 3 (sequence and bank) or 4
 * (wave archives). Their only references are the two pool words of
 * sub_02006300 below.
 */
void sub_020062D8(void *arg)
{
    func_02074AC4(*(u32 *)arg, 3, _SndState.heap);
}

void sub_020062EC(void *arg)
{
    func_02074AC4(*(u32 *)arg, 4, _SndState.heap);
}

/*
 * Start the loader thread for `bgmNo`: mode 0 loads sequence and bank, mode 1
 * the wave archives. The thread object is at 0x020AA354, its stack ends at
 * 0x020AA9B4 (0x400 bytes), the priority is 0x11. The thread argument is the
 * address of loaderSeqNo, the word just written.
 */
void sub_02006300(u32 bgmNo, int mode)
{
    _SndState.loaderSeqNo = bgmNo;
    sub_02006368();
    switch (mode) {
    case 0:
        func_020853C0(_WorkerThread, sub_020062D8, &_SndState.loaderSeqNo,
                      _SndHeapBuf, 0x400, 0x11);
        break;
    case 1:
        func_020853C0(_WorkerThread, sub_020062EC, &_SndState.loaderSeqNo,
                      _SndHeapBuf, 0x400, 0x11);
        break;
    }
    func_02085868(_WorkerThread);
    _SndState.loaderThread = (u32)_WorkerThread;
}

/* Destroy the loader thread when it was started and has not finished. */
void func_02006368(void)
{
    if (_SndState.loaderThread != 0) {
        if (func_0208574C(_WorkerThread) == 0) {
            func_020855BC(_WorkerThread);
            _SndState.loaderThread = 0;
        }
    }
}

/* 1 when the loader thread finished; a thread that was never started counts as finished. */
int sub_02006394(void)
{
    if (_SndState.loaderThread == 0) {
        return 1;
    }
    return func_0208574C(_WorkerThread);
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
 * leftover result of sub_0200590C, which takes none.
 */
u32 func_020063B4(u32 bgmNo, u32 *step, u32 abort)
{
    if (abort == 1) {
        sub_02005D14();
        sub_02006368();
        *step = 0;
    } else {
        switch (*step) {
        case 0:
            func_020746B0(0x1300);
            sub_02006300(bgmNo, 0);
            (*step)++;
            break;
        case 1:
            if (sub_02006394() == 1) {
                sub_0200597C();
                sub_02006300(bgmNo, 1);
                (*step)++;
            } else {
                func_02085A38(2);
            }
            break;
        case 2:
            if (sub_02006394() == 1) {
                s32 zero = 0;

                func_020746B0(0);
                sub_020059A0(bgmNo);
                func_020755A8(sub_0200590C(), 0, zero - 1, zero - 1, bgmNo);
                (*step)++;
                return 1;
            }
            func_02085A38(2);
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
int func_02006448(u32 seqAddr, u32 bankAddr, u32 bgmNo)
{
    struct SndArcSeqEntry *seq;
    struct SndArcBankEntry *bank;
    u32 seqFileId;
    u16 bankNo;
    u32 bankFileId;
    int i;

    seq = func_02074324(bgmNo);
    seqFileId = seq->fileId;
    bankNo = seq->bankNo;
    bank = func_020743EC(bankNo);
    bankFileId = bank->fileId;
    sub_0200597C();
    for (i = 0; i < 4; i++) {
        if (bank->waveArc[i] != 0xFFFF) {
            if (func_02074A98(bank->waveArc[i], _SndState.heap) == 0) {
                return 0;
            }
        }
    }
    func_02074694(bankFileId, bankAddr);
    func_02074694(seqFileId, seqAddr);
    sub_020059A0(bgmNo);
    return 1;
}

/*
 * Replace wave `waveIndex` of a wave archive by wave `srcWaveIndex` of
 * another archive's data. The file id is a 24 bit unsigned bitfield (a
 * lsls #8 / lsrs #8 pair); `& 0xFFFFFF` would load a pool word instead.
 */
int sub_020064B8(u32 waveArcNo, u32 waveIndex, u32 srcWaveArc, u32 srcWaveIndex)
{
    struct SndArcWaveArcEntry *entry;
    u32 *waveArcData;

    entry = func_02074450(waveArcNo);
    if (entry == 0) {
        return 0;
    }
    waveArcData = (u32 *)func_0207466C(entry->fileId);
    if (waveArcData == 0) {
        return 0;
    }
    func_0208A640(waveArcData, waveIndex, func_0208A674(srcWaveArc, srcWaveIndex));
    return 1;
}

/* Start a sequence on the current handle. */
void sub_020064F4(u32 seqNo)
{
    func_02075560(sub_0200590C(), seqNo);
}

/* Same body as sub_02005D14: stop the current sequence and drop its data. */
void sub_02006504(void)
{
    func_02072E7C(sub_0200590C(), 0);
    sub_020059C8();
}

/*
 * Forget the buffers that func_02006448 installed for SEQ_PRELOADED_BGM:
 * the bank file's data address and the sequence file's data address are
 * set to zero. 0x3F2 is past the Thumb movs immediate range, so it arrives
 * in r4 through a pool word and is used twice from there.
 */
void sub_02006518(void)
{
    u32 bankFileId = func_020743EC(SEQ_PRELOADED_BGM)->fileId;
    u32 seqFileId = func_02074324(SEQ_PRELOADED_BGM)->fileId;

    func_02074694(bankFileId, 0);
    func_02074694(seqFileId, 0);
}

/*
 * Set up the voice mixer: remember the heap and the two callbacks, put the
 * master volume to maximum, and for each of the three 0x34 byte voices
 * clear the active word, copy the two 4-bit channel numbers out of the
 * halfword table (they are adjacent u8 bitfields, hence the narrowing to 8
 * bits), and reset the voice. Voice 0 also gets the static buffer as its
 * buffer and its sample data pointer. One voice is in use afterwards.
 */
void func_02006544(u16 heapId,
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
        sub_020067D0(voice);
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
void sub_020065D8(void)
{
    int i;

    for (i = 0; i < PM_VOICE_SLOT_COUNT; i++) {
        struct PmVoice *voice = &_VoiceSystem.voices[i];

        if (voice->active == 1) {
            func_02006948(voice);
        }
    }
}

/* Stop the voices whose hardware channels have gone silent. */
void sub_020065FC(void)
{
    struct PmVoice *voice;
    int i;
    u32 busyA;
    u32 busyB;

    for (i = 0; i < _VoiceSystem.count; i++) {
        voice = &_VoiceSystem.voices[i];
        if (voice->active == 1) {
            busyA = func_02072CC4(voice->channelA);
            if (voice->dual == 1) {
                busyB = func_02072CC4(voice->channelB);
            } else {
                busyB = 0;
            }
            if (busyA == 0 && busyB == 0) {
                func_02006948(voice);
            }
        }
    }
}

int sub_02006650(void)
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
void sub_02006674(int extraVoices, u32 heapId)
{
    struct PmVoice *voice;
    int i;

    sub_020065D8();
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
void sub_020066E8(void)
{
    struct PmVoice *voice;
    int i;

    sub_020065D8();
    for (i = 0; i < _VoiceSystem.count; i++) {
        voice = &_VoiceSystem.voices[i];
        if (voice->buffer != 0 && voice->ownsBuffer == 1) {
            func_020307B0(voice->buffer);
            sub_020067D0(voice);
        }
    }
    _VoiceSystem.count = 1;
    _VoiceSystem.current = 0;
}

void sub_02006734(u8 volume)
{
    _VoiceSystem.masterVolume = volume;
}

void sub_02006740(void)
{
    _VoiceSystem.masterVolume = SND_VOLUME_MAX;
}

/*
 * Scale a volume by the master volume. Both operands promote to int, so the
 * signed division helper (_s32_div_f) is called.
 */
u8 sub_0200674C(u8 volume)
{
    return (u8)(volume * _VoiceSystem.masterVolume / SND_VOLUME_MAX);
}

/* Round robin: stop the voice in the current slot, advance, return the slot. */
u16 sub_02006768(void)
{
    struct PmVoice *voice;
    u16 slot;

    slot = _VoiceSystem.current;
    voice = &_VoiceSystem.voices[slot];
    if (voice->active == 1) {
        func_02006948(voice);
    }
    if (_VoiceSystem.current < _VoiceSystem.count - 1) {
        _VoiceSystem.current = _VoiceSystem.current + 1;
    } else {
        _VoiceSystem.current = 0;
    }
    return slot;
}

/* Back to the idle parameters; the buffer stays. */
void sub_020067A4(struct PmVoice *voice)
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
void sub_020067D0(struct PmVoice *voice)
{
    voice->buffer = 0;
    voice->ownsBuffer = 0;
    sub_020067A4(voice);
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
int sub_020067E0(struct PmVoice *voice, u32 waveId)
{
    struct SndArcWaveArcEntry *entry;
    struct PmWaveFile *file;
    struct PmWave *wave;
    u32 fileSize;
    u32 waveBytes;
    int bytesRead;

    entry = func_02074450(waveId);
    if (entry == 0) {
        return 0;
    }
    fileSize = func_0207457C(entry->fileId);
    if (fileSize == 0) {
        return 0;
    }
    bytesRead = func_020745A4(entry->fileId, voice->buffer, fileSize, 0);
    if (bytesRead == -1) {
        return 0;
    }
    if (bytesRead != fileSize) {
        return 0;
    }
    file = voice->buffer;
    wave = (struct PmWave *)((u8 *)file + file->waveOffset);
    func_0208A638((char *)file);
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
int sub_02006868(struct PmVoice *voice)
{
    int volumeB;

    if (voice->buffer == 0) {
        return 0;
    }
    if (voice->dataSize == 0) {
        return 0;
    }
    voice->channelA = func_02072A44(voice->channelNoA);
    if (voice->channelA == 0) {
        return 0;
    }
    if (func_02072AA0(voice->channelA, 0, voice->data, 0, 0, voice->dataSize,
                      voice->sampleRate, sub_0200674C(voice->volume),
                      voice->frequency, voice->pan) == 0) {
        return 0;
    }
    if (voice->dual == 1) {
        voice->channelB = func_02072A44(voice->channelNoB);
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
        if (func_02072AA0(voice->channelB, 0, voice->data, 0, 0, voice->dataSize,
                          voice->sampleRate, sub_0200674C((u8)volumeB),
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
void func_02006948(struct PmVoice *voice)
{
    func_02072BDC(voice->channelA);
    func_02072D20(voice->channelA);
    func_02072A88(voice->channelA);
    if (voice->dual == 1) {
        func_02072BDC(voice->channelB);
        func_02072D20(voice->channelB);
        func_02072A88(voice->channelB);
    }
    voice->active = 0;
    sub_020067A4(voice);
}

/*
 * Prepare and start a voice. Eight parameters: four in registers and four in
 * the caller's frame, which are copied down into the outgoing argument area.
 * While the BGM loader thread runs the call sleeps 2 ms at a time; the wait
 * loop is an `if` around a `do`/`while` because `v = 2` is emitted after the
 * first test and the back edge skips it. The sleep time and the slot share
 * one local.
 */
u32 func_02006984(u32 species, u32 form, u32 pan, u32 dual,
                  u32 volumeBiasB, u32 frequencyOffsetB, u32 reverse,
                  void **recordedVoice)
{
    u32 slot;

    if (sub_02005C64() == 1) {
        slot = 2;
        do {
            func_02085A38(slot);
        } while (sub_02005C64() == 1);
    }
    slot = (u16)func_020069D4(species, form, pan, dual, volumeBiasB,
                              frequencyOffsetB, reverse, recordedVoice);
    func_02006A64(slot);
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
int func_020069D4(int species, int form, int pan, int dual,
                  int volumeBiasB, int frequencyOffsetB, int reverse,
                  void **recordedVoice)
{
    u32 waveId;
    int slot;
    struct PmVoice *voice;

    _VoiceSystem.resolveCallback(species, form, &waveId);
    slot = sub_02006768();
    voice = &_VoiceSystem.voices[slot];
    if (voice->active == 1)
        func_02006948(voice);
    if (_VoiceSystem.prepareCallback(species, form, recordedVoice, &voice->data,
                                     &voice->dataSize, &voice->sampleRate,
                                     &voice->frequency, &voice->volume) == 0)
        sub_020067E0(voice, waveId);
    if (reverse != 0)
        sub_02006BE0(voice->data, voice->dataSize);
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
int func_02006A64(u32 slot)
{
    if (sub_02006868(&_VoiceSystem.voices[slot]) == 0) {
        func_02006948(&_VoiceSystem.voices[slot]);
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
void func_02006A8C(u32 slot, int delta)
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
    func_02072C18(voice->channelA, sub_0200674C(voice->volume));
    if (voice->dual == 1) {
        volume = voice->volume + voice->volumeBiasB;
        if (volume < 0) {
            volume = 0;
        }
        if (volume > SND_VOLUME_MAX) {
            volume = SND_VOLUME_MAX;
        }
        func_02072C18(voice->channelA, sub_0200674C((u8)volume));
    }
}

/*
 * Add `delta` to the frequency of a voice. The sum is stored first and the
 * stored value is passed to the first call; the second call re-reads the
 * frequency and adds the channel B offset.
 */
void func_02006AEC(u32 slot, u32 delta)
{
    struct PmVoice *voice;
    u32 frequency;

    voice = &_VoiceSystem.voices[slot];
    if (voice->active == 0) {
        return;
    }
    frequency = voice->frequency + delta;
    voice->frequency = frequency;
    func_02072C40(voice->channelA, frequency);
    if (voice->dual == 1) {
        func_02072C40(voice->channelB, voice->frequency + voice->frequencyOffsetB);
    }
}

/*
 * Getters over the 0x34 byte voice records; most return an idle value for a
 * voice that is not active. None of them saves a register, so the listing
 * does not label them. The index arithmetic is a `muls` by 0x34 (not a
 * power of two). sub_02006B20 reads the s8 volume with a register offset
 * ldrsb, the evidence that the field is signed. sub_02006BB4 computes the
 * slot address only inside the if, where the other functions compute it
 * before the test.
 */
s8 sub_02006B20(u32 slot)
{
    struct PmVoice *voice = &_VoiceSystem.voices[slot];

    if (voice->active == 0) {
        return 0;
    }
    return voice->volume;
}

u32 sub_02006B3C(u32 slot)
{
    struct PmVoice *voice = &_VoiceSystem.voices[slot];

    if (voice->active == 0) {
        return PM_VOICE_DEFAULT_FREQUENCY;
    }
    return voice->frequency;
}

u8 *sub_02006B5C(u32 slot)
{
    struct PmVoice *voice = &_VoiceSystem.voices[slot];

    if (voice->active == 0) {
        return 0;
    }
    return voice->data;
}

u32 sub_02006B78(u32 slot)
{
    struct PmVoice *voice = &_VoiceSystem.voices[slot];

    if (voice->active == 0) {
        return 0;
    }
    return voice->dataSize;
}

u32 sub_02006B94(u32 slot)
{
    struct PmVoice *voice = &_VoiceSystem.voices[slot];

    if (voice->active == 0) {
        return PM_VOICE_DEFAULT_SAMPLE_RATE;
    }
    return voice->sampleRate;
}

void sub_02006BB4(u32 slot)
{
    if (_VoiceSystem.voices[slot].active == 1) {
        func_02006948(&_VoiceSystem.voices[slot]);
    }
}

u32 sub_02006BD0(u32 slot)
{
    return _VoiceSystem.voices[slot].active;
}

/* Reverse `count` bytes in place. */
void sub_02006BE0(u8 *bytes, u32 count)
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
void sub_02006C00(u32 species, u32 form, u32 *cryIndex)
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
 * Cry parameters for a species. func_02048F4C copies one 4-byte record of
 * archive 194 (a/1/9/4, 652 records) into `record`; its second halfword's
 * low byte is the cry volume (97 to 127). Species 441 (Chatot) is the one
 * cry that is a recorded sample: when the recording exists, its 8180 bytes
 * are copied into the voice's sample data, the sample rate is 0x1FF4, the
 * volume 120 and the frequency a random value in 0x8000..0xA000. Returns 1
 * when the sample was supplied, otherwise 0 and the wave file is loaded.
 * The literal 441 is rematerialised as 194 + 247 off the register that
 * holds the archive id. Content constants (441, 652) are Black-image values.
 */
u32 func_02006C2C(u32 species, u32 form, void **recordedVoice, u8 **data,
                  u32 *dataSize, u32 *sampleRate, u32 *frequency, s8 *volume)
{
    u16 record[2];

    func_02048F4C(record, 194, species);
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
void sub_02006CAC(struct SaveBlock **out)
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
void func_02006CBC(u16 heapId)
{
    struct SndMic *mic;
    void *sampleBuffer;

    mic = func_02030734(heapId, 0x28, 0, _SndMicFile, 0x59);
    func_02082BCC(mic, 0, 0x28);
    sampleBuffer = func_02030734(heapId, 0x2014, 0, _SndMicFile, 0x5f);
    func_02082BCC(sampleBuffer, 0, 0x2014);
    mic->sampleBuffer = sampleBuffer;
    func_0208BEF0(1);
    func_0208BF38(2);
    mic->status.word = (mic->status.word & ~1u) | 1u;
    func_0208B24C();
    if (func_02085D3C() == 1) {
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
void sub_02006D44(void)
{
    PM_SetAmp(0);
    func_020307B0(_SndMic->sampleBuffer);
    func_020307B0(_SndMic);
}

/* Add `ticks` to the recorded time while recording and below the limit. */
void sub_02006D64(u32 ticks)
{
    struct SndMic *mic = _SndMic;

    if (mic->status.bits.recording) {
        if (sub_02006D94() == 0) {
            mic->status.bits.elapsed += ticks;
        }
    }
}

/* 1 once more than 180 ticks were recorded. */
u32 sub_02006D94(void)
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
u32 sub_02006DAC(const struct MICAutoParam *param)
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
u32 sub_02006DD8(MICCallback callback, void *arg)
{
    struct MICAutoParam param;

    param.type = 2;
    param.buffer = sub_02006E2C();
    param.size = 0x1FF4;
    if (param.size & 0x1F) {
        param.size &= ~0x1Fu;
    }
    param.rate = 0x1001;
    param.loop_enable = 0;
    param.full_callback = callback;
    param.full_arg = arg;
    return sub_02006DAC(&param);
}

/* Copy the recorded buffer into a Perap voice (Chatot) record. */
void func_02006E18(struct PerapVoice *perapVoice)
{
    void *buffer = sub_02006E2C();

    func_02007BD0(perapVoice, buffer);
}

/*
 * The sample buffer address rounded up to a multiple of 32. The mask is
 * materialised in r1 and applied with bics (Thumb has no immediate bic);
 * the compiler hoists the movs above both loads.
 */
void *sub_02006E2C(void)
{
    return (void *)(((u32)_SndMic->sampleBuffer + 0x1F) & ~0x1Fu);
}
