/*
 * file:     nhttp_rap.c
 * unit:     yes
 * function: NHTTP_RAP_Alloc, NHTTP_RAP_Free, NHTTP_RAP_ConnectionCallback, NHTTP_RAP_CreateRequest, NHTTP_RAP_GetConnection, NHTTP_RAP_StartConnection, NHTTP_RAP_DeleteConnection, NHTTP_RAP_PollConnection, NHTTP_RAP_GetRecvBuffer, NHTTP_RAP_Create, NHTTP_RAP_Destroy, NHTTP_RAP_WritePostHeader, NHTTP_RAP_AllocPostData, NHTTP_RAP_AppendPostData, NHTTP_RAP_CreatePostRequest, NHTTP_RAP_FreePostData, NHTTP_RAP_GetResultCode, NHTTP_RAP_RecordList_GetCount, NHTTP_RAP_RecordList_GetValue, NHTTP_RAP_RecordList_GetRecord, NHTTP_RAP_VerifySignature
 * address:  0x021B95A0
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Cut from nhttp_rap.c by tools/splitfile.py.
 *
 * symbols:
 *   DWC_RAPCOMMON_Alloc  0x02156F5C  thumb  ov009
 *   DWC_RAPCOMMON_Free  0x02156FDC  thumb  ov009
 *   sNHTTPRapStrings 0x021CE2D4 data a4
 *   sNHTTPRapRequestTable 0x021CE284 data a4
 *   sNHTTPRapRootCA 0x021CE280 data a4
 *   NHTTP_Startup 0x021BE648 arm ov114
 *   NHTTP_CreateConnection 0x021BF04C arm ov114
 *   NHTTP_SetRootCA 0x021BE9C8 arm ov114
 *   NHTTP_AddHeaderField 0x021BE6BC arm ov114
 *   NHTTP_SetBasicAuthorization 0x021BE8E8 arm ov114
 *   GF_PANIC_Fail 0x02034714 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   STD_TSNPrintf 0x0208D80C arm
 *   NHTTP_StartConnection  0x021BF308  arm  ov114
 *   NHTTP_Cleanup  0x021BE698  arm  ov114
 *   NHTTP_DeleteConnection  0x021BF184  arm  ov114
 *   NHTTP_GetResultCode  0x021BE880  arm  ov114
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   sNHTTPRapCryptoHeapId 0x021CE31C data a2
 *   sNHTTPRapSignatureModulus 0x021CE320 data a4
 *   GFL_NET_STATE_SetError  0x0203C9AC  arm  arm9
 *   GFL_NET_AllocAligned  0x0203D7C8  arm  arm9
 *   GFL_NET_FreeAligned  0x0203D7FC  arm  arm9
 *   NHTTP_GetError  0x021BE6AC  arm
 *   NHTTP_AddPostDataRaw  0x021BE79C  arm
 *   NHTTP_GetHeaderAll  0x021BE838  arm
 *   NHTTP_GetConnectionError  0x021BF488  arm
 *   NHTTP_GetConnectionProgress  0x021BF4B0  arm
 *   CRYPTO_VerifySignature  0x021CAA70  arm
 *   CRYPTO_SetMemAllocator  0x021CAB1C  arm
 *   NHTTP_RAP_EvilCheckCryptoAlloc 0x021B9AA8 thumb ov114
 *   NHTTP_RAP_EvilCheckCryptoFree 0x021B9AF8 thumb ov114
 *   STD_CopyString  0x0208CADC  arm  arm9
 *   GFL_HEAP_Alloc  0x02030734  arm  arm9
 */
#include "../version.h"
#include "nhttp_types.h"
#include "nhttp_rap_types.h"








#include "../arm9/gf_panic.h"

#include "../arm9/mi_memory.h"

#include "../arm9/std_sprintf.h"


#include "../arm9/net_state.h"






#include "../arm9/gfl_heap_wrap.h"


#include "../arm9/net.h"




#include "../arm9/std_string.h"




#include "crypto_sign.h"
#include "crypto_util.h"
#include "d_nhttp.h"
#include "d_nhttp_private.h"
#include "../ov009/dwc_rapcommon.h"

void *NHTTP_RAP_Alloc(unsigned long size, int align);

void NHTTP_RAP_Free(void *ptr_p);

