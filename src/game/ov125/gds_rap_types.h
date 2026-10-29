#ifndef OV125_GDS_RAP_TYPES_H
#define OV125_GDS_RAP_TYPES_H
/*
 * Types of the online data station (GDS) client in ov125.  Owner header of
 * gds_rap.c (the request layer: one work object, HTTP stage plus socket
 * stage) and gds_socket.c (the socket layer: one connection object, wire
 * packets).  Needs u8, u16, u32, u64, s32 from the including file.
 */

#include "../arm9/battle_rec_types.h"
#ifndef OV114_BASIC_TYPES
#define OV114_BASIC_TYPES
#endif
#include "../ov114/nhttp_rap_types.h"

struct GameData;
struct MsgData;
struct WordSet;
struct Strbuf;

/* Request ids.  The server answers with a packet that carries the same id
 * (21000 = 0x5208 ... 22003 = 0x55F3). */
#define GDS_REQUEST_UPLOAD_ENTRY      0x5208  /* one profile block and one payload block */
#define GDS_REQUEST_DOWNLOAD_ENTRIES  0x5209  /* up to five entries for one key */
#define GDS_REQUEST_UPLOAD_VIDEO      0x55F0  /* battle video, two server stages */
#define GDS_REQUEST_SEARCH_VIDEOS     0x55F1  /* list of video summaries */
#define GDS_REQUEST_GET_VIDEO         0x55F2  /* one full video by data number */
#define GDS_REQUEST_MARK_VIDEO        0x55F3  /* reply is a result code only */
#define GDS_REQUEST_NONE              0x55F4  /* no request pending or finished */

/* Search modes of GDS_REQUEST_SEARCH_VIDEOS (field searchKind). */
#define GDS_SEARCH_BY_CONDITION  0
#define GDS_SEARCH_KIND_1        1
#define GDS_SEARCH_KIND_2        2
#define GDS_SEARCH_KIND_3        3

/* Socket states (GdsSocket.state). */
#define GDS_SOCKET_STATE_IDLE      0
#define GDS_SOCKET_STATE_READY     1
#define GDS_SOCKET_STATE_TOKEN     2  /* wait for the service token */
#define GDS_SOCKET_STATE_RESOLVE   3  /* create socket, resolve host, enable SSL */
#define GDS_SOCKET_STATE_CONNECT   4
#define GDS_SOCKET_STATE_SEND      5
#define GDS_SOCKET_STATE_RECEIVE   6
#define GDS_SOCKET_STATE_CANCELLED 7
#define GDS_SOCKET_STATE_DONE      8
#define GDS_SOCKET_STATE_FAILED    9

/* Socket error codes (GdsSocket.errorCode). */
#define GDS_SOCKET_ERROR_ABORTED 13   /* the caller asked to cancel */

#define GDS_WIRE_HEADER_SIZE 0x140    /* length word, id, client info */
#define GDS_PROFILE_SIZE     0x80
#define GDS_PAYLOAD_SIZE     0x1B0
#define GDS_TICKET_SIZE      0x80
#define GDS_TICKET_MAX       256
#define GDS_SEARCH_LIMIT     100
#define GDS_VIDEO_VERSION    100
#define GDS_DOWNLOAD_MAX     5
#define GDS_SEARCH_MAX       30
#define GDS_NICKNAME_LEN     11
#define GDS_NAME_SLOTS       12

/* Pokemon of party and member counted from the first Pokemon of the first
 * party.  A party holds six Pokemon behind a 4 byte count, so the party
 * stride is not six times the Pokemon size. */
#define GDS_REC_POKE(first, party, member)     ((struct BattleRecMon *)((u8 *)(first) + (party) * sizeof(struct BattleRecParty) + (member) * sizeof(struct BattleRecMon)))

typedef struct GdsSvlToken {
    u8 text[301];                       /* service token string with terminator */
} GdsSvlToken;

/* Result of the service locator token request (DWC_SVLGetTokenAsync).  Owned
 * by ov114/dwc_svl_types.h and shared with the DWC nd front end; the former
 * GdsSvlResult copy is folded into DWCSvlResult. */
#include "../ov114/dwc_svl_types.h"

/* Identity block at the front of the request packet and of the socket
 * object (0x138 bytes). */
typedef struct GdsClientInfo {
    u32 profileId;                      /* 0x000 */
    u8 packetType;                      /* 0x004: 0x15, as in NHTTPRapTrainerInfo */
    u8 language;                        /* 0x005: the cartridge language id */
    GdsSvlToken svlToken;               /* 0x006 */
    u8 unknown133[5];                   /* 0x133 */
} GdsClientInfo;

