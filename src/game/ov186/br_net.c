/*
 * file:     br_net.c
 * unit:     yes
 * function: BR_NET_Create, BR_NET_Destroy, BR_NET_Main, BR_NET_StartRequest, BR_NET_IsIdle, BR_NET_GetDownloadEntries, BR_NET_GetUploadedDataNumber, BR_NET_GetVideoReply, BR_NET_GetSearchResults, BR_NET_GetSearchResultsForRanking, BR_NET_GetSearchResultsForNewest, BR_NET_PollErrorMessage, BR_NET_HandleNetError, BR_NET_IsFatal, BR_NET_StepIdle, BR_NET_StepWaitRequest, BR_NET_StepUploadEntry, BR_NET_StepDownloadEntries, BR_NET_StepUploadVideo, BR_NET_StepGetVideo, BR_NET_StepSearchVideos, BR_NET_StepSearchKind1, BR_NET_StepSearchKind3, BR_NET_StepSearchKind2, BR_NET_StepMarkVideo, BR_NET_OnUploadEntry, BR_NET_OnDownloadEntries, BR_NET_OnUploadVideo, BR_NET_OnSearchVideos, BR_NET_OnGetVideo, BR_NET_OnMarkVideo, BR_NET_CreateTask, BR_NET_DestroyTask, BR_NET_RunTask, BR_NET_SetStep, BR_NET_IsStep, BR_NET_OnRapError
 * address:  0x021FF408
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from br_proc_sys.c, br_btn.c, br_graphic.c, br_util.c, br_net.c, BR_MEMBER_COUNT_GetU16Count.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_NET_Create 0x021FF408 thumb ov186
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   ov125_id 0x0000007D data
 *   BR_NET_IsFatal 0x021FF8D4 thumb ov186
 *   BR_NET_Destroy 0x021FF4E4 thumb ov186
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   BR_NET_Main 0x021FF52C thumb ov186
 *   GF_PANIC_Fail 0x02034714 arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   GDS_PROFILE_Init 0x0200D5D0 thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   MYSTATUS_GetProfileId 0x0200853C thumb
 *   GDS_RAP_Init 0x021D6660 thumb ov125
 *   GDS_PROFILE_Create 0x0200D59C thumb
 *   DWC_RAP_SetErrorHookCallback 0x02156DE0 thumb ov009
 *   gBrNetSourceFile 0x02200D8C data a1
 *   GDS_PROFILE_Delete 0x0200D5C8 thumb
 *   GDS_RAP_Exit 0x021D6770 thumb ov125
 *   GDS_RAP_Main 0x021D6A34 thumb ov125
 *   gBrNetAssertString 0x02200D98 data a1
 *   GDS_RAP_GetDownloadEntries  0x021D7374  thumb  ov125
 *   GDS_RAP_GetUploadedDataNumber 0x021D73E0 thumb ov125
 *   GDS_RAP_GetVideoReply  0x021D74D8  thumb  ov125
 *   GDS_RAP_GetSearchResults 0x021D7414 thumb ov125
 *   GDS_RAP_GetResult 0x021D72EC thumb ov125
 *   GDS_RAP_ClearResult 0x021D72F8 thumb ov125
 *   GFL_USE_StopAllSe 0x02006210 thumb
 *   GFL_NET_ERR_RaiseFatal 0x0200FB4C thumb
 *   DWC_RAPCOMMON_HandleNetError 0x02157170 thumb ov009
 *   GFL_NET_ERR_Halt 0x0200F7DC thumb
 *   GDS_RAP_IsIdle  0x021D730C  thumb  ov125
 *   GDS_RAP_RequestUploadEntry 0x021D67C8 thumb ov125
 *   GDS_RAP_RequestDownloadEntries 0x021D6814 thumb ov125
 *   GDS_RAP_RequestUploadVideo 0x021D683C thumb ov125
 *   GDS_RAP_RequestGetVideo 0x021D69DC thumb ov125
 *   GDS_RAP_RequestSearchVideos 0x021D68EC thumb ov125
 *   GDS_RAP_RequestSearchKind1 0x021D6968 thumb ov125
 *   GDS_RAP_RequestSearchKind3 0x021D69B4 thumb ov125
 *   GDS_RAP_RequestSearchKind2 0x021D698C thumb ov125
 *   GDS_RAP_RequestMarkVideo 0x021D6A08 thumb ov125
 *   GAME_DATA_IsSaving 0x02012E40 thumb
 *   GDS_RAP_ReleaseSession 0x021D7124 thumb ov125
 */
