#ifndef ALETHEIA_OV009_GPI_TYPES_H
#define ALETHEIA_OV009_GPI_TYPES_H
/*
 * GameSpy GP ("GPI") types shared by gpibuddy, gpipeer_1,
 * gpiprofile and gpisearch (ov009, the libdwcgsgp gp*.o objects).
 * One definition per object, field offsets checked against every view the
 * parts used.
 *
 *   GPIConnection   0x638 bytes     GPIProfile       0x30 bytes
 *   GPIBuffer       0x10 bytes      GPIBuddyStatus   0x1C bytes
 *   GPIPeer         0x50 bytes      GPIBuddyStatusInfo 0x3C bytes
 *   GPIOperation    0x24 bytes      GPIPeerOp        0x18 bytes
 *   GPISearchData   0x1A0 bytes     GPIMessage       0x18 bytes
 */

#ifndef OV009_BASIC_TYPES
#define OV009_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#endif

typedef enum { _GPIFalse = 0, _GPITrue = 1 } GPIBool;
typedef int GPEnum;
typedef int GPErrorCode;
typedef void *GPConnection;
typedef u32 gsi_time;

typedef enum _GPResult {
    GP_NO_ERROR,
    GP_MEMORY_ERROR,
    GP_PARAMETER_ERROR,
    GP_NETWORK_ERROR,
    GP_SERVER_ERROR,
    GP_MISC_ERROR,
    GP_COUNT
} GPResult;

typedef void (*GPCallback)(void **connection, void *arg, void *param);

typedef struct GPICallback {
    GPCallback callback;
    void *param;
} GPICallback;

typedef struct GPIBuffer {
    char *buffer;                     /* 0x00 */
    int size;                         /* 0x04 */
    int len;                          /* 0x08 */
    int pos;                          /* 0x0C */
} GPIBuffer;

typedef struct GPIMessage {
    GPIBuffer buffer;                 /* 0x00 */
    int type;                         /* 0x10 */
    int start;                        /* 0x14 */
} GPIMessage;

/* Strings a profile caches (nick, uniquenick, email, ...); only these are used. */
typedef struct GPIInfoCache {
    char *nick;                       /* 0x00 */
    char *uniquenick;                 /* 0x04 */
    char *email;                      /* 0x08 */
} GPIInfoCache;

typedef struct GPIBuddyStatus {
    int buddyIndex;                   /* 0x00 */
    int status;                       /* 0x04 */
    char *statusString;               /* 0x08 */
    char *locationString;             /* 0x0C */
    unsigned int ip;                  /* 0x10 */
    unsigned short port;              /* 0x14 */
    int quietModeFlags;               /* 0x18 */
} GPIBuddyStatus;

typedef struct GPIBuddyStatusInfo {
    int buddyIndex;                   /* 0x00 */
    int statusState;                  /* 0x04 */
    char *richStatus;                 /* 0x08 */
    char *gameType;                   /* 0x0C */
    char *gameVariant;                /* 0x10 */
    char *gameMapName;                /* 0x14 */
    int sessionFlags;                        /* 0x18 */
    unsigned int ip;                  /* 0x1C */
    unsigned short port;              /* 0x20 */
    unsigned int hostIp;               /* 0x24 */
    unsigned int hostPrivateIp;               /* 0x28 */
    unsigned short queryPort;             /* 0x2C */
    unsigned short hostPort;             /* 0x2E */
    int quietModeFlags;                        /* 0x30 */
    int productId;                        /* 0x34 */
    void *extendedInfoKeys;           /* 0x38 */
} GPIBuddyStatusInfo;

