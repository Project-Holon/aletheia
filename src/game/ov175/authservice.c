/*
 * file:     authservice.c
 * unit:     yes
 * function: wsiServiceAvailable, wsGetServiceUrl, wsLoginRemoteAuthCallback, wsLoginRemoteAuth, wsiToNetworkOrder, wsLoginCertIsValid, wsLoginCertWriteXML, wsLoginCertReadXML
 * address:  0x021E2290
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * GameSpy web services login (libdwcgswebservices, object authservice.o): the
 * LoginRemoteAuth SOAP call that exchanges an auth token for a signed login
 * certificate, the check of that certificate and its XML read/write form.
 * wsLoginCertReadXML was its own file (authservice_readxml.c, 0x021E2A5C) and
 * is merged here: it is the same original object authservice.o.
 *
 * symbols:
 *   GSMD5Final  0x02184A34  arm ov009
 *   GSMD5Init  0x02184938  arm ov009
 *   GSMD5Update  0x0218497C  arm ov009
 *   OS_SNPrintf  0x02084F80  arm arm9
 *   wsLoginCertReadXML  0x021E2A5C  arm  ov175
 *   g_021ACEF8  0x021ACEF8  data
 *   g_021ACEFC  0x021ACEFC  data
 *   sWsSignatureKeyExponent  0x021E2CC0  data
 *   sWsSignatureKeyModulus  0x021E2CC8  data
 *   gWsSoapNamespaces  0x021E49A4  data
 *   sWsAuthUrlFormat  0x021E49D0  data
 *   sWsNoAvailabilityMessage  0x021E4A18  data
 *   sWsTagResponseCode  0x021E4A2C  data
 *   sWsTagCertificate  0x021E4A3C  data
 *   sWsTagPeerKeyPrivate  0x021E4A48  data
 *   sWsNamespaceNs1  0x021E4A58  data
 *   sWsTagVersion  0x021E4A5C  data
 *   sWsTagPartnerCode  0x021E4A64  data
 *   sWsTagNamespaceId  0x021E4A70  data
 *   sWsTagProfileNick  0x021E4A7C  data
 *   sWsTagUniqueNick  0x021E4A88  data
 *   sWsTagLoginRemoteAuthResult  0x021E4A94  data
 *   sWsTagLoginRemoteAuth  0x021E4AAC  data
 *   sWsTagAuthToken  0x021E4ABC  data
 *   sWsTagChallenge  0x021E4AC8  data
 *   sWsSoapActionLoginRemoteAuth  0x021E4AD4  data
 *   sWsTagLength  0x021E4B14  data
 *   sWsTagUserId  0x021E4B1C  data
 *   sWsTagProfileId  0x021E4B24  data
 *   sWsTagExpireTime  0x021E4B30  data
 *   sWsTagCdKeyHash  0x021E4B3C  data
 *   sWsTagPeerKeyModulus  0x021E4B48  data
 *   sWsTagPeerKeyExponent  0x021E4B58  data
 *   sWsTagServerData  0x021E4B68  data
 *   sWsTagSignature  0x021E4B74  data
 *   gWsAuthServiceUrl  0x021E53BC  data
 *   gsCryptRSAVerifySignedHash  0x0217CF5C  arm ov009
 *   gsDebugFormat  0x0217D254  arm ov009
 *   gsLargeIntAddToMD5  0x0217E978  arm  ov009
 *   gsLargeIntSetFromHexString  0x0217E848  arm  ov009
 *   gsXmlCloseWriter  0x02181DE8  arm ov009
 *   gsXmlCreateStreamWriter  0x021819B0  arm ov009
 *   gsXmlFreeWriter  0x02181D84  arm ov009
 *   gsXmlMoveToChild  0x021835D0  arm ov009
 *   gsXmlMoveToNext  0x021834E8  arm ov009
 *   gsXmlMoveToParent  0x02183560  arm ov009
 *   gsXmlMoveToStart  0x021834D0  arm ov009
 *   gsXmlReadChildAsInt  0x02183A24  arm ov009
 *   gsXmlReadChildAsStringNT  0x0218372C  arm ov009
 *   gsXmlReadChildAsHexBinary  0x021837A4  arm ov009
 *   gsXmlReadChildAsLargeInt  0x02183E50  arm ov009
 *   gsXmlWriteAsciiStringElement  0x02182B68  arm ov009
 *   gsXmlWriteCloseTag  0x02182A2C  arm ov009
 *   gsXmlWriteHexBinaryElement  0x02182E90  arm ov009
 *   gsXmlWriteIntElement  0x02182CF0  arm ov009
 *   gsXmlWriteLargeIntElement  0x021830D0  arm ov009
 *   gsXmlWriteOpenTag  0x021829AC  arm ov009
 *   gsXmlWriteStringElement  0x02182AC0  arm ov009
 *   gsiExecuteSoap  0x0217FD7C  arm ov009
 *   gsifree  0x0217EAE0  arm ov009
 *   gsimalloc  0x0217EAB0  arm ov009
 *   memcpy  0x02092344  arm
 *   memset  0x020923B0  arm
 *   strlen  0x0209477C  arm
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "auth_types.h"
extern int wsLoginCertReadXML(GSLoginCertificate *cert, void *reader);

extern int OS_SNPrintf(char *dst, unsigned long len, const char *fmt, ...);
extern void gsDebugFormat(int theCategory, int theType, int theLevel, const char *theTokenStr, ...);
extern int gsXmlMoveToStart(void *stream);
extern int gsXmlMoveToNext(void *stream, char *matchtag);
extern int gsXmlMoveToChild(void *stream, char *matchtag);
extern int gsXmlMoveToParent(void *stream);
extern int gsXmlReadChildAsInt(void *stream, char *matchtag, int *valueOut);
extern int gsXmlReadChildAsStringNT(void *stream, char *matchtag, char *valueOut, int maxLen);
extern int gsXmlReadChildAsHexBinary(void *stream, char *matchtag, unsigned char *valueOut, int maxLen,
                                     int *lenOut);
extern int gsXmlReadChildAsLargeInt(void *stream, char *matchtag, int *lintData);
extern void GSMD5Init(GSMD5_CTX *context);
extern void gsLargeIntAddToMD5(gsLargeInt_t *lint, GSMD5_CTX *md5);
extern void GSMD5Update(GSMD5_CTX *context, unsigned char *input, unsigned int inputLen);
extern void GSMD5Final(unsigned char *digest, GSMD5_CTX *context);
extern void gsifree(void *ptr);
extern void *gsimalloc(unsigned long size);
extern void *gsXmlCreateStreamWriter(const char **namespaces, int count);
extern int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteIntElement(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int gsXmlWriteStringElement(void *stream, char *namespaceName, char *tag, char *value);
extern int gsXmlWriteAsciiStringElement(void *stream, char *namespaceName, char *tag, char *value);
extern int gsXmlWriteLargeIntElement(void *stream, char *namespaceName, char *tag, gsLargeInt_t *lint);
extern int gsXmlWriteHexBinaryElement(void *stream, char *namespaceName, char *tag, unsigned char *data,
                                      int len);
extern int gsXmlCloseWriter(void *stream);
extern void gsXmlFreeWriter(void **writerRef);
extern void *gsiExecuteSoap(char *theURL, char *theService, void *theRequestSoap, GSSoapCallback theCallbackFunc,
                            void *theUserData);
extern int gsLargeIntSetFromHexString(gsLargeInt_t *lint, char *hexstream);
extern int gsCryptRSAVerifySignedHash(gsCryptRSAKey *publicKey, unsigned char *hash, unsigned int hashLen,
                                      unsigned char *sig, unsigned int sigLen);

int wsiServiceAvailable(void);
char *wsGetServiceUrl(void);
void wsLoginRemoteAuthCallback(int theResult, void *theRequestXml, void *theResponseXml, void *theRequestData);
int wsLoginRemoteAuth(int partnerCode, int namespaceId, char *authtoken, char *partnerChallenge,
                  WSLoginCallback userCallback, void *userData);
unsigned int wsiToNetworkOrder(unsigned int num);
int wsLoginCertIsValid(GSLoginCertificate *theCertificate);
int wsLoginCertWriteXML(GSLoginCertificate *theCertificate, char *theNamespace, void *theWriter);

extern int g_021ACEF8;
extern char g_021ACEFC[];
extern char sWsAuthUrlFormat[];
extern char gWsAuthServiceUrl[];
extern char sWsNoAvailabilityMessage[];
extern char sWsTagLoginRemoteAuthResult[];
extern char sWsTagResponseCode[];
extern char sWsTagCertificate[];
extern char sWsTagPeerKeyPrivate[];
extern char *gWsSoapNamespaces[];
extern char sWsNamespaceNs1[];
extern char sWsTagLoginRemoteAuth[];
extern char sWsTagVersion[];
extern char sWsTagPartnerCode[];
extern char sWsTagNamespaceId[];
extern char sWsTagAuthToken[];
extern char sWsTagChallenge[];
extern char sWsSoapActionLoginRemoteAuth[];
extern char sWsSignatureKeyModulus[];
extern char sWsSignatureKeyExponent[];
extern char sWsTagLength[];
extern char sWsTagUserId[];
extern char sWsTagProfileId[];
extern char sWsTagExpireTime[];
extern char sWsTagProfileNick[];
extern char sWsTagUniqueNick[];
extern char sWsTagCdKeyHash[];
extern char sWsTagPeerKeyModulus[];
extern char sWsTagPeerKeyExponent[];
extern char sWsTagServerData[];
extern char sWsTagSignature[];

/*
 * wsiServiceAvailable: true when the availability check passed.  Builds the
 * auth service URL on first use.
 */