#include "br_types.h"

#include "../arm9/gf_overlay.h"

struct GameData;
struct SaveControl;

#include "../arm9/game_data.h"
struct GdsProfile;

#include "../arm9/gds_profile.h"

extern char ov125_id[];

#include "../arm9/mi_memory.h"

#include "../arm9/gfl_heap_wrap.h"

struct MyStatus;


#include "../arm9/mystatus.h"



typedef int (*BrNetErrorHook)(struct BrNet *net, int unused, int errorKind, int unused2);

extern void DWC_RAP_SetErrorHookCallback(BrNetErrorHook hook, unsigned int hookArg);

#include "../arm9/gf_panic.h"

#include "../arm9/gfl_use.h"

#include "../arm9/net_err.h"

#include "../ov009/dwc_rapcommon.h"



#include "../ov125/gds_rap.h"




















extern const char gBrNetSourceFile[];

extern const char gBrNetAssertString[];

/* Message id bases added to the error code of a GDS reply (see BR_NET_PollErrorMessage). */
#define BR_NET_MSG_SOCKET_ERROR 283
#define BR_NET_MSG_ABORTED 298
#define BR_NET_MSG_UPLOAD_ENTRY 230
#define BR_NET_MSG_DOWNLOAD_ENTRIES 237
#define BR_NET_MSG_UPLOAD_VIDEO 261
#define BR_NET_MSG_SEARCH_VIDEOS 269
#define BR_NET_MSG_GET_VIDEO 274

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

int BR_NET_OnRapError(struct BrNet *net, int unused, int errorKind, int unused2);

typedef char BrNetCheckSize[sizeof(struct BrNet) == 0x5E4 ? 1 : -1];
typedef char BrNetCheckRequest[sizeof(union BrNetRequest) == 8 ? 1 : -1];
typedef char BrNetCheckTask[sizeof(struct BrNetTask) == 0x10 ? 1 : -1];

/*
 * Layout: original fills 0x2c bytes of local config and allocates 0x5e4-byte context. Callback table occupies its final seven words.
 */
struct BrNet *BR_NET_Create(struct GameData *gameData, void *profileSource, u16 heapId)
{
    struct BrNet *net;
    GdsRapInitParams params;
    GF_OVERLAY_Load((sptr)ov125_id);
    net=GFL_HEAP_Alloc(heapId,sizeof(struct BrNet),0,gBrNetSourceFile,0x97);
    MI_CpuFill8(net,0,sizeof(struct BrNet));
    net->gameData=gameData;
    MI_CpuFill8(&params,0,sizeof(GdsRapInitParams));
    params.gameData=gameData;
    params.profileId=MYSTATUS_GetProfileId(GAME_DATA_GetMyStatus(gameData));
    params.profileSource=profileSource;
    params.callbacks.userData=net;
    params.callbacks.onUploadEntry=BR_NET_OnUploadEntry;
    params.callbacks.onDownloadEntries=BR_NET_OnDownloadEntries;
    params.callbacks.onUploadVideo=BR_NET_OnUploadVideo;
    params.callbacks.onSearchVideos=BR_NET_OnSearchVideos;
    params.callbacks.onGetVideo=BR_NET_OnGetVideo;
    params.callbacks.onMarkVideo=BR_NET_OnMarkVideo;
    GDS_RAP_Init(&net->rap,&params);
    net->rapActive=1;
    GAME_DATA_GetSaveControl(gameData);
    net->profile=GDS_PROFILE_Create(heapId);
    GDS_PROFILE_Init(net->profile,gameData);
    net->task=BR_NET_CreateTask(net,BR_NET_StepIdle,heapId);
    DWC_RAP_SetErrorHookCallback(BR_NET_OnRapError,(uptr)net);
    return net;
}

