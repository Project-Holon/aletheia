/*
 * file:     gpiinfo.c
 * unit:     yes
 * function: gpiIsValidDate, gpiIntToDate, gpiInfoCacheToArg, gpiProcessGetInfo, gpiAddLocalInfo, gpiSendLocalInfo, gpiSendUserInfo, func_0218C774, func_0218CC48, func_0218D40C, gpiGetInfo, gpiSetInfoCache, func_0218D71C
 * address:  0x0218BA10
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
 *   gpiSetErrorString  0x02193734  arm   ov009
 *   gGpiInfoErrorInvalidDate     0x021A4A98  data  ov009
 *   strzcpy  0x0219327C  arm   ov009
 *   gpiCheckForError  0x0219329C  arm   ov009
 *   strncmp  0x020949F4  arm
 *   gpiSetError  0x02193710  arm   ov009
 *   gpiCallErrorCallback  0x02189D78  arm   ov009
 *   gpiValueForKey  0x02193418  arm   ov009
 *   atoi  0x020964E0  arm
 *   func_0218FD9C  0x0218FD9C  arm   ov009
 *   atof  0x02095B2C  arm
 *   func_0209B64C  0x0209B64C  arm
 *   gpiProfileListAdd  0x0218FCD8  arm   ov009
 *   gsifree  0x0217EAE0  arm   ov009
 *   goastrdup  0x0217F1E0  arm   ov009
 *   gsimalloc  0x0217EAB0  arm   ov009
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
 *   gpiAppendStringToBuffer  0x0218946C  arm  ov009
 *   gpiAppendIntToBuffer  0x0218949C  arm  ov009
 *   gGpiInfoKeyUpdateProSessKey  0x021A4BF4  data
 *   gGpiInfoKeyPartnerId  0x021A4C0C  data
 *   gGpiInfoKeyFinal  0x021A4C18  data
 *   gGpiInfoKeyUpdateUiSessKey  0x021A4C20  data
 *   gpiSetErrorString  0x02193734  arm
 *   OS_SPrintf         0x02084F40  arm
 *   gpiSendLocalInfo   0x0218C6E4  arm  ov009
 *   gpiSendUserInfo    0x0218C72C  arm  ov009
 *   str15081           0x021A4B24  data
 *   str15083           0x021A4B3C  data
 *   str15091           0x021A4B7C  data
 *   str15094           0x021A4B94  data
 *   str15095           0x021A4B9C  data
 *   str15096           0x021A4BA4  data
 *   str15097           0x021A4BAC  data
 *   str15098           0x021A4BB4  data
 *   str15099           0x021A4BBC  data
 *   str15100           0x021A4BC4  data
 *   str15206           0x021A4C34  data
 *   str15207           0x021A4C48  data
 *   str15208           0x021A4C4C  data
 *   str15209           0x021A4C50  data
 *   str15210           0x021A4C54  data
 *   str15211           0x021A4C58  data
 *   str15212           0x021A4C68  data
 *   str15213           0x021A4C78  data
 *   str15214           0x021A4C84  data
 *   str15215           0x021A4C90  data
 *   str15216           0x021A4CA0  data
 *   str15217           0x021A4CB0  data
 *   str15218           0x021A4CC0  data
 *   str15219           0x021A4CD4  data
 *   str15220           0x021A4CE4  data
 *   strzcpy            0x0219327C  arm
 *   _strlwr            0x0217F21C  arm  ov009
 *   gpiEncodeString    0x02193748  arm
 *   strlen             0x0209477C  arm
 *   gsiSafeStrcpyA     0x021803BC  arm
 *   atoi               0x020964E0  arm
 *   str15341           0x021A4CF4  data
 *   str15076           0x021A4AEC  data
 *   str15077           0x021A4AF4  data
 *   str15078           0x021A4B04  data
 *   str15342           0x021A4D04  data
 *   str15079           0x021A4B0C  data
 *   str15080           0x021A4B18  data
 *   str15082           0x021A4B30  data
 *   str15343           0x021A4D14  data
 *   str15084           0x021A4B48  data
 *   __upper_mapC       0x020A615C  data
 *   str15344           0x021A4D2C  data
 *   str15345           0x021A4D40  data
 *   str15346           0x021A4D54  data
 *   str15093           0x021A4B8C  data
 *   gpiAppendStringToBuffer  0x0218946C  arm
 *   gpiAppendIntToBuffer     0x0218949C  arm
 *   gGpiInfoKeyGetProfileSessKey               0x021A4D60  data
 *   gGpiInfoKeyId               0x021A4D78  data
 *   func_0218E114  0x0218E114  arm   ov009
 *   func_0218D40C  0x0218D40C  arm   ov009
 *   func_02186E9C  0x02186E9C  arm   ov009
 *   func_0218D71C  0x0218D71C  arm   ov009
 *   gsifree                          0x0217EAE0 arm
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

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

typedef struct GPIBuffer {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer;

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

struct GPIConnection_0218C5FC {
    char pad0[0x198];
    int profileid;
    char pad1[8];
    int sessionKey;
    char pad2[0x43c];
    char *nick;
    char pad3[4];
    int nickPending;
    char pad4[4];
    char *email;
    char pad5[4];
    int emailPending;
};

typedef struct GPIConnection_0218C6E4 {
    unsigned char pad[0x5E4];
    unsigned char outputBuffer[0x10];
} GPIConnection_0218C6E4;

typedef int _GPResult;

extern void gpiSetErrorString(int *p, int b);
extern int gpiCheckForError(void **connection, char *input, int callErrorCallback);
extern int strncmp(const char *a, const char *b, unsigned int n);
extern void gpiSetError(void **connection, int errorCode, char *errorString);
extern void gpiCallErrorCallback(void **connection, int result, int fatal);
extern int gpiValueForKey(const char *command, const char *key, char *value, int valueLen);
extern int atoi(const char *s);
extern int func_0218FD9C(void **connection, int profileid, GPIProfile **pProfile);
extern double atof(const char *s);
extern float func_0209B64C(double d);
extern GPIProfile *gpiProfileListAdd(void **connection, int id);
extern void gsifree(void *ptr);
extern char *goastrdup(char *src);
extern void *gsimalloc(unsigned long size);
extern void *memset(void *dst, int c, unsigned long n);
extern int gpiAddCallback(void **connection, GPICallback callback, void *arg, GPIOperation_s *operation, int type);
extern void gpiRemoveOperation(void **connection, GPIOperation_s *operation);
extern int gpiAppendStringToBuffer(int *connection, int *buffer, const char *string);
extern int gpiAppendIntToBuffer(int *connection, int *buffer, int value);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern _GPResult gpiSendLocalInfo(void **connection, char *info, char *value);
extern _GPResult gpiSendUserInfo(void **connection, char *info, char *value);
extern void strzcpy(char *dest, char *src, unsigned long len);
extern char *_strlwr(char *string);
extern void gpiEncodeString(char *unencodedString, char *encodedString);
extern int strlen(char *s);
extern unsigned long gsiSafeStrcpyA(char *dst, char *src, unsigned long size);
extern int func_0218E114(void **connection, int type, void *data, GPIOperation_s **op, int blocking, void (*callback)(void **, void *, void *), void *param);
extern int func_0218D40C(void **connection, int profileid, int operationid);
extern int func_02186E9C(void **connection, int blockingOperationID);
extern void func_0218D71C(GPIProfile *profile);
extern void gsifree(void * ptr);
int gpiIsValidDate(int day, int month, int year);
int gpiIntToDate(void **connection, int date, int *day, int *month, int *year);
void gpiInfoCacheToArg(GPIInfoCache *cache, GPGetInfoResponseArg *arg);
int gpiProcessGetInfo(void **connection, GPIOperation_s *operation, char *input);
int gpiAddLocalInfo(void **connection, void *buffer);
int gpiSendLocalInfo(void **connection, char *info, char *value);
int gpiSendUserInfo(void **connection, char *info, char *value);
_GPResult gpiSetInfoi(void **connection, int info, int value);
_GPResult gpiSetInfos(void **connection, int info, char *value);
int gpiSendGetInfo(void **connection, int profileid, int operationid);
int gpiGetInfo(void **connection, int profile, int checkCache, int blocking, void (*callback)(void **, void *, void *), void *param);
int gpiSetInfoCache(void **connection, GPIProfile *profile, GPIInfoCache *cache);
void gpiFreeInfoCache(GPIProfile *profile);
extern char gGpiInfoErrorInvalidDate[];
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
extern char gGpiInfoKeyUpdateProSessKey[];
extern char gGpiInfoKeyPartnerId[];
extern char gGpiInfoKeyFinal[];
extern char gGpiInfoKeyUpdateUiSessKey[];
extern char str15081[];
extern char str15083[];
extern char str15091[];
extern char str15094[];
extern char str15095[];
extern char str15096[];
extern char str15097[];
extern char str15098[];
extern char str15099[];
extern char str15100[];
extern char str15206[];
extern char str15207[];
extern char str15208[];
extern char str15209[];
extern char str15210[];
extern char str15211[];
extern char str15212[];
extern char str15213[];
extern char str15214[];
extern char str15215[];
extern char str15216[];
extern char str15217[];
extern char str15218[];
extern char str15219[];
extern char str15220[];
extern char str15341[];
extern char str15076[];
extern char str15077[];
extern char str15078[];
extern char str15342[];
extern char str15079[];
extern char str15080[];
extern char str15082[];
extern char str15343[];
extern char str15084[];
extern unsigned char __upper_mapC[];
extern char str15344[];
extern char str15345[];
extern char str15346[];
extern char str15093[];
extern char gGpiInfoKeyGetProfileSessKey[];
extern char gGpiInfoKeyId[];




/*
 * Date validity (day, month, year): all-zero is accepted, negatives rejected,
 * month dispatch with February leap handling, then a 1900..2079 window with a
 * 2079-07-06 upper cutoff.
 */
