/*
 * file:     unit_021DD610.c
 * unit:     yes
 * function: func_021DD610, func_021DD64C, func_021DD84C, func_021DD98C, func_021DDA98, func_021DDB10
 * address:  0x021DD610
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020948E0  0x020948E0  arm
 *   d_021E3730     0x021E3730  data
 *   d_021E3738     0x021E3738  data
 *   d_021E374C     0x021E374C  data
 *   d_021E375C     0x021E375C  data
 *   d_021E3770     0x021E3770  data
 *   d_021E3784     0x021E3784  data
 *   d_021E3798     0x021E3798  data
 *   d_021E37A8     0x021E37A8  data
 *   d_021E37B8     0x021E37B8  data
 *   d_021E37C8     0x021E37C8  data
 *   d_021E37DC     0x021E37DC  data
 *   d_021E37EC     0x021E37EC  data
 *   d_021E3800     0x021E3800  data
 *   d_021E3810     0x021E3810  data
 *   d_021E381C     0x021E381C  data
 *   d_021E3828     0x021E3828  data
 *   d_021E3838     0x021E3838  data
 *   d_021E3844     0x021E3844  data
 *   func_021834D0  0x021834D0  arm  ov009
 *   func_021834E8  0x021834E8  arm  ov009
 *   func_0218372C  0x0218372C  arm  ov009
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_021DD604  0x021DD604  arm  ov175
 *   func_021819B0  0x021819B0  arm   ov009
 *   func_021829AC  0x021829AC  arm   ov009
 *   func_02182CF0  0x02182CF0  arm   ov009
 *   func_02182AC0  0x02182AC0  arm   ov009
 *   func_02181D84  0x02181D84  arm   ov009
 *   func_02182A2C  0x02182A2C  arm   ov009
 *   func_02181DE8  0x02181DE8  arm   ov009
 *   g_021E370C     0x021E370C  data
 *   g_021E3858     0x021E3858  data
 *   g_021E385C     0x021E385C  data
 *   g_021E3864     0x021E3864  data
 *   g_021E3870     0x021E3870  data
 *   func_02084F80  0x02084F80  arm
 *   func_0217FD7C  0x0217FD7C  arm  ov009
 *   g_021E4C88  0x021E4C88  data
 *   g_021E387C  0x021E387C  data
 */
struct SAKERequestInternal;
struct SAKERequestInternal_021DD98C;
typedef int s32_021DD610;

typedef int s32_021DD64C;

typedef struct {
    int mOutputSize;
    int pad4;
    int pad8;
    char *mSoapResponseTag;
    char *mResultTag;
    int pad14;
    int pad18;
    int (*mParseFunc)(struct SAKERequestInternal *);
    void (*mFreeFunc)(struct SAKERequestInternal *);
} SAKEIRequestInfo_vD610;

typedef struct SAKERequestInternal {
    void *mSake;
    int mType;
    void *mInput;
    void *mOutput;
    void (*mCallback)(void *, struct SAKERequestInternal *, int, void *, void *, void *);
    void *mUserData;
    void *mSoapRequest;
    void *mSoapResponse;
    SAKEIRequestInfo_vD610 *mInfo;
} SAKERequestInternal;

typedef signed int     s32_021DD84C;

typedef struct SAKEIRequestInfo_vD98C {
    int f0;
    char *soapTag;
    char pad8[0x14 - 0x8];
    int (*validateInputFunc)(struct SAKERequestInternal_021DD98C *);
    int (*fillFunc)(struct SAKERequestInternal_021DD98C *);
    int f1C;
    void (*cleanupFunc)(struct SAKERequestInternal_021DD98C *);
} SAKEIRequestInfo_vD98C;

typedef struct SAKEI {
    char pad0[0x14];
    unsigned int gameId;
    char gameName[0x2c - 0x18];
    char secretKey[1];
} SAKEI;

typedef struct SAKERequestInternal_021DD98C {
    SAKEI *mSake;
    int mType;
    void *mInput;
    void *mOutput;
    void *mCallback;
    void *mUserData;
    void *mSoapRequest;
    void *mSoapResponse;
    SAKEIRequestInfo_vD98C *mInfo;
} SAKERequestInternal_021DD98C;