void BR_NET_Destroy(struct BrNet *net)
{
    DWC_RAP_SetErrorHookCallback(0, 0);
    BR_NET_DestroyTask(net->task);
    GDS_PROFILE_Delete(net->profile);
    if (net->rapActive) {
        GDS_RAP_Exit(&net->rap);
        net->rapActive = 0;
    }
    GFL_HEAP_Free(net);
    GF_OVERLAY_Unload((sptr)ov125_id);
}

void BR_NET_Main(struct BrNet *net)
{
    if(net->rapActive){
        BR_NET_RunTask(net->task);
        GDS_RAP_Main(&net->rap);
    }
}

/*
 * Extent: 252 bytes; the listing extent of 276 includes the separately filed BR_NET_IsIdle at +0xFC.
 * recoup 2026-10-05: the 8-byte payload copy as one struct assignment gives the original r2/r1 load colours; two int stores gave r1/r1 (2 bytes off). Struct copy is a plausible human form. EXACT* only because of the 276 vs 252 listing extent.
 */
void BR_NET_StartRequest(struct BrNet *net, int kind, const union BrNetRequest *request)
{
    if(kind>=BR_NET_REQUEST_COUNT)GF_PANIC_Fail(gBrNetAssertString,0,gBrNetAssertString);
    if(request){
        net->request=*request;
    }
    MI_CpuFill8(&net->uploadEntryDone,0,0x24);
    switch(kind){
    case BR_NET_REQUEST_UPLOAD_ENTRY:BR_NET_SetStep(net->task,BR_NET_StepUploadEntry);break;
    case BR_NET_REQUEST_DOWNLOAD_ENTRIES:BR_NET_SetStep(net->task,BR_NET_StepDownloadEntries);break;
    case BR_NET_REQUEST_UPLOAD_VIDEO:BR_NET_SetStep(net->task,BR_NET_StepUploadVideo);break;
    case BR_NET_REQUEST_GET_VIDEO:BR_NET_SetStep(net->task,BR_NET_StepGetVideo);break;
    case BR_NET_REQUEST_SEARCH_VIDEOS:BR_NET_SetStep(net->task,BR_NET_StepSearchVideos);break;
    case BR_NET_REQUEST_SEARCH_KIND1:BR_NET_SetStep(net->task,BR_NET_StepSearchKind1);break;
    case BR_NET_REQUEST_SEARCH_KIND3:BR_NET_SetStep(net->task,BR_NET_StepSearchKind3);break;
    case BR_NET_REQUEST_SEARCH_KIND2:BR_NET_SetStep(net->task,BR_NET_StepSearchKind2);break;
    case BR_NET_REQUEST_MARK_VIDEO:BR_NET_SetStep(net->task,BR_NET_StepMarkVideo);break;
    default:GF_PANIC_Fail(gBrNetAssertString,0,gBrNetAssertString);break;
    }
}

int BR_NET_IsIdle(struct BrNet *net)
{
    return BR_NET_IsStep(net->task,BR_NET_StepIdle);
}

int BR_NET_GetDownloadEntries(struct BrNet *net, void **entries, int max, int *count)
{
    int done = net->downloadEntriesDone;

    if (done != 0)
        *count = GDS_RAP_GetDownloadEntries(&net->rap, entries, max);
    return done;
}

u32 BR_NET_GetUploadedDataNumber(struct BrNet *net, u64 *dataNumber)
{
    u32 done;
    done=net->uploadVideoDone;
    if(done)*dataNumber=GDS_RAP_GetUploadedDataNumber(&net->rap);
    return done;
}

