/*
 * function: func_021E2A5C
 * address:  0x021E2A5C
 * packet:   pkt_021E2A5C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gsXmlReadChildAsInt         0x02183A24  arm
 *   gsXmlReadChildAsStringNT    0x0218372C  arm
 *   gsXmlReadChildAsHexBinary   0x021837A4  arm
 *   gsLargeIntSetFromHexString  0x0217E848  arm
 *   sWsTagVersion                  0x021E4A5C  data
 *   sWsTagPartnerCode                  0x021E4A64  data
 *   sWsTagNamespaceId                  0x021E4A70  data
 *   sWsTagProfileNick                  0x021E4A7C  data
 *   sWsTagUniqueNick                  0x021E4A88  data
 *   sWsTagLength                  0x021E4B14  data
 *   sWsTagUserId                  0x021E4B1C  data
 *   sWsTagProfileId                  0x021E4B24  data
 *   sWsTagExpireTime                  0x021E4B30  data
 *   sWsTagCdKeyHash                  0x021E4B3C  data
 *   sWsTagPeerKeyModulus                  0x021E4B48  data
 *   sWsTagPeerKeyExponent                  0x021E4B58  data
 *   sWsTagServerData                  0x021E4B68  data
 *   sWsTagSignature                  0x021E4B74  data
 *
 * Gamespy (DWC) login profile XML reader: one long conjunction of
 * gsXmlReadChild* calls, so every failure shares the single fallback
 * epilogue at 0x021E2C18 (see
 * docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md).
 * The two peer-key blobs are read as NT strings into a scratch buffer and
 * converted in place by gsLargeIntSetFromHexString.
 *
 * The conjunction must be written `if (!(a && ... && n)) return 0; return 1;`
 * and NOT `return a && ... && n;`: the direct return if-converts the last
 * operand into a predicated success epilogue (`addne sp`/`movne r0,#1`/`popne`)
 * where the original branches to a separate success block; the negated-if form
 * reproduces the branch. See
 * docs/idioms/a-negated-conjunction-return-is-not-the-same-as-returning-the-conjunction.md.
 *
 * All four callees are DWC/gamespy SDK (libdwcgscommon) and every pool word is
 * a gamespy XML key string, so this packet has no non-SDK dependency leaf.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021E2A5C.c \
 *       --func func_021E2A5C --addr 0x021E2A5C --cc dsi/1.1p1 --arm \
 *       --region ov175 --flags=-O4,p
 */

typedef unsigned int u32;

typedef struct {
    u32 length;
    u32 data[64];
} GsLargeInt;

typedef struct {
    int  unk00;
    int  length;
    int  version;
    int  partnercode;
    int  namespace;
    int  userid;
    int  profileid;
    int  expiretime;
    char profile[31];
    char uniquenick[21];
    char cdkeyhash[33];
    char pad[3];
    GsLargeInt peerkeymodulus;
    GsLargeInt peerkeyexponent;
    char signature[128];
    char serverdata[128];
} GsProfile;

extern int gsXmlReadChildAsInt(void *xml, const char *name, int *out);
extern int gsXmlReadChildAsStringNT(void *xml, const char *name, char *out, u32 len);
extern int gsXmlReadChildAsHexBinary(void *xml, const char *name, void *out, u32 len, int *outLen);
extern int gsLargeIntSetFromHexString(void *dst, const char *hex);

extern char sWsTagVersion[];
extern char sWsTagPartnerCode[];
extern char sWsTagNamespaceId[];
extern char sWsTagProfileNick[];
extern char sWsTagUniqueNick[];
extern char sWsTagLength[];
extern char sWsTagUserId[];
extern char sWsTagProfileId[];
extern char sWsTagExpireTime[];
extern char sWsTagCdKeyHash[];
extern char sWsTagPeerKeyModulus[];
extern char sWsTagPeerKeyExponent[];
extern char sWsTagServerData[];
extern char sWsTagSignature[];

int func_021E2A5C(GsProfile *p, void *xml)
{
    char buf[0x101];
    int outLen;

    if (!(gsXmlReadChildAsInt(xml, sWsTagLength, &p->length)
        && gsXmlReadChildAsInt(xml, sWsTagVersion, &p->version)
        && gsXmlReadChildAsInt(xml, sWsTagPartnerCode, &p->partnercode)
        && gsXmlReadChildAsInt(xml, sWsTagNamespaceId, &p->namespace)
        && gsXmlReadChildAsInt(xml, sWsTagUserId, &p->userid)
        && gsXmlReadChildAsInt(xml, sWsTagProfileId, &p->profileid)
        && gsXmlReadChildAsInt(xml, sWsTagExpireTime, &p->expiretime)
        && gsXmlReadChildAsStringNT(xml, sWsTagProfileNick, p->profile, 0x1f)
        && gsXmlReadChildAsStringNT(xml, sWsTagUniqueNick, p->uniquenick, 0x15)
        && gsXmlReadChildAsStringNT(xml, sWsTagCdKeyHash, p->cdkeyhash, 0x21)
        && gsXmlReadChildAsStringNT(xml, sWsTagPeerKeyModulus, buf, 0x101)
        && gsLargeIntSetFromHexString(&p->peerkeymodulus, buf)
        && gsXmlReadChildAsStringNT(xml, sWsTagPeerKeyExponent, buf, 0x101)
        && gsLargeIntSetFromHexString(&p->peerkeyexponent, buf)
        && gsXmlReadChildAsHexBinary(xml, sWsTagServerData, p->serverdata, 0x80, &outLen)
        && gsXmlReadChildAsHexBinary(xml, sWsTagSignature, p->signature, 0x80, &outLen)))
        return 0;
    return 1;
}
