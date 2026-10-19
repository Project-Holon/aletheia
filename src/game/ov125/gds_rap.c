/*
 * file:     gds_rap.c
 * unit:     yes
 * function: GDS_RAP_Init, GDS_RAP_Exit, GDS_RAP_RequestUploadEntry, GDS_RAP_RequestDownloadEntries, GDS_RAP_RequestUploadVideo, GDS_RAP_RequestSearchVideos, GDS_RAP_RequestSearchKind1, GDS_RAP_RequestSearchKind2, GDS_RAP_RequestSearchKind3, GDS_RAP_RequestGetVideo, GDS_RAP_RequestMarkVideo, GDS_RAP_Main, GDS_RAP_RunRequest, GDS_RAP_UpdateSocketState, GDS_RAP_PollNothing, GDS_RAP_PollSaveUploadedVideo, GDS_RAP_PollNothingAfterError, GDS_RAP_ReleaseSession, GDS_RAP_FindMember, GDS_RAP_CopyNickname, GDS_RAP_ReadReply, GDS_RAP_IsIdle, GDS_RAP_CheckUploadEntryReply, GDS_RAP_CheckDownloadEntriesReply, GDS_RAP_GetDownloadEntries, GDS_RAP_CheckUploadVideoReply, GDS_RAP_GetUploadedDataNumber, GDS_RAP_CheckSearchVideosReply, GDS_RAP_GetSearchResults, GDS_RAP_CheckGetVideoReply, GDS_RAP_GetVideoReply, GDS_RAP_CheckMarkVideoReply, GDS_RAP_SaveVideoSeq, GDS_RAP_SaveVideoWithDataNumber, GDS_RAP_SaveVideoSecured, GDS_RAP_StartVideoSave, GDS_RAP_StepVideoSave, GDS_RAP_GetVideoWork
 * address:  0x021D6660
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GDS_SOCKET_GetMaxReplySize 0x021D8600 arm ov125
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   GDS_SOCKET_Begin 0x021D8598 arm ov125
 *   GF_PANIC_Fail 0x02034714 arm
 *   ov114_id 0x00000072 data
 *   sGdsRapFileName 0x021D8D00 data a4
 *   sGdsServerHost 0x021D8D0C data a4
 *   sGdsEmptyString 0x021D8D28 data a4
 *   NHTTP_RAP_FreePostData 0x021B99B8 thumb ov114
 *   NHTTP_RAP_Destroy 0x021B9838 thumb ov114
 *   GDS_SOCKET_Shutdown 0x021D85B4 arm ov125
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   BATTLE_REC_GetWork 0x0200B910 thumb
 *   sGdsSearchCategories 0x021D8C80 data a2
 *   GDS_SOCKET_GetState 0x021D85C0 arm ov125
 *   GDS_SOCKET_SendUploadEntry  0x021D860C  arm  ov125
 *   GDS_SOCKET_SendDownloadEntries  0x021D8654  arm  ov125
 *   GDS_SOCKET_SendUploadVideo  0x021D8694  arm  ov125
 *   GDS_SOCKET_SendSearchByCondition  0x021D8754  arm  ov125
 *   GDS_SOCKET_SendSearchKind1  0x021D879C  arm  ov125
 *   GDS_SOCKET_SendSearchKind3  0x021D87FC  arm  ov125
 *   GDS_SOCKET_SendSearchKind2  0x021D885C  arm  ov125
 *   GDS_SOCKET_SendGetVideo  0x021D88BC  arm  ov125
 *   GDS_SOCKET_SendMarkVideo  0x021D88F0  arm  ov125
 *   NHTTP_RAP_StartConnection  0x021B9748  thumb  ov114
 *   NHTTP_RAP_DeleteConnection  0x021B9774  thumb  ov114
 *   NHTTP_RAP_PollConnection  0x021B9790  thumb  ov114
 *   NHTTP_RAP_GetRecvBuffer  0x021B97F4  thumb  ov114
 *   NHTTP_RAP_Create  0x021B9800  thumb  ov114
 *   NHTTP_RAP_AllocPostData  0x021B98A0  thumb  ov114
 *   NHTTP_RAP_AppendPostData  0x021B98D8  thumb  ov114
 *   NHTTP_RAP_CreatePostRequest  0x021B98F8  thumb  ov114
 *   NHTTP_RAP_GetResultCode  0x021B99DC  thumb  ov114
 *   NHTTP_RAP_RecordList_GetCount  0x021B99F0  thumb  ov114
 *   NHTTP_RAP_RecordList_GetValue  0x021B99F4  thumb  ov114
 *   NHTTP_RAP_RecordList_GetRecord  0x021B9A14  thumb  ov114
 *   MYSTATUS_GetProfileId  0x0200853C  thumb
 *   MSGDATA_ReadUnits  0x02045F5C  arm
 *   BATTLE_REC_GetModeLayout  0x0200B784  thumb
 *   BATTLE_REC_GetBody  0x0200B91C  thumb
 *   BATTLE_REC_SetBodyCrc  0x0200BA44  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   gSpeciesNameBank  0x020A7370  data
 *   GDS_SOCKET_GetError 0x021D85DC arm ov125
 *   GDS_SOCKET_GetReply 0x021D85E8 arm ov125
 *   BATTLE_REC_DecodeWork 0x0200B490 thumb
 *   BATTLE_REC_EncodeWork 0x0200B4B8 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   GDS_SOCKET_GetReplySize 0x021D85F4 arm ov125
 *   MI_CpuFill8 0x02082BCC arm
 *   GF_STANDARD_CalcCrc16 0x0203F1FC arm
 *   sGdsEmptyString2 0x021D8D2C data a4
 *   d_0214616C 0x0214616C data a4
 *   SAVE_CONTROL_LoadExtraSave 0x0200725C thumb
 *   SAVE_CONTROL_GetExtraSaveRecord 0x020073D8 thumb
 *   BATTLE_REC_Clear 0x0200B448 thumb
 *   GAME_DATA_PartSaveStart 0x02012E4C thumb
 *   GAME_DATA_PartSaveMain 0x02012E7C thumb
 *   SAVE_CONTROL_DeleteExtraSave 0x020072A4 thumb
 *   gGdsSocket 0x021D9E40 data a4
 *   gGdsHostTail 0x021DA040 data a4
 *   GDS_SOCKET_ResetConnection 0x021D7808 arm ov125
 *   GDS_SOCKET_Nop 0x021D7CEC arm ov125
 *   GDS_SOCKET_NopVoid 0x021D7D20 arm ov125
 *   GDS_SOCKET_NopBegin 0x021D8588 arm ov125
 *   GDS_SOCKET_InitTick 0x021D7CF4 arm ov125
 *   GDS_SOCKET_InitLock 0x021D7CD4 arm ov125
 *   GDS_SOCKET_Close 0x021D7F60 arm ov125
 *   GDS_SOCKET_InitSsl 0x021D858C arm ov125
 *   GDS_SOCKET_WaitToken 0x021D8444 arm ov125
 *   GDS_SOCKET_OpenAndResolve 0x021D7E80 arm ov125
 *   GDS_SOCKET_Connect 0x021D7FA0 arm ov125
 *   GDS_SOCKET_Send 0x021D80E0 arm ov125
 *   GDS_SOCKET_Receive 0x021D824C arm ov125
 *   GDS_SOCKET_Unlock 0x021D7CC0 arm ov125
 *   GDS_SOCKET_Sleep 0x021D8438 arm ov125
 *   GDS_SOCKET_GetMaxReplySizeOf 0x021D89EC arm ov125
 *   GDS_SOCKET_GetRequestSize 0x021D891C arm ov125
 *   GDS_SOCKET_StartThread 0x021D7D30 arm ov125
 *   memcpy 0x02092344 arm
 *   DWC_Alloc  0x0205A16C  arm
 *   DWC_Free 0x0205A1B0 arm
 *   OS_LockMutex  0x02086028  arm
 *   gGdsSocketMutex     0x021DA174  data  a4
 *   BATTLE_REC_SaveSeq  0x0200B67C  thumb  arm9
 *   BATTLE_REC_Encode  0x0200B908  thumb  arm9
 *   WORDSET_Delete  0x0201ED04  thumb  arm9
 *   strcpy  0x02094798  arm  arm9
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed int s32;

#include "../version.h"
#include "gds_rap_types.h"

struct MyStatus;
struct SaveControl;

extern int GF_OVERLAY_Load(s32 overlayId);
extern void GF_OVERLAY_Unload(s32 overlayId);
extern void GF_PANIC_Fail(const char *file, u32 line, const char *message);
extern void MI_CpuFill8(void *dst, int value, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 GFL_HEAP_Free(void *p);
struct MsgBank;
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 MSGDATA_Delete(struct MsgBank *bank);
extern void MSGDATA_ReadUnits(struct MsgBank *bank, u32 msgIndex, u16 *str, u32 maxLen);
struct WordSet;
extern struct WordSet *WORDSET_CreateDefault(u16 heapId);
extern u32 WORDSET_Delete(struct WordSet *wordSet);
struct Strbuf;
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_Delete(struct Strbuf *strbuf);
extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gameData);
extern u32 MYSTATUS_GetProfileId(const struct MyStatus *status);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern void GAME_DATA_PartSaveStart(struct GameData *gameData, u32 id);
extern int GAME_DATA_PartSaveMain(struct GameData *gameData, int id);
extern u32 SAVE_CONTROL_LoadExtraSave(struct SaveControl *saveControl, u32 slot, u8 heapId);
extern void *SAVE_CONTROL_GetExtraSaveRecord(struct SaveControl *save, u32 id, u32 arg);
extern void SAVE_CONTROL_DeleteExtraSave(struct SaveControl *save, u32 id);
extern u16 GF_STANDARD_CalcCrc16(const u8 *src, u32 len);

extern void BATTLE_REC_GetModeLayout(u16 mode, s32 *sides, s32 *members);
extern struct BattleRecSave *BATTLE_REC_GetWork(void);
extern struct BattleRecBody *BATTLE_REC_GetBody(void);
extern void BATTLE_REC_SetBodyCrc(struct BattleRecBody *body);
extern void BATTLE_REC_DecodeWork(void);
extern void BATTLE_REC_EncodeWork(void);
extern void BATTLE_REC_Encode(void *data, u32 size, u32 code);
extern u32 BATTLE_REC_SaveSeq(struct GameData *gameData, struct BattleRecSave *rec, u32 id, u16 *seq, u16 heap);
extern void BATTLE_REC_Clear(struct BattleRecSave *rec);

extern int NHTTP_RAP_StartConnection(NHTTPRapSession *session);
extern void NHTTP_RAP_DeleteConnection(NHTTPRapSession *session);
extern int NHTTP_RAP_PollConnection(NHTTPRapSession *session);
extern char *NHTTP_RAP_GetRecvBuffer(NHTTPRapSession *session);
extern NHTTPRapSession *NHTTP_RAP_Create(u32 heapId, u32 gameCode, char *source);
extern void NHTTP_RAP_Destroy(NHTTPRapSession *session);
extern void NHTTP_RAP_AllocPostData(NHTTPRapSession *session, int alignment, int size, int id);
extern void NHTTP_RAP_AppendPostData(NHTTPRapSession *session, const void *src, int size);
extern int NHTTP_RAP_CreatePostRequest(NHTTPRapSession *session);
extern void NHTTP_RAP_FreePostData(NHTTPRapSession *session);
extern int NHTTP_RAP_GetResultCode(NHTTPRapSession *session);
extern int NHTTP_RAP_RecordList_GetCount(NHTTPRapRecordList *list);
extern u32 NHTTP_RAP_RecordList_GetValue(NHTTPRapRecordList *list, u32 index);
extern NHTTPRapRecord *NHTTP_RAP_RecordList_GetRecord(NHTTPRapRecordList *list, u32 index);

/* ARM half of this file and gds_socket.c */
extern int GDS_SOCKET_Begin(GdsClientInfo *client, const char *host, int port);
extern void GDS_SOCKET_Shutdown(void);
extern unsigned GDS_SOCKET_GetState(void);
extern int GDS_SOCKET_GetError(void);
extern void *GDS_SOCKET_GetReply(void);
extern int GDS_SOCKET_GetReplySize(void);
extern int GDS_SOCKET_GetMaxReplySize(int requestId);
extern int GDS_SOCKET_SendUploadEntry(const GdsEntryBlocks *entry, void *replyBuffer);
extern int GDS_SOCKET_SendDownloadEntries(int key, void *replyBuffer);
extern int GDS_SOCKET_SendUploadVideo(const struct BattleRecSave *video, const void *ticket, int ticketLength, void *replyBuffer);
extern int GDS_SOCKET_SendSearchByCondition(GdsSearchParams *params, void *replyBuffer);
extern int GDS_SOCKET_SendSearchKind1(int limit, void *replyBuffer);
extern int GDS_SOCKET_SendSearchKind3(int limit, void *replyBuffer);
extern int GDS_SOCKET_SendSearchKind2(int limit, void *replyBuffer);
extern int GDS_SOCKET_SendGetVideo(u32 dataNumberLo, u32 dataNumberHi, u32 version, void *replyBuffer);
extern int GDS_SOCKET_SendMarkVideo(u32 dataNumberLo, u32 dataNumberHi, void *replyBuffer);

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