int NHTTP_RAP_ConnectionCallback(NHTTPConnection *connection_p, int type, void *arg_p);

int NHTTP_RAP_CreateRequest(int index, NHTTPRapSession *session_p);

NHTTPConnection *NHTTP_RAP_GetConnection(NHTTPRapSession *session_p);

int NHTTP_RAP_StartConnection(NHTTPRapSession *session_p);

void NHTTP_RAP_DeleteConnection(NHTTPRapSession *session_p);

int NHTTP_RAP_PollConnection(NHTTPRapSession *session_p);

char *NHTTP_RAP_GetRecvBuffer(NHTTPRapSession *session_p);

NHTTPRapSession *NHTTP_RAP_Create(u16 heapId, u32 gameCode, char *source_p);

void NHTTP_RAP_Destroy(NHTTPRapSession *session_p);

void NHTTP_RAP_WritePostHeader(NHTTPRapSession *session_p, int id);

void NHTTP_RAP_AllocPostData(NHTTPRapSession *session_p, int alignment, int size, int id);

void NHTTP_RAP_AppendPostData(NHTTPRapSession *session_p, const void *src_p, int size);

int NHTTP_RAP_CreatePostRequest(NHTTPRapSession *session_p);

void NHTTP_RAP_FreePostData(NHTTPRapSession *session_p);

int NHTTP_RAP_GetResultCode(NHTTPRapSession *session_p);

int NHTTP_RAP_RecordList_GetCount(NHTTPRapRecordList *list_p);

u32 NHTTP_RAP_RecordList_GetValue(NHTTPRapRecordList *list_p, u32 index);

NHTTPRapRecord *NHTTP_RAP_RecordList_GetRecord(NHTTPRapRecordList *list_p, u32 index);

int NHTTP_RAP_VerifySignature(void *data_p, int elemSize, int count, char *sign_p, u16 heapId);

#include "nhttp_rap_evilcheck.h"


extern char sNHTTPRapStrings[],sNHTTPRapRootCA[];

extern NHTTPRapRequestEntry sNHTTPRapRequestTable[];

extern u16 sNHTTPRapCryptoHeapId;

extern unsigned int sNHTTPRapSignatureModulus[];

void *NHTTP_RAP_Alloc(unsigned long size, int align)
{
    return DWC_RAPCOMMON_Alloc(13, size, align);
}

void NHTTP_RAP_Free(void *ptr_p)
{
    DWC_RAPCOMMON_Free(13, ptr_p, 0);
}

int NHTTP_RAP_ConnectionCallback(NHTTPConnection *connection_p, int type, void *arg_p)
{
    switch (type) {
    case 1: break;
    case 2:
    case 3: ((NHTTPBodyBufArg *)arg_p)->offset = 0; break;
    }
    return 0;
}

int NHTTP_RAP_CreateRequest(int index, NHTTPRapSession *session_p)
{
    NHTTPConnection *connection_p;
    if(NHTTP_Startup(NHTTP_RAP_Alloc,NHTTP_RAP_Free,12)!=0) {
        GF_PANIC_Fail(sNHTTPRapStrings,0,sNHTTPRapStrings);
        return 0;
    }
    if(session_p==0) return 0;
    MI_CpuFill8(session_p->url,0,4);
    if(index==4) STD_TSNPrintf(session_p->url,400,sNHTTPRapRequestTable[index].urlFormat,session_p->source_p+69);
    else STD_TSNPrintf(session_p->url,400,sNHTTPRapRequestTable[index].urlFormat,session_p->gameCode,PM_VERSION_ID,2,1,session_p->source_p+69);
    connection_p=NHTTP_CreateConnection(session_p->url,sNHTTPRapRequestTable[index].method,session_p->recvBuf,1024,NHTTP_RAP_ConnectionCallback,session_p);
    if(connection_p==0) GF_PANIC_Fail(sNHTTPRapStrings,0,sNHTTPRapStrings);
    if(connection_p==0) return 0;
    session_p->connection_p=connection_p;
    if(NHTTP_SetRootCA(connection_p,sNHTTPRapRootCA,1)<0) {
        GF_PANIC_Fail(sNHTTPRapStrings,0,sNHTTPRapStrings);
        return 0;
    }
    if(NHTTP_AddHeaderField(connection_p,sNHTTPRapStrings+4,sNHTTPRapStrings+12)!=0) {
        GF_PANIC_Fail(sNHTTPRapStrings,0,sNHTTPRapStrings);
        return 0;
    }
    if(NHTTP_AddHeaderField(connection_p,sNHTTPRapStrings+16,sNHTTPRapStrings+28)!=0) {
        GF_PANIC_Fail(sNHTTPRapStrings,0,sNHTTPRapStrings);
        return 0;
    }
    if(NHTTP_SetBasicAuthorization(connection_p,sNHTTPRapStrings+40,sNHTTPRapStrings+48)!=0) {
        GF_PANIC_Fail(sNHTTPRapStrings,0,sNHTTPRapStrings);
        return 0;
    }
    return 1;
}

