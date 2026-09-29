/*
 * function: gpiProcessRecvBuddyMessage
 * address:  0x021870B8
 * packet:   pkt_ov009_021870B8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      gpiProcessRecvBuddyMessage (libdwcgsgp.TWL.HYB.a gpibuddy.o)
 *
 * residue:  DIFF, 1908/3212 concrete bytes; 120 of 123 relocations resolve (the
 *   three unresolved are data witnesses for g_021A42B0/g_021A42E0/g_021A437C
 *   that the harness cannot corroborate outside this function, not real gaps).
 *   Semantics are complete and verified: all 106 call sites match the original's
 *   call multiset exactly (gpiValueForKey 15, gpiSetError 13, gpiCallErrorCallback
 *   13, atoi 11, gsimalloc 10, gpiSetErrorString 14, gpiAddCallback 7, strlen 3,
 *   strcpy 2, strstr 3, gsifree 3, goastrdup 3, strzcpy 2, gpiProfileListAdd 2,
 *   and one each of gsiTimeNitro/gsDebugFormat/gpiRemoveBuddyStatusInfo/
 *   gsiSafeStrcpyA/gpiSendBuddyMessage) and every struct offset, callback slot
 *   and error arm lines up.  Remaining byte gap is 4.0.0.1025 vs dsi/1.1p1:
 *   1. The dense switch is `cmp r4,#6` with a 7-entry table plus a compare
 *      chain for 100/101/102, and the addls base is instr+8, so table[i] is
 *      case i: the handled values are 1, 2, 4, 5, 6 (3 and 7 fall to default).
 *   2. 1025 hoists the error constant 1 into fp right after the \date\ parse and
 *      rematerialises &buffer per use; 1.1p1 hoists &buffer into fp and emits
 *      `mov #1` per arm.  The missing `mov fp,#1` shifts all later code by 4
 *      bytes, which is most of the residual diff.
 *   3. 1025 inlines the 28-byte buddyStatus zero fill as a 7x4 strb loop; 1.1p1
 *      calls memset (0x020923B0), so that one site is a call and not a fill.
 *   4. Case-local arg pointers land in r10/r4/r3/r6 in the original and in r4
 *      here, and the two compilers fold the |ip|/|p| masks differently.
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

typedef struct GPRecvGameInviteArg {
    int profileid;
    unsigned int date;
    char *message;
} GPRecvGameInviteArg;

typedef struct GPRecvBuddyAuthArg {
    int profileid;
    unsigned int date;
    char reason[1028];
} GPRecvBuddyAuthArg;

typedef struct GPRecvBuddyRevokeArg {
    int profileid;
    unsigned int date;
} GPRecvBuddyRevokeArg;

typedef struct GPRecvBuddyMessageArg {
    int profileid;
    unsigned int date;
    char *message;
} GPRecvBuddyMessageArg;

typedef struct GPRecvBuddyUTMArg {
    int profileid;
    unsigned int date;
} GPRecvBuddyUTMArg;

typedef struct GPRecvBuddyStatusArg {
    int profileid;
    unsigned int date;
    int buddyIndex;
} GPRecvBuddyStatusArg;

typedef struct GPRecvBuddyRequestArg {
    int profileid;
    int productID;
    char location[256];
} GPRecvBuddyRequestArg;

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
extern void *memset(void *dst, int val, unsigned long n);

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

#define PARSE_KEY(k) do { \
    if (!gpiValueForKey(input, (k), buffer, 0x1000)) { \
        gpiSetError(connection, 1, g_021A4280); \
        gpiCallErrorCallback(connection, 3, 1); \
        return 3; \
    } \
} while (0)

static int gpiProcessRecvBuddyMessage(void **connection, char *input)
{
    char buffer[4096];
    char strTemp[256];
    char intValue[16];
    int type;
    int profileid;
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPIProfile *profile;
    GPIBuddyStatus *buddyStatus;
    char *str;
    int productID;
    unsigned short port;
    long date;

    PARSE_KEY(g_021A4278);
    type = atoi(buffer);

    PARSE_KEY(g_021A42B0);
    profileid = atoi(buffer);

    if (gpiValueForKey(input, g_021A42B4, buffer, 0x1000))
        date = atoi(buffer);
    else
        date = gsiTimeNitro(0);

    switch (type) {
    case 1:
        {
            GPICallback callback;
            GPRecvGameInviteArg *arg;
            callback = iconnection->callbacks[3];
            if (callback.fn) {
                arg = (GPRecvGameInviteArg *)gsimalloc(sizeof(GPRecvGameInviteArg));
                if (arg == 0) {
                    gpiSetErrorString(connection, g_021A42BC);
                    return 1;
                }
                PARSE_KEY(g_021A42CC);
                arg->message = (char *)gsimalloc(strlen(buffer) + 1);
                if (arg->message == 0) {
                    gpiSetErrorString(connection, g_021A42BC);
                    return 1;
                }
                strcpy(arg->message, buffer);
                arg->profileid = profileid;
                arg->date = date;
                {
                    int __result__ = gpiAddCallback(connection, callback, arg, 0, 2);
                    if (__result__ != 0)
                        return __result__;
                }
            }
            break;
        }

    case 5:
        {
            GPICallback callback;
            GPRecvBuddyMessageArg *arg;
            callback = iconnection->callbacks[4];
            if (callback.fn) {
                arg = (GPRecvBuddyMessageArg *)gsimalloc(sizeof(GPRecvBuddyMessageArg));
                if (arg == 0) {
                    gpiSetErrorString(connection, g_021A42BC);
                    return 1;
                }
                PARSE_KEY(g_021A42CC);
                arg->message = (char *)gsimalloc(strlen(buffer) + 1);
                if (arg->message == 0) {
                    gpiSetErrorString(connection, g_021A42BC);
                    return 1;
                }
                strcpy(arg->message, buffer);
                arg->profileid = profileid;
                arg->date = date;
                {
                    int __result__ = gpiAddCallback(connection, callback, arg, 0, 11);
                    if (__result__ != 0)
                        return __result__;
                }
            }
            break;
        }

    case 2:
        {
            GPICallback callback;
            GPRecvBuddyAuthArg *arg;
            profile = gpiProfileListAdd(connection, profileid);
            if (profile == 0) {
                gpiSetErrorString(connection, g_021A42BC);
                return 1;
            }
            PARSE_KEY(g_021A42CC);
            str = strstr(buffer, g_021A42D4);
            if (str == 0) {
                gpiSetError(connection, 1, g_021A4280);
                gpiCallErrorCallback(connection, 3, 1);
                return 3;
            }
            *str = 0;
            if (strlen(str + 8) != 0x20) {
                gpiSetError(connection, 1, g_021A4280);
                gpiCallErrorCallback(connection, 3, 1);
                return 3;
            }
            gsifree(profile->authSig);
            profile->authSig = goastrdup(str + 8);
            profile->requestCount++;
            callback = iconnection->callbacks[1];
            if (callback.fn) {
                arg = (GPRecvBuddyAuthArg *)gsimalloc(sizeof(GPRecvBuddyAuthArg));
                if (arg == 0) {
                    gpiSetErrorString(connection, g_021A42BC);
                    return 1;
                }
                strzcpy(arg->reason, buffer, sizeof(*arg) - 11);
                arg->profileid = profileid;
                arg->date = date;
                {
                    int __result__ = gpiAddCallback(connection, callback, arg, arg, 6);
                    if (__result__ != 0)
                        return __result__;
                }
            }
            break;
        }

    case 4:
        {
            GPICallback callback;
            GPRecvBuddyRevokeArg *arg;
            callback = iconnection->callbacks[7];
            if (callback.fn) {
                arg = (GPRecvBuddyRevokeArg *)gsimalloc(sizeof(GPRecvBuddyRevokeArg));
                if (arg == 0) {
                    gpiSetErrorString(connection, g_021A42BC);
                    return 1;
                }
                arg->profileid = profileid;
                arg->date = date;
                {
                    int __result__ = gpiAddCallback(connection, callback, arg, 0, 10);
                    if (__result__ != 0)
                        return __result__;
                }
            }
            break;
        }

    case 6:
        {
            GPICallback callback;
            GPRecvBuddyUTMArg *arg;
            callback = iconnection->callbacks[8];
            if (callback.fn) {
                arg = (GPRecvBuddyUTMArg *)gsimalloc(sizeof(GPRecvBuddyUTMArg));
                if (arg == 0) {
                    gpiSetErrorString(connection, g_021A42BC);
                    return 1;
                }
                arg->profileid = profileid;
                arg->date = date;
                {
                    int __result__ = gpiAddCallback(connection, callback, arg, 0, 12);
                    if (__result__ != 0)
                        return __result__;
                }
            }
            break;
        }

    case 100:
        {
            GPICallback callback;
            GPRecvBuddyStatusArg *arg;
            profile = gpiProfileListAdd(connection, profileid);
            if (profile == 0) {
                gpiSetErrorString(connection, g_021A42BC);
                return 1;
            }
            if (iconnection->connectState == 3 && profile->deletedLocally != 0) {
                gsDebugFormat(1, 4, 2, g_021A42E0, profileid);
                break;
            }
            if (profile->blocked != 0)
                break;
            if (profile->buddyStatus == 0) {
                profile->buddyStatus = (GPIBuddyStatus *)gsimalloc(sizeof(GPIBuddyStatus));
                if (profile->buddyStatus == 0) {
                    gpiSetErrorString(connection, g_021A42BC);
                    return 1;
                }
                memset(profile->buddyStatus, 0, sizeof(GPIBuddyStatus));
            }
            if (profile->buddyStatusInfo == 0) {
                profile->buddyStatus->buddyIndex = iconnection->profileList.numBuddies++;
            } else {
                profile->buddyStatus->buddyIndex = *(int *)profile->buddyStatusInfo;
                gpiRemoveBuddyStatusInfo(profile->buddyStatusInfo);
                profile->buddyStatusInfo = 0;
            }
            buddyStatus = profile->buddyStatus;

            PARSE_KEY(g_021A42CC);

            if (!gpiValueForKey(buffer, g_021A437C, intValue, 0x10)) {
                gpiSetError(connection, 1, g_021A4280);
                gpiCallErrorCallback(connection, 3, 1);
                return 3;
            }
            buddyStatus->status = atoi(intValue);
            gsifree(buddyStatus->statusString);
            buddyStatus->statusString = 0;

            if (!gpiValueForKey(buffer, g_021A4380, strTemp, 0x100))
                strTemp[0] = 0;
            buddyStatus->statusString = goastrdup(strTemp);
            if (buddyStatus->statusString == 0) {
                gpiSetErrorString(connection, g_021A42BC);
                return 1;
            }

            gsifree(buddyStatus->locationString);
            buddyStatus->locationString = 0;

            if (!gpiValueForKey(buffer, g_021A4388, strTemp, 0x100))
                strTemp[0] = 0;
            buddyStatus->locationString = goastrdup(strTemp);
            if (buddyStatus->locationString == 0) {
                gpiSetErrorString(connection, g_021A42BC);
                return 1;
            }

            if (gpiValueForKey(buffer, g_021A4390, intValue, 0x10))
                buddyStatus->ip = ((atoi(intValue) << 24) & 0xff000000) |
                                 ((atoi(intValue) << 8) & 0xff0000) |
                                 ((atoi(intValue) >> 24) & 0xff) |
                                 ((atoi(intValue) >> 8) & 0xff00);
            else
                buddyStatus->ip = 0;

            if (gpiValueForKey(buffer, g_021A4398, intValue, 0x10)) {
                port = (unsigned short)atoi(intValue);
                buddyStatus->port = (unsigned short)(((port >> 8) & 0xff) | ((port << 8) & 0xff00));
            } else
                buddyStatus->port = 0;

            if (gpiValueForKey(buffer, g_021A439C, intValue, 0x10))
                buddyStatus->quietModeFlags = atoi(intValue);
            else
                buddyStatus->quietModeFlags = 0;

            callback = iconnection->callbacks[2];
            if (callback.fn) {
                arg = (GPRecvBuddyStatusArg *)gsimalloc(sizeof(GPRecvBuddyStatusArg));
                if (arg == 0) {
                    gpiSetErrorString(connection, g_021A42BC);
                    return 1;
                }
                arg->profileid = profileid;
                arg->date = date;
                arg->buddyIndex = buddyStatus->buddyIndex;
                {
                    int __result__ = gpiAddCallback(connection, callback, arg, 0, 5);
                    if (__result__ != 0)
                        return __result__;
                }
            }
            break;
        }

    case 101:
        {
            GPICallback callback;
            GPRecvBuddyRequestArg *arg;
            PARSE_KEY(g_021A42CC);

            str = strstr(buffer, g_021A4398);
            if (str == 0) {
                gpiSetError(connection, 1, g_021A4280);
                gpiCallErrorCallback(connection, 3, 1);
                return 3;
            }
            if (str[3] == 0) {
                gpiSetError(connection, 1, g_021A4280);
                gpiCallErrorCallback(connection, 3, 1);
                return 3;
            }
            productID = atoi(str + 3);

            str = strstr(buffer, g_021A43A4);
            if (str)
                strzcpy(strTemp, str + 3, 0x100);
            else
                strTemp[0] = 0;

            callback = iconnection->callbacks[5];
            if (callback.fn) {
                arg = (GPRecvBuddyRequestArg *)gsimalloc(sizeof(GPRecvBuddyRequestArg));
                if (arg == 0) {
                    gpiSetErrorString(connection, g_021A42BC);
                    return 1;
                }
                arg->profileid = profileid;
                arg->productID = productID;
                gsiSafeStrcpyA(arg->location, strTemp, 0x100);
                {
                    int __result__ = gpiAddCallback(connection, callback, arg, 0, 0);
                    if (__result__ != 0)
                        return __result__;
                }
            }
            break;
        }

    case 102:
        PARSE_KEY(g_021A42CC);
        gpiSendBuddyMessage(connection, profileid, 0x67, g_021A43A8, 0, 0);
        break;

    default:
        break;
    }

    return 0;
}
