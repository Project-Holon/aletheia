#ifndef GAME_ARM9_PERAPVOICE_H
#define GAME_ARM9_PERAPVOICE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of perapvoice.c, prototypes copied from their definitions. */

struct PerapVoice;
struct SaveControl;
struct PokeParty;

#include "../types.h"

u32 PERAPVOICE_GetSize(void);
void PERAPVOICE_Init(struct PerapVoice *voice);
struct PerapVoice *PERAPVOICE_Create(u32 heapId);
struct PerapVoice *PERAPVOICE_GetFromSave(struct SaveControl *saveControl);
u32 PERAPVOICE_IsRecorded(struct PerapVoice *voice);
void PERAPVOICE_ClearRecorded(struct PerapVoice *voice);
void PERAPVOICE_SetRecorded(struct PerapVoice *voice);
u8 *PERAPVOICE_GetSamples(struct PerapVoice *voice);
void PERAPVOICE_Unpack(s8 *dest, const s8 *src);
void PERAPVOICE_Pack(struct PerapVoice *voice, const s8 *src);
void PERAPVOICE_Copy(struct PerapVoice *dest, const struct PerapVoice *src);
void PERAPVOICE_ClearIfNoChatot(struct PerapVoice *voice, struct PokeParty *party);
u32 PERAPVOICE_GetVoiceKind(struct PerapVoice *voice);
/* END mkheaders: generated region */

#endif
