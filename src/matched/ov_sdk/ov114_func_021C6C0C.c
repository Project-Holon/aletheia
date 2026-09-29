/*
 * function: setupHttp
 * address:  0x021C6C0C
 * packet:   pkt_ov114_021C6C0C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK: TwlDWC/lib/ARM9-TS/Rom/libdwcnd.TWL.HYB.a(dwci_nd.o).
 *
 * symbols:
 *   DWCi_Ndi_getDSdesc              0x021c67fc arm
 *   DWCi_NdSetError                 0x021c659c arm
 *   DWCi_Ndi_prepareHttpCallback    0x021c7934 arm
 *   freeHttpParam                   0x021c6b44 arm
 *   DWCi_NdCleanupConnectionHandle  0x021c654c arm
 *   NHTTP_CreateConnection          0x021bf04c arm
 *   DWCi_Ndi_unprepareHttpCallback  0x021c797c arm
 *   NHTTP_SetRootCA                 0x021be9c8 arm
 *   NHTTP_SetVerifyOption           0x021be8b8 arm
 *   NHTTP_AddHeaderField            0x021be6bc arm
 *   NHTTP_AddPostDataAscii          0x021be748 arm
 *   DWCi_Ndi_strlen                 0x021c7a18 arm
 *   freeHttp                        0x021c6bec arm
 *   DWCi_Ndi_memclr                 0x021c7a30 arm
 *   DWCi_Ndi_encodeBASE64           0x021c60c8 arm
 *   DWCi_Ndi_decodeBASE64           0x021c61c0 arm
 *   g_021D3BC4   0x021d3bc4 data
 *   g_021D3C0A   0x021d3c0a data
 *   g_021D3B9C   0x021d3b9c data
 *   g_021C68BC   0x021c68bc arm
 *   g_021CF37C   0x021cf37c data
 *   g_021CF498   0x021cf498 data
 *   g_021D3C69   0x021d3c69 data
 *   g_021CF4A4   0x021cf4a4 data
 *   g_021D3BCD   0x021d3bcd data
 *   g_021CF4AC   0x021cf4ac data
 *   g_021CF4B8   0x021cf4b8 data
 *   g_021D3C50   0x021d3c50 data
 *   g_021CF4C0   0x021cf4c0 data
 *   g_021CF4C8   0x021cf4c8 data
 *   g_021CF4D0   0x021cf4d0 data
 *   g_021D3BE4   0x021d3be4 data
 *   g_021CF4D8   0x021cf4d8 data
 *   g_021CF4E0   0x021cf4e0 data
 *   g_021CF4E8   0x021cf4e8 data
 *   g_021CF4F0   0x021cf4f0 data
 *   g_021CF4F8   0x021cf4f8 data
 *   g_021D3BF5   0x021d3bf5 data
 *   g_021D3CCC   0x021d3ccc data
 *   g_021CF500   0x021cf500 data
 */
typedef unsigned char u8;
typedef unsigned int u32;

typedef void *(*AllocFn)(int size, int align);

struct DWCiNdiDl {
    char *p00;
    AllocFn alloc;
    char *p08;
    char *p0C;
    char *p10;
    char *p14;
    char *p18;
    char *p1C;
    char *p20[7];
    char *p3C;
    char *p40;
    char *p44;
};

struct tagDWCi_Ndi_HTTPREQ {
    char _0[4];
    void *f4;
    void *f8;
    char _c[0x14];
};

extern int DWCi_Ndi_getDSdesc(char *gamecode, char *userid);
extern void DWCi_NdSetError(int err, int servererror);
extern int DWCi_Ndi_prepareHttpCallback(void);
extern void freeHttpParam(struct tagDWCi_Ndi_HTTPREQ *hrq);
extern int DWCi_NdCleanupConnectionHandle(void *handle);
extern void *NHTTP_CreateConnection(char *url_p, int method, char *buf_p, unsigned long len, int (*callback)(void *, int, void *), void *userParam_p);
extern void DWCi_Ndi_unprepareHttpCallback(void);
extern int NHTTP_SetRootCA(void *handle, char *rootCAData_p, unsigned long rootCASize);
extern int NHTTP_SetVerifyOption(void *handle, unsigned long verifyOption);
extern int NHTTP_AddHeaderField(void *handle, char *label_p, char *value_p);
extern int NHTTP_AddPostDataAscii(void *handle, char *label_p, char *value_p);
extern unsigned long DWCi_Ndi_strlen(char *p);
extern void freeHttp(struct tagDWCi_Ndi_HTTPREQ *hrq, void *req);
extern void DWCi_Ndi_memclr(void *p, int size);
extern int DWCi_Ndi_encodeBASE64(char *encstr, char *srcbin, int length);
extern int DWCi_Ndi_decodeBASE64(char *decbin, char *str, int length);
extern int g_021C68BC(void *res, int event, void *arg);

