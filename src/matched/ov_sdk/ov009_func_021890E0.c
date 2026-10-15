/*
 * function: gpiDeleteBuddy
 * address:  0x021890E0
 * packet:   pkt_ov009_021890E0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiDeleteBuddy (gpibuddy.o)
 *
 * symbols:
 *   func_0218FD9C  0x0218FD9C  arm   ov009
 *   gpiSetErrorString  0x02193734  arm   ov009
 *   gpiAppendStringToBuffer  0x0218946C  arm   ov009
 *   gpiAppendIntToBuffer  0x0218949C  arm   ov009
 *   gpiBuddyDeletedLocally  0x02189300  arm   ov009
 *   gsifree  0x0217EAE0  arm   ov009
 *   func_0218FFFC  0x0218FFFC  arm   ov009
 *   func_021841B0  0x021841B0  arm   ov009
 *   gpiFixBuddyIndices  0x021890A4  arm   ov009
 *   gGpiBuddyErrorInvalidProfile     0x021A446C  data
 *   gGpiBuddyKeyDelBuddy     0x021A44AC  data
 *   gGpiBuddyKeySessKey     0x021A424C  data
 *   gGpiBuddyKeyDelProfileId     0x021A44B8  data
 *   gGpiBuddyKeyFinal     0x021A4270  data
 *
 * The object frees buddyStatusInfo, clears the pointer, then reads
 * extendedInfoKeys through it; the C keeps that order.
 */

typedef struct GPIBuffer {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer;

typedef struct GPIBuddyStatus {
    int buddyIndex;
    int status;
    char *statusString;
    char *locationString;
} GPIBuddyStatus;

typedef struct GPIBuddyStatusInfo {
    int buddyIndex;
    int statusState;
    char *richStatus;
    char *gameType;
    char *gameVariant;
    char *gameMapName;
    char pad18[0x38 - 0x18];
    void *extendedInfoKeys;
} GPIBuddyStatusInfo;

typedef struct GPIProfile {
    int profileId;
    int userId;
    GPIBuddyStatus *buddyStatus;
    GPIBuddyStatusInfo *buddyStatusInfo;
} GPIProfile;

typedef struct GPIConnection {
    char pad0[0x198];
    int sessKey;
    char pad19c[0x210 - 0x19c];
    GPIBuffer outputBuffer;
    char pad220[0x5d0 - 0x220];
    int numBuddies;
} GPIConnection;

extern int func_0218FD9C(void **connection, int profileid, GPIProfile **pProfile);
extern void gpiSetErrorString(int *p, int b);
extern int gpiAppendStringToBuffer(int *connection, int *buffer, const char *string);
extern int gpiAppendIntToBuffer(int *connection, int *buffer, int value);
extern int gpiBuddyDeletedLocally(void **connection, int id, int isDeleted);
extern void gsifree(void *ptr);
extern int func_0218FFFC(void **connection, int (*func)(void **, GPIProfile *, void *), void *data);
extern void func_021841B0(void *array);
extern int gpiFixBuddyIndices(int unused, struct GPIProfile *profile, int baseIndex);
extern char gGpiBuddyErrorInvalidProfile[];
extern char gGpiBuddyKeyDelBuddy[];
extern char gGpiBuddyKeySessKey[];
extern char gGpiBuddyKeyDelProfileId[];
extern char gGpiBuddyKeyFinal[];

int gpiDeleteBuddy(void **connection, int profile, int sendServerRequest)
{
    GPIProfile *pProfile;
    GPIConnection *iconnection = (GPIConnection *)*connection;
    int index;

    if (!func_0218FD9C(connection, profile, &pProfile)) {
        gpiSetErrorString((int *)connection, (int)gGpiBuddyErrorInvalidProfile);
        return 2;
    }

    if (sendServerRequest == 1) {
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), gGpiBuddyKeyDelBuddy);
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), gGpiBuddyKeySessKey);
        gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->sessKey);
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), gGpiBuddyKeyDelProfileId);
        gpiAppendIntToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), pProfile->profileId);
        gpiAppendStringToBuffer((int *)connection, (int *)(&iconnection->outputBuffer), gGpiBuddyKeyFinal);
    }
    gpiBuddyDeletedLocally(connection, profile, 1);

    if (pProfile->buddyStatus) {
        index = pProfile->buddyStatus->buddyIndex;
        gsifree(pProfile->buddyStatus->statusString);
        pProfile->buddyStatus->statusString = 0;
        gsifree(pProfile->buddyStatus->locationString);
        pProfile->buddyStatus->locationString = 0;
        gsifree(pProfile->buddyStatus);
        pProfile->buddyStatus = 0;
        iconnection->numBuddies--;
        func_0218FFFC(connection, (int (*)(void **, GPIProfile *, void *))gpiFixBuddyIndices, (void *)index);
    }
    if (pProfile->buddyStatusInfo) {
        index = pProfile->buddyStatusInfo->buddyIndex;
        gsifree(pProfile->buddyStatusInfo->richStatus);
        pProfile->buddyStatusInfo->richStatus = 0;
        gsifree(pProfile->buddyStatusInfo->gameType);
        pProfile->buddyStatusInfo->gameType = 0;
        gsifree(pProfile->buddyStatusInfo->gameVariant);
        pProfile->buddyStatusInfo->gameVariant = 0;
        gsifree(pProfile->buddyStatusInfo->gameMapName);
        pProfile->buddyStatusInfo->gameMapName = 0;
        gsifree(pProfile->buddyStatusInfo);
        pProfile->buddyStatusInfo = 0;
        if (pProfile->buddyStatusInfo->extendedInfoKeys) {
            func_021841B0(pProfile->buddyStatusInfo->extendedInfoKeys);
            pProfile->buddyStatusInfo->extendedInfoKeys = 0;
        }
        iconnection->numBuddies--;
        func_0218FFFC(connection, (int (*)(void **, GPIProfile *, void *))gpiFixBuddyIndices, (void *)index);
    }
    return 0;
}
