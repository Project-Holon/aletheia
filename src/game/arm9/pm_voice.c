/*
 * file:     pm_voice.c
 * unit:     yes
 * function: PM_VOICE_Init, PM_VOICE_StopAll, PM_VOICE_StopFinished, PM_VOICE_IsAnyActive, PM_VOICE_AllocBuffers, PM_VOICE_FreeBuffers, PM_VOICE_SetMasterVolume, PM_VOICE_ResetMasterVolume, PM_VOICE_ScaleVolume, PM_VOICE_NextSlot, PM_VOICE_ResetParams, PM_VOICE_ClearSlot, PM_VOICE_LoadWave, PM_VOICE_StartChannels, PM_VOICE_Stop, PM_VOICE_Play, PM_VOICE_Prepare, PM_VOICE_Start, PM_VOICE_AddVolume, PM_VOICE_AddFrequency, PM_VOICE_GetVolume, PM_VOICE_GetFrequency, PM_VOICE_GetData, PM_VOICE_GetDataSize, PM_VOICE_GetSampleRate, PM_VOICE_StopSlot, PM_VOICE_IsSlotActive, PM_VOICE_ReverseBytes, PM_VOICE_GetCryIndex, PM_VOICE_PrepareCry, PM_VOICE_GetPerapVoiceSave
 * address:  0x02006544
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pm_voice.c by tools/splitfile.py.
 *
 * symbols:
 *   OS_Sleep       0x02085A38  arm
 *   NNS_SndArcGetWaveArcInfo  0x02074450  arm
 *   GFL_HEAP_Alloc       0x02030734  arm
 *   NNS_SndWaveOutIsPlaying       0x02072CC4  arm
 *   GFL_HEAP_Free       0x020307B0  arm
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
 *   GFL_USE_GetRandom  0x020056EC  thumb
 *   PERAPVOICE_IsRecorded  0x02007B50  thumb
 *   PERAPVOICE_GetSamples  0x02007B64  thumb
 *   PERAPVOICE_Unpack  0x02007B68  thumb
 *   ARC_TOOL_ReadMember  0x02048F4C  arm
 *   SAVE_CONTROL_Get  0x020070A4  thumb
 *   PERAPVOICE_GetFromSave  0x02007B44  thumb
 *   _VoiceSystem        0x02140484  data
 *   _VoiceBuffer0       0x02140534  data
 *   _VoiceChannelTable  0x0209D8C0  data
 *   _PmVoiceFile        0x020A7024  data
 *   GFL_USE_IsLoaderBusy         0x02005C64  thumb
 *   _ll_udiv                     0x0209C00C  arm
 */
#include "pm_voice_shared_types.h"
#include "gfl_use.h"

#include "../types.h"
#include "species.h"

/* Sound volume range and the player numbers the sequence start call takes. */
#define SND_VOLUME_MAX       0x7F

/* Voice mixer limits. */
#define PM_VOICE_SLOT_COUNT  3

#define PM_VOICE_DEFAULT_SAMPLE_RATE 0x3443

#define PM_VOICE_DEFAULT_FREQUENCY   0x64E1

#define PM_VOICE_BUFFER_SIZE 0x5C30

struct SndChannel;

struct SaveData;

struct SaveBlock;

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

#include "os_thread.h"

#include "nns_snd_arc.h"

/* Calls into the voice channel layer and the other data readers. */
#include "gfl_heap_wrap.h"

struct NNSSndWaveOutHandle;

#include "nns_snd_waveout.h"





#include "snd_bank.h"






struct PerapVoice;

#include "perapvoice.h"



#include "arc_tool.h"
struct SaveControl;

#include "save_control.h"


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

extern struct PmVoiceSystem _VoiceSystem;

extern u8 _VoiceBuffer0[];

extern struct PmVoiceChannelPair _VoiceChannelTable[];