extern char ov114_id[];
extern const char sGdsRapFileName[];
extern const char sGdsServerHost[];
extern char sGdsEmptyString[];
extern char sGdsEmptyString2[];
extern const GdsSearchCategory sGdsSearchCategories[];
extern void *gSpeciesNameBank;
extern struct BattleRecSave *d_0214616C;

int GDS_RAP_Init(GdsRapWork *work, GdsRapInitParams *params)
{
    GF_OVERLAY_Load((int)ov114_id);
    MI_CpuFill8(work, 0, sizeof(GdsRapWork));
    work->heapId = params->heapId;
    work->gameData = params->gameData;
    work->profileSource = params->profileSource;
    work->callbacks = params->callbacks;
    work->lastSocketState = -1;
    work->requestId = GDS_REQUEST_NONE;
    work->finishedRequestId = GDS_REQUEST_NONE;
    work->replyBuffer = GFL_HEAP_Alloc(params->heapId, GDS_SOCKET_GetMaxReplySize(-1), 0, sGdsRapFileName, 0x84);
    MI_CpuFill8(work->replyBuffer, 0, GDS_SOCKET_GetMaxReplySize(-1));
    work->msgData = (struct MsgData *)MSGDATA_CreateFromArchive(0, 2, 0xE8, params->heapId);
    work->wordSet = WORDSET_CreateDefault(params->heapId);
    work->strBuf = (struct StrBuf *)STRBUF_Create(0x100, params->heapId);
    work->client.profileId = params->profileId;
    work->client.packetType = PM_VERSION_ID;
    work->client.protocolVersion = 2;
    if (GDS_SOCKET_Begin(&work->client, sGdsServerHost, 0x3071) != 1)
        GF_PANIC_Fail(sGdsEmptyString, 0, sGdsEmptyString);
    work->active = 1;
    work->initialized = 1;
    return 1;
}


