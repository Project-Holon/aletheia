/*
 * file:     unit_02187010_p01.c
 * unit:     yes
 * function: func_02188638, func_021888C0, func_021889A0
 * address:  0x02188638
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
 *   g_021A4280     0x021A4280  data
 *   g_021A4458     0x021A4458  data
 *   g_021A4460     0x021A4460  data
 *   g_021A42BC     0x021A42BC  data
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

typedef struct GPIBuddyStatusInfo {
    char pad0[0x20];
    unsigned short f20;
} GPIBuddyStatusInfo;

typedef struct GPIProfile_021889A0 {
    char pad0[0xc];
    GPIBuddyStatusInfo *buddyStatus;
    char pad1[0x1c - 0x10];
    int f1C;
} GPIProfile_021889A0;

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
int func_02188638(void **connection, char *input);
int func_021888C0(void **connection, int profileid, int type, char *message);
GPResult func_021889A0(void **connection, int profileid, int type, char *message, int sendOption, GPIPeerOp *peerOp);
extern char g_021A4450[];
extern char g_021A4280[];
extern char g_021A4458[];
extern char g_021A4460[];
extern char g_021A42BC[];
extern char g_021A4278[];
extern char g_021A424C[];
extern char g_021A4464[];
extern char g_021A42CC[];
extern char g_021A4270[];


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
