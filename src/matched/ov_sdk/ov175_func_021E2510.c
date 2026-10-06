/*
 * function: func_021E2510
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
 *   func_021E2290  0x021E2290  arm  ov175
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
 *   func_021E2354  0x021E2354  arm  ov175
 *   g_021E49A4  0x021E49A4  data
 *   g_021E4A58  0x021E4A58  data
 *   g_021E4AAC  0x021E4AAC  data
 *   g_021E4A5C  0x021E4A5C  data
 *   g_021E4A64  0x021E4A64  data
 *   g_021E4A70  0x021E4A70  data
 *   g_021E4ABC  0x021E4ABC  data
 *   g_021E4AC8  0x021E4AC8  data
 *   g_021E53BC  0x021E53BC  data
 *   g_021E4AD4  0x021E4AD4  data
 */

typedef struct {
    void *mUserCallback;
    void *mUserData;
} WSIRequestData;

extern int func_021E2290(void);
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
extern void func_021E2354(int theResult, void *theRequestXml, void *theResponseXml, void *theRequestData);
extern char *g_021E49A4[];
extern char g_021E4A58[];
extern char g_021E4AAC[];
extern char g_021E4A5C[];
extern char g_021E4A64[];
extern char g_021E4A70[];
extern char g_021E4ABC[];
extern char g_021E4AC8[];
extern char g_021E53BC[];
extern char g_021E4AD4[];

int func_021E2510(int partnerCode, int namespaceId, char *authtoken, char *partnerChallenge, void *userCallback, void *userData)
{
    void *writer;
    WSIRequestData *requestData;
    void *aTask;

    if (!func_021E2290())
        return 0x6a;
    requestData = (WSIRequestData *)func_0217EAB0(sizeof(WSIRequestData));
    if (requestData == 0)
        return 0x68;
    requestData->mUserCallback = userCallback;
    requestData->mUserData = userData;
    writer = func_021819B0((const char **)g_021E49A4, 1);
    if (writer == 0)
        return 0x68;
    if (!func_021829AC(writer, g_021E4A58, g_021E4AAC)
        || !func_02182CF0(writer, g_021E4A58, g_021E4A5C, 1)
        || !func_02182CF0(writer, g_021E4A58, g_021E4A64, partnerCode)
        || !func_02182CF0(writer, g_021E4A58, g_021E4A70, namespaceId)
        || !func_02182AC0(writer, g_021E4A58, g_021E4ABC, authtoken)
        || !func_02182AC0(writer, g_021E4A58, g_021E4AC8, partnerChallenge)
        || !func_02182A2C(writer, g_021E4A58, g_021E4AAC)
        || !func_02181DE8(writer)) {
        func_02181D84(writer);
        return 0x68;
    }
    aTask = func_0217FD7C(g_021E53BC, g_021E4AD4, writer, func_021E2354, requestData);
    if (aTask == 0) {
        func_02181D84(writer);
        func_0217EAE0(requestData);
        return 0x68;
    }
    return 0;
}
