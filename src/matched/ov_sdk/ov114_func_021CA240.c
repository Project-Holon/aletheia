/*
 * function: DWCi_EncSessionGetPrivateAsync
 * address:  0x021CA240
 * packet:   pkt_ov114_021CA240
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * notes:    the block-scoped `p` (request pointer loaded once before strlen) is not a DWARF local; it is the spelling that keeps the load in r6 across the call. strlen is declared returning unsigned long, which gives the `strb r2, [r1, -r0]` form.
 *
 * sdk:      DWCi_EncSessionGetPrivateAsync (libdwcenc.TWL.HYB.a(dwc_encsession.o))
 *
 * symbols:
 *   func_0205A16C  0x0205A16C  arm
 *   func_0205A1B0  0x0205A1B0  arm
 *   strlen  0x0209477C  arm
 *   OS_SNPrintf  0x02084F80  arm
 *   OS_SPrintf  0x02084F40  arm
 *   func_02092344  0x02092344  arm
 *   b64size  0x021C9858  arm  ov114
 *   DWCi_EncSessionEncrypt  0x021C9D9C  arm  ov114
 *   gDwcEncSession  0x021CF7AC  data
 *   gDwcEncServerUrl  0x021CF7A8  data
 *   sDwcEncSessionData  0x021CF8D0  data
 *   sDwcEncSessionHash  0x021CF84C  data
 *   sDwcEncSessionPidFormat  0x021CF8D8  data
 *   sDwcEncSessionPid  0x021CF8DC  data
 *   sDwcEncSessionZeroHash  0x021CF900  data
 *   sDwcEncSessionEmptyString  0x021CF92C  data
 *   sDwcEncSessionPidHashData  0x021CF8E4  data
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
    int   state;
    int   isinitialized;
    int   reqid;
    int   validated;
    char  gamename[32];
    char  secretkey[20];
    u32   key1;
    u32   key2;
    u32   key3;
    u32   key4;
    char *request;
    char *hash;
    char *data;
    void *resbuf;
    u32   resbuflen;
    void *decodedbuf;
    u32   decodedbuflen;
    int (*callback)(u32 *, int);
    char  lastHash[41];
} Session;

typedef struct {
    long pid;
    u32  size;
} PutHeader;

extern void *func_0205A16C(int name, u32 size);
extern void func_0205A1B0(int name, void *ptr, u32 size);
extern u32 b64size(u32 len);
extern unsigned long strlen(const char *s);
extern int OS_SNPrintf(char *dst, u32 len, const char *fmt, ...);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern int DWCi_EncSessionEncrypt(u8 *outbuf, u8 *header, u32 headerlen, u8 *srcbuf, u32 srclen);
extern void *func_02092344(void *dest, const void *src, unsigned int n);
extern Session gDwcEncSession;
extern char *gDwcEncServerUrl;
extern char sDwcEncSessionData[];
extern char sDwcEncSessionHash[];
extern char sDwcEncSessionPidFormat[];
extern char sDwcEncSessionPid[];
extern char sDwcEncSessionZeroHash[];
extern char sDwcEncSessionEmptyString[];
extern char sDwcEncSessionPidHashData[];

int DWCi_EncSessionGetPrivateAsync(char *url, long pid, void *data, u32 size, int (*cb)(u32 *, int), int reuseHash)
{
    PutHeader putheader;
    char buf[16];
    int res;

    if (gDwcEncSession.validated != 1)
        return 3;
    if (gDwcEncSession.request != 0) {
        func_0205A1B0(8, gDwcEncSession.request, 0);
        gDwcEncSession.request = 0;
    }
    gDwcEncSession.request = func_0205A16C(8,
        strlen(gDwcEncServerUrl) + strlen(gDwcEncSession.gamename) + strlen(url)
        + strlen(sDwcEncSessionPid) + OS_SNPrintf(buf, 16, sDwcEncSessionPidFormat, pid)
        + strlen(sDwcEncSessionHash) + 40 + 1 + strlen(sDwcEncSessionData) + b64size(size + 12));
    if (gDwcEncSession.request == 0)
        return 2;
    OS_SPrintf(gDwcEncSession.request, sDwcEncSessionPidHashData, gDwcEncServerUrl, gDwcEncSession.gamename, url, pid, sDwcEncSessionZeroHash, sDwcEncSessionEmptyString);
    {
        char *p = gDwcEncSession.request;
        gDwcEncSession.data = p + strlen(p);
    }
    gDwcEncSession.hash = gDwcEncSession.data - strlen(sDwcEncSessionData) - 40;
    putheader.pid = pid;
    putheader.size = size;
    res = DWCi_EncSessionEncrypt((u8 *)gDwcEncSession.data, (u8 *)&putheader, 8, data, size);
    if (res == 2) {
        func_0205A1B0(8, gDwcEncSession.request, 0);
        gDwcEncSession.request = 0;
        return 2;
    }
    if (reuseHash) {
        func_02092344(gDwcEncSession.hash, gDwcEncSession.lastHash, 40);
        gDwcEncSession.state = 6;
    } else {
        gDwcEncSession.hash[-strlen(sDwcEncSessionHash)] = '\0';
        gDwcEncSession.state = 4;
    }
    gDwcEncSession.callback = cb;
    return 0;
}