void GDS_RAP_Exit(GdsRapWork *work)
{
    if (work->session) {
        NHTTP_RAP_FreePostData(work->session);
        NHTTP_RAP_Destroy(work->session);
    }
    GDS_SOCKET_Shutdown();
    work->active = 0;
    STRBUF_Delete((struct Strbuf *)work->strBuf);
    WORDSET_Delete(work->wordSet);
    MSGDATA_Delete((struct MsgBank *)work->msgData);
    GFL_HEAP_Free(work->replyBuffer);
    GF_OVERLAY_Unload((int)ov114_id);
}


int GDS_RAP_RequestUploadEntry(GdsRapWork *work, const GdsProfileBlock *profile, const GdsPayloadBlock *payload)
{
    if (!GDS_RAP_IsIdle(work)) return 0;
    work->args.entry.profile = *profile;
    work->args.entry.payload = *payload;
    work->waitFrames = 0x3c;
    work->requestId = GDS_REQUEST_UPLOAD_ENTRY;
    return 1;
}


int GDS_RAP_RequestDownloadEntries(GdsRapWork *work, int key) {if(!GDS_RAP_IsIdle(work))return 0;work->arg2.downloadKey=key;work->requestId=GDS_REQUEST_DOWNLOAD_ENTRIES;return 1;}


