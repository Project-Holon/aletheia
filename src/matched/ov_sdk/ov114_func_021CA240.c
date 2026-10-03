/*
 * function: func_021CA240
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
 *   func_02084F80  0x02084F80  arm
 *   func_02084F40  0x02084F40  arm
 *   func_02092344  0x02092344  arm
 *   func_021C9858  0x021C9858  arm  ov114
 *   func_021C9D9C  0x021C9D9C  arm  ov114
 *   g_021CF7AC  0x021CF7AC  data
 *   g_021CF7A8  0x021CF7A8  data
 *   g_021CF8D0  0x021CF8D0  data
 *   g_021CF84C  0x021CF84C  data
 *   g_021CF8D8  0x021CF8D8  data
 *   g_021CF8DC  0x021CF8DC  data
 *   g_021CF900  0x021CF900  data
 *   g_021CF92C  0x021CF92C  data
 *   g_021CF8E4  0x021CF8E4  data
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
extern u32 func_021C9858(u32 len);
extern unsigned long strlen(const char *s);
extern int func_02084F80(char *dst, u32 len, const char *fmt, ...);
extern int func_02084F40(char *dst, const char *fmt, ...);
extern int func_021C9D9C(u8 *outbuf, u8 *header, u32 headerlen, u8 *srcbuf, u32 srclen);
extern void *func_02092344(void *dest, const void *src, unsigned int n);
extern Session g_021CF7AC;
extern char *g_021CF7A8;
extern char g_021CF8D0[];
extern char g_021CF84C[];
extern char g_021CF8D8[];
extern char g_021CF8DC[];
extern char g_021CF900[];
extern char g_021CF92C[];
extern char g_021CF8E4[];

int func_021CA240(char *url, long pid, void *data, u32 size, int (*cb)(u32 *, int), int reuseHash)
{
    PutHeader putheader;
    char buf[16];
    int res;

    if (g_021CF7AC.validated != 1)
        return 3;
    if (g_021CF7AC.request != 0) {
        func_0205A1B0(8, g_021CF7AC.request, 0);
        g_021CF7AC.request = 0;
    }
    g_021CF7AC.request = func_0205A16C(8,
        strlen(g_021CF7A8) + strlen(g_021CF7AC.gamename) + strlen(url)
        + strlen(g_021CF8DC) + func_02084F80(buf, 16, g_021CF8D8, pid)
        + strlen(g_021CF84C) + 40 + 1 + strlen(g_021CF8D0) + func_021C9858(size + 12));
    if (g_021CF7AC.request == 0)
        return 2;
    func_02084F40(g_021CF7AC.request, g_021CF8E4, g_021CF7A8, g_021CF7AC.gamename, url, pid, g_021CF900, g_021CF92C);
    {
        char *p = g_021CF7AC.request;
        g_021CF7AC.data = p + strlen(p);
    }
    g_021CF7AC.hash = g_021CF7AC.data - strlen(g_021CF8D0) - 40;
    putheader.pid = pid;
    putheader.size = size;
    res = func_021C9D9C((u8 *)g_021CF7AC.data, (u8 *)&putheader, 8, data, size);
    if (res == 2) {
        func_0205A1B0(8, g_021CF7AC.request, 0);
        g_021CF7AC.request = 0;
        return 2;
    }
    if (reuseHash) {
        func_02092344(g_021CF7AC.hash, g_021CF7AC.lastHash, 40);
        g_021CF7AC.state = 6;
    } else {
        g_021CF7AC.hash[-strlen(g_021CF84C)] = '\0';
        g_021CF7AC.state = 4;
    }
    g_021CF7AC.callback = cb;
    return 0;
}
