#ifndef GAME_ARM9_WORDSET_H
#define GAME_ARM9_WORDSET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of wordset.c, prototypes copied from their definitions. */

struct WordSet;
struct WordTag;
struct Strbuf;

#include "../types.h"
#include "../version.h"

struct WordSet *WORDSET_Create(u32 slotCount, u32 textCapacity, u16 heapId);
u32 WORDSET_Delete(struct WordSet *words);
void WORDSET_Init(struct WordTag *tag);
void WORDSET_ResetSlot(struct WordSet *words, u32 slot);
void WORDSET_SetSlotText(struct WordSet *words, u32 slot, struct Strbuf *src, const struct WordTag *tag);
void WORDSET_SetSlotFromMessage(struct WordSet *words, u32 slot, u32 messageId, u32 entryIndex);
void WORDSET_SetSlotTag(struct WordSet *words, u32 slot, struct Strbuf *src, u32 grammarCase, u32 isPlural, u32 gender);
void WORDSET_SetSlotSpeciesName(struct WordSet *words, u32 slot, u16 speciesId);
void WORDSET_SetSlotMonSpeciesName(struct WordSet *words, u32 slot, void *mon);
void WORDSET_SetSlotMonNameAlt(struct WordSet *words, u32 slot, void *mon);
void WORDSET_SetSlotFromMsg119(struct WordSet *words, u32 slot, u16 entryIndex);
void WORDSET_SetSlotMonNameEx(struct WordSet *words, u32 slot, void *mon);
void WORDSET_SetSlotMonNickname(struct WordSet *words, u32 slot, void *mon);
void WORDSET_SetSlotMonNicknameAlt(struct WordSet *words, u32 slot, void *mon);
void WORDSET_SetSlotFromMsgCB(struct WordSet *words, u32 slot, u32 entryIndex);
void WORDSET_SetSlotFromMsg36(struct WordSet *words, u32 slot, u32 entryIndex);
void WORDSET_SetSlotFromMsg117(struct WordSet *words, u32 slot, u32 entryIndex);
void WORDSET_SetSlotFromMsg118(struct WordSet *words, u32 slot, u32 entryIndex);
void WORDSET_SetSlotFromBank(struct WordSet *words, u32 slot, u32 entryIndex, u32 useFirstBank, u32 useSecondBank);
void WORDSET_SetSlotFromMsgB6(struct WordSet *words, u32 slot, u32 entryIndex);
void WORDSET_SetSlotFromMsg18(struct WordSet *words, u32 slot, u32 entryIndex);
void WORDSET_SetSlotNumber(struct WordSet *words, u32 slot, u32 number, u32 topDigitIndex, u32 padMode, u32 isHalfWidth);
void WORDSET_SetSlotPmsWord(struct WordSet *words, u32 slot, u32 pmsWord);
void WORDSET_SetSlotMarkerFlag(struct WordSet *words, u32 slot, u32 markerFlag);
void WORDSET_SetSlotFromMsgC7(struct WordSet *words, u32 slot, u32 entryIndex);
void WORDSET_SetSlotMyStatus(struct WordSet *words, u32 slot, void *source);
void WORDSET_SetSlotFromMsgE7(struct WordSet *words, u32 slot, u32 entryIndex);
void WORDSET_SetSlotFromKeyedMessage(struct WordSet *words, u32 slot, u32 key, u32 entryIndex);
void WORDSET_SetSlotFromMsgBF(struct WordSet *words, u32 slot, u32 entryIndex);
void WORDSET_SetSlotPokeData(struct WordSet *words, u32 slot, u32 trainerId);
#if LANGUAGE != LANGUAGE_JAPANESE
void WORDSET_SetSlotFromMsg11B(struct WordSet *words, u32 slot, u32 entryIndex);
#endif
void WORDSET_SetSlotFromMsgBE(struct WordSet *words, u32 slot, u32 entryIndex);
void WORDSET_SetSlotFromMsgB4(struct WordSet *words, u32 slot, u32 entryIndex);
void WORDSET_SetSlotFromMsg37(struct WordSet *words, u32 slot, u32 entryIndex);
void WORDSET_SetSlotFromMsg59(struct WordSet *words, u32 slot, u32 entryIndex);
void WORDSET_SetSlotBoxName(struct WordSet *words, u32 slot, void *save, u32 boxIndex);
void WORDSET_SetSlotFromMsgA0(struct WordSet *words, u32 slot, s32 entryIndex);
void WORDSET_SetSlotFromMsg2B(struct WordSet *words, u32 slot, u32 entryIndex);
void WORDSET_SetSlotFromMsg00(struct WordSet *words, u32 slot, u8 entryIndex);
void WORDSET_SetSlotFromMsg38(struct WordSet *words, u32 slot, u32 entryIndex);
void WORDSET_SetSlotWeekday(struct WordSet *words, u32 slot, u32 weekday);
#if LANGUAGE == LANGUAGE_JAPANESE
static inline void WORDSET_SetSlotMonth(struct WordSet *words, u32 slot, u32 month)
{
    WORDSET_SetSlotFromMsg38(words, slot, month);
}
#else
void WORDSET_SetSlotMonth(struct WordSet *words, u32 slot, u32 month);
#endif
void WORDSET_CopyTaggedText(struct WordSet *words, struct Strbuf *dst, struct Strbuf *src);
void WORDSET_ClearAllSlots(struct WordSet *words);
void WORDSET_LoadSpeciesNameBank(u16 heapId);
void WORDSET_FormatNumber(struct Strbuf *text, s32 number, u32 topDigitIndex, u32 padMode, u32 isHalfWidth);
void WORDSET_CopyString(const u16 *src, u16 *dst, u32 maxLength);
u32 WORDSET_IsStringEqual(const u16 *left, const u16 *right);
u32 WORDSET_IsPackedString(struct Strbuf *text);
void WORDSET_AppendUnpackedString(struct Strbuf *dst, struct Strbuf *src);
/* END mkheaders: generated region */

#endif
