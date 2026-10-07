/*
 * file:     unit_0218BA10_p02.c
 * unit:     yes
 * function: func_0218BDB8, func_0218C5FC, func_0218C6E4
 * address:  0x0218BDB8
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
 *   func_020949F4  0x020949F4  arm
 *   func_02193710  0x02193710  arm   ov009
 *   func_02189D78  0x02189D78  arm   ov009
 *   func_02193418  0x02193418  arm   ov009
 *   func_020964E0  0x020964E0  arm
 *   func_0218FD9C  0x0218FD9C  arm   ov009
 *   func_02095B2C  0x02095B2C  arm
 *   func_0209B64C  0x0209B64C  arm
 *   func_0218BB70  0x0218BB70  arm   ov009
 *   func_0218FCD8  0x0218FCD8  arm   ov009
 *   func_0217EAE0  0x0217EAE0  arm   ov009
 *   func_0217F1E0  0x0217F1E0  arm   ov009
 *   func_0218D644  0x0218D644  arm   ov009
 *   func_0217EAB0  0x0217EAB0  arm   ov009
 *   func_02193734  0x02193734  arm   ov009
 *   func_0218BBDC  0x0218BBDC  arm   ov009
 *   func_02189DFC  0x02189DFC  arm   ov009
 *   func_0218E240  0x0218E240  arm   ov009
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
 *   func_0218946C  0x0218946C  arm  ov009
 *   func_0218949C  0x0218949C  arm  ov009
 *   g_021A4BF4  0x021A4BF4  data
 *   g_021A4C0C  0x021A4C0C  data
 *   g_021A4C18  0x021A4C18  data
 *   g_021A4C20  0x021A4C20  data
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

typedef struct GPIConnection_0218BDB8 {
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
} GPIConnection_0218BDB8;

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

extern int func_0219329C(void **connection, char *input, int callErrorCallback);
extern int func_020949F4(const char *a, const char *b, unsigned int n);
extern void func_02193710(void **connection, int errorCode, char *errorString);
extern void func_02189D78(void **connection, int result, int fatal);
extern int func_02193418(const char *command, const char *key, char *value, int valueLen);
extern int func_020964E0(const char *s);
extern int func_0218FD9C(void **connection, int profileid, GPIProfile **pProfile);
extern double func_02095B2C(const char *s);
extern float func_0209B64C(double d);
extern int func_0218BB70(void **connection, int date, int *day, int *month, int *year);
extern GPIProfile *func_0218FCD8(void **connection, int id);
extern void func_0217EAE0(void *ptr);
extern char *func_0217F1E0(char *src);
extern int func_0218D644(void **connection, GPIProfile *profile, GPIInfoCache *cache);
extern void *func_0217EAB0(unsigned long size);
extern void func_02193734(void **connection, char *errorString);
extern void func_0218BBDC(GPIInfoCache *cache, GPGetInfoResponseArg *arg);
extern void *memset(void *dst, int c, unsigned long n);
extern int func_02189DFC(void **connection, GPICallback callback, void *arg, GPIOperation_s *operation, int type);
extern void func_0218E240(void **connection, GPIOperation_s *operation);
extern int func_0218946C(int *connection, int *buffer, const char *string);
extern int func_0218949C(int *connection, int *buffer, int value);
int func_0218BDB8(void **connection, GPIOperation_s *operation, char *input);
int func_0218C5FC(void **connection, void *buffer);
int func_0218C6E4(void **connection, char *info, char *value);
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
extern char g_021A4BF4[];
extern char g_021A4C0C[];
extern char g_021A4C18[];
extern char g_021A4C20[];


/*
 * sdk:      gpiProcessGetInfo (gpiinfo.o)
 */
