#ifndef GAME_OV125_GDS_RAP_H
#define GAME_OV125_GDS_RAP_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gds_rap.c, prototypes copied from their definitions. */

struct BattleRecSave;
struct GameData;

#include "../ov125/gds_rap_types.h"
#include "../ov125/gds_rap_types.h"
#include "../types.h"

int GDS_RAP_Init(GdsRapWork *work, GdsRapInitParams *params);
void GDS_RAP_Exit(GdsRapWork *work);
int GDS_RAP_RequestUploadEntry(GdsRapWork *work, const GdsProfileBlock *profile, const GdsPayloadBlock *payload);
int GDS_RAP_RequestDownloadEntries(GdsRapWork *work, int key);
int GDS_RAP_RequestUploadVideo(GdsRapWork *work, void *profile);
int GDS_RAP_RequestSearchVideos(GdsRapWork *work, int keyId, unsigned int categoryIndex, int mode, u8 flag);
int GDS_RAP_RequestSearchKind1(GdsRapWork *work);
int GDS_RAP_RequestSearchKind2(GdsRapWork *work);
int GDS_RAP_RequestSearchKind3(GdsRapWork *work);
int GDS_RAP_RequestGetVideo(GdsRapWork *work, int dataNumberLo, int dataNumberHi);
int GDS_RAP_RequestMarkVideo(GdsRapWork *work, int dataNumberLo, int dataNumberHi);
int GDS_RAP_Main(GdsRapWork *work);
int GDS_RAP_RunRequest(GdsRapWork *work, int *done);
int GDS_RAP_UpdateSocketState(GdsRapWork *work);
int GDS_RAP_PollNothing(GdsRapWork *work, GdsRapPending *pending);
int GDS_RAP_PollSaveUploadedVideo(GdsRapWork *work, GdsRapPending *pending);
int GDS_RAP_PollNothingAfterError(GdsRapWork *work, GdsRapPending *pending);
void GDS_RAP_ReleaseSession(GdsRapWork *work, int unused, int scene, int unused2);
int GDS_RAP_FindMember(GdsRapWork *work, int index, int *party, int *member);
void GDS_RAP_CopyNickname(const void *src, void *dst, u32 count);
int GDS_RAP_ReadReply(GdsRapWork *work);
int GDS_RAP_GetResult(GdsRapWork *work, GdsRapResult **result);
void GDS_RAP_ClearResult(GdsRapWork *work);
int GDS_RAP_IsIdle(GdsRapWork *work);
/* END mkheaders: generated region */

#endif