int gpiIsValidDate(int day, int month, int year)
{
    if (day == 0 && month == 0 && year == 0)
        return 1;
    if (day < 0 || month < 0 || year < 0)
        return 0;
    switch (month) {
    case 0:
        if (day != 0)
            return 0;
        break;
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        if (day > 31)
            return 0;
        break;
    case 4: case 6: case 9: case 11:
        if (day > 30)
            return 0;
        break;
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            if (day > 29)
                return 0;
        } else {
            if (day > 28)
                return 0;
        }
        break;
    default:
        return 0;
    }
    if (year < 1900)
        return 0;
    if (year > 2079)
        return 0;
    if (year == 2079) {
        if (month > 6)
            return 0;
        if (month == 6 && day > 6)
            return 0;
    }
    return 1;
}




/*
 * sdk:      gpiIntToDate (gpiinfo.o)
 */
int gpiIntToDate(void **connection, int date, int *day, int *month, int *year)
{
    int d;
    int m;
    int y;

    d = (date >> 24) & 0xFF;
    m = (date >> 16) & 0xFF;
    y = date & 0xFFFF;
    if (!gpiIsValidDate(d, m, y)) {
        gpiSetErrorString((int *)connection, (int)gGpiInfoErrorInvalidDate);
        return 2;
    }
    *day = d;
    *month = m;
    *year = y;
    return 0;
}