typedef struct GPIProfile {
    int profileId;                    /* 0x00 */
    int userId;                       /* 0x04 */
    GPIBuddyStatus *buddyStatus;      /* 0x08 */
    GPIBuddyStatusInfo *buddyStatusInfo; /* 0x0C */
    GPIInfoCache *cache;              /* 0x10 */
    char *authSig;                    /* 0x14 */
    int requestCount;                 /* 0x18 */
    char *peerSig;                    /* 0x1C */
    int blocked;                      /* 0x20 */
    int blockIndex;                   /* 0x24 */
    int buddyOrBlockCache;            /* 0x28 */
    int deletedLocally;               /* 0x2C */
} GPIProfile;

typedef struct GPIPeerOp {
    int state;                        /* 0x00 */
    void *userData;                   /* 0x04 */
    GPCallback callback;              /* 0x08 */
    struct GPIPeerOp *next;           /* 0x0C */
    int type;                         /* 0x10 */
    unsigned int timeout;             /* 0x14 */
} GPIPeerOp;

typedef struct GPIPeer {
    int state;                        /* 0x00 */
    int initiated;                    /* 0x04 */
    unsigned int ip;                  /* 0x08 */
    unsigned short port;              /* 0x0C */
    int profile;                      /* 0x10 */
    int timeout;                      /* 0x14 */
    int nackCount;                    /* 0x18 */
    GPIBuffer inputBuffer;            /* 0x1C */
    GPIBuffer outputBuffer;           /* 0x2C */
    void *messages;                   /* 0x3C */
    GPIPeerOp *queueHead;             /* 0x40 */
    GPIPeerOp *firstOp;               /* 0x44 */
    GPIPeerOp *lastOp;                /* 0x48 */
    struct GPIPeer *pnext;            /* 0x4C */
} GPIPeer;

typedef struct GPIOperation {
    int type;                         /* 0x00 */
    struct GPISearchData *data;       /* 0x04 */
    int blocking;                     /* 0x08 */
    GPICallback callback;             /* 0x0C */
    int state;                        /* 0x14 */
    int id;                           /* 0x18 */
    int result;                       /* 0x1C */
    struct GPIOperation *pnext;       /* 0x20 */
} GPIOperation;

typedef struct GPISearchData {
    int type;                         /* 0x000 */
    int sock;                         /* 0x004 */
    GPIBuffer inputBuffer;            /* 0x008 */
    GPIBuffer outputBuffer;           /* 0x018 */
    char nick[31];                    /* 0x028 */
    char uniquenick[21];              /* 0x047 */
    int namespaceIDs[16];             /* 0x05C */
    int numNamespaces;                /* 0x09C */
    char email[51];                   /* 0x0A0 */
    char firstname[31];               /* 0x0D3 */
    char lastname[31];                /* 0x0F2 */
    char password[31];                /* 0x111 */
    char cdkey[65];                   /* 0x130 */
    int partnerID;                    /* 0x174 */
    int icquin;                       /* 0x178 */
    int skip;                         /* 0x17C */
    int productID;                    /* 0x180 */
    int processing;                   /* 0x184 */
    int remove;                       /* 0x188 */
    u32 searchStartTime;              /* 0x18C */
    int *revBuddyProfileIds;          /* 0x190 */
    int numOfRevBuddyProfiles;        /* 0x194 */
    int profile;                      /* 0x198 */
    int maxResults;                   /* 0x19C */
} GPISearchData;

typedef struct GPIProfileList {
    void *profileTable;               /* 0x00 */
    int num;                          /* 0x04 */
    int numBuddies;                   /* 0x08 */
    int numBlocked;                   /* 0x0C */
} GPIProfileList;