int GDS_RAP_RequestUploadVideo(GdsRapWork *work, void *profile)
{
    struct BattleRecSave *video;
    struct BattleRecMon *firstPoke;
    int party, member;
    int sides, members;
    int i;
    video = GDS_RAP_GetVideoWork();
    if (!GDS_RAP_IsIdle(work)) return 0;
    BATTLE_REC_GetModeLayout(video->head.mode, &sides, &members);
    firstPoke = video->body.party[0].members;
    for (i = 0; i < GDS_NAME_SLOTS; i++) {
        if (!GDS_RAP_FindMember(work, i, &party, &member)) break;
        GDS_RAP_CopyNickname(GDS_REC_POKE(firstPoke, party, member)->nickname, work->nicknames[i], GDS_NICKNAME_LEN);
    }
    work->namesChanged = 0;
    work->secondPass = 0;
    work->args.video = video;
    MI_CpuCopy8(profile, BATTLE_REC_GetWork(), GDS_PROFILE_SIZE);
    work->waitFrames = 60;
    work->requestId = GDS_REQUEST_UPLOAD_VIDEO;
    return 1;
}


int GDS_RAP_RequestSearchVideos(GdsRapWork *work, int keyId, unsigned int categoryIndex, int mode, u8 flag)
{
    if (!GDS_RAP_IsIdle(work)) return 0;
    if (categoryIndex >= 20) GF_PANIC_Fail(sGdsEmptyString, 0, sGdsEmptyString);
    MI_CpuFill8(&work->args.search, 0, 16);
    work->args.search.keyId = keyId;
    work->args.search.category = sGdsSearchCategories[categoryIndex].category;
    work->args.search.categoryMask = sGdsSearchCategories[categoryIndex].mask;
    work->args.search.mode = mode;
    work->args.search.flag = flag;
    work->args.search.limit = GDS_SEARCH_LIMIT;
    work->searchKind = GDS_SEARCH_BY_CONDITION;
    work->requestId = GDS_REQUEST_SEARCH_VIDEOS;
    return 1;
}


int GDS_RAP_RequestSearchKind1(GdsRapWork *work) {if(!GDS_RAP_IsIdle(work))return 0;work->searchKind=GDS_SEARCH_KIND_1;work->requestId=GDS_REQUEST_SEARCH_VIDEOS;return 1;}


int GDS_RAP_RequestSearchKind2(GdsRapWork *work) {if(!GDS_RAP_IsIdle(work))return 0;work->searchKind=GDS_SEARCH_KIND_2;work->requestId=GDS_REQUEST_SEARCH_VIDEOS;return 1;}


int GDS_RAP_RequestSearchKind3(GdsRapWork *work) {if(!GDS_RAP_IsIdle(work))return 0;work->searchKind=GDS_SEARCH_KIND_3;work->requestId=GDS_REQUEST_SEARCH_VIDEOS;return 1;}


int GDS_RAP_RequestGetVideo(GdsRapWork *work, int dataNumberLo, int dataNumberHi) {if(!GDS_RAP_IsIdle(work))return 0;work->arg2.dataNumber.lo=dataNumberLo;work->arg2.dataNumber.hi=dataNumberHi;work->requestId=GDS_REQUEST_GET_VIDEO;return 1;}


int GDS_RAP_RequestMarkVideo(GdsRapWork *work, int dataNumberLo, int dataNumberHi) {if(!GDS_RAP_IsIdle(work))return 0;work->arg2.dataNumber.lo=dataNumberLo;work->arg2.dataNumber.hi=dataNumberHi;work->requestId=GDS_REQUEST_MARK_VIDEO;return 1;}


int GDS_RAP_Main(GdsRapWork *work)
{
    int result;
    if (work->active == 1) {
        if (work->requestId != GDS_REQUEST_NONE) {
            if (work->waitFrames != 0) {
                work->waitFrames--;
            } else {
                switch (GDS_SOCKET_GetState()) {
                case 1: case 7: case 8: case 9:
                    if (GDS_RAP_RunRequest(work, &result) == 1) {
                        work->requestId = GDS_REQUEST_NONE;
                        work->step = 0;
                        if (result == 1) {
                            work->result.errorKind = 2;
                            work->result.requestId = GDS_REQUEST_UPLOAD_VIDEO;
                            work->result.errorCode = work->httpErrorCode;
                            work->result.pending = 1;
                            if (work->callbacks.onUploadVideo != 0)
                                work->callbacks.onUploadVideo(work->callbacks.userData, &work->result);
                        }
                    }
                    break;
                case 0: case 2: case 3: case 4: case 5: case 6:
                default: break;
                }
            }
        }
        GDS_RAP_UpdateSocketState(work);
        if (work->pending.poll != 0) {
            if (work->pending.poll(work, &work->pending) == 1) {
                work->pending.poll = 0;
                if (work->pending.callback != 0) {
                    work->pending.callback(work->callbacks.userData, &work->result);
                    work->pending.callback = 0;
                }
                MI_CpuFill8(&work->pending, 0, sizeof(GdsRapPending));
                work->finishedRequestId = GDS_REQUEST_NONE;
            }
        }
    }
    return 1;
}



