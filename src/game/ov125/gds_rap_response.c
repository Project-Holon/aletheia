/*
 * file:     gds_rap_response.c
 * unit:     yes
 * function: GDS_RAP_CheckUploadEntryReply, GDS_RAP_CheckDownloadEntriesReply, GDS_RAP_GetDownloadEntries, GDS_RAP_CheckUploadVideoReply, GDS_RAP_GetUploadedDataNumber, GDS_RAP_CheckSearchVideosReply, GDS_RAP_GetSearchResults, GDS_RAP_CheckGetVideoReply, GDS_RAP_GetVideoReply, GDS_RAP_CheckMarkVideoReply, GDS_RAP_SaveVideoSeq, GDS_RAP_EncodeVideoBody, GDS_RAP_SaveVideoWithDataNumber, GDS_RAP_SaveVideoSecured, GDS_RAP_StartVideoSave, GDS_RAP_StepVideoSave, GDS_RAP_GetVideoWork
 * address:  0x021D732C
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

#include "../types.h"

#include "../version.h"
#include "gds_rap_types.h"

struct MyStatus;
struct SaveControl;

#include "../arm9/gf_overlay.h"
#include "../arm9/gf_panic.h"
#include "../arm9/mi_memory.h"
#include "../arm9/gfl_heap_wrap.h"
struct MsgBank;
#include "../arm9/msgdata.h"
struct WordSet;
#include "../arm9/gf_font.h"
#include "../arm9/wordset.h"
struct Strbuf;
#include "../arm9/strbuf.h"
#include "../arm9/game_data.h"
#include "../arm9/mystatus.h"
#include "../arm9/save_control.h"
#include "../arm9/gf_standard.h"

#include "../arm9/battle_rec.h"

#include "../ov114/nhttp_rap.h"

/* ARM half of this file and gds_socket.c */
#include "gds_socket.h"
#if LANGUAGE == LANGUAGE_JAPANESE
extern const char str_ja_021D8C40[];
extern const char str_ja_021D8C68[];
extern const char str_ja_021D8C74[];
extern const char str_ja_021D8CA0[];
extern const char str_ja_021D8CB8[];
extern const char str_ja_021D8CBC[];
extern const char str_ja_021D8CC0[];
extern const char str_ja_021D8CE8[];
extern const char str_ja_021D8CFC[];
#endif

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
        GF_PANIC_Fail(PM_LANG_JA(sGdsEmptyString2, str_ja_021D8CE8), PM_SRC_LINE(0, 0x159), PM_LANG_JA(sGdsEmptyString2, str_ja_021D8CFC));
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
