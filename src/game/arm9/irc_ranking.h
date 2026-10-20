#ifndef GAME_ARM9_IRC_RANKING_H
#define GAME_ARM9_IRC_RANKING_H

/* Public functions of irc_ranking.c, prototypes copied from their definitions. */

struct IrcRankSave;
struct SaveControl;
struct IrcRankEntry;
struct RTCDate;

#include "../types.h"

struct IrcRankSave *IRC_RANKING_GetFromSave(struct SaveControl *save);
s32 IRC_RANKING_GetEntryCount(struct IrcRankSave *rank);
struct IrcRankEntry *IRC_RANKING_GetEntry(struct IrcRankSave *rank, u32 index);
u8 IRC_RANKING_GetEntryScore(struct IrcRankSave *rank, u32 index);
u16 IRC_RANKING_GetEntryMeetCount(struct IrcRankSave *rank, u32 index);
u32 IRC_RANKING_GetEntryGender(struct IrcRankSave *rank, u32 index);
void IRC_RANKING_GetEntryProfile(const struct IrcRankEntry *entries, u32 index, u16 *outWord, u8 *outByte, u8 *outBits, u8 *outFlag);
u8 IRC_RANKING_GetLastSlot(struct IrcRankSave *rank);
int IRC_RANKING_FindClosestEntry(struct IrcRankSave *rank, u32 month, u32 day, struct RTCDate *today);
int IRC_RANKING_IsEntryNew(struct IrcRankEntry *entries, u32 trainerId);
int IRC_RANKING_HasEntry(struct IrcRankEntry *entries, u32 trainerId);
u8 IRC_RANKING_GetDateScore(u32 month, u32 day, struct RTCDate *today);
u8 IRC_RANKING_AddEntry(struct IrcRankSave *rank, const void *name, u16 score, u8 gender, u8 language, u8 version, u32 trainerId, u16 profileWord, u8 profileByte, u8 profileBits, u8 profileFlag);
void IRC_RANKING_ClearNewFlags(struct IrcRankEntry *entries);
int IRC_RANKING_GetSize(void);
void IRC_RANKING_Init(struct IrcRankSave *rank);
u8 IRC_RANKING_InsertEntry(struct IrcRankEntry *list, s32 count, struct IrcRankEntry *entry);
int IRC_RANKING_HasEntryByTrainerId(struct IrcRankEntry *list, int count, struct IrcRankEntry *entry);
void IRC_RANKING_InitEntry(struct IrcRankEntry *entry, const void *name, u32 score, u32 meetCount, u8 gender, u8 language, u8 version, u32 trainerId, u16 profileWord, u8 profileByte, u8 profileBits, u8 profileFlag);
struct IrcRankEntry *IRC_RANKING_FindEntryByTrainerId(struct IrcRankEntry *list, int count, int trainerId);
void IRC_RANKING_UpdateEntryMeetCount(struct IrcRankEntry *list, int total, struct IrcRankEntry *entry);

#endif