/*
 * 2026-10-05 (wD9r lane109): EXACT. The 0x55F1 inner switch is written out as an expanded inline:
 *   r = 0; cases 0..2 set r and break; case 3 sets t and `goto join`; then `t = r; join: ret = t;`.
 *   t is declared first, so the merged ret/t/r value keeps an early local's spill slot ([sp,#8]);
 *   a real static inline helper put it in the inline return temp's slot ([sp]).
 */
int GDS_RAP_RunRequest(GdsRapWork *work, int *done)
{
    int t;
    int sides, members;
    int party, member;
    int sides2, members2;
    int ret;
    int r;
    struct BattleRecSave *video;
    struct BattleRecSave *video2;
    int i;
    NHTTPRapRecordList *list;
    int httpStatus, pollStatus;

    *done = 0;
    ret = 0;
    switch (work->requestId) {
    case GDS_REQUEST_UPLOAD_ENTRY:
        ret = GDS_SOCKET_SendUploadEntry(&work->args.entry, work->replyBuffer);
        break;
    case GDS_REQUEST_DOWNLOAD_ENTRIES:
        ret = GDS_SOCKET_SendDownloadEntries(work->arg2.downloadKey, work->replyBuffer);
        break;
    case GDS_REQUEST_UPLOAD_VIDEO:
        switch (work->step) {
        case 0:
            video = GDS_RAP_GetVideoWork();
            if (work->session != 0)
                GF_PANIC_Fail(sGdsEmptyString, ret, sGdsEmptyString);
            work->session = NHTTP_RAP_Create((u16)work->heapId, MYSTATUS_GetProfileId(GAME_DATA_GetMyStatus(work->gameData)), work->profileSource);
            NHTTP_RAP_AllocPostData(work->session, (u16)work->heapId, 0x540, 3);
            BATTLE_REC_GetModeLayout(video->head.mode, &sides, &members);
            work->memberCount = 0;
            for (i = 0; i < sides; i++) {
                NHTTP_RAP_AppendPostData(work->session, video->body.party[i].members, video->body.party[i].count * sizeof(struct BattleRecMon));
                work->memberCount += (u8)video->body.party[i].count;
            }
            if (!NHTTP_RAP_CreatePostRequest(work->session))
                GF_PANIC_Fail(sGdsEmptyString, 0, sGdsEmptyString);
            if (!(NHTTP_RAP_StartConnection(work->session) == 0 ? 1 : 0))
                GF_PANIC_Fail(sGdsEmptyString, 0, sGdsEmptyString);
            work->step++;
            break;
        case 1:
            httpStatus = NHTTP_RAP_GetResultCode(work->session);
            pollStatus = NHTTP_RAP_PollConnection(work->session);
            if (httpStatus != 200 && pollStatus != 15) {
                switch (NHTTP_RAP_GetResultCode(work->session)) {
                case 0x190: work->httpErrorCode = 0x96; break;
                case 0x191: work->httpErrorCode = 0x97; break;
                case 0x198: work->httpErrorCode = 0x98; break;
                default: work->httpErrorCode = 0x99; break;
                }
                NHTTP_RAP_FreePostData(work->session);
                NHTTP_RAP_DeleteConnection(work->session);
                NHTTP_RAP_Destroy(work->session);
                work->session = 0;
                *done = 1;
                return 1;
            }
            if (pollStatus == 0) {
                list = (NHTTPRapRecordList *)NHTTP_RAP_GetRecvBuffer(work->session);
                if (NHTTP_RAP_RecordList_GetCount(list) == 0) {
                    work->nameCheckFailed = 0;
                    MI_CpuCopy8(NHTTP_RAP_RecordList_GetRecord(list, work->memberCount), work->ticket, GDS_TICKET_SIZE);
                    for (i = 0; i < work->memberCount; i++)
                        work->nameCheckResult = NHTTP_RAP_RecordList_GetValue(list, i);
                    work->step++;
                } else {
                    video2 = GDS_RAP_GetVideoWork();
                    if (work->secondPass == 1)
                        work->nameCheckFailed = 1;
                    BATTLE_REC_GetModeLayout(video2->head.mode, &sides2, &members2);
                    for (i = 0; i < work->memberCount; i++) {
                        work->nameCheckResult = NHTTP_RAP_RecordList_GetValue(list, i);
                        if (work->nameCheckResult != 0 && work->secondPass == 0) {
                            if (!GDS_RAP_FindMember(work, i, &party, &member))
                                break;
                            {
                                struct BattleRecMon *poke = &video2->body.party[party].members[member];
                                MSGDATA_ReadUnits(gSpeciesNameBank, poke->species, poke->nickname, GDS_NICKNAME_LEN);
                            }
                            work->namesChanged = 1;
                        }
                    }
                    if (work->secondPass == 0) {
                        BATTLE_REC_SetBodyCrc(BATTLE_REC_GetBody());
                        work->step = 0;
                        work->secondPass++;
                    } else {
                        work->step++;
                    }
                }
                NHTTP_RAP_FreePostData(work->session);
                NHTTP_RAP_Destroy(work->session);
                work->session = 0;
                break;
            }
            if (pollStatus != 15 && work->session != 0) {
                NHTTP_RAP_FreePostData(work->session);
                NHTTP_RAP_DeleteConnection(work->session);
                NHTTP_RAP_Destroy(work->session);
                work->session = 0;
                return 1;
            }
            return 0;
        case 2:
            GAME_DATA_GetSaveControl(work->gameData);
            GDS_RAP_EncodeVideoBody();
            work->step++;
            break;
        case 3:
            ret = GDS_SOCKET_SendUploadVideo(work->args.video, work->ticket, GDS_TICKET_SIZE, work->replyBuffer);
            break;
        }
        break;
    case GDS_REQUEST_SEARCH_VIDEOS:
        r = 0;
        switch (work->searchKind) {
        case 0:
            r = GDS_SOCKET_SendSearchByCondition(&work->args.search, work->replyBuffer);
            break;
        case 1:
            r = GDS_SOCKET_SendSearchKind1(GDS_SEARCH_LIMIT, work->replyBuffer);
            break;
        case 2:
            r = GDS_SOCKET_SendSearchKind2(GDS_SEARCH_LIMIT, work->replyBuffer);
            break;
        case 3:
            t = GDS_SOCKET_SendSearchKind3(GDS_SEARCH_LIMIT, work->replyBuffer);
            goto join;
            break;
        }
        t = r;
    join:
        ret = t;
        break;
    case GDS_REQUEST_GET_VIDEO:
        ret = GDS_SOCKET_SendGetVideo(work->arg2.dataNumber.lo, work->arg2.dataNumber.hi, GDS_VIDEO_VERSION, work->replyBuffer);
        break;
    case GDS_REQUEST_MARK_VIDEO:
        ret = GDS_SOCKET_SendMarkVideo(work->arg2.dataNumber.lo, work->arg2.dataNumber.hi, work->replyBuffer);
        break;
    default:
        GF_PANIC_Fail(sGdsEmptyString, 0, sGdsEmptyString);
        break;
    }
    if (ret == 1)
        work->finishedRequestId = work->requestId;
    return ret;
}



