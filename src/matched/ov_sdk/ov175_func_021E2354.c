/*
 * function: wsLoginRemoteAuthCallback
 * address:  0x021E2354
 * packet:   pkt_ov175_021E2354
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      wsLoginRemoteAuthCallback (libdwcgswebservices.TWL.HYB.a(authservice.o))
 *
 * The object calls with four arguments (the gsiExecuteSoap callback type); the DWARF
 * prototype lists three. The mIsValid store before the clear is in the object.
 *
 * symbols:
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
 *   wsLoginCertIsValid  0x021E26BC  arm  ov175
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   sWsTagLoginRemoteAuthResult  0x021E4A94  data
 *   sWsTagResponseCode  0x021E4A2C  data
 *   sWsTagCertificate  0x021E4A3C  data
 *   sWsTagPeerKeyPrivate  0x021E4A48  data
 */

#include "../arm9_sdk/libc/string.h"

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
extern int wsLoginCertIsValid(GSLoginCertificate *cert);
extern void func_0217EAE0(void *ptr);
extern char sWsTagLoginRemoteAuthResult[];
extern char sWsTagResponseCode[];
extern char sWsTagCertificate[];
extern char sWsTagPeerKeyPrivate[];

void wsLoginRemoteAuthCallback(int theResult, void *theRequestXml, void *theResponseXml, void *theRequestData)
{
    WSIRequestData *requestData = (WSIRequestData *)theRequestData;
    WSLoginResponse response;
    GSLoginCertificate *cert;
    GSMD5_CTX md5;

    cert = &response.mCertificate;
    cert->mIsValid = 0;
    memset(&response, 0, sizeof(response));
    if (theResult == 0) {
        if (!func_021834D0(theResponseXml) || !func_021834E8(theResponseXml, sWsTagLoginRemoteAuthResult))
            response.mLoginResult = 0x65;
        else if (!func_02183A24(theResponseXml, sWsTagResponseCode, &response.mResponseCode))
            response.mLoginResult = 0x65;
        else if (response.mResponseCode != 0)
            response.mLoginResult = 7;
        else if (!func_021835D0(theResponseXml, sWsTagCertificate)
            || !func_021E2A5C(cert, theResponseXml)
            || !func_02183560(theResponseXml)
            || !func_02183E50(theResponseXml, sWsTagPeerKeyPrivate, &response.mPrivateData.mPeerPrivateKey.exponent))
            response.mLoginResult = 0x65;
        else {
            memcpy(&response.mPrivateData.mPeerPrivateKey.modulus, &cert->mPeerPublicKey.modulus, sizeof(gsLargeInt_t));
            func_02184938(&md5);
            gsLargeIntAddToMD5(&response.mPrivateData.mPeerPrivateKey.exponent, &md5);
            func_02184A34((unsigned char *)response.mPrivateData.mKeyHash, &md5);
            cert->mIsValid = wsLoginCertIsValid(cert);
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
