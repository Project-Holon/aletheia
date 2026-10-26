#ifndef GAME_ARM9_COMM_PLAYER_SUPPORT_H
#define GAME_ARM9_COMM_PLAYER_SUPPORT_H

struct GameData;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of comm_player_support.c, prototypes copied from their definitions. */

struct CommPlayerSupport;
struct MyStatus;
struct PlayerInfo;
struct PeerBook;
struct PlayerLookup;

#include "../types.h"

struct CommPlayerSupport *COMM_PLAYER_SUPPORT_Create(u32 heapId);
void COMM_PLAYER_SUPPORT_Delete(void *support);
void COMM_PLAYER_SUPPORT_Init(struct CommPlayerSupport *support);
void COMM_PLAYER_SUPPORT_SetModeAndCurrent(struct CommPlayerSupport *support, u32 mode, const struct MyStatus *record);
struct MyStatus *COMM_PLAYER_SUPPORT_GetCurrent(struct CommPlayerSupport *support);
u32 COMM_PLAYER_SUPPORT_GetMode(struct CommPlayerSupport *support);
void COMM_PLAYER_SUPPORT_SavePreviousAndSuspend(struct CommPlayerSupport *support);
void COMM_PLAYER_SUPPORT_StashMode(struct CommPlayerSupport *support);
int COMM_PLAYER_SUPPORT_HasSavedMode(const struct CommPlayerSupport *support);
struct MyStatus *COMM_PLAYER_SUPPORT_GetActiveRecord(struct CommPlayerSupport *support);
int COMM_PLAYER_SUPPORT_GetInfoCode(struct PlayerInfo *info);
int COMM_PLAYER_SUPPORT_IsSeasonChanged(struct PlayerInfo *info, u16 *outStored, u16 *outCurrent);
u8 COMM_PLAYER_SUPPORT_GetSeasonFromClock(void);
u8 COMM_PLAYER_SUPPORT_NextSeason(u8 season);
u8 COMM_PLAYER_SUPPORT_PrevSeason(s32 season);
void COMM_PLAYER_SUPPORT_SetSeason(struct GameData *handle, s32 value);
int COMM_PLAYER_SUPPORT_FindPeerRecord(const struct PeerBook *book, struct PlayerLookup *lookup, const u8 *mac);
u16 *COMM_PLAYER_SUPPORT_GetRecordFieldPtr(const struct MyStatus *record);
u16 COMM_PLAYER_SUPPORT_GetRecordField(const struct MyStatus *record);
/* END mkheaders: generated region */

#endif
