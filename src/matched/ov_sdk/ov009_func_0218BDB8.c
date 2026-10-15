/*
 * function: gpiProcessGetInfo
 * address:  0x0218BDB8
 * packet:   pkt_ov009_0218BDB8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProcessGetInfo (gpiinfo.o)
 *
 * symbols:
 *   gpiCheckForError  0x0219329C  arm   ov009
 *   strncmp  0x020949F4  arm
 *   gpiSetError  0x02193710  arm   ov009
 *   gpiCallErrorCallback  0x02189D78  arm   ov009
 *   gpiValueForKey  0x02193418  arm   ov009
 *   atoi  0x020964E0  arm
 *   func_0218FD9C  0x0218FD9C  arm   ov009
 *   atof  0x02095B2C  arm
 *   func_0209B64C  0x0209B64C  arm
 *   gpiIntToDate  0x0218BB70  arm   ov009
 *   gpiProfileListAdd  0x0218FCD8  arm   ov009
 *   gsifree  0x0217EAE0  arm   ov009
 *   goastrdup  0x0217F1E0  arm   ov009
 *   gpiSetInfoCache  0x0218D644  arm   ov009
 *   gsimalloc  0x0217EAB0  arm   ov009
 *   gpiSetErrorString  0x02193734  arm   ov009
 *   gpiInfoCacheToArg  0x0218BBDC  arm   ov009
 *   gpiAddCallback  0x02189DFC  arm   ov009
 *   gpiRemoveOperation  0x0218E240  arm   ov009
 *   g_021A4AA8     0x021A4AA8  data
 *   g_021A4AB0     0x021A4AB0  data
 *   g_021A4AE0     0x021A4AE0  data
 *   g_021A4AEC     0x021A4AEC  data
 *   g_021A4AF4     0x021A4AF4  data
 *   g_021A4B04     0x021A4B04  data
 *   g_021A4B0C     0x021A4B0C  data
 *   g_021A4B18     0x021A4B18  data
 *   g_021A4B24     0x021A4B24  data
 *   g_021A4B30     0x021A4B30  data
 *   g_021A4B3C     0x021A4B3C  data
 *   g_021A4B48     0x021A4B48  data
 *   g_021A4B58     0x021A4B58  data
 *   g_021A4B60     0x021A4B60  data
 *   g_021A4B68     0x021A4B68  data
 *   g_021A4B70     0x021A4B70  data
 *   g_021A4B7C     0x021A4B7C  data
 *   g_021A4B84     0x021A4B84  data
 *   g_021A4B8C     0x021A4B8C  data
 *   g_021A4B94     0x021A4B94  data
 *   g_021A4B9C     0x021A4B9C  data
 *   g_021A4BA4     0x021A4BA4  data
 *   g_021A4BAC     0x021A4BAC  data
 *   g_021A4BB4     0x021A4BB4  data
 *   g_021A4BBC     0x021A4BBC  data
 *   g_021A4BC4     0x021A4BC4  data
 *   g_021A4BCC     0x021A4BCC  data
 *   g_021A4BD4     0x021A4BD4  data
 *   g_021A4BDC     0x021A4BDC  data
 *   g_021A4BE4     0x021A4BE4  data
 */