typedef struct GPIConnection {
    char errorString[256];            /* 0x000 */
    int infoCaching;                  /* 0x100 */
    int infoCachingBuddyAndBlockOnly; /* 0x104 */
    int simulation;                   /* 0x108 */
    int firewall;                     /* 0x10C */
    char nick[31];                    /* 0x110 */
    char uniquenick[21];              /* 0x12F */
    char email[51];                   /* 0x144 */
    char password[31];                /* 0x177 */
    int sessKey;                      /* 0x198 */
    int userid;                       /* 0x19C */
    int profileid;                    /* 0x1A0 */
    int partnerID;                    /* 0x1A4 */
    GPICallback callbacks[9];         /* 0x1A8 */
    int cmSocket;                     /* 0x1F0 */
    int connectState;                 /* 0x1F4 */
    GPIBuffer socketBuffer;           /* 0x1F8 */
    char *inputBuffer;                /* 0x208 */
    int inputBufferSize;              /* 0x20C */
    GPIBuffer outputBuffer;           /* 0x210 */
    char mHeader[16];                 /* 0x220 */
    unsigned short peerPort;          /* 0x230 */
    int nextOperationID;              /* 0x234 */
    int numSearches;                  /* 0x238 */
    int lastStatusState;              /* 0x23C */
    unsigned int hostIp;              /* 0x240 */
    unsigned int hostPrivateIp;       /* 0x244 */
    unsigned short queryPort;         /* 0x248 */
    unsigned short hostPort;          /* 0x24A */
    unsigned int sessionFlags;        /* 0x24C */
    char richStatus[256];             /* 0x250 */
    char gameType[33];                /* 0x350 */
    char gameVariant[33];             /* 0x371 */
    char gameMapName[33];             /* 0x392 */
    void *extendedInfoKeys;           /* 0x3B4 */
    char lastStatusString[256];       /* 0x3B8 */
    char lastLocationString[256];     /* 0x4B8 */
    int errorCode;                    /* 0x5B8 */
    int fatalError;                   /* 0x5BC */
    void *diskCache;                  /* 0x5C0 */
    GPIOperation *operationList;      /* 0x5C4 */
    GPIProfileList profileList;       /* 0x5C8 */
    GPIPeer *peerList;                /* 0x5D8 */
    void *callbackList;               /* 0x5DC */
    void *lastCallback;               /* 0x5E0 */
    GPIBuffer updateproBuffer;        /* 0x5E4 */
    GPIBuffer updateuiBuffer;         /* 0x5F4 */
    void *transfers;                  /* 0x604 */
    unsigned int nextTransferID;      /* 0x608 */
    int productID;                    /* 0x60C */
    int namespaceID;                  /* 0x610 */
    char loginTicket[25];             /* 0x614 */
    int quietModeFlags;               /* 0x630 */
    unsigned int kaTransmit;          /* 0x634 */
} GPIConnection;

typedef struct GPITransferID {
    int profileid;                    /* 0x00 */
    unsigned int count;               /* 0x04 */
    unsigned int time;                /* 0x08 */
} GPITransferID;

/* Profile table walkers (gpiprofile.o). */

typedef struct GPIProfileMapData {
    void **connection;
    int (*func)(void *, GPIProfile *, void *);
    void *data;
} GPIProfileMapData;

typedef struct GPIFindProfileData {
    int blockIndex;
    GPIProfile *profile;
} GPIFindProfileData;

typedef struct GPIFindProfileByUserData {
    char *nick;
    char *email;
    GPIProfile **profile;
    int found;
} GPIFindProfileByUserData;

/* Callback argument records handed to the game. */

typedef struct GPRecvBuddyMessageArg {
    int profile;
    unsigned int date;
    char *message;
} GPRecvBuddyMessageArg;

typedef struct GPRecvBuddyUTMArg {
    int profile;
    unsigned int date;
    char *message;
} GPRecvBuddyUTMArg;

typedef struct GPRecvBuddyRequestArg {
    int profile;
    unsigned int date;
    char reason[1025];
} GPRecvBuddyRequestArg;

typedef struct GPRecvBuddyAuthArg {
    int profile;
    unsigned int date;
} GPRecvBuddyAuthArg;

typedef struct GPRecvBuddyRevokeArg {
    int profile;
    unsigned int date;
} GPRecvBuddyRevokeArg;

typedef struct GPRecvBuddyStatusArg {
    int profile;
    unsigned int date;
    int buddyIndex;
} GPRecvBuddyStatusArg;