/*
 * Earlier blocker (closed): 5 bytes, a pure r4/r5 swap.  The original keeps the out pointer
 * in r4 and the field value in r5; every spelling tried (named pointer copy,
 * reversed declarations, int index, inline re-read) makes this compiler put
 * the field value in r4 and the pointer in r5, because the loaded value is
 *   the first live temporary while the pointer (arg r2) is spilled to the
 *   highest callee-saved register.  `cmp`-style naming does not move it.
 *   Re-verified (DIFF fixer): declaration order v-then-o, assignment o-then-v,
 *   and dropping the `o` alias to store through `out` directly all still swap
 *   r4/r5 the same way.
 *
 * 2026-10-05: tried a local k=0x5c4 reused as the call argument, pointer-typed value, u32 types, struct field access, early return for v==0, static inline getter, out alias inside the if. All still give out in r5 and value in r4 (original: out r4, value r5). Residue unchanged: 5 bytes, pure r4/r5 swap.
 *
 * 2026-10-05 (D9-14): closed. The swap was a wrong callee arity: GDS_RAP_GetVideoReply
 *   (matched in ov125) takes two arguments; the 0x5c4 in r2 at the call is only the
 *   leftover offset register. Two-argument call, no alias local: EXACT.
 */
int BR_NET_GetVideoReply(struct BrNet *net, struct BattleRecSave **video, int *result)
{
    int done = net->getVideoDone;

    if (done != 0)
        *result = GDS_RAP_GetVideoReply(&net->rap, video);
    return done;
}

int BR_NET_GetSearchResults(struct BrNet *net, char *buffer, int max, int *count)
{
    int done;
    done=net->searchVideosDone;
    if(done)*count=GDS_RAP_GetSearchResults(&net->rap,buffer,max);
    if(*count!=0 && done!=0)return 1;
    return 0;
}

int BR_NET_GetSearchResultsForRanking(struct BrNet *net, char *buffer, int max, int *count)
{
    int done;
    done=net->searchVideosDone;
    if(done)*count=GDS_RAP_GetSearchResults(&net->rap,buffer,max);
    if(*count!=0 && done!=0)return 1;
    return 0;
}

int BR_NET_GetSearchResultsForNewest(struct BrNet *net, char *buffer, int max, int *count)
{
    int done;
    done=net->searchVideosDone;
    if(done)*count=GDS_RAP_GetSearchResults(&net->rap,buffer,max);
    if(*count!=0 && done!=0)return 1;
    return 0;
}

/*
 * Returns 0 when nothing is pending, 1 to retry, 2 for an error with a message
 * id in *messageId, 3 when the error was fatal.
 * note: pass 4 2026-10-06 P4L01: EXACT (also with --lang c). Case 1 works on a block local copy of the
 *   result (`int r=result; ... r=1; ... result=r;`). The final `result=r` is a register copy that the
 *   allocator coalesces away, so the block after case 1's if is empty only after allocation; it is then
 *   merged into case 1's copy block, which gives that block a new (front of list) edge to the release
 *   join. The cross-jump keeps the first predecessor in the join's list, so case 1's `movs r5,#1` keeps
 *   and case 0's after-store copy and 22002's copy become hops onto it (the image's forward hop at +002E).
 *   Earlier forms (2 B off) kept case 0's copy, the earliest original edge.
 */
int BR_NET_PollErrorMessage(struct BrNet *net, int *messageId)
{
    GdsRapResult *event;
    int result;
    if(GDS_RAP_GetResult(&net->rap,&event)){
        result=1;
        if(event->errorKind==0){
            if(event->errorCode){
                if(messageId)*messageId=event->errorCode+BR_NET_MSG_SOCKET_ERROR;
                result=1;
            }
        }else if(event->errorKind==1){
            int r=result;
            if(event->errorCode==7){
                if(messageId)*messageId=event->errorCode+BR_NET_MSG_ABORTED;
                r=1;
            }
            result=r;
        }else if(event->errorKind==2){
            switch(event->requestId){
            case GDS_REQUEST_UPLOAD_ENTRY:
                if(event->errorCode){if(messageId)*messageId=event->errorCode+BR_NET_MSG_UPLOAD_ENTRY;result=2;}
                break;
            case GDS_REQUEST_DOWNLOAD_ENTRIES:
                if(event->errorCode){if(messageId)*messageId=event->errorCode+BR_NET_MSG_DOWNLOAD_ENTRIES;result=2;}
                break;
            case GDS_REQUEST_UPLOAD_VIDEO:
                if(event->errorCode){
                    switch(event->errorCode){
                    case 150:GFL_USE_StopAllSe();GFL_NET_ERR_RaiseFatal(65);result=3;break;
                    case 151:GFL_USE_StopAllSe();GFL_NET_ERR_RaiseFatal(66);result=3;break;
                    case 152:GFL_USE_StopAllSe();GFL_NET_ERR_RaiseFatal(68);result=3;break;
                    case 153:GFL_USE_StopAllSe();GFL_NET_ERR_RaiseFatal(67);result=3;break;
                    default:if(messageId)*messageId=event->errorCode+BR_NET_MSG_UPLOAD_VIDEO;result=2;break;
                    }
                }
                break;
            case GDS_REQUEST_SEARCH_VIDEOS:
                if(event->errorCode){if(messageId)*messageId=event->errorCode+BR_NET_MSG_SEARCH_VIDEOS;result=2;}
                break;
            case GDS_REQUEST_GET_VIDEO:
                if(event->errorCode){if(messageId)*messageId=event->errorCode+BR_NET_MSG_GET_VIDEO;result=1;}
                break;
            case GDS_REQUEST_MARK_VIDEO:result=0;break;
            }
        }
        GDS_RAP_ClearResult(&net->rap);
        if(result==3)net->fatal=1;
        return result;
    }
    return 0;
}

