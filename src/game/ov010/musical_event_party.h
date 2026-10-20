#ifndef GAME_OV010_MUSICAL_EVENT_PARTY_H
#define GAME_OV010_MUSICAL_EVENT_PARTY_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of musical_event_party.c, prototypes copied from their definitions. */

struct MusicalEventWork;
struct GameData;
struct GameSystem;

void MUSICAL_EVENT_SetPartyLevel50(void *party);
void MUSICAL_EVENT_BuildParty(int partySource, struct MusicalEventWork *work);
void MUSICAL_EVENT_TrimPartyToThree(void *party);
void MUSICAL_EVENT_TrimAllPartiesToThree(struct MusicalEventWork *work);
void MUSICAL_EVENT_UpdateFriendRecords(struct MusicalEventWork *work, struct GameData *gameData);
void MUSICAL_EVENT_BindParticipantSlots(struct MusicalEventWork *work, struct GameSystem *gameSystem);
/* END mkheaders: generated region */

#endif
