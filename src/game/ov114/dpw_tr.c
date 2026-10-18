/*
 * file:     dpw_tr.c
 * function: DPW_TR_Init, DPW_TR_Main, DPW_TR_End, DPW_TR_IsAsyncEnd, DPW_TR_GetAsyncResult, DPW_TR_UploadAsync, DPW_TR_GetUploadResultAsync, DPW_TR_DownloadAsync, DPW_TR_ReturnAsync, DPW_TR_DeleteAsync, DPW_TR_UploadFinishAsync, DPW_TR_CancelAsync, DPW_TR_DownloadMatchDataAsync, DPW_TR_DownloadMatchDataRawAsync, DPW_TR_TradeAsync, DPW_TR_TradeFinishAsync, DPW_TR_GetServerStateAsync, DPW_TR_SetProfileAsync, DPW_TR_ConvertDwcError
 * address:  0x021C7BA0
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Wi-Fi trade (Global Terminal) server client: a request/response state machine on top of the
 * DWC encryption session.  One request runs at a time; the state selects the request kind.
 *
 * symbols:
 *   gDpwTrWork                  0x021D3D2C  data  a4
 *   DWCi_EncSessionProcess      0x021CA0A0  arm
 *   DWCi_EncSessionShutdown     0x021CA1B4  arm
 *   DWCi_EncSessionGetResponse  0x021CA228  arm
 *   DWC_GetLastErrorEx          0x02059E38  arm
 *   memcpy               0x02092344  arm
 *   gDpwTrServerIndex   0x021D3D28  data  a4
 *   gDpwTrBaseUrl   0x021CF538  data  a4
 *   gDpwTrPathDownload   0x021CF5B8  data  a4
 *   gDpwTrRequestPacket   0x021D3D40  data  a4
 *   DWCi_EncSessionInitialize 0x021C9EE4  arm
 *   DWCi_EncSessionGetAsync 0x021CA470  arm
 *   DWCi_EncSessionShutdown 0x021CA1B4  arm
 *   gDpwTrPathReturn   0x021CF5D4  data  a4
 *   DWCi_EncSessionCancel  0x021CA188  arm  ov114
 *   gDpwTrPathDownloadMatchData   0x021CF634  data  a4
 *   gDpwTrWantedData 0x021D3E6C data a4
 *   gDpwTrPathTrade 0x021CF654 data a4
 *   gDpwTrKeyHeader 0x021D3D38 data a4
 *   gDpwTrPathTradeFinish 0x021CF674 data a4
 *   gDpwTrPathGetServerState 0x021CF69C data a4
 *   gDpwTrPathSetProfile 0x021CF6B8 data a4
 *   OS_GetMacAddress 0x02087C6C arm
 *   DWC_UpdateConnection  0x0205D074  arm
 *   DWC_ClearError        0x02059F18  arm
 *   gDpwTrPathGetUploadResult 0x021CF594 data a4
 *   gDpwTrPathDelete 0x021CF5F4 data a4
 *   gDpwTrPathUploadFinish 0x021CF614 data a4
 *   gDpwTrPathUpload                       0x021CF578  data  a4
 */
#include "../../matched/arm9_sdk/libc/string.h"

typedef unsigned char u8;
typedef unsigned int u32;

#define DPW_TR_STATE_UNINITIALIZED 0
#define DPW_TR_STATE_IDLE 1
#define DPW_TR_STATE_UPLOAD 2
#define DPW_TR_STATE_UPLOAD_CANCELED 3
#define DPW_TR_STATE_GET_UPLOAD_RESULT 4
#define DPW_TR_STATE_GET_UPLOAD_RESULT_CANCELED 5
#define DPW_TR_STATE_DOWNLOAD 6
#define DPW_TR_STATE_DOWNLOAD_CANCELED 7
#define DPW_TR_STATE_RETURN 8
#define DPW_TR_STATE_RETURN_CANCELED 9
#define DPW_TR_STATE_DELETE 10
#define DPW_TR_STATE_DELETE_CANCELED 11
#define DPW_TR_STATE_UPLOAD_FINISH 12
#define DPW_TR_STATE_UPLOAD_FINISH_CANCELED 13
#define DPW_TR_STATE_DOWNLOAD_MATCH_DATA 14
#define DPW_TR_STATE_DOWNLOAD_MATCH_DATA_CANCELED 15
#define DPW_TR_STATE_TRADE 16
#define DPW_TR_STATE_TRADE_CANCELED 17
#define DPW_TR_STATE_TRADE_FINISH 18
#define DPW_TR_STATE_TRADE_FINISH_CANCELED 19
#define DPW_TR_STATE_GET_SERVER_STATE 20
#define DPW_TR_STATE_GET_SERVER_STATE_CANCELED 21
#define DPW_TR_STATE_SET_PROFILE 22
#define DPW_TR_STATE_SET_PROFILE_CANCELED 23
#define DPW_TR_STATE_DONE 24