int GDS_RAP_UpdateSocketState(GdsRapWork *work)
{
    unsigned int state;
    if (work->finishedRequestId == GDS_REQUEST_NONE) return 1;
    state = GDS_SOCKET_GetState();
    work->socketState = state;
    if (state != work->lastSocketState) {
        switch (state) {
        case 7:
            work->result.errorKind = 1;
            work->result.requestId = 0;
            work->result.errorCode = 7;
            work->result.pending = 1;
            work->pending.poll = GDS_RAP_PollNothingAfterError;
            break;
        case 8:
            work->pending.poll = GDS_RAP_PollNothing;
            GDS_RAP_ReadReply(work);
            break;
        case 9:
            work->result.errorKind = 0;
            work->result.requestId = 0;
            work->result.errorCode = GDS_SOCKET_GetError();
            work->result.pending = 1;
            work->pending.poll = GDS_RAP_PollNothingAfterError;
            break;
        case 0: case 1: case 2: case 3: case 4: case 5: case 6:
        default: break;
        }
        work->lastSocketState = work->socketState;
    }
    return 1;
}



int GDS_RAP_PollNothing(GdsRapWork *work, GdsRapPending *pending) { return 1; }



int GDS_RAP_PollSaveUploadedVideo(GdsRapWork *work, GdsRapPending *pending)
{
    struct BattleRecSave *video;
    struct BattleRecMon *firstPoke;
    u8 *names;
    int party, member;
    int sides, members;
    int i;
    GdsReplyUploadVideo *reply;
    int result;
    if (pending->saveStep == 0 && work->namesChanged != 0) {
        video = GDS_RAP_GetVideoWork();
        BATTLE_REC_DecodeWork();
        BATTLE_REC_GetModeLayout(video->head.mode, &sides, &members);
        i = 0;
        names = (u8 *)work->nicknames;
        firstPoke = video->body.party[0].members;
        for (; i < GDS_NAME_SLOTS; i++) {
            if (!GDS_RAP_FindMember(work, i, &party, &member)) break;
            GDS_RAP_CopyNickname(names + i * sizeof(work->nicknames[0]), GDS_REC_POKE(firstPoke, party, member)->nickname, GDS_NICKNAME_LEN);
        }
        BATTLE_REC_SetBodyCrc(BATTLE_REC_GetBody());
        BATTLE_REC_EncodeWork();
    }
    reply = (GdsReplyUploadVideo *)GDS_SOCKET_GetReply();
    result = GDS_RAP_SaveVideoWithDataNumber(work->gameData, reply->dataNumber.half.lo, reply->dataNumber.half.hi, &pending->saveStep, &pending->saveSubStep, work->heapId);
    if (result == 2 || result == 3) return 1;
    return 0;
}



int GDS_RAP_PollNothingAfterError(GdsRapWork *work, GdsRapPending *pending) { return 1; }




