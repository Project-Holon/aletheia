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
 *   gGpiInfoResponsePi     0x021A4AA8  data
 *   gGpiInfoErrorUnexpectedData     0x021A4AB0  data
 *   gGpiInfoKeyProfileId     0x021A4AE0  data
 *   gGpiInfoKeyNick     0x021A4AEC  data
 *   gGpiInfoKeyUniqueNick     0x021A4AF4  data
 *   gGpiInfoKeyEmail     0x021A4B04  data
 *   gGpiInfoKeyFirstName     0x021A4B0C  data
 *   gGpiInfoKeyLastName     0x021A4B18  data
 *   gGpiInfoKeyIcqUin     0x021A4B24  data
 *   gGpiInfoKeyHomepage     0x021A4B30  data
 *   gGpiInfoKeyZipCode     0x021A4B3C  data
 *   gGpiInfoKeyCountryCode     0x021A4B48  data
 *   gGpiInfoKeyLon     0x021A4B58  data
 *   gGpiInfoKeyLat     0x021A4B60  data
 *   gGpiInfoKeyLoc     0x021A4B68  data
 *   gGpiInfoKeyBirthday     0x021A4B70  data
 *   gGpiInfoKeySex     0x021A4B7C  data
 *   gGpiInfoKeyPmask     0x021A4B84  data
 *   gGpiInfoKeyAim     0x021A4B8C  data
 *   gGpiInfoKeyPic     0x021A4B94  data
 *   gGpiInfoKeyOcc     0x021A4B9C  data
 *   gGpiInfoKeyInd     0x021A4BA4  data
 *   gGpiInfoKeyInc     0x021A4BAC  data
 *   gGpiInfoKeyMar     0x021A4BB4  data
 *   gGpiInfoKeyChc     0x021A4BBC  data
 *   gGpiInfoKeyI1     0x021A4BC4  data
 *   gGpiInfoKeyO1     0x021A4BCC  data
 *   gGpiInfoKeyConn     0x021A4BD4  data
 *   gGpiInfoKeySig     0x021A4BDC  data
 *   gGpiInfoErrorOutOfMemory     0x021A4BE4  data
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
extern char gGpiInfoResponsePi[];
extern char gGpiInfoErrorUnexpectedData[];
extern char gGpiInfoKeyProfileId[];
extern char gGpiInfoKeyNick[];
extern char gGpiInfoKeyUniqueNick[];
extern char gGpiInfoKeyEmail[];
extern char gGpiInfoKeyFirstName[];
extern char gGpiInfoKeyLastName[];
extern char gGpiInfoKeyIcqUin[];
extern char gGpiInfoKeyHomepage[];
extern char gGpiInfoKeyZipCode[];
extern char gGpiInfoKeyCountryCode[];
extern char gGpiInfoKeyLon[];
extern char gGpiInfoKeyLat[];
extern char gGpiInfoKeyLoc[];
extern char gGpiInfoKeyBirthday[];
extern char gGpiInfoKeySex[];
extern char gGpiInfoKeyPmask[];
extern char gGpiInfoKeyAim[];
extern char gGpiInfoKeyPic[];
extern char gGpiInfoKeyOcc[];
extern char gGpiInfoKeyInd[];
extern char gGpiInfoKeyInc[];
extern char gGpiInfoKeyMar[];
extern char gGpiInfoKeyChc[];
extern char gGpiInfoKeyI1[];
extern char gGpiInfoKeyO1[];
extern char gGpiInfoKeyConn[];
extern char gGpiInfoKeySig[];
extern char gGpiInfoErrorOutOfMemory[];

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

    if (strncmp(input, gGpiInfoResponsePi, 4) != 0) {
        gpiSetError(connection, 1, gGpiInfoErrorUnexpectedData);
        __result__ = 3;
        gpiCallErrorCallback(connection, __result__, 1);
        return __result__;
    }

    if (!gpiValueForKey(input, gGpiInfoKeyProfileId, buffer, sizeof(buffer))) {
        gpiSetError(connection, 1, gGpiInfoErrorUnexpectedData);
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

    if (!gpiValueForKey(input, gGpiInfoKeyNick, infoCache.nick, 31))
        infoCache.nick[0] = '\0';
    if (!gpiValueForKey(input, gGpiInfoKeyUniqueNick, infoCache.uniquenick, 21))
        infoCache.uniquenick[0] = '\0';
    if (!gpiValueForKey(input, gGpiInfoKeyEmail, infoCache.email, 51))
        infoCache.email[0] = '\0';
    if (!gpiValueForKey(input, gGpiInfoKeyFirstName, infoCache.firstname, 31))
        infoCache.firstname[0] = '\0';
    if (!gpiValueForKey(input, gGpiInfoKeyLastName, infoCache.lastname, 31))
        infoCache.lastname[0] = '\0';
    if (!gpiValueForKey(input, gGpiInfoKeyIcqUin, buffer, sizeof(buffer)))
        infoCache.icquin = -1;
    else
        infoCache.icquin = atoi(buffer);
    if (!gpiValueForKey(input, gGpiInfoKeyHomepage, infoCache.homepage, 76))
        infoCache.homepage[0] = '\0';
    if (!gpiValueForKey(input, gGpiInfoKeyZipCode, infoCache.zipcode, sizeof(infoCache.zipcode)))
        infoCache.zipcode[0] = '\0';
    if (!gpiValueForKey(input, gGpiInfoKeyCountryCode, infoCache.countrycode, sizeof(infoCache.countrycode)))
        infoCache.countrycode[0] = '\0';
    if (!gpiValueForKey(input, gGpiInfoKeyLon, buffer, sizeof(buffer)))
        infoCache.longitude = 0;
    else
        infoCache.longitude = func_0209B64C(atof(buffer));
    if (!gpiValueForKey(input, gGpiInfoKeyLat, buffer, sizeof(buffer)))
        infoCache.latitude = 0;
    else
        infoCache.latitude = func_0209B64C(atof(buffer));
    if (!gpiValueForKey(input, gGpiInfoKeyLoc, infoCache.place, 128))
        infoCache.place[0] = '\0';
    if (!gpiValueForKey(input, gGpiInfoKeyBirthday, buffer, sizeof(buffer))) {
        infoCache.birthday = 0;
        infoCache.birthmonth = 0;
        infoCache.birthyear = 0;
    } else {
        __result__ = gpiIntToDate(connection, atoi(buffer), &infoCache.birthday,
                                   &infoCache.birthmonth, &infoCache.birthyear);
        if (__result__ != 0)
            return __result__;
    }
    if (!gpiValueForKey(input, gGpiInfoKeySex, buffer, sizeof(buffer)))
        infoCache.sex = 0x502;
    else if (buffer[0] == '0')
        infoCache.sex = 0x500;
    else if (buffer[0] == '1')
        infoCache.sex = 0x501;
    else
        infoCache.sex = 0x502;
    if (!gpiValueForKey(input, gGpiInfoKeyPmask, buffer, sizeof(buffer)))
        infoCache.publicmask = 0xFFFFFFFF;
    else
        infoCache.publicmask = atoi(buffer);
    if (!gpiValueForKey(input, gGpiInfoKeyAim, infoCache.aimname, 51))
        infoCache.aimname[0] = '\0';
    if (!gpiValueForKey(input, gGpiInfoKeyPic, buffer, sizeof(buffer)))
        infoCache.pic = 0;
    else
        infoCache.pic = atoi(buffer);
    if (!gpiValueForKey(input, gGpiInfoKeyOcc, buffer, sizeof(buffer)))
        infoCache.occupationid = 0;
    else
        infoCache.occupationid = atoi(buffer);
    if (!gpiValueForKey(input, gGpiInfoKeyInd, buffer, sizeof(buffer)))
        infoCache.industryid = 0;
    else
        infoCache.industryid = atoi(buffer);
    if (!gpiValueForKey(input, gGpiInfoKeyInc, buffer, sizeof(buffer)))
        infoCache.incomeid = 0;
    else
        infoCache.incomeid = atoi(buffer);
    if (!gpiValueForKey(input, gGpiInfoKeyMar, buffer, sizeof(buffer)))
        infoCache.marriedid = 0;
    else
        infoCache.marriedid = atoi(buffer);
    if (!gpiValueForKey(input, gGpiInfoKeyChc, buffer, sizeof(buffer)))
        infoCache.childcount = 0;
    else
        infoCache.childcount = atoi(buffer);
    if (!gpiValueForKey(input, gGpiInfoKeyI1, buffer, sizeof(buffer)))
        infoCache.interests1 = 0;
    else
        infoCache.interests1 = atoi(buffer);
    if (!gpiValueForKey(input, gGpiInfoKeyO1, buffer, sizeof(buffer)))
        infoCache.ownership1 = 0;
    else
        infoCache.ownership1 = atoi(buffer);
    if (!gpiValueForKey(input, gGpiInfoKeyConn, buffer, sizeof(buffer)))
        infoCache.conntypeid = 0;
    else
        infoCache.conntypeid = atoi(buffer);

    if (!gpiValueForKey(input, gGpiInfoKeySig, buffer, sizeof(buffer))) {
        gpiSetError(connection, 1, gGpiInfoErrorUnexpectedData);
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
            gpiSetErrorString(connection, gGpiInfoErrorOutOfMemory);
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