/*
 * extent: the following labelled function is NHTTP_RAP_StartConnection.
 */
NHTTPConnection *NHTTP_RAP_GetConnection(NHTTPRapSession *session_p)
{
    if (session_p) return session_p->connection_p;
    return 0;
}

int NHTTP_RAP_StartConnection(NHTTPRapSession *session_p)
{
    int error;

    if (session_p != 0) {
        error = NHTTP_StartConnection(session_p->connection_p);
        if (error != 0) {
            GFL_NET_STATE_SetError(error, 2, error, 0x3f6);
            return error;
        }
        return 0;
    }
    return 1;
}

void NHTTP_RAP_DeleteConnection(NHTTPRapSession *session_p)
{
    if (session_p == 0)
        return;
    if (session_p->connection_p == 0)
        return;
    NHTTP_DeleteConnection(session_p->connection_p);
    session_p->connection_p = 0;
    NHTTP_Cleanup();
}

/*
 * NHTTP_GetConnectionError 0x021BF488 arm ov114
 * NHTTP_GetConnectionProgress 0x021BF4B0 arm ov114
 * NHTTP_GetHeaderAll 0x021BE838 arm ov114
 * NHTTP_RAP_DeleteConnection 0x021B9774 thumb ov114
 * GFL_NET_STATE_SetError 0x0203C9AC arm
 */
int NHTTP_RAP_PollConnection(NHTTPRapSession *session_p)
{
    int received,contentLength,headerAll;
    int result;
    if (session_p == 0) return -1;
    if (session_p->connection_p == 0) return 0;
    result = NHTTP_GetConnectionError(session_p->connection_p);
    if (result == 15) {
        NHTTP_GetConnectionProgress(session_p->connection_p, (unsigned long *)(&received), (unsigned long *)(&contentLength));
    } else {
        int error = NHTTP_GetConnectionError(session_p->connection_p);
        if (error == 0) NHTTP_GetHeaderAll(session_p->connection_p, (char **)(&headerAll));
        else GFL_NET_STATE_SetError(error, 2, error, 0x3f6);
        NHTTP_RAP_DeleteConnection(session_p);
        return result;
    }
    return result;
}

char *NHTTP_RAP_GetRecvBuffer(NHTTPRapSession *session_p) { if(session_p==0) return 0; return session_p->recvBuf; }

NHTTPRapSession *NHTTP_RAP_Create(u16 heapId, u32 gameCode, char *source_p)
{
    NHTTPRapSession *session_p = GFL_HEAP_Alloc(heapId, 0x5a8, 1, (const char *)0x021CE310, 0x1aa);

    *(NHTTPRapSession **)0x021CF960 = session_p;
    session_p->gameCode = gameCode;
    session_p->source_p = source_p;
    return session_p;
}

/*
 * Frees the session's post buffer, then the session itself.
 */
void NHTTP_RAP_Destroy(NHTTPRapSession *session_p)
{
    if (session_p == 0)
        return;
    NHTTP_RAP_FreePostData(session_p);
    GFL_HEAP_Free(session_p);
}

void NHTTP_RAP_WritePostHeader(NHTTPRapSession *session_p, int id)
{
    char c;
    id = (u16)id;
    if (session_p) {
        session_p->postLen = 0;
        while ((c = (session_p->source_p + session_p->postLen)[0x45]) != 0) {
            session_p->postBuf_p[session_p->postLen] = c;
            session_p->postLen++;
        }
        session_p->postBuf_p[session_p->postLen++] = 0;
        session_p->postBuf_p[session_p->postLen++] = id >> 8;
        session_p->postBuf_p[session_p->postLen++] = id;
    }
}

