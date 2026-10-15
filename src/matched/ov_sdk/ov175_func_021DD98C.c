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
 *   gsXmlCreateStreamWriter  0x021819B0  arm   ov009
 *   gsXmlWriteOpenTag  0x021829AC  arm   ov009
 *   gsXmlWriteIntElement  0x02182CF0  arm   ov009
 *   gsXmlWriteStringElement  0x02182AC0  arm   ov009
 *   gsXmlFreeWriter  0x02181D84  arm   ov009
 *   gsXmlWriteCloseTag  0x02182A2C  arm   ov009
 *   gsXmlCloseWriter  0x02181DE8  arm   ov009
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

extern void *gsXmlCreateStreamWriter(const char **namespaces, int count);
extern int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteIntElement(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int gsXmlWriteStringElement(void *stream, char *namespaceName, char *tag, char *value);
extern void gsXmlFreeWriter(void **p);
extern int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlCloseWriter(void *stream);
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
    request->mSoapRequest = gsXmlCreateStreamWriter((const char **)sSoapNamespaces, 1);
    if (request->mSoapRequest == 0)
        return 2;
    gsXmlWriteOpenTag(request->mSoapRequest, sXmlNamespacePrefix, request->mInfo->soapTag);
    gsXmlWriteIntElement(request->mSoapRequest, sXmlNamespacePrefix, sTagGameid, request->mSake->gameId);
    gsXmlWriteStringElement(request->mSoapRequest, sXmlNamespacePrefix, sTagSecretKey, request->mSake->gameName);
    gsXmlWriteStringElement(request->mSoapRequest, sXmlNamespacePrefix, sTagLoginTicket, request->mSake->secretKey);
    result = info->fillFunc(request);
    if (result != 0) {
        gsXmlFreeWriter(request->mSoapRequest);
        request->mSoapRequest = 0;
        if (info->cleanupFunc != 0)
            info->cleanupFunc(request);
        return result;
    }
    gsXmlWriteCloseTag(request->mSoapRequest, sXmlNamespacePrefix, request->mInfo->soapTag);
    gsXmlCloseWriter(request->mSoapRequest);
    return 0;
}
