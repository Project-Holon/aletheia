/*
 * file:     unit_0218BA10_p03.c
 * unit:     yes
 * function: func_0218C72C, func_0218C774, func_0218CC48, func_0218D40C, func_0218D4A4, func_0218D644, func_0218D71C
 * address:  0x0218C72C
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
 *   func_0218946C  0x0218946C  arm   ov009
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
 *   g_021A4D60               0x021A4D60  data
 *   g_021A4AE0               0x021A4AE0  data
 *   g_021A4D78               0x021A4D78  data
 *   g_021A4C18               0x021A4C18  data
 *   func_0218FD9C  0x0218FD9C  arm   ov009
 *   func_0217EAB0  0x0217EAB0  arm   ov009
 *   func_02193734  0x02193734  arm   ov009
 *   func_0218BBDC  0x0218BBDC  arm   ov009
 *   func_0218E114  0x0218E114  arm   ov009
 *   func_02189DFC  0x02189DFC  arm   ov009
 *   func_0218E240  0x0218E240  arm   ov009
 *   func_0218D40C  0x0218D40C  arm   ov009
 *   func_02186E9C  0x02186E9C  arm   ov009
 *   g_021A4BE4     0x021A4BE4  data
 *   func_0218D71C  0x0218D71C  arm   ov009
 *   func_0217F1E0  0x0217F1E0  arm   ov009
 *   gsifree                          0x0217EAE0 arm
 */
struct GPIInfoCache;
struct GPIOperation;
typedef struct GPIConnection_0218C72C {
    unsigned char pad[0x5E4];
    unsigned char outputBuffer[0x10];
} GPIConnection_0218C72C;

typedef int _GPResult;

struct GPIBuffer {
    char *buffer;  /* +0x00 */
    int   size;    /* +0x04 */
    int   len;     /* +0x08 */
    int   pos;     /* +0x0c */
};

struct GPIConnection_0218D40C {
    char pad0[0x198];
    int sessKey;                            /* +0x198 */
    char pad19c[0x210 - 0x19c];
    struct GPIBuffer outputBuffer;          /* +0x210 */
};

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
} GPIOperation;

typedef struct GPIProfile_0218D4A4 {
    int profileId;
    int userId;
    void *buddyStatus;
    void *buddyStatusInfo;
    void *cache;
} GPIProfile_0218D4A4;

typedef struct GPGetInfoResponseArg {
    int result;
    int profile;
    char rest[0x204 - 8];
} GPGetInfoResponseArg;

typedef struct GPIConnection_0218D4A4 {
    char pad0[0x100];
    int infoCaching;
} GPIConnection_0218D4A4;

typedef struct GPIInfoCache_0218D644 {
    char *s0;
    char *s4;
    char *s8;
    char *sC;
    char *s10;
    char *s14;
    unsigned char pad[0xC8 - 0x18];
    char *sC8;
    unsigned char pad2[0xF0 - 0xCC];
} GPIInfoCache_0218D644;

typedef struct GPIProfile_0218D644 {
    unsigned char pad[0x10];
    GPIInfoCache_0218D644 *cache;
} GPIProfile_0218D644;

typedef struct GPIConnection_0218D644 {
    unsigned char pad[0x100];
    int f100;
} GPIConnection_0218D644;

typedef struct GPIInfoCache_0218D71C
{
	void * field0;
	void * field4;
	void * field8;
	void * fieldC;
	void * field10;
	void * field14;
	char pad[0xC8 - 0x18];
	void * fieldC8;
} GPIInfoCache_0218D71C;

struct GPIProfile_0218D71C
{
	char pad[0x10];
	GPIInfoCache_0218D71C * infoCache;
};

extern int func_0218946C(int *connection, int *buffer, const char *string);
extern void gpiSetErrorString(void **connection, char *errorString);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern _GPResult gpiSendLocalInfo(void **connection, char *info, char *value);
extern _GPResult gpiSendUserInfo(void **connection, char *info, char *value);
extern void strzcpy(char *dest, char *src, unsigned long len);
extern char *_strlwr(char *string);
extern void gpiEncodeString(char *unencodedString, char *encodedString);
extern int strlen(char *s);
extern unsigned long gsiSafeStrcpyA(char *dst, char *src, unsigned long size);
extern int atoi(char *s);
extern int gpiAppendStringToBuffer(void **connection, struct GPIBuffer *outputBuffer,
                                   char *buffer);
extern int gpiAppendIntToBuffer(void **connection, struct GPIBuffer *outputBuffer,
                                int num);
extern int func_0218FD9C(void **connection, int profileid, GPIProfile_0218D4A4 **pProfile);
extern void *func_0217EAB0(unsigned long size);
extern void func_02193734(int *p, int b);
extern void func_0218BBDC(struct GPIInfoCache *cache, struct GPGetInfoResponseArg *arg);
extern int func_0218E114(void **connection, int type, void *data, GPIOperation **op, int blocking, void (*callback)(void **, void *, void *), void *param);
extern int func_02189DFC(void **connection, GPICallback callback, void *arg, GPIOperation *operation, int type);
extern void func_0218E240(void **connection, struct GPIOperation *operation);
extern int func_0218D40C(void **connection, int profileid, int operationid);
extern int func_02186E9C(void **connection, int blockingOperationID);
extern void func_0218D71C(GPIProfile_0218D644 *profile);
extern char *func_0217F1E0(char *src);
extern void gsifree(void * ptr);
int func_0218C72C(void **connection, char *info, char *value);
_GPResult gpiSetInfoi(void **connection, int info, int value);
_GPResult gpiSetInfos(void **connection, int info, char *value);
int gpiSendGetInfo(void **connection, int profileid, int operationid);
int func_0218D4A4(void **connection, int profile, int checkCache, int blocking, void (*callback)(void **, void *, void *), void *param);
int func_0218D644(void **connection, GPIProfile_0218D644 *profile, GPIInfoCache_0218D644 *cache);
void gpiFreeInfoCache(struct GPIProfile_0218D71C * profile);
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
extern char g_021A4D60[];
extern char g_021A4AE0[];
extern char g_021A4D78[];
extern char g_021A4C18[];
extern char g_021A4BE4[];