typedef struct SAKEInternal {
    unsigned char pad0[4];
    char gameName[1];
} SAKEInternal;

typedef struct GSSoapTask {
    unsigned char pad0[0x24];
    int f24;
} GSSoapTask;

typedef struct SAKEService {
    unsigned char pad0[8];
    char *serviceName;
    unsigned char padC[0x18];
    int f24;
} SAKEService;

typedef struct SAKERequestInternal_021DDA98 {
    SAKEInternal *sake;
    unsigned char pad4[0x14];
    void *soapRequest;
    unsigned char pad1C[4];
    SAKEService *service;
} SAKERequestInternal_021DDA98;

extern s32_021DD64C func_020948E0(const char *a, const char *b);
extern int func_021834D0(int *p);
extern int func_021834E8(void *stream, char *matchtag);
extern int func_0218372C(void *stream, char *matchtag, char *valueOut, int maxLen);
extern void *func_0217EAB0(unsigned long size);
extern void func_0217EAE0(void *ptr);
extern void func_021DD604(void *request);
extern void *func_021819B0(const char **namespaces, int count);
extern int func_021829AC(void *stream, char *namespaceName, char *tag);
extern int func_02182CF0(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int func_02182AC0(void *stream, char *namespaceName, char *tag, char *value);
extern void func_02181D84(void **p);
extern int func_02182A2C(void *stream, char *namespaceName, char *tag);
extern int func_02181DE8(void *stream);
extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);
extern GSSoapTask *func_0217FD7C(char *url, char *service, void *soap, void (*callback)(int, void *, void *), void *userData);
s32_021DD610 func_021DD610(s32_021DD610 a);
s32_021DD64C func_021DD64C(const char *p);
void func_021DD84C(int httpResult, int unused, void *responseData, void *userData);
int func_021DD98C(SAKERequestInternal_021DD98C *request);
void func_021DDA98(SAKERequestInternal_021DDA98 *request);
int func_021DDB10(void *p, int v);
extern char d_021E3730[];
extern char d_021E3738[];
extern char d_021E374C[];
extern char d_021E375C[];
extern char d_021E3770[];
extern char d_021E3784[];
extern char d_021E3798[];
extern char d_021E37A8[];
extern char d_021E37B8[];
extern char d_021E37C8[];
extern char d_021E37DC[];
extern char d_021E37EC[];
extern char d_021E3800[];
extern char d_021E3810[];
extern char d_021E381C[];
extern char d_021E3828[];
extern char d_021E3838[];
extern char d_021E3844[];
extern char *g_021E370C[1];
extern char g_021E3858[];
extern char g_021E385C[];
extern char g_021E3864[];
extern char g_021E3870[];
extern char g_021E4C88[128];
extern char g_021E387C[];



/*
 * Category selector: 0 -> 0, 1 -> 6, 0x12 -> 0x17, anything else -> 4.
 */
s32_021DD610 func_021DD610(s32_021DD610 a)
{
    switch (a) {
    case 0:
        return 0;
    case 1:
        return 6;
    case 0x12:
        return 0x17;
    default:
        return 4;
    }
}



/*
 * Nintendo WFC / Wi-Fi connection error-name to index table: a plain
 * strcmp-style probe (func_020948E0) against each known status string,
 * returning the string's index.  Seven indices (6 in the 9..0x14 range)
 * are skipped because they are not reachable from this pool; the caller
 * reads the dedicated return value from those.
 */
s32_021DD64C func_021DD64C(const char *p)
{
    if (func_020948E0(p, d_021E3730) == 0)
        return 0;
    if (func_020948E0(p, d_021E3738) == 0)
        return 1;
    if (func_020948E0(p, d_021E374C) == 0)
        return 2;
    if (func_020948E0(p, d_021E375C) == 0)
        return 7;
    if (func_020948E0(p, d_021E3770) == 0)
        return 8;
    if (func_020948E0(p, d_021E3784) == 0)
        return 9;
    if (func_020948E0(p, d_021E3798) == 0)
        return 0xa;
    if (func_020948E0(p, d_021E37A8) == 0)
        return 0xb;
    if (func_020948E0(p, d_021E37B8) == 0)
        return 0xc;
    if (func_020948E0(p, d_021E37C8) == 0)
        return 0xd;
    if (func_020948E0(p, d_021E37DC) == 0)
        return 0xe;
    if (func_020948E0(p, d_021E37EC) == 0)
        return 0xf;
    if (func_020948E0(p, d_021E3800) == 0)
        return 0x10;
    if (func_020948E0(p, d_021E3810) == 0)
        return 0x11;
    if (func_020948E0(p, d_021E381C) == 0)
        return 0x12;
    if (func_020948E0(p, d_021E3828) == 0)
        return 0x13;
    if (func_020948E0(p, d_021E3838) == 0)
        return 0x14;
    return func_020948E0(p, d_021E3844) == 0 ? 0x15 : 0x16;
}



