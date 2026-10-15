/*
 * function: gpiProcessRecvBuddyList
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
 *   gpiCheckForError  0x0219329C  arm   ov009
 *   gpiValueForKeyWithIndex  0x02193378  arm   ov009
 *   gpiSetError  0x02193710  arm   ov009
 *   gpiCallErrorCallback  0x02189D78  arm   ov009
 *   atoi  0x020964E0  arm
 *   strstr  0x02094B20  arm
 *   gpiProfileListAdd  0x0218FCD8  arm   ov009
 *   gpiSetErrorString  0x02193734  arm   ov009
 *   gsimalloc  0x0217EAB0  arm   ov009
 *   gpiBuddyDeletedLocally  0x02189300  arm   ov009
 *   gGpiBuddyKeyBdy     0x021A4450  data
 *   gGpiBuddyErrorUnexpectedData     0x021A4280  data
 *   gGpiBuddyKeyList     0x021A4458  data
 *   gGpiBuddyComma     0x021A4460  data
 *   gGpiBuddyErrorOutOfMemory     0x021A42BC  data
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

extern int gpiCheckForError(void **connection, char *input, int callErrorCallback);
extern int gpiValueForKeyWithIndex(char *command, char *key, int *index, char *value, int len);
extern void gpiSetError(void **connection, int errorCode, char *errorString);
extern void gpiCallErrorCallback(void **connection, int result, int fatal);
extern int atoi(const char *s);
extern char *strstr(const char *s, const char *sub);
extern GPIProfile *gpiProfileListAdd(void **connection, int id);
extern void gpiSetErrorString(void **connection, char *errorString);
extern void *gsimalloc(unsigned long size);
extern int gpiBuddyDeletedLocally(void **connection, int id, int isDeleted);
extern char gGpiBuddyKeyBdy[];
extern char gGpiBuddyErrorUnexpectedData[];
extern char gGpiBuddyKeyList[];
extern char gGpiBuddyComma[];
extern char gGpiBuddyErrorOutOfMemory[];

int gpiProcessRecvBuddyList(void **connection, char *input)
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

    if (gpiCheckForError(connection, input, 1))
        return 4;

    if (!gpiValueForKeyWithIndex(input, gGpiBuddyKeyBdy, &index, buffer, sizeof(buffer))) {
        gpiSetError(connection, 1, gGpiBuddyErrorUnexpectedData);
        gpiCallErrorCallback(connection, 3, 1);
        return 3;
    }
    num = atoi(buffer);

    str = strstr(input, gGpiBuddyKeyList);
    if (str == 0) {
        gpiSetError(connection, 1, gGpiBuddyErrorUnexpectedData);
        gpiCallErrorCallback(connection, 3, 1);
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
            if (!gpiValueForKeyWithIndex(input, gGpiBuddyComma, &index, buffer, sizeof(buffer))) {
                gpiSetError(connection, 1, gGpiBuddyErrorUnexpectedData);
                gpiCallErrorCallback(connection, 3, 1);
                return 3;
            }
        }

        profileid = atoi(buffer);
        profile = gpiProfileListAdd(connection, profileid);
        if (profile == 0) {
            gpiSetErrorString(connection, gGpiBuddyErrorOutOfMemory);
            return 1;
        }
        profile->buddyStatus = (GPIBuddyStatus *)gsimalloc(sizeof(GPIBuddyStatus));
        if (profile->buddyStatus == 0) {
            gpiSetErrorString(connection, gGpiBuddyErrorOutOfMemory);
            return 1;
        }
        __builtin__clear(profile->buddyStatus, sizeof(GPIBuddyStatus));
        profile->buddyStatus->buddyIndex = iconnection->numBuddies++;
        profile->buddyStatus->status = 0;
        gpiBuddyDeletedLocally(connection, profileid, 0);
    }
    return 0;
}