int BR_NET_HandleNetError(struct BrNet *net)
{
    if (!net) return 0;
    switch (DWC_RAPCOMMON_HandleNetError(1, 0)) {
    case 1: GFL_USE_StopAllSe(); return 1;
    case 2: GFL_USE_StopAllSe(); net->fatal = 1; return 2;
    case 3: GFL_USE_StopAllSe(); GFL_NET_ERR_Halt(); break;
    }
    return 0;
}

int BR_NET_IsFatal(struct BrNet *net)
{
    return net->fatal;
}

void BR_NET_StepIdle(struct BrNetTask *task, u32 *counter, struct BrNet *net)
{
}

/*
 * 0x021FF8E0 is an unlabelled two-byte `bx lr` leaf reached through the pool
 * word 0x021FF8E1 (thumb bit set); now matched as src/matched/BR_NET_StepIdle.c.
 */
void BR_NET_StepWaitRequest(struct BrNetTask *task, u32 *counter, struct BrNet *net)
{
    if (GDS_RAP_IsIdle(&net->rap) != 0)
        BR_NET_SetStep(task, BR_NET_StepIdle);
}

void BR_NET_StepUploadEntry(struct BrNetTask *task, u32 *counter, struct BrNet *net)
{
    if(!GDS_RAP_RequestUploadEntry(&net->rap,(const GdsProfileBlock *)net->profile,net->request.payload))
        GF_PANIC_Fail(gBrNetAssertString,0,gBrNetAssertString);
    BR_NET_SetStep(task,BR_NET_StepWaitRequest);
}

void BR_NET_StepDownloadEntries(struct BrNetTask *task, u32 *counter, struct BrNet *net)
{
    if(!GDS_RAP_RequestDownloadEntries(&net->rap,net->request.downloadKey))
        GF_PANIC_Fail(gBrNetAssertString,0,gBrNetAssertString);
    BR_NET_SetStep(task,BR_NET_StepWaitRequest);
}

void BR_NET_StepUploadVideo(struct BrNetTask *task, u32 *counter, struct BrNet *net)
{
    if(!GDS_RAP_RequestUploadVideo(&net->rap,net->profile))
        GF_PANIC_Fail(gBrNetAssertString,0,gBrNetAssertString);
    BR_NET_SetStep(task,BR_NET_StepWaitRequest);
}

void BR_NET_StepGetVideo(struct BrNetTask *task, u32 *counter, struct BrNet *net)
{
    if(!GDS_RAP_RequestGetVideo(&net->rap,net->request.dataNumber.lo,net->request.dataNumber.hi))
        GF_PANIC_Fail(gBrNetAssertString,0,gBrNetAssertString);
    BR_NET_SetStep(task,BR_NET_StepWaitRequest);
}

void BR_NET_StepSearchVideos(struct BrNetTask *task, u32 *counter, struct BrNet *net)
{
    if (!GDS_RAP_RequestSearchVideos(&net->rap, net->request.search.keyId, net->request.search.category, net->request.search.mode, net->request.search.flag))
        GF_PANIC_Fail(gBrNetAssertString, 0, gBrNetAssertString);
    BR_NET_SetStep(task, BR_NET_StepWaitRequest);
}