/* One entry of the profile and payload pair of GDS_REQUEST_UPLOAD_ENTRY
 * (0x230 bytes). */
typedef struct GdsProfileBlock {
    u32 words[GDS_PROFILE_SIZE / 4];
} GdsProfileBlock;

typedef struct GdsPayloadBlock {
    u32 words[GDS_PAYLOAD_SIZE / 4];
} GdsPayloadBlock;

typedef struct GdsEntryBlocks {
    GdsProfileBlock profile;
    GdsPayloadBlock payload;
} GdsEntryBlocks;

/* Search filter of GDS_REQUEST_SEARCH_VIDEOS, searchKind 0 (16 bytes). */
typedef struct GdsSearchParams {
    u16 keyId;
    u16 category;
    u16 categoryMask;
    u8 mode;
    u8 flag;
    u32 limit;                          /* GDS_SEARCH_LIMIT */
    u32 reserved;
} GdsSearchParams;

/* Entry of the search table: the category and its mask. */
typedef struct GdsSearchCategory {
    u16 category;
    u16 mask;
} GdsSearchCategory;

/* Reply of one video listing: profile and header of the record (0xC4). */
typedef struct GdsVideoListing {
    u8 profile[GDS_PROFILE_SIZE];
    struct BattleRecHeader head;
} GdsVideoListing;

/* One entry of a search reply (0xD0 bytes).  The server id goes into
 * listing.head.dataNumber when the two differ. */
typedef struct GdsListingEntry {
    u32 unknown0;
    BattleRecDataNumber dataNumber;
    GdsVideoListing listing;
} GdsListingEntry;

/* One entry of a download reply (572 bytes). */
typedef struct GdsDownloadEntry {
    u8 unknown0[12];
    GdsEntryBlocks blocks;
} GdsDownloadEntry;

/* One full video of a get reply: server id, then the record. */
typedef struct GdsVideoEntry {
    u32 unknown0;
    BattleRecDataNumber dataNumber;
    struct BattleRecSave video;
} GdsVideoEntry;

/* Reply packets.  The reply starts with the request id and a result code
 * (0 = accepted); the socket layer hands out the packet after its length
 * word. */
typedef struct GdsReply {
    u16 requestId;
    u16 resultCode;
} GdsReply;

typedef struct GdsDownloadList {
    u32 count;
    GdsDownloadEntry entries[1];
} GdsDownloadList;

typedef struct GdsReplyDownload {
    GdsReply reply;
    GdsDownloadList list;
} GdsReplyDownload;

typedef struct GdsReplyUploadVideo {
    GdsReply reply;
    BattleRecDataNumber dataNumber;     /* id the server gave to the video */
} GdsReplyUploadVideo;

typedef struct GdsListingList {
    u32 count;
    GdsListingEntry entries[1];
} GdsListingList;

typedef struct GdsReplySearch {
    GdsReply reply;
    GdsListingList list;
} GdsReplySearch;

typedef struct GdsReplyGetVideo {
    GdsReply reply;
    GdsVideoEntry entry;
} GdsReplyGetVideo;

/* Wire packets (GdsPacketHeader precedes every body). */
typedef struct GdsPacketHeader {
    u32 totalSize;                      /* counts this word and the header */
    u16 requestId;
    u16 reserved;
    GdsClientInfo client;
} GdsPacketHeader;

typedef struct GdsPacketDownload {      /* GDS_REQUEST_DOWNLOAD_ENTRIES body, 12 bytes */
    u16 reserved0;
    u16 reserved1;
    long long key;
} GdsPacketDownload;

typedef struct GdsPacketUploadVideo {   /* GDS_REQUEST_UPLOAD_VIDEO body, 0x19A8 bytes */
    struct BattleRecSave video;
    s32 ticketLength;
    char ticket[GDS_TICKET_MAX];
} GdsPacketUploadVideo;

typedef struct GdsPacketSearch {        /* GDS_REQUEST_SEARCH_VIDEOS body, 28 bytes */
    u16 searchKind;
    u16 reserved;
    GdsSearchParams params;
    u32 tail[2];
} GdsPacketSearch;

typedef struct GdsPacketGetVideo {      /* GDS_REQUEST_GET_VIDEO body, 12 bytes */
    u32 dataNumberLo;
    u32 dataNumberHi;
    u32 version;
} GdsPacketGetVideo;

