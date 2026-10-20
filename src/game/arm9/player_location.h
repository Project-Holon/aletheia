#ifndef GAME_ARM9_PLAYER_LOCATION_H
#define GAME_ARM9_PLAYER_LOCATION_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of player_location.c, prototypes copied from their definitions. */

struct PlayerLocationData;
struct Location;
struct LocationRecordBuf;
struct LocationRecord;

#include "../types.h"

u32 PLAYER_LOCATION_GetSize(void);
void PLAYER_LOCATION_Init(struct PlayerLocationData *location_data);
struct Location *PLAYER_LOCATION_Nop(u32 situation);
struct Location *PLAYER_LOCATION_GetLocationA(struct PlayerLocationData *location_data);
struct Location *PLAYER_LOCATION_GetLocationB(struct PlayerLocationData *location_data);
u16 *PLAYER_LOCATION_GetShortData(struct PlayerLocationData *location_data);
struct PlayerLocationData *PLAYER_LOCATION_GetData(void *save);
void PLAYER_LOCATION_SetRecordFromBuffer(void *save, const struct LocationRecordBuf *src);
void PLAYER_LOCATION_CopyRecordToBuffer(void *save, struct LocationRecordBuf *dest);
void PLAYER_LOCATION_CopyRecord(void *save, struct LocationRecord *dest);
void PLAYER_LOCATION_ReadFlashActiveFrom(struct PlayerLocationData *location_data, const void *src);
void PLAYER_LOCATION_WriteFlashActiveTo(const struct PlayerLocationData *location_data, void *dest);
void PLAYER_LOCATION_SetSeason(struct PlayerLocationData *location_data, u8 value);
void PLAYER_LOCATION_GetSeason(const struct PlayerLocationData *location_data, u8 *out);
void PLAYER_LOCATION_SetWeatherId(struct PlayerLocationData *location_data, u8 value);
void PLAYER_LOCATION_GetWeatherId(const struct PlayerLocationData *location_data, u8 *out);
void PLAYER_LOCATION_SetEggStepCounter(struct PlayerLocationData *location_data, u32 value);
void PLAYER_LOCATION_GetEggStepCounter(const struct PlayerLocationData *location_data, u32 *out);
u16 PLAYER_LOCATION_GetWalkCounter(const struct PlayerLocationData *location_data);
void PLAYER_LOCATION_SetWalkCounter(struct PlayerLocationData *location_data, u16 value);
void PLAYER_LOCATION_SetStepMessageCount(struct PlayerLocationData *location_data, u16 value);
u16 PLAYER_LOCATION_GetStepMessageCount(const struct PlayerLocationData *location_data);
u16 PLAYER_LOCATION_GetZoneId(const struct PlayerLocationData *location_data);
void PLAYER_LOCATION_SetZoneId(struct PlayerLocationData *location_data, u16 value);
/* END mkheaders: generated region */

#endif
