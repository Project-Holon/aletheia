#ifndef GAME_ARM9_PM_VOICE_H
#define GAME_ARM9_PM_VOICE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pm_voice.c, prototypes copied from their definitions. */

struct PmVoice;
struct SaveBlock;

#include "../types.h"

void PM_VOICE_Init(u16 heapId, void (*resolveCallback)(u32 species, u32 form, u32 *waveId), u32 (*prepareCallback)(u32 species, u32 form, void **recordedVoice, u8 **data, u32 *dataSize, u32 *sampleRate, u32 *frequency, s8 *volume));
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
u32 PM_VOICE_Play(u32 species, u32 form, u32 pan, u32 dual, u32 volumeBiasB, u32 frequencyOffsetB, u32 reverse, void **recordedVoice);
int PM_VOICE_Prepare(int species, int form, int pan, int dual, int volumeBiasB, int frequencyOffsetB, int reverse, void **recordedVoice);
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
u32 PM_VOICE_PrepareCry(u32 species, u32 form, void **recordedVoice, u8 **data, u32 *dataSize, u32 *sampleRate, u32 *frequency, s8 *volume);
void PM_VOICE_GetPerapVoiceSave(struct SaveBlock **out);
/* END mkheaders: generated region */

#endif
