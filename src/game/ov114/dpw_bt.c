/*
 * file:     dpw_bt.c
 * function: DPW_BT_Init, DPW_BT_Main, DPW_BT_End, DPW_BT_IsAsyncEnd, DPW_BT_GetAsyncResult, DPW_BT_GetRoomNumAsync, DPW_BT_DownloadPlayerAsync, DPW_BT_UploadPlayerAsync, DPW_BT_CancelAsync, DPW_BT_GetServerStateAsync, DPW_BT_SetProfileAsync, DPW_BT_ConvertDwcError
 * address:  0x021C8F2C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Wi-Fi battle subway server client: a request/response state machine on top of the DWC
 * encryption session, the same design as dpw_tr.c.  One request runs at a time.
 *
 * symbols:
 *   DWCi_EncSessionProcess      0x021CA0A0  arm
 *   DWCi_EncSessionShutdown     0x021CA1B4  arm
 *   DWCi_EncSessionGetResponse  0x021CA228  arm
 *   DWC_GetLastErrorEx          0x02059E38  arm
 *   memcpy               0x02092344  arm
 *   DWCi_EncSessionInitialize 0x021C9EE4  arm
 *   DWCi_EncSessionGetAsync 0x021CA470  arm
 *   DWCi_EncSessionShutdown 0x021CA1B4  arm
 *   DWCi_EncSessionCancel  0x021CA188  arm  ov114
 *   OS_GetMacAddress 0x02087C6C arm
 *   DWC_UpdateConnection  0x0205D074  arm
 *   DWC_ClearError        0x02059F18  arm
 *   gDpwBtWork 0x021D4084 data a4
 *   gDpwBtServerIndex 0x021D3EFC data a4
 *   gDpwBtBaseUrl 0x021CF6D4 data a4
 *   gDpwBtPathGetRoomNum 0x021CF714 data a4
 *   gDpwBtRequestPacket 0x021D4098 data a4
 *   gDpwBtPathDownloadPlayer 0x021CF734 data a4
 *   gDpwBtUploadStaging 0x021D3F00 data a4
 *   gDpwBtUploadPairKey 0x021D3FF8 data a4
 *   gDpwBtUploadLeaderData 0x021D4000 data a4
 *   gDpwBtPairKeyInit 0x021D4090 data a4
 *   gDpwBtPathUploadPlayer 0x021CF754 data a4
 *   gDpwBtPathGetServerState 0x021CF770 data a4
 *   gDpwBtPathSetProfile 0x021CF78C data a4
 */
#include "dwc_encsession_2.h"
#include "../../matched/arm9_sdk/libc/string.h"

#include "../types.h"

#define DPW_BT_STATE_UNINITIALIZED 0
#define DPW_BT_STATE_IDLE 1
#define DPW_BT_STATE_GET_ROOM_NUM 2
#define DPW_BT_STATE_GET_ROOM_NUM_CANCELED 3
#define DPW_BT_STATE_DOWNLOAD_PLAYER 4
#define DPW_BT_STATE_DOWNLOAD_PLAYER_CANCELED 5
#define DPW_BT_STATE_UPLOAD_PLAYER 6
#define DPW_BT_STATE_UPLOAD_PLAYER_CANCELED 7
#define DPW_BT_STATE_GET_SERVER_STATE 8
#define DPW_BT_STATE_GET_SERVER_STATE_CANCELED 9
#define DPW_BT_STATE_SET_PROFILE 10
#define DPW_BT_STATE_SET_PROFILE_CANCELED 11
#define DPW_BT_STATE_DONE 12

/* Results of DWCi_EncSessionProcess that end a request. */
#define DWC_ENC_PROCESS_ERROR 1
#define DWC_ENC_PROCESS_DONE 8

/* Two-byte answer header of the server. */
typedef struct DpwBtResponse {
    u8 code;
    u8 detail;
} DpwBtResponse;

typedef struct DpwBtResponse8 {
    DpwBtResponse h[4];
} DpwBtResponse8;

/* The client state at gDpwBtWork. */
typedef struct DpwBtWork {
    int state;                          /* 0x000 */
    int result;                         /* 0x004 */
    unsigned int profileId;             /* 0x008 */
    unsigned int friendKeyLo;           /* 0x00c */
    unsigned int friendKeyHi;           /* 0x010 */
    u8 rank;                            /* 0x014 */
    u8 roomNo;                          /* 0x015 */
    u8 reserved16[0x198 - 0x16];
    DpwBtResponse response;             /* 0x198 */
    u8 reserved19a[2];
    u8 *resultBuf;                      /* 0x19c */
} DpwBtWork;