int wsiServiceAvailable(void)
{
    if (g_021ACEF8 == 1) {
        if (gWsAuthServiceUrl[0] == 0)
            OS_SNPrintf(gWsAuthServiceUrl, 0x80, sWsAuthUrlFormat, g_021ACEFC);
        return 1;
    }
    return 0;
}

/*
 * wsGetServiceUrl: the URL of the auth service (built on first use), or null
 * after a debug message when the availability check has not passed.
 */
char *wsGetServiceUrl(void)
{
    if (g_021ACEF8 == 1) {
        if (gWsAuthServiceUrl[0] == 0)
            OS_SNPrintf(gWsAuthServiceUrl, 0x80, sWsAuthUrlFormat, g_021ACEFC);
        return gWsAuthServiceUrl;
    }
    gsDebugFormat(0, 3, 1, sWsNoAvailabilityMessage);
    return 0;
}

/*
 * wsLoginRemoteAuthCallback: parses the LoginRemoteAuth response into a
 * WSLoginResponse, checks the certificate and calls the caller's callback.
 *
 * The object calls with four arguments (the gsiExecuteSoap callback type); the DWARF
 * prototype lists three. The mIsValid store before the clear is in the object.
 */
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
            response.mLoginResult = WSLoginResult_PARSE_ERROR;
        else if (!gsXmlReadChildAsInt(theResponseXml, sWsTagResponseCode, &response.mResponseCode))
            response.mLoginResult = WSLoginResult_PARSE_ERROR;
        else if (response.mResponseCode != 0)
            response.mLoginResult = WSLoginResult_SERVER_ERROR;
        else if (!gsXmlMoveToChild(theResponseXml, sWsTagCertificate)
            || !wsLoginCertReadXML(cert, theResponseXml)
            || !gsXmlMoveToParent(theResponseXml)
            || !gsXmlReadChildAsLargeInt(theResponseXml, sWsTagPeerKeyPrivate, (int *)(&response.mPrivateData.mPeerPrivateKey.exponent)))
            response.mLoginResult = WSLoginResult_PARSE_ERROR;
        else {
            memcpy(&response.mPrivateData.mPeerPrivateKey.modulus, &cert->mPeerPublicKey.modulus, sizeof(gsLargeInt_t));
            GSMD5Init(&md5);
            gsLargeIntAddToMD5(&response.mPrivateData.mPeerPrivateKey.exponent, &md5);
            GSMD5Final((unsigned char *)response.mPrivateData.mKeyHash, &md5);
            cert->mIsValid = wsLoginCertIsValid(cert);
            if (!cert->mIsValid)
                response.mLoginResult = WSLoginResult_INVALID_CERTIFICATE;
        }
    } else if (theResult == 0x12)
        response.mLoginResult = WSLoginResult_CANCELLED;
    else
        response.mLoginResult = WSLoginResult_HTTP_ERROR;
    if (requestData->mUserCallback != 0)
        requestData->mUserCallback(theResult, &response, requestData->mUserData);
    gsifree(requestData);
}

