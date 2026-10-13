/*
 * function: scSubmitReport
 * address:  0x021DFBB8
 * packet:   pkt_ov175_021DFBB8
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      scSubmitReport (libdwcgssc.TWL.HYB.a(scimain.o))
 *
 * The mChecksum zero-fill is a hand-unrolled 4-byte strb loop over an UNSIGNED
 * counter, declared before the cursor: signed n folds the exit test into
 * `cmp n,#0` + `bgt` and reverses the two scratch registers.  See
 * docs/idioms/an-unsigned-counter-keeps-the-subs-bne-of-a-countdown-loop.md.
 *
 * symbols:
 *   func_02184938  0x02184938  arm  ov009
 *   func_0218497C  0x0218497C  arm  ov009
 *   func_02184A34  0x02184A34  arm  ov009
 *   sciWsSubmitReport  0x021E0DB8  arm  ov175
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

struct GSMD5_CTX;
extern void func_02184938(struct GSMD5_CTX *context);
extern void func_0218497C(GSMD5_CTX *ctx, unsigned char *input, unsigned int len);
extern void func_02184A34(unsigned char *digest, struct GSMD5_CTX *context);
extern int sciWsSubmitReport(void *ws, unsigned int gameId, char *sessionId, char *connectionId,
                         struct SCIReport *report, int isAuth, void *cert, void *priv,
                         void *cb, unsigned int timeout, void *userData);

int scSubmitReport(void *theInterface, void *theReport, int isAuthoritative, void *theCertificate,
                  void *thePrivateData, void *theCallback, unsigned int theTimeoutMs, void *theUserData)
{
    unsigned int n;
    unsigned char *p;
    GSMD5_CTX md5;
    struct SCIReportHeader *header;
    struct SCIReport *aReport;
    struct SCInterface *anInterface;

    anInterface = theInterface;
    if (anInterface == 0)
        return 2;
    if (anInterface->mInit == 0)
        return 3;
    aReport = theReport;
    header = aReport->mData;
    p = header->mChecksum;
    n = 4;
    do {
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p += 4;
    } while (--n);
    func_02184938((struct GSMD5_CTX *)(&md5));
    func_0218497C(&md5, (unsigned char *)aReport->mData, aReport->mLength);
    func_02184A34(header->mChecksum, (struct GSMD5_CTX *)(&md5));
    return sciWsSubmitReport(anInterface, anInterface->mGameId, (char *)anInterface->mSessionId,
                         (char *)anInterface->mConnectionId, aReport, isAuthoritative,
                         theCertificate, thePrivateData, theCallback, theTimeoutMs, theUserData);
}