/* Results of DWCi_EncSessionProcess that end a request. */
#define DWC_ENC_PROCESS_ERROR 1
#define DWC_ENC_PROCESS_DONE 8

/* Two-byte answer header of the server. */
typedef struct DpwTrResponse {
    u8 code;
    u8 detail;
} DpwTrResponse;

/* Search key of the match-data request (six bytes sent as they are). */
typedef struct DpwTrSearchKey {
    u8 speciesLo;
    u8 speciesHi;
    u8 gender;
    u8 levelMin;
    u8 levelMax;
    u8 country;
} DpwTrSearchKey;

/*
 * The client state at gDpwTrWork.  The request packet gDpwTrRequestPacket starts at +0x14 of this
 * struct and gDpwTrWantedData at +0x140, so the request bytes overlay the middle of it.
 */
typedef struct DpwTrWork {
    int state;                          /* 0x000 */
    int result;                         /* 0x004 */
    unsigned int profileId;             /* 0x008 */
    unsigned int friendKeyLo;           /* 0x00c */
    unsigned int friendKeyHi;           /* 0x010 */
    u8 requestHead[6];                  /* 0x014 */
    u8 searchCount;                     /* 0x01a */
    u8 requestBody[0x13c - 0x1b];       /* 0x01b */
    unsigned int uploadFlag;            /* 0x13c */
    unsigned int wantedData[0x20];      /* 0x140 */
    unsigned int wantedLen;             /* 0x1c0 */
    DpwTrResponse response;             /* 0x1c4 */
    u8 reserved1c6[2];
    u8 *resultBuf;                      /* 0x1c8 */
} DpwTrWork;

extern int DWCi_EncSessionProcess(void);
extern void DWCi_EncSessionShutdown(void);
extern const void *DWCi_EncSessionGetResponse(u32 *len);
extern int DWC_GetLastErrorEx(int *code, int *type);
extern void DWCi_EncSessionInitialize(int server, char *initdata);
extern int DWCi_EncSessionGetAsync(void *, unsigned int, void *, unsigned int, unsigned int);
extern void DWCi_EncSessionCancel(void);
extern void OS_GetMacAddress(void *);
extern int DWC_UpdateConnection(void);
extern void DWC_ClearError(void);

int DPW_TR_ConvertDwcError(u32 dwcErrorType);

extern DpwTrWork gDpwTrWork;
extern int gDpwTrServerIndex;
extern unsigned int gDpwTrRequestPacket[];
extern unsigned int gDpwTrBaseUrl[];
extern unsigned int gDpwTrWantedData[], gDpwTrPathUpload[];
extern const unsigned int gDpwTrKeyHeader[];
extern unsigned int gDpwTrPathGetUploadResult[];
extern unsigned int gDpwTrPathDownload[];
extern unsigned int gDpwTrPathReturn[];
extern unsigned int gDpwTrBaseUrl[], gDpwTrPathDelete[];
extern unsigned int gDpwTrBaseUrl[], gDpwTrPathUploadFinish[];
extern unsigned int gDpwTrBaseUrl[], gDpwTrPathDownloadMatchData[];
extern unsigned gDpwTrWantedData[], gDpwTrBaseUrl[], gDpwTrPathTrade[];
extern unsigned gDpwTrBaseUrl[], gDpwTrPathTradeFinish[];
extern unsigned gDpwTrBaseUrl[], gDpwTrPathGetServerState[];
extern unsigned gDpwTrBaseUrl[], gDpwTrPathSetProfile[];

