/*
 * function: func_021C6348
 * address:  0x021C6348
 * packet:   pkt_ov114_021C6348
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_NdStartup (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   func_021C79C0  0x021C79C0  arm  ov114
 *   func_021C6898  0x021C6898  arm  ov114
 *   func_021C62FC  0x021C62FC  arm  ov114
 *   func_021C60C8  0x021C60C8  arm  ov114
 *   func_021C7908  0x021C7908  arm  ov114
 *   func_021C78C4  0x021C78C4  arm  ov114
 *   func_021BE648  0x021BE648  arm  ov114
 *   func_021C6704  0x021C6704  arm  ov114
 *   func_021C78DC  0x021C78DC  arm  ov114
 *   func_021C659C  0x021C659C  arm  ov114
 *   g_021D3B9C  0x021D3B9C  data
 *   g_021D3BE4  0x021D3BE4  data
 *   g_021D3C69  0x021D3C69  data
 *   g_021D3BCD  0x021D3BCD  data
 *   g_021D3C50  0x021D3C50  data
 *   g_021D3BF5  0x021D3BF5  data
 *
 * The file statics of dwci_nd.o sit in one block based at DWCi_Ndi_dlcallback
 * (0x021D3B9C); the struct below names its words by offset.
 */

typedef unsigned long u32;

typedef void *(*NdAlloc)(u32 size, int align);
typedef void (*NdFree)(void *p);
typedef void (*NdCallback)(int reason, int err, int servererror);

typedef struct NdStatics {
    NdCallback callback;    /* +0x00 */
    NdAlloc alloc;          /* +0x04 */
    int initialized;        /* +0x08 */
    int apinfo;             /* +0x0c */
    int w10;                /* +0x10 */
    NdFree free;            /* +0x14 */
    char *token;            /* +0x18 */
    char *url;              /* +0x1c */
    char pad20[0x3c - 0x20];
    int w3c;                /* +0x3c */
    int w40;                /* +0x40 */
    int w44;                /* +0x44 */
} NdStatics;

extern NdStatics g_021D3B9C;
extern char g_021D3BE4[];
extern char g_021D3C69[];
extern char g_021D3BCD[];
extern char g_021D3C50[];
extern char g_021D3BF5[];

extern void func_021C79C0(char *macaddr);
extern void func_021C6898(char *userAgent);
extern char *func_021C62FC(char *src);
extern int func_021C60C8(char *encstr, char *srcbin, int length);
extern int func_021C7908(void);
extern int func_021C78C4(void);
extern int func_021BE648(NdAlloc alloc, NdFree free, u32 threadprio);
extern int func_021C6704(char *apinfo);
extern void func_021C78DC(void);
extern void func_021C659C(int err, int servererror);

int func_021C6348(NdAlloc alloc, NdFree free, char *url, char *token, char *gamecd,
                  char *passwd, NdCallback callback)
{
    int len;

    g_021D3B9C.alloc = alloc;
    g_021D3B9C.free = free;
    g_021D3B9C.callback = callback;
    g_021D3B9C.w3c = 0;
    g_021D3B9C.w40 = 0;
    g_021D3B9C.w44 = 0;
    g_021D3B9C.apinfo = 0;
    g_021D3B9C.w10 = 0;
    g_021D3B9C.token = 0;
    g_021D3B9C.url = 0;

    func_021C79C0(g_021D3BE4);
    func_021C6898(g_021D3C69);

    g_021D3B9C.url = func_021C62FC(url);
    if (g_021D3B9C.url == 0)
        goto fail;
    g_021D3B9C.token = func_021C62FC(token);
    if (g_021D3B9C.token == 0)
        goto fail;

    len = func_021C60C8(g_021D3BCD, gamecd, 4);
    g_021D3BCD[len] = 0;
    len = func_021C60C8(g_021D3C50, passwd, 16);
    g_021D3C50[len] = 0;

    if (func_021C7908() && func_021C78C4()) {
        if (func_021BE648(alloc, free, 17) != -1) {
            g_021D3B9C.apinfo = func_021C6704(g_021D3BF5);
            g_021D3B9C.initialized = 1;
            return 1;
        }
        func_021C78DC();
    }
    g_021D3B9C.free(g_021D3B9C.token);
    g_021D3B9C.free(g_021D3B9C.url);
    func_021C659C(8, 0);
    return 0;

fail:
    if (g_021D3B9C.token != 0)
        g_021D3B9C.free(g_021D3B9C.token);
    if (g_021D3B9C.url != 0)
        g_021D3B9C.free(g_021D3B9C.url);
    func_021C659C(1, 0);
    return 0;
}
