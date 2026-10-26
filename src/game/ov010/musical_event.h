#ifndef GAME_OV010_MUSICAL_EVENT_H
#define GAME_OV010_MUSICAL_EVENT_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of musical_event.c, prototypes copied from their definitions. */

struct GameEvent;
struct MusicalLink;
struct MusicalEventWork;
typedef struct MusicalLink MusicalLink;
typedef struct MusicalEventWork MusicalEventWork;

#include "../types.h"
#include "../ov010/musical_event_shared_types.h"

struct GameEvent *MUSICAL_EVENT_Create(void *gameSys, void *gameData, u8 partyIndex, u32 linkMode, MusicalLink *link);
int MUSICAL_EVENT_Main(struct GameEvent *event, int *unused, void *work);
void MUSICAL_EVENT_CreateLocalPerformer(MusicalEventWork *work);
MusicalLink *MUSICAL_EVENT_Free(MusicalEventWork *work);
MusicalDressupParam *MUSICAL_EVENT_CreateDressupParam(MusicalEventWork *work);
void MUSICAL_EVENT_SendLocalPerformer(MusicalEventWork *work);
void MUSICAL_EVENT_CreateStage(MusicalEventWork *work);
void MUSICAL_EVENT_ScorePerformers(MusicalEventWork *work);
void MUSICAL_EVENT_CreateShowRecord(MusicalEventWork *work);
void MUSICAL_EVENT_ApplyResults(MusicalEventWork *work);
void MUSICAL_EVENT_RollProgramRewards(MusicalEventWork *work);
int MUSICAL_EVENT_RunLeaveSequence(void *event, MusicalEventWork *work);
int MUSICAL_EVENT_RunEnterSequence(void *event, MusicalEventWork *work);
void MUSICAL_EVENT_SpawnSeatEffect(void *event, MusicalEventWork *work);
void MUSICAL_EVENT_SpawnExitEffect(void *event, MusicalEventWork *work);
void MUSICAL_EVENT_ShowMessage(void *event, MusicalEventWork *work, int messageId);
u8 MUSICAL_EVENT_CountNpcSlotsBelow(MusicalEventWork *work, u8 n);
u8 MUSICAL_EVENT_GetLocalSlot(MusicalEventWork *work);
u8 MUSICAL_EVENT_GetPlayerOfSlot(MusicalEventWork *work, u8 slot);
u8 MUSICAL_EVENT_GetProgramBestCategory(MusicalEventWork *work);
void *MUSICAL_EVENT_AllocTitleString(MusicalEventWork *work, int heapId);
u8 MUSICAL_EVENT_GetScoreCapped(MusicalEventWork *work, u8 slot);
u16 MUSICAL_EVENT_GetMaxScore(MusicalEventWork *work);
u16 MUSICAL_EVENT_GetMinScore(MusicalEventWork *work);
u8 MUSICAL_EVENT_GetSlotOfRank(MusicalEventWork *work, u8 rank);
u8 MUSICAL_EVENT_GetBestAppealCategory(MusicalEventWork *work, u8 slot);
u8 MUSICAL_EVENT_GetPortraitClass(MusicalEventWork *work, u8 slot);
void MUSICAL_EVENT_SetPlayerNameWord(MusicalEventWork *work, u8 slot, void *wordSet, u32 wordIndex);
void MUSICAL_EVENT_SetPokemonNameWord(MusicalEventWork *work, u8 slot, void *wordSet, u32 wordIndex);
void MUSICAL_EVENT_ReceiveShowProgram(MusicalEventWork *work);
void MUSICAL_EVENT_CheckNetError(MusicalEventWork *work);
u32 MUSICAL_EVENT_IsAborted(MusicalEventWork *work);
/* END mkheaders: generated region */

#endif
