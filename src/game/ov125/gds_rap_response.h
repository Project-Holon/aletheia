#ifndef GAME_OV125_GDS_RAP_RESPONSE_H
#define GAME_OV125_GDS_RAP_RESPONSE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gds_rap_response.c, prototypes copied from their definitions. */

struct BattleRecSave;
struct GameData;

#include "../ov125/gds_rap_types.h"
#include "../ov125/gds_rap_types.h"
#include "../types.h"

int GDS_RAP_CheckUploadEntryReply(GdsRapWork *work, const GdsReply *reply);
int GDS_RAP_CheckDownloadEntriesReply(GdsRapWork *work, const GdsReply *reply);
int GDS_RAP_GetDownloadEntries(GdsRapWork *work, void **entries, int max);
int GDS_RAP_CheckUploadVideoReply(GdsRapWork *work, const GdsReply *reply);
u64 GDS_RAP_GetUploadedDataNumber(GdsRapWork *work);
int GDS_RAP_CheckSearchVideosReply(GdsRapWork *work, const GdsReply *reply);
int GDS_RAP_GetSearchResults(GdsRapWork *work, char *dst, int max);
int GDS_RAP_CheckGetVideoReply(GdsRapWork *work, const GdsReply *reply);
int GDS_RAP_GetVideoReply(GdsRapWork *work, struct BattleRecSave **video);
int GDS_RAP_CheckMarkVideoReply(GdsRapWork *work, const GdsReply *reply);
int GDS_RAP_SaveVideoSeq(struct GameData *gameData, int id, int mode, u16 *state, u16 *seq, u16 heap);
void GDS_RAP_EncodeVideoBody(void);
int GDS_RAP_SaveVideoWithDataNumber(struct GameData *gameData, int dataNumberLo, int dataNumberHi, u16 *state, u16 *seq, u16 heap);
int GDS_RAP_SaveVideoSecured(struct GameData *gameData, int id, u16 *state, u16 *seq, u16 heap);
void GDS_RAP_StartVideoSave(struct GameData *gameData, u8 heap, u32 id);
int GDS_RAP_StepVideoSave(struct GameData *gameData, int id);
struct BattleRecSave *GDS_RAP_GetVideoWork(void);
/* END mkheaders: generated region */

#endif
