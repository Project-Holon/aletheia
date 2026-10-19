/*
 * file:     wifi_bsubway.c
 * unit:     yes
 * function: WIFI_BSUBWAY_Create, WIFI_BSUBWAY_Step, WIFI_BSUBWAY_Delete, WIFI_BSUBWAY_IsTransferReady, WIFI_BSUBWAY_ClearTrainers, WIFI_BSUBWAY_StartRoomRequest, WIFI_BSUBWAY_FinishRoomRequest, WIFI_BSUBWAY_StartPlayerDownload, WIFI_BSUBWAY_FinishPlayerDownload, WIFI_BSUBWAY_GetRoomNumber, WIFI_BSUBWAY_GetPlayerIndex, WIFI_BSUBWAY_GetDownloadResult, WIFI_BSUBWAY_GetTransferState, WIFI_BSUBWAY_NormalizeTrainers, WIFI_BSUBWAY_SaveTrainers, WIFI_BSUBWAY_SaveHistory, WIFI_BSUBWAY_StatusInit, WIFI_BSUBWAY_StatusDelete, WIFI_BSUBWAY_StatusSetMessage, WIFI_BSUBWAY_StatusCheckMessage, WIFI_BSUBWAY_StartProfileUpload, WIFI_BSUBWAY_FinishProfileUpload, WIFI_BSUBWAY_BuildProfile, WIFI_BSUBWAY_OnHttpError, WIFI_BSUBWAY_StartHttpRequest, WIFI_BSUBWAY_PollHttpRequest, WIFI_BSUBWAY_ReadRecordUnits, WIFI_BSUBWAY_AbortHttpRequest, WIFI_BSUBWAY_StartUploadPlayer, WIFI_BSUBWAY_IsUploadDone, WIFI_BSUBWAY_AsyncInit, WIFI_BSUBWAY_AsyncReset, WIFI_BSUBWAY_PollAsync, WIFI_BSUBWAY_AsyncHasError, WIFI_BSUBWAY_GetErrorState, WIFI_BSUBWAY_CheckFatalError, WIFI_BSUBWAY_SetDownloadResult, WIFI_BSUBWAY_SetHttpError, WIFI_BSUBWAY_ResetUpload, WIFI_BSUBWAY_TickUploadTimeout, WIFI_BSUBWAY_OpenCodeIn
 * address:  0x021D6660
 * region:   ov116
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
 *   ov_id 0x00000072 data
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GAME_DATA_GetSaveBlock3B 0x02012EFC thumb
 *   GAME_DATA_GetSaveBlock3A 0x02012EF0 thumb
 *   CONSOLE_STAMP_GetFromSave 0x02008B08 thumb
 *   WIFI_BSUBWAY_GRAPHIC_StartSaveProc 0x021D737C thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_GetSaveState 0x021D73D4 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_CreateWindow 0x021D7B70 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_InitBt 0x021D7A3C thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_PrintMessage 0x021D8010 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon 0x021D8190 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_PollBt 0x021D7A94 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream 0x021D80CC thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_DispatchTable 0x021D7424 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_CancelBt 0x021D7AA8 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_EndBt 0x021D7AC8 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_DeleteWindow 0x021D7C58 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_StartRetryProc 0x021D73E0 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_CheckNetError 0x021D7B00 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_IsPrintDone 0x021D7B64 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_UpdateText 0x021D7CF4 thumb ov116
 *   DPW_BT_Main 0x021C8FA8 arm ov114
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   WIFI_BSUBWAY_GRAPHIC_DeleteTextParam 0x021D730C thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_Noop 0x021D73D0 thumb ov116
 *   WIFI_BSUBWAY_GRAPHIC_NoopRetry 0x021D7420 thumb ov116
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   DPW_BT_GetRoomNumAsync 0x021C941C arm ov114
 *   DPW_BT_DownloadPlayerAsync 0x021C94A0 arm ov114
 *   NATION_AREA_SanitizeNation 0x02025C1C thumb
 *   NATION_AREA_SanitizeArea 0x02025C30 thumb
 *   CURSOR_MOVE_FindTableGroupIndex 0x02025CB0 thumb
 *   CURSOR_MOVE_GetTableGroup 0x02025C88 thumb
 *   DWC_GetDateTime 0x02167ED8 arm ov009
 *   BSUBWAY_WIFIDATA_SetTrainerBit 0x0200DD28 thumb
 *   BSUBWAY_SAVEDATA_SetHistory 0x0200DF10 thumb
 *   MYSTATUS_Create 0x0200846C thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   MYSTATUS_Copy 0x02008494 thumb
 *   MYSTATUS_CreateNameStrbuf 0x02008510 thumb
 *   STRBUF_GetChars 0x02045A90 arm
 *   STRBUF_GetLength 0x020458F8 arm
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   DWC_CheckProfanityExAsync 0x0217BC44 arm ov009
 *   STRBUF_Delete 0x02045808 arm
 *   DWC_CheckProfanityProcess 0x0217BC90 arm ov009
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   NHTTP_RAP_InitTrainerInfo 0x021B9B00 thumb ov114
 *   DPW_BT_SetProfileAsync 0x021C9744 arm ov114
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   WIFI_HISTORY_GetBlock 0x02009470 thumb
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   GREETING_SAVEDATA_GetFromSave 0x0200E6F0 thumb
 *   MYSTATUS_GetName 0x020084F4 thumb
 *   MI_CpuCopy8 0x02082D44 arm
 *   MYSTATUS_GetId 0x02008530 thumb
 *   GAME_VERSION_Code 0x0209DF08 data a1
 *   GAME_LANGUAGE_Code 0x0209DF0C data a1
 *   MYSTATUS_GetNation 0x0200856C thumb
 *   MYSTATUS_GetArea 0x02008570 thumb
 *   MYSTATUS_GetSex 0x02008550 thumb
 *   MYSTATUS_GetTrainerView 0x02008554 thumb
 *   GREETING_SAVEDATA_GetSentence 0x0200E6FC thumb
 *   BSUBWAY_SCOREDATA_GetRecordScore 0x0200DCF8 thumb
 *   BSUBWAY_SCOREDATA_GetRecordBlob 0x0200DC74 thumb
 *   NHTTP_RAP_DeleteConnection 0x021B9774 thumb ov114
 *   NHTTP_RAP_Create 0x021B9800 thumb ov114
 *   DWC_RAP_SetErrorCallback 0x02156DC4 thumb ov009
 *   NHTTP_RAP_AllocPostData 0x021B98A0 thumb ov114
 *   NHTTP_RAP_AppendPostData 0x021B98D8 thumb ov114
 *   NHTTP_RAP_CreatePostRequest 0x021B98F8 thumb ov114
 *   NHTTP_RAP_StartConnection 0x021B9748 thumb ov114
 *   NHTTP_RAP_GetResultCode 0x021B99DC thumb ov114
 *   NHTTP_RAP_PollConnection 0x021B9790 thumb ov114
 *   NHTTP_RAP_FreePostData 0x021B99B8 thumb ov114
 *   NHTTP_RAP_Destroy 0x021B9838 thumb ov114
 *   NHTTP_RAP_GetRecvBuffer 0x021B97F4 thumb ov114
 *   NHTTP_RAP_RecordList_GetCount 0x021B99F0 thumb ov114
 *   NHTTP_RAP_RecordList_GetRecord 0x021B9A14 thumb ov114
 *   NHTTP_RAP_RecordList_GetValue 0x021B99F4 thumb ov114
 *   gSpeciesNameBank 0x020A7370 data a4
 *   MSGDATA_ReadUnits 0x02045F5C arm
 *   DPW_BT_UploadPlayerAsync 0x021C9530 arm ov114
 *   BSUBWAY_SAVEDATA_GetTrainersTagA 0x0200DE94 thumb
 *   BSUBWAY_SAVEDATA_GetTrainersTagB 0x0200DEA0 thumb
 *   DPW_BT_IsAsyncEnd 0x021C93D0 arm ov114
 *   DPW_BT_GetAsyncResult 0x021C940C arm ov114
 *   DPW_BT_CancelAsync 0x021C9634 arm ov114
 *   GFL_NET_ERR_ShowScreen 0x0200F7B8 thumb
 *   GFL_NET_ERR_RaiseFatal 0x0200FB4C thumb
 *   CODEIN_PARAM_Create 0x0202E4EC thumb
 *   GAMESYSTEM_CallProc 0x020120B4 thumb
 *   gWifiBsubwayCodeInParam 0x021D8560 data ov116 a4
 *   gWifiBsubwayCodeInParamEx 0x021D8568 data ov116 a4
 *   d_021DA62C 0x021DA62C data ov129 a4
 *   ov129_id 0x81 data
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb  arm9
 *   GFL_USE_SetBgmPaused  0x02005DE4  thumb  arm9
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb  arm9
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb  arm9
 *   GFL_USE_IsBgmFading  0x02005E50  thumb  arm9
 *   GFL_USE_PushBgm  0x02005E64  thumb  arm9
 *   GFL_USE_PopBgm  0x02005E9C  thumb  arm9
 *   BSUBWAY_SAVEDATA_SetTrainers  0x0200DE6C  thumb  arm9
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb  arm9
 *   BSUBWAY_SCOREDATA_GetRecordScoreTier  0x0200DCFC  thumb  arm9
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb  arm9
 *   MYSTATUS_NameFromStrbuf  0x020084E4  thumb  arm9
 *   MYSTATUS_GetProfileId  0x0200853C  thumb  arm9
 */

