/*
 * function: func_021E2874
 * address:  0x021E2874
 * packet:   pkt_ov175_021E2874
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      wsLoginCertWriteXML (libdwcgswebservices.TWL.HYB.a(authservice.o))
 *
 * symbols:
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

extern int func_02182CF0(void *stream, char *namespaceName, char *tag, unsigned int value);
extern int func_02182B68(void *stream, char *namespaceName, char *tag, char *value);
extern int func_021830D0(void *stream, char *namespaceName, char *tag, gsLargeInt_t *lint);
extern int func_02182E90(void *stream, char *namespaceName, char *tag, unsigned char *data, int len);
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