/*
 * sdk:      gpiInfoCacheToArg (gpiinfo.o)
 */
void gpiInfoCacheToArg(GPIInfoCache *cache, GPGetInfoResponseArg *arg)
{
    if (cache->nick)
        strzcpy(arg->nick, cache->nick, 31);
    else
        arg->nick[0] = '\0';
    if (cache->uniquenick)
        strzcpy(arg->uniquenick, cache->uniquenick, 21);
    else
        arg->uniquenick[0] = '\0';
    if (cache->email)
        strzcpy(arg->email, cache->email, 51);
    else
        arg->email[0] = '\0';
    if (cache->firstname)
        strzcpy(arg->firstname, cache->firstname, 31);
    else
        arg->firstname[0] = '\0';
    if (cache->lastname)
        strzcpy(arg->lastname, cache->lastname, 31);
    else
        arg->lastname[0] = '\0';
    if (cache->homepage)
        strzcpy(arg->homepage, cache->homepage, 76);
    else
        arg->homepage[0] = '\0';
    arg->icquin = cache->icquin;
    strzcpy(arg->zipcode, cache->zipcode, 11);
    strzcpy(arg->countrycode, cache->countrycode, 3);
    arg->longitude = cache->longitude;
    arg->latitude = cache->latitude;
    if (cache->place)
        strzcpy(arg->place, cache->place, 128);
    else
        arg->place[0] = '\0';
    arg->birthday = cache->birthday;
    arg->birthmonth = cache->birthmonth;
    arg->birthyear = cache->birthyear;
    arg->sex = cache->sex;
    arg->publicmask = cache->publicmask;
    if (cache->aimname)
        strzcpy(arg->aimname, cache->aimname, 51);
    else
        arg->aimname[0] = '\0';
    arg->icquin = cache->icquin;
    arg->longitude = cache->longitude;
    arg->latitude = cache->latitude;
    arg->birthday = cache->birthday;
    arg->birthmonth = cache->birthmonth;
    arg->birthyear = cache->birthyear;
    arg->sex = cache->sex;
    arg->publicmask = cache->publicmask;
    arg->pic = cache->pic;
    arg->occupationid = cache->occupationid;
    arg->industryid = cache->industryid;
    arg->incomeid = cache->incomeid;
    arg->marriedid = cache->marriedid;
    arg->childcount = cache->childcount;
    arg->interests1 = cache->interests1;
    arg->ownership1 = cache->ownership1;
    arg->conntypeid = cache->conntypeid;
}




