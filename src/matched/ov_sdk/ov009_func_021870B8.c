/*
 * function: gpiProcessRecvBuddyMessage
 * address:  0x021870B8
 * packet:   pkt_ov009_021870B8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProcessRecvBuddyMessage (libdwcgsgp.TWL.HYB.a gpibuddy.o)
 *
 * note:     EXACT (2026-10-01, wave 3 lane 04).  Rewritten in the GameSpy
 *   gpiBuddy.c shape: one function-scope GPICallback (DWARF has a single
 *   callback at fb+56) and the DWARF declaration order, Error/
 *   CallbackFatalError/CHECK_RESULT/freeclear macros, enum _GPResult return.
 *   The parked "fp allocation tie" was source shape: the buddyStatusInfo
 *   block belongs inside `if (!profile->buddyStatus)` (image bne skips it),
 *   freeclear stores NULL after gsifree(authSig), and the buddy request
 *   callback passes a NULL operation, not arg.  strzcpy length is
 *   GP_REASON_LEN 1025.
 *
 * symbols:
 *   gpiValueForKey                0x02193418 arm ov009
 *   gpiSetError                   0x02193710 arm ov009
 *   gpiCallErrorCallback          0x02189D78 arm ov009
 *   atoi                          0x020964E0 arm
 *   gsiTimeNitro                  0x02184098 arm ov009
 *   gsimalloc                     0x0217EAB0 arm ov009
 *   gpiSetErrorString             0x02193734 arm ov009
 *   strlen                        0x0209477C arm
 *   strcpy                        0x02094798 arm
 *   gpiAddCallback                0x02189DFC arm ov009
 *   gpiProfileListAdd             0x0218FCD8 arm ov009
 *   strstr                        0x02094B20 arm
 *   gsifree                       0x0217EAE0 arm ov009
 *   goastrdup                     0x0217F1E0 arm ov009
 *   strzcpy                       0x0219327C arm ov009
 *   gsDebugFormat                 0x0217D254 arm ov009
 *   gpiRemoveBuddyStatusInfo      0x021900EC arm ov009
 *   gsiSafeStrcpyA                0x021803BC arm ov009
 *   gpiSendBuddyMessage           0x021889A0 arm ov009
 *   memset                        0x020923B0 arm
 *   g_021A4278                    0x021A4278 data
 *   g_021A4280                    0x021A4280 data
 *   g_021A42B0                    0x021A42B0 data
 *   g_021A42B4                    0x021A42B4 data
 *   g_021A42BC                    0x021A42BC data
 *   g_021A42CC                    0x021A42CC data
 *   g_021A42D4                    0x021A42D4 data
 *   g_021A42E0                    0x021A42E0 data
 *   g_021A437C                    0x021A437C data
 *   g_021A4380                    0x021A4380 data
 *   g_021A4388                    0x021A4388 data
 *   g_021A4390                    0x021A4390 data
 *   g_021A4398                    0x021A4398 data
 *   g_021A439C                    0x021A439C data
 *   g_021A43A4                    0x021A43A4 data
 *   g_021A43A8                    0x021A43A8 data
 */

