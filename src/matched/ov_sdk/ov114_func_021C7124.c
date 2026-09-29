/*
 * function: DWCi_NdGetFileListAsync
 * address:  0x021C7124
 * packet:   pkt_ov114_021C7124
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_NdGetFileListAsync (libdwcnd.TWL.HYB.a dwci_nd.o)
 *
 * The two NHTTP_AddPostDataAscii labels are the vendor object's own anonymous
 * string objects, so they are written here as literals and named in the
 * symbols: block under the member's @N spelling: @17416 "offset" (7 bytes at
 * 0x021CF510) and @17417 "num" (4 bytes at 0x021CF518).  Each pattern occurs
 * at exactly one aligned address of ov114's image, which is the `template`
 * class.  0x021CF518 is a three-character string, so `string` and
 * `sole-ref/string` both refuse it on length, and it is an object start in
 * ov021 as well as not one in ov114, so an ov114 `symbols:` hint on it was
 * contested; the template route needs no such hint.
 *
 * symbols:
 *   DWCi_NdSetError                 0x021C659C  arm  ov114
 *   DWCi_Ndi_intToStr               0x021C7A68  arm  ov114
 *   DWCi_Ndi_getEncodeLenBASE64     0x021C60AC  arm  ov114
 *   DWCi_Ndi_encodeBASE64           0x021C60C8  arm  ov114
 *   setupHttp                       0x021C6C0C  arm  ov114
 *   NHTTP_AddPostDataAscii          0x021BE748  arm  ov114
 *   runHttp                         0x021C70D4  arm  ov114
 *   freeHttp                        0x021C6BEC  arm  ov114
 *   g_021D3B9C                      0x021D3B9C  data  ov114
 *   DWCiNd_action_list              0x021CE0CE  data  ov114
 *   @17416                          0x021CF510  data
 *   @17417                          0x021CF518  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct DWCNdFileInfo {
    char name[33];
    short explain[51];
    char param1[11];
    char param2[11];
    char param3[11];
    unsigned int size;
} DWCNdFileInfo;

typedef struct NdStatics {
    void *callback;
    void *(*alloc)(u32 size, int align);
    int initialized;
    int apinfo;
    int w10;
    void (*free)(void *p);
} NdStatics;

typedef struct tagDWCi_Ndi_HTTPREQ {
    int reason;
    void *callback;
    void *threadEvent;
    union {
        struct {
            char *encName;
            unsigned int size;
        } getfile;
        struct {
            DWCNdFileInfo *filelist;
            int num;
            char *pBuf;
            char *strOffset;
            char *strNum;
        } list;
        char pad[20];
    } param;
} tagDWCi_Ndi_HTTPREQ;

extern NdStatics g_021D3B9C;
extern char DWCiNd_action_list[9];

extern void DWCi_NdSetError(int err, int servererror);
extern int DWCi_Ndi_intToStr(char *p, unsigned long n);
extern int DWCi_Ndi_getEncodeLenBASE64(int len);
extern int DWCi_Ndi_encodeBASE64(char *encstr, char *srcbin, int length);
extern int setupHttp(tagDWCi_Ndi_HTTPREQ **phrq, void **preq, char *strAction,
                     char *recvbuf, unsigned int recvbufLen, char *opt);
extern int NHTTP_AddPostDataAscii(void *handle, char *label_p, char *value_p);
extern int runHttp(void *hrq, void *req);
extern void freeHttp(tagDWCi_Ndi_HTTPREQ *hrq, void *req);

int DWCi_NdGetFileListAsync(DWCNdFileInfo *filelist, int offset, int num)
{
    int lenBuf;
    char *pBuf;
    char *strOffset;
    char *strNum;
    int lenNum;
    int lenOffset;
    tagDWCi_Ndi_HTTPREQ *hrq;
    void *req;
    char strBuf[12];

    lenBuf = num << 8;
    if (lenBuf < 0x80)
        lenBuf = 0x80;
    pBuf = g_021D3B9C.alloc(lenBuf, 4);
    if (pBuf == 0) {
        DWCi_NdSetError(1, 0);
        return 0;
    }
    lenOffset = DWCi_Ndi_intToStr(strBuf, offset);
    strOffset = g_021D3B9C.alloc(DWCi_Ndi_getEncodeLenBASE64(lenOffset) + 1, 4);
    if (strOffset == 0) {
        g_021D3B9C.free(pBuf);
        DWCi_NdSetError(1, 0);
        return 0;
    }
    strOffset[DWCi_Ndi_encodeBASE64(strOffset, strBuf, lenOffset)] = 0;
    lenNum = DWCi_Ndi_intToStr(strBuf, num);
    strNum = g_021D3B9C.alloc(DWCi_Ndi_getEncodeLenBASE64(lenNum) + 1, 4);
    if (strNum == 0) {
        g_021D3B9C.free(strOffset);
        g_021D3B9C.free(pBuf);
        DWCi_NdSetError(1, 0);
        return 0;
    }
    strNum[DWCi_Ndi_encodeBASE64(strNum, strBuf, lenNum)] = 0;
    if (!setupHttp(&hrq, &req, DWCiNd_action_list, pBuf, lenBuf, 0)) {
        g_021D3B9C.free(strNum);
        g_021D3B9C.free(strOffset);
        g_021D3B9C.free(pBuf);
        return 0;
    }
    if (NHTTP_AddPostDataAscii(req, "offset", strOffset) == -1)
        goto error;
    if (NHTTP_AddPostDataAscii(req, "num", strNum) == -1)
        goto error;
    hrq->reason = 2;
    hrq->param.list.filelist = filelist;
    hrq->param.list.strOffset = strOffset;
    hrq->param.list.strNum = strNum;
    hrq->param.list.num = num;
    hrq->param.list.pBuf = pBuf;
    if (runHttp(hrq, req))
        return 1;
    g_021D3B9C.free(strNum);
    g_021D3B9C.free(strOffset);
    g_021D3B9C.free(pBuf);
    return 0;

error:
    g_021D3B9C.free(strNum);
    g_021D3B9C.free(strOffset);
    g_021D3B9C.free(pBuf);
    freeHttp(hrq, req);
    DWCi_NdSetError(1, 0);
    return 0;
}
