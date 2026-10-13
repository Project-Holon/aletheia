/*
 * function: sakeiSetupRequest
 * address:  0x021DD98C
 * packet:   pkt_ov175_021DD98C
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sakeiSetupRequest (libdwcgssake.TWL.HYB.a sakerequest.o)
 *
 * symbols:
 *   func_021819B0  0x021819B0  arm   ov009
 *   func_021829AC  0x021829AC  arm   ov009
 *   func_02182CF0  0x02182CF0  arm   ov009
 *   func_02182AC0  0x02182AC0  arm   ov009
 *   func_02181D84  0x02181D84  arm   ov009
 *   func_02182A2C  0x02182A2C  arm   ov009
 *   func_02181DE8  0x02181DE8  arm   ov009
 *   sSoapNamespaces     0x021E370C  data
 *   sXmlNamespacePrefix     0x021E3858  data
 *   sTagGameid     0x021E385C  data
 *   sTagSecretKey     0x021E3864  data
 *   sTagLoginTicket     0x021E3870  data
 */

struct SAKERequestInternal;

typedef struct SAKEIRequestInfo {
    int f0;
    char *soapTag;
    char pad8[0x14 - 0x8];
    int (*validateInputFunc)(struct SAKERequestInternal *);
    int (*fillFunc)(struct SAKERequestInternal *);
    int f1C;
    void (*cleanupFunc)(struct SAKERequestInternal *);
} SAKEIRequestInfo;

typedef struct SAKEI {
    char pad0[0x14];
    unsigned int gameId;
    char gameName[0x2c - 0x18];
    char secretKey[1];
} SAKEI;

typedef struct SAKERequestInternal {
    SAKEI *mSake;
    int mType;
    void *mInput;
    void *mOutput;
    void *mCallback;
    void *mUserData;
    void *mSoapRequest;
    void *mSoapResponse;
    SAKEIRequestInfo *mInfo;
} SAKERequestInternal;

extern void *func_021819B0(const char **namespaces, int count);
extern int func_021829AC(void *stream, char *namespaceName, char *tag);
extern int func_02182CF0(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int func_02182AC0(void *stream, char *namespaceName, char *tag, char *value);
extern void func_02181D84(void **p);
extern int func_02182A2C(void *stream, char *namespaceName, char *tag);
extern int func_02181DE8(void *stream);
extern char *sSoapNamespaces[1];
extern char sXmlNamespacePrefix[];
extern char sTagGameid[];
extern char sTagSecretKey[];
extern char sTagLoginTicket[];

int sakeiSetupRequest(SAKERequestInternal *request)
{
    SAKEIRequestInfo *info = request->mInfo;
    int result;

    result = info->validateInputFunc(request);
    if (result != 0)
        return result;
    request->mSoapRequest = func_021819B0((const char **)sSoapNamespaces, 1);
    if (request->mSoapRequest == 0)
        return 2;
    func_021829AC(request->mSoapRequest, sXmlNamespacePrefix, request->mInfo->soapTag);
    func_02182CF0(request->mSoapRequest, sXmlNamespacePrefix, sTagGameid, request->mSake->gameId);
    func_02182AC0(request->mSoapRequest, sXmlNamespacePrefix, sTagSecretKey, request->mSake->gameName);
    func_02182AC0(request->mSoapRequest, sXmlNamespacePrefix, sTagLoginTicket, request->mSake->secretKey);
    result = info->fillFunc(request);
    if (result != 0) {
        func_02181D84(request->mSoapRequest);
        request->mSoapRequest = 0;
        if (info->cleanupFunc != 0)
            info->cleanupFunc(request);
        return result;
    }
    func_02182A2C(request->mSoapRequest, sXmlNamespacePrefix, request->mInfo->soapTag);
    func_02181DE8(request->mSoapRequest);
    return 0;
}
