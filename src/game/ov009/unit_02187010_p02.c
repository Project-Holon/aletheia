/*
 * file:     unit_02187010_p02.c
 * unit:     yes
 * function: gpiProcessRecvBuddyStatusInfo, func_02188638, func_021888C0, func_021889A0
 * address:  0x02187D60
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gsiTimeNitro                  0x02184098 arm ov009
 *   gpiValueForKey                0x02193418 arm ov009
 *   gpiSetError                   0x02193710 arm ov009
 *   gpiCallErrorCallback          0x02189D78 arm ov009
 *   atoi                          0x020964E0 arm
 *   gpiProfileListAdd             0x0218FCD8 arm ov009
 *   gpiSetErrorString             0x02193734 arm ov009
 *   gsimalloc                     0x0217EAB0 arm ov009
 *   memset                        0x020923B0 arm
 *   gpiRemoveBuddyStatus          0x021900BC arm ov009
 *   ArrayNew                      0x02184144 arm ov009
 *   gsifree                       0x0217EAE0 arm ov009
 *   goastrdup                     0x0217F1E0 arm ov009
 *   gpiAddCallback                0x02189DFC arm ov009
 *   g_021A43AC                    0x021A43AC data
 *   g_021A4280                    0x021A4280 data
 *   g_021A42BC                    0x021A42BC data
 *   g_021A43B8                    0x021A43B8 data
 *   g_021A43C0                    0x021A43C0 data
 *   g_021A43C8                    0x021A43C8 data
 *   g_021A43D0                    0x021A43D0 data
 *   g_021A43DC                    0x021A43DC data
 *   g_021A43E8                    0x021A43E8 data
 *   g_021A43F0                    0x021A43F0 data
 *   g_021A43F8                    0x021A43F8 data
 *   g_021A4404                    0x021A4404 data
 *   g_021A4410                    0x021A4410 data
 *   g_021A441C                    0x021A441C data
 *   g_021A4428                    0x021A4428 data
 *   g_021A4434                    0x021A4434 data
 *   g_021A4440                    0x021A4440 data
 *   func_0219329C  0x0219329C  arm   ov009
 *   func_02193378  0x02193378  arm   ov009
 *   func_02193710  0x02193710  arm   ov009
 *   func_02189D78  0x02189D78  arm   ov009
 *   func_020964E0  0x020964E0  arm
 *   func_02094B20  0x02094B20  arm
 *   func_0218FCD8  0x0218FCD8  arm   ov009
 *   func_02193734  0x02193734  arm   ov009
 *   func_0217EAB0  0x0217EAB0  arm   ov009
 *   func_02189300  0x02189300  arm   ov009
 *   g_021A4450     0x021A4450  data
 *   g_021A4458     0x021A4458  data
 *   g_021A4460     0x021A4460  data
 *   func_0219327C  0x0219327C  arm   ov009
 *   func_0218946C  0x0218946C  arm   ov009
 *   func_0218949C  0x0218949C  arm   ov009
 *   g_021A4278     0x021A4278  data  ov009
 *   g_021A424C     0x021A424C  data  ov009
 *   g_021A4464     0x021A4464  data  ov009
 *   g_021A42CC     0x021A42CC  data  ov009
 *   g_021A4270     0x021A4270  data  ov009
 *   func_0218F0B8  0x0218F0B8  arm   ov009
 *   func_0218FD9C  0x0218FD9C  arm   ov009
 *   func_0218F150  0x0218F150  arm   ov009
 *   func_0218F1E0  0x0218F1E0  arm   ov009
 *   func_0218F248  0x0218F248  arm   ov009
 *   func_0218F884  0x0218F884  arm   ov009
 *   func_0218F350  0x0218F350  arm   ov009
 */
typedef struct GPIBuddyStatusInfo_02187D60 {
    int unk0;
    int unk4;
    char *unk8;
    char *unkc;
    char *unk10;
    char *unk14;
    int unk18;
    unsigned int unk1c;
    unsigned short unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned short unk2c;
    unsigned short unk2e;
    int unk30;
    int unk34;
    void *unk38;
} GPIBuddyStatusInfo_02187D60;

