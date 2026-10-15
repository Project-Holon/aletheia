/*
 * function: sciWsSetReportIntention
 * address:  0x021E0A7C
 * packet:   pkt_ov175_021E0A7C
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sciWsSetReportIntention (sciwebservices.o)
 *
 * symbols:
 *   gSciSoapNamespaces  0x021E41B8  data
 *   sSciNamespaceGsc  0x021E41E4  data
 *   sSciTagSetReportIntention  0x021E42D4  data
 *   sSciTagCertificate  0x021E41F8  data
 *   sSciTagProof  0x021E4204  data
 *   sSciTagCsid  0x021E42C4  data
 *   sSciTagCcid  0x021E42CC  data
 *   sSciTagGameId  0x021E420C  data
 *   sSciTagAuthoritative  0x021E42E8  data
 *   gScStatsServiceUrl  0x021E52B4  data
 *   sSciSoapActionSetReportIntention  0x021E42F8  data
 *   gsXmlCreateStreamWriter  0x021819B0  arm  ov009
 *   gsXmlWriteOpenTag  0x021829AC  arm  ov009
 *   wsLoginCertWriteXML  0x021E2874  arm  ov175
 *   gsXmlWriteCloseTag  0x02182A2C  arm  ov009
 *   gsXmlWriteHexBinaryElement  0x02182E90  arm  ov009
 *   gsXmlWriteStringElement  0x02182AC0  arm  ov009
 *   gsXmlWriteIntElement  0x02182CF0  arm  ov009
 *   gsXmlCloseWriter  0x02181DE8  arm  ov009
 *   gsXmlFreeWriter  0x02181D84  arm  ov009
 *   func_0217FD7C  0x0217FD7C  arm  ov009
 *   sciWsSetReportIntentionCallback  0x021E0C68  arm  ov175
 *
 * The DWARF prototype places theUserData at fb+60 after theCallback at fb+52; the
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

extern char *gSciSoapNamespaces[1];
extern char sSciNamespaceGsc[];
extern char sSciTagSetReportIntention[];
extern char sSciTagCertificate[];
extern char sSciTagProof[];
extern char sSciTagCsid[];
extern char sSciTagCcid[];
extern char sSciTagGameId[];
extern char sSciTagAuthoritative[];
extern char gScStatsServiceUrl[];
extern char sSciSoapActionSetReportIntention[];

extern void *gsXmlCreateStreamWriter(const char **namespaces, int count);
extern int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
extern int wsLoginCertWriteXML(struct GSLoginCertificate *cert, char *aNamespace, void *writer);
extern int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteHexBinaryElement(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
extern int gsXmlWriteStringElement(void *stream, char *namespaceName, char *tag, char *value);
extern int gsXmlWriteIntElement(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int gsXmlCloseWriter(void *stream);
extern void gsXmlFreeWriter(void **p);
extern void *func_0217FD7C(char *theURL, char *theService, void *theRequestSoap,
                           void (*theCallbackFunc)(int, void *, void *, void *), void *theUserData);
extern void sciWsSetReportIntentionCallback(int theHttpResult, int unused, void *theResponseData, void *theUserData);

int sciWsSetReportIntention(SCWebServices *theWebServices, unsigned int theGameId, char *theSessionId,
                  char *theConnectionId, int isAuthoritative, GSLoginCertificate *theCertificate,
                  GSLoginCertificatePrivate *thePrivateData, SCWebCallback theCallback,
                  unsigned int theTimeoutMs, void *theUserData)
{
    void *aRequest;

    if (theWebServices->mSetReportIntentionPending)
        return 6;
    aRequest = gsXmlCreateStreamWriter((const char **)gSciSoapNamespaces, 1);
    if (aRequest == 0)
        return 5;
    if (!gsXmlWriteOpenTag(aRequest, sSciNamespaceGsc, sSciTagSetReportIntention) ||
        !gsXmlWriteOpenTag(aRequest, sSciNamespaceGsc, sSciTagCertificate) ||
        !wsLoginCertWriteXML(theCertificate, sSciNamespaceGsc, aRequest) ||
        !gsXmlWriteCloseTag(aRequest, sSciNamespaceGsc, sSciTagCertificate) ||
        !gsXmlWriteHexBinaryElement(aRequest, sSciNamespaceGsc, sSciTagProof, thePrivateData->mKeyHash, 16) ||
        !gsXmlWriteStringElement(aRequest, sSciNamespaceGsc, sSciTagCsid, theSessionId) ||
        !gsXmlWriteStringElement(aRequest, sSciNamespaceGsc, sSciTagCcid, theConnectionId) ||
        !gsXmlWriteIntElement(aRequest, sSciNamespaceGsc, sSciTagGameId, theGameId) ||
        !gsXmlWriteIntElement(aRequest, sSciNamespaceGsc, sSciTagAuthoritative, isAuthoritative ? 1 : 0) ||
        !gsXmlWriteCloseTag(aRequest, sSciNamespaceGsc, sSciTagSetReportIntention) ||
        !gsXmlCloseWriter(aRequest)) {
        gsXmlFreeWriter(aRequest);
        return 7;
    }
    theWebServices->mSetReportIntentionCallback = theCallback;
    theWebServices->mSetReportIntentionUserData = theUserData;
    theWebServices->mSetReportIntentionPending = 1;
    func_0217FD7C(gScStatsServiceUrl, sSciSoapActionSetReportIntention, aRequest, (void (*)(int, void *, void *, void *))sciWsSetReportIntentionCallback, theWebServices);
    return 0;
}