/*
 * sdk:      gpiProcessGetInfo (gpiinfo.o)
 */
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
            gpiSetErrorString((int *)connection, (int)gGpiInfoErrorOutOfMemory);
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




/*
 * sdk:      gpiAddLocalInfo (libdwcgsgp.TWL.HYB.a(gpiinfo.o))
 */
int gpiAddLocalInfo(void **connection, void *buffer)
{
    struct GPIConnection_0218C5FC *iconnection = (struct GPIConnection_0218C5FC *)*connection;

    if (iconnection->nickPending > 0) {
        gpiAppendStringToBuffer((int *)connection, buffer, gGpiInfoKeyUpdateProSessKey);
        gpiAppendIntToBuffer((int *)connection, buffer, iconnection->profileid);
        gpiAppendStringToBuffer((int *)connection, buffer, iconnection->nick);
        gpiAppendStringToBuffer((int *)connection, buffer, gGpiInfoKeyPartnerId);
        gpiAppendIntToBuffer((int *)connection, buffer, iconnection->sessionKey);
        gpiAppendStringToBuffer((int *)connection, buffer, gGpiInfoKeyFinal);
        iconnection->nickPending = 0;
    }
    if (iconnection->emailPending > 0) {
        gpiAppendStringToBuffer((int *)connection, buffer, gGpiInfoKeyUpdateUiSessKey);
        gpiAppendIntToBuffer((int *)connection, buffer, iconnection->profileid);
        gpiAppendStringToBuffer((int *)connection, buffer, iconnection->email);
        gpiAppendStringToBuffer((int *)connection, buffer, gGpiInfoKeyFinal);
        iconnection->emailPending = 0;
    }
    return 0;
}




/*
 * sdk:      gpiSendLocalInfo (gpiinfo.o)
 */
int gpiSendLocalInfo(void **connection, char *info, char *value)
{
    GPIConnection_0218C6E4 *iconnection = (GPIConnection_0218C6E4 *)*connection;
    int result;

    if ((result = gpiAppendStringToBuffer((int *)connection, (int *)((char *)iconnection + 0x1e4 + 0x400), info)) != 0)
        return result;
    if ((result = gpiAppendStringToBuffer((int *)connection, (int *)((char *)iconnection + 0x1e4 + 0x400), value)) != 0)
        return result;
    return 0;
}



/*
 * sdk:      gpiSendUserInfo (gpiinfo.o)
 */
