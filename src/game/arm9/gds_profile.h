#ifndef GAME_ARM9_GDS_PROFILE_H
#define GAME_ARM9_GDS_PROFILE_H

#include "../types.h"

struct GdsProfile *GDS_PROFILE_Create(u32 heap);

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gds_profile.c, prototypes copied from their definitions. */

struct GdsProfile;
struct StoredMon;
struct GdsProfileRaw;
struct GdsRecord;
struct BsubwayPlayData;
struct BsubwayScoreData;
struct GdsScoreSrc;
struct BsubwayWifiData;
struct Stamp;

#include "../types.h"

struct GdsProfile *GDS_PROFILE_Create(u32 heap);
void GDS_PROFILE_Delete(struct GdsProfile *profile);
void GDS_PROFILE_Init(struct GdsProfile *profile, void *sys);
void *GDS_PROFILE_CreateNameStr(const void *src, u32 tag);
u32 GDS_PROFILE_GetEggFlag(struct StoredMon *p);
u32 GDS_PROFILE_GetSpecies(struct StoredMon *p);
u32 GDS_PROFILE_GetFormSpecies(struct StoredMon *p);
u32 GDS_PROFILE_GetNicknameFlag(struct StoredMon *p);
u32 GDS_PROFILE_GetBadEggFlag(struct StoredMon *p);
u32 GDS_PROFILE_GetValidatedCountry(struct GdsProfileRaw *p);
u32 GDS_PROFILE_GetValidatedRegion(struct GdsProfileRaw *p);
void *GDS_PROFILE_ExportRecord(struct GdsProfileRaw *p, struct GdsRecord *out, u32 tag);
u32 GDS_PROFILE_GetBirthMonth(struct GdsProfileRaw *p);
u32 GDS_PROFILE_GetTrainerSprite(struct GdsProfileRaw *p);
u32 GDS_PROFILE_GetLanguage(struct GdsProfileRaw *p);
u32 BSUBWAY_PLAYDATA_GetSize(void);
void BSUBWAY_PLAYDATA_Init(struct BsubwayPlayData *p);
void BSUBWAY_PLAYDATA_SetFlag01(struct BsubwayPlayData *p, u32 v);
u32 BSUBWAY_PLAYDATA_GetFlag01(struct BsubwayPlayData *p);
u32 BSUBWAY_PLAYDATA_GetField(struct BsubwayPlayData *p, u32 id, void *out);
void BSUBWAY_PLAYDATA_SetField(struct BsubwayPlayData *p, u32 id, const void *src);
void BSUBWAY_PLAYDATA_AddCounters(struct BsubwayPlayData *p, s32 a, s32 b, s32 c);
void BSUBWAY_PLAYDATA_ClearRound(struct BsubwayPlayData *p);
void BSUBWAY_PLAYDATA_IncRound(struct BsubwayPlayData *p);
u16 BSUBWAY_PLAYDATA_GetRound(struct BsubwayPlayData *p);
u32 BSUBWAY_SCOREDATA_GetSize(void);
void BSUBWAY_SCOREDATA_Init(struct BsubwayScoreData *p);
void BSUBWAY_SCOREDATA_AddBattlePoints(struct BsubwayScoreData *p, s32 v);
void BSUBWAY_SCOREDATA_SubBattlePoints(struct BsubwayScoreData *p, u16 v);
u16 BSUBWAY_SCOREDATA_GetBattlePoints(struct BsubwayScoreData *p);
u32 BSUBWAY_SCOREDATA_MapPlayMode(u32 i);
u16 BSUBWAY_SCOREDATA_GetWinCount(struct BsubwayScoreData *p, u32 i);
u16 BSUBWAY_SCOREDATA_GetMaxWinCount(struct BsubwayScoreData *p, u32 i);
void BSUBWAY_SCOREDATA_UpdateMaxWinCount(struct BsubwayScoreData *p, u32 i, u16 v);
void BSUBWAY_SCOREDATA_SetWinCount(struct BsubwayScoreData *p, u32 i, u16 v);
void BSUBWAY_SCOREDATA_ResetClearCount(struct BsubwayScoreData *p, u32 i);
void BSUBWAY_SCOREDATA_SetFirstClear(struct BsubwayScoreData *p, u32 i);
u32 BSUBWAY_SCOREDATA_HasCleared(struct BsubwayScoreData *p, u32 i);
void BSUBWAY_SCOREDATA_IncClearCount(struct BsubwayScoreData *p, u32 i);
u16 BSUBWAY_SCOREDATA_GetRepeatClearCount(struct BsubwayScoreData *p, u32 i);
u32 BSUBWAY_SCOREDATA_AccessFlag(struct BsubwayScoreData *p, s32 i, u32 op);
void BSUBWAY_SCOREDATA_IncLevel(struct BsubwayScoreData *p);
void BSUBWAY_SCOREDATA_DecLevel(struct BsubwayScoreData *p);
u8 BSUBWAY_SCOREDATA_GetLevel(struct BsubwayScoreData *p);
u8 BSUBWAY_SCOREDATA_UpdateStreak(struct BsubwayScoreData *p, u32 kind);
void BSUBWAY_SCOREDATA_SetRecordBlob(struct BsubwayScoreData *p, u32 which, const void *src);
void BSUBWAY_SCOREDATA_GetRecordBlob(struct BsubwayScoreData *p, u32 which, void *dest);
void BSUBWAY_SCOREDATA_CalcRecordScore(struct BsubwayScoreData *p, const struct GdsScoreSrc *q);
u16 BSUBWAY_SCOREDATA_GetRecordScore(struct BsubwayScoreData *p);
u8 BSUBWAY_SCOREDATA_GetRecordScoreTier(struct BsubwayScoreData *p);
u32 BSUBWAY_WIFIDATA_GetSize(void);
void BSUBWAY_WIFIDATA_Init(struct BsubwayWifiData *p);
void BSUBWAY_WIFIDATA_SetTrainerBit(u8 *p, u8 a, u8 b, u32 *q);
void BSUBWAY_WIFIDATA_ClearStampAndBitmap(struct BsubwayWifiData *p);
u32 BSUBWAY_WIFIDATA_IsStampNewer(const struct Stamp *a, const struct Stamp *b);
int BSUBWAY_WIFIDATA_GetTrainerBit(struct BsubwayWifiData *p, u8 a, u8 b, const struct Stamp *q);
/* END mkheaders: generated region */

#endif
