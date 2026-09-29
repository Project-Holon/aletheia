/*
 * function: func_021DFBB8
 * address:  0x021DFBB8
 * packet:   pkt_ov175_021DFBB8
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      scSubmitReport (libdwcgssc.TWL.HYB.a(scimain.o))
 *
 * NEAR MISS (200 vs 212 B): the mChecksum zero-fill is an unrolled 4-byte strb loop in the object; the rolled for loop here does not reproduce it.
 *
 * symbols:
 *   func_02184938  0x02184938  arm  ov175
 *   func_0218497C  0x0218497C  arm  ov175
 *   func_02184A34  0x02184A34  arm  ov175
 *   func_021E0DB8  0x021E0DB8  arm  ov175
 */

typedef struct {
    unsigned int state[4];
    unsigned int count[2];
    unsigned char buffer[64];
} GSMD5_CTX;

struct SCIReportHeader {
    unsigned int mProtocolVersion;
    unsigned int mDeveloperVersion;
    unsigned char mChecksum[16];
};

struct SCIReport {
    int mReportState;
    char pad[0x114 - 4];
    char mBufferPad[0xc];
    unsigned int mLength;
    struct SCIReportHeader *mData;
};

struct SCInterface {
    char pad0[0x4c];
    unsigned int mGameId;
    int mInit;
    char pad1[8];
    unsigned char mSessionId[40];
    unsigned char mConnectionId[40];
};

extern void func_02184938(GSMD5_CTX *ctx);
extern void func_0218497C(GSMD5_CTX *ctx, unsigned char *input, unsigned int len);
extern void func_02184A34(unsigned char *digest, GSMD5_CTX *ctx);
extern int func_021E0DB8(void *ws, unsigned int gameId, char *sessionId, char *connectionId,
                         struct SCIReport *report, int isAuth, void *cert, void *priv,
                         void *cb, unsigned int timeout, void *userData);

int func_021DFBB8(void *theInterface, void *theReport, int isAuthoritative, void *theCertificate,
                  void *thePrivateData, void *theCallback, unsigned int theTimeoutMs, void *theUserData)
{
    GSMD5_CTX md5;
    struct SCIReportHeader *header;
    struct SCIReport *aReport;
    struct SCInterface *anInterface;
    int i;

    anInterface = theInterface;
    if (anInterface == 0)
        return 2;
    if (anInterface->mInit == 0)
        return 3;
    aReport = theReport;
    header = aReport->mData;
    for (i = 0; i < 16; i++)
        header->mChecksum[i] = 0;
    func_02184938(&md5);
    func_0218497C(&md5, (unsigned char *)aReport->mData, aReport->mLength);
    func_02184A34(header->mChecksum, &md5);
    return func_021E0DB8(anInterface, anInterface->mGameId, (char *)anInterface->mSessionId,
                         (char *)anInterface->mConnectionId, aReport, isAuthoritative,
                         theCertificate, thePrivateData, theCallback, theTimeoutMs, theUserData);
}
