/*
 * function: func_02188638
 * address:  0x02188638
 * packet:   pkt_ov009_02188638
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProcessRecvBuddyList (gpibuddy.o)
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
 *
 * The 28-byte byte-store zero loop after gsimalloc is __builtin__clear on
 * the new GPIBuddyStatus (no memset call in the object).
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

typedef struct GPIProfile {
    int profileId;
    int userId;
    GPIBuddyStatus *buddyStatus;
} GPIProfile;

typedef struct GPIConnection {
    char pad0[0x5d0];
    int numBuddies;
} GPIConnection;

extern int func_0219329C(void **connection, char *input, int callErrorCallback);
extern int func_02193378(char *command, char *key, int *index, char *value, int len);
extern void func_02193710(void **connection, int errorCode, char *errorString);
extern void func_02189D78(void **connection, int result, int fatal);
extern int func_020964E0(const char *s);
extern char *func_02094B20(const char *s, const char *sub);
extern GPIProfile *func_0218FCD8(void **connection, int id);
extern void func_02193734(void **connection, char *errorString);
extern void *func_0217EAB0(unsigned long size);
extern int func_02189300(void **connection, int id, int isDeleted);
extern char g_021A4450[];
extern char g_021A4280[];
extern char g_021A4458[];
extern char g_021A4460[];
extern char g_021A42BC[];

int func_02188638(void **connection, char *input)
{
    int i;
    int num;
    unsigned int j;
    int index = 0;
    char c;
    char *str;
    char buffer[512];
    GPIProfile *profile;
    int profileid;
    GPIConnection *iconnection = (GPIConnection *)*connection;

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