/* Starts a session for the player profile; serverType selects the server (0, 1 or 2). */
void DPW_TR_Init(unsigned int profileId, unsigned int friendKeyLo, unsigned int friendKeyHi, int serverType)
{
    gDpwTrWork.state = DPW_TR_STATE_IDLE;
    gDpwTrWork.result = 0;
    gDpwTrWork.profileId = profileId;
    gDpwTrWork.friendKeyLo = friendKeyLo;
    gDpwTrWork.friendKeyHi = friendKeyHi;
    switch (serverType) {
    case 0: gDpwTrServerIndex = 0; break;
    case 1: gDpwTrServerIndex = 1; break;
    case 2: gDpwTrServerIndex = 2; break;
    default: gDpwTrServerIndex = 1; break;
    }
}

/*
 * Session poll, called every frame: runs the encryption session of the pending
 * request.  On completion the state becomes DONE and the result is mapped from
 * the response header; a canceled request ends with result -12.
 * Matching note: the header copy must be memcpy(&work.response, GetResponse(&len), 2) on the
 * global itself (no pointer local), otherwise the register colours differ.
 */
void DPW_TR_Main(void)
{
    u32 len;
    int code;
    int type;
    const u8 *resp;
    switch (gDpwTrWork.state) {
    case DPW_TR_STATE_UPLOAD:
        switch (DWCi_EncSessionProcess()) {
        case DWC_ENC_PROCESS_ERROR:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case DWC_ENC_PROCESS_DONE:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            memcpy(&gDpwTrWork.response, DWCi_EncSessionGetResponse(&len), 2);
            switch (gDpwTrWork.response.code) {
            case 1: gDpwTrWork.result = 0; break;
            case 2: gDpwTrWork.result = -5; break;
            case 3: gDpwTrWork.result = -4; break;
            case 7: gDpwTrWork.result = -1; break;
            case 12: gDpwTrWork.result = -6; break;
            case 13: gDpwTrWork.result = -7; break;
            case 8: gDpwTrWork.result = -8; break;
            case 9: gDpwTrWork.result = -9; break;
            case 10: gDpwTrWork.result = -10; break;
            case 11: gDpwTrWork.result = -11; break;
            case 14: gDpwTrWork.result = -2; break;
            default: gDpwTrWork.result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case DPW_TR_STATE_GET_UPLOAD_RESULT:
        switch (DWCi_EncSessionProcess()) {
        case DWC_ENC_PROCESS_ERROR:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case DWC_ENC_PROCESS_DONE:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            memcpy(&gDpwTrWork.response, DWCi_EncSessionGetResponse(&len), 2);
            switch (gDpwTrWork.response.code) {
            case 1: gDpwTrWork.result = 0; break;
            case 2: gDpwTrWork.result = -5; break;
            case 3: gDpwTrWork.result = -4; break;
            case 5: gDpwTrWork.result = -3; break;
            case 14: gDpwTrWork.result = -2; break;
            default: gDpwTrWork.result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case DPW_TR_STATE_DOWNLOAD:
        switch (DWCi_EncSessionProcess()) {
        case DWC_ENC_PROCESS_ERROR:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case DWC_ENC_PROCESS_DONE:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            resp = (const u8 *)DWCi_EncSessionGetResponse(&len);
            memcpy(gDpwTrWork.resultBuf, resp, 0x128);
            if (len == 0x128) {
                gDpwTrWork.result = 0;
            } else {
                switch (gDpwTrWork.resultBuf[0]) {
                case 5: gDpwTrWork.result = -3; break;
                case 3: gDpwTrWork.result = -4; break;
                case 14: gDpwTrWork.result = -2; break;
                default: gDpwTrWork.result = -13; break;
                }
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case DPW_TR_STATE_RETURN:
        switch (DWCi_EncSessionProcess()) {
        case DWC_ENC_PROCESS_ERROR:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case DWC_ENC_PROCESS_DONE:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            resp = (const u8 *)DWCi_EncSessionGetResponse(&len);
            memcpy(gDpwTrWork.resultBuf, resp, 0x128);
            if (len == 0x128) {
                gDpwTrWork.result = 1;
            } else {
                switch (gDpwTrWork.resultBuf[0]) {
                case 5: gDpwTrWork.result = -3; break;
                case 3: gDpwTrWork.result = -4; break;
                case 4: gDpwTrWork.result = 0; break;
                case 14: gDpwTrWork.result = -2; break;
                default: gDpwTrWork.result = -13; break;
                }
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case DPW_TR_STATE_DELETE:
        switch (DWCi_EncSessionProcess()) {
        case DWC_ENC_PROCESS_ERROR:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case DWC_ENC_PROCESS_DONE:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            memcpy(&gDpwTrWork.response, DWCi_EncSessionGetResponse(&len), 2);
            switch (gDpwTrWork.response.code) {
            case 1: gDpwTrWork.result = 0; break;
            case 5: gDpwTrWork.result = -3; break;
            case 3: gDpwTrWork.result = -4; break;
            case 14: gDpwTrWork.result = -2; break;
            default: gDpwTrWork.result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case DPW_TR_STATE_UPLOAD_FINISH:
        switch (DWCi_EncSessionProcess()) {
        case DWC_ENC_PROCESS_ERROR:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case DWC_ENC_PROCESS_DONE:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            memcpy(&gDpwTrWork.response, DWCi_EncSessionGetResponse(&len), 2);
            switch (gDpwTrWork.response.code) {
            case 1: gDpwTrWork.result = 0; break;
            case 5: gDpwTrWork.result = -3; break;
            case 2: gDpwTrWork.result = -5; break;
            case 3: gDpwTrWork.result = -4; break;
            case 14: gDpwTrWork.result = -2; break;
            default: gDpwTrWork.result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case DPW_TR_STATE_DOWNLOAD_MATCH_DATA:
        switch (DWCi_EncSessionProcess()) {
        case DWC_ENC_PROCESS_ERROR:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case DWC_ENC_PROCESS_DONE:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            resp = (const u8 *)DWCi_EncSessionGetResponse(&len);
            *(DpwTrResponse *)gDpwTrWork.resultBuf = *(DpwTrResponse *)resp;
            switch (gDpwTrWork.resultBuf[0]) {
            case 1:
                if (len - 2 >= 0x128) {
                    gDpwTrWork.result = (len - 2) / 0x128;
                    memcpy(gDpwTrWork.resultBuf, resp + 2, len - 2);
                } else if (len == 2) {
                    gDpwTrWork.result = 0;
                }
                break;
            case 14: gDpwTrWork.result = -2; break;
            default: gDpwTrWork.result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case DPW_TR_STATE_TRADE:
        switch (DWCi_EncSessionProcess()) {
        case DWC_ENC_PROCESS_ERROR:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case DWC_ENC_PROCESS_DONE:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            resp = (const u8 *)DWCi_EncSessionGetResponse(&len);
            memcpy(gDpwTrWork.resultBuf, resp, 0x128);
            if (len == 0x128) {
                gDpwTrWork.result = 0;
            } else {
                switch (gDpwTrWork.resultBuf[0]) {
                case 2: gDpwTrWork.result = -5; break;
                case 12: gDpwTrWork.result = -6; break;
                case 13: gDpwTrWork.result = -7; break;
                case 8: gDpwTrWork.result = -8; break;
                case 9: gDpwTrWork.result = -9; break;
                case 10: gDpwTrWork.result = -10; break;
                case 11: gDpwTrWork.result = -11; break;
                case 14: gDpwTrWork.result = -2; break;
                default: gDpwTrWork.result = -13; break;
                }
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case DPW_TR_STATE_TRADE_FINISH:
        switch (DWCi_EncSessionProcess()) {
        case DWC_ENC_PROCESS_ERROR:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case DWC_ENC_PROCESS_DONE:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            memcpy(&gDpwTrWork.response, DWCi_EncSessionGetResponse(&len), 2);
            switch (gDpwTrWork.response.code) {
            case 1: gDpwTrWork.result = 0; break;
            case 2: gDpwTrWork.result = -5; break;
            case 14: gDpwTrWork.result = -2; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case DPW_TR_STATE_GET_SERVER_STATE:
        switch (DWCi_EncSessionProcess()) {
        case DWC_ENC_PROCESS_ERROR:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case DWC_ENC_PROCESS_DONE:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            memcpy(&gDpwTrWork.response, DWCi_EncSessionGetResponse(&len), 2);
            switch (gDpwTrWork.response.code) {
            case 1: gDpwTrWork.result = 0; break;
            case 6: gDpwTrWork.result = 1; break;
            case 7: gDpwTrWork.result = 2; break;
            case 14: gDpwTrWork.result = -2; break;
            default: gDpwTrWork.result = -13; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case DPW_TR_STATE_SET_PROFILE:
        switch (DWCi_EncSessionProcess()) {
        case DWC_ENC_PROCESS_ERROR:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            DWC_GetLastErrorEx(&code, &type);
            gDpwTrWork.result = DPW_TR_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case DWC_ENC_PROCESS_DONE:
            gDpwTrWork.state = DPW_TR_STATE_DONE;
            resp = (const u8 *)DWCi_EncSessionGetResponse(&len);
            *(DpwTrResponse *)gDpwTrWork.resultBuf = *(DpwTrResponse *)resp;
            if (len == 8) {
                gDpwTrWork.result = 0;
            } else {
                switch (gDpwTrWork.resultBuf[0]) {
                case 1: gDpwTrWork.result = 0; break;
                case 6: gDpwTrWork.result = 1; break;
                case 7: gDpwTrWork.result = 2; break;
                case 14: gDpwTrWork.result = -2; break;
                default: gDpwTrWork.result = -13; break;
                }
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case DPW_TR_STATE_UPLOAD_CANCELED:
    case DPW_TR_STATE_GET_UPLOAD_RESULT_CANCELED:
    case DPW_TR_STATE_DOWNLOAD_CANCELED:
    case DPW_TR_STATE_RETURN_CANCELED:
    case DPW_TR_STATE_DELETE_CANCELED:
    case DPW_TR_STATE_UPLOAD_FINISH_CANCELED:
    case DPW_TR_STATE_DOWNLOAD_MATCH_DATA_CANCELED:
    case DPW_TR_STATE_TRADE_CANCELED:
    case DPW_TR_STATE_TRADE_FINISH_CANCELED:
    case DPW_TR_STATE_GET_SERVER_STATE_CANCELED:
    case DPW_TR_STATE_SET_PROFILE_CANCELED:
        gDpwTrWork.state = DPW_TR_STATE_DONE;
        gDpwTrWork.result = -12;
        DWCi_EncSessionShutdown();
        return;
    case DPW_TR_STATE_UNINITIALIZED:
    case DPW_TR_STATE_IDLE:
    case DPW_TR_STATE_DONE:
        break;
    }
}

/* Resets the session to the uninitialized state. */
void DPW_TR_End(void)
{
    gDpwTrWork.state = DPW_TR_STATE_UNINITIALIZED;
}

/* Returns 1 when no request is running (idle or done); a finished request returns to idle. */
int DPW_TR_IsAsyncEnd(void)
{
    switch (gDpwTrWork.state) {
    case DPW_TR_STATE_IDLE:
        return 1;
    case DPW_TR_STATE_DONE:
        gDpwTrWork.state = DPW_TR_STATE_IDLE;
        return 1;
    }
    return 0;
}

/* Result of the last finished request. */
int DPW_TR_GetAsyncResult(void)
{
    return gDpwTrWork.result;
}

/* Request: upload a trade (0x128 bytes) with its wanted-Pokemon data. */
void DPW_TR_UploadAsync(const void *tradeData, const void *wantedData, int wantedLen)
{
    memcpy(gDpwTrRequestPacket, tradeData, 0x128);
    gDpwTrWork.uploadFlag = 0;
    memcpy(gDpwTrWantedData, wantedData, wantedLen);
    gDpwTrWork.wantedLen = wantedLen;
    DWCi_EncSessionInitialize(gDpwTrServerIndex, (char *)gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathUpload, gDpwTrWork.profileId, gDpwTrRequestPacket, 0x1b0, 0) == 0) {
        gDpwTrWork.state = DPW_TR_STATE_UPLOAD;
        return;
    }
    gDpwTrWork.state = DPW_TR_STATE_DONE;
    gDpwTrWork.result = -13;
    DWCi_EncSessionShutdown();
}

/* Request: query the upload result. */
void DPW_TR_GetUploadResultAsync(void)
{
    memcpy(gDpwTrRequestPacket, gDpwTrKeyHeader, 8);
    DWCi_EncSessionInitialize(gDpwTrServerIndex, (char *)gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathGetUploadResult, gDpwTrWork.profileId, gDpwTrRequestPacket, 8, 0) == 0) {
        gDpwTrWork.state = DPW_TR_STATE_GET_UPLOAD_RESULT;
        return;
    }
    gDpwTrWork.state = DPW_TR_STATE_DONE;
    gDpwTrWork.result = -13;
    DWCi_EncSessionShutdown();
}

/* Request: download; the response (0x128 bytes) is copied to resultBuf. */
void DPW_TR_DownloadAsync(u8 *resultBuf)
{
    gDpwTrWork.resultBuf = resultBuf;
    DWCi_EncSessionInitialize(gDpwTrServerIndex, (char *)gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathDownload, gDpwTrWork.profileId, gDpwTrRequestPacket, 0x1b0, 0) == 0) {
        gDpwTrWork.state = DPW_TR_STATE_DOWNLOAD;
        return;
    }
    gDpwTrWork.state = DPW_TR_STATE_DONE;
    gDpwTrWork.result = -0x0d;
    DWCi_EncSessionShutdown();
}

/* Request: return; the response (0x128 bytes) is copied to resultBuf. */
void DPW_TR_ReturnAsync(u8 *resultBuf)
{
    gDpwTrWork.resultBuf = resultBuf;
    DWCi_EncSessionInitialize(gDpwTrServerIndex, (char *)gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathReturn, gDpwTrWork.profileId, gDpwTrRequestPacket, 0x1b0, 0) == 0) {
        gDpwTrWork.state = DPW_TR_STATE_RETURN;
        return;
    }
    gDpwTrWork.state = DPW_TR_STATE_DONE;
    gDpwTrWork.result = -0x0d;
    DWCi_EncSessionShutdown();
}

/* Request: delete the uploaded Pokemon. */
void DPW_TR_DeleteAsync(void)
{
    DWCi_EncSessionInitialize(gDpwTrServerIndex, (char *)gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathDelete, gDpwTrWork.profileId, gDpwTrRequestPacket, 0x1b0, 0) == 0) {
        gDpwTrWork.state = DPW_TR_STATE_DELETE;
        return;
    }
    gDpwTrWork.state = DPW_TR_STATE_DONE;
    gDpwTrWork.result = -13;
    DWCi_EncSessionShutdown();
}

/* Request: finish the upload. */
void DPW_TR_UploadFinishAsync(void)
{
    DWCi_EncSessionInitialize(gDpwTrServerIndex, (char *)gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathUploadFinish, gDpwTrWork.profileId, gDpwTrRequestPacket, 0, 0) == 0) {
        gDpwTrWork.state = DPW_TR_STATE_UPLOAD_FINISH;
        return;
    }
    gDpwTrWork.state = DPW_TR_STATE_DONE;
    gDpwTrWork.result = -13;
    DWCi_EncSessionShutdown();
}

/* Cancels the running request: the session is canceled and the state moves to its CANCELED value. */
void DPW_TR_CancelAsync(void)
{
    switch (gDpwTrWork.state) {
    case DPW_TR_STATE_UPLOAD:
        DWCi_EncSessionCancel();
        gDpwTrWork.state = DPW_TR_STATE_UPLOAD_CANCELED;
        break;
    case DPW_TR_STATE_GET_UPLOAD_RESULT:
        DWCi_EncSessionCancel();
        gDpwTrWork.state = DPW_TR_STATE_GET_UPLOAD_RESULT_CANCELED;
        break;
    case DPW_TR_STATE_DOWNLOAD:
        DWCi_EncSessionCancel();
        gDpwTrWork.state = DPW_TR_STATE_DOWNLOAD_CANCELED;
        break;
    case DPW_TR_STATE_RETURN:
        DWCi_EncSessionCancel();
        gDpwTrWork.state = DPW_TR_STATE_RETURN_CANCELED;
        break;
    case DPW_TR_STATE_DELETE:
        DWCi_EncSessionCancel();
        gDpwTrWork.state = DPW_TR_STATE_DELETE_CANCELED;
        break;
    case DPW_TR_STATE_UPLOAD_FINISH:
        DWCi_EncSessionCancel();
        gDpwTrWork.state = DPW_TR_STATE_UPLOAD_FINISH_CANCELED;
        break;
    case DPW_TR_STATE_DOWNLOAD_MATCH_DATA:
        DWCi_EncSessionCancel();
        gDpwTrWork.state = DPW_TR_STATE_DOWNLOAD_MATCH_DATA_CANCELED;
        break;
    case DPW_TR_STATE_TRADE:
        DWCi_EncSessionCancel();
        gDpwTrWork.state = DPW_TR_STATE_TRADE_CANCELED;
        break;
    case DPW_TR_STATE_TRADE_FINISH:
        DWCi_EncSessionCancel();
        gDpwTrWork.state = DPW_TR_STATE_TRADE_FINISH_CANCELED;
        break;
    case DPW_TR_STATE_GET_SERVER_STATE:
        DWCi_EncSessionCancel();
        gDpwTrWork.state = DPW_TR_STATE_GET_SERVER_STATE_CANCELED;
        break;
    case DPW_TR_STATE_SET_PROFILE:
        DWCi_EncSessionCancel();
        gDpwTrWork.state = DPW_TR_STATE_SET_PROFILE_CANCELED;
        break;
    }
}

/*
 * Matching note: opt_propagation off with a named destination pointer assigned first and a const
 * source pointer gives the original register colours and load order.
 */
#pragma opt_propagation off

/* Request: download match data for a search key. */
void DPW_TR_DownloadMatchDataAsync(const DpwTrSearchKey *searchKey, int searchCount, u8 *resultBuf)
{
    DpwTrSearchKey *dst;
    u8 speciesLo, speciesHi, gender, levelMin, levelMax, country;
    dst = ((DpwTrSearchKey *)gDpwTrRequestPacket);
    gDpwTrWork.resultBuf = resultBuf;
    speciesLo = searchKey->speciesLo; speciesHi = searchKey->speciesHi; gender = searchKey->gender;
    levelMin = searchKey->levelMin; levelMax = searchKey->levelMax; country = searchKey->country;
    dst->country = country;
    dst->speciesLo = speciesLo;
    dst->speciesHi = speciesHi;
    dst->gender = gender;
    dst->levelMin = levelMin;
    dst->levelMax = levelMax;
    gDpwTrWork.searchCount = searchCount;
    DWCi_EncSessionInitialize(gDpwTrServerIndex, (char *)gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathDownloadMatchData, gDpwTrWork.profileId, ((DpwTrSearchKey *)gDpwTrRequestPacket), 7, 0) == 0) {
        gDpwTrWork.state = DPW_TR_STATE_DOWNLOAD_MATCH_DATA;
        return;
    }
    gDpwTrWork.state = DPW_TR_STATE_DONE;
    gDpwTrWork.result = -13;
    DWCi_EncSessionShutdown();
}

#pragma opt_propagation reset

/* Request: download match data for an 8-byte key. */
void DPW_TR_DownloadMatchDataRawAsync(const void *searchData, u8 *resultBuf)
{
    gDpwTrWork.resultBuf = resultBuf;
    memcpy(gDpwTrRequestPacket, searchData, 8);
    DWCi_EncSessionInitialize(gDpwTrServerIndex, (char *)gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathDownloadMatchData, gDpwTrWork.profileId, gDpwTrRequestPacket, 8, 0) == 0) {
        gDpwTrWork.state = DPW_TR_STATE_DOWNLOAD_MATCH_DATA;
        return;
    }
    gDpwTrWork.state = DPW_TR_STATE_DONE;
    gDpwTrWork.result = -13;
    DWCi_EncSessionShutdown();
}

/* Request: trade; sends the trade data and wanted data. */
void DPW_TR_TradeAsync(unsigned uploadFlag, const void *tradeData, u8 *resultBuf, const void *wantedData, unsigned wantedLen)
{
    gDpwTrWork.resultBuf = resultBuf;
    memcpy(gDpwTrRequestPacket, tradeData, 0x128);
    gDpwTrWork.uploadFlag = uploadFlag;
    memcpy(gDpwTrWantedData, wantedData, wantedLen);
    gDpwTrWork.wantedLen = wantedLen;
    DWCi_EncSessionInitialize(gDpwTrServerIndex, (char *)gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathTrade, gDpwTrWork.profileId, gDpwTrRequestPacket, 0x1b0, 0) == 0) {
        gDpwTrWork.state = DPW_TR_STATE_TRADE;
        return;
    }
    gDpwTrWork.state = DPW_TR_STATE_DONE;
    gDpwTrWork.result = -13;
    DWCi_EncSessionShutdown();
}

/* Request: finish the trade. */
void DPW_TR_TradeFinishAsync(void)
{
    memcpy(gDpwTrRequestPacket, gDpwTrKeyHeader, 8);
    DWCi_EncSessionInitialize(gDpwTrServerIndex, (char *)gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathTradeFinish, gDpwTrWork.profileId, gDpwTrRequestPacket, 8, 0) == 0) {
        gDpwTrWork.state = DPW_TR_STATE_TRADE_FINISH;
        return;
    }
    gDpwTrWork.state = DPW_TR_STATE_DONE;
    gDpwTrWork.result = -13;
    DWCi_EncSessionShutdown();
}

/* Request: query the server state. */
void DPW_TR_GetServerStateAsync(void)
{
    DWCi_EncSessionInitialize(gDpwTrServerIndex, (char *)gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathGetServerState, gDpwTrWork.profileId, gDpwTrRequestPacket, 0, 0) == 0) {
        gDpwTrWork.state = DPW_TR_STATE_GET_SERVER_STATE;
        return;
    }
    gDpwTrWork.state = DPW_TR_STATE_DONE;
    gDpwTrWork.result = -13;
    DWCi_EncSessionShutdown();
}

/* Request: set the player profile (100 bytes). */
void DPW_TR_SetProfileAsync(unsigned char *profile, u8 *resultBuf)
{
    OS_GetMacAddress(profile + 0x1c);
    memcpy(gDpwTrRequestPacket, profile, 100);
    gDpwTrWork.resultBuf = resultBuf;
    DWCi_EncSessionInitialize(gDpwTrServerIndex, (char *)gDpwTrBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwTrPathSetProfile, gDpwTrWork.profileId, gDpwTrRequestPacket, 100, 0) == 0) {
        gDpwTrWork.state = DPW_TR_STATE_SET_PROFILE;
        return;
    }
    gDpwTrWork.state = DPW_TR_STATE_DONE;
    gDpwTrWork.result = -13;
    DWCi_EncSessionShutdown();
}

/* Maps a DWC error type to a result code; clears the DWC error unless the result is -13.
 * Case order matters: the case arms are laid out in source order, so case 5 comes before case 4. */
int DPW_TR_ConvertDwcError(u32 dwcErrorType)
{
    int r;

    switch (dwcErrorType) {
    case 0:
    case 1:
    case 2:
        r = -15;
        break;
    case 3:
        r = -14;
        break;
    case 5:
        r = -14;
        break;
    case 4:
        r = -15;
        break;
    case 6:
        r = -14;
        break;
    case 7:
        r = -13;
        break;
    default:
        r = -14;
        break;
    }

    if (r != -13) {
        if (DWC_UpdateConnection() != 0)
            r = -14;
        DWC_ClearError();
    }

    return r;
}