typedef struct GPIProfile {
    char pad0[8];
    GPIBuddyStatusInfo_02187D60 *unk8;
    GPIBuddyStatusInfo_02187D60 *unkc;
    char pad10[0x10];
    int unk20;
    char pad24[8];
    int unk2c;
} GPIProfile;

typedef struct GPICallback {
    void (*fn)(void *, void *);
    void *arg;
} GPICallback;

typedef struct GPIConnection {
    char pad0[0x1b8];
    GPICallback callback;
    char pad1[0x5d0 - 0x1c0];
    int numBuddies;
} GPIConnection;

typedef struct GPRecvBuddyStatusArg {
    int profileid;
    long date;
    int buddyIndex;
} GPRecvBuddyStatusArg;

typedef struct GPIBuddyStatus {
    int buddyIndex;
    int status;
    char *statusString;
    char *locationString;
    unsigned int ip;
    int port;
    int quietModeFlags;
} GPIBuddyStatus;

typedef struct GPIProfile_02188638 {
    int profileId;
    int userId;
    GPIBuddyStatus *buddyStatus;
} GPIProfile_02188638;

typedef struct GPIConnection_02188638 {
    char pad0[0x5d0];
    int numBuddies;
} GPIConnection_02188638;

typedef struct GPIConnection_021888C0 {
    unsigned char pad0[0x198];
    int f198;
    unsigned char pad1[0x210 - 0x19C];
    unsigned char outputBuffer[0x10];
} GPIConnection_021888C0;

typedef enum { GP_NO_ERROR, GP_MEMORY_ERROR, GP_PARAMETER_ERROR, GP_NETWORK_ERROR } GPResult;

typedef struct GPIPeer {
    int state;
} GPIPeer;

typedef struct GPIPeerOp GPIPeerOp;

typedef struct GPIBuddyStatusInfo_02187010 {
    char pad0[0x20];
    unsigned short f20;
} GPIBuddyStatusInfo_02187010;

typedef struct GPIProfile_021889A0 {
    char pad0[0xc];
    GPIBuddyStatusInfo_02187010 *buddyStatus;
    char pad1[0x1c - 0x10];
    int f1C;
} GPIProfile_021889A0;

extern long gsiTimeNitro(long *timer);
extern int gpiValueForKey(char *command, char *key, char *value, int len);
extern void gpiSetError(void **connection, int errorCode, char *errorString);
extern void gpiCallErrorCallback(void **connection, int result, int fatal);
extern int atoi(const char *s);
extern GPIProfile *gpiProfileListAdd(void **connection, int id);
extern void gpiSetErrorString(void **connection, char *errorString);
extern void *gsimalloc(unsigned long size);
extern void memset(void *dst, int val, unsigned long n);
extern void gpiRemoveBuddyStatus(void *buddyStatus);
extern void *ArrayNew(int elemSize, int numElemsToAllocate, void (*elemFreeFn)(void *));
extern void gsifree(void *ptr);
extern char *goastrdup(char *src);
extern int gpiAddCallback(void **connection, GPICallback callback, void *arg,
                          void *operation, int type);