typedef struct GPRecvGameInviteArg {
    int profile;
    int productID;
    char location[256];
} GPRecvGameInviteArg;

typedef struct GPGetBuddyStatusInfoKeysArg {
    int profile;
    char **keys;
    char **values;
    int numKeys;
} GPGetBuddyStatusInfoKeysArg;

typedef struct GPNewProfileResponseArg {
    int result;
    int profile;
} GPNewProfileResponseArg;

typedef struct GPDeleteProfileResponseArg {
    int result;
    int profile;
} GPDeleteProfileResponseArg;

typedef struct GPProfileSearchMatch {
    int profile;                      /* 0x00 */
    char nick[31];                    /* 0x04 */
    char uniquenick[21];              /* 0x23 */
    int namespaceID;                  /* 0x38 */
    char firstname[31];               /* 0x3C */
    char lastname[31];                /* 0x5B */
    char email[51];                   /* 0x7A */
} GPProfileSearchMatch;

typedef struct GPUniqueMatch {
    int profile;                      /* 0x00 */
    char uniqueNick[21];              /* 0x04 */
} GPUniqueMatch;

typedef struct GPProfileSearchResponseArg {
    int result;                       /* 0x00 */
    int numMatches;                   /* 0x04 */
    GPEnum more;                      /* 0x08 */
    GPProfileSearchMatch *matches;    /* 0x0C */
} GPProfileSearchResponseArg;

typedef struct GPGetReverseBuddiesResponseArg {
    int result;                       /* 0x00 */
    int numProfiles;                  /* 0x04 */
    GPProfileSearchMatch *profiles;   /* 0x08 */
} GPGetReverseBuddiesResponseArg;

typedef struct GPGetReverseBuddiesListResponseArg {
    int result;                       /* 0x00 */
    int numOfUniqueMatchs;            /* 0x04 */
    GPUniqueMatch *matches;           /* 0x08 */
} GPGetReverseBuddiesListResponseArg;

typedef struct GPIsValidEmailResponseArg {
    int result;                       /* 0x00 */
    char email[51];                   /* 0x04 */
    GPEnum isValid;                   /* 0x38 */
} GPIsValidEmailResponseArg;

typedef struct GPGetUserNicksResponseArg {
    int result;                       /* 0x00 */
    char email[51];                   /* 0x04 */
    int numNicks;                     /* 0x38 */
    char **nicks;                     /* 0x3C */
    char **uniquenicks;               /* 0x40 */
} GPGetUserNicksResponseArg;

typedef struct GPFindPlayerMatch {
    int profile;                      /* 0x00 */
    char nick[31];                    /* 0x04 */
    GPEnum status;                    /* 0x24 */
    char statusString[256];           /* 0x28 */
} GPFindPlayerMatch;

typedef struct GPFindPlayersResponseArg {
    int result;                       /* 0x00 */
    int productID;                    /* 0x04 */
    int numMatches;                   /* 0x08 */
    GPFindPlayerMatch *matches;       /* 0x0C */
} GPFindPlayersResponseArg;

typedef struct GPNewUserResponseArg {
    int result;                       /* 0x00 */
    int profile;                      /* 0x04 */
} GPNewUserResponseArg;

typedef struct GPCheckResponseArg {
    int result;                       /* 0x00 */
    int profile;                      /* 0x04 */
} GPCheckResponseArg;

typedef struct GPSuggestUniqueNickResponseArg {
    int result;                       /* 0x00 */
    int numSuggestedNicks;            /* 0x04 */
    char **suggestedNicks;            /* 0x08 */
} GPSuggestUniqueNickResponseArg;

typedef struct GPProfileListResponseArg {
    int result;                       /* 0x00 */
    int profile;                      /* 0x04 */
    int hidden;                       /* 0x08 */
    int numMatches;                   /* 0x0C */
    int *matches;                     /* 0x10 */
} GPProfileListResponseArg;

#endif