void BR_NET_StepSearchKind1(struct BrNetTask *task, u32 *counter, struct BrNet *net)
{
    if(!GDS_RAP_RequestSearchKind1(&net->rap))
        GF_PANIC_Fail(gBrNetAssertString,0,gBrNetAssertString);
    BR_NET_SetStep(task,BR_NET_StepWaitRequest);
}

void BR_NET_StepSearchKind3(struct BrNetTask *task, u32 *counter, struct BrNet *net)
{
    if(!GDS_RAP_RequestSearchKind3(&net->rap))
        GF_PANIC_Fail(gBrNetAssertString,0,gBrNetAssertString);
    BR_NET_SetStep(task,BR_NET_StepWaitRequest);
}

void BR_NET_StepSearchKind2(struct BrNetTask *task, u32 *counter, struct BrNet *net)
{
    if(!GDS_RAP_RequestSearchKind2(&net->rap))
        GF_PANIC_Fail(gBrNetAssertString,0,gBrNetAssertString);
    BR_NET_SetStep(task,BR_NET_StepWaitRequest);
}

void BR_NET_StepMarkVideo(struct BrNetTask *task, u32 *counter, struct BrNet *net)
{
    if (!GDS_RAP_RequestMarkVideo(&net->rap, net->request.dataNumber.lo, net->request.dataNumber.hi))
        GF_PANIC_Fail(gBrNetAssertString, 0, gBrNetAssertString);
    BR_NET_SetStep(task, BR_NET_StepWaitRequest);
}

void BR_NET_OnUploadEntry(void *userData, GdsRapResult *result) { ((struct BrNet *)userData)->uploadEntryDone = 1; }

void BR_NET_OnDownloadEntries(void *userData, GdsRapResult *result) { ((struct BrNet *)userData)->downloadEntriesDone = 1; }

void BR_NET_OnUploadVideo(void *userData, GdsRapResult *result) { ((struct BrNet *)userData)->uploadVideoDone = 1; }

void BR_NET_OnSearchVideos(void *userData, GdsRapResult *result) { ((struct BrNet *)userData)->searchVideosDone = 1; }

void BR_NET_OnGetVideo(void *userData, GdsRapResult *result) { ((struct BrNet *)userData)->getVideoDone = 1; }

void BR_NET_OnMarkVideo(void *userData, GdsRapResult *result) { ((struct BrNet *)userData)->markVideoDone = 1; }

struct BrNetTask *BR_NET_CreateTask(struct BrNet *net, BrNetStepFunc step, u16 heapId)
{
    struct BrNetTask *task=GFL_HEAP_Alloc(heapId,sizeof(struct BrNetTask),0,gBrNetSourceFile,0x44f);
    MI_CpuFill8(task,0,sizeof(struct BrNetTask));
    task->net=net;
    BR_NET_SetStep(task,step);
    return task;
}

void BR_NET_DestroyTask(struct BrNetTask *task) {GFL_HEAP_Free(task);}

void BR_NET_RunTask(struct BrNetTask *task)
{
    if (task->step != 0)
        task->step(task, &task->counter, task->net);
}

void BR_NET_SetStep(struct BrNetTask *task, BrNetStepFunc step)
{
    task->step = step;
    task->counter = 0;
}

int BR_NET_IsStep(struct BrNetTask *task, BrNetStepFunc step)
{
    if(task->step==step) return 1;
    return 0;
}

int BR_NET_OnRapError(struct BrNet *net, int unused, int errorKind, int unused2)
{
    if (GAME_DATA_IsSaving(net->gameData)) return 1;
    GDS_RAP_ReleaseSession(&net->rap, unused, errorKind, unused2);
    if (errorKind == 3 || errorKind == 6) {
        if (net->rapActive) {
            GDS_RAP_Exit(&net->rap);
            net->rapActive = 0;
        }
        DWC_RAP_SetErrorHookCallback(0, 0);
    }
    return 0;
}