int gpiSendUserInfo(void **connection, char *info, char *value)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;
    int result;

    if ((result = gpiAppendStringToBuffer((int *)connection, (int *)&iconnection->updateuiBuffer, info)) != 0)
        return result;
    if ((result = gpiAppendStringToBuffer((int *)connection, (int *)&iconnection->updateuiBuffer, value)) != 0)
        return result;
    return 0;
}



_GPResult gpiSetInfoi(void **connection, int info, int value)
{
    char intValue[16];
    _GPResult __result__;

    switch (info) {
    case 0x708:
        if (value < 0) {
            gpiSetErrorString((int *)connection, (int)str15206);
            return 2;
        }
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendLocalInfo(connection, str15083, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x70B:
        switch (value) {
        case 0x500:
            __result__ = gpiSendLocalInfo(connection, str15091, str15208);
            if (__result__)
                return __result__;
            break;
        case 0x501:
            __result__ = gpiSendLocalInfo(connection, str15091, str15209);
            if (__result__)
                return __result__;
            break;
        case 0x502:
            __result__ = gpiSendLocalInfo(connection, str15091, str15210);
            if (__result__)
                return __result__;
            break;
        default:
            gpiSetErrorString((int *)connection, (int)str15211);
            return 2;
        }
        break;
    case 0x706:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendLocalInfo(connection, str15081, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x70C:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendUserInfo(connection, str15212, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x70D:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendUserInfo(connection, str15213, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x70E:
        OS_SPrintf(intValue, str15207, value / 16);
        __result__ = gpiSendUserInfo(connection, str15214, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x710:
        OS_SPrintf(intValue, str15207, value / 4);
        __result__ = gpiSendUserInfo(connection, str15215, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x712:
        OS_SPrintf(intValue, str15207, value / 4);
        __result__ = gpiSendUserInfo(connection, str15216, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x713:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendUserInfo(connection, str15217, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x714:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendUserInfo(connection, str15218, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x715:
        value = value;
        if (value)
            value = 1;
        OS_SPrintf(intValue, str15207, value);
        __result__ = gpiSendUserInfo(connection, str15219, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x718:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendLocalInfo(connection, str15094, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x719:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendLocalInfo(connection, str15095, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x71A:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendLocalInfo(connection, str15096, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x71B:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendLocalInfo(connection, str15097, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x71C:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendLocalInfo(connection, str15098, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x71D:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendLocalInfo(connection, str15099, intValue);
        if (__result__)
            return __result__;
        break;
    case 0x71E:
        OS_SPrintf(intValue, str15207);
        __result__ = gpiSendLocalInfo(connection, str15100, intValue);
        if (__result__)
            return __result__;
        break;
    default:
        gpiSetErrorString((int *)connection, (int)str15220);
        return 2;
    }
    return 0;
}



_GPResult gpiSetInfos(void **connection, int info, char *value)
{
    char *iconnection;
    char passwordenc[45];
    char buffer[256];
    char sex;
    _GPResult __result__;

    iconnection = (char *)*connection;
    if (value == 0) {
        gpiSetErrorString((int *)connection, (int)str15341);
        return 2;
    }

    switch (info) {
    case 0x700:
        if (value[0] == 0) {
            gpiSetErrorString((int *)connection, (int)str15341);
            return 2;
        }
        strzcpy(buffer, value, 0x1f);
        strzcpy(iconnection + 0x110, buffer, 0x1f);
        __result__ = gpiSendLocalInfo(connection, str15076, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x701:
        if (value[0] == 0) {
            gpiSetErrorString((int *)connection, (int)str15341);
            return 2;
        }
        strzcpy(buffer, value, 0x15);
        strzcpy(iconnection + 0x12f, buffer, 0x15);
        __result__ = gpiSendLocalInfo(connection, str15077, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x702:
        if (value[0] == 0) {
            gpiSetErrorString((int *)connection, (int)str15341);
            return 2;
        }
        strzcpy(buffer, value, 0x33);
        _strlwr(buffer);
        strzcpy(iconnection + 0x144, buffer, 0x33);
        __result__ = gpiSendUserInfo(connection, str15078, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x703:
        if (value[0] == 0) {
            gpiSetErrorString((int *)connection, (int)str15341);
            return 2;
        }
        strzcpy(buffer, value, 0x1f);
        strzcpy(iconnection + 0x177, buffer, 0x1f);
        gpiEncodeString(iconnection + 0x177, passwordenc);
        __result__ = gpiSendUserInfo(connection, str15342, passwordenc);
        if (__result__)
            return __result__;
        break;
    case 0x704:
        strzcpy(buffer, value, 0x1f);
        __result__ = gpiSendLocalInfo(connection, str15079, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x705:
        strzcpy(buffer, value, 0x1f);
        __result__ = gpiSendLocalInfo(connection, str15080, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x707:
        strzcpy(buffer, value, 0x4c);
        __result__ = gpiSendLocalInfo(connection, str15082, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x708:
        strzcpy(buffer, value, 0xb);
        __result__ = gpiSendLocalInfo(connection, str15083, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x709:
        if (strlen(value) != 2) {
            gpiSetErrorString((int *)connection, (int)str15343);
            return 2;
        }
        strzcpy(buffer, value, 3);
        __result__ = gpiSendLocalInfo(connection, str15084, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x70B:
        {
            int c;
            c = value[0];
            if (c >= 0 && c < 0x80)
                c = __upper_mapC[c];
            sex = c;
        }
        if (sex == 'M')
            buffer[0] = '0';
        else if (sex == 'F')
            buffer[0] = '1';
        else
            buffer[0] = '2';
        buffer[1] = 0;
        __result__ = gpiSendLocalInfo(connection, str15091, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x706:
        gsiSafeStrcpyA(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15081, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x70D:
        __result__ = gpiSetInfoi(connection, 0x70D, atoi(value));
        if (__result__)
            return __result__;
        break;
    case 0x70E:
        __result__ = gpiSetInfoi(connection, 0x70E, atoi(value));
        if (__result__)
            return __result__;
        break;
    case 0x70F:
        strzcpy(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15344, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x710:
        __result__ = gpiSetInfoi(connection, 0x710, atoi(value));
        if (__result__)
            return __result__;
        break;
    case 0x711:
        strzcpy(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15345, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x712:
        __result__ = gpiSetInfoi(connection, 0x712, atoi(value));
        if (__result__)
            return __result__;
        break;
    case 0x714:
        __result__ = gpiSetInfoi(connection, 0x714, atoi(value));
        if (__result__)
            return __result__;
        break;
    case 0x715:
        __result__ = gpiSetInfoi(connection, 0x715, atoi(value));
        if (__result__)
            return __result__;
        break;
    case 0x716:
        strzcpy(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15346, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x717:
        strzcpy(buffer, value, 0x33);
        __result__ = gpiSendLocalInfo(connection, str15093, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x718:
        strzcpy(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15094, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x719:
        strzcpy(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15095, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x71A:
        strzcpy(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15096, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x71B:
        strzcpy(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15097, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x71C:
        strzcpy(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15098, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x71D:
        strzcpy(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15099, buffer);
        if (__result__)
            return __result__;
        break;
    case 0x71E:
        strzcpy(buffer, value, 0x100);
        __result__ = gpiSendLocalInfo(connection, str15100, buffer);
        if (__result__)
            return __result__;
        break;
    default:
        gpiSetErrorString((int *)connection, (int)str15220);
        return 2;
    }
    return 0;
}



int gpiSendGetInfo(void **connection, int profileid, int operationid)
{
    GPIConnection *iconnection = (GPIConnection *)*connection;

    gpiAppendStringToBuffer((int *)connection, (int *)&iconnection->outputBuffer, gGpiInfoKeyGetProfileSessKey);
    gpiAppendIntToBuffer((int *)connection, (int *)&iconnection->outputBuffer, iconnection->sessKey);
    gpiAppendStringToBuffer((int *)connection, (int *)&iconnection->outputBuffer, gGpiInfoKeyProfileId);
    gpiAppendIntToBuffer((int *)connection, (int *)&iconnection->outputBuffer, profileid);
    gpiAppendStringToBuffer((int *)connection, (int *)&iconnection->outputBuffer, gGpiInfoKeyId);
    gpiAppendIntToBuffer((int *)connection, (int *)&iconnection->outputBuffer, operationid);
    gpiAppendStringToBuffer((int *)connection, (int *)&iconnection->outputBuffer, gGpiInfoKeyFinal);
    return 0;
}



/*
 * sdk:      gpiGetInfo (gpiinfo.o)
 */
int gpiGetInfo(void **connection, int profile, int checkCache, int blocking,
                  void (*callback)(void **, void *, void *), void *param)
{
    GPIProfile *pProfile;
    GPIConnection *iconnection = (GPIConnection *)*connection;
    GPIOperation_s *operation = 0;
    int useCache;
    int result;
    int id;

    useCache = (checkCache == 1) ? 1 : 0;
    if (!iconnection->infoCaching)
        useCache = 0;

    if (callback && useCache) {
        if (func_0218FD9C(connection, profile, &pProfile) && pProfile->cache) {
            GPICallback gpiCallback;
            GPGetInfoResponseArg *arg;

            arg = (GPGetInfoResponseArg *)gsimalloc(sizeof(GPGetInfoResponseArg));
            if (arg == 0) {
                gpiSetErrorString((int *)connection, (int)gGpiInfoErrorOutOfMemory);
                return 1;
            }
            gpiInfoCacheToArg(pProfile->cache, arg);
            arg->result = 0;
            arg->profile = profile;
            gpiCallback.callback = callback;
            gpiCallback.param = param;
            { int __result__ = func_0218E114(connection, 2, 0, &operation, 1, callback, param);
              if (__result__ != 0) return __result__; }
            id = operation->id;
            { int __result__ = gpiAddCallback(connection, gpiCallback, arg, operation, 0);
              if (__result__ != 0) return __result__; }
            gpiRemoveOperation(connection, (struct GPIOperation_s *)operation);
            goto done;
        }
    }
    { int __result__ = func_0218E114(connection, 2, 0, &operation, blocking, callback, param);
      if (__result__ != 0) return __result__; }
    id = operation->id;
    { int __result__ = func_0218D40C(connection, profile, id);
      if (__result__ != 0) return __result__; }
done:
    if (blocking) {
        int __result__ = func_02186E9C(connection, id);
        if (__result__ != 0) return __result__;
    }
    return 0;
}



/*
 * sdk:      gpiSetInfoCache (gpiinfo.o)
 */
int gpiSetInfoCache(void **connection, GPIProfile *profile, GPIInfoCache *cache)
{
    if (((GPIConnection *)*connection)->infoCaching == 0)
        return 1;
    func_0218D71C(profile);
    profile->cache = gsimalloc(sizeof(GPIInfoCache));
    if (profile->cache != 0) {
        *profile->cache = *cache;
        profile->cache->nick = goastrdup(cache->nick);
        profile->cache->uniquenick = goastrdup(cache->uniquenick);
        profile->cache->email = goastrdup(cache->email);
        profile->cache->firstname = goastrdup(cache->firstname);
        profile->cache->lastname = goastrdup(cache->lastname);
        profile->cache->homepage = goastrdup(cache->homepage);
        profile->cache->aimname = goastrdup(cache->aimname);
    }
    return profile->cache != 0;
}



void gpiFreeInfoCache(GPIProfile *profile)
{
	if (profile->cache == 0)
		return;
	gsifree(profile->cache->nick);
	profile->cache->nick = 0;
	gsifree(profile->cache->uniquenick);
	profile->cache->uniquenick = 0;
	gsifree(profile->cache->email);
	profile->cache->email = 0;
	gsifree(profile->cache->firstname);
	profile->cache->firstname = 0;
	gsifree(profile->cache->lastname);
	profile->cache->lastname = 0;
	gsifree(profile->cache->homepage);
	profile->cache->homepage = 0;
	gsifree(profile->cache->aimname);
	profile->cache->aimname = 0;
	gsifree(profile->cache);
	profile->cache = 0;
}