/*
 * sdk:      gpiSendUserInfo (gpiinfo.o)
 */
int func_0218C72C(void **connection, char *info, char *value)
{
    GPIConnection_0218C72C *iconnection = (GPIConnection_0218C72C *)*connection;
    int result;

    if ((result = func_0218946C((int *)connection, (int *)((char *)iconnection + 0x1f4 + 0x400), info)) != 0)
        return result;
    if ((result = func_0218946C((int *)connection, (int *)((char *)iconnection + 0x1f4 + 0x400), value)) != 0)
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
            gpiSetErrorString(connection, str15206);
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
            gpiSetErrorString(connection, str15211);
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
        gpiSetErrorString(connection, str15220);
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
        gpiSetErrorString(connection, str15341);
        return 2;
    }

    switch (info) {
    case 0x700:
        if (value[0] == 0) {
            gpiSetErrorString(connection, str15341);
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
            gpiSetErrorString(connection, str15341);
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
            gpiSetErrorString(connection, str15341);
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
            gpiSetErrorString(connection, str15341);
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
            gpiSetErrorString(connection, str15343);
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
        gpiSetErrorString(connection, str15220);
        return 2;
    }
    return 0;
}


int gpiSendGetInfo(void **connection, int profileid, int operationid)
{
    struct GPIConnection_0218D40C *iconnection = (struct GPIConnection_0218D40C *)*connection;

    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A4D60);
    gpiAppendIntToBuffer(connection, &iconnection->outputBuffer, iconnection->sessKey);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A4AE0);
    gpiAppendIntToBuffer(connection, &iconnection->outputBuffer, profileid);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A4D78);
    gpiAppendIntToBuffer(connection, &iconnection->outputBuffer, operationid);
    gpiAppendStringToBuffer(connection, &iconnection->outputBuffer, g_021A4C18);
    return 0;
}


/*
 * sdk:      gpiGetInfo (gpiinfo.o)
 */
int func_0218D4A4(void **connection, int profile, int checkCache, int blocking,
                  void (*callback)(void **, void *, void *), void *param)
{
    GPIProfile_0218D4A4 *pProfile;
    GPIConnection_0218D4A4 *iconnection = (GPIConnection_0218D4A4 *)*connection;
    GPIOperation *operation = 0;
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

            arg = (GPGetInfoResponseArg *)func_0217EAB0(sizeof(GPGetInfoResponseArg));
            if (arg == 0) {
                func_02193734((int *)connection, (int)g_021A4BE4);
                return 1;
            }
            func_0218BBDC(pProfile->cache, arg);
            arg->result = 0;
            arg->profile = profile;
            gpiCallback.callback = callback;
            gpiCallback.param = param;
            { int __result__ = func_0218E114(connection, 2, 0, &operation, 1, callback, param);
              if (__result__ != 0) return __result__; }
            id = operation->id;
            { int __result__ = func_02189DFC(connection, gpiCallback, arg, operation, 0);
              if (__result__ != 0) return __result__; }
            func_0218E240(connection, (struct GPIOperation *)operation);
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
int func_0218D644(void **connection, GPIProfile_0218D644 *profile, GPIInfoCache_0218D644 *cache)
{
    if (((GPIConnection_0218D644 *)*connection)->f100 == 0)
        return 1;
    func_0218D71C(profile);
    profile->cache = func_0217EAB0(sizeof(GPIInfoCache_0218D644));
    if (profile->cache != 0) {
        *profile->cache = *cache;
        profile->cache->s0 = func_0217F1E0(cache->s0);
        profile->cache->s4 = func_0217F1E0(cache->s4);
        profile->cache->s8 = func_0217F1E0(cache->s8);
        profile->cache->sC = func_0217F1E0(cache->sC);
        profile->cache->s10 = func_0217F1E0(cache->s10);
        profile->cache->s14 = func_0217F1E0(cache->s14);
        profile->cache->sC8 = func_0217F1E0(cache->sC8);
    }
    return profile->cache != 0;
}


void gpiFreeInfoCache(struct GPIProfile_0218D71C * profile)
{
	if (profile->infoCache == 0)
		return;
	gsifree(profile->infoCache->field0);
	profile->infoCache->field0 = 0;
	gsifree(profile->infoCache->field4);
	profile->infoCache->field4 = 0;
	gsifree(profile->infoCache->field8);
	profile->infoCache->field8 = 0;
	gsifree(profile->infoCache->fieldC);
	profile->infoCache->fieldC = 0;
	gsifree(profile->infoCache->field10);
	profile->infoCache->field10 = 0;
	gsifree(profile->infoCache->field14);
	profile->infoCache->field14 = 0;
	gsifree(profile->infoCache->fieldC8);
	profile->infoCache->fieldC8 = 0;
	gsifree(profile->infoCache);
	profile->infoCache = 0;
}