extern void gpiStatusInfoKeyFree(void *ptr);
extern int func_0219329C(void **connection, char *input, int callErrorCallback);
extern int func_02193378(char *command, char *key, int *index, char *value, int len);
extern void func_02193710(void **connection, int errorCode, char *errorString);
extern void func_02189D78(void **connection, int result, int fatal);
extern int func_020964E0(const char *s);
extern char *func_02094B20(const char *s, const char *sub);
extern GPIProfile_02188638 *func_0218FCD8(void **connection, int id);
extern void func_02193734(void **connection, char *errorString);
extern void *func_0217EAB0(unsigned long size);
extern int func_02189300(void **connection, int id, int isDeleted);
extern void func_0219327C(char *p, int b, int n);
extern int func_0218946C(int *connection, int *buffer, const char *string);
extern int func_0218949C(int *connection, int *buffer, int value);
extern char *func_0218F0B8(void **p, int v);
extern int func_0218FD9C(void **connection, int profileid, GPIProfile_021889A0 **pProfile);
extern GPIPeer *func_0218F150(void **connection, int profileid, int initiate);
extern GPResult func_0218F1E0(void **connection, GPIPeer *peer);
extern GPResult func_0218F248(void **connection, GPIPeer *peer);
extern void func_0218F884(GPIPeer *peer, GPIPeerOp *operation);
extern GPResult func_0218F350(void **connection, GPIPeer *peer, int type, char *message);
/*
 * sdk: gpiProcessRecvBuddyList (gpibuddy.o) * * The 28-byte byte-store zero loop after gsimalloc is __builtin__clear on * the new GPIBuddyStatus (no memset call in the object).
 */
int func_02188638(void **connection, char *input);
/*
 * sdk: gpiSendServerBuddyMessage (gpibuddy.o)
 */
int func_021888C0(void **connection, int profileid, int type, char *message);
GPResult func_021889A0(void **connection, int profileid, int type, char *message, int sendOption, GPIPeerOp *peerOp);
extern char g_021A43AC[];
extern char g_021A4280[];
extern char g_021A42BC[];
extern char g_021A43B8[];
extern char g_021A43C0[];
extern char g_021A43C8[];
extern char g_021A43D0[];
extern char g_021A43DC[];
extern char g_021A43E8[];
extern char g_021A43F0[];
extern char g_021A43F8[];
extern char g_021A4404[];
extern char g_021A4410[];
extern char g_021A441C[];
extern char g_021A4428[];
extern char g_021A4434[];
extern char g_021A4440[];
extern char g_021A4450[];
extern char g_021A4458[];
extern char g_021A4460[];
extern char g_021A4278[];
extern char g_021A424C[];
extern char g_021A4464[];
extern char g_021A42CC[];
extern char g_021A4270[];


#define PARSE_KEY(k) do { \
    if (!gpiValueForKey(input, (k), buffer, 0x400)) { \
        gpiSetError(connection, 1, g_021A4280); \
        gpiCallErrorCallback(connection, 3, 1); \
        return 3; \
    } \
} while (0)


