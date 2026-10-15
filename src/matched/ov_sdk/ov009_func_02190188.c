/*
 * function: func_02190188
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
 *   func_0219329C  0x0219329C  arm  ov009
 *   func_02193378  0x02193378  arm  ov009
 *   func_02193710  0x02193710  arm  ov009
 *   func_02189D78  0x02189D78  arm  ov009
 *   atoi  0x020964E0  arm
 *   strstr  0x02094B20  arm
 *   func_0218FCD8  0x0218FCD8  arm  ov009
 *   func_02193734  0x02193734  arm  ov009
 *   func_02189300  0x02189300  arm  ov009
 *   g_021A522C     0x021A522C  data
 *   g_021A51D8     0x021A51D8  data
 *   g_021A5234     0x021A5234  data
 *   g_021A523C     0x021A523C  data
 *   g_021A5214     0x021A5214  data
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

extern char g_021A522C[];
extern char g_021A51D8[];
extern char g_021A5234[];
extern char g_021A523C[];
extern char g_021A5214[];

extern int func_0219329C(int *connection, const char *input, int fatal);
extern int func_02193378(char *command, char *key, int *index, char *value, int len);
extern void func_02193710(int *connection, int result, int errorString);
extern int func_02189D78(int *connection, int a1, int a2);
extern int atoi(const char *s);
extern char *strstr(const char *s1, const char *s2);
extern GPIProfile *func_0218FCD8(void **connection, int id);
extern void func_02193734(int *p, int b);
extern int func_02189300(void **connection, int id, int isDeleted);

int func_02190188(void **connection, char *input)
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

    if (func_0219329C((int *)connection, input, 1))
        return 4;

    if (!func_02193378(input, g_021A522C, &index, buffer, sizeof(buffer))) {
        func_02193710((int *)connection, 1, (int)g_021A51D8);
        func_02189D78((int *)connection, 3, 1);
        return 3;
    }
    num = atoi(buffer);

    str = strstr(input, g_021A5234);
    if (!str) {
        func_02193710((int *)connection, 1, (int)g_021A51D8);
        func_02189D78((int *)connection, 3, 1);
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
            if (!func_02193378(input, g_021A523C, &index, buffer, sizeof(buffer))) {
                func_02193710((int *)connection, 1, (int)g_021A51D8);
                func_02189D78((int *)connection, 3, 1);
                return 3;
            }
        }

        profileid = atoi(buffer);
        profile = func_0218FCD8(connection, profileid);
        if (!profile) {
            func_02193734((int *)connection, (int)g_021A5214);
            return 1;
        }
        profile->blocked = 1;
        profile->blockIndex = iconnection->numBlocked++;
        func_02189300(connection, profileid, 1);
    }

    return 0;
}
