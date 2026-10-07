/*
 * file:     unit_021E06DC.c
 * unit:     yes
 * function: func_021E06DC, func_021E0730, func_021E0764, func_021E0774, func_021E08E8, func_021E0A7C, func_021E0C68, func_021E0D84, func_021E0DB8, func_021E0FE8
 * address:  0x021E06DC
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
 *   func_0217CE1C  0x0217CE1C  arm
 *   func_0217CCCC  0x0217CCCC  arm  ov009
 *   func_021819B0  0x021819B0  arm  ov009
 *   func_021829AC  0x021829AC  arm  ov009
 *   func_021E2874  0x021E2874  arm  ov175
 *   func_02182A2C  0x02182A2C  arm  ov009
 *   func_02182E90  0x02182E90  arm  ov009
 *   func_02182CF0  0x02182CF0  arm  ov009
 *   func_02181DE8  0x02181DE8  arm  ov009
 *   func_02181D84  0x02181D84  arm  ov009
 *   func_0217FD7C  0x0217FD7C  arm  ov009
 *   g_021E41B8  0x021E41B8  data
 *   g_021E41E4  0x021E41E4  data
 *   g_021E41E8  0x021E41E8  data
 *   g_021E41F8  0x021E41F8  data
 *   g_021E4204  0x021E4204  data
 *   g_021E420C  0x021E420C  data
 *   g_021E52B4  0x021E52B4  data
 *   g_021E4214  0x021E4214  data
 *   func_021834D0  0x021834D0  arm  ov009
 *   func_021834E8  0x021834E8  arm  ov009
 *   func_02183A24  0x02183A24  arm  ov009
 *   func_0218372C  0x0218372C  arm  ov009
 *   func_021DF928  0x021DF928  arm  ov175
 *   func_021DF948  0x021DF948  arm  ov175
 *   g_021E4250  0x021E4250  data
 *   g_021E4268  0x021E4268  data
 *   g_021E4288  0x021E4288  data
 *   g_021E429C  0x021E429C  data
 *   g_021E42BC  0x021E42BC  data
 *   g_021E42C4  0x021E42C4  data
 *   g_021E42CC  0x021E42CC  data
 *   g_021E42D4  0x021E42D4  data
 *   g_021E42E8  0x021E42E8  data
 *   g_021E42F8  0x021E42F8  data
 *   func_02182AC0  0x02182AC0  arm  ov009
 *   g_021E4338  0x021E4338  data
 *   g_021E4354  0x021E4354  data
 *   func_021C24B4  0x021C24B4  arm  ov114
 *   g_021E4370    0x021E4370  data
 *   g_021E4378    0x021E4378  data
 *   g_021E4388  0x021E4388  data
 *   g_021E4398  0x021E4398  data
 *   func_0217FE68  0x0217FE68  arm  ov009
 *   g_021E43D4  0x021E43D4  data
 *   g_021E43EC  0x021E43EC  data
 */
struct GHIPost;
struct SCIRequest;
typedef int s32;

typedef unsigned int u32_021E06DC;

typedef void (*SCWebCallback)(void *, int, int, void *);

typedef struct {
    void *mInterface;
    SCWebCallback mCreateSessionCallback;
    SCWebCallback mSetReportIntentionCallback;
    SCWebCallback mSubmitReportDataCallback;
    int mSetReportIntentionPending;
    int mCreateSessionPending;
    int mSubmitReportPending;
    int mGetStatsPending;
    int mGetLeaderboardPending;
    int mGetRanksPending;
    void *mSetReportIntentionUserData;
    void *mCreateSessionUserData;
    void *mSubmitReportUserData;
    void *mGetStatsUserData;
    void *mGetLeaderboardUserData;
    void *mGetRanksUserData;
    unsigned char *mSubmitReportData;
    unsigned int mSubmitReportLength;
    int mInit;
} SCWebServices;

typedef struct {
    char pad[0x208];
    char mKeyHash[16];
} GSLoginCertificatePrivate_021E0774;

typedef struct GSLoginCertificate GSLoginCertificate;

typedef struct GSLoginCertificatePrivate_021E0A7C {
    unsigned char mPrivateKey[0x208];
    unsigned char mKeyHash[16];
} GSLoginCertificatePrivate_021E0A7C;

typedef unsigned long u32_021E0D84;

typedef struct GSLoginCertificatePrivate_021E0DB8 {
    unsigned char mPrivateKey[0x208];
    unsigned char mKeyHash[16];
} GSLoginCertificatePrivate_021E0DB8;

