/*
 * function: func_021E0774
 * address:  0x021E0774
 * packet:   pkt_ov175_021E0774
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sciWsCreateSession (libdwcgssc.TWL.HYB.a sciwebservices.o)
 *
 * symbols:
 *   func_021819B0  0x021819B0  arm  ov009
 *   func_021829AC  0x021829AC  arm  ov009
 *   func_021E2874  0x021E2874  arm  ov175
 *   func_02182A2C  0x02182A2C  arm  ov009
 *   func_02182E90  0x02182E90  arm  ov009
 *   func_02182CF0  0x02182CF0  arm  ov009
 *   func_02181DE8  0x02181DE8  arm  ov009
 *   func_02181D84  0x02181D84  arm  ov009
 *   func_0217FD7C  0x0217FD7C  arm  ov009
 *   func_021E08E8  0x021E08E8  arm  ov175
 *   g_021E41B8  0x021E41B8  data
 *   g_021E41E4  0x021E41E4  data
 *   g_021E41E8  0x021E41E8  data
 *   g_021E41F8  0x021E41F8  data
 *   g_021E4204  0x021E4204  data
 *   g_021E420C  0x021E420C  data
 *   g_021E52B4  0x021E52B4  data
 *   g_021E4214  0x021E4214  data
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
typedef struct {
    char pad[0x208];
    char mKeyHash[16];
} GSLoginCertificatePrivate;
typedef struct GSLoginCertificate GSLoginCertificate;

extern void *func_021819B0(const char **namespaces, int count);
extern int func_021829AC(void *stream, char *namespaceName, char *tag);
extern int func_021E2874(struct GSLoginCertificate *cert, char *aNamespace, void *writer);
extern int func_02182A2C(void *stream, char *namespaceName, char *tag);
extern int func_02182E90(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
extern int func_02182CF0(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int func_02181DE8(void *stream);
extern void func_02181D84(void **p);
extern void *func_0217FD7C(char *theURL, char *theService, void *theRequestSoap, void (*cb)(int, void *, void *, void *), void *theUserData);
extern void func_021E08E8(int theHttpResult, int unused, void *theResponseData, void *theUserData);
extern char *g_021E41B8[1];
extern char g_021E41E4[];
extern char g_021E41E8[];
extern char g_021E41F8[];
extern char g_021E4204[];
extern char g_021E420C[];
extern char g_021E52B4[];
extern char g_021E4214[];

int func_021E0774(SCWebServices *theWebServices, unsigned int theGameId, GSLoginCertificate *theCertificate,
                  GSLoginCertificatePrivate *thePrivateData, SCWebCallback theCallback, int unused,
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