typedef struct GPIBuffer {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer;

typedef struct GPICallback {
    void (*fn)(void *, void *);
    void *arg;
} GPICallback;

typedef struct GPIProfileList {
    void *first;                      /* 0x00 */
    void *last;                       /* 0x04 */
    int numBuddies;                   /* 0x08 */
    void *cache;                      /* 0x0C */
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
    void *operationList;              /* 0x5C4 */
    GPIProfileList profileList;       /* 0x5C8 */
    void *peerList;                   /* 0x5D8 */
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

typedef struct GPIProfile {
    int profileId;                    /* 0x00 */
    int userId;                       /* 0x04 */
    struct GPIBuddyStatus *buddyStatus; /* 0x08 */
    void *buddyStatusInfo;            /* 0x0C */
    void *cache;                      /* 0x10 */
    char *authSig;                    /* 0x14 */
    int requestCount;                 /* 0x18 */
    char *peerSig;                    /* 0x1C */
    int blocked;                      /* 0x20 */
    int blockIndex;                   /* 0x24 */
    int buddyOrBlockCache;            /* 0x28 */
    int deletedLocally;               /* 0x2C */
} GPIProfile;

typedef struct GPIBuddyStatus {
    int buddyIndex;                   /* 0x00 */
    int status;                       /* 0x04 */
    char *statusString;               /* 0x08 */
    char *locationString;             /* 0x0C */
    unsigned int ip;                  /* 0x10 */
    unsigned short port;              /* 0x14 */
    int quietModeFlags;               /* 0x18 */
} GPIBuddyStatus;

typedef struct GPRecvBuddyMessageArg {
    int profileid;
    unsigned int date;
    char *message;
} GPRecvBuddyMessageArg;

typedef struct GPRecvBuddyUTMArg {
    int profileid;
    unsigned int date;
    char *message;
} GPRecvBuddyUTMArg;

typedef struct GPRecvBuddyRequestArg {
    int profileid;
    unsigned int date;
    char reason[1025];
} GPRecvBuddyRequestArg;

typedef struct GPRecvBuddyAuthArg {
    int profileid;
    unsigned int date;
} GPRecvBuddyAuthArg;

typedef struct GPRecvBuddyRevokeArg {
    int profileid;
    unsigned int date;
} GPRecvBuddyRevokeArg;

typedef struct GPRecvBuddyStatusArg {
    int profileid;
    unsigned int date;
    int buddyIndex;
} GPRecvBuddyStatusArg;

typedef struct GPRecvGameInviteArg {
    int profileid;
    int productID;
    char location[256];
} GPRecvGameInviteArg;

extern int gpiValueForKey(char *command, char *key, char *value, int len);
extern void gpiSetError(void **connection, int errorCode, char *errorString);
extern void gpiCallErrorCallback(void **connection, int result, int fatal);
extern int atoi(const char *s);
extern long gsiTimeNitro(long *timer);
extern void *gsimalloc(unsigned long size);
extern void gpiSetErrorString(void **connection, char *errorString);
extern unsigned long strlen(const char *s);
extern char *strcpy(char *dst, const char *src);
extern int gpiAddCallback(void **connection, GPICallback callback, void *arg,
                          void *operation, int type);
extern GPIProfile *gpiProfileListAdd(void **connection, int id);
extern char *strstr(const char *s, const char *t);
extern void gsifree(void *ptr);
extern char *goastrdup(char *src);
extern void strzcpy(char *dest, char *src, unsigned long len);
extern void gsDebugFormat(int theCat, int theType, int theLevel, char *theTokenStr,
                          int profileid);
extern void gpiRemoveBuddyStatusInfo(void *buddyStatusInfo);
extern unsigned long gsiSafeStrcpyA(char *dst, char *src, unsigned long size);
extern int gpiSendBuddyMessage(void **connection, int profileid, int type,
                               char *message, int sendOption, void *peerOp);
#include "../../matched/arm9_sdk/libc/string.h"

extern char g_021A4278[];             /* "\bm\"  */
extern char g_021A4280[];             /* "Unexpected data was received ..." */
extern char g_021A42B0[];             /* "\f\"  */
extern char g_021A42B4[];             /* "\date\" */
extern char g_021A42BC[];             /* "Out of memory." */
extern char g_021A42CC[];             /* "\msg\" */
extern char g_021A42D4[];             /* "|signed|" */
extern char g_021A42E0[];             /* "Deliberately ignoring ..." */
extern char g_021A437C[];             /* "|s|"  */
extern char g_021A4380[];             /* "|ss|" */
extern char g_021A4388[];             /* "|ls|" */
extern char g_021A4390[];             /* "|ip|" */
extern char g_021A4398[];             /* "|p|"  */
extern char g_021A439C[];             /* "|qm|" */
extern char g_021A43A4[];             /* "|l|"  */
extern char g_021A43A8[];             /* "1"    */

typedef enum _GPResult {
    GP_NO_ERROR,
    GP_MEMORY_ERROR,
    GP_PARAMETER_ERROR,
    GP_NETWORK_ERROR,
    GP_SERVER_ERROR,
    GP_MISC_ERROR,
    GP_COUNT
} GPResult;

#define Error(connection, result, errorString) \
{ \
    gpiSetErrorString(connection, errorString); \
    return (result); \
}

#define CallbackFatalError(connection, result, errorCode, errorString) \
{ \
    gpiSetError(connection, errorCode, errorString); \
    gpiCallErrorCallback(connection, result, 1); \
    return (result); \
}

#define freeclear(mem) { gsifree(mem); (mem) = 0; }

#define CHECK_RESULT(result) \
{ \
    GPResult __result__ = (result); \
    if (__result__ != GP_NO_ERROR) \
        return __result__; \
}

static GPResult gpiProcessRecvBuddyMessage(void **connection, char *input)
{
    char buffer[4096];
    int type;
    int profileid;
    long date;
    GPICallback callback;
    GPIProfile *profile;
    GPIBuddyStatus *buddyStatus;
    char intValue[16];
    char *str;
    unsigned short port;
    int productID;
    GPIConnection *iconnection = (GPIConnection *)*connection;
    char strTemp[256];

    if (!gpiValueForKey(input, g_021A4278, buffer, sizeof(buffer)))
        CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
    type = atoi(buffer);

    if (!gpiValueForKey(input, g_021A42B0, buffer, sizeof(buffer)))
        CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
    profileid = atoi(buffer);

    if (!gpiValueForKey(input, g_021A42B4, buffer, sizeof(buffer)))
        date = gsiTimeNitro(0);
    else
        date = atoi(buffer);

    switch (type) {
    case 1:
        callback = iconnection->callbacks[3];
        if (callback.fn != 0) {
            GPRecvBuddyMessageArg *arg;
            arg = (GPRecvBuddyMessageArg *)gsimalloc(sizeof(GPRecvBuddyMessageArg));
            if (arg == 0)
                Error(connection, GP_MEMORY_ERROR, g_021A42BC);
            if (!gpiValueForKey(input, g_021A42CC, buffer, sizeof(buffer)))
                CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
            arg->message = (char *)gsimalloc(strlen(buffer) + 1);
            if (arg->message == 0)
                Error(connection, GP_MEMORY_ERROR, g_021A42BC);
            strcpy(arg->message, buffer);
            arg->profileid = profileid;
            arg->date = (unsigned int)date;
            CHECK_RESULT(gpiAddCallback(connection, callback, arg, 0, 2));
        }
        break;

    case 5:
        callback = iconnection->callbacks[4];
        if (callback.fn != 0) {
            GPRecvBuddyUTMArg *arg;
            arg = (GPRecvBuddyUTMArg *)gsimalloc(sizeof(GPRecvBuddyUTMArg));
            if (arg == 0)
                Error(connection, GP_MEMORY_ERROR, g_021A42BC);
            if (!gpiValueForKey(input, g_021A42CC, buffer, sizeof(buffer)))
                CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
            arg->message = (char *)gsimalloc(strlen(buffer) + 1);
            if (arg->message == 0)
                Error(connection, GP_MEMORY_ERROR, g_021A42BC);
            strcpy(arg->message, buffer);
            arg->profileid = profileid;
            arg->date = (unsigned int)date;
            CHECK_RESULT(gpiAddCallback(connection, callback, arg, 0, 11));
        }
        break;

    case 2:
        profile = gpiProfileListAdd(connection, profileid);
        if (!profile)
            Error(connection, GP_MEMORY_ERROR, g_021A42BC);
        if (!gpiValueForKey(input, g_021A42CC, buffer, sizeof(buffer)))
            CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
        str = strstr(buffer, g_021A42D4);
        if (!str)
            CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
        *str = 0;
        str += 8;
        if (strlen(str) != 32)
            CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
        freeclear(profile->authSig);
        profile->authSig = goastrdup(str);
        profile->requestCount++;
        callback = iconnection->callbacks[1];
        if (callback.fn != 0) {
            GPRecvBuddyRequestArg *arg;
            arg = (GPRecvBuddyRequestArg *)gsimalloc(sizeof(GPRecvBuddyRequestArg));
            if (arg == 0)
                Error(connection, GP_MEMORY_ERROR, g_021A42BC);
            strzcpy(arg->reason, buffer, 1025);
            arg->profileid = profileid;
            arg->date = (unsigned int)date;
            CHECK_RESULT(gpiAddCallback(connection, callback, arg, 0, 6));
        }
        break;

    case 4:
        callback = iconnection->callbacks[7];
        if (callback.fn != 0) {
            GPRecvBuddyAuthArg *arg;
            arg = (GPRecvBuddyAuthArg *)gsimalloc(sizeof(GPRecvBuddyAuthArg));
            if (arg == 0)
                Error(connection, GP_MEMORY_ERROR, g_021A42BC);
            arg->profileid = profileid;
            arg->date = (unsigned int)date;
            CHECK_RESULT(gpiAddCallback(connection, callback, arg, 0, 10));
        }
        break;

    case 6:
        callback = iconnection->callbacks[8];
        if (callback.fn != 0) {
            GPRecvBuddyRevokeArg *arg;
            arg = (GPRecvBuddyRevokeArg *)gsimalloc(sizeof(GPRecvBuddyRevokeArg));
            if (arg == 0)
                Error(connection, GP_MEMORY_ERROR, g_021A42BC);
            arg->profileid = profileid;
            arg->date = (unsigned int)date;
            CHECK_RESULT(gpiAddCallback(connection, callback, arg, 0, 12));
        }
        break;

    case 100:
        profile = gpiProfileListAdd(connection, profileid);
        if (!profile)
            Error(connection, GP_MEMORY_ERROR, g_021A42BC);
        if (iconnection->connectState == 3 && profile->deletedLocally) {
            gsDebugFormat(1, 4, 2, g_021A42E0, profileid);
            break;
        }
        if (profile->blocked)
            break;
        if (!profile->buddyStatus) {
            profile->buddyStatus = (GPIBuddyStatus *)gsimalloc(sizeof(GPIBuddyStatus));
            if (!profile->buddyStatus)
                Error(connection, GP_MEMORY_ERROR, g_021A42BC);
            memset(profile->buddyStatus, 0, sizeof(GPIBuddyStatus));
            if (profile->buddyStatusInfo) {
                profile->buddyStatus->buddyIndex = *(int *)profile->buddyStatusInfo;
                gpiRemoveBuddyStatusInfo(profile->buddyStatusInfo);
                profile->buddyStatusInfo = 0;
            } else
                profile->buddyStatus->buddyIndex = iconnection->profileList.numBuddies++;
        }
        buddyStatus = profile->buddyStatus;

        if (!gpiValueForKey(input, g_021A42CC, buffer, sizeof(buffer)))
            CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);

        if (!gpiValueForKey(buffer, g_021A437C, intValue, sizeof(intValue)))
            CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
        buddyStatus->status = atoi(intValue);

        freeclear(buddyStatus->statusString);
        if (!gpiValueForKey(buffer, g_021A4380, strTemp, 256))
            strTemp[0] = 0;
        buddyStatus->statusString = goastrdup(strTemp);
        if (!buddyStatus->statusString)
            Error(connection, GP_MEMORY_ERROR, g_021A42BC);

        freeclear(buddyStatus->locationString);
        if (!gpiValueForKey(buffer, g_021A4388, strTemp, 256))
            strTemp[0] = 0;
        buddyStatus->locationString = goastrdup(strTemp);
        if (!buddyStatus->locationString)
            Error(connection, GP_MEMORY_ERROR, g_021A42BC);

        if (!gpiValueForKey(buffer, g_021A4390, intValue, sizeof(intValue)))
            buddyStatus->ip = 0;
        else
            buddyStatus->ip = (((unsigned int)atoi(intValue) >> 24) & 0xff) |
                              (((unsigned int)atoi(intValue) >> 8) & 0xff00) |
                              (((unsigned int)atoi(intValue) << 8) & 0xff0000) |
                              (((unsigned int)atoi(intValue) << 24) & 0xff000000);

        if (!gpiValueForKey(buffer, g_021A4398, intValue, sizeof(intValue)))
            buddyStatus->port = 0;
        else {
            port = (unsigned short)atoi(intValue);
            buddyStatus->port = (unsigned short)(((port >> 8) & 0xff) | ((port << 8) & 0xff00));
        }

        if (!gpiValueForKey(buffer, g_021A439C, intValue, sizeof(intValue)))
            buddyStatus->quietModeFlags = 0;
        else
            buddyStatus->quietModeFlags = atoi(intValue);

        callback = iconnection->callbacks[2];
        if (callback.fn != 0) {
            GPRecvBuddyStatusArg *arg;
            arg = (GPRecvBuddyStatusArg *)gsimalloc(sizeof(GPRecvBuddyStatusArg));
            if (arg == 0)
                Error(connection, GP_MEMORY_ERROR, g_021A42BC);
            arg->profileid = profileid;
            arg->buddyIndex = buddyStatus->buddyIndex;
            arg->date = (unsigned int)date;
            CHECK_RESULT(gpiAddCallback(connection, callback, arg, 0, 5));
        }
        break;

    case 101:
        if (!gpiValueForKey(input, g_021A42CC, buffer, sizeof(buffer)))
            CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
        str = strstr(buffer, g_021A4398);
        if (!str)
            CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
        str += 3;
        if (!*str)
            CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
        productID = atoi(str);
        str = strstr(buffer, g_021A43A4);
        if (str)
            strzcpy(strTemp, str + 3, 256);
        else
            strTemp[0] = 0;
        callback = iconnection->callbacks[5];
        if (callback.fn != 0) {
            GPRecvGameInviteArg *arg;
            arg = (GPRecvGameInviteArg *)gsimalloc(sizeof(GPRecvGameInviteArg));
            if (arg == 0)
                Error(connection, GP_MEMORY_ERROR, g_021A42BC);
            arg->profileid = profileid;
            arg->productID = productID;
            gsiSafeStrcpyA(arg->location, strTemp, 256);
            CHECK_RESULT(gpiAddCallback(connection, callback, arg, 0, 0));
        }
        break;

    case 102:
        if (!gpiValueForKey(input, g_021A42CC, buffer, sizeof(buffer)))
            CallbackFatalError(connection, GP_NETWORK_ERROR, 1, g_021A4280);
        gpiSendBuddyMessage(connection, profileid, 103, g_021A43A8, 0, 0);
        break;
    }

    return GP_NO_ERROR;
}
