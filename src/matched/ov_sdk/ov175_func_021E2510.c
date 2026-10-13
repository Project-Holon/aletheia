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
 *   func_021819B0  0x021819B0  arm  ov009
 *   func_021829AC  0x021829AC  arm  ov009
 *   func_02182CF0  0x02182CF0  arm  ov009
 *   func_02182AC0  0x02182AC0  arm  ov009
 *   func_02182A2C  0x02182A2C  arm  ov009
 *   func_02181DE8  0x02181DE8  arm  ov009
 *   func_02181D84  0x02181D84  arm  ov009
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
extern void *func_021819B0(const char **namespaces, int count);
extern int func_021829AC(void *stream, char *namespaceName, char *tag);
extern int func_02182CF0(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int func_02182AC0(void *stream, char *namespaceName, char *tag, char *value);
extern int func_02182A2C(void *stream, char *namespaceName, char *tag);
extern int func_02181DE8(void *stream);
extern void func_02181D84(void **p);
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
    writer = func_021819B0((const char **)gWsSoapNamespaces, 1);
    if (writer == 0)
        return 0x68;
    if (!func_021829AC(writer, sWsNamespaceNs1, sWsTagLoginRemoteAuth)
        || !func_02182CF0(writer, sWsNamespaceNs1, sWsTagVersion, 1)
        || !func_02182CF0(writer, sWsNamespaceNs1, sWsTagPartnerCode, partnerCode)
        || !func_02182CF0(writer, sWsNamespaceNs1, sWsTagNamespaceId, namespaceId)
        || !func_02182AC0(writer, sWsNamespaceNs1, sWsTagAuthToken, authtoken)
        || !func_02182AC0(writer, sWsNamespaceNs1, sWsTagChallenge, partnerChallenge)
        || !func_02182A2C(writer, sWsNamespaceNs1, sWsTagLoginRemoteAuth)
        || !func_02181DE8(writer)) {
        func_02181D84(writer);
        return 0x68;
    }
    aTask = func_0217FD7C(gWsAuthServiceUrl, sWsSoapActionLoginRemoteAuth, writer, wsLoginRemoteAuthCallback, requestData);
    if (aTask == 0) {
        func_02181D84(writer);
        func_0217EAE0(requestData);
        return 0x68;
    }
    return 0;
}
