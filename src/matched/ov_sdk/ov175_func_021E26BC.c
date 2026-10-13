/*
 * function: wsLoginCertIsValid
 * address:  0x021E26BC
 * packet:   pkt_ov175_021E26BC
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      wsLoginCertIsValid (libdwcgswebservices.TWL.HYB.a(authservice.o))
 *
 * symbols:
 *   func_02184938  0x02184938  arm  ov009
 *   wsiToNetworkOrder  0x021E26B8  arm  ov175
 *   func_0218497C  0x0218497C  arm  ov009
 *   strlen  0x0209477C  arm
 *   gsLargeIntAddToMD5  0x0217E978  arm  ov009
 *   func_02184A34  0x02184A34  arm  ov009
 *   gsLargeIntSetFromHexString  0x0217E848  arm  ov009
 *   func_0217CF5C  0x0217CF5C  arm  ov009
 *   sWsSignatureKeyModulus  0x021E2CC8  data
 *   sWsSignatureKeyExponent  0x021E2CC0  data
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

extern void func_02184938(GSMD5_CTX *context);
extern unsigned int wsiToNetworkOrder(unsigned int num);
extern void func_0218497C(GSMD5_CTX *context, unsigned char *input, unsigned int inputLen);
extern void gsLargeIntAddToMD5(gsLargeInt_t *lint, GSMD5_CTX *md5);
extern void func_02184A34(unsigned char *digest, GSMD5_CTX *context);
extern int gsLargeIntSetFromHexString(gsLargeInt_t *lint, char *hexstream);
extern int func_0217CF5C(gsCryptRSAKey *publicKey, unsigned char *hash, unsigned int hashLen, unsigned char *sig, unsigned int sigLen);
extern char sWsSignatureKeyModulus[];
extern char sWsSignatureKeyExponent[];

int wsLoginCertIsValid(GSLoginCertificate *cert)
{
    gsCryptRSAKey sigkeypub;
    GSMD5_CTX md5;
    unsigned char hash[16];
    int cryptResult;
    unsigned int temp;

    func_02184938(&md5);
    temp = wsiToNetworkOrder(cert->mLength);
    func_0218497C(&md5, (unsigned char *)&temp, 4);
    temp = wsiToNetworkOrder(cert->mVersion);
    func_0218497C(&md5, (unsigned char *)&temp, 4);
    temp = wsiToNetworkOrder(cert->mPartnerCode);
    func_0218497C(&md5, (unsigned char *)&temp, 4);
    temp = wsiToNetworkOrder(cert->mNamespaceId);
    func_0218497C(&md5, (unsigned char *)&temp, 4);
    temp = wsiToNetworkOrder(cert->mUserId);
    func_0218497C(&md5, (unsigned char *)&temp, 4);
    temp = wsiToNetworkOrder(cert->mProfileId);
    func_0218497C(&md5, (unsigned char *)&temp, 4);
    temp = wsiToNetworkOrder(cert->mExpireTime);
    func_0218497C(&md5, (unsigned char *)&temp, 4);
    func_0218497C(&md5, (unsigned char *)cert->mProfileNick, strlen(cert->mProfileNick));
    func_0218497C(&md5, (unsigned char *)cert->mUniqueNick, strlen(cert->mUniqueNick));
    func_0218497C(&md5, (unsigned char *)cert->mCdKeyHash, strlen(cert->mCdKeyHash));
    gsLargeIntAddToMD5(&cert->mPeerPublicKey.modulus, &md5);
    gsLargeIntAddToMD5(&cert->mPeerPublicKey.exponent, &md5);
    func_0218497C(&md5, cert->mServerData, 128);
    func_02184A34(hash, &md5);
    gsLargeIntSetFromHexString(&sigkeypub.modulus, sWsSignatureKeyModulus);
    gsLargeIntSetFromHexString(&sigkeypub.exponent, sWsSignatureKeyExponent);
    cryptResult = func_0217CF5C(&sigkeypub, hash, 16, cert->mSignature, 128);
    if (cryptResult == 0)
        return 1;
    return 0;
}