typedef struct GdsPacketMarkVideo {     /* GDS_REQUEST_MARK_VIDEO body, 8 bytes */
    u32 dataNumberLo;
    u32 dataNumberHi;
} GdsPacketMarkVideo;

/* Result block the caller reads through GDS_RAP_GetResult (16 bytes). */
typedef struct GdsRapResult {
    s32 pending;                        /* 1 while the block holds an unread result */
    s32 errorKind;                      /* 0 socket error, 1 aborted, 2 server error */
    s32 requestId;
    s32 errorCode;
} GdsRapResult;

typedef void (*GdsRapCallback)(void *userData, GdsRapResult *result);

/* Call-backs of a work object (0x1C bytes, also the tail of the init
 * parameters). */
typedef struct GdsRapCallbacks {
    void *userData;
    GdsRapCallback onUploadEntry;       /* reply 21000 */
    GdsRapCallback onDownloadEntries;   /* reply 21001 */
    GdsRapCallback onUploadVideo;       /* reply 22000, also the HTTP stage failure */
    GdsRapCallback onSearchVideos;      /* reply 22001 */
    GdsRapCallback onGetVideo;          /* reply 22002 */
    GdsRapCallback onMarkVideo;         /* reply 22003 */
} GdsRapCallbacks;

/* Parameters of the work object constructor (0x2C bytes). */
typedef struct GdsRapInitParams {
    u32 profileId;
    u16 heapId;
    /* 2 bytes of compiler alignment before the 4 byte gameData pointer; no
     * code reads or writes them (the original had no member there). */
    struct GameData *gameData;
    void *profileSource;
    GdsRapCallbacks callbacks;
} GdsRapInitParams;

struct GdsRapWork;
struct GdsRapPending;
typedef int (*GdsRapPollFunc)(struct GdsRapWork *work, struct GdsRapPending *pending);

/* Reply that is waiting for its call-back (16 bytes). */
typedef struct GdsRapPending {
    GdsRapCallback callback;            /* 0x0 */
    u16 saveStep;                       /* 0x4: first halfword of the save sequence */
    u16 saveSubStep;                    /* 0x6 */
    u32 unknown8;
    GdsRapPollFunc poll;                /* 0xC: finishes the work before the call-back */
} GdsRapPending;

/* The request work object (0x5A4 bytes), allocated by the caller. */
typedef struct GdsRapWork {
    struct GameData *gameData;          /* 0x000 */
    GdsClientInfo client;               /* 0x004 */
    u32 heapId;                         /* 0x13C */
    u32 socketState;                    /* 0x140 */
    s32 lastSocketState;                /* 0x144 */
    GdsRapCallbacks callbacks;          /* 0x148 */
    GdsRapResult result;                /* 0x164 */
    union {                             /* 0x174: arguments of the pending request */
        GdsEntryBlocks entry;           /* GDS_REQUEST_UPLOAD_ENTRY */
        GdsSearchParams search;         /* GDS_REQUEST_SEARCH_VIDEOS */
        struct BattleRecSave *video;    /* GDS_REQUEST_UPLOAD_VIDEO */
    } args;
    union {                             /* 0x3A4 */
        u16 downloadKey;                /* GDS_REQUEST_DOWNLOAD_ENTRIES */
        struct {
            u32 lo;
            u32 hi;
        } dataNumber;                   /* GDS_REQUEST_GET_VIDEO, GDS_REQUEST_MARK_VIDEO */
    } arg2;
    void *replyBuffer;                  /* 0x3AC */
    u32 initialized;                    /* 0x3B0 */
    u32 active;                         /* 0x3B4 */
    u8 unknown3B8[0x20];                /* 0x3B8 */
    s32 requestId;                      /* 0x3D8: GDS_REQUEST_NONE when idle */
    s32 finishedRequestId;              /* 0x3DC */
    u32 searchKind;                     /* 0x3E0 */
    struct MsgData *msgData;            /* 0x3E4 */
    struct WordSet *wordSet;            /* 0x3E8 */
    struct Strbuf *strBuf;              /* 0x3EC */
    GdsRapPending pending;              /* 0x3F0 */
    u8 unknown400;                      /* 0x400 */
    u8 waitFrames;                      /* 0x401 */
    u8 step;                            /* 0x402 */
    u8 secondPass;                      /* 0x403 */
    NHTTPRapSession *session;           /* 0x404 */
    u8 unknown408[2];                   /* 0x408 */
    u8 ticket[GDS_TICKET_SIZE];         /* 0x40A */
    u8 unknown48A[2];                   /* 0x48A */
    u32 nameCheckResult;                /* 0x48C */
    u8 memberCount;                     /* 0x490 */
    u8 unknown491;                      /* 0x491 */
    u8 nameCheckFailed;                 /* 0x492 */
    u8 httpErrorCode;                   /* 0x493 */
    void *profileSource;                /* 0x494 */
    u16 nicknames[GDS_NAME_SLOTS][GDS_NICKNAME_LEN]; /* 0x498 */
    u32 namesChanged;                   /* 0x5A0 */
} GdsRapWork;

