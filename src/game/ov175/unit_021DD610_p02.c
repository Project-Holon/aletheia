/*
 * file:     unit_021DD610_p02.c
 * unit:     yes
 * function: func_021DD98C, func_021DDA98, func_021DDB10
 * address:  0x021DD98C
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
 *   func_021DD84C  0x021DD84C  arm  ov175
 *   g_021E4C88  0x021E4C88  data
 *   g_021E387C  0x021E387C  data
 */
struct SAKERequestInternal_021DD98C;
typedef struct SAKEIRequestInfo {
    int f0;
    char *soapTag;
    char pad8[0x14 - 0x8];
    int (*validateInputFunc)(struct SAKERequestInternal_021DD98C *);
    int (*fillFunc)(struct SAKERequestInternal_021DD98C *);
    int f1C;
    void (*cleanupFunc)(struct SAKERequestInternal_021DD98C *);
} SAKEIRequestInfo;

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
    SAKEIRequestInfo *mInfo;
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

extern void *func_021819B0(const char **namespaces, int count);
extern int func_021829AC(void *stream, char *namespaceName, char *tag);
extern int func_02182CF0(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int func_02182AC0(void *stream, char *namespaceName, char *tag, char *value);
extern void func_02181D84(void **p);
extern int func_02182A2C(void *stream, char *namespaceName, char *tag);
extern int func_02181DE8(void *stream);
extern int func_02084F80(char *dst, unsigned long len, const char *fmt, ...);
extern GSSoapTask *func_0217FD7C(char *url, char *service, void *soap, void (*callback)(int, void *, void *), void *userData);
extern void func_021DD84C(int httpResult, int unused, void *responseData, void *userData);
int func_021DD98C(SAKERequestInternal_021DD98C *request);
void func_021DDA98(SAKERequestInternal_021DDA98 *request);
int func_021DDB10(void *p, int v);
extern char *g_021E370C[1];
extern char g_021E3858[];
extern char g_021E385C[];
extern char g_021E3864[];
extern char g_021E3870[];
extern char g_021E4C88[128];
extern char g_021E387C[];


int func_021DD98C(SAKERequestInternal_021DD98C *request)
{
    SAKEIRequestInfo *info = request->mInfo;
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
