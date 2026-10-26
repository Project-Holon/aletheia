#ifndef GAME_OV186_BR_NET_H
#define GAME_OV186_BR_NET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of br_net.c, prototypes copied from their definitions. */

struct BrNet;
struct GameData;
union BrNetRequest;
struct BattleRecSave;
struct BrNetTask;

#include "../types.h"
#include "../ov125/gds_rap_types.h"
#include "../ov186/br_types.h"

struct BrNet *BR_NET_Create(struct GameData *gameData, void *profileSource, u16 heapId);
void BR_NET_Destroy(struct BrNet *net);
void BR_NET_Main(struct BrNet *net);
void BR_NET_StartRequest(struct BrNet *net, int kind, const union BrNetRequest *request);
int BR_NET_IsIdle(struct BrNet *net);
int BR_NET_GetDownloadEntries(struct BrNet *net, void **entries, int max, int *count);
u32 BR_NET_GetUploadedDataNumber(struct BrNet *net, u64 *dataNumber);
int BR_NET_GetVideoReply(struct BrNet *net, struct BattleRecSave **video, int *result);
int BR_NET_GetSearchResults(struct BrNet *net, char *buffer, int max, int *count);
int BR_NET_GetSearchResultsForRanking(struct BrNet *net, char *buffer, int max, int *count);
int BR_NET_GetSearchResultsForNewest(struct BrNet *net, char *buffer, int max, int *count);
int BR_NET_PollErrorMessage(struct BrNet *net, int *messageId);
int BR_NET_HandleNetError(struct BrNet *net);
int BR_NET_IsFatal(struct BrNet *net);
void BR_NET_StepIdle(struct BrNetTask *task, u32 *counter, struct BrNet *net);
void BR_NET_StepWaitRequest(struct BrNetTask *task, u32 *counter, struct BrNet *net);
void BR_NET_StepUploadEntry(struct BrNetTask *task, u32 *counter, struct BrNet *net);
void BR_NET_StepDownloadEntries(struct BrNetTask *task, u32 *counter, struct BrNet *net);
void BR_NET_StepUploadVideo(struct BrNetTask *task, u32 *counter, struct BrNet *net);
void BR_NET_StepGetVideo(struct BrNetTask *task, u32 *counter, struct BrNet *net);
void BR_NET_StepSearchVideos(struct BrNetTask *task, u32 *counter, struct BrNet *net);
void BR_NET_StepSearchKind1(struct BrNetTask *task, u32 *counter, struct BrNet *net);
void BR_NET_StepSearchKind3(struct BrNetTask *task, u32 *counter, struct BrNet *net);
void BR_NET_StepSearchKind2(struct BrNetTask *task, u32 *counter, struct BrNet *net);
void BR_NET_StepMarkVideo(struct BrNetTask *task, u32 *counter, struct BrNet *net);
void BR_NET_OnUploadEntry(void *userData, GdsRapResult *result);
void BR_NET_OnDownloadEntries(void *userData, GdsRapResult *result);
void BR_NET_OnUploadVideo(void *userData, GdsRapResult *result);
void BR_NET_OnSearchVideos(void *userData, GdsRapResult *result);
void BR_NET_OnGetVideo(void *userData, GdsRapResult *result);
void BR_NET_OnMarkVideo(void *userData, GdsRapResult *result);
struct BrNetTask *BR_NET_CreateTask(struct BrNet *net, BrNetStepFunc step, u16 heapId);
void BR_NET_DestroyTask(struct BrNetTask *task);
void BR_NET_RunTask(struct BrNetTask *task);
void BR_NET_SetStep(struct BrNetTask *task, BrNetStepFunc step);
int BR_NET_IsStep(struct BrNetTask *task, BrNetStepFunc step);
int BR_NET_OnRapError(void *arg, u32 errorCode, u32 errorKind, int dwcError);
/* END mkheaders: generated region */

#endif
