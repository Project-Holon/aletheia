#ifndef GAME_ARM9_PMSI_PARAM_H
#define GAME_ARM9_PMSI_PARAM_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of pmsi_param.c, prototypes copied from their definitions. */

struct PmsiParam;
struct PmsData;

#include "../types.h"

struct PmsiParam *PMSI_PARAM_Create(u32 inputMode, u32 unused, void *initialSentence, u32 optionFlag, void *saveControl, u32 heapId);
void PMSI_PARAM_Delete(void *obj);
void PMSI_PARAM_SetWord(struct PmsiParam *obj, u16 word);
void PMSI_PARAM_SetSentence(struct PmsiParam *obj, const struct PmsData *sentence);
int PMSI_PARAM_CheckCanceled(const struct PmsiParam *obj);
int PMSI_PARAM_CheckModified(const struct PmsiParam *obj);
unsigned int PMSI_PARAM_GetWord(const struct PmsiParam *obj);
void PMSI_PARAM_GetSentence(const struct PmsiParam *obj, struct PmsData *outSentence);
u32 PMSI_PARAM_GetInputMode(const struct PmsiParam *obj);
void *PMSI_PARAM_GetSaveWork(const struct PmsiParam *obj);
void *PMSI_PARAM_GetWordSave(const struct PmsiParam *obj);
int PMSI_PARAM_GetEventFlag(const struct PmsiParam *obj);
u32 PMSI_PARAM_HasInitialSentence(const struct PmsiParam *obj);
int PMSI_PARAM_GetOptionFlag(const struct PmsiParam *obj);
void PMSI_PARAM_GetResult(const struct PmsiParam *obj, u16 *outWords, u16 *outSentence);
u32 PMSI_PARAM_IsSameInput(const struct PmsiParam *obj, const u16 *words, const struct PmsData *sentence);
void PMSI_PARAM_SetResult(struct PmsiParam *obj, const u16 *words, const struct PmsData *sentence);
void PMSI_PARAM_GetUiInputMode(void);
void PMSI_PARAM_SetUiInputMode(void *unused, void *inputMode);
void FX_MakeSineTable(s16 *table, u32 count, u16 step, int amplitude);
void PMSI_PARAM_ClearSentence(struct PmsData *sentence);
void PMSI_PARAM_InitSentence(struct PmsData *sentence, u32 sentenceType);
void PMSI_PARAM_InitSentenceId(struct PmsData *sentence, u32 sentenceType, u32 sentenceId);
void PMSI_PARAM_SetDefaultSentence(struct PmsData *sentence, u32 preset);
void PMSI_PARAM_SetDefaultGreeting(struct PmsData *sentence);
void *PMSI_PARAM_ToString(const struct PmsData *sentence, unsigned int heapId);
void *PMSI_PARAM_ToStringWords(const struct PmsData *sentence, u32 heapId, int wordCount);
void *PMSI_PARAM_GetSourceString(const struct PmsData *sentence, u32 heapId);
int PMSI_PARAM_IsEnabled(const u16 *word);
int PMSI_PARAM_IsComplete(struct PmsData *sentence, u16 heapId);
u32 PMSI_PARAM_GetWordCount(u32 sentenceType, u32 sentenceId, u16 heapId);
u16 PMSI_PARAM_GetWordId(const struct PmsData *sentence, u32 index);
u16 PMSI_PARAM_GetWordRaw(const struct PmsData *sentence, u32 index);
u32 PMSI_PARAM_IsDecoWordAt(const struct PmsData *sentence, u32 index);
u32 PMSI_PARAM_IsDecoWord(u32 word);
u32 PMSI_PARAM_GetDecoId(u32 word);
int PMSI_PARAM_GetSentenceType(const struct PmsData *sentence);
unsigned int PMSI_PARAM_GetSentenceId(const struct PmsData *sentence);
int PMSI_PARAM_Compare(const struct PmsData *left, const struct PmsData *right);
void PMSI_PARAM_Copy(struct PmsData *dst, const struct PmsData *src);
u8 PMSI_PARAM_GetSentenceCount(u32 sentenceType);
void PMSI_PARAM_SetSentenceId(struct PmsData *sentence, int sentenceType, int sentenceId);
void PMSI_PARAM_SetWordAt(struct PmsData *sentence, unsigned index, u16 word);
void PMSI_PARAM_ClearUnusedWords(struct PmsData *sentence, u16 heapId);
u32 PMSI_PARAM_IsValid(struct PmsData *sentence, u32 heapId);
u32 PMSI_PARAM_Validate(struct PmsData *sentence, u32 allowEmpty, u32 heapId);
u32 PMSI_PARAM_ValidateWord(u16 *word, u32 allowEmpty, u32 allowDeco);
u32 PMSI_PARAM_ValidateDecoValue(u32 *decoId, u32 allowZero);
int PMSI_PARAM_IsSpecialWord(u32 word);
/* END mkheaders: generated region */

#endif