/* wsLoginRemoteAuth: sends the LoginRemoteAuth SOAP call for an auth token and a partner challenge. */
int wsLoginRemoteAuth(int partnerCode, int namespaceId, char *authtoken, char *partnerChallenge,
                  WSLoginCallback userCallback, void *userData)
{
    void *writer;
    WSIRequestData *requestData;
    void *aTask;

    if (!wsiServiceAvailable())
        return WSLoginResult_NO_AVAILABILITY_CHECK;
    requestData = (WSIRequestData *)gsimalloc(sizeof(WSIRequestData));
    if (requestData == 0)
        return WSLoginResult_OUT_OF_MEMORY;
    requestData->mUserCallback = userCallback;
    requestData->mUserData = userData;
    writer = gsXmlCreateStreamWriter((const char **)gWsSoapNamespaces, 1);
    if (writer == 0)
        return WSLoginResult_OUT_OF_MEMORY;
    if (!gsXmlWriteOpenTag(writer, sWsNamespaceNs1, sWsTagLoginRemoteAuth)
        || !gsXmlWriteIntElement(writer, sWsNamespaceNs1, sWsTagVersion, 1)
        || !gsXmlWriteIntElement(writer, sWsNamespaceNs1, sWsTagPartnerCode, partnerCode)
        || !gsXmlWriteIntElement(writer, sWsNamespaceNs1, sWsTagNamespaceId, namespaceId)
        || !gsXmlWriteStringElement(writer, sWsNamespaceNs1, sWsTagAuthToken, authtoken)
        || !gsXmlWriteStringElement(writer, sWsNamespaceNs1, sWsTagChallenge, partnerChallenge)
        || !gsXmlWriteCloseTag(writer, sWsNamespaceNs1, sWsTagLoginRemoteAuth)
        || !gsXmlCloseWriter(writer)) {
        gsXmlFreeWriter(writer);
        return WSLoginResult_OUT_OF_MEMORY;
    }
    aTask = gsiExecuteSoap(gWsAuthServiceUrl, sWsSoapActionLoginRemoteAuth, writer, wsLoginRemoteAuthCallback, requestData);
    if (aTask == 0) {
        gsXmlFreeWriter(writer);
        gsifree(requestData);
        return WSLoginResult_OUT_OF_MEMORY;
    }
    return 0;
}