void GDS_RAP_ReleaseSession(GdsRapWork *work, int unused, int scene, int unused2)
{
    if ((scene == 3 || scene == 6) && work->session != 0) {
        NHTTP_RAP_FreePostData(work->session);
        NHTTP_RAP_DeleteConnection(work->session);
        NHTTP_RAP_Destroy(work->session);
        work->session = 0;
    }
}



int GDS_RAP_FindMember(GdsRapWork *work, int index, int *party, int *member)
{
    struct BattleRecSave *video;
    int sides, other;
    int i;
    i = 0;
    video = GDS_RAP_GetVideoWork();
    BATTLE_REC_GetModeLayout(video->head.mode, &sides, &other);
    for (*party = 0; *party < sides; ++*party) {
        for (*member = 0; *member < video->body.party[*party].count; ++*member) {
            if (i == index) return 1;
            ++i;
        }
    }
    return 0;
}



void GDS_RAP_CopyNickname(const void *src, void *dst, u32 count) {MI_CpuCopy8(src,dst,count*2);}



int GDS_RAP_ReadReply(GdsRapWork *work)
{
    const GdsReply *reply;
    int result = 1;
    reply = (const GdsReply *)GDS_SOCKET_GetReply();
    GDS_SOCKET_GetReplySize();
    if (work->finishedRequestId != reply->requestId) GF_PANIC_Fail(sGdsEmptyString, 0, sGdsEmptyString);
    work->pending.callback = 0;
    switch (reply->requestId) {
    case 0: break;
    case 21000:
        result = GDS_RAP_CheckUploadEntryReply(work, reply);
        work->pending.callback = work->callbacks.onUploadEntry;
        break;
    case 21001:
        result = GDS_RAP_CheckDownloadEntriesReply(work, reply);
        work->pending.callback = work->callbacks.onDownloadEntries;
        break;
    case 22000:
        result = GDS_RAP_CheckUploadVideoReply(work, reply);
        work->pending.callback = work->callbacks.onUploadVideo;
        if (result == 1) work->pending.poll = GDS_RAP_PollSaveUploadedVideo;
        break;
    case 22001:
        result = GDS_RAP_CheckSearchVideosReply(work, reply);
        work->pending.callback = work->callbacks.onSearchVideos;
        break;
    case 22002:
        result = GDS_RAP_CheckGetVideoReply(work, reply);
        work->pending.callback = work->callbacks.onGetVideo;
        break;
    case 22003:
        result = GDS_RAP_CheckMarkVideoReply(work, reply);
        work->pending.callback = work->callbacks.onMarkVideo;
        break;
    }
    if (result == 0) {
        work->result.errorKind = 2;
        work->result.requestId = reply->requestId;
        work->result.errorCode = reply->resultCode;
        work->result.pending = 1;
    } else work->result.pending = 0;
    return result;
}



int GDS_RAP_GetResult(GdsRapWork *work, GdsRapResult **result)
{
    *result = &work->result;
    return work->result.pending;
}



void GDS_RAP_ClearResult(GdsRapWork *work)
{
    MI_CpuFill8(&work->result, 0, sizeof(GdsRapResult));
}



int GDS_RAP_IsIdle(GdsRapWork *work) { if (work->requestId==GDS_REQUEST_NONE && work->finishedRequestId==GDS_REQUEST_NONE) return 1; return 0; }



int GDS_RAP_CheckUploadEntryReply(GdsRapWork *work, const GdsReply *reply) { int r=0; switch (reply->resultCode) { case 0: r=1; break; case 1: case 2: case 3: case 4: case 5: case 6: break; default: break; } return r; }



int GDS_RAP_CheckDownloadEntriesReply(GdsRapWork *work, const GdsReply *reply) { int r=0; switch (reply->resultCode) { case 0: r=1; break; case 1: case 2: case 3: break; default: break; } return r; }



int GDS_RAP_GetDownloadEntries(GdsRapWork *work, void **entries, int max)
{
    GdsDownloadList *list;
    GdsDownloadEntry *base;
    int count;
    int i;
    list = &((GdsReplyDownload *)GDS_SOCKET_GetReply())->list;
    count = list->count;
    if (count > max) count = max;
    base = list->entries;
    for (i = 0; i < count; i++) entries[i] = &base[i].blocks;
    for (; i < max; i++) entries[i] = 0;
    return count;
}



int GDS_RAP_CheckUploadVideoReply(GdsRapWork *work, const GdsReply *reply) { int r=0; switch (reply->resultCode) { case 0: r=1; break; case 1: case 2: case 3: case 4: case 5: case 6: case 7: break; default: break; } return r; }



u64 GDS_RAP_GetUploadedDataNumber(GdsRapWork *work) { GdsReplyUploadVideo *reply=(GdsReplyUploadVideo *)GDS_SOCKET_GetReply(); return reply->dataNumber.value; }



int GDS_RAP_CheckSearchVideosReply(GdsRapWork *work, const GdsReply *reply) { int r=0; switch (reply->resultCode) { case 0: r=1; break; case 1: case 2: case 3: case 4: break; default: break; } return r; }




/*
 * note: 2026-10-05 (D4-14): the xor/orr equality is a 64-bit compare; written as u64 loads, EXACT.
 */