extern const char _PmVoiceFile[];

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
            busyA = NNS_SndWaveOutIsPlaying((struct NNSSndWaveOutHandle *)voice->channelA);
            if (voice->dual == 1) {
                busyB = NNS_SndWaveOutIsPlaying((struct NNSSndWaveOutHandle *)voice->channelB);
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
            void *block = GFL_HEAP_Alloc(heapId, PM_VOICE_BUFFER_SIZE, 1, _PmVoiceFile, 0x105);

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
            GFL_HEAP_Free(voice->buffer);
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
    NNSSndArcWaveArcInfo *entry;
    struct PmWaveFile *file;
    struct PmWave *wave;
    u32 fileSize;
    u32 waveBytes;
    int bytesRead;

    entry = NNS_SndArcGetWaveArcInfo(waveId);
    if (entry == 0) {
        return 0;
    }
    fileSize = NNS_SndArcGetFileSize(entry->bits.fileId);
    if (fileSize == 0) {
        return 0;
    }
    bytesRead = NNS_SndArcReadFile(entry->bits.fileId, voice->buffer, fileSize, 0);
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
    voice->channelA = (struct SndChannel *)NNS_SndWaveOutAllocChannel(voice->channelNoA);
    if (voice->channelA == 0) {
        return 0;
    }
    if (NNS_SndWaveOutStart((struct NNSSndWaveOutHandle *)voice->channelA, 0, voice->data, 0, 0, voice->dataSize,
                      voice->sampleRate, PM_VOICE_ScaleVolume(voice->volume),
                      voice->frequency, voice->pan) == 0) {
        return 0;
    }
    if (voice->dual == 1) {
        voice->channelB = (struct SndChannel *)NNS_SndWaveOutAllocChannel(voice->channelNoB);
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
        if (NNS_SndWaveOutStart((struct NNSSndWaveOutHandle *)voice->channelB, 0, voice->data, 0, 0, voice->dataSize,
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
    NNS_SndWaveOutStop((struct NNSSndWaveOutHandle *)voice->channelA);
    NNS_SndWaveOutWaitIdle((struct NNSSndWaveOutHandle *)voice->channelA);
    NNSi_SndWaveOutUnlockChannel((u32 *)voice->channelA);
    if (voice->dual == 1) {
        NNS_SndWaveOutStop((struct NNSSndWaveOutHandle *)voice->channelB);
        NNS_SndWaveOutWaitIdle((struct NNSSndWaveOutHandle *)voice->channelB);
        NNSi_SndWaveOutUnlockChannel((u32 *)voice->channelB);
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
    NNS_SndWaveOutSetVolume((struct NNSSndWaveOutHandle *)voice->channelA, PM_VOICE_ScaleVolume(voice->volume));
    if (voice->dual == 1) {
        volume = voice->volume + voice->volumeBiasB;
        if (volume < 0) {
            volume = 0;
        }
        if (volume > SND_VOLUME_MAX) {
            volume = SND_VOLUME_MAX;
        }
        NNS_SndWaveOutSetVolume((struct NNSSndWaveOutHandle *)voice->channelA, PM_VOICE_ScaleVolume((u8)volume));
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
    NNS_SndWaveOutSetSpeed((struct NNSSndWaveOutHandle *)voice->channelA, frequency);
    if (voice->dual == 1) {
        NNS_SndWaveOutSetSpeed((struct NNSSndWaveOutHandle *)voice->channelB, voice->frequency + voice->frequencyOffsetB);
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
    if (species < 1 && species > SPECIES_LAST) {
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
    if (species == 441 && form == 0 && PERAPVOICE_IsRecorded(recordedVoice[0]) == 1) {
        PERAPVOICE_Unpack((s8 *)data[0], (s8 *)(PERAPVOICE_GetSamples(recordedVoice[0])));
        *dataSize = 0x1FF4;
        *sampleRate = 0x1FF4;
        *volume = 0x78;
        *frequency = GFL_USE_GetRandom(0x2000) + 0x8000;
        return 1;
    }
    return 0;
}

/*
 * Save block with the recorded voice. SAVE_CONTROL_Get is a lazily initialised
 * singleton getter, never reading r0, so the call is nested and the result
 * of PERAPVOICE_GetFromSave is stored through the argument.
 */
void PM_VOICE_GetPerapVoiceSave(struct SaveBlock **out)
{
    *out = (struct SaveBlock *)PERAPVOICE_GetFromSave(SAVE_CONTROL_Get());
}
