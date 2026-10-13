/*
 * file:     unit_021E26BC.c
 * unit:     yes
 * function: func_021E26BC, func_021E2874
 * address:  0x021E26BC
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
 *   func_02184938  0x02184938  arm  ov009
 *   func_021E26B8  0x021E26B8  arm  ov175
 *   func_0218497C  0x0218497C  arm  ov009
 *   strlen  0x0209477C  arm
 *   gsLargeIntAddToMD5  0x0217E978  arm  ov009
 *   func_02184A34  0x02184A34  arm  ov009
 *   gsLargeIntSetFromHexString  0x0217E848  arm  ov009
 *   func_0217CF5C  0x0217CF5C  arm  ov009
 *   g_021E2CC8  0x021E2CC8  data
 *   g_021E2CC0  0x021E2CC0  data
 *   func_02182CF0  0x02182CF0  arm  ov009
 *   func_02182B68  0x02182B68  arm  ov009
 *   func_021830D0  0x021830D0  arm  ov009
 *   func_02182E90  0x02182E90  arm  ov009
 *   g_021E4B14  0x021E4B14  data
 *   g_021E4A5C  0x021E4A5C  data
 *   g_021E4A64  0x021E4A64  data
 *   g_021E4A70  0x021E4A70  data
 *   g_021E4B1C  0x021E4B1C  data
 *   g_021E4B24  0x021E4B24  data
 *   g_021E4B30  0x021E4B30  data
 *   g_021E4A7C  0x021E4A7C  data
 *   g_021E4A88  0x021E4A88  data
 *   g_021E4B3C  0x021E4B3C  data
 *   g_021E4B48  0x021E4B48  data
 *   g_021E4B58  0x021E4B58  data
 *   g_021E4B68  0x021E4B68  data
 *   g_021E4B74  0x021E4B74  data
 */
#include "../../matched/arm9_sdk/libc/string.h"

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
extern unsigned int func_021E26B8(unsigned int num);
extern void func_0218497C(GSMD5_CTX *context, unsigned char *input, unsigned int inputLen);
extern void gsLargeIntAddToMD5(gsLargeInt_t *lint, GSMD5_CTX *md5);
extern void func_02184A34(unsigned char *digest, GSMD5_CTX *context);
extern int gsLargeIntSetFromHexString(gsLargeInt_t *lint, char *hexstream);
extern int func_0217CF5C(gsCryptRSAKey *publicKey, unsigned char *hash, unsigned int hashLen, unsigned char *sig, unsigned int sigLen);
extern int func_02182CF0(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int func_02182B68(void *stream, char *namespaceName, char *tag, char *value);
extern int func_021830D0(void *stream, char *namespaceName, char *tag, gsLargeInt_t *lint);
extern int func_02182E90(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
int func_021E26BC(GSLoginCertificate *cert);
int func_021E2874(GSLoginCertificate *cert, char *aNamespace, void *writer);
extern char g_021E2CC8[];
extern char g_021E2CC0[];
extern char g_021E4B14[];
extern char g_021E4A5C[];
extern char g_021E4A64[];
extern char g_021E4A70[];
extern char g_021E4B1C[];
extern char g_021E4B24[];
extern char g_021E4B30[];
extern char g_021E4A7C[];
extern char g_021E4A88[];
extern char g_021E4B3C[];
extern char g_021E4B48[];
extern char g_021E4B58[];
extern char g_021E4B68[];
extern char g_021E4B74[];


/*
 * sdk:      wsLoginCertIsValid (libdwcgswebservices.TWL.HYB.a(authservice.o))
 */
int func_021E26BC(GSLoginCertificate *cert)
{
    gsCryptRSAKey sigkeypub;
    GSMD5_CTX md5;
    unsigned char hash[16];
    int cryptResult;
    unsigned int temp;

    func_02184938(&md5);
    temp = func_021E26B8(cert->mLength);
    func_0218497C(&md5, (unsigned char *)&temp, 4);
    temp = func_021E26B8(cert->mVersion);
    func_0218497C(&md5, (unsigned char *)&temp, 4);
    temp = func_021E26B8(cert->mPartnerCode);
    func_0218497C(&md5, (unsigned char *)&temp, 4);
    temp = func_021E26B8(cert->mNamespaceId);
    func_0218497C(&md5, (unsigned char *)&temp, 4);
    temp = func_021E26B8(cert->mUserId);
    func_0218497C(&md5, (unsigned char *)&temp, 4);
    temp = func_021E26B8(cert->mProfileId);
    func_0218497C(&md5, (unsigned char *)&temp, 4);
    temp = func_021E26B8(cert->mExpireTime);
    func_0218497C(&md5, (unsigned char *)&temp, 4);
    func_0218497C(&md5, (unsigned char *)cert->mProfileNick, strlen(cert->mProfileNick));
    func_0218497C(&md5, (unsigned char *)cert->mUniqueNick, strlen(cert->mUniqueNick));
    func_0218497C(&md5, (unsigned char *)cert->mCdKeyHash, strlen(cert->mCdKeyHash));
    gsLargeIntAddToMD5(&cert->mPeerPublicKey.modulus, &md5);
    gsLargeIntAddToMD5(&cert->mPeerPublicKey.exponent, &md5);
    func_0218497C(&md5, cert->mServerData, 128);
    func_02184A34(hash, &md5);
    gsLargeIntSetFromHexString(&sigkeypub.modulus, g_021E2CC8);
    gsLargeIntSetFromHexString(&sigkeypub.exponent, g_021E2CC0);
    cryptResult = func_0217CF5C(&sigkeypub, hash, 16, cert->mSignature, 128);
    if (cryptResult == 0)
        return 1;
    return 0;
}


/*
 * sdk:      wsLoginCertWriteXML (libdwcgswebservices.TWL.HYB.a(authservice.o))
 */
int func_021E2874(GSLoginCertificate *cert, char *aNamespace, void *writer)
{
    if (!func_02182CF0(writer, aNamespace, g_021E4B14, cert->mLength)
        || !func_02182CF0(writer, aNamespace, g_021E4A5C, cert->mVersion)
        || !func_02182CF0(writer, aNamespace, g_021E4A64, cert->mPartnerCode)
        || !func_02182CF0(writer, aNamespace, g_021E4A70, cert->mNamespaceId)
        || !func_02182CF0(writer, aNamespace, g_021E4B1C, cert->mUserId)
        || !func_02182CF0(writer, aNamespace, g_021E4B24, cert->mProfileId)
        || !func_02182CF0(writer, aNamespace, g_021E4B30, cert->mExpireTime)
        || !func_02182B68(writer, aNamespace, g_021E4A7C, cert->mProfileNick)
        || !func_02182B68(writer, aNamespace, g_021E4A88, cert->mUniqueNick)
        || !func_02182B68(writer, aNamespace, g_021E4B3C, cert->mCdKeyHash)
        || !func_021830D0(writer, aNamespace, g_021E4B48, &cert->mPeerPublicKey.modulus)
        || !func_021830D0(writer, aNamespace, g_021E4B58, &cert->mPeerPublicKey.exponent)
        || !func_02182E90(writer, aNamespace, g_021E4B68, cert->mServerData, 128)
        || !func_02182E90(writer, aNamespace, g_021E4B74, cert->mSignature, 128))
        return 0;
    return 1;
}
