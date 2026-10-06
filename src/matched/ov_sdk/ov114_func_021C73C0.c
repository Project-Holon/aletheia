/*
 * function: func_021C73C0
 * address:  0x021C73C0
 * packet:   pkt_ov114_021C73C0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_NdGetFileAsync (libdwcnd.TWL.HYB.a(dwci_nd.o))
 *
 * symbols:
 *   func_021C659C  0x021C659C  arm  ov114
 *   func_021C7A18  0x021C7A18  arm  ov114
 *   func_021C60AC  0x021C60AC  arm  ov114
 *   func_021C6C0C  0x021C6C0C  arm  ov114
 *   func_021C60C8  0x021C60C8  arm  ov114
 *   func_021BE748  0x021BE748  arm  ov114
 *   func_021C70D4  0x021C70D4  arm  ov114
 *   func_021C6BEC  0x021C6BEC  arm  ov114
 *   g_021D3B9C  0x021D3B9C  data
 *   g_021CE0D7  0x021CE0D7  data
 *   @17442  0x021CF51C  data
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
} NdStatics;

typedef struct DWCNdFileInfo {
    char name[33];          /* +0x00 */
    short explain[51];      /* +0x22 */
    char param1[11];        /* +0x88 */
    char param2[11];        /* +0x93 */
    char param3[11];        /* +0x9e */
    unsigned int size;      /* +0xac */
} DWCNdFileInfo;

typedef struct DWCi_Ndi_HTTPREQ {
    int reason;             /* +0x00 */
    NdCallback callback;    /* +0x04 */
    void *threadEvent;      /* +0x08 */
    union {
        struct {
            char *encName;  /* +0x0c */
            unsigned int size; /* +0x10 */
        } getfile;
        char pad[20];
    } param;
} DWCi_Ndi_HTTPREQ;

extern NdStatics g_021D3B9C;
extern char g_021CE0D7[13];

extern void func_021C659C(int err, int servererror);
typedef unsigned char  u8;
extern u32 func_021C7A18(const u8 *a0);
extern int func_021C60AC(int len);
extern int func_021C6C0C(DWCi_Ndi_HTTPREQ **phrq, void **preq, char *strAction, char *recvbuf,
                         unsigned int recvbufLen, char *opt);
extern int func_021C60C8(char *encstr, char *srcbin, int length);
extern int func_021BE748(void *handle, char *label_p, char *value_p);
extern int func_021C70D4(int unused, void *req);
extern void func_021C6BEC(void *a, int b);

int func_021C73C0(DWCNdFileInfo *filelist, char *buf, unsigned int bufsize, char *opt)
{
    DWCi_Ndi_HTTPREQ *hrq;
    void *req;
    int fnameLen;
    char *encName;
    int n;

    if (bufsize < filelist->size) {
        func_021C659C(5, 0);
        return 0;
    }
    fnameLen = func_021C7A18((const u8 *)filelist->name);
    if (fnameLen > 32) {
        func_021C659C(5, 0);
        return 0;
    }
    if (fnameLen > 0)
        n = func_021C60AC(fnameLen);
    else
        n = 0;
    encName = g_021D3B9C.alloc(n + 1, 4);
    if (encName == 0) {
        func_021C659C(1, 0);
        return 0;
    }
    if (!func_021C6C0C(&hrq, &req, g_021CE0D7, buf, filelist->size, opt)) {
        g_021D3B9C.free(encName);
        return 0;
    }
    if (n > 0) {
        encName[func_021C60C8(encName, filelist->name, fnameLen)] = 0;
        if (func_021BE748(req, "contents", encName) == -1)
            goto error;
    }
    hrq->reason = 3;
    hrq->param.getfile.encName = encName;
    hrq->param.getfile.size = filelist->size;
    if (func_021C70D4((int)hrq, req))
        return 1;
    g_021D3B9C.free(encName);
    return 0;

error:
    func_021C6BEC(hrq, (int)req);
    g_021D3B9C.free(encName);
    func_021C659C(1, 0);
    return 0;
}
