/*
 * function: sciWsCreateSession
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
 *   gsXmlCreateStreamWriter  0x021819B0  arm  ov009
 *   gsXmlWriteOpenTag  0x021829AC  arm  ov009
 *   wsLoginCertWriteXML  0x021E2874  arm  ov175
 *   gsXmlWriteCloseTag  0x02182A2C  arm  ov009
 *   gsXmlWriteHexBinaryElement  0x02182E90  arm  ov009
 *   gsXmlWriteIntElement  0x02182CF0  arm  ov009
 *   gsXmlCloseWriter  0x02181DE8  arm  ov009
 *   gsXmlFreeWriter  0x02181D84  arm  ov009
 *   func_0217FD7C  0x0217FD7C  arm  ov009
 *   sciWsCreateSessionCallback  0x021E08E8  arm  ov175
 *   gSciSoapNamespaces  0x021E41B8  data
 *   sSciNamespaceGsc  0x021E41E4  data
 *   sSciTagCreateSession  0x021E41E8  data
 *   sSciTagCertificate  0x021E41F8  data
 *   sSciTagProof  0x021E4204  data
 *   sSciTagGameId  0x021E420C  data
 *   gScStatsServiceUrl  0x021E52B4  data
 *   sSciSoapActionCreateSession  0x021E4214  data
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

extern void *gsXmlCreateStreamWriter(const char **namespaces, int count);
extern int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
extern int wsLoginCertWriteXML(struct GSLoginCertificate *cert, char *aNamespace, void *writer);
extern int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteHexBinaryElement(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
extern int gsXmlWriteIntElement(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int gsXmlCloseWriter(void *stream);
extern void gsXmlFreeWriter(void **p);
extern void *func_0217FD7C(char *theURL, char *theService, void *theRequestSoap, void (*cb)(int, void *, void *, void *), void *theUserData);
extern void sciWsCreateSessionCallback(int theHttpResult, int unused, void *theResponseData, void *theUserData);
extern char *gSciSoapNamespaces[1];
extern char sSciNamespaceGsc[];
extern char sSciTagCreateSession[];
extern char sSciTagCertificate[];
extern char sSciTagProof[];
extern char sSciTagGameId[];
extern char gScStatsServiceUrl[];
extern char sSciSoapActionCreateSession[];

int sciWsCreateSession(SCWebServices *theWebServices, unsigned int theGameId, GSLoginCertificate *theCertificate,
                  GSLoginCertificatePrivate *thePrivateData, SCWebCallback theCallback, int unused,
                  void *theUserData)
{
    void *aRequest;

    if (theWebServices->mCreateSessionPending)
        return 6;
    aRequest = gsXmlCreateStreamWriter((const char **)gSciSoapNamespaces, 1);
    if (!aRequest)
        return 5;
    if (!gsXmlWriteOpenTag(aRequest, sSciNamespaceGsc, sSciTagCreateSession) ||
        !gsXmlWriteOpenTag(aRequest, sSciNamespaceGsc, sSciTagCertificate) ||
        !wsLoginCertWriteXML(theCertificate, sSciNamespaceGsc, aRequest) ||
        !gsXmlWriteCloseTag(aRequest, sSciNamespaceGsc, sSciTagCertificate) ||
        !gsXmlWriteHexBinaryElement(aRequest, sSciNamespaceGsc, sSciTagProof, (unsigned char *)thePrivateData->mKeyHash, 16) ||
        !gsXmlWriteIntElement(aRequest, sSciNamespaceGsc, sSciTagGameId, theGameId) ||
        !gsXmlWriteCloseTag(aRequest, sSciNamespaceGsc, sSciTagCreateSession) ||
        !gsXmlCloseWriter(aRequest)) {
        gsXmlFreeWriter(aRequest);
        return 7;
    }
    theWebServices->mCreateSessionCallback = theCallback;
    theWebServices->mCreateSessionUserData = theUserData;
    theWebServices->mCreateSessionPending = 1;
    func_0217FD7C(gScStatsServiceUrl, sSciSoapActionCreateSession, aRequest, (void (*)(int, void *, void *, void *))sciWsCreateSessionCallback, theWebServices);
    return 0;
}