typedef struct GPIBuffer {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer;

typedef struct GPIInfoCache {
    char *nick;
    char *uniquenick;
    char *email;
    char *firstname;
    char *lastname;
    char *homepage;
    int icquin;
    char zipcode[11];
    char countrycode[3];
    float longitude;
    float latitude;
    char place[128];
    int birthday;
    int birthmonth;
    int birthyear;
    int sex;
    int publicmask;
    char *aimname;
    int pic;
    int occupationid;
    int industryid;
    int incomeid;
    int marriedid;
    int childcount;
    int interests1;
    int ownership1;
    int conntypeid;
} GPIInfoCache;

typedef struct GPGetInfoResponseArg {
    int result;
    int profile;
    char nick[31];
    char uniquenick[21];
    char email[51];
    char firstname[31];
    char lastname[31];
    char homepage[76];
    int icquin;
    char zipcode[11];
    char countrycode[3];
    float longitude;
    float latitude;
    char place[128];
    int birthday;
    int birthmonth;
    int birthyear;
    int sex;
    int publicmask;
    char aimname[51];
    int pic;
    int occupationid;
    int industryid;
    int incomeid;
    int marriedid;
    int childcount;
    int interests1;
    int ownership1;
    int conntypeid;
} GPGetInfoResponseArg;

typedef struct GPICallback {
    void (*callback)(void **, void *, void *);
    void *param;
} GPICallback;

typedef struct GPIOperation_s {
    int type;
    void *data;
    int blocking;
    GPICallback callback;
    int state;
    int id;
    int result;
    struct GPIOperation_s *pnext;
} GPIOperation_s;

typedef struct GPIProfile {
    int profileId;
    int userId;
    void *buddyStatus;
    void *buddyStatusInfo;
    GPIInfoCache *cache;
    char *authSig;
    int requestCount;
    char *peerSig;
    int blocked;
    int blockIndex;
    int buddyOrBlockCache;
    int deletedLocally;
} GPIProfile;

typedef struct GPIPeer_s {
    int state;
    int initiated;
    unsigned int ip;
    unsigned short port;
    int profile;
    long timeout;
    int nackCount;
    GPIBuffer inputBuffer;
    GPIBuffer outputBuffer;
    void *messages;
    char peerOpQueue[12];
    struct GPIPeer_s *pnext;
} GPIPeer_s;

typedef struct GPIConnection {
    char errorString[256];
    int infoCaching;
    int infoCachingBuddyAndBlockOnly;
    int simulation;
    int firewall;
    char nick[31];
    char uniquenick[21];
    char email[51];
    char password[31];
    int sessKey;
    int userid;
    int profileid;
    int partnerID;
    GPICallback callbacks[9];
    int cmSocket;
    int connectState;
    GPIBuffer socketBuffer;
    char *inputBuffer;
    int inputBufferSize;
    GPIBuffer outputBuffer;
    char mHeader[16];
    unsigned short peerPort;
    int nextOperationID;
    int numSearches;
    int lastStatusState;
    unsigned int hostIp;
    unsigned int hostPrivateIp;
    unsigned short queryPort;
    unsigned short hostPort;
    unsigned int sessionFlags;
    char richStatus[256];
    char gameType[33];
    char gameVariant[33];
    char gameMapName[33];
    void *extendedInfoKeys;
    char lastStatusString[256];
    char lastLocationString[256];
    int errorCode;
    int fatalError;
    void *diskCache;
    GPIOperation_s *operationList;
    char profileList[16];
    struct GPIPeer_s *peerList;
    void *callbackList;
    void *lastCallback;
    GPIBuffer updateproBuffer;
    GPIBuffer updateuiBuffer;
    void *transfers;
    unsigned int nextTransferID;
    int productID;
    int namespaceID;
    char loginTicket[25];
    int quietModeFlags;
    unsigned int kaTransmit;
} GPIConnection;

extern int gpiCheckForError(void **connection, char *input, int callErrorCallback);
extern int strncmp(const char *a, const char *b, unsigned int n);
extern void gpiSetError(void **connection, int errorCode, char *errorString);
extern void gpiCallErrorCallback(void **connection, int result, int fatal);
extern int gpiValueForKey(const char *command, const char *key, char *value, int valueLen);
extern int atoi(const char *s);
extern int func_0218FD9C(void **connection, int profileid, GPIProfile **pProfile);
extern double atof(const char *s);
extern float func_0209B64C(double d);
extern int gpiIntToDate(void **connection, int date, int *day, int *month, int *year);
extern GPIProfile *gpiProfileListAdd(void **connection, int id);
extern void gsifree(void *ptr);
extern char *goastrdup(char *src);
extern int gpiSetInfoCache(void **connection, GPIProfile *profile, GPIInfoCache *cache);
extern void *gsimalloc(unsigned long size);
extern void gpiSetErrorString(void **connection, char *errorString);
extern void gpiInfoCacheToArg(GPIInfoCache *cache, GPGetInfoResponseArg *arg);
extern void *memset(void *dst, int c, unsigned long n);
extern int gpiAddCallback(void **connection, GPICallback callback, void *arg, GPIOperation_s *operation, int type);
extern void gpiRemoveOperation(void **connection, GPIOperation_s *operation);
extern char g_021A4AA8[];
extern char g_021A4AB0[];
extern char g_021A4AE0[];
extern char g_021A4AEC[];
extern char g_021A4AF4[];
extern char g_021A4B04[];
extern char g_021A4B0C[];
extern char g_021A4B18[];
extern char g_021A4B24[];
extern char g_021A4B30[];
extern char g_021A4B3C[];
extern char g_021A4B48[];
extern char g_021A4B58[];
extern char g_021A4B60[];
extern char g_021A4B68[];
extern char g_021A4B70[];
extern char g_021A4B7C[];
extern char g_021A4B84[];
extern char g_021A4B8C[];
extern char g_021A4B94[];
extern char g_021A4B9C[];
extern char g_021A4BA4[];
extern char g_021A4BAC[];
extern char g_021A4BB4[];
extern char g_021A4BBC[];
extern char g_021A4BC4[];
extern char g_021A4BCC[];
extern char g_021A4BD4[];
extern char g_021A4BDC[];
extern char g_021A4BE4[];

int gpiProcessGetInfo(void **connection, GPIOperation_s *operation, char *input)
{
    GPIInfoCache infoCache;
    char buffer[64];
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPIPeer_s *peer;
    int saveSig;
    int profileid;
    GPIProfile *profile;
    GPICallback callback;
    char nick[31];
    char uniquenick[21];
    char email[51];
    char firstname[31];
    char lastname[31];
    char homepage[76];
    char aimname[51];
    int __result__;

    if (gpiCheckForError(connection, input, 1))
        return 4;

    if (strncmp(input, g_021A4AA8, 4) != 0) {
        gpiSetError(connection, 1, g_021A4AB0);
        __result__ = 3;
        gpiCallErrorCallback(connection, __result__, 1);
        return __result__;
    }

    if (!gpiValueForKey(input, g_021A4AE0, buffer, sizeof(buffer))) {
        gpiSetError(connection, 1, g_021A4AB0);
        __result__ = 3;
        gpiCallErrorCallback(connection, __result__, 1);
        return __result__;
    }
    profileid = atoi(buffer);

    func_0218FD9C(connection, profileid, &profile);

    __builtin__clear(&infoCache, sizeof(GPIInfoCache));
    infoCache.nick = nick;
    infoCache.uniquenick = uniquenick;
    infoCache.email = email;
    infoCache.firstname = firstname;
    infoCache.lastname = lastname;
    infoCache.homepage = homepage;
    infoCache.aimname = aimname;

    if (!gpiValueForKey(input, g_021A4AEC, infoCache.nick, 31))
        infoCache.nick[0] = '\0';
    if (!gpiValueForKey(input, g_021A4AF4, infoCache.uniquenick, 21))
        infoCache.uniquenick[0] = '\0';
    if (!gpiValueForKey(input, g_021A4B04, infoCache.email, 51))
        infoCache.email[0] = '\0';
    if (!gpiValueForKey(input, g_021A4B0C, infoCache.firstname, 31))
        infoCache.firstname[0] = '\0';
    if (!gpiValueForKey(input, g_021A4B18, infoCache.lastname, 31))
        infoCache.lastname[0] = '\0';
    if (!gpiValueForKey(input, g_021A4B24, buffer, sizeof(buffer)))
        infoCache.icquin = -1;
    else
        infoCache.icquin = atoi(buffer);
    if (!gpiValueForKey(input, g_021A4B30, infoCache.homepage, 76))
        infoCache.homepage[0] = '\0';
    if (!gpiValueForKey(input, g_021A4B3C, infoCache.zipcode, sizeof(infoCache.zipcode)))
        infoCache.zipcode[0] = '\0';
    if (!gpiValueForKey(input, g_021A4B48, infoCache.countrycode, sizeof(infoCache.countrycode)))
        infoCache.countrycode[0] = '\0';
    if (!gpiValueForKey(input, g_021A4B58, buffer, sizeof(buffer)))
        infoCache.longitude = 0;
    else
        infoCache.longitude = func_0209B64C(atof(buffer));
    if (!gpiValueForKey(input, g_021A4B60, buffer, sizeof(buffer)))
        infoCache.latitude = 0;
    else
        infoCache.latitude = func_0209B64C(atof(buffer));
    if (!gpiValueForKey(input, g_021A4B68, infoCache.place, 128))
        infoCache.place[0] = '\0';
    if (!gpiValueForKey(input, g_021A4B70, buffer, sizeof(buffer))) {
        infoCache.birthday = 0;
        infoCache.birthmonth = 0;
        infoCache.birthyear = 0;
    } else {
        __result__ = gpiIntToDate(connection, atoi(buffer), &infoCache.birthday,
                                   &infoCache.birthmonth, &infoCache.birthyear);
        if (__result__ != 0)
            return __result__;
    }
    if (!gpiValueForKey(input, g_021A4B7C, buffer, sizeof(buffer)))
        infoCache.sex = 0x502;
    else if (buffer[0] == '0')
        infoCache.sex = 0x500;
    else if (buffer[0] == '1')
        infoCache.sex = 0x501;
    else
        infoCache.sex = 0x502;
    if (!gpiValueForKey(input, g_021A4B84, buffer, sizeof(buffer)))
        infoCache.publicmask = 0xFFFFFFFF;
    else
        infoCache.publicmask = atoi(buffer);
    if (!gpiValueForKey(input, g_021A4B8C, infoCache.aimname, 51))
        infoCache.aimname[0] = '\0';
    if (!gpiValueForKey(input, g_021A4B94, buffer, sizeof(buffer)))
        infoCache.pic = 0;
    else
        infoCache.pic = atoi(buffer);
    if (!gpiValueForKey(input, g_021A4B9C, buffer, sizeof(buffer)))
        infoCache.occupationid = 0;
    else
        infoCache.occupationid = atoi(buffer);
    if (!gpiValueForKey(input, g_021A4BA4, buffer, sizeof(buffer)))
        infoCache.industryid = 0;
    else
        infoCache.industryid = atoi(buffer);
    if (!gpiValueForKey(input, g_021A4BAC, buffer, sizeof(buffer)))
        infoCache.incomeid = 0;
    else
        infoCache.incomeid = atoi(buffer);
    if (!gpiValueForKey(input, g_021A4BB4, buffer, sizeof(buffer)))
        infoCache.marriedid = 0;
    else
        infoCache.marriedid = atoi(buffer);
    if (!gpiValueForKey(input, g_021A4BBC, buffer, sizeof(buffer)))
        infoCache.childcount = 0;
    else
        infoCache.childcount = atoi(buffer);
    if (!gpiValueForKey(input, g_021A4BC4, buffer, sizeof(buffer)))
        infoCache.interests1 = 0;
    else
        infoCache.interests1 = atoi(buffer);
    if (!gpiValueForKey(input, g_021A4BCC, buffer, sizeof(buffer)))
        infoCache.ownership1 = 0;
    else
        infoCache.ownership1 = atoi(buffer);
    if (!gpiValueForKey(input, g_021A4BD4, buffer, sizeof(buffer)))
        infoCache.conntypeid = 0;
    else
        infoCache.conntypeid = atoi(buffer);

    if (!gpiValueForKey(input, g_021A4BDC, buffer, sizeof(buffer))) {
        gpiSetError(connection, 1, g_021A4AB0);
        __result__ = 3;
        gpiCallErrorCallback(connection, __result__, 1);
        return __result__;
    }

    saveSig = iconnection->infoCaching;

    for (peer = iconnection->peerList; peer != 0; peer = peer->pnext) {
        if (peer->profile == profileid) {
            if (peer->state == 0x65) {
                if (!profile)
                    profile = gpiProfileListAdd(connection, profileid);
                peer->state = 0x66;
                saveSig = 1;
            }
        }
    }

    if (!profile && iconnection->infoCaching)
        profile = gpiProfileListAdd(connection, profileid);

    if (saveSig) {
        gsifree(profile->peerSig);
        profile->peerSig = 0;
        profile->peerSig = goastrdup(buffer);
    }

    if (iconnection->infoCaching)
        gpiSetInfoCache(connection, profile, &infoCache);

    callback = operation->callback;
    if (callback.callback != 0) {
        GPGetInfoResponseArg *arg;
        arg = (GPGetInfoResponseArg *)gsimalloc(sizeof(GPGetInfoResponseArg));
        if (arg == 0) {
            gpiSetErrorString(connection, g_021A4BE4);
            return 1;
        }
        gpiInfoCacheToArg(&infoCache, arg);
        arg->result = 0;
        arg->profile = profileid;
        __result__ = gpiAddCallback(connection, callback, arg, operation, 0);
        if (__result__ != 0)
            return __result__;
    }

    gpiRemoveOperation(connection, operation);

    return 0;
}
