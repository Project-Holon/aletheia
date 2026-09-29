/*
 * function: DWCi_Ndi_response_list
 * address:  0x021C7644
 * packet:   pkt_ov114_021C7644
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * blocker:  full body, logic matches the listing.  Object was built by
 *           Metrowerks 4.0.0.1025, which no tools/mwccarm build writes;
 *           dsi/1.1p1 (1024) differs in two scheduling decisions: it
 *           branches the `bodyLen > 0 && size > 0` guard where the image
 *           predicates it (ldrgt/movgt/strgt/cmpgt/ble), and it inlines the
 *           shared `return isComplete` epilogue at every early return where
 *           the image jumps to one shared ldr [sp,#4]/pop at 0x021C78B4.
 *           Result 724 vs 640 bytes.  Callee-saved mapping now matches the
 *           image (state=r6, bgn=r7, pfi=r8, tempBuf=sl) after declaring
 *           state before bgn.
 *
 * sdk:      DWCi_Ndi_response_list (libdwcnd.TWL.HYB.a dwci_nd.o)
 *
 * symbols:
 *   DWCi_Ndi_memclr                0x021C7A30  arm  ov114
 *   NHTTP_GetHeaderField           0x021BE7FC  arm  ov114
 *   NHTTP_GetBodyBuffer            0x021BF3E4  arm  ov114
 *   DWCi_Ndi_strToInt              0x021C7A5C  arm  ov114
 *   DWCi_Ndi_memcpy                0x021C7A44  arm  ov114
 *   DWCi_Ndi_getDecodeLenBASE64    0x021C60A0  arm  ov114
 *   DWCi_Ndi_decodeBASE64          0x021C61C0  arm  ov114
 *   g_021CF528                     0x021CF528  data  ov114
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

typedef struct tagDWCi_Ndi_HTTPREQ {
    int reason;
    void *callback;
    void *threadEvent;
    union {
        struct {
            char *encName;
            unsigned int size;
        } getfile;
        char pad[20];
    } param;
} tagDWCi_Ndi_HTTPREQ;

extern void DWCi_Ndi_memclr(void *p, int size);
extern int NHTTP_GetHeaderField(void *handle, char *label_p, char **value_pp);
extern int NHTTP_GetBodyBuffer(void *handle, char **value_pp, unsigned long *size_p);
extern int DWCi_Ndi_strToInt(char *p, int len);
extern void DWCi_Ndi_memcpy(void *dst, void *src, int size);
extern int DWCi_Ndi_getDecodeLenBASE64(int len);
extern int DWCi_Ndi_decodeBASE64(char *decbin, char *str, int length);
extern char g_021CF528[];

int DWCi_Ndi_response_list(void *res, tagDWCi_Ndi_HTTPREQ *hrq)
{
    char tempBuf[104];
    char *body;
    unsigned long bodyBufSize;
    char *contentlen;
    int n;
    int isComplete;
    tagDWCi_Ndi_HTTPREQ *req;
    int bodyLen;
    int p;
    int state;
    int bgn;
    int detect0x0d;
    int decordedLen;
    DWCNdFileInfo *pfi;

    req = hrq;
    isComplete = 0;
    DWCi_Ndi_memclr(hrq->param.getfile.encName, hrq->param.getfile.size * 0xb0);
    if (NHTTP_GetHeaderField(res, g_021CF528, &contentlen) > 0) {
        if (contentlen[0] == '0' && contentlen[1] == 0)
            return 1;
    }
    bodyLen = NHTTP_GetBodyBuffer(res, &body, &bodyBufSize);
    if (bodyLen > 0 && req->param.getfile.size > 0) {
        p = 0;
        for (n = 0; n < req->param.getfile.size; n++) {
            if (p >= bodyLen) { isComplete = 1; break; }
            pfi = (DWCNdFileInfo *)(req->param.getfile.encName + n * 0xb0);
            state = 0;
            bgn = p;
            detect0x0d = 0;
            isComplete = 0;
            for (; p < bodyLen; p++) {
                int c = body[p];
                if (c == 0xd) {
                    detect0x0d = 1;
                    continue;
                }
                if (detect0x0d) {
                    if (c != 0xa) {
                        detect0x0d = 0;
                        continue;
                    }
                    if (state == 5) {
                        if (p - 1 - bgn > 8)
                            return isComplete;
                        decordedLen = DWCi_Ndi_strToInt(body + bgn, p - 1 - bgn);
                        if (decordedLen < 0)
                            return isComplete;
                        pfi->size = decordedLen;
                    }
                    isComplete = state >= 5;
                    p++;
                    goto next_file;
                }
                if (c == 9) {
                    switch (state) {
                    case 0:
                        if (p - bgn > 0x20)
                            return isComplete;
                        DWCi_Ndi_memcpy(pfi, body + bgn, p - bgn);
                        break;
                    case 1:
                        decordedLen = DWCi_Ndi_getDecodeLenBASE64(p - bgn);
                        if (decordedLen > 0x66)
                            return isComplete;
                        decordedLen = DWCi_Ndi_decodeBASE64(tempBuf, body + bgn, p - bgn);
                        if (decordedLen > 0x66)
                            decordedLen = 0x66;
                        DWCi_Ndi_memcpy(pfi->explain, tempBuf, decordedLen);
                        pfi->explain[50] = 0;
                        break;
                    case 2:
                        if (p - bgn > 0xa)
                            return isComplete;
                        DWCi_Ndi_memcpy(pfi->param1, body + bgn, p - bgn);
                        break;
                    case 3:
                        if (p - bgn > 0xa)
                            return isComplete;
                        DWCi_Ndi_memcpy(pfi->param2, body + bgn, p - bgn);
                        break;
                    case 4:
                        if (p - bgn > 0xa)
                            return isComplete;
                        DWCi_Ndi_memcpy(pfi->param3, body + bgn, p - bgn);
                        break;
                    case 5:
                        if (p - bgn > 8)
                            return isComplete;
                        decordedLen = DWCi_Ndi_strToInt(body + bgn, p - bgn);
                        if (decordedLen < 0)
                            return isComplete;
                        pfi->size = decordedLen;
                        break;
                    }
                    state++;
                    bgn = p + 1;
                }
                detect0x0d = 0;
            }
        next_file:
            ;
        }
    }
    return isComplete;
}
