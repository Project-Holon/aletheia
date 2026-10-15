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
 *   gsXmlMoveToStart  0x021834D0  arm  ov009
 *   gsXmlMoveToNext  0x021834E8  arm  ov009
 *   gsXmlReadChildAsInt  0x02183A24  arm  ov009
 *   gsXmlMoveToChild  0x021835D0  arm  ov009
 *   func_021E2A5C  0x021E2A5C  arm  ov175
 *   gsXmlMoveToParent  0x02183560  arm  ov009
 *   gsXmlReadChildAsLargeInt  0x02183E50  arm  ov009
 *   memcpy  0x02092344  arm
 *   GSMD5Init  0x02184938  arm  ov009
 *   gsLargeIntAddToMD5  0x0217E978  arm  ov009
 *   GSMD5Final  0x02184A34  arm  ov009
 *   wsLoginCertIsValid  0x021E26BC  arm  ov175
 *   gsifree  0x0217EAE0  arm  ov009
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

extern int gsXmlMoveToStart(void *stream);
extern int gsXmlMoveToNext(void *stream, char *matchtag);
extern int gsXmlReadChildAsInt(void *stream, char *matchtag, int *valueOut);
extern int gsXmlMoveToChild(void *stream, char *matchtag);
extern int func_021E2A5C(GSLoginCertificate *cert, void *reader);
extern int gsXmlMoveToParent(void *stream);
extern int gsXmlReadChildAsLargeInt(void *stream, char *matchtag, gsLargeInt_t *valueOut);
extern void GSMD5Init(GSMD5_CTX *context);
extern void gsLargeIntAddToMD5(gsLargeInt_t *lint, GSMD5_CTX *md5);
extern void GSMD5Final(unsigned char *digest, GSMD5_CTX *context);
extern int wsLoginCertIsValid(GSLoginCertificate *cert);
extern void gsifree(void *ptr);
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
        if (!gsXmlMoveToStart(theResponseXml) || !gsXmlMoveToNext(theResponseXml, sWsTagLoginRemoteAuthResult))
            response.mLoginResult = 0x65;
        else if (!gsXmlReadChildAsInt(theResponseXml, sWsTagResponseCode, &response.mResponseCode))
            response.mLoginResult = 0x65;
        else if (response.mResponseCode != 0)
            response.mLoginResult = 7;
        else if (!gsXmlMoveToChild(theResponseXml, sWsTagCertificate)
            || !func_021E2A5C(cert, theResponseXml)
            || !gsXmlMoveToParent(theResponseXml)
            || !gsXmlReadChildAsLargeInt(theResponseXml, sWsTagPeerKeyPrivate, &response.mPrivateData.mPeerPrivateKey.exponent))
            response.mLoginResult = 0x65;
        else {
            memcpy(&response.mPrivateData.mPeerPrivateKey.modulus, &cert->mPeerPublicKey.modulus, sizeof(gsLargeInt_t));
            GSMD5Init(&md5);
            gsLargeIntAddToMD5(&response.mPrivateData.mPeerPrivateKey.exponent, &md5);
            GSMD5Final((unsigned char *)response.mPrivateData.mKeyHash, &md5);
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
    gsifree(requestData);
}
