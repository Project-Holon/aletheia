/*
 * function: func_021E0DB8
 * address:  0x021E0DB8
 * packet:   pkt_ov175_021E0DB8
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sciWsSubmitReport (sciwebservices.o)
 *
 * symbols:
 *   g_021E41B8  0x021E41B8  data
 *   g_021E41E4  0x021E41E4  data
 *   g_021E4388  0x021E4388  data
 *   g_021E41F8  0x021E41F8  data
 *   g_021E4204  0x021E4204  data
 *   g_021E42C4  0x021E42C4  data
 *   g_021E42CC  0x021E42CC  data
 *   g_021E420C  0x021E420C  data
 *   g_021E42E8  0x021E42E8  data
 *   g_021E52B4  0x021E52B4  data
 *   g_021E4398  0x021E4398  data
 *   func_021819B0  0x021819B0  arm  ov009
 *   func_021829AC  0x021829AC  arm  ov009
 *   func_021E2874  0x021E2874  arm  ov175
 *   func_02182A2C  0x02182A2C  arm  ov009
 *   func_02182E90  0x02182E90  arm  ov009
 *   func_02182AC0  0x02182AC0  arm  ov009
 *   func_02182CF0  0x02182CF0  arm  ov009
 *   func_02181DE8  0x02181DE8  arm  ov009
 *   func_02181D84  0x02181D84  arm  ov009
 *   func_0217FE68  0x0217FE68  arm  ov009
 *   func_021E0D84  0x021E0D84  arm  ov175
 *   func_021E0FE8  0x021E0FE8  arm  ov175
 *
 * The DWARF prototype places theUserData at fb+72 after theCallback at fb+64; the
 * object reads the user data one word past the callback, so an unused word parameter
 * (theTimeoutMs here) sits between them.
 */

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

typedef struct GSLoginCertificate GSLoginCertificate;

typedef struct GSLoginCertificatePrivate {
    unsigned char mPrivateKey[0x208];
    unsigned char mKeyHash[16];
} GSLoginCertificatePrivate;

typedef struct SCIReportBuffer {
    unsigned int mPos;
    unsigned char *mData;
} SCIReportBuffer;

typedef struct SCIReport {
    unsigned char pad0[0x120];
    SCIReportBuffer mBuffer;
} SCIReport;

extern char *g_021E41B8[1];
extern char g_021E41E4[];
extern char g_021E4388[];
extern char g_021E41F8[];
extern char g_021E4204[];
extern char g_021E42C4[];
extern char g_021E42CC[];
extern char g_021E420C[];
extern char g_021E42E8[];
extern char g_021E52B4[];
extern char g_021E4398[];

extern void *func_021819B0(char **namespaces, int count);
extern int func_021829AC(void *stream, char *namespaceName, char *tag);
struct SCIRequest;
extern int func_021E2874(struct GSLoginCertificate *cert, char *aNamespace, void *writer);
extern int func_02182A2C(void *stream, char *namespaceName, char *tag);
extern int func_02182E90(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
extern int func_02182AC0(void *stream, char *namespaceName, char *tag, char *value);
extern int func_02182CF0(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int func_02181DE8(void *stream);
extern void func_02181D84(void **p);
extern void *func_0217FE68(char *theURL, char *theService, void *theRequestSoap,
                           void (*theCallbackFunc)(int, void *, void *, void *),
                           void (*theRequestFunc)(void *, void *), void *theUserData);
extern void func_021E0D84(void *theRequest, void *theUserData);
extern void func_021E0FE8(int theHttpResult, int unused, void *theResponseData, struct SCIRequest *theUserData);

int func_021E0DB8(SCWebServices *theWebServices, unsigned int theGameId, char *theSessionId,
                  char *theConnectionId, SCIReport *theReport, int isAuthoritative,
                  GSLoginCertificate *theCertificate, GSLoginCertificatePrivate *thePrivateData,
                  SCWebCallback theCallback, unsigned int theTimeoutMs, void *theUserData)
{
    void *aRequest;

    if (theWebServices->mSubmitReportPending)
        return 6;
    if (theReport->mBuffer.mPos < 0x44)
        return 12;
    aRequest = func_021819B0(g_021E41B8, 1);
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
                  func_021E0D84, theWebServices);
    return 0;
}