/* Upload request packet (0x184 bytes) at gDpwBtRequestPacket; gDpwBtUploadStaging is its staging copy. */
typedef struct DpwBtPacket {
    u32 playerData[60];                 /* 0x000 */
    u8 rank;                            /* 0x0f0 */
    u8 roomNo;                          /* 0x0f1 */
    u8 section;                         /* 0x0f2 */
    u8 reserved0f3[5];
    u32 pairKey[2];                     /* 0x0f8 */
    u32 leaderData[32];                 /* 0x100 */
    u32 rankScore;                      /* 0x180 */
} DpwBtPacket;

#include "../arm9/dwc_error.h"
#include "../arm9/os_ownerinfo.h"
#include "../arm9/dwc_connectinet.h"

int DPW_BT_ConvertDwcError(unsigned dwcErrorType);

extern DpwBtWork gDpwBtWork;
extern int gDpwBtServerIndex;
extern DpwBtPacket gDpwBtRequestPacket;
extern DpwBtPacket gDpwBtUploadStaging;
extern char gDpwBtBaseUrl[], gDpwBtPathGetRoomNum[];
extern char gDpwBtBaseUrl[], gDpwBtPathDownloadPlayer[];
extern u32 gDpwBtUploadPairKey[], gDpwBtUploadLeaderData[];
extern u32 gDpwBtPairKeyInit[];
extern char gDpwBtBaseUrl[], gDpwBtPathUploadPlayer[];
extern char gDpwBtBaseUrl[], gDpwBtPathGetServerState[];
extern char gDpwBtBaseUrl[], gDpwBtPathSetProfile[];

/* Starts a session for the player profile; serverType selects the server (0, 1 or 2). */
void DPW_BT_Init(unsigned profileId, unsigned friendKeyLo, unsigned friendKeyHi, unsigned serverType)
{
    gDpwBtWork.state = DPW_BT_STATE_IDLE;
    gDpwBtWork.result = 0;
    gDpwBtWork.profileId = profileId;
    gDpwBtWork.friendKeyLo = friendKeyLo;
    gDpwBtWork.friendKeyHi = friendKeyHi;
    switch (serverType) {
    case 0: gDpwBtServerIndex = 0; break;
    case 1: gDpwBtServerIndex = 1; break;
    case 2: gDpwBtServerIndex = 2; break;
    default: gDpwBtServerIndex = 1; break;
    }
}

/*
 * Session poll, called every frame: runs the encryption session of the pending request.  On
 * completion the state becomes DONE and the result is mapped from the response; a canceled
 * request ends with result -4.
 */