int func_0218BDB8(void **connection, GPIOperation_s *operation, char *input)
{
    GPIInfoCache infoCache;
    char buffer[64];
    GPIConnection_0218BDB8 *iconnection = (GPIConnection_0218BDB8 *)*connection;
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

    if (func_0219329C(connection, input, 1))
        return 4;

    if (func_020949F4(input, g_021A4AA8, 4) != 0) {
        func_02193710(connection, 1, g_021A4AB0);
        __result__ = 3;
        func_02189D78(connection, __result__, 1);
        return __result__;
    }

    if (!func_02193418(input, g_021A4AE0, buffer, sizeof(buffer))) {
        func_02193710(connection, 1, g_021A4AB0);
        __result__ = 3;
        func_02189D78(connection, __result__, 1);
        return __result__;
    }
    profileid = func_020964E0(buffer);

    func_0218FD9C(connection, profileid, &profile);

    __builtin__clear(&infoCache, sizeof(GPIInfoCache));
    infoCache.nick = nick;
    infoCache.uniquenick = uniquenick;
    infoCache.email = email;
    infoCache.firstname = firstname;
    infoCache.lastname = lastname;
    infoCache.homepage = homepage;
    infoCache.aimname = aimname;

    if (!func_02193418(input, g_021A4AEC, infoCache.nick, 31))
        infoCache.nick[0] = '\0';
    if (!func_02193418(input, g_021A4AF4, infoCache.uniquenick, 21))
        infoCache.uniquenick[0] = '\0';
    if (!func_02193418(input, g_021A4B04, infoCache.email, 51))
        infoCache.email[0] = '\0';
    if (!func_02193418(input, g_021A4B0C, infoCache.firstname, 31))
        infoCache.firstname[0] = '\0';
    if (!func_02193418(input, g_021A4B18, infoCache.lastname, 31))
        infoCache.lastname[0] = '\0';
    if (!func_02193418(input, g_021A4B24, buffer, sizeof(buffer)))
        infoCache.icquin = -1;
    else
        infoCache.icquin = func_020964E0(buffer);
    if (!func_02193418(input, g_021A4B30, infoCache.homepage, 76))
        infoCache.homepage[0] = '\0';
    if (!func_02193418(input, g_021A4B3C, infoCache.zipcode, sizeof(infoCache.zipcode)))
        infoCache.zipcode[0] = '\0';
    if (!func_02193418(input, g_021A4B48, infoCache.countrycode, sizeof(infoCache.countrycode)))
        infoCache.countrycode[0] = '\0';
    if (!func_02193418(input, g_021A4B58, buffer, sizeof(buffer)))
        infoCache.longitude = 0;
    else
        infoCache.longitude = func_0209B64C(func_02095B2C(buffer));
    if (!func_02193418(input, g_021A4B60, buffer, sizeof(buffer)))
        infoCache.latitude = 0;
    else
        infoCache.latitude = func_0209B64C(func_02095B2C(buffer));
    if (!func_02193418(input, g_021A4B68, infoCache.place, 128))
        infoCache.place[0] = '\0';
    if (!func_02193418(input, g_021A4B70, buffer, sizeof(buffer))) {
        infoCache.birthday = 0;
        infoCache.birthmonth = 0;
        infoCache.birthyear = 0;
    } else {
        __result__ = func_0218BB70(connection, func_020964E0(buffer), &infoCache.birthday,
                                   &infoCache.birthmonth, &infoCache.birthyear);
        if (__result__ != 0)
            return __result__;
    }
    if (!func_02193418(input, g_021A4B7C, buffer, sizeof(buffer)))
        infoCache.sex = 0x502;
    else if (buffer[0] == '0')
        infoCache.sex = 0x500;
    else if (buffer[0] == '1')
        infoCache.sex = 0x501;
    else
        infoCache.sex = 0x502;
    if (!func_02193418(input, g_021A4B84, buffer, sizeof(buffer)))
        infoCache.publicmask = 0xFFFFFFFF;
    else
        infoCache.publicmask = func_020964E0(buffer);
    if (!func_02193418(input, g_021A4B8C, infoCache.aimname, 51))
        infoCache.aimname[0] = '\0';
    if (!func_02193418(input, g_021A4B94, buffer, sizeof(buffer)))
        infoCache.pic = 0;
    else
        infoCache.pic = func_020964E0(buffer);
    if (!func_02193418(input, g_021A4B9C, buffer, sizeof(buffer)))
        infoCache.occupationid = 0;
    else
        infoCache.occupationid = func_020964E0(buffer);
    if (!func_02193418(input, g_021A4BA4, buffer, sizeof(buffer)))
        infoCache.industryid = 0;
    else
        infoCache.industryid = func_020964E0(buffer);
    if (!func_02193418(input, g_021A4BAC, buffer, sizeof(buffer)))
        infoCache.incomeid = 0;
    else
        infoCache.incomeid = func_020964E0(buffer);
    if (!func_02193418(input, g_021A4BB4, buffer, sizeof(buffer)))
        infoCache.marriedid = 0;
    else
        infoCache.marriedid = func_020964E0(buffer);
    if (!func_02193418(input, g_021A4BBC, buffer, sizeof(buffer)))
        infoCache.childcount = 0;
    else
        infoCache.childcount = func_020964E0(buffer);
    if (!func_02193418(input, g_021A4BC4, buffer, sizeof(buffer)))
        infoCache.interests1 = 0;
    else
        infoCache.interests1 = func_020964E0(buffer);
    if (!func_02193418(input, g_021A4BCC, buffer, sizeof(buffer)))
        infoCache.ownership1 = 0;
    else
        infoCache.ownership1 = func_020964E0(buffer);
    if (!func_02193418(input, g_021A4BD4, buffer, sizeof(buffer)))
        infoCache.conntypeid = 0;
    else
        infoCache.conntypeid = func_020964E0(buffer);

    if (!func_02193418(input, g_021A4BDC, buffer, sizeof(buffer))) {
        func_02193710(connection, 1, g_021A4AB0);
        __result__ = 3;
        func_02189D78(connection, __result__, 1);
        return __result__;
    }

    saveSig = iconnection->infoCaching;

    for (peer = iconnection->peerList; peer != 0; peer = peer->pnext) {
        if (peer->profile == profileid) {
            if (peer->state == 0x65) {
                if (!profile)
                    profile = func_0218FCD8(connection, profileid);
                peer->state = 0x66;
                saveSig = 1;
            }
        }
    }

    if (!profile && iconnection->infoCaching)
        profile = func_0218FCD8(connection, profileid);

    if (saveSig) {
        func_0217EAE0(profile->peerSig);
        profile->peerSig = 0;
        profile->peerSig = func_0217F1E0(buffer);
    }

    if (iconnection->infoCaching)
        func_0218D644(connection, profile, &infoCache);

    callback = operation->callback;
    if (callback.callback != 0) {
        GPGetInfoResponseArg *arg;
        arg = (GPGetInfoResponseArg *)func_0217EAB0(sizeof(GPGetInfoResponseArg));
        if (arg == 0) {
            func_02193734(connection, g_021A4BE4);
            return 1;
        }
        func_0218BBDC(&infoCache, arg);
        arg->result = 0;
        arg->profile = profileid;
        __result__ = func_02189DFC(connection, callback, arg, operation, 0);
        if (__result__ != 0)
            return __result__;
    }

    func_0218E240(connection, operation);

    return 0;
}