extern char g_021D3BC4[9];
extern char g_021D3C0A[21];
extern struct DWCiNdiDl g_021D3B9C;
extern char g_021CF37C[];
extern char g_021CF498[];
extern char g_021D3C69[33];
extern char g_021CF4A4[];
extern char g_021D3BCD[9];
extern char g_021CF4AC[];
extern char g_021CF4B8[];
extern char g_021D3C50[25];
extern char g_021CF4C0[];
extern char g_021CF4C8[];
extern char g_021CF4D0[];
extern char g_021D3BE4[17];
extern char g_021CF4D8[];
extern char g_021CF4E0[];
extern char g_021CF4E8[];
extern char g_021CF4F0[];
extern char g_021CF4F8[];
extern char g_021D3BF5[21];
extern char g_021D3CCC[89];
extern char g_021CF500[];

static int setupHttp(struct tagDWCi_Ndi_HTTPREQ **phrq, void **preq, char *strAction, char *recvbuf, unsigned int recvbufLen, char *opt)
{
    char strTemp[256];
    int n;
    struct tagDWCi_Ndi_HTTPREQ *hrq;
    void *req;

    if (DWCi_Ndi_getDSdesc(g_021D3BC4, g_021D3C0A) == 0) {
        DWCi_NdSetError(8, 0);
        return 0;
    }
    hrq = (struct tagDWCi_Ndi_HTTPREQ *)g_021D3B9C.alloc(0x20, 4);
    if (hrq == 0) {
        DWCi_NdSetError(1, 0);
        return 0;
    }
    hrq->f4 = g_021D3B9C.p00;
    hrq->f8 = 0;
    if (DWCi_Ndi_prepareHttpCallback() == 0) {
        freeHttpParam(hrq);
        DWCi_NdSetError(2, 0);
        return 0;
    }
    if (DWCi_NdCleanupConnectionHandle(g_021D3B9C.p10) == 0)
        return 0;
    req = NHTTP_CreateConnection(g_021D3B9C.p1C, 1, recvbuf, recvbufLen, g_021C68BC, hrq);
    if (req == 0) {
        DWCi_Ndi_unprepareHttpCallback();
        freeHttpParam(hrq);
        DWCi_NdSetError(3, 0);
        return 0;
    }
    *phrq = hrq;
    *preq = req;
    if (NHTTP_SetRootCA(req, g_021CF37C, 1) == -1)
        goto fail;
    if (NHTTP_SetVerifyOption(req, 0) == -1)
        goto fail;
    if (NHTTP_AddHeaderField(req, g_021CF498, g_021D3C69) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, g_021CF4A4, g_021D3BCD) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, g_021CF4AC, g_021D3BC4) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, g_021CF4B8, g_021D3C50) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, g_021CF4C0, g_021D3B9C.p18) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, g_021CF4C8, g_021D3C0A) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, g_021CF4D0, g_021D3BE4) == -1)
        goto fail;
    if (NHTTP_AddPostDataAscii(req, g_021CF4D8, strAction) == -1)
        goto fail;
    if (g_021D3B9C.p3C != 0 && NHTTP_AddPostDataAscii(req, g_021CF4E0, g_021D3B9C.p3C) == -1)
        goto fail;
    if (g_021D3B9C.p40 != 0 && NHTTP_AddPostDataAscii(req, g_021CF4E8, g_021D3B9C.p40) == -1)
        goto fail;
    if (g_021D3B9C.p44 != 0 && NHTTP_AddPostDataAscii(req, g_021CF4F0, g_021D3B9C.p44) == -1)
        goto fail;
    if (g_021D3B9C.p0C != 0 && NHTTP_AddPostDataAscii(req, g_021CF4F8, g_021D3BF5) == -1)
        goto fail;
    if (opt != 0) {
        n = DWCi_Ndi_strlen(opt);
        if (n > 0x40) {
            DWCi_NdSetError(5, 0);
            freeHttp(hrq, req);
            return 0;
        }
        DWCi_Ndi_memclr(g_021D3CCC, 0x59);
        DWCi_Ndi_encodeBASE64(g_021D3CCC, opt, n);
        if (NHTTP_AddPostDataAscii(req, g_021CF500, g_021D3CCC) == -1)
            goto fail;
    }
    DWCi_Ndi_decodeBASE64(strTemp, g_021D3BCD, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, g_021D3BC4, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, g_021D3C50, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, g_021D3B9C.p18, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, g_021D3C0A, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, g_021D3BE4, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, strAction, 0x80);
    DWCi_Ndi_decodeBASE64(strTemp, g_021D3BF5, 0x80);
    if (g_021D3B9C.p3C != 0)
        DWCi_Ndi_decodeBASE64(strTemp, g_021D3B9C.p3C, 0x80);
    if (g_021D3B9C.p40 != 0)
        DWCi_Ndi_decodeBASE64(strTemp, g_021D3B9C.p40, 0x80);
    if (g_021D3B9C.p44 != 0)
        DWCi_Ndi_decodeBASE64(strTemp, g_021D3B9C.p44, 0x80);
    if (opt != 0)
        DWCi_Ndi_decodeBASE64(strTemp, g_021D3CCC, 0x80);
    return 1;
fail:
    freeHttp(hrq, req);
    DWCi_NdSetError(1, 0);
    return 0;
}
