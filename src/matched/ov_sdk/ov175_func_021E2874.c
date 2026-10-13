/*
 * function: wsLoginCertWriteXML
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
 *   sWsTagLength  0x021E4B14  data
 *   sWsTagVersion  0x021E4A5C  data
 *   sWsTagPartnerCode  0x021E4A64  data
 *   sWsTagNamespaceId  0x021E4A70  data
 *   sWsTagUserId  0x021E4B1C  data
 *   sWsTagProfileId  0x021E4B24  data
 *   sWsTagExpireTime  0x021E4B30  data
 *   sWsTagProfileNick  0x021E4A7C  data
 *   sWsTagUniqueNick  0x021E4A88  data
 *   sWsTagCdKeyHash  0x021E4B3C  data
 *   sWsTagPeerKeyModulus  0x021E4B48  data
 *   sWsTagPeerKeyExponent  0x021E4B58  data
 *   sWsTagServerData  0x021E4B68  data
 *   sWsTagSignature  0x021E4B74  data
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
extern char sWsTagLength[];
extern char sWsTagVersion[];
extern char sWsTagPartnerCode[];
extern char sWsTagNamespaceId[];
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

int wsLoginCertWriteXML(GSLoginCertificate *cert, char *aNamespace, void *writer)
{
    if (!func_02182CF0(writer, aNamespace, sWsTagLength, cert->mLength)
        || !func_02182CF0(writer, aNamespace, sWsTagVersion, cert->mVersion)
        || !func_02182CF0(writer, aNamespace, sWsTagPartnerCode, cert->mPartnerCode)
        || !func_02182CF0(writer, aNamespace, sWsTagNamespaceId, cert->mNamespaceId)
        || !func_02182CF0(writer, aNamespace, sWsTagUserId, cert->mUserId)
        || !func_02182CF0(writer, aNamespace, sWsTagProfileId, cert->mProfileId)
        || !func_02182CF0(writer, aNamespace, sWsTagExpireTime, cert->mExpireTime)
        || !func_02182B68(writer, aNamespace, sWsTagProfileNick, cert->mProfileNick)
        || !func_02182B68(writer, aNamespace, sWsTagUniqueNick, cert->mUniqueNick)
        || !func_02182B68(writer, aNamespace, sWsTagCdKeyHash, cert->mCdKeyHash)
        || !func_021830D0(writer, aNamespace, sWsTagPeerKeyModulus, &cert->mPeerPublicKey.modulus)
        || !func_021830D0(writer, aNamespace, sWsTagPeerKeyExponent, &cert->mPeerPublicKey.exponent)
        || !func_02182E90(writer, aNamespace, sWsTagServerData, cert->mServerData, 128)
        || !func_02182E90(writer, aNamespace, sWsTagSignature, cert->mSignature, 128))
        return 0;
    return 1;
}
