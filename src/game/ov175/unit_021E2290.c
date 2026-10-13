/*
 * file:     unit_021E2290.c
 * unit:     yes
 * function: func_021E2290, func_021E22E4, func_021E2354, func_021E2510
 * address:  0x021E2290
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
 *   func_02084F80  0x02084F80  arm
 *   g_021ACEF8     0x021ACEF8  data
 *   g_021ACEFC     0x021ACEFC  data
 *   g_021E49D0     0x021E49D0  data
 *   g_021E53BC     0x021E53BC  data
 *   func_0217D254  0x0217D254  arm
 *   g_021E4A18     0x021E4A18  data
 *   func_021834D0  0x021834D0  arm  ov009
 *   func_021834E8  0x021834E8  arm  ov009
 *   func_02183A24  0x02183A24  arm  ov009
 *   func_021835D0  0x021835D0  arm  ov009
 *   func_021E2A5C  0x021E2A5C  arm  ov175
 *   func_02183560  0x02183560  arm  ov009
 *   func_02183E50  0x02183E50  arm  ov009
 *   memcpy  0x02092344  arm
 *   func_02184938  0x02184938  arm  ov009
 *   gsLargeIntAddToMD5  0x0217E978  arm  ov009
 *   func_02184A34  0x02184A34  arm  ov009
 *   func_021E26BC  0x021E26BC  arm  ov175
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   g_021E4A94  0x021E4A94  data
 *   g_021E4A2C  0x021E4A2C  data
 *   g_021E4A3C  0x021E4A3C  data
 *   g_021E4A48  0x021E4A48  data
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_021819B0  0x021819B0  arm  ov009
 *   func_021829AC  0x021829AC  arm  ov009
 *   func_02182CF0  0x02182CF0  arm  ov009
 *   func_02182AC0  0x02182AC0  arm  ov009
 *   func_02182A2C  0x02182A2C  arm  ov009
 *   func_02181DE8  0x02181DE8  arm  ov009
 *   func_02181D84  0x02181D84  arm  ov009
 *   func_0217FD7C  0x0217FD7C  arm  ov009
 *   g_021E49A4  0x021E49A4  data
 *   g_021E4A58  0x021E4A58  data
 *   g_021E4AAC  0x021E4AAC  data
 *   g_021E4A5C  0x021E4A5C  data
 *   g_021E4A64  0x021E4A64  data
 *   g_021E4A70  0x021E4A70  data
 *   g_021E4ABC  0x021E4ABC  data
 *   g_021E4AC8  0x021E4AC8  data
 *   g_021E4AD4  0x021E4AD4  data
 */
#include "../../matched/arm9_sdk/libc/string.h"

typedef unsigned int u32;

typedef signed int s32;

typedef signed char s8;

typedef struct {
    unsigned int state[4];
    unsigned int count[2];
    unsigned char buffer[64];
} GSMD5_CTX;

typedef struct gsLargeInt_s {
    unsigned int mLength;
    unsigned int mData[64];
} gsLargeInt_t;

typedef struct {
    gsLargeInt_t modulus;
    gsLargeInt_t exponent;
} gsCryptRSAKey;

typedef struct GSLoginCertificate {
    int mIsValid;
    unsigned int mLength;
    unsigned int mVersion;
    unsigned int mPartnerCode;
    unsigned int mNamespaceId;
    unsigned int mUserId;
    unsigned int mProfileId;
    unsigned int mExpireTime;
    char mProfileNick[31];
    char mUniqueNick[21];
    char mCdKeyHash[33];
    gsCryptRSAKey mPeerPublicKey;
    unsigned char mSignature[128];
    unsigned char mServerData[128];
} GSLoginCertificate;

typedef struct {
    gsCryptRSAKey mPeerPrivateKey;
    char mKeyHash[16];
} GSLoginCertificatePrivate;

typedef struct WSLoginResponse {
    int mLoginResult;
    int mResponseCode;
    GSLoginCertificate mCertificate;
    GSLoginCertificatePrivate mPrivateData;
    void *mUserData;
} WSLoginResponse;

typedef struct {
    void (*mUserCallback)(int, WSLoginResponse *, void *);
    void *mUserData;
} WSIRequestData;

