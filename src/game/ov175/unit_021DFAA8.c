/*
 * file:     unit_021DFAA8.c
 * unit:     yes
 * function: func_021DFAA8, func_021DFAB8, func_021DFB18, func_021DFBB8, func_021DFC8C
 * address:  0x021DFAA8
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
 *   func_021DF928  0x021DF928  arm
 *   func_021E26BC  0x021E26BC  arm  ov175
 *   func_021E0774  0x021E0774  arm  ov175
 *   func_021DF948  0x021DF948  arm
 *   func_021E0A7C  0x021E0A7C  arm
 *   func_02184938  0x02184938  arm  ov009
 *   func_0218497C  0x0218497C  arm  ov009
 *   func_02184A34  0x02184A34  arm  ov009
 *   func_021E0DB8  0x021E0DB8  arm  ov175
 *   func_021DFE2C  0x021DFE2C  arm  ov175
 */
struct GSLoginCertificate;
struct GSMD5_CTX;
typedef unsigned int u32;

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

extern void func_021DF928(char *obj, int v);
extern int func_021E26BC(struct GSLoginCertificate *cert);
extern int func_021E0774(void *, u32, u32, u32, u32, u32, u32);
int func_021DF948(int *ctx, int a1);
int func_021E0A7C(int *ctx, int x, char *p, char *q,
                  int a, int b, int c, int d, int e, int f);
extern void func_02184938(struct GSMD5_CTX *context);
extern void func_0218497C(GSMD5_CTX *ctx, unsigned char *input, unsigned int len);
extern void func_02184A34(unsigned char *digest, struct GSMD5_CTX *context);
extern int func_021E0DB8(void *ws, unsigned int gameId, char *sessionId, char *connectionId,
                         struct SCIReport *report, int isAuth, void *cert, void *priv,
                         void *cb, unsigned int timeout, void *userData);
extern int func_021DFE2C(void *, int, int, int, void **);
int func_021DFAA8(char *a, int b);
int func_021DFAB8(u32 *p, u32 a, u32 b, u32 c, u32 d, u32 e);
int func_021DFB18(int *ctx, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
int func_021DFBB8(void *theInterface, void *theReport, int isAuthoritative, void *theCertificate, void *thePrivateData, void *theCallback, unsigned int theTimeoutMs, void *theUserData);
int func_021DFC8C(u32 *p, int a1, int a2, int a3, void **out);




/*
 * Fire-and-forget wrapper: kick 0x021DF928 and report success.
 */
int func_021DFAA8(char *a, int b)
{
    func_021DF928(a, b);
    return 0;
}




/*
 * SDK provenance: scCreateMatchlessSession (TwlDWC/libdwcgssc.TWL.HYB.a,
 * scimain.o), ov175.  Validate the certificate, then hand the session request
 * to sciWsCreateMatchlessSession with the stored host list.
 */
int func_021DFAB8(u32 *p, u32 a, u32 b, u32 c, u32 d, u32 e)
{
    if (func_021E26BC((void *)a) == 0)
        return 2;
    return func_021E0774(p, p[0x4c / 4], a, b, c, d, e);
}



int func_021DFB18(int *ctx, int a1, int a2, int a3,
                  int a4, int a5, int a6, int a7)
{
    if (ctx == 0)
        return 2;
    if (a3 == 0)
        return 2;
    if (a4 == 0)
        return 2;
    if (ctx[0x14] == 0)
        return 3;
    func_021DF948(ctx, a1);
    return func_021E0A7C(ctx, ctx[0x13], (char *)ctx + 0x5c, (char *)ctx + 0x84,
                        a2, a3, a4, a5, a6, a7);
}



/*
 * sdk:      scSubmitReport (libdwcgssc.TWL.HYB.a(scimain.o))
 *
 * The mChecksum zero-fill is a hand-unrolled 4-byte strb loop over an UNSIGNED
 * counter, declared before the cursor: signed n folds the exit test into
 * `cmp n,#0` + `bgt` and reverses the two scratch registers.  See
 * docs/idioms/an-unsigned-counter-keeps-the-subs-bne-of-a-countdown-loop.md.
 */
int func_021DFBB8(void *theInterface, void *theReport, int isAuthoritative, void *theCertificate,
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
    return func_021E0DB8(anInterface, anInterface->mGameId, (char *)anInterface->mSessionId,
                         (char *)anInterface->mConnectionId, aReport, isAuthoritative,
                         theCertificate, thePrivateData, theCallback, theTimeoutMs, theUserData);
}



/*
 * SDK provenance: scCreateReport (TwlDWC/libdwcgssc.TWL.HYB.a, scimain.o),
 * ov175.  Guard the handle and the out-parameter, then forward to
 * sciCreateReport and publish the new record on success.
 */
int func_021DFC8C(u32 *p, int a1, int a2, int a3, void **out)
{
    void *tmp = 0;
    int r;

    if (p == 0)
        return 2;
    if (out == 0)
        return 2;
    r = func_021DFE2C((char *)p + 0x5c, a1, a2, a3, &tmp);
    if (r == 0)
        *out = tmp;
    return r;
}
