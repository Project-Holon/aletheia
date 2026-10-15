/*
 * function: DWCi_NdStartup
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
 *   DWCi_Ndi_getMacAddress  0x021C79C0  arm  ov114
 *   DWCi_Ndi_getUserAgent  0x021C6898  arm  ov114
 *   strAlloc  0x021C62FC  arm  ov114
 *   DWCi_Ndi_encodeBASE64  0x021C60C8  arm  ov114
 *   DWCi_Ndi_initHttpCallback  0x021C7908  arm  ov114
 *   func_021C78C4  0x021C78C4  thumb  ov114
 *   NHTTP_Startup  0x021BE648  arm  ov114
 *   DWCi_Ndi_getApInfo  0x021C6704  arm  ov114
 *   DWCi_Ndi_freeLockGlobal  0x021C78DC  arm  ov114
 *   DWCi_NdSetError  0x021C659C  arm  ov114
 *   gDwciNdStatics  0x021D3B9C  data
 *   gDwciNdMacAddressEncoded  0x021D3BE4  data
 *   gDwciNdUserAgent  0x021D3C69  data
 *   gDwciNdGameCodeEncoded  0x021D3BCD  data
 *   gDwciNdPasswordEncoded  0x021D3C50  data
 *   gDwciNdApInfoEncoded  0x021D3BF5  data
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

extern NdStatics gDwciNdStatics;
extern char gDwciNdMacAddressEncoded[];
extern char gDwciNdUserAgent[];
extern char gDwciNdGameCodeEncoded[];
extern char gDwciNdPasswordEncoded[];
extern char gDwciNdApInfoEncoded[];

extern void DWCi_Ndi_getMacAddress(char *macaddr);
extern void DWCi_Ndi_getUserAgent(int a);
extern char *strAlloc(char *src);
extern int DWCi_Ndi_encodeBASE64(char *encstr, char *srcbin, int length);
extern int DWCi_Ndi_initHttpCallback(void);
extern int func_021C78C4(void);
extern int NHTTP_Startup(int a, int b, int c);
extern int DWCi_Ndi_getApInfo(char *apinfo);
extern void DWCi_Ndi_freeLockGlobal(void);
extern void DWCi_NdSetError(int err, int servererror);

int DWCi_NdStartup(NdAlloc alloc, NdFree free, char *url, char *token, char *gamecd,
                  char *passwd, NdCallback callback)
{
    int len;

    gDwciNdStatics.alloc = alloc;
    gDwciNdStatics.free = free;
    gDwciNdStatics.callback = callback;
    gDwciNdStatics.w3c = 0;
    gDwciNdStatics.w40 = 0;
    gDwciNdStatics.w44 = 0;
    gDwciNdStatics.apinfo = 0;
    gDwciNdStatics.w10 = 0;
    gDwciNdStatics.token = 0;
    gDwciNdStatics.url = 0;

    DWCi_Ndi_getMacAddress(gDwciNdMacAddressEncoded);
    DWCi_Ndi_getUserAgent((int)gDwciNdUserAgent);

    gDwciNdStatics.url = strAlloc(url);
    if (gDwciNdStatics.url == 0)
        goto fail;
    gDwciNdStatics.token = strAlloc(token);
    if (gDwciNdStatics.token == 0)
        goto fail;

    len = DWCi_Ndi_encodeBASE64(gDwciNdGameCodeEncoded, gamecd, 4);
    gDwciNdGameCodeEncoded[len] = 0;
    len = DWCi_Ndi_encodeBASE64(gDwciNdPasswordEncoded, passwd, 16);
    gDwciNdPasswordEncoded[len] = 0;

    if (DWCi_Ndi_initHttpCallback() && func_021C78C4()) {
        if (NHTTP_Startup((int)alloc, (int)free, 17) != -1) {
            gDwciNdStatics.apinfo = DWCi_Ndi_getApInfo(gDwciNdApInfoEncoded);
            gDwciNdStatics.initialized = 1;
            return 1;
        }
        DWCi_Ndi_freeLockGlobal();
    }
    gDwciNdStatics.free(gDwciNdStatics.token);
    gDwciNdStatics.free(gDwciNdStatics.url);
    DWCi_NdSetError(8, 0);
    return 0;

fail:
    if (gDwciNdStatics.token != 0)
        gDwciNdStatics.free(gDwciNdStatics.token);
    if (gDwciNdStatics.url != 0)
        gDwciNdStatics.free(gDwciNdStatics.url);
    DWCi_NdSetError(1, 0);
    return 0;
}