/*
 * sdk:      gpiAddLocalInfo (libdwcgsgp.TWL.HYB.a(gpiinfo.o))
 */
int func_0218C5FC(void **connection, void *buffer)
{
    struct GPIConnection_0218C5FC *iconnection = (struct GPIConnection_0218C5FC *)*connection;

    if (iconnection->nickPending > 0) {
        func_0218946C((int *)connection, buffer, g_021A4BF4);
        func_0218949C((int *)connection, buffer, iconnection->profileid);
        func_0218946C((int *)connection, buffer, iconnection->nick);
        func_0218946C((int *)connection, buffer, g_021A4C0C);
        func_0218949C((int *)connection, buffer, iconnection->sessionKey);
        func_0218946C((int *)connection, buffer, g_021A4C18);
        iconnection->nickPending = 0;
    }
    if (iconnection->emailPending > 0) {
        func_0218946C((int *)connection, buffer, g_021A4C20);
        func_0218949C((int *)connection, buffer, iconnection->profileid);
        func_0218946C((int *)connection, buffer, iconnection->email);
        func_0218946C((int *)connection, buffer, g_021A4C18);
        iconnection->emailPending = 0;
    }
    return 0;
}


/*
 * sdk:      gpiSendLocalInfo (gpiinfo.o)
 */
int func_0218C6E4(void **connection, char *info, char *value)
{
    GPIConnection_0218C6E4 *iconnection = (GPIConnection_0218C6E4 *)*connection;
    int result;

    if ((result = func_0218946C((int *)connection, (int *)((char *)iconnection + 0x1e4 + 0x400), info)) != 0)
        return result;
    if ((result = func_0218946C((int *)connection, (int *)((char *)iconnection + 0x1e4 + 0x400), value)) != 0)
        return result;
    return 0;
}