void NHTTP_RAP_AllocPostData(NHTTPRapSession *session_p, int alignment, int size, int id)
{
    void *buf_p;

    if (session_p == 0)
        return;
    buf_p = GFL_NET_AllocAligned(alignment, size + 0x130, (const char *)0x021CE310, 0x1f5);
    session_p->postBuf_p = buf_p;
    MI_CpuFill8(buf_p, 0, size + 0x130);
    NHTTP_RAP_WritePostHeader(session_p, id);
}

/*
 * Appends `size` bytes at the write cursor and advances it.
 */
void NHTTP_RAP_AppendPostData(NHTTPRapSession *session_p, const void *src_p, int size)
{
    if (session_p == 0)
        return;
    MI_CpuCopy8(src_p, session_p->postBuf_p + session_p->postLen, size);
    session_p->postLen += size;
}

int NHTTP_RAP_CreatePostRequest(NHTTPRapSession *session_p)
{
    NHTTPConnection *connection_p;
    if (session_p == 0) return 0;
    if (NHTTP_Startup(NHTTP_RAP_Alloc, NHTTP_RAP_Free, 12) != 0) {
        GF_PANIC_Fail(sNHTTPRapStrings, 0, sNHTTPRapStrings);
        return 0;
    }
    MI_CpuFill8(session_p->url, 0, 4);
    STD_CopyString(session_p->url, sNHTTPRapRequestTable[7].urlFormat);
    connection_p = NHTTP_CreateConnection((char *)sNHTTPRapRequestTable[7].urlFormat, sNHTTPRapRequestTable[7].method, session_p->recvBuf, 0x400, NHTTP_RAP_ConnectionCallback, 0);
    if (connection_p == 0) {
        NHTTP_GetError();
        if (connection_p == 0) GF_PANIC_Fail(sNHTTPRapStrings, 0, sNHTTPRapStrings);
        return 0;
    }
    session_p->connection_p = connection_p;
    if (NHTTP_SetRootCA(connection_p, sNHTTPRapRootCA, 1) < 0) {
        GF_PANIC_Fail(sNHTTPRapStrings, 0, sNHTTPRapStrings);
        return 0;
    }
    NHTTP_AddPostDataRaw(connection_p, session_p->postBuf_p, session_p->postLen);
    return 1;
}

void NHTTP_RAP_FreePostData(NHTTPRapSession *session_p)
{
    if (session_p != 0) {
        if (session_p->postBuf_p != 0)
            GFL_NET_FreeAligned(session_p->postBuf_p);
        session_p->postBuf_p = 0;
        session_p->postLen = 0;
    }
    *(u32 *)0x021CF960 = 0;
}

int NHTTP_RAP_GetResultCode(NHTTPRapSession *session_p)
{
    if (session_p != 0)
        return NHTTP_GetResultCode(session_p->connection_p);
    return 0;
}

int NHTTP_RAP_RecordList_GetCount(NHTTPRapRecordList *list_p) { return list_p->count; }

u32 NHTTP_RAP_RecordList_GetValue(NHTTPRapRecordList *list_p, u32 index)
{
    u32 recordsAddr = (uptr)list_p + 1;

    return (((NHTTPRapRecord *)recordsAddr)[index].a<<24)|(((NHTTPRapRecord *)recordsAddr)[index].b<<16)|(((NHTTPRapRecord *)recordsAddr)[index].c<<8)|((NHTTPRapRecord *)recordsAddr)[index].d;
}

NHTTPRapRecord *NHTTP_RAP_RecordList_GetRecord(NHTTPRapRecordList *list_p, u32 index) { return &list_p->records[index]; }

int NHTTP_RAP_VerifySignature(void *data_p, int elemSize, int count, char *sign_p, u16 heapId)
{
    int result;
    sNHTTPRapCryptoHeapId = heapId;
    CRYPTO_SetMemAllocator(NHTTP_RAP_EvilCheckCryptoAlloc, NHTTP_RAP_EvilCheckCryptoFree, 0);
    result = CRYPTO_VerifySignature(data_p, elemSize*count, sign_p, sNHTTPRapSignatureModulus);
    sNHTTPRapCryptoHeapId = 0xffff;
    return result;
}
