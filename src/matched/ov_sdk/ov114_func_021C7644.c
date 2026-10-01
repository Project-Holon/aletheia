/*
 * function: DWCi_Ndi_response_list
 * address:  0x021C7644
 * packet:   pkt_ov114_021C7644
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * lane 06 (2026-10-01): closed from 430 B. The 4.0.0.1025 "scheduling" residue was source
 *           shape: the request count at hrq+0x10 is a signed int (ble, not bls); the
 *           field-length guards compare against sizeof (unsigned bhi/movhi); the inner loop
 *           is `if (body[p] == 0x0d) {...continue;} if (detect0x0d) { if (body[p] == 0x0a)
 *           {...} } else if (body[p] == 0x09) {...} detect0x0d = 0;` so a non-LF after CR
 *           falls into the shared clear; no `req`/`c` stand-ins (not in DWARF); `size`
 *           holds p - bgn for the BASE64 case; and `p++` comes before
 *           `isComplete = state >= 5`.
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
            int size;
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
    char *body;
    int bodyLen;
    int n;
    int p;
    int state;
    int bgn;
    int isComplete;
    int detect0x0d;
    DWCNdFileInfo *pfi;
    int size;
    unsigned long bodyBufSize;
    char *contentlen;
    char tempBuf[104];
    int decordedLen;

    isComplete = 0;
    DWCi_Ndi_memclr(hrq->param.getfile.encName, hrq->param.getfile.size * 0xb0);
    if (NHTTP_GetHeaderField(res, g_021CF528, &contentlen) > 0) {
        if (contentlen[0] == '0' && contentlen[1] == 0)
            return 1;
    }
    bodyLen = NHTTP_GetBodyBuffer(res, &body, &bodyBufSize);
    if (bodyLen > 0) {
        p = 0;
        for (n = 0; n < hrq->param.getfile.size; n++) {
            if (p >= bodyLen) { isComplete = 1; break; }
            pfi = (DWCNdFileInfo *)(hrq->param.getfile.encName + n * 0xb0);
            state = 0;
            bgn = p;
            detect0x0d = 0;
            isComplete = 0;
            for (; p < bodyLen; p++) {
                if (body[p] == 0x0d) {
                    detect0x0d = 1;
                    continue;
                }
                if (detect0x0d) {
                    if (body[p] == 0x0a) {
                        if (state == 5) {
                            if (p - 1 - bgn > 8)
                                goto done;
                            decordedLen = DWCi_Ndi_strToInt(body + bgn, p - 1 - bgn);
                            if (decordedLen < 0)
                                goto done;
                            pfi->size = decordedLen;
                        }
                        p++;
                        isComplete = state >= 5;
                        break;
                    }
                } else if (body[p] == 0x09) {
                    switch (state) {
                    case 0:
                        if (p - bgn > sizeof(pfi->name) - 1)
                            goto done;
                        DWCi_Ndi_memcpy(pfi->name, body + bgn, p - bgn);
                        break;
                    case 1:
                        size = p - bgn;
                        decordedLen = DWCi_Ndi_getDecodeLenBASE64(size);
                        if (decordedLen > sizeof(pfi->explain))
                            goto done;
                        decordedLen = DWCi_Ndi_decodeBASE64(tempBuf, body + bgn, size);
                        if (decordedLen > sizeof(pfi->explain))
                            decordedLen = sizeof(pfi->explain);
                        DWCi_Ndi_memcpy(pfi->explain, tempBuf, decordedLen);
                        pfi->explain[50] = 0;
                        break;
                    case 2:
                        if (p - bgn > sizeof(pfi->param1) - 1)
                            goto done;
                        DWCi_Ndi_memcpy(pfi->param1, body + bgn, p - bgn);
                        break;
                    case 3:
                        if (p - bgn > sizeof(pfi->param2) - 1)
                            goto done;
                        DWCi_Ndi_memcpy(pfi->param2, body + bgn, p - bgn);
                        break;
                    case 4:
                        if (p - bgn > sizeof(pfi->param3) - 1)
                            goto done;
                        DWCi_Ndi_memcpy(pfi->param3, body + bgn, p - bgn);
                        break;
                    case 5:
                        if (p - bgn > 8)
                            goto done;
                        decordedLen = DWCi_Ndi_strToInt(body + bgn, p - bgn);
                        if (decordedLen < 0)
                            goto done;
                        pfi->size = decordedLen;
                        break;
                    }
                    state++;
                    bgn = p + 1;
                }
                detect0x0d = 0;
            }
        }
    }
done:
    return isComplete;
}
