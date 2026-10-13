/*
 * function: DWCi_NdGetFileAsync
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
 *   DWCi_NdSetError  0x021C659C  arm  ov114
 *   DWCi_Ndi_strlen  0x021C7A18  arm  ov114
 *   DWCi_Ndi_getEncodeLenBASE64  0x021C60AC  arm  ov114
 *   setupHttp  0x021C6C0C  arm  ov114
 *   DWCi_Ndi_encodeBASE64  0x021C60C8  arm  ov114
 *   NHTTP_AddPostDataAscii  0x021BE748  arm  ov114
 *   runHttp  0x021C70D4  arm  ov114
 *   freeHttp  0x021C6BEC  arm  ov114
 *   gDwciNdStatics  0x021D3B9C  data
 *   sDwciNdYUdgvudhm  0x021CE0D7  data
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

extern NdStatics gDwciNdStatics;
extern char sDwciNdYUdgvudhm[13];

extern void DWCi_NdSetError(int err, int servererror);
typedef unsigned char  u8;
extern u32 DWCi_Ndi_strlen(const u8 *a0);
extern int DWCi_Ndi_getEncodeLenBASE64(int len);
extern int setupHttp(DWCi_Ndi_HTTPREQ **phrq, void **preq, char *strAction, char *recvbuf,
                         unsigned int recvbufLen, char *opt);
extern int DWCi_Ndi_encodeBASE64(char *encstr, char *srcbin, int length);
extern int NHTTP_AddPostDataAscii(void *handle, char *label_p, char *value_p);
extern int runHttp(int unused, void *req);
extern void freeHttp(void *a, int b);

int DWCi_NdGetFileAsync(DWCNdFileInfo *filelist, char *buf, unsigned int bufsize, char *opt)
{
    DWCi_Ndi_HTTPREQ *hrq;
    void *req;
    int fnameLen;
    char *encName;
    int n;

    if (bufsize < filelist->size) {
        DWCi_NdSetError(5, 0);
        return 0;
    }
    fnameLen = DWCi_Ndi_strlen((const u8 *)filelist->name);
    if (fnameLen > 32) {
        DWCi_NdSetError(5, 0);
        return 0;
    }
    if (fnameLen > 0)
        n = DWCi_Ndi_getEncodeLenBASE64(fnameLen);
    else
        n = 0;
    encName = gDwciNdStatics.alloc(n + 1, 4);
    if (encName == 0) {
        DWCi_NdSetError(1, 0);
        return 0;
    }
    if (!setupHttp(&hrq, &req, sDwciNdYUdgvudhm, buf, filelist->size, opt)) {
        gDwciNdStatics.free(encName);
        return 0;
    }
    if (n > 0) {
        encName[DWCi_Ndi_encodeBASE64(encName, filelist->name, fnameLen)] = 0;
        if (NHTTP_AddPostDataAscii(req, "contents", encName) == -1)
            goto error;
    }
    hrq->reason = 3;
    hrq->param.getfile.encName = encName;
    hrq->param.getfile.size = filelist->size;
    if (runHttp((int)hrq, req))
        return 1;
    gDwciNdStatics.free(encName);
    return 0;

error:
    freeHttp(hrq, (int)req);
    gDwciNdStatics.free(encName);
    DWCi_NdSetError(1, 0);
    return 0;
}
