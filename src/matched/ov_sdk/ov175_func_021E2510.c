/*
 * function: wsLoginRemoteAuth
 * address:  0x021E2510
 * packet:   pkt_ov175_021E2510
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      wsLoginRemoteAuth (libdwcgswebservices.TWL.HYB.a(authservice.o))
 *
 * symbols:
 *   wsiServiceAvailable  0x021E2290  arm  ov175
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   gsXmlCreateStreamWriter  0x021819B0  arm  ov009
 *   gsXmlWriteOpenTag  0x021829AC  arm  ov009
 *   gsXmlWriteIntElement  0x02182CF0  arm  ov009
 *   gsXmlWriteStringElement  0x02182AC0  arm  ov009
 *   gsXmlWriteCloseTag  0x02182A2C  arm  ov009
 *   gsXmlCloseWriter  0x02181DE8  arm  ov009
 *   gsXmlFreeWriter  0x02181D84  arm  ov009
 *   func_0217FD7C  0x0217FD7C  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   wsLoginRemoteAuthCallback  0x021E2354  arm  ov175
 *   gWsSoapNamespaces  0x021E49A4  data
 *   sWsNamespaceNs1  0x021E4A58  data
 *   sWsTagLoginRemoteAuth  0x021E4AAC  data
 *   sWsTagVersion  0x021E4A5C  data
 *   sWsTagPartnerCode  0x021E4A64  data
 *   sWsTagNamespaceId  0x021E4A70  data
 *   sWsTagAuthToken  0x021E4ABC  data
 *   sWsTagChallenge  0x021E4AC8  data
 *   gWsAuthServiceUrl  0x021E53BC  data
 *   sWsSoapActionLoginRemoteAuth  0x021E4AD4  data
 */

typedef struct {
    void *mUserCallback;
    void *mUserData;
} WSIRequestData;

extern int wsiServiceAvailable(void);
extern void *func_0217EAB0(unsigned long size);
extern void *gsXmlCreateStreamWriter(const char **namespaces, int count);
extern int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteIntElement(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int gsXmlWriteStringElement(void *stream, char *namespaceName, char *tag, char *value);
extern int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlCloseWriter(void *stream);
extern void gsXmlFreeWriter(void **p);
extern void *func_0217FD7C(char *theURL, char *theService, void *theRequestSoap, void *theCallbackFunc, void *theUserData);
extern void func_0217EAE0(void *ptr);
extern void wsLoginRemoteAuthCallback(int theResult, void *theRequestXml, void *theResponseXml, void *theRequestData);
extern char *gWsSoapNamespaces[];
extern char sWsNamespaceNs1[];
extern char sWsTagLoginRemoteAuth[];
extern char sWsTagVersion[];
extern char sWsTagPartnerCode[];
extern char sWsTagNamespaceId[];
extern char sWsTagAuthToken[];
extern char sWsTagChallenge[];
extern char gWsAuthServiceUrl[];
extern char sWsSoapActionLoginRemoteAuth[];

int wsLoginRemoteAuth(int partnerCode, int namespaceId, char *authtoken, char *partnerChallenge, void *userCallback, void *userData)
{
    void *writer;
    WSIRequestData *requestData;
    void *aTask;

    if (!wsiServiceAvailable())
        return 0x6a;
    requestData = (WSIRequestData *)func_0217EAB0(sizeof(WSIRequestData));
    if (requestData == 0)
        return 0x68;
    requestData->mUserCallback = userCallback;
    requestData->mUserData = userData;
    writer = gsXmlCreateStreamWriter((const char **)gWsSoapNamespaces, 1);
    if (writer == 0)
        return 0x68;
    if (!gsXmlWriteOpenTag(writer, sWsNamespaceNs1, sWsTagLoginRemoteAuth)
        || !gsXmlWriteIntElement(writer, sWsNamespaceNs1, sWsTagVersion, 1)
        || !gsXmlWriteIntElement(writer, sWsNamespaceNs1, sWsTagPartnerCode, partnerCode)
        || !gsXmlWriteIntElement(writer, sWsNamespaceNs1, sWsTagNamespaceId, namespaceId)
        || !gsXmlWriteStringElement(writer, sWsNamespaceNs1, sWsTagAuthToken, authtoken)
        || !gsXmlWriteStringElement(writer, sWsNamespaceNs1, sWsTagChallenge, partnerChallenge)
        || !gsXmlWriteCloseTag(writer, sWsNamespaceNs1, sWsTagLoginRemoteAuth)
        || !gsXmlCloseWriter(writer)) {
        gsXmlFreeWriter(writer);
        return 0x68;
    }
    aTask = func_0217FD7C(gWsAuthServiceUrl, sWsSoapActionLoginRemoteAuth, writer, wsLoginRemoteAuthCallback, requestData);
    if (aTask == 0) {
        gsXmlFreeWriter(writer);
        func_0217EAE0(requestData);
        return 0x68;
    }
    return 0;
}