#include "ov116_types.h"

struct Big;
struct BigObj;
struct Ctx;
struct Sub02008AECObj;
/* The PROCSYS work object is shared and opaque here; kept as void * so this
 * file carries no address-named stand-in. */
struct Proc;
struct RecSlot;
struct U16Vec;
struct MsgBank;
struct Rec;
struct Blk1AC;
struct Rec0200E6FC;
struct Sub0200852CObj;
struct Sub02009470Obj;
struct MsgData;
struct IcaAnime;
struct Param;
typedef unsigned char u8;


typedef unsigned int   u32;

typedef unsigned short u16;


typedef short s16;

typedef signed char s8;


typedef struct { u8 a : 1, b : 1, c : 6; } Bits;

struct Record { unsigned short id:11; unsigned short rest:5; };






extern int GF_OVERLAY_Load(int handle);
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *PROCSYS_AllocProcWork(void *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *,int,unsigned);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02008AECObj *CONSOLE_STAMP_GetFromSave(void *sys);
extern u32 GAME_DATA_GetWifiList(const struct BigObj *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *GAME_DATA_GetSaveBlock3B(void **p);
extern void *GAME_DATA_GetSaveBlock3A(void **p);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_SetBgmPaused(void *p);
extern int GFL_USE_PushBgm(void);
extern void GFL_USE_CancelChangeAndPlayBgm(int,int);
extern void GFL_USE_FadeInBgmFull(unsigned);
extern void GFL_USE_FadeOutBgm(u32 a);
extern void WIFI_BSUBWAY_GRAPHIC_StartSaveProc(u8 *);
extern void WIFI_BSUBWAY_GRAPHIC_CreateWindow(u8 *,u32);
extern void FADE_Start(u32 a, int b, int c, int d);
extern void WIFI_BSUBWAY_GRAPHIC_InitBt(u8 *);
extern int WIFI_BSUBWAY_GRAPHIC_GetSaveState(u8 *),FADE_IsActive(void),WIFI_BSUBWAY_GRAPHIC_PollBt(u8 *),WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(void *);
extern void WIFI_BSUBWAY_GRAPHIC_PrintMessage(void *,u32);
extern void WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon(u8 *p);
extern int WIFI_BSUBWAY_StatusCheckMessage(u8 *,unsigned),WIFI_BSUBWAY_FinishProfileUpload(u8 *,u8 *),WIFI_BSUBWAY_GRAPHIC_DispatchTable(u8 *,int),WIFI_BSUBWAY_GRAPHIC_EndBt(u8 *);
extern void WIFI_BSUBWAY_StartProfileUpload(u8 *,void *,u8 *),WIFI_BSUBWAY_GRAPHIC_CancelBt(u8 *),WIFI_BSUBWAY_GRAPHIC_DeleteWindow(u8 *),WIFI_BSUBWAY_GRAPHIC_StartRetryProc(u8 *);
extern u32 GFL_NET_ERR_ShowScreen(u32 isFatal);
extern int WIFI_BSUBWAY_GRAPHIC_CheckNetError(u8 *);
extern int WIFI_BSUBWAY_GRAPHIC_IsPrintDone(u8 *);
extern void WIFI_BSUBWAY_AbortHttpRequest(u8 *),DPW_BT_Main(void),WIFI_BSUBWAY_GRAPHIC_UpdateText(u8 *);
extern void WIFI_BSUBWAY_GRAPHIC_DeleteTextParam(u8 *p);
extern void WIFI_BSUBWAY_GRAPHIC_Noop(void *);
extern void WIFI_BSUBWAY_GRAPHIC_NoopRetry(void *);
extern void WIFI_BSUBWAY_GRAPHIC_DeleteWindow(u8 *p);
extern void PROCSYS_FreeProcWork(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int);
extern void GF_OVERLAY_Unload(int handle);
extern int GFL_USE_PopBgm(void);
extern int FADE_IsActive(void);
extern void DPW_BT_GetRoomNumAsync(unsigned x);
extern void DPW_BT_DownloadPlayerAsync(unsigned x, unsigned y, unsigned z);
extern u32 NATION_AREA_SanitizeNation(u32,u32,u32);
extern u32 NATION_AREA_SanitizeArea(u32,u32,u32);
extern u32 CURSOR_MOVE_FindTableGroupIndex(u32);
extern u32 CURSOR_MOVE_GetTableGroup(u32);
extern int DWC_GetDateTime(void *, void *);
extern void BSUBWAY_SAVEDATA_SetTrainers(struct RecSlot *p, const void *src, u8 a, u8 b);
extern void BSUBWAY_WIFIDATA_SetTrainerBit(u8 *p, u8 a, u8 b, u32 *q);
extern void BSUBWAY_SAVEDATA_SetHistory(struct RecSlot *p, const void *src, u8 a, u8 b);
extern void *MYSTATUS_Create(int);
extern u32 GFL_HEAP_Free(void *p);
extern void MYSTATUS_Copy(void *, void *);
extern void *MYSTATUS_CreateNameStrbuf(void *, int);
extern u16 *STRBUF_GetChars(struct U16Vec *vec);
extern u16 STRBUF_GetLength(struct U16Vec *vec);
extern u16 STRBUF_GetEosChar(void);
extern int DWC_CheckProfanityExAsync(unsigned short **words, int wordsnum, char *reserved, int timeout, char *result, int *badwordsnum, int region);
extern void STRBUF_Delete(struct U16Vec *vec);
extern int DWC_CheckProfanityProcess(void);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void MYSTATUS_NameFromStrbuf(u16 *out, struct U16Vec *vec);
extern void NHTTP_RAP_InitTrainerInfo(u8 *,int);
extern void DPW_BT_SetProfileAsync(unsigned char *p, unsigned x);
extern struct Sub02009470Obj *WIFI_HISTORY_GetBlock(void *sys);
extern void *GREETING_SAVEDATA_GetFromSave(u32);
extern const void *MYSTATUS_GetName(const void *p);
extern void MI_CpuCopy8(const void *, void *, u32);
extern u32 MYSTATUS_GetId(const struct Sub0200852CObj *obj);
extern u8 MYSTATUS_GetNation(const struct Sub0200852CObj *obj);
extern u8 MYSTATUS_GetArea(const struct Sub0200852CObj *obj);
extern u8 MYSTATUS_GetSex(const struct Sub0200852CObj *obj);
extern u8 MYSTATUS_GetTrainerView(const struct Sub0200852CObj *obj);
extern void GREETING_SAVEDATA_GetSentence(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern u16 BSUBWAY_SCOREDATA_GetRecordScore(struct Blk1AC *p);
extern void BSUBWAY_SCOREDATA_GetRecordBlob(struct Blk1AC *p, u32 which, void *dest);
extern void NHTTP_RAP_DeleteConnection(unsigned char *);
extern u32 MYSTATUS_GetProfileId(const struct Sub0200852CObj *obj);
extern u8 *NHTTP_RAP_Create(int,int,int);
extern void DWC_RAP_SetErrorCallback(int errorFunc, int errorArg);
extern void NHTTP_RAP_AllocPostData(u8 *,int,int,int);
extern void NHTTP_RAP_AppendPostData(u8 *p, int a, int n);
extern int NHTTP_RAP_CreatePostRequest(u8 *p);
extern int NHTTP_RAP_StartConnection(u8 *);
extern int NHTTP_RAP_GetResultCode(u8 *);
extern int NHTTP_RAP_PollConnection(u8 *);
extern void NHTTP_RAP_FreePostData(u8 *);
extern void NHTTP_RAP_Destroy(u8 *);
extern u8 *NHTTP_RAP_GetRecvBuffer(u8 *);
extern int NHTTP_RAP_RecordList_GetCount(u8 *p);
extern u8 *NHTTP_RAP_RecordList_GetRecord(u8 *p, u32 i);
extern u32 NHTTP_RAP_RecordList_GetValue(u32 p, u32 i);
extern void MSGDATA_ReadUnits(struct MsgData *,unsigned int,unsigned short *,unsigned int);
extern u8 BSUBWAY_SAVEDATA_GetTrainersTagA(struct RecSlot *p);
extern u8 BSUBWAY_SAVEDATA_GetTrainersTagB(struct RecSlot *p);
extern u8 BSUBWAY_SCOREDATA_GetRecordScoreTier(struct Blk1AC *p);
extern void DPW_BT_UploadPlayerAsync(u32 a, u32 b, u32 c, const void *p, const void *q, u32 v);
extern int DPW_BT_IsAsyncEnd(void);
extern int DPW_BT_GetAsyncResult(void);
extern void DPW_BT_CancelAsync(void);
extern void GFL_NET_ERR_RaiseFatal(unsigned int x);
extern struct Param *CODEIN_PARAM_Create(u32 heap, u32 mode, u32 initialPage, u32 maxLength, u32 *src);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
int WIFI_BSUBWAY_Create(void *ctx,int unused,u8 *q);
int WIFI_BSUBWAY_Step(void *a,int *state,int b,u8 *p);
int WIFI_BSUBWAY_Delete(void *p, int a, int b, u8 *q);
int WIFI_BSUBWAY_IsTransferReady(unsigned char *a,int b);
void WIFI_BSUBWAY_ClearTrainers(void *a);
void WIFI_BSUBWAY_StartRoomRequest(unsigned char *a,unsigned char *b,unsigned short c);
int WIFI_BSUBWAY_FinishRoomRequest(unsigned char *a,unsigned char *b);
void WIFI_BSUBWAY_StartPlayerDownload(unsigned char *a,unsigned char *b,unsigned short c);
int WIFI_BSUBWAY_FinishPlayerDownload(unsigned char *a,unsigned char *b);
u16 WIFI_BSUBWAY_GetRoomNumber(u8 *p);
u16 WIFI_BSUBWAY_GetPlayerIndex(u8 *p);
u16 WIFI_BSUBWAY_GetDownloadResult(u8 *p);
int WIFI_BSUBWAY_GetTransferState(unsigned char *p);
void WIFI_BSUBWAY_NormalizeTrainers(u8 *p);
void WIFI_BSUBWAY_SaveTrainers(u8 *p, void *q);
void WIFI_BSUBWAY_SaveHistory(unsigned char *a,void *b);
void WIFI_BSUBWAY_StatusInit(unsigned char *a,int b);
void WIFI_BSUBWAY_StatusDelete(unsigned char *a);
void WIFI_BSUBWAY_StatusSetMessage(u8 *p, void *save, int id);
int WIFI_BSUBWAY_StatusCheckMessage(u8 *p,unsigned heap);
void WIFI_BSUBWAY_StartProfileUpload(u8 *p,void *q,u8 *r);
int WIFI_BSUBWAY_FinishProfileUpload(unsigned char *a,unsigned char *b);
void WIFI_BSUBWAY_BuildProfile(u8 *p, void *save, void *idx);
void WIFI_BSUBWAY_OnHttpError(unsigned char *a);
void WIFI_BSUBWAY_StartHttpRequest(u8 *p,u8 *q,int a,int b);
int WIFI_BSUBWAY_PollHttpRequest(u8 *p, u8 *q, int flag);
void WIFI_BSUBWAY_ReadRecordUnits(unsigned int a,unsigned int b);
void WIFI_BSUBWAY_AbortHttpRequest(u8 *p);
void WIFI_BSUBWAY_StartUploadPlayer(u8 *p, u8 *q);
int WIFI_BSUBWAY_IsUploadDone(void *unused, u8 *p);
void WIFI_BSUBWAY_AsyncInit(void *p);
void WIFI_BSUBWAY_AsyncReset(u8 *p);
int WIFI_BSUBWAY_PollAsync(u8 *p,int *q);
int WIFI_BSUBWAY_AsyncHasError(u8 *p);
int WIFI_BSUBWAY_GetErrorState(int *p);
int WIFI_BSUBWAY_CheckFatalError(int *p);
void WIFI_BSUBWAY_SetDownloadResult(u8 *p, u32 v);
void WIFI_BSUBWAY_SetHttpError(u8 *p, u32 v);
void WIFI_BSUBWAY_ResetUpload(u8 *p);
void WIFI_BSUBWAY_TickUploadTimeout(u8 *p);
void WIFI_BSUBWAY_OpenCodeIn(u8 *p,int a);
extern u8 ov_id[];
extern u8 GAME_VERSION_Code, GAME_LANGUAGE_Code;
extern struct MsgData *gSpeciesNameBank;
extern u32 gWifiBsubwayCodeInParam[],gWifiBsubwayCodeInParamEx[],d_021DA62C[];
extern u8 ov129_id[];

int WIFI_BSUBWAY_Create(void *task,int unused,u8 *parent) {
    u8 *work;
    void *saveControl;
    GF_OVERLAY_Load((int)ov_id);
    GFL_HEAP_CreateChildHeap(1,125,0x18000);
    work=PROCSYS_AllocProcWork(task,0x185c,125);
    MI_CpuFill8(work,0,0x185c);
    *(u8 **)work=parent;
    *(int *)(parent+8)=1;
    saveControl=GAMESYSTEM_GetGameData(*(void **)(*(u8 **)work+4));
    parent=GAME_DATA_GetSaveControl(saveControl);
    *(void **)(work+0x1844)=saveControl;
    *(int *)(work+0x1848)=(int)CONSOLE_STAMP_GetFromSave(parent);
    *(int *)(work+0x184c)=GAME_DATA_GetWifiList(saveControl);
    *(int *)(work+0x1850)=(int)GAME_DATA_GetMyStatus(saveControl);
    *(int *)(work+0x1854)=(int)GAME_DATA_GetSaveBlock3B(saveControl);
    *(int *)(work+0x1858)=(int)GAME_DATA_GetSaveBlock3A(saveControl);
    WIFI_BSUBWAY_ClearTrainers(work+0xb74);
    WIFI_BSUBWAY_StatusInit(work+0x1610,125);
    WIFI_BSUBWAY_AsyncInit(work+0x182c);
    return 1;
}

int WIFI_BSUBWAY_Step(void *unusedA,int *state,int unusedB,u8 *work)
{
    int result;
    if(WIFI_BSUBWAY_IsTransferReady(work,*state)!=0) {
        if(WIFI_BSUBWAY_AsyncHasError(work+0x182c)!=0 || GFL_NET_ERR_GetErrorLevel()!=0) *state=20;
    }
    switch(*state) {
    case 0: GFL_USE_FadeOutBgm(6); ++*state; break;
    case 1: if(GFL_USE_IsBgmFading()==0) { GFL_USE_SetBgmPaused((void *)1); GFL_USE_PushBgm(); GFL_USE_CancelChangeAndPlayBgm(1153,65535); GFL_USE_FadeInBgmFull(6); ++*state; } break;
    case 2: WIFI_BSUBWAY_GRAPHIC_StartSaveProc(work); ++*state; break;
    case 3: if(WIFI_BSUBWAY_GRAPHIC_GetSaveState(work)==0) ++*state; else { ((struct WifiBsubwayParent *)(*(u8 * *)&((struct WifiBsubwayWork *)work)->parent))->state=2; *state=17; } break;
    case 4: WIFI_BSUBWAY_GRAPHIC_CreateWindow(work+4,125); FADE_Start(3,16,0,1); ++*state; break;
    case 5: if(FADE_IsActive()==0) ++*state; break;
    case 6: WIFI_BSUBWAY_GRAPHIC_InitBt(work); WIFI_BSUBWAY_GRAPHIC_PrintMessage(work+4,26); WIFI_BSUBWAY_GRAPHIC_CreateTimeIcon(work+4); ++*state; break;
    case 7: if(WIFI_BSUBWAY_GRAPHIC_PollBt(work)!=0) ++*state; break;
    case 8: if(WIFI_BSUBWAY_GRAPHIC_UpdatePrintStream(work+4)!=0) ++*state; break;
    case 9: WIFI_BSUBWAY_StatusSetMessage(work+0x1610,((struct WifiBsubwayWork *)work)->saveControl,125); ++*state; break;
    case 10: if(WIFI_BSUBWAY_StatusCheckMessage(work+0x1610,125)!=0) ++*state; break;
    case 11: WIFI_BSUBWAY_StartProfileUpload(work+0x1610,((struct WifiBsubwayWork *)work)->saveControl,work+0x182c); ++*state; break;
    case 12: if(WIFI_BSUBWAY_FinishProfileUpload(work+0x1610,work+0x182c)!=0) ++*state; break;
    case 13: result=WIFI_BSUBWAY_GRAPHIC_DispatchTable(work,125); if(result==1) { ((struct WifiBsubwayParent *)(*(u8 * *)&((struct WifiBsubwayWork *)work)->parent))->state=0; ++*state; } else if(result==2) { ((struct WifiBsubwayParent *)(*(u8 * *)&((struct WifiBsubwayWork *)work)->parent))->state=2; ++*state; } break;
    case 14: WIFI_BSUBWAY_GRAPHIC_CancelBt(work); FADE_Start(3,0,16,1); ++*state; break;
    case 15: if(WIFI_BSUBWAY_GRAPHIC_EndBt(work)!=0 && FADE_IsActive()==0) { WIFI_BSUBWAY_GRAPHIC_DeleteWindow(work+4); ++*state; } break;
    case 16: if(GFL_NET_ERR_ShowScreen(0)==0) WIFI_BSUBWAY_GRAPHIC_StartRetryProc(work); ++*state; break;
    case 17: GFL_USE_FadeOutBgm(6); ++*state; break;
    case 18: if(GFL_USE_IsBgmFading()==0) ++*state; break;
    case 19: return 1;
    case 20: if(WIFI_BSUBWAY_GRAPHIC_CheckNetError(work)!=0) *state=21; else *state=14; WIFI_BSUBWAY_AbortHttpRequest(work+0x1610); break;
    case 21: if(WIFI_BSUBWAY_GRAPHIC_IsPrintDone(work)!=0) *state=14; break;
    }
    if(((struct WifiBsubwayWork *)work)->dpwActive!=0) DPW_BT_Main();
    WIFI_BSUBWAY_GRAPHIC_UpdateText(work+4);
    return 0;
}

int WIFI_BSUBWAY_Delete(void *unusedA, int unusedB, int unusedC, u8 *work) {
    WIFI_BSUBWAY_GRAPHIC_DeleteTextParam(work);
    WIFI_BSUBWAY_GRAPHIC_Noop(work);
    WIFI_BSUBWAY_GRAPHIC_NoopRetry(work);
    WIFI_BSUBWAY_StatusDelete(work + 0x1610);
    WIFI_BSUBWAY_GRAPHIC_DeleteWindow(work + 4);
    PROCSYS_FreeProcWork(unusedA);
    GFL_HEAP_DeleteChecked(125);
    GF_OVERLAY_Unload((int)ov_id);
    GFL_USE_PopBgm();
    GFL_USE_SetBgmPaused(0);
    GFL_USE_FadeInBgmFull(60);
    return 1;
}

int WIFI_BSUBWAY_IsTransferReady(unsigned char *work,int state) { if(state<=13 && FADE_IsActive()==0 && ((struct WifiBsubwayWork *)work)->dpwActive!=0 && ((struct WifiBsubwayWork *)work)->dpwDone==0) return 1; return 0; }

void WIFI_BSUBWAY_ClearTrainers(void *trainers) { MI_CpuFill8(trainers,0,0xa9c); }

/*
 * Two bytes zero alignment padding follow the compiled function.
 */
void WIFI_BSUBWAY_StartRoomRequest(unsigned char *trainers,unsigned char *async,unsigned short roomNumber) { ((struct WifiBsubwayTrainers *)trainers)->roomNumber=roomNumber; DPW_BT_GetRoomNumAsync((unsigned char)roomNumber); WIFI_BSUBWAY_AsyncReset(async); }

int WIFI_BSUBWAY_FinishRoomRequest(unsigned char *trainers,unsigned char *async) { int result; if(WIFI_BSUBWAY_PollAsync(async,&result) && WIFI_BSUBWAY_AsyncHasError(async)==0) { ((struct WifiBsubwayTrainers *)trainers)->downloadResult=result; ((struct WifiBsubwayTrainers *)trainers)->roomReady=1; return 1; } return 0; }

void WIFI_BSUBWAY_StartPlayerDownload(unsigned char *trainers,unsigned char *async,unsigned short playerIndex) { ((struct WifiBsubwayTrainers *)trainers)->playerIndex=playerIndex; DPW_BT_DownloadPlayerAsync((unsigned char)(((struct WifiBsubwayTrainers *)trainers)->roomNumber),(unsigned char)(((struct WifiBsubwayTrainers *)trainers)->playerIndex),(unsigned int)(trainers+14)); WIFI_BSUBWAY_AsyncReset(async); }

/*
 * Remaining extent: existing matched accessor files at 021D6A40 and 021D6A44.
 */
int WIFI_BSUBWAY_FinishPlayerDownload(unsigned char *trainers,unsigned char *async) { int result; if(((struct WifiBsubwayTrainers *)trainers)->playerReady) return 1; if(WIFI_BSUBWAY_PollAsync(async,&result) && WIFI_BSUBWAY_AsyncHasError(async)==0) { ((struct WifiBsubwayTrainers *)trainers)->playerReady=1; return 1; } return 0; }

/*
 * leaf: blocks WIFI_BSUBWAY_GRAPHIC_StepWithInput.
 */
u16 WIFI_BSUBWAY_GetRoomNumber(u8 *trainers) { return ((struct WifiBsubwayTrainers *)trainers)->roomNumber; }

u16 WIFI_BSUBWAY_GetPlayerIndex(u8 *trainers) { return ((struct WifiBsubwayTrainers *)trainers)->playerIndex; }


u16 WIFI_BSUBWAY_GetDownloadResult(u8 *trainers) { return ((struct WifiBsubwayTrainers *)trainers)->downloadResult; }

int WIFI_BSUBWAY_GetTransferState(unsigned char *trainers)
{
    if (*(unsigned short *)(trainers + 12) < 100) {
        return 2;
    }
    return 3;
}

void WIFI_BSUBWAY_NormalizeTrainers(u8 *trainers) {
    int i,j;
    u8 *records,*history;
    records=trainers+14;
    history=trainers+0x69e;
    for(i=0;i<7;i++) {
        j=i*240;
        records[j+0xc6]=NATION_AREA_SanitizeNation(records[j+0xc6],records[j+0xc7],records[j+0xc5]);
        records[j+0xc7]=NATION_AREA_SanitizeArea(records[j+0xc6],records[j+0xc7],records[j+0xc5]);
        records[j+0xd5]=CURSOR_MOVE_GetTableGroup(CURSOR_MOVE_FindTableGroupIndex(records[j+0xd5]));
    }
    for(i=0;i<30;i++) {
        records=history+i*34;
        records[18]=NATION_AREA_SanitizeNation(records[18],records[19],records[17]);
        records[19]=NATION_AREA_SanitizeArea(records[18],records[19],records[17]);
    }
}

void WIFI_BSUBWAY_SaveTrainers(u8 *trainers, void *save) {
    u32 time[3];
    u32 date[4];
    DWC_GetDateTime(date, time);
    BSUBWAY_SAVEDATA_SetTrainers(save, trainers + 14, *(u16 *)(trainers + 8), *(u16 *)(trainers + 10));
    BSUBWAY_WIFIDATA_SetTrainerBit(save, *(u16 *)(trainers + 8), *(u16 *)(trainers + 10), date);
}

void WIFI_BSUBWAY_SaveHistory(unsigned char *trainers,void *save) { BSUBWAY_SAVEDATA_SetHistory(save,trainers+0x69e,((struct WifiBsubwayTrainers *)trainers)->roomNumber,((struct WifiBsubwayTrainers *)trainers)->playerIndex); }

void WIFI_BSUBWAY_StatusInit(unsigned char *status,int heapId) { MI_CpuFill8(status,0,0x21c); ((struct WifiBsubwayStatus *)status)->mystatus=MYSTATUS_Create(heapId); }

void WIFI_BSUBWAY_StatusDelete(unsigned char *status) { if(((struct WifiBsubwayStatus *)status)->mystatus) { GFL_HEAP_Free(((struct WifiBsubwayStatus *)status)->mystatus); ((struct WifiBsubwayStatus *)status)->mystatus=0; } }

/*
 * extent: two zero alignment bytes at 021D6C4E follow the epilogue.
 * evidence: 0217BC44's full ov009 ARM wrapper forwards r0-r3 and
 * three full-word stack arguments to 0217B828; this caller supplies all7.
 */
void WIFI_BSUBWAY_StatusSetMessage(u8 *status, void *saveControl, int msgId)
{
    void *msg;
    u16 *chars;
    u32 i;
    MYSTATUS_Copy(GAME_DATA_GetMyStatus(saveControl), ((struct WifiBsubwayStatus *)status)->mystatus);
    msg = MYSTATUS_CreateNameStrbuf(((struct WifiBsubwayStatus *)status)->mystatus, msgId);
    MI_CpuFill8(status + 0x1f0, 0, 40);
    ((struct WifiBsubwayStatus *)status)->msgId = msgId;
    chars = STRBUF_GetChars(msg);
    for (i = 0; i < STRBUF_GetLength(msg) + 1u; i++) {
        u16 ch = chars[i];
        if (ch == STRBUF_GetEosChar()) ((u16 *)(status + 0x1f0))[i] = 0;
        else ((u16 *)(status + 0x1f0))[i] = ch;
    }
    ((struct WifiBsubwayStatus *)status)->wordList = status + 0x1f0;
    ((struct WifiBsubwayStatus *)status)->badWordCount = 0;
    DWC_CheckProfanityExAsync((short unsigned int **)(status + 0x208), 1, 0, 0, (char *)(status + 0x20c), (int *)(status + 0x210), 128);
    STRBUF_Delete(msg);
}

int WIFI_BSUBWAY_StatusCheckMessage(u8 *status,unsigned heapId) {
    int pollResult,hasBadWords;
    void *msgBank,*msg;
    pollResult = DWC_CheckProfanityProcess()==2;
    if(pollResult) hasBadWords = ((struct WifiBsubwayStatus *)status)->badWordCount>0;
    if(pollResult==0) return 0;
    if(pollResult==1 && hasBadWords==1) {
        msgBank = MSGDATA_CreateFromArchive(0,2,0x51,heapId);
        msg = MSGDATA_AllocString(msgBank,15);
        MSGDATA_Delete(msgBank);
        MYSTATUS_NameFromStrbuf((u16 *)((struct WifiBsubwayStatus *)status)->mystatus,msg);
        STRBUF_Delete(msg);
        return 2;
    }
    return 1;
}

/*
 *   extern int SAVE_CONTROL_GetBlock(void *,int);
 *   int GAME_DATA_GetSaveBlock3A(void **p) { return SAVE_CONTROL_GetBlock(*p,58); }
 *   extern int SAVE_CONTROL_GetBlock(void *,int);
 *   int GAME_DATA_GetSaveBlock3B(void **p) { return SAVE_CONTROL_GetBlock(*p,59); }
 */
void WIFI_BSUBWAY_StartProfileUpload(u8 *status,void *saveControl,u8 *async) {
    int saveBlockB,saveBlockA,recordCount;
    GAME_DATA_GetSaveControl(saveControl);
    saveBlockB = (int)GAME_DATA_GetSaveBlock3B(saveControl);
    saveBlockA = (int)GAME_DATA_GetSaveBlock3A(saveControl);
    recordCount = *(int *)(status+0x218);
    NHTTP_RAP_InitTrainerInfo(status+4,recordCount);
    DPW_BT_SetProfileAsync(status+4,(unsigned int)(status+0x68));
    WIFI_BSUBWAY_AsyncReset(async);
    WIFI_BSUBWAY_BuildProfile(status+0x70,saveControl,(void *)recordCount);
    *(int *)(status+0x160)=saveBlockB;
    *(int *)(status+0x164)=saveBlockA;
}

int WIFI_BSUBWAY_FinishProfileUpload(unsigned char *status,unsigned char *async) { int result; if(WIFI_BSUBWAY_PollAsync(async,&result) && WIFI_BSUBWAY_AsyncHasError(async)==0) { ((struct WifiBsubwayStatus *)status)->ready=1; return 1; } return 0; }

/*
 * singleton tu --suggest-split returns MATCH252, no viable partition.
 * fixed dsi/1.1p1 -O4,p Thumb; copied prior 6CBC blocker, owner the integrator.
 *   extern int SAVE_CONTROL_GetBlock(void *, int);
 *   int GAME_DATA_GetSaveBlock3A(void **p) { return SAVE_CONTROL_GetBlock(*p, 58); }
 * evidence: 084F4 is bx lr and preserves its incoming pointer in r0;
 * caller consumes it despite the matched callee's void signature.
 * evidence: 08550's matched body returns zero-extended byte +1d;
 * original caller explicitly truncates that r0 before the byte bitfield.
 * A wide extern and explicit u8 cast retain that redundant conversion.
 * checks: 1 own callee/unit bodies and original live registers agree;
 * 2 full 6CBC/6A5C/6E50 twins; 3 wide8550+u8 cast fixes missing4B;
 * 4 redundant-bitfield/result-truncation idioms; 5 fresh full idiom ls
 * and full 6C50/6A5C/6E50 neighbours. Iteration2, no stop exhaustion.
 */
void WIFI_BSUBWAY_BuildProfile(u8 *profileRecord, void *saveControl, void *trainer)
{
    void *profile, *saveBlockA, *saveData;
    int i;
    profile = GAME_DATA_GetSaveControl(saveControl);
    WIFI_HISTORY_GetBlock(profile);
    GAME_DATA_GetWifiList(saveControl);
    saveBlockA = GAME_DATA_GetSaveBlock3A(saveControl);
    saveData = GREETING_SAVEDATA_GetFromSave((u32)profile);
    MI_CpuFill8(profileRecord, 0, 240);
    MI_CpuCopy8(MYSTATUS_GetName(trainer), profileRecord + 0xb4, 16);
    *(u32 *)(profileRecord + 0xc8) = MYSTATUS_GetId(trainer);
    profileRecord[0xc4] = GAME_VERSION_Code;
    profileRecord[0xc5] = GAME_LANGUAGE_Code;
    profileRecord[0xc6] = MYSTATUS_GetNation(trainer);
    profileRecord[0xc7] = MYSTATUS_GetArea(trainer);
    ((Bits *)(profileRecord + 0xd4))->b = (u8)(u32)MYSTATUS_GetSex(trainer);
    profileRecord[0xd5] = MYSTATUS_GetTrainerView(trainer);
    profileRecord[0xd5] = CURSOR_MOVE_GetTableGroup(profileRecord[0xd5]);
    for (i = 0; i < 3; i++) GREETING_SAVEDATA_GetSentence(saveData, i + 1, (struct Rec0200E6FC *)(profileRecord + 0xd6 + i * 8));
    GREETING_SAVEDATA_GetSentence(saveData, 4, (struct Rec0200E6FC *)(profileRecord + 0xcc));
    *(u16 *)(profileRecord + 0xee) = BSUBWAY_SCOREDATA_GetRecordScore(saveBlockA);
    BSUBWAY_SCOREDATA_GetRecordBlob(saveBlockA, 1, profileRecord);
}

void WIFI_BSUBWAY_OnHttpError(unsigned char *status) { if(((struct WifiBsubwayStatus *)status)->http) NHTTP_RAP_DeleteConnection(((struct WifiBsubwayStatus *)status)->http); }

void WIFI_BSUBWAY_StartHttpRequest(u8 *status,u8 *async,int unusedA,int heapId) {
    *(u8 * *)&((struct WifiBsubwayStatus *)status)->http=NHTTP_RAP_Create(heapId,MYSTATUS_GetProfileId(((struct WifiBsubwayStatus *)status)->mystatus),unusedA);
    DWC_RAP_SetErrorCallback((int)WIFI_BSUBWAY_OnHttpError,(int)status);
    NHTTP_RAP_AllocPostData(*(u8 * *)&((struct WifiBsubwayStatus *)status)->http,heapId,180,4);
    NHTTP_RAP_AppendPostData(*(u8 * *)&((struct WifiBsubwayStatus *)status)->http,(int)(status+0x70),180);
    ((struct WifiBsubwayStatus *)status)->recordCount=3;
    NHTTP_RAP_CreatePostRequest(*(u8 * *)&((struct WifiBsubwayStatus *)status)->http);
    NHTTP_RAP_StartConnection(*(u8 * *)&((struct WifiBsubwayStatus *)status)->http);
    WIFI_BSUBWAY_ResetUpload(async);
}

/*
 * extent: two zero alignment bytes at 021D700E follow the epilogue.
 * evidence: ov114 labelled 97F4/99F0/99F4/9A14 bodies read the
 * declared pointer/index inputs; 99F4 reconstructs a full32-bit value.
 * Original keeps field loads and repeated per-call object reloads.
 */
int WIFI_BSUBWAY_PollHttpRequest(u8 *status, u8 *async, int quiet)
{
    int result = 0;
    int httpCode, pollResult, allOk, i;
    u8 *recvBuf;
    httpCode = NHTTP_RAP_GetResultCode(*(u8 * *)&((struct WifiBsubwayStatus *)status)->http);
    pollResult = NHTTP_RAP_PollConnection(*(u8 * *)&((struct WifiBsubwayStatus *)status)->http);
    if (httpCode != 200 && pollResult == 0) {
        WIFI_BSUBWAY_SetHttpError(async, httpCode);
        NHTTP_RAP_DeleteConnection(*(u8 * *)&((struct WifiBsubwayStatus *)status)->http);
        NHTTP_RAP_FreePostData(*(u8 * *)&((struct WifiBsubwayStatus *)status)->http);
        NHTTP_RAP_Destroy(*(u8 * *)&((struct WifiBsubwayStatus *)status)->http);
        *(u8 * *)&((struct WifiBsubwayStatus *)status)->http = 0;
        DWC_RAP_SetErrorCallback(0, 0);
        return 2;
    }
    if (pollResult != 0) {
        WIFI_BSUBWAY_TickUploadTimeout(async);
    } else {
        recvBuf = NHTTP_RAP_GetRecvBuffer(*(u8 * *)&((struct WifiBsubwayStatus *)status)->http);
        if (NHTTP_RAP_RecordList_GetCount(recvBuf) == 0) {
            allOk = 1;
            MI_CpuCopy8(NHTTP_RAP_RecordList_GetRecord(recvBuf, ((struct WifiBsubwayStatus *)status)->recordCount), status + 0x16e, 128);
            for (i = 0; i < ((struct WifiBsubwayStatus *)status)->recordCount; i++) {
                if (NHTTP_RAP_RecordList_GetValue((u32)recvBuf, i) != 0) {
                    allOk = 0;
                    if (quiet != 0) WIFI_BSUBWAY_SetDownloadResult(async, 1);
                    else WIFI_BSUBWAY_ReadRecordUnits((unsigned int)status, i);
                }
            }
            if (allOk != 0) result = 1;
            else result = 2;
        } else {
            if (quiet != 0) WIFI_BSUBWAY_SetDownloadResult(async, 2);
            result = 2;
            for (i = 0; i < ((struct WifiBsubwayStatus *)status)->recordCount; i++) {
                if (NHTTP_RAP_RecordList_GetValue((u32)recvBuf, i) != 0) WIFI_BSUBWAY_ReadRecordUnits((unsigned int)status, i);
            }
        }
        NHTTP_RAP_FreePostData(*(u8 * *)&((struct WifiBsubwayStatus *)status)->http);
        NHTTP_RAP_Destroy(*(u8 * *)&((struct WifiBsubwayStatus *)status)->http);
        *(u8 * *)&((struct WifiBsubwayStatus *)status)->http = 0;
        DWC_RAP_SetErrorCallback(0, 0);
    }
    return result;
}

void WIFI_BSUBWAY_ReadRecordUnits(unsigned int status,unsigned int index) { unsigned int record; record=status+0x70+index*0x3c; MSGDATA_ReadUnits(gSpeciesNameBank,((struct Record *)record)->id,(unsigned short *)(record+0x22),11); }

void WIFI_BSUBWAY_AbortHttpRequest(u8 *status)
{
    if (*(u8 * *)&((struct WifiBsubwayStatus *)status)->http) {
        DWC_RAP_SetErrorCallback(0, 0);
        NHTTP_RAP_FreePostData(*(u8 * *)&((struct WifiBsubwayStatus *)status)->http);
        NHTTP_RAP_Destroy(*(u8 * *)&((struct WifiBsubwayStatus *)status)->http);
        *(u8 * *)&((struct WifiBsubwayStatus *)status)->http = 0;
    }
}

void WIFI_BSUBWAY_StartUploadPlayer(u8 *status, u8 *async) {
    int tagA, tagB, tagC;
    tagA = BSUBWAY_SAVEDATA_GetTrainersTagA(((struct WifiBsubwayStatus *)status)->saveBlockB);
    tagB = BSUBWAY_SAVEDATA_GetTrainersTagB(((struct WifiBsubwayStatus *)status)->saveBlockB);
    tagC = BSUBWAY_SCOREDATA_GetRecordScoreTier(((struct WifiBsubwayStatus *)status)->saveBlockA);
    DPW_BT_UploadPlayerAsync((u8)tagA,(u8)tagB,(u8)tagC,status+0x70,status+0x16e,(int)0x80);
    WIFI_BSUBWAY_AsyncReset(async);
}

int WIFI_BSUBWAY_IsUploadDone(void *unused, u8 *async)
{
    int result;
    if (WIFI_BSUBWAY_PollAsync(async, &result) && WIFI_BSUBWAY_AsyncHasError(async) == 0) return 1;
    return 0;
}

void WIFI_BSUBWAY_AsyncInit(void *async) { MI_CpuFill8(async, 0, 0x14); }


void WIFI_BSUBWAY_AsyncReset(u8 *async) { ((struct WifiBsubwayAsync *)async)->timedOut = 0; ((struct WifiBsubwayAsync *)async)->ticks = 0; }

/*
 * 2026-10-05 (wD4 lane19): still MATCH. Blocked by ov114 ARM 0x021C93D0 and 0x021C940C (pengy overlay, no witness).
 * Also unresolved: ov114 ARM 0x021C93D0, unlabelled state query leaf.
 * No overlay leaves filed because the SDK blocker persists; parent requested park.
 * ISA evidence: show --region ov114 --arm reads state at 0x021D4084;
 * overlapping ov021 0x021C93D0 is different Thumb code.
 * 2026-10-05 (wD8 lane09): re-run, still MATCH. Open relocations: DPW_BT_IsAsyncEnd and DPW_BT_GetAsyncResult (ov114
 *   ARM, SDK-side, no witness). Nothing source-side to change.
 */
int WIFI_BSUBWAY_PollAsync(u8 *async,int *outResult) {
    int done=0;
    if(DPW_BT_IsAsyncEnd()==0) {
        (*(s16 *)(async+10))++;
        if(*(s16 *)(async+10)==3600) {
            DPW_BT_CancelAsync();
            *(s16 *)(async+8)=1;
        }
    } else {
        int result=DPW_BT_GetAsyncResult();
        done=1;
        switch(result) {
        case -7: case -6: case -4: case -3: case -2: case -1:
            *(int *)async=result; break;
        case -5: GFL_NET_ERR_ShowScreen(1); break;
        default:
            if(result>=0) *outResult=result;
            else GFL_NET_ERR_ShowScreen(1);
            break;
        }
    }
    return done;
}

int WIFI_BSUBWAY_AsyncHasError(u8 *async)
{
    if (((struct WifiBsubwayAsync *)async)->result < 0) return 1;
    if (((struct WifiBsubwayAsync *)async)->flag != 0) return 1;
    if (((struct WifiBsubwayAsync *)async)->state != 0) return 1;
    if (((struct WifiBsubwayAsync *)async)->timedOut != 0) return 1;
    return 0;
}

int WIFI_BSUBWAY_GetErrorState(int *async) {
    int state=0;
    if(async[0]<0) {
        switch(async[0]) {
        case -2: state=16; break;
        case -6: state=17; break;
        case -1: state=15; break;
        case -7: state=19; break;
        case -4: state=18; break;
        case -3: state=20; break;
        default: state=22; break;
        }
    } else {
        switch(async[1]) {
        case 1: state=13; break;
        case 2: state=14; break;
        case 0:
            switch(async[3]) {
            case 1: state=23; break;
            case 2: state=23; break;
            case 0: if(((struct WifiBsubwayAsync *)async)->timedOut!=0) state=16; break;
            }
            break;
        }
    }
    return state;
}

int WIFI_BSUBWAY_CheckFatalError(int *async) {
    int errorId;
    if(async[3]==3) {
        switch(async[4]) {
        case 200: case 400: errorId=65; break;
        case 401: errorId=66; break;
        case 408: errorId=68; break;
        default: errorId=67; break;
        }
        GFL_NET_ERR_RaiseFatal(errorId);
        return 1;
    }
    return 0;
}


void WIFI_BSUBWAY_SetDownloadResult(u8 *async, u32 state) { ((struct WifiBsubwayAsync *)async)->state = state; }


void WIFI_BSUBWAY_SetHttpError(u8 *async, u32 httpCode) { ((struct WifiBsubwayAsync *)async)->state = 3; ((struct WifiBsubwayAsync *)async)->httpCode = httpCode; }


void WIFI_BSUBWAY_ResetUpload(u8 *async) { ((struct WifiBsubwayAsync *)async)->timedOut = 0; ((struct WifiBsubwayAsync *)async)->ticks = 0; }

void WIFI_BSUBWAY_TickUploadTimeout(u8 *async)
{
    (((struct WifiBsubwayAsync *)async)->ticks)++;
    if (((struct WifiBsubwayAsync *)async)->ticks == 3600) ((struct WifiBsubwayAsync *)async)->timedOut = 1;
}

void WIFI_BSUBWAY_OpenCodeIn(u8 *work,int heapId) {
    void *codeInParam;
    gWifiBsubwayCodeInParam[2]=(u32)WIFI_BSUBWAY_GetTransferState(work+0xb74);
    codeInParam=CODEIN_PARAM_Create(heapId,1,WIFI_BSUBWAY_GetDownloadResult(work+0xb74),3,gWifiBsubwayCodeInParamEx);
    ((struct WifiBsubwayWork *)work)->codeInParam=codeInParam;
    GAMESYSTEM_CallProc(((struct WifiBsubwayParent *)(*(u8 * *)&((struct WifiBsubwayWork *)work)->parent))->proc,(u32)ov129_id,d_021DA62C,codeInParam);
}