void DPW_BT_Main(void)
{
    u32 len;
    int code;
    int type;
    const u8 *resp;
    switch (gDpwBtWork.state) {
    case DPW_BT_STATE_GET_ROOM_NUM:
        switch (DWCi_EncSessionProcess()) {
        case DWC_ENC_PROCESS_ERROR:
            gDpwBtWork.state = DPW_BT_STATE_DONE;
            DWC_GetLastErrorEx(&code, &type);
            gDpwBtWork.result = DPW_BT_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case DWC_ENC_PROCESS_DONE:
            gDpwBtWork.state = DPW_BT_STATE_DONE;
            memcpy(&gDpwBtWork.response, (void *)DWCi_EncSessionGetResponse(&len), 2);
            if (len != 0) {
                gDpwBtWork.result = gDpwBtWork.response.code;
            } else {
                gDpwBtWork.result = -2;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case DPW_BT_STATE_DOWNLOAD_PLAYER:
        switch (DWCi_EncSessionProcess()) {
        case DWC_ENC_PROCESS_ERROR:
            gDpwBtWork.state = DPW_BT_STATE_DONE;
            DWC_GetLastErrorEx(&code, &type);
            gDpwBtWork.result = DPW_BT_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case DWC_ENC_PROCESS_DONE:
            gDpwBtWork.state = DPW_BT_STATE_DONE;
            resp = (const u8 *)DWCi_EncSessionGetResponse(&len);
            memcpy(gDpwBtWork.resultBuf, resp, 0xa8c);
            if (len == 0xa8c) {
                gDpwBtWork.result = 0;
            } else {
                switch (gDpwBtWork.resultBuf[0]) {
                case 2: gDpwBtWork.result = -3; break;
                case 5: gDpwBtWork.result = -2; break;
                default: gDpwBtWork.result = -5; break;
                }
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case DPW_BT_STATE_UPLOAD_PLAYER:
        switch (DWCi_EncSessionProcess()) {
        case DWC_ENC_PROCESS_ERROR:
            gDpwBtWork.state = DPW_BT_STATE_DONE;
            DWC_GetLastErrorEx(&code, &type);
            gDpwBtWork.result = DPW_BT_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case DWC_ENC_PROCESS_DONE:
            gDpwBtWork.state = DPW_BT_STATE_DONE;
            memcpy(&gDpwBtWork.response, (void *)DWCi_EncSessionGetResponse(&len), 2);
            switch (gDpwBtWork.response.code) {
            case 1: gDpwBtWork.result = 0; break;
            case 2: gDpwBtWork.result = -3; break;
            case 4: gDpwBtWork.result = -1; break;
            case 5: gDpwBtWork.result = -2; break;
            default: gDpwBtWork.result = -5; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case DPW_BT_STATE_GET_SERVER_STATE:
        switch (DWCi_EncSessionProcess()) {
        case DWC_ENC_PROCESS_ERROR:
            gDpwBtWork.state = DPW_BT_STATE_DONE;
            DWC_GetLastErrorEx(&code, &type);
            gDpwBtWork.result = DPW_BT_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case DWC_ENC_PROCESS_DONE:
            gDpwBtWork.state = DPW_BT_STATE_DONE;
            memcpy(&gDpwBtWork.response, (void *)DWCi_EncSessionGetResponse(&len), 2);
            switch (gDpwBtWork.response.code) {
            case 1: gDpwBtWork.result = 0; break;
            case 3: gDpwBtWork.result = 1; break;
            case 4: gDpwBtWork.result = 2; break;
            case 5: gDpwBtWork.result = -2; break;
            default: gDpwBtWork.result = -5; break;
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case DPW_BT_STATE_SET_PROFILE:
        switch (DWCi_EncSessionProcess()) {
        case DWC_ENC_PROCESS_ERROR:
            gDpwBtWork.state = DPW_BT_STATE_DONE;
            DWC_GetLastErrorEx(&code, &type);
            gDpwBtWork.result = DPW_BT_ConvertDwcError(type);
            DWCi_EncSessionShutdown();
            return;
        case DWC_ENC_PROCESS_DONE:
            gDpwBtWork.state = DPW_BT_STATE_DONE;
            resp = (const u8 *)DWCi_EncSessionGetResponse(&len);
            *(DpwBtResponse8 *)gDpwBtWork.resultBuf=*(DpwBtResponse8 *)resp;
            if (len == 8) {
                gDpwBtWork.result = 0;
            } else {
                switch (gDpwBtWork.resultBuf[0]) {
                case 1: gDpwBtWork.result = 0; break;
                case 3: gDpwBtWork.result = 1; break;
                case 4: gDpwBtWork.result = 2; break;
                case 5: gDpwBtWork.result = -2; break;
                default: gDpwBtWork.result = -5; break;
                }
            }
            DWCi_EncSessionShutdown();
            return;
        }
        return;
    case DPW_BT_STATE_GET_ROOM_NUM_CANCELED: case 5: case 7: case 9: case 11:
        gDpwBtWork.state = DPW_BT_STATE_DONE;
        gDpwBtWork.result = -4;
        DWCi_EncSessionShutdown();
            return;
    case DPW_BT_STATE_UNINITIALIZED: case 1: case 12: break;
    }
}

/* Resets the session to the uninitialized state. */
void DPW_BT_End(void)
{
    gDpwBtWork.state = DPW_BT_STATE_UNINITIALIZED;
}

/* Returns 1 when no request is running; a finished request returns to idle. */
int DPW_BT_IsAsyncEnd(void)
{
    switch (gDpwBtWork.state) {
    case 1:
        return 1;
    case 12:
        gDpwBtWork.state = DPW_BT_STATE_IDLE;
        return 1;
    }
    return 0;
}

/* Result of the last finished request. */
int DPW_BT_GetAsyncResult(void)
{
    return gDpwBtWork.result;
}

/* Request: number of the room for a rank. */
void DPW_BT_GetRoomNumAsync(unsigned rank)
{
    gDpwBtWork.rank = rank - 1;
    DWCi_EncSessionInitialize(gDpwBtServerIndex, gDpwBtBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwBtPathGetRoomNum, gDpwBtWork.profileId, ((unsigned *)&gDpwBtRequestPacket), 1, 0) == 0) {
        gDpwBtWork.state = DPW_BT_STATE_GET_ROOM_NUM;
        return;
    }
    gDpwBtWork.state = DPW_BT_STATE_DONE;
    gDpwBtWork.result = -5;
    DWCi_EncSessionShutdown();
}

/* Request: download the players of a room into resultBuf. */
void DPW_BT_DownloadPlayerAsync(unsigned rank, unsigned roomNo, u8 *resultBuf)
{
    gDpwBtWork.resultBuf = (unsigned char *)resultBuf;
    gDpwBtWork.rank = rank - 1;
    gDpwBtWork.roomNo = roomNo - 1;
    DWCi_EncSessionInitialize(gDpwBtServerIndex, gDpwBtBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwBtPathDownloadPlayer, gDpwBtWork.profileId, ((unsigned *)&gDpwBtRequestPacket), 2, 0) == 0) {
        gDpwBtWork.state = DPW_BT_STATE_DOWNLOAD_PLAYER;
        return;
    }
    gDpwBtWork.state = DPW_BT_STATE_DONE;
    gDpwBtWork.result = -5;
    DWCi_EncSessionShutdown();
}

/* Request: upload the player (240 bytes) and leader (128 bytes) data for a room. */
void DPW_BT_UploadPlayerAsync(u32 rank, u32 roomNo, u32 section, const void *playerData, const void *leaderData, u32 resultBuf)
{
    memcpy(gDpwBtUploadStaging.playerData, playerData, 240);
    gDpwBtUploadStaging.rank = rank - 1;
    gDpwBtUploadStaging.roomNo = roomNo - 1;
    gDpwBtUploadStaging.section = section;
    memcpy(gDpwBtUploadPairKey, gDpwBtPairKeyInit, 8);
    memcpy(gDpwBtUploadLeaderData, leaderData, 128);
    gDpwBtUploadStaging.rankScore = resultBuf;
    gDpwBtRequestPacket = gDpwBtUploadStaging;
    DWCi_EncSessionInitialize(gDpwBtServerIndex, gDpwBtBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwBtPathUploadPlayer, gDpwBtWork.profileId, &gDpwBtRequestPacket, 388, 0) == 0) {
        gDpwBtWork.state = DPW_BT_STATE_UPLOAD_PLAYER;
        return;
    }
    gDpwBtWork.state = DPW_BT_STATE_DONE;
    gDpwBtWork.result = -5;
    DWCi_EncSessionShutdown();
}

/* Cancels the running request: the session is canceled and the state moves to its CANCELED value. */
void DPW_BT_CancelAsync(void)
{
    switch (gDpwBtWork.state) {
    case 2: DWCi_EncSessionCancel(); gDpwBtWork.state = 3; break;
    case 4: DWCi_EncSessionCancel(); gDpwBtWork.state = 5; break;
    case 6: DWCi_EncSessionCancel(); gDpwBtWork.state = 7; break;
    case 8: DWCi_EncSessionCancel(); gDpwBtWork.state = 9; break;
    case 10: DWCi_EncSessionCancel(); gDpwBtWork.state = 11; break;
    }
}

/* Request: query the server state. */
void DPW_BT_GetServerStateAsync(void)
{
    DWCi_EncSessionInitialize(gDpwBtServerIndex, gDpwBtBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwBtPathGetServerState, gDpwBtWork.profileId, ((unsigned *)&gDpwBtRequestPacket), 0, 0) == 0) {
        gDpwBtWork.state = DPW_BT_STATE_GET_SERVER_STATE;
        return;
    }
    gDpwBtWork.state = DPW_BT_STATE_DONE;
    gDpwBtWork.result = -5;
    DWCi_EncSessionShutdown();
}

/* Request: set the player profile (100 bytes). */
void DPW_BT_SetProfileAsync(unsigned char *profile, u8 *resultBuf)
{
    OS_GetMacAddress(profile + 0x1c);
    memcpy(((unsigned *)&gDpwBtRequestPacket), profile, 100);
    gDpwBtWork.resultBuf = (unsigned char *)resultBuf;
    DWCi_EncSessionInitialize(gDpwBtServerIndex, gDpwBtBaseUrl);
    if (DWCi_EncSessionGetAsync(gDpwBtPathSetProfile, gDpwBtWork.profileId, ((unsigned *)&gDpwBtRequestPacket), 100, 0) == 0) {
        gDpwBtWork.state = DPW_BT_STATE_SET_PROFILE;
        return;
    }
    gDpwBtWork.state = DPW_BT_STATE_DONE;
    gDpwBtWork.result = -5;
    DWCi_EncSessionShutdown();
}

/* Maps a DWC error type to a result code; clears the DWC error unless the result is -5. */
int DPW_BT_ConvertDwcError(unsigned dwcErrorType)
{
    int r;
    switch (dwcErrorType) {
    case 0: case 1: case 2: r = -7; break;
    case 3: r = -6; break;
    case 5: r = -6; break;
    case 4: r = -7; break;
    case 6: r = -6; break;
    case 7: r = -5; break;
    default: r = -6; break;
    }
    if (r != -5) {
        if (DWC_UpdateConnection() != 0) r = -6;
        DWC_ClearError();
    }
    return r;
}