static int gpiProcessRecvBuddyStatusInfo(void **connection, char *input)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    char buffer[1024];
    int flag = 0;
    int rc;
    int profileid;
    long date;
    GPIProfile *profile;
    GPIBuddyStatusInfo_02187D60 *buddyStatus;
    GPICallback callback;
    GPRecvBuddyStatusArg *anArg;

    date = gsiTimeNitro(0);

    PARSE_KEY(g_021A43AC);
    profileid = atoi(buffer);
    profile = gpiProfileListAdd(connection, profileid);
    if (profile == 0) {
        gpiSetErrorString(connection, g_021A42BC);
        return 1;
    }
    if (profile->unk20 == 0 && profile->unk2c == 0) {

    if (profile->unkc == 0) {
        profile->unkc = (GPIBuddyStatusInfo_02187D60 *)gsimalloc(0x3c);
        if (profile->unkc == 0) {
            gpiSetErrorString(connection, g_021A42BC);
            return 1;
        }
        memset(profile->unkc, 0, 0x3c);
        if (profile->unk8 != 0) {
            profile->unkc->unk0 = *(int *)profile->unk8;
            gpiRemoveBuddyStatus((void *)profile->unk8);
            profile->unk8 = 0;
        } else {
            profile->unkc->unk0 = iconnection->numBuddies++;
        }
        flag = 1;
        profile->unkc->unk38 = ArrayNew(8, 1, gpiStatusInfoKeyFree);
        if (profile->unkc->unk38 == 0) {
            gpiSetErrorString(connection, g_021A42BC);
            return flag;
        }
    }

    buddyStatus = profile->unkc;

    PARSE_KEY(g_021A43B8);
    buddyStatus->unk4 = atoi(buffer);

    PARSE_KEY(g_021A43C0);
    buddyStatus->unk1c = (((unsigned int)atoi(buffer) >> 24) & 0xff) |
                         (((unsigned int)atoi(buffer) >> 8) & 0xff00) |
                         (((unsigned int)atoi(buffer) << 8) & 0xff0000) |
                         (((unsigned int)atoi(buffer) << 24) & 0xff000000);

    PARSE_KEY(g_021A43C8);
    buddyStatus->unk20 = (unsigned short)atoi(buffer);

    PARSE_KEY(g_021A43D0);
    buddyStatus->unk24 = (((unsigned int)atoi(buffer) >> 24) & 0xff) |
                         (((unsigned int)atoi(buffer) >> 8) & 0xff00) |
                         (((unsigned int)atoi(buffer) << 8) & 0xff0000) |
                         (((unsigned int)atoi(buffer) << 24) & 0xff000000);

    PARSE_KEY(g_021A43DC);
    buddyStatus->unk28 = (((unsigned int)atoi(buffer) >> 24) & 0xff) |
                         (((unsigned int)atoi(buffer) >> 8) & 0xff00) |
                         (((unsigned int)atoi(buffer) << 8) & 0xff0000) |
                         (((unsigned int)atoi(buffer) << 24) & 0xff000000);

    PARSE_KEY(g_021A43E8);
    buddyStatus->unk2c = (unsigned short)atoi(buffer);

    PARSE_KEY(g_021A43F0);
    buddyStatus->unk2e = (unsigned short)atoi(buffer);

    PARSE_KEY(g_021A43F8);
    buddyStatus->unk18 = atoi(buffer);
    gsifree(buddyStatus->unk8);
    buddyStatus->unk8 = 0;

    PARSE_KEY(g_021A4404);
    buddyStatus->unk8 = goastrdup(buffer);
    gsifree(buddyStatus->unkc);
    buddyStatus->unkc = 0;

    PARSE_KEY(g_021A4410);
    buddyStatus->unkc = goastrdup(buffer);
    gsifree(buddyStatus->unk10);
    buddyStatus->unk10 = 0;

    PARSE_KEY(g_021A441C);
    buddyStatus->unk10 = goastrdup(buffer);
    gsifree(buddyStatus->unk14);
    buddyStatus->unk14 = 0;

    PARSE_KEY(g_021A4428);
    buddyStatus->unk14 = goastrdup(buffer);

    PARSE_KEY(g_021A4434);
    buddyStatus->unk34 = atoi(buffer);

    PARSE_KEY(g_021A4440);
    buddyStatus->unk30 = atoi(buffer);

    callback = iconnection->callback;
    if (callback.fn != 0) {
        anArg = (GPRecvBuddyStatusArg *)gsimalloc(0xc);
        if (anArg == 0) {
            gpiSetErrorString(connection, g_021A42BC);
            return 1;
        }
        anArg->date = date;
        anArg->buddyIndex = buddyStatus->unk0;
        anArg->profileid = profileid;
        rc = gpiAddCallback(connection, callback, anArg, 0, 0);
        if (rc != 0)
            return rc;
    }
    }
    return 0;
}



/*
 * sdk:      gpiProcessRecvBuddyList (gpibuddy.o)
 *
 * The 28-byte byte-store zero loop after gsimalloc is __builtin__clear on
 * the new GPIBuddyStatus (no memset call in the object).
 */
