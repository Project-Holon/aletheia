/*
 * function: func_021890E0
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
 *   func_02193734  0x02193734  arm   ov009
 *   func_0218946C  0x0218946C  arm   ov009
 *   func_0218949C  0x0218949C  arm   ov009
 *   func_02189300  0x02189300  arm   ov009
 *   func_0217EAE0  0x0217EAE0  arm   ov009
 *   func_0218FFFC  0x0218FFFC  arm   ov009
 *   func_021841B0  0x021841B0  arm   ov009
 *   func_021890A4  0x021890A4  arm   ov009
 *   g_021A446C     0x021A446C  data
 *   g_021A44AC     0x021A44AC  data
 *   g_021A424C     0x021A424C  data
 *   g_021A44B8     0x021A44B8  data
 *   g_021A4270     0x021A4270  data
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
extern void func_02193734(int *p, int b);
extern int func_0218946C(void **connection, GPIBuffer *outputBuffer, char *buffer);
extern int func_0218949C(void **connection, GPIBuffer *outputBuffer, int num);
extern int func_02189300(void **connection, int id, int isDeleted);
extern void func_0217EAE0(void *ptr);
extern int func_0218FFFC(void **connection, int (*func)(void **, GPIProfile *, void *), void *data);
extern void func_021841B0(void *array);
extern int func_021890A4(int unused, struct GPIProfile *profile, int baseIndex);
extern char g_021A446C[];
extern char g_021A44AC[];
extern char g_021A424C[];
extern char g_021A44B8[];
extern char g_021A4270[];

int func_021890E0(void **connection, int profile, int sendServerRequest)
{
    GPIProfile *pProfile;
    GPIConnection *iconnection = (GPIConnection *)*connection;
    int index;

    if (!func_0218FD9C(connection, profile, &pProfile)) {
        func_02193734((int *)connection, (int)g_021A446C);
        return 2;
    }

    if (sendServerRequest == 1) {
        func_0218946C(connection, &iconnection->outputBuffer, g_021A44AC);
        func_0218946C(connection, &iconnection->outputBuffer, g_021A424C);
        func_0218949C(connection, &iconnection->outputBuffer, iconnection->sessKey);
        func_0218946C(connection, &iconnection->outputBuffer, g_021A44B8);
        func_0218949C(connection, &iconnection->outputBuffer, pProfile->profileId);
        func_0218946C(connection, &iconnection->outputBuffer, g_021A4270);
    }
    func_02189300(connection, profile, 1);

    if (pProfile->buddyStatus) {
        index = pProfile->buddyStatus->buddyIndex;
        func_0217EAE0(pProfile->buddyStatus->statusString);
        pProfile->buddyStatus->statusString = 0;
        func_0217EAE0(pProfile->buddyStatus->locationString);
        pProfile->buddyStatus->locationString = 0;
        func_0217EAE0(pProfile->buddyStatus);
        pProfile->buddyStatus = 0;
        iconnection->numBuddies--;
        func_0218FFFC(connection, (int (*)(void **, GPIProfile *, void *))func_021890A4, (void *)index);
    }
    if (pProfile->buddyStatusInfo) {
        index = pProfile->buddyStatusInfo->buddyIndex;
        func_0217EAE0(pProfile->buddyStatusInfo->richStatus);
        pProfile->buddyStatusInfo->richStatus = 0;
        func_0217EAE0(pProfile->buddyStatusInfo->gameType);
        pProfile->buddyStatusInfo->gameType = 0;
        func_0217EAE0(pProfile->buddyStatusInfo->gameVariant);
        pProfile->buddyStatusInfo->gameVariant = 0;
        func_0217EAE0(pProfile->buddyStatusInfo->gameMapName);
        pProfile->buddyStatusInfo->gameMapName = 0;
        func_0217EAE0(pProfile->buddyStatusInfo);
        pProfile->buddyStatusInfo = 0;
        if (pProfile->buddyStatusInfo->extendedInfoKeys) {
            func_021841B0(pProfile->buddyStatusInfo->extendedInfoKeys);
            pProfile->buddyStatusInfo->extendedInfoKeys = 0;
        }
        iconnection->numBuddies--;
        func_0218FFFC(connection, (int (*)(void **, GPIProfile *, void *))func_021890A4, (void *)index);
    }
    return 0;
}