/* wsiToNetworkOrder (name guessed): the identity; the build is for a big-endian target. */
unsigned int wsiToNetworkOrder(unsigned int num)
{
    return num;
}

/* wsLoginCertIsValid: hashes the certificate fields with MD5 and verifies the signature with the server's public key. */
int wsLoginCertIsValid(GSLoginCertificate *cert)
{
    gsCryptRSAKey sigkeypub;
    GSMD5_CTX md5;
    unsigned char hash[16];
    int cryptResult;
    unsigned int temp;

    GSMD5Init(&md5);
    temp = wsiToNetworkOrder(cert->mLength);
    GSMD5Update(&md5, (unsigned char *)&temp, 4);
    temp = wsiToNetworkOrder(cert->mVersion);
    GSMD5Update(&md5, (unsigned char *)&temp, 4);
    temp = wsiToNetworkOrder(cert->mPartnerCode);
    GSMD5Update(&md5, (unsigned char *)&temp, 4);
    temp = wsiToNetworkOrder(cert->mNamespaceId);
    GSMD5Update(&md5, (unsigned char *)&temp, 4);
    temp = wsiToNetworkOrder(cert->mUserId);
    GSMD5Update(&md5, (unsigned char *)&temp, 4);
    temp = wsiToNetworkOrder(cert->mProfileId);
    GSMD5Update(&md5, (unsigned char *)&temp, 4);
    temp = wsiToNetworkOrder(cert->mExpireTime);
    GSMD5Update(&md5, (unsigned char *)&temp, 4);
    GSMD5Update(&md5, (unsigned char *)cert->mProfileNick, strlen(cert->mProfileNick));
    GSMD5Update(&md5, (unsigned char *)cert->mUniqueNick, strlen(cert->mUniqueNick));
    GSMD5Update(&md5, (unsigned char *)cert->mCdKeyHash, strlen(cert->mCdKeyHash));
    gsLargeIntAddToMD5(&cert->mPeerPublicKey.modulus, &md5);
    gsLargeIntAddToMD5(&cert->mPeerPublicKey.exponent, &md5);
    GSMD5Update(&md5, cert->mServerData, 128);
    GSMD5Final(hash, &md5);
    gsLargeIntSetFromHexString(&sigkeypub.modulus, sWsSignatureKeyModulus);
    gsLargeIntSetFromHexString(&sigkeypub.exponent, sWsSignatureKeyExponent);
    cryptResult = gsCryptRSAVerifySignedHash(&sigkeypub, hash, 16, cert->mSignature, 128);
    if (cryptResult == 0)
        return 1;
    return 0;
}

