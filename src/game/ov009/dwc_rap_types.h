/* Types of the Wi-Fi session wrapper over the DWC library (dwc_rap.c). */
#ifndef DWC_RAP_TYPES_H
#define DWC_RAP_TYPES_H

#include "../types.h"

#include "../arm9/net_types.h"
#include "../arm9/dwc_connectinet_types.h"

typedef void (*DwcRapRecvFunc)(u32 aid, u8 *data, u16 size);

/*
 * Work block of the Wi-Fi session state machine (0x7AC bytes), allocated by
 * the create function and held in the file static _pRapWork.
 */
typedef struct DwcRapWork {
    union { int word; u8 octet[4]; } sendHeader; /* 0x000 type | vchat flag << 8 | seq << 16 */
    u8 sendPayload[0xFC];               /* 0x004 */
    u8 *friendList;                     /* 0x100 DWCFriendData[], 12 bytes each; NULL when not used */
    u8 pad104[4];
    void *userData;                     /* 0x108 DWC account user data */
    DWCstInetControl inetWork;          /* 0x10C work area of the DWC internet connect call */
    void *recvBuffer[2];                /* 0x174 reliable receive buffer per peer (0x1000 bytes) */
    int deletedFriendIndex[32];         /* 0x17C queued by the friend-delete callback, -1 when free */
    int deletedFriendSrcIndex[32];      /* 0x1FC */
    DwcRapRecvFunc serverRecvFunc;      /* 0x27C game receive callback while this node is the server */
    DwcRapRecvFunc clientRecvFunc;      /* 0x280 game receive callback while this node is a client */
    void (*connectionClosedFunc)(u32, u32); /* 0x284 (aid, connectionClosedArg) */
    u32 connectionClosedArg;            /* 0x288 */
    int (*errorFunc)(u32, u32, u32, int);   /* 0x28C (errorArg, errorCode, errorType, dwcError) */
    u32 errorArg;                       /* 0x290 */
    int (*errorHookFunc)(u32, u32, u32, int); /* 0x294 runs first; returning 1 swallows the error */
    u32 errorHookArg;                   /* 0x298 */
    void (*connectEventFunc)(int, int); /* 0x29C (aid, connectEventArg) after a match or a new client */
    int connectEventArg;                /* 0x2A0 */
    int (*acceptFriendFunc)(int, void *);  /* 0x2A4 (friendIndex, userArg); 0 rejects the peer */
    void (*fatalErrorFunc)(int);        /* 0x2A8 called with the negated error code (error type 7) */
    char matchFilter[0x80];             /* 0x2AC "a = value" filter string of the match search */
    u8 friendStatus[32];                /* 0x32C status byte per friend index */
    u8 friendStatusData[32][0x20];      /* 0x34C status string per friend index */
    u32 friendPollCursor;               /* 0x74C counter; (cursor & 31) is the friend polled this frame */
    int connectionUserData;             /* 0x750 handed to the DWC connect call */
    int state;                          /* 0x754 DWC_RAP_STATE_* */
    int result;                         /* 0x758 last result code reported to the game */
    int connectMode;                    /* 0x75C 0 match anybody, 1 host a friend game, 2 join a friend */
    int sendInFlight;                   /* 0x760 a reliable packet is still being sent */
    int maxPlayers;                     /* 0x764 */
    int vchatAidBitmap;                 /* 0x768 AID bitmap the voice chat last synchronised to */
    int vchatActive;                    /* 0x76C voice chat is running */
    int targetFriendIndex;              /* 0x770 friend to join (-1 when hosting), later the peer index */
    int newClientAid;                   /* 0x774 AID of the last client that joined, -1 when none */
    int connectPending;                 /* 0x778 a connect call has not reported back yet */
    int vchatPlayerCount;               /* 0x77C picks the voice chat session size (2..5) */
    short canceledPeerIndex;            /* 0x780 peer that cancelled the match, -1 when none */
    short vchatEnabled;                 /* 0x782 the game asked for voice chat */
    int peerCounter[3];                 /* 0x784 frames since the last send to peer 0 and 1; [2] counts connect retries */
    int vchatPeerOn;                    /* 0x790 voice chat flag the peer sent in its header */
    u16 vchatLocalOn;                   /* 0x794 voice chat flag this node sends in its header */
    u16 vchatGateOpen;                  /* 0x796 third voice chat condition, set when the session starts */
    int aidBitmapAtConnect;             /* 0x798 */
    u8 sendSeq;                         /* 0x79C */
    u8 lastRecvSeq;                     /* 0x79D */
    u8 forceFatalError;                 /* 0x79E reported as the fatal result when set */
    u8 vchatTalkLock;                   /* 0x79F */
    u8 kickNewPeers;                    /* 0x7A0 close the connection of every peer that joins */
    u8 connectArmed;                    /* 0x7A1 */
    u8 userDataChanged;                 /* 0x7A2 the account data became dirty and must be saved */
    u8 errorOnDisconnect;               /* 0x7A3 raise a game error when the connection closes */
    u8 rejectStrangers;                 /* 0x7A4 reject a peer that is not in the friend list */
    u8 allowConnect;                    /* 0x7A5 answer of the connect attempt callback */
    u8 sendStateReady;                  /* 0x7A6 the peer acknowledged the last state packet */
    u8 ackPending;                      /* 0x7A7 an acknowledge packet still has to be sent */
    u8 peerAlive;                       /* 0x7A8 something was received from the peer */
    u8 friendsMatchInit;                /* 0x7A9 DWC_InitFriendsMatch has run */
    u8 pad7AA[2];
} DwcRapWork;