int func_02188638(void **connection, char *input)
{
    int i;
    int num;
    unsigned int j;
    int index = 0;
    char c;
    char *str;
    char buffer[512];
    GPIProfile_02188638 *profile;
    int profileid;
    GPIConnection_02188638 *iconnection = (GPIConnection_02188638 *)*connection;

    if (func_0219329C(connection, input, 1))
        return 4;

    if (!func_02193378(input, g_021A4450, &index, buffer, sizeof(buffer))) {
        func_02193710(connection, 1, g_021A4280);
        func_02189D78(connection, 3, 1);
        return 3;
    }
    num = func_020964E0(buffer);

    str = func_02094B20(input, g_021A4458);
    if (str == 0) {
        func_02193710(connection, 1, g_021A4280);
        func_02189D78(connection, 3, 1);
        return 3;
    }
    index += 6;

    for (i = 0; i < num; i++) {
        if (i == 0) {
            for (j = 0; (j < sizeof(buffer)) && ((c = str[j + 6]) != '\0') && (c != ','); j++)
                buffer[j] = c;
            buffer[j] = '\0';
            index += j;
        } else {
            if (!func_02193378(input, g_021A4460, &index, buffer, sizeof(buffer))) {
                func_02193710(connection, 1, g_021A4280);
                func_02189D78(connection, 3, 1);
                return 3;
            }
        }

        profileid = func_020964E0(buffer);
        profile = func_0218FCD8(connection, profileid);
        if (profile == 0) {
            func_02193734(connection, g_021A42BC);
            return 1;
        }
        profile->buddyStatus = (GPIBuddyStatus *)func_0217EAB0(sizeof(GPIBuddyStatus));
        if (profile->buddyStatus == 0) {
            func_02193734(connection, g_021A42BC);
            return 1;
        }
        __builtin__clear(profile->buddyStatus, sizeof(GPIBuddyStatus));
        profile->buddyStatus->buddyIndex = iconnection->numBuddies++;
        profile->buddyStatus->status = 0;
        func_02189300(connection, profileid, 0);
    }
    return 0;
}



/*
 * sdk:      gpiSendServerBuddyMessage (gpibuddy.o)
 */
int func_021888C0(void **connection, int profileid, int type, char *message)
{
    GPIConnection_021888C0 *iconnection;
    char buffer[3501];

    iconnection = (GPIConnection_021888C0 *)*connection;
    func_0219327C(buffer, (int)message, 3501);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4278);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), type);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A424C);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), iconnection->f198);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4464);
    func_0218949C((int *)connection, (int *)(&iconnection->outputBuffer), profileid);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A42CC);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), buffer);
    func_0218946C((int *)connection, (int *)(&iconnection->outputBuffer), g_021A4270);
    return 0;
}



GPResult func_021889A0(void **connection, int profileid, int type, char *message, int sendOption, GPIPeerOp *peerOp)
{
    GPResult result;
    GPIProfile_021889A0 *profile;
    GPIPeer *peer;

    peer = (GPIPeer *)func_0218F0B8(connection, profileid);
    if (peer == 0) {
        if (!func_0218FD9C(connection, profileid, &profile) || profile->buddyStatus == 0 || profile->buddyStatus->f20 == 0) {
            if (sendOption == 0xb00)
                return GP_NETWORK_ERROR;
            return func_021888C0(connection, profileid, type, message);
        }
        peer = func_0218F150(connection, profileid, 1);
        if (peer == 0)
            return GP_MEMORY_ERROR;
        if (profile->f1C == 0) {
            result = func_0218F1E0(connection, peer);
            if (result != GP_NO_ERROR)
                return result;
        } else {
            result = func_0218F248(connection, peer);
            if (result != GP_NO_ERROR)
                return result;
        }
    } else if (peer->state == 0x6a) {
        if (func_0218FD9C(connection, profileid, &profile)) {
            if (profile->buddyStatus != 0)
                profile->buddyStatus->f20 = 0;
            if (sendOption == 0xb00)
                return GP_NETWORK_ERROR;
            if (type < 100)
                return func_021888C0(connection, profileid, type, message);
        }
    }
    if (peerOp != 0)
        func_0218F884(peer, peerOp);
    result = func_0218F350(connection, peer, type, message);
    if (result != GP_NO_ERROR)
        return result;
    return GP_NO_ERROR;
}