/* wsLoginCertWriteXML: writes every field of the certificate as an XML element. */
int wsLoginCertWriteXML(GSLoginCertificate *cert, char *aNamespace, void *writer)
{
    if (!gsXmlWriteIntElement(writer, aNamespace, sWsTagLength, cert->mLength)
        || !gsXmlWriteIntElement(writer, aNamespace, sWsTagVersion, cert->mVersion)
        || !gsXmlWriteIntElement(writer, aNamespace, sWsTagPartnerCode, cert->mPartnerCode)
        || !gsXmlWriteIntElement(writer, aNamespace, sWsTagNamespaceId, cert->mNamespaceId)
        || !gsXmlWriteIntElement(writer, aNamespace, sWsTagUserId, cert->mUserId)
        || !gsXmlWriteIntElement(writer, aNamespace, sWsTagProfileId, cert->mProfileId)
        || !gsXmlWriteIntElement(writer, aNamespace, sWsTagExpireTime, cert->mExpireTime)
        || !gsXmlWriteAsciiStringElement(writer, aNamespace, sWsTagProfileNick, cert->mProfileNick)
        || !gsXmlWriteAsciiStringElement(writer, aNamespace, sWsTagUniqueNick, cert->mUniqueNick)
        || !gsXmlWriteAsciiStringElement(writer, aNamespace, sWsTagCdKeyHash, cert->mCdKeyHash)
        || !gsXmlWriteLargeIntElement(writer, aNamespace, sWsTagPeerKeyModulus, &cert->mPeerPublicKey.modulus)
        || !gsXmlWriteLargeIntElement(writer, aNamespace, sWsTagPeerKeyExponent, &cert->mPeerPublicKey.exponent)
        || !gsXmlWriteHexBinaryElement(writer, aNamespace, sWsTagServerData, cert->mServerData, 128)
        || !gsXmlWriteHexBinaryElement(writer, aNamespace, sWsTagSignature, cert->mSignature, 128))
        return 0;
    return 1;
}

/*
 * wsLoginCertReadXML: reads every certificate field out of the reader's current
 * certificate element.  Returns 0 on the first read that fails, 1 when all of
 * them succeed.
 */
int wsLoginCertReadXML(GSLoginCertificate *cert, void *reader)
{
    char buf[257];
    int len;
    if (!gsXmlReadChildAsInt(reader, sWsTagLength, (int *)&cert->mLength)
        || !gsXmlReadChildAsInt(reader, sWsTagVersion, (int *)&cert->mVersion)
        || !gsXmlReadChildAsInt(reader, sWsTagPartnerCode, (int *)&cert->mPartnerCode)
        || !gsXmlReadChildAsInt(reader, sWsTagNamespaceId, (int *)&cert->mNamespaceId)
        || !gsXmlReadChildAsInt(reader, sWsTagUserId, (int *)&cert->mUserId)
        || !gsXmlReadChildAsInt(reader, sWsTagProfileId, (int *)&cert->mProfileId)
        || !gsXmlReadChildAsInt(reader, sWsTagExpireTime, (int *)&cert->mExpireTime)
        || !gsXmlReadChildAsStringNT(reader, sWsTagProfileNick, cert->mProfileNick, 31)
        || !gsXmlReadChildAsStringNT(reader, sWsTagUniqueNick, cert->mUniqueNick, 21)
        || !gsXmlReadChildAsStringNT(reader, sWsTagCdKeyHash, cert->mCdKeyHash, 33)
        || !gsXmlReadChildAsStringNT(reader, sWsTagPeerKeyModulus, buf, 257)
        || !gsLargeIntSetFromHexString(&cert->mPeerPublicKey.modulus, buf)
        || !gsXmlReadChildAsStringNT(reader, sWsTagPeerKeyExponent, buf, 257)
        || !gsLargeIntSetFromHexString(&cert->mPeerPublicKey.exponent, buf)
        || !gsXmlReadChildAsHexBinary(reader, sWsTagServerData, cert->mServerData, 128, &len)
        || !gsXmlReadChildAsHexBinary(reader, sWsTagSignature, cert->mSignature, 128, &len))
        return 0;
    return 1;
}