int GDS_RAP_GetSearchResults(GdsRapWork *work, char *dst, int max)
{
    GdsReplySearch *reply = (GdsReplySearch *)GDS_SOCKET_GetReply();
    GdsListingList *list = &reply->list;
    GdsListingEntry *base;
    int count;
    int i;

    count = list->count;
    if (count > max) {
        count = max;
        GF_PANIC_Fail(sGdsEmptyString2, 0, sGdsEmptyString2);
    }
    MI_CpuFill8(dst, 0, max * sizeof(GdsVideoListing));
    i = 0;
    base = list->entries;
    for (i = 0; i < count; i++) {
        GdsListingEntry *entry = &base[i];
        u64 id = entry->dataNumber.value;
        if (entry->listing.head.dataNumber.value != id) {
            entry->listing.head.dataNumber.value = id;
            entry->listing.head.crc = GF_STANDARD_CalcCrc16((const u8 *)&entry->listing.head, 0x38);
        }
        *(GdsVideoListing *)(dst + i * sizeof(GdsVideoListing)) = entry->listing;
    }
    return count;
}



int GDS_RAP_CheckGetVideoReply(GdsRapWork *work, const GdsReply *reply) { int r=0; switch (reply->resultCode) { case 0: r=1; break; case 1: case 2: case 3: case 4: break; default: break; } return r; }



int GDS_RAP_GetVideoReply(GdsRapWork *work, struct BattleRecSave **video)
{
    GdsReplyGetVideo *reply = (GdsReplyGetVideo *)GDS_SOCKET_GetReply();
    GdsVideoEntry *entry = &reply->entry;
    u64 id;

    *video = &entry->video;
    id = reply->entry.dataNumber.value;
    if (entry->video.head.dataNumber.value != id) {
        entry->video.head.dataNumber.value = id;
        (*video)->head.crc = GF_STANDARD_CalcCrc16((const u8 *)&(*video)->head, 0x38);
    }
    return reply->entry.dataNumber.half.lo;
}



int GDS_RAP_CheckMarkVideoReply(GdsRapWork *work, const GdsReply *reply) { int r=0; switch (reply->resultCode) { case 0: r=1; break; case 1: case 2: case 3: break; default: break; } return r; }



int GDS_RAP_SaveVideoSeq(struct GameData *gameData, int id, int mode, u16 *state, u16 *seq, u16 heap)
{
    unsigned int value;
    switch (*state) {
    case 0:
        if (mode == 1) {
            d_0214616C->head.secure = mode;
            d_0214616C->head.magic = 57985;
            d_0214616C->head.crc = GF_STANDARD_CalcCrc16((const u8 *)&d_0214616C->head, 56);
        }
        value = d_0214616C->body.crc;
        BATTLE_REC_Encode(&d_0214616C->body, 0x17dc, value + ((value ^ 0xffff) << 16));
        ++*state;
        break;
    case 1:
        return BATTLE_REC_SaveSeq(gameData, d_0214616C, id, seq, heap);
    }
    return 0;
}



void GDS_RAP_EncodeVideoBody(void)
{
    unsigned int value;
    value = d_0214616C->body.crc;
    BATTLE_REC_Encode(&d_0214616C->body, 0x17dc, value + ((value ^ 0xffff) << 16));
}



int GDS_RAP_SaveVideoWithDataNumber(struct GameData *gameData, int dataNumberLo, int dataNumberHi, u16 *state, u16 *seq, u16 heap)
{
    struct BattleRecSave *video;
    switch (*state) {
    case 0:
        video = d_0214616C;
        video->head.dataNumber.half.lo = dataNumberLo;
        video->head.dataNumber.half.hi = dataNumberHi;
        ++*state;
        break;
    case 1:
        return BATTLE_REC_SaveSeq(gameData, d_0214616C, 0, seq, heap);
    }
    return 0;
}



int GDS_RAP_SaveVideoSecured(struct GameData *gameData, int id, u16 *state, u16 *seq, u16 heap)
{
    unsigned int value;
    switch (*state) {
    case 0:
        d_0214616C->head.secure = 1;
        d_0214616C->head.magic = 57985;
        d_0214616C->head.crc = GF_STANDARD_CalcCrc16((const u8 *)&d_0214616C->head, 56);
        value = d_0214616C->body.crc;
        BATTLE_REC_Encode(&d_0214616C->body, 0x17dc, value + ((value ^ 0xffff) << 16));
        ++*state;
        break;
    case 1:
        return BATTLE_REC_SaveSeq(gameData, d_0214616C, id, seq, heap);
    }
    return 0;
}



void GDS_RAP_StartVideoSave(struct GameData *gameData, u8 heap, u32 id) {struct SaveControl *save=GAME_DATA_GetSaveControl(gameData); SAVE_CONTROL_LoadExtraSave(save,id,heap); BATTLE_REC_Clear(SAVE_CONTROL_GetExtraSaveRecord(save,id,0)); GAME_DATA_PartSaveStart(gameData,id);}



int GDS_RAP_StepVideoSave(struct GameData *gameData, int id) {struct SaveControl *save=GAME_DATA_GetSaveControl(gameData); int r=GAME_DATA_PartSaveMain(gameData,id); if(r==2 || r==3) SAVE_CONTROL_DeleteExtraSave(save,id); return r;}



struct BattleRecSave *GDS_RAP_GetVideoWork(void) { return d_0214616C; }