/* Tail of GdsSocket.hostName and the port behind it: the image addresses
 * them as the separate object gGdsHostTail. */
struct GdsHostTail {
    char nameEnd[0x40];
    u16 port;
};

/* The connection object (0x418 bytes, global in ov125). */
typedef struct GdsSocket {
    GdsClientInfo client;               /* 0x000 */
    s32 tokenReady;                     /* 0x138 */
    s32 state;                          /* 0x13C */
    char hostName[256];                 /* 0x140 */
    u16 port;                           /* 0x240 */
    /* 2 bytes of compiler alignment before the 4 byte connectTimeout; the
     * image addresses nothing here. */
    s32 connectTimeout;                 /* 0x244, seconds */
    s32 sendTimeout;                    /* 0x248 */
    s32 receiveTimeout;                 /* 0x24C */
    s32 errorCode;                      /* 0x250 */
    s32 sendSize;                       /* 0x254 */
    u8 *sendBuffer;                     /* 0x258 */
    s32 receiveSize;                    /* 0x25C */
    u8 *receiveBuffer;                  /* 0x260 */
    u32 serverAddress;                  /* 0x264, network order */
    s32 cancelRequested;                /* 0x268 */
    s32 socket;                         /* 0x26C */
    u32 threadPriority;                 /* 0x270 */
    u8 objectsStorage[0x198];           /* 0x274: connect thread, mutex, receive thread */
    s32 receiveResult;                  /* 0x40C: written by the receive thread */
    s32 receiveCount;                   /* 0x410 */
    s32 receiveReady;                   /* 0x414 */
} GdsSocket;

/* Size checks (a wrong size makes the array length negative). */
typedef char GdsCheckClientInfo[(sizeof(void *) != 4 || (sizeof(GdsClientInfo) == 0x138)) ? 1 : -1];
typedef char GdsCheckPoke[(sizeof(void *) != 4 || (sizeof(struct BattleRecMon) == 0x70)) ? 1 : -1];
typedef char GdsCheckParty[(sizeof(void *) != 4 || (sizeof(struct BattleRecParty) == 0x2A4)) ? 1 : -1];
typedef char GdsCheckRecBody[(sizeof(void *) != 4 || (sizeof(struct BattleRecBody) == 0x17E0)) ? 1 : -1];
typedef char GdsCheckRecSave[(sizeof(void *) != 4 || (sizeof(struct BattleRecSave) == 0x18A4)) ? 1 : -1];
typedef char GdsCheckListing[(sizeof(void *) != 4 || (sizeof(GdsVideoListing) == 0xC4)) ? 1 : -1];
typedef char GdsCheckListingEntry[(sizeof(void *) != 4 || (sizeof(GdsListingEntry) == 0xD0)) ? 1 : -1];
typedef char GdsCheckDownloadEntry[(sizeof(void *) != 4 || (sizeof(GdsDownloadEntry) == 572)) ? 1 : -1];
typedef char GdsCheckVideoEntry[(sizeof(void *) != 4 || (sizeof(GdsVideoEntry) == 0x18B0)) ? 1 : -1];
typedef char GdsCheckPacketHeader[(sizeof(void *) != 4 || (sizeof(GdsPacketHeader) == GDS_WIRE_HEADER_SIZE)) ? 1 : -1];
typedef char GdsCheckDownloadPacket[(sizeof(void *) != 4 || (sizeof(GdsPacketDownload) == 12)) ? 1 : -1];
typedef char GdsCheckUploadVideo[(sizeof(void *) != 4 || (sizeof(GdsPacketUploadVideo) == 0x19A8)) ? 1 : -1];
typedef char GdsCheckSearch[(sizeof(void *) != 4 || (sizeof(GdsPacketSearch) == 28)) ? 1 : -1];
typedef char GdsCheckRapWork[(sizeof(void *) != 4 || (sizeof(GdsRapWork) == 0x5A4)) ? 1 : -1];
typedef char GdsCheckSocket[(sizeof(void *) != 4 || (sizeof(GdsSocket) == 0x418)) ? 1 : -1];

#endif