typedef struct SCIReportBuffer {
    unsigned int mPos;
    unsigned char *mData;
} SCIReportBuffer;

typedef struct SCIReport {
    unsigned char pad0[0x120];
    SCIReportBuffer mBuffer;
} SCIReport;

struct SCIRequest {
    void *ws;
    char pad0[0xc - 4];
    void (*callback)(void *, int, int, void *);
    char pad1[0x18 - 0x10];
    int f18;
    char pad2[0x30 - 0x1c];
    void *userData;
    char pad3[0x48 - 0x34];
    int active;
};

extern s32 func_0217CE1C(void);
extern void func_0217CCCC(unsigned int theMS);
extern void *func_021819B0(const char **namespaces, int count);
extern int func_021829AC(void *stream, char *namespaceName, char *tag);
extern int func_021E2874(struct GSLoginCertificate *cert, char *aNamespace, void *writer);
extern int func_02182A2C(void *stream, char *namespaceName, char *tag);
extern int func_02182E90(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
extern int func_02182CF0(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int func_02181DE8(void *stream);
extern void func_02181D84(void **p);
extern void *func_0217FD7C(char *theURL, char *theService, void *theRequestSoap, void (*cb)(int, void *, void *, void *), void *theUserData);
extern int func_021834D0(int *p);
extern int func_021834E8(void *stream, char *matchtag);
extern int func_02183A24(void *stream, char *matchtag, int *valueOut);
extern int func_0218372C(void *stream, char *matchtag, char *valueOut, int maxLen);
extern void func_021DF928(char *obj, int v);
extern void func_021DF948(char *obj, int v);
extern int func_02182AC0(void *stream, char *namespaceName, char *tag, char *value);
extern int func_021C24B4(struct GHIPost *_post, char *name, char *buffer, int bufferLen, char *reportFilename, char *contentType);
extern void *func_0217FE68(char *theURL, char *theService, void *theRequestSoap,
                           void (*theCallbackFunc)(int, void *, void *, void *),
                           void (*theRequestFunc)(void *, void *), void *theUserData);
s32 func_021E06DC(char *p, u32_021E06DC v);
void func_021E0730(char *p);
void func_021E0764(void *p);
int func_021E0774(SCWebServices *theWebServices, unsigned int theGameId, GSLoginCertificate *theCertificate, GSLoginCertificatePrivate_021E0774 *thePrivateData, SCWebCallback theCallback, int unused, void *theUserData);
void func_021E08E8(int theHttpResult, int unused, void *theResponseData, void *theUserData);
int func_021E0A7C(SCWebServices *theWebServices, unsigned int theGameId, char *theSessionId, char *theConnectionId, int isAuthoritative, GSLoginCertificate *theCertificate, GSLoginCertificatePrivate_021E0A7C *thePrivateData, SCWebCallback theCallback, unsigned int theTimeoutMs, void *theUserData);
void func_021E0C68(int theHttpResult, int unused, void *theResponseData, void *theUserData);
void func_021E0D84(char *a, char *b);
int func_021E0DB8(SCWebServices *theWebServices, unsigned int theGameId, char *theSessionId, char *theConnectionId, SCIReport *theReport, int isAuthoritative, GSLoginCertificate *theCertificate, GSLoginCertificatePrivate_021E0DB8 *thePrivateData, SCWebCallback theCallback, unsigned int theTimeoutMs, void *theUserData);
void func_021E0FE8(int theHttpResult, int unused, void *theResponseData, struct SCIRequest *theUserData);
extern char *g_021E41B8[1];
extern char g_021E41E4[];
extern char g_021E41E8[];
extern char g_021E41F8[];
extern char g_021E4204[];
extern char g_021E420C[];
extern char g_021E52B4[];
extern char g_021E4214[];
extern char g_021E4250[];
extern char g_021E4268[];
extern char g_021E4288[];
extern char g_021E429C[];
extern char g_021E42BC[];
extern char g_021E42C4[];
extern char g_021E42CC[];
extern char g_021E42D4[];
extern char g_021E42E8[];
extern char g_021E42F8[];
extern char g_021E4338[];
extern char g_021E4354[];
extern u32_021E0D84 g_021E4370[];
extern u32_021E0D84 g_021E4378[];
extern char g_021E4388[];
extern char g_021E4398[];
extern char g_021E43D4[];
extern char g_021E43EC[];


s32 func_021E06DC(char *p, u32_021E06DC v)
{
    u32_021E06DC z = 0;

    if (func_0217CE1C() != 0)
        return 4;
    *(u32_021E06DC *)(p + 0x00) = v;
    *(u32_021E06DC *)(p + 0x04) = z;
    *(u32_021E06DC *)(p + 0x08) = z;
    *(u32_021E06DC *)(p + 0x0c) = z;
    *(u32_021E06DC *)(p + 0x2c) = z;
    *(u32_021E06DC *)(p + 0x28) = z;
    *(u32_021E06DC *)(p + 0x30) = z;
    *(u32_021E06DC *)(p + 0x14) = z;
    *(u32_021E06DC *)(p + 0x10) = z;
    *(u32_021E06DC *)(p + 0x18) = z;
    *(u32_021E06DC *)(p + 0x48) = 1;
    return 0;
}

/*
 * ARM leaf reset: clear the eleven words of the state block, in the order
 * the image writes them.
 */
void func_021E0730(char *p)
{
    *(int *)(p + 0x48) = 0;
    *(int *)(p + 4) = 0;
    *(int *)(p + 8) = 0;
    *(int *)(p + 0xc) = 0;
    *(int *)(p + 0x2c) = 0;
    *(int *)(p + 0x28) = 0;
    *(int *)(p + 0x30) = 0;
    *(int *)(p + 0x14) = 0;
    *(int *)(p + 0x10) = 0;
    *(int *)(p + 0x18) = 0;
    *(int *)(p + 0) = 0;
}


void func_021E0764(void *p)
{
    func_0217CCCC(0);
}


int func_021E0774(SCWebServices *theWebServices, unsigned int theGameId, GSLoginCertificate *theCertificate,
                  GSLoginCertificatePrivate_021E0774 *thePrivateData, SCWebCallback theCallback, int unused,
                  void *theUserData)
{
    void *aRequest;

    if (theWebServices->mCreateSessionPending)
        return 6;
    aRequest = func_021819B0((const char **)g_021E41B8, 1);
    if (!aRequest)
        return 5;
    if (!func_021829AC(aRequest, g_021E41E4, g_021E41E8) ||
        !func_021829AC(aRequest, g_021E41E4, g_021E41F8) ||
        !func_021E2874(theCertificate, g_021E41E4, aRequest) ||
        !func_02182A2C(aRequest, g_021E41E4, g_021E41F8) ||
        !func_02182E90(aRequest, g_021E41E4, g_021E4204, (unsigned char *)thePrivateData->mKeyHash, 16) ||
        !func_02182CF0(aRequest, g_021E41E4, g_021E420C, theGameId) ||
        !func_02182A2C(aRequest, g_021E41E4, g_021E41E8) ||
        !func_02181DE8(aRequest)) {
        func_02181D84(aRequest);
        return 7;
    }
    theWebServices->mCreateSessionCallback = theCallback;
    theWebServices->mCreateSessionUserData = theUserData;
    theWebServices->mCreateSessionPending = 1;
    func_0217FD7C(g_021E52B4, g_021E4214, aRequest, (void (*)(int, void *, void *, void *))func_021E08E8, theWebServices);
    return 0;
}


void func_021E08E8(int theHttpResult, int unused, void *theResponseData, void *theUserData)
{
    int aTranslatedResult = 7;
    SCWebServices *aWebServices = (SCWebServices *)theUserData;
    char csid[255];
    char ccid[255];
    int createResult;

    if (!aWebServices->mInit)
        return;
    if (theHttpResult == 0) {
        createResult = 0;
        if (!func_021834D0(theResponseData))
            aTranslatedResult = 9;
        else if (!func_021834E8(theResponseData, g_021E4250) && !func_021834E8(theResponseData, g_021E4268))
            aTranslatedResult = 9;
        if (!func_021834E8(theResponseData, g_021E4288) && !func_021834E8(theResponseData, g_021E429C))
            aTranslatedResult = 9;
        if (!func_02183A24(theResponseData, g_021E42BC, &createResult))
            aTranslatedResult = 9;
        else if (aTranslatedResult != 9) {
            if (createResult == 0) {
                if (!func_0218372C(theResponseData, g_021E42C4, csid, 255) ||
                    !func_0218372C(theResponseData, g_021E42CC, ccid, 255)) {
                    aTranslatedResult = 9;
                } else {
                    func_021DF928(aWebServices->mInterface, (int)csid);
                    func_021DF948(aWebServices->mInterface, (int)ccid);
                    aTranslatedResult = 0;
                }
            } else {
                aTranslatedResult = 9;
            }
        }
    }
    aWebServices->mCreateSessionPending = 0;
    if (aWebServices->mCreateSessionCallback) {
        aWebServices->mCreateSessionCallback(aWebServices->mInterface, theHttpResult, aTranslatedResult,
                                             aWebServices->mCreateSessionUserData);
        aWebServices->mCreateSessionUserData = 0;
        aWebServices->mCreateSessionCallback = 0;
    }
}


/*
 * sdk:      sciWsSetReportIntention (sciwebservices.o)
 *
 * The DWARF prototype places theUserData at fb+60 after theCallback at fb+52; the
 * object reads the user data one word past the callback, so an unused word parameter
 * (theTimeoutMs here) sits between them.
 */
int func_021E0A7C(SCWebServices *theWebServices, unsigned int theGameId, char *theSessionId,
                  char *theConnectionId, int isAuthoritative, GSLoginCertificate *theCertificate,
                  GSLoginCertificatePrivate_021E0A7C *thePrivateData, SCWebCallback theCallback,
                  unsigned int theTimeoutMs, void *theUserData)
{
    void *aRequest;

    if (theWebServices->mSetReportIntentionPending)
        return 6;
    aRequest = func_021819B0((const char **)g_021E41B8, 1);
    if (aRequest == 0)
        return 5;
    if (!func_021829AC(aRequest, g_021E41E4, g_021E42D4) ||
        !func_021829AC(aRequest, g_021E41E4, g_021E41F8) ||
        !func_021E2874(theCertificate, g_021E41E4, aRequest) ||
        !func_02182A2C(aRequest, g_021E41E4, g_021E41F8) ||
        !func_02182E90(aRequest, g_021E41E4, g_021E4204, thePrivateData->mKeyHash, 16) ||
        !func_02182AC0(aRequest, g_021E41E4, g_021E42C4, theSessionId) ||
        !func_02182AC0(aRequest, g_021E41E4, g_021E42CC, theConnectionId) ||
        !func_02182CF0(aRequest, g_021E41E4, g_021E420C, theGameId) ||
        !func_02182CF0(aRequest, g_021E41E4, g_021E42E8, isAuthoritative ? 1 : 0) ||
        !func_02182A2C(aRequest, g_021E41E4, g_021E42D4) ||
        !func_02181DE8(aRequest)) {
        func_02181D84(aRequest);
        return 7;
    }
    theWebServices->mSetReportIntentionCallback = theCallback;
    theWebServices->mSetReportIntentionUserData = theUserData;
    theWebServices->mSetReportIntentionPending = 1;
    func_0217FD7C(g_021E52B4, g_021E42F8, aRequest, (void (*)(int, void *, void *, void *))func_021E0C68, theWebServices);
    return 0;
}


/*
 * sdk:      sciWsSetReportIntentionCallback (libdwcgssc.TWL.HYB.a sciwebservices.o)
 */
void func_021E0C68(int theHttpResult, int unused, void *theResponseData, void *theUserData)
{
    SCWebServices *aWebServices = (SCWebServices *)theUserData;
    int aTranslatedResult;
    char ccid[255];
    int intentionResult;

    if (!aWebServices->mInit)
        return;
    if (theHttpResult == 0) {
        aTranslatedResult = 0;
        intentionResult = 0;
        if (!func_021834D0(theResponseData) || !func_021834E8(theResponseData, g_021E4338) ||
            !func_021834E8(theResponseData, g_021E4354) ||
            !func_02183A24(theResponseData, g_021E42BC, &intentionResult) ||
            !func_0218372C(theResponseData, g_021E42CC, ccid, 255)) {
            aTranslatedResult = 9;
        } else if (intentionResult != 0) {
            aTranslatedResult = 8;
        } else {
            func_021DF948(aWebServices->mInterface, (int)ccid);
        }
    } else {
        aTranslatedResult = 7;
    }
    aWebServices->mSetReportIntentionPending = 0;
    if (aWebServices->mSetReportIntentionCallback) {
        aWebServices->mSetReportIntentionCallback(aWebServices->mInterface, theHttpResult,
                                                  aTranslatedResult,
                                                  aWebServices->mSetReportIntentionUserData);
        aWebServices->mSetReportIntentionUserData = 0;
        aWebServices->mSetReportIntentionCallback = 0;
    }
}


/*
 * Hand the +0x40/+0x44 pair of the source block to 0x021C24B4 together with
 * the 0x021E4370 and 0x021E4378 tables.
 */
void func_021E0D84(char *a, char *b)
{
    func_021C24B4((struct GHIPost *)a, (char *)((u32_021E0D84)g_021E4370), (char *)(*(int *)(b + 0x40)), *(int *)(b + 0x44),
                  (char *)((u32_021E0D84)g_021E4370), (char *)((u32_021E0D84)g_021E4378));
}


/*
 * sdk:      sciWsSubmitReport (sciwebservices.o)
 *
 * The DWARF prototype places theUserData at fb+72 after theCallback at fb+64; the
 * object reads the user data one word past the callback, so an unused word parameter
 * (theTimeoutMs here) sits between them.
 */
int func_021E0DB8(SCWebServices *theWebServices, unsigned int theGameId, char *theSessionId,
                  char *theConnectionId, SCIReport *theReport, int isAuthoritative,
                  GSLoginCertificate *theCertificate, GSLoginCertificatePrivate_021E0DB8 *thePrivateData,
                  SCWebCallback theCallback, unsigned int theTimeoutMs, void *theUserData)
{
    void *aRequest;

    if (theWebServices->mSubmitReportPending)
        return 6;
    if (theReport->mBuffer.mPos < 0x44)
        return 12;
    aRequest = func_021819B0((const char **)g_021E41B8, 1);
    if (aRequest == 0)
        return 5;
    if (!func_021829AC(aRequest, g_021E41E4, g_021E4388) ||
        !func_021829AC(aRequest, g_021E41E4, g_021E41F8) ||
        !func_021E2874(theCertificate, g_021E41E4, aRequest) ||
        !func_02182A2C(aRequest, g_021E41E4, g_021E41F8) ||
        !func_02182E90(aRequest, g_021E41E4, g_021E4204, thePrivateData->mKeyHash, 16) ||
        !func_02182AC0(aRequest, g_021E41E4, g_021E42C4, theSessionId) ||
        !func_02182AC0(aRequest, g_021E41E4, g_021E42CC, theConnectionId) ||
        !func_02182CF0(aRequest, g_021E41E4, g_021E420C, theGameId) ||
        !func_02182CF0(aRequest, g_021E41E4, g_021E42E8, isAuthoritative ? 1 : 0) ||
        !func_02182A2C(aRequest, g_021E41E4, g_021E4388) ||
        !func_02181DE8(aRequest)) {
        func_02181D84(aRequest);
        return 5;
    }
    theWebServices->mSubmitReportData = theReport->mBuffer.mData;
    theWebServices->mSubmitReportLength = theReport->mBuffer.mPos;
    theWebServices->mSubmitReportDataCallback = theCallback;
    theWebServices->mSubmitReportUserData = theUserData;
    theWebServices->mSubmitReportPending = 1;
    func_0217FE68(g_021E52B4, g_021E4398, aRequest, (void (*)(int, void *, void *, void *))func_021E0FE8,
                  (void (*)(void *, void *))func_021E0D84, theWebServices);
    return 0;
}


/*
 * sdk:      sciWsSubmitReportCallback (libdwcgssc.TWL.HYB.a(sciwebservices.o))
 */
void func_021E0FE8(int theHttpResult, int unused, void *theResponseData, struct SCIRequest *theUserData)
{
    int submitResult;
    int aTranslatedResult;

    if (theUserData->active == 0)
        return;
    if (theHttpResult == 0) {
        aTranslatedResult = 0;
        submitResult = 0;
        if (!func_021834D0(theResponseData)
            || !func_021834E8(theResponseData, g_021E43D4)
            || !func_021834E8(theResponseData, g_021E43EC)
            || !func_02183A24(theResponseData, g_021E42BC, &submitResult)) {
            aTranslatedResult = 9;
        } else if (submitResult != 0) {
            if (submitResult == 7)
                aTranslatedResult = 12;
            else
                aTranslatedResult = 8;
        }
    } else {
        aTranslatedResult = 7;
    }
    theUserData->f18 = 0;
    if (theUserData->callback != 0) {
        theUserData->callback(theUserData->ws, theHttpResult, aTranslatedResult, theUserData->userData);
        theUserData->userData = 0;
        theUserData->callback = 0;
    }
}
