/*
 * function: gpiProcessRecvBlockedList
 * address:  0x02190188
 * packet:   pkt_ov009_02190188
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProcessRecvBlockedList (libdwcgsgp.TWL.HYB.a gpiprofile.o)
 *
 * symbols:
 *   gpiCheckForError  0x0219329C  arm  ov009
 *   gpiValueForKeyWithIndex  0x02193378  arm  ov009
 *   gpiSetError  0x02193710  arm  ov009
 *   gpiCallErrorCallback  0x02189D78  arm  ov009
 *   atoi  0x020964E0  arm
 *   strstr  0x02094B20  arm
 *   gpiProfileListAdd  0x0218FCD8  arm  ov009
 *   gpiSetErrorString  0x02193734  arm  ov009
 *   gpiBuddyDeletedLocally  0x02189300  arm  ov009
 *   gGpiProfileKeyBlk     0x021A522C  data
 *   gGpiProfileErrorUnexpectedData     0x021A51D8  data
 *   gGpiProfileKeyList     0x021A5234  data
 *   gGpiProfileComma     0x021A523C  data
 *   gGpiProfileErrorOutOfMemory     0x021A5214  data
 */

typedef struct GPIProfile {
    int profileId;                   /* 0x00 */
    int userId;                      /* 0x04 */
    void *buddyStatus;               /* 0x08 */
    void *buddyStatusInfo;           /* 0x0C */
    void *cache;                     /* 0x10 */
    char *authSig;                   /* 0x14 */
    int requestCount;                /* 0x18 */
    char *peerSig;                   /* 0x1C */
    int blocked;                     /* 0x20 */
    int blockIndex;                  /* 0x24 */
    int buddyOrBlockCache;           /* 0x28 */
    int deletedLocally;              /* 0x2C */
} GPIProfile;

typedef struct GPIConnection {
    char pad000[0x5D4];
    int numBlocked;                  /* 0x5D4 */
} GPIConnection;

extern char gGpiProfileKeyBlk[];
extern char gGpiProfileErrorUnexpectedData[];
extern char gGpiProfileKeyList[];
extern char gGpiProfileComma[];
extern char gGpiProfileErrorOutOfMemory[];

extern int gpiCheckForError(int *connection, const char *input, int fatal);
extern int gpiValueForKeyWithIndex(char *command, char *key, int *index, char *value, int len);
extern void gpiSetError(int *connection, int result, int errorString);
extern int gpiCallErrorCallback(int *connection, int a1, int a2);
extern int atoi(const char *s);
extern char *strstr(const char *s1, const char *s2);
extern GPIProfile *gpiProfileListAdd(void **connection, int id);
extern void gpiSetErrorString(int *p, int b);
extern int gpiBuddyDeletedLocally(void **connection, int id, int isDeleted);

int gpiProcessRecvBlockedList(void **connection, char *input)
{
    int i;
    unsigned int j;
    int num;
    int index;
    char c;
    char *str;
    char buffer[512];
    GPIProfile *profile;
    int profileid;
    GPIConnection *iconnection;

    index = 0;
    iconnection = (GPIConnection *)*connection;

    if (gpiCheckForError((int *)connection, input, 1))
        return 4;

    if (!gpiValueForKeyWithIndex(input, gGpiProfileKeyBlk, &index, buffer, sizeof(buffer))) {
        gpiSetError((int *)connection, 1, (int)gGpiProfileErrorUnexpectedData);
        gpiCallErrorCallback((int *)connection, 3, 1);
        return 3;
    }
    num = atoi(buffer);

    str = strstr(input, gGpiProfileKeyList);
    if (!str) {
        gpiSetError((int *)connection, 1, (int)gGpiProfileErrorUnexpectedData);
        gpiCallErrorCallback((int *)connection, 3, 1);
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
            if (!gpiValueForKeyWithIndex(input, gGpiProfileComma, &index, buffer, sizeof(buffer))) {
                gpiSetError((int *)connection, 1, (int)gGpiProfileErrorUnexpectedData);
                gpiCallErrorCallback((int *)connection, 3, 1);
                return 3;
            }
        }

        profileid = atoi(buffer);
        profile = gpiProfileListAdd(connection, profileid);
        if (!profile) {
            gpiSetErrorString((int *)connection, (int)gGpiProfileErrorOutOfMemory);
            return 1;
        }
        profile->blocked = 1;
        profile->blockIndex = iconnection->numBlocked++;
        gpiBuddyDeletedLocally(connection, profileid, 1);
    }

    return 0;
}
