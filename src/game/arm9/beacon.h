#ifndef GAME_ARM9_BEACON_H
#define GAME_ARM9_BEACON_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of beacon.c, prototypes copied from their definitions. */

struct MiscSave;
struct SaveControl;
struct Strbuf;

#include "../types.h"

u32 MISC_GetSize(void);
void MISC_Init(struct MiscSave *beacon);
struct MiscSave *MISC_GetFromSave(struct SaveControl *save);
struct MiscSave *MISC_GetBlock(struct SaveControl *save);
void MISC_SetInputFlag(struct MiscSave *beacon, u32 index, u8 value);
u8 MISC_GetInputFlag(struct MiscSave *beacon, u32 index);
void MISC_ClearInputFlags(struct MiscSave *beacon);
void MISC_SetMonRecord(struct MiscSave *misc, u16 species, u32 form, u32 isEgg, u32 gender);
void MISC_GetMonRecord(const struct MiscSave *misc, u32 *species, u32 *form, u32 *isEgg, u32 *gender);
u32 MISC_GetBestScore(struct MiscSave *beacon);
void MISC_SetBestScore(struct MiscSave *beacon, u32 score);
u8 MISC_GetRank(struct MiscSave *beacon);
void MISC_SetRank(struct MiscSave *beacon, u32 rank);
u32 MISC_GetGreetCount(struct MiscSave *beacon);
u32 MISC_IncrementGreetCount(struct MiscSave *beacon);
u32 MISC_GetThanksCount(struct MiscSave *beacon);
u32 MISC_IncrementThanksCount(struct MiscSave *beacon);
u16 *MISC_GetGreetMessage(struct MiscSave *beacon);
void MISC_SetGreetMessage(struct MiscSave *beacon, struct Strbuf *message);
u16 *MISC_GetThanksMessage(struct MiscSave *beacon);
void MISC_SetThanksMessage(struct MiscSave *beacon, struct Strbuf *message);
u8 MISC_GetResearchRank(struct MiscSave *beacon);
void MISC_SetResearchRank(struct MiscSave *beacon, u8 mode);
u32 MISC_GetBadge(struct MiscSave *beacon, u32 bit);
void MISC_SetBadge(struct MiscSave *beacon, u32 bit);
u32 MISC_CountBadges(struct MiscSave *beacon);
u32 MISC_GetMoney(struct MiscSave *beacon);
u32 MISC_AddMoney(struct MiscSave *beacon, u32 add);
u32 MISC_SubMoney(struct MiscSave *beacon, u32 sub);
void MISC_SetTeam(struct MiscSave *beacon, u32 index, const u16 *species);
void MISC_GetTeam(struct MiscSave *beacon, u32 index, u16 *species);
void MISC_SetSlotState(struct MiscSave *beacon, u32 slot, u8 state);
u8 MISC_GetSlotState(struct MiscSave *beacon, u32 slot);
u8 MISC_GetSlotStates(struct MiscSave *beacon);
void MISC_SetSlotStates(struct MiscSave *beacon, u8 states);
u8 MISC_GetResearchMissionIndex(struct MiscSave *beacon);
void MISC_SetResearchMissionIndex(struct MiscSave *beacon, u8 count);
int MISC_GetRecentId(struct MiscSave *beacon, u8 index);
void MISC_SetRecentId(struct MiscSave *beacon, u8 index, u8 id);
u16 MISC_GetRecentValue(struct MiscSave *beacon, u32 index);
void MISC_SetRecentValue(struct MiscSave *beacon, u32 index, int value);
void MISC_AddRecentValue(struct MiscSave *beacon, u8 index, int add);
u64 MISC_GetLastTime(struct MiscSave *beacon);
void MISC_SetLastTime(struct MiscSave *beacon, u32 lo, u32 hi);
void MISC_SetHashedId(struct MiscSave *beacon, s32 index, u32 value);
u32 MISC_GetHashedId(struct MiscSave *beacon, s32 index);
u16 MISC_GetGatePoints(struct MiscSave *beacon);
void MISC_SetGatePoints(struct MiscSave *beacon, u16 points);
void MISC_SubGatePoints(struct MiscSave *beacon, u16 sub);
u8 MISC_GetRecorderFlag(struct MiscSave *beacon);
void MISC_SetRecorderFlag(struct MiscSave *beacon, u32 flag);
/* END mkheaders: generated region */

#endif