extern int func_02084F80(char *dst, unsigned int len, const char *fmt, ...);
extern void func_0217D254(int, int, int, u32 *);
extern int func_021834D0(void *stream);
extern int func_021834E8(void *stream, char *matchtag);
extern int func_02183A24(void *stream, char *matchtag, int *valueOut);
extern int func_021835D0(void *stream, char *matchtag);
extern int func_021E2A5C(GSLoginCertificate *cert, void *reader);
extern int func_02183560(void *stream);
extern int func_02183E50(void *stream, char *matchtag, gsLargeInt_t *valueOut);
extern void func_02184938(GSMD5_CTX *context);
extern void gsLargeIntAddToMD5(gsLargeInt_t *lint, GSMD5_CTX *md5);
extern void func_02184A34(unsigned char *digest, GSMD5_CTX *context);
extern int func_021E26BC(GSLoginCertificate *cert);
extern void func_0217EAE0(void *ptr);
extern void *func_0217EAB0(unsigned long size);
extern void *func_021819B0(const char **namespaces, int count);
extern int func_021829AC(void *stream, char *namespaceName, char *tag);
extern int func_02182CF0(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int func_02182AC0(void *stream, char *namespaceName, char *tag, char *value);
extern int func_02182A2C(void *stream, char *namespaceName, char *tag);
extern int func_02181DE8(void *stream);
extern void func_02181D84(void **p);
extern void *func_0217FD7C(char *theURL, char *theService, void *theRequestSoap, void *theCallbackFunc, void *theUserData);
s32 func_021E2290(void);
s32 func_021E22E4(void);
void func_021E2354(int theResult, void *theRequestXml, void *theResponseXml, void *theRequestData);
int func_021E2510(int partnerCode, int namespaceId, char *authtoken, char *partnerChallenge, void (*userCallback)(int, WSLoginResponse *, void *), void *userData);
extern u32 g_021ACEF8;
extern u32 g_021ACEFC[];
extern u32 g_021E49D0[];
extern char g_021E53BC[];
extern u32 g_021E4A18[];
extern char g_021E4A94[];
extern char g_021E4A2C[];
extern char g_021E4A3C[];
extern char g_021E4A48[];
extern char *g_021E49A4[];
extern char g_021E4A58[];
extern char g_021E4AAC[];
extern char g_021E4A5C[];
extern char g_021E4A64[];
extern char g_021E4A70[];
extern char g_021E4ABC[];
extern char g_021E4AC8[];
extern char g_021E4AD4[];




/*
 * Session gate: only in state 1, and only while the 0x021E53BC flag byte is
 * clear, hand the 0x021E49D0 table to func_02084F80 with the 0x021ACEFC base.
 */
s32 func_021E2290(void)
{
    if (g_021ACEF8 == 1) {
        if (g_021E53BC[0] == 0)
            func_02084F80((char *)g_021E53BC, 0x80, (const char *)g_021E49D0, g_021ACEFC);
        return 1;
    }
    return 0;
}




/*
 * Session state probe: state 1 initialises the 0x021E53BC flag through
 * func_02084F80 and reports the flag; any other state asks func_0217D254 to
 * bring the 0x021E4A18 scene up (3/1).
 */
s32 func_021E22E4(void)
{
    if (g_021ACEF8 == 1) {
        if (g_021E53BC[0] == 0)
            func_02084F80((char *)g_021E53BC, 0x80, (const char *)g_021E49D0, g_021ACEFC);
        return (s32)g_021E53BC;
    }
    func_0217D254(0, 3, 1, g_021E4A18);
    return 0;
}



/*
 * sdk:      wsLoginRemoteAuthCallback (libdwcgswebservices.TWL.HYB.a(authservice.o))
 *
 * The object calls with four arguments (the gsiExecuteSoap callback type); the DWARF
 * prototype lists three. The mIsValid store before the clear is in the object.
 */
void func_021E2354(int theResult, void *theRequestXml, void *theResponseXml, void *theRequestData)
{
    WSIRequestData *requestData = (WSIRequestData *)theRequestData;
    WSLoginResponse response;
    GSLoginCertificate *cert;
    GSMD5_CTX md5;

    cert = &response.mCertificate;
    cert->mIsValid = 0;
    memset(&response, 0, sizeof(response));
    if (theResult == 0) {
        if (!func_021834D0(theResponseXml) || !func_021834E8(theResponseXml, g_021E4A94))
            response.mLoginResult = 0x65;
        else if (!func_02183A24(theResponseXml, g_021E4A2C, &response.mResponseCode))
            response.mLoginResult = 0x65;
        else if (response.mResponseCode != 0)
            response.mLoginResult = 7;
        else if (!func_021835D0(theResponseXml, g_021E4A3C)
            || !func_021E2A5C(cert, theResponseXml)
            || !func_02183560(theResponseXml)
            || !func_02183E50(theResponseXml, g_021E4A48, &response.mPrivateData.mPeerPrivateKey.exponent))
            response.mLoginResult = 0x65;
        else {
            memcpy(&response.mPrivateData.mPeerPrivateKey.modulus, &cert->mPeerPublicKey.modulus, sizeof(gsLargeInt_t));
            func_02184938(&md5);
            gsLargeIntAddToMD5(&response.mPrivateData.mPeerPrivateKey.exponent, &md5);
            func_02184A34((unsigned char *)response.mPrivateData.mKeyHash, &md5);
            cert->mIsValid = func_021E26BC(cert);
            if (!cert->mIsValid)
                response.mLoginResult = 0x66;
        }
    } else if (theResult == 0x12)
        response.mLoginResult = 0x6b;
    else
        response.mLoginResult = 0x64;
    if (requestData->mUserCallback != 0)
        requestData->mUserCallback(theResult, &response, requestData->mUserData);
    func_0217EAE0(requestData);
}


/*
 * sdk:      wsLoginRemoteAuth (libdwcgswebservices.TWL.HYB.a(authservice.o))
 */
int func_021E2510(int partnerCode, int namespaceId, char *authtoken, char *partnerChallenge, void (*userCallback)(int, WSLoginResponse *, void *), void *userData)
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