/*
 * sdk:      sakeiSoapCallback (libdwcgssake.TWL.HYB.a sakerequest.o)
 */
void func_021DD84C(int httpResult, int unused, void *responseData, void *userData)
{
    SAKERequestInternal *request;
    void *output;
    int result;
    char resultString[32];

    request = (SAKERequestInternal *)userData;
    output = 0;
    if (!request || !request->mSake || !request->mInfo)
        return;
    result = func_021DD610(httpResult);
    if (result == 0) {
        if (!func_021834D0(responseData) || !func_021834E8(responseData, request->mInfo->mSoapResponseTag) ||
            !func_0218372C(responseData, request->mInfo->mResultTag, resultString, 32)) {
            result = 5;
        } else {
            result = func_021DD64C(resultString);
            if (result == 0 && request->mInfo->mOutputSize) {
                request->mOutput = func_0217EAB0(request->mInfo->mOutputSize);
                if (request->mOutput) {
                    request->mSoapResponse = responseData;
                    result = request->mInfo->mParseFunc(request);
                    if (result == 0)
                        output = request->mOutput;
                } else {
                    result = 6;
                }
            }
        }
    }
    if (request->mCallback)
        request->mCallback(request->mSake, request, result, request->mInput, output, request->mUserData);
    if (request->mInfo->mFreeFunc)
        request->mInfo->mFreeFunc(request);
    func_0217EAE0(request->mOutput);
    request->mOutput = 0;
    func_021DD604(request);
}



int func_021DD98C(SAKERequestInternal_021DD98C *request)
{
    SAKEIRequestInfo_vD98C *info = request->mInfo;
    int result;

    result = info->validateInputFunc(request);
    if (result != 0)
        return result;
    request->mSoapRequest = func_021819B0((const char **)g_021E370C, 1);
    if (request->mSoapRequest == 0)
        return 2;
    func_021829AC(request->mSoapRequest, g_021E3858, request->mInfo->soapTag);
    func_02182CF0(request->mSoapRequest, g_021E3858, g_021E385C, request->mSake->gameId);
    func_02182AC0(request->mSoapRequest, g_021E3858, g_021E3864, request->mSake->gameName);
    func_02182AC0(request->mSoapRequest, g_021E3858, g_021E3870, request->mSake->secretKey);
    result = info->fillFunc(request);
    if (result != 0) {
        func_02181D84(request->mSoapRequest);
        request->mSoapRequest = 0;
        if (info->cleanupFunc != 0)
            info->cleanupFunc(request);
        return result;
    }
    func_02182A2C(request->mSoapRequest, g_021E3858, request->mInfo->soapTag);
    func_02181DE8(request->mSoapRequest);
    return 0;
}



/*
 * sdk:      sakeiExecuteRequest (sakerequest.o)
 */
void func_021DDA98(SAKERequestInternal_021DDA98 *request)
{
    GSSoapTask *soapTask;

    if (!g_021E4C88[0])
        func_02084F80(g_021E4C88, 128, g_021E387C, request->sake->gameName);
    soapTask = func_0217FD7C(g_021E4C88, request->service->serviceName, request->soapRequest, (void (*)(int,  void *, void *))func_021DD84C, request);
    if (soapTask)
        request->service->f24 = soapTask->f24;
    else
        request->service->f24 = 0;
}



int func_021DDB10(void *p, int v)
{
    int r;

    *(int *)((char *)p + 0x20) = v;
    r = func_021DD98C(p);
    if (r)
        return r;
    func_021DDA98(p);
    return 0;
}