/* Values of DwcRapWork.state. */
enum {
    DWC_RAP_STATE_START = 0,            /* start the internet connect */
    DWC_RAP_STATE_WAIT_INET = 1,        /* waiting for the access point link */
    DWC_RAP_STATE_INIT_LOGIN = 2,       /* init friends match and call login */
    DWC_RAP_STATE_LOGIN = 3,            /* login running */
    DWC_RAP_STATE_UPDATE_SERVERS = 4,   /* start the friend list update */
    DWC_RAP_STATE_WAIT_UPDATE = 5,      /* friend list update running */
    DWC_RAP_STATE_IDLE = 6,             /* logged in, no connection */
    DWC_RAP_STATE_MATCHING = 7,         /* match search or join running */
    DWC_RAP_STATE_CANCELING = 8,        /* closing connections for a cancel */
    DWC_RAP_STATE_CONNECTED = 9,        /* match done, report it once */
    DWC_RAP_STATE_IN_SESSION = 10,      /* connected, exchanging data */
    DWC_RAP_STATE_CANCELED = 11,
    DWC_RAP_STATE_MATCH_FAILING = 12,   /* connections closing after a failed match */
    DWC_RAP_STATE_MATCH_FAILED = 13,
    DWC_RAP_STATE_ERROR = 14,           /* error while logging in */
    DWC_RAP_STATE_FATAL_DISCONNECT = 16,
    DWC_RAP_STATE_FATAL_ERROR = 17,     /* error type 7 */
    DWC_RAP_STATE_CLOSING = 18,         /* connection lost, closing */
    DWC_RAP_STATE_CLOSED = 19,
    DWC_RAP_STATE_TIMED_OUT = 20        /* receive timeout */
};

/* Results the state machine reports to the game (DwcRapWork.result, game error code). */
enum {
    DWC_RAP_RESULT_CONNECTED = 1000,
    DWC_RAP_RESULT_CANCELED = 0x3E9,
    DWC_RAP_RESULT_MATCH_FAILED = 0x3EA,
    DWC_RAP_RESULT_TIMED_OUT = 0x3EB,
    DWC_RAP_RESULT_CLOSED = 0x3EC,
    DWC_RAP_RESULT_FATAL = 0x3EE,
    DWC_RAP_RESULT_IDLE = 0x3EF,        /* nothing to report */
    DWC_RAP_RESULT_TIMEOUT_ERROR = 0x3F0,
    DWC_RAP_RESULT_DISCONNECT_ERROR = 0x3F1
};


/* Heap object that _pRapHeap points to (the DWC allocator of this module). */
typedef struct DwcRapHeap {
    u32 mainHeap;                       /* 0x00 handle of the main heap */
    u32 mainMem;                        /* 0x04 its backing block */
    u32 subHeap;                        /* 0x08 secondary heap, 0 when none */
    u32 subMem;                         /* 0x0C its backing block */
    u32 subOwnerId;                     /* 0x10 owner id the secondary heap serves */
    u32 subLiveBlocks;                  /* 0x14 live blocks in the secondary heap */
    u32 subMinRequest;                  /* 0x18 smallest request that is not served from it */
    u32 allocFailed;                    /* 0x1C set when an allocation failed */
    u16 tag;                            /* 0x20 */
} DwcRapHeap;

#endif
