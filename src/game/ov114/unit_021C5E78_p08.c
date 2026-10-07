/*
 * file:     unit_021C5E78_p08.c
 * unit:     yes
 * function: func_021C75BC, func_021C7614, func_021C7644, func_021C78C4
 * address:  0x021C75BC
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021BF3E4  0x021BF3E4  arm  ov114
 *   func_021C7A5C  0x021C7A5C  arm  ov114
 *   NHTTP_GetBodyBuffer  0x021BF3E4  arm
 *   DWCi_Ndi_memclr                0x021C7A30  arm  ov114
 *   NHTTP_GetHeaderField           0x021BE7FC  arm  ov114
 *   DWCi_Ndi_strToInt              0x021C7A5C  arm  ov114
 *   DWCi_Ndi_memcpy                0x021C7A44  arm  ov114
 *   DWCi_Ndi_getDecodeLenBASE64    0x021C60A0  arm  ov114
 *   DWCi_Ndi_decodeBASE64          0x021C61C0  arm  ov114
 *   g_021CF528                     0x021CF528  data  ov114
 */
typedef struct {
	int a, b, c;
	int *count;
} HTTPREQ_021C75BC;

typedef struct HTTPREQ_021C7614 {
    unsigned char pad0[0x10];
    int f10;
} HTTPREQ_021C7614;

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

extern int func_021BF3E4(void *handle, char **value_pp, unsigned long *size_p);
extern int func_021C7A5C(char *p, int len);
extern int NHTTP_GetBodyBuffer(void *handle, char **value_pp, unsigned long *size_p);
extern void DWCi_Ndi_memclr(void *p, int size);
extern int NHTTP_GetHeaderField(void *handle, char *label_p, char **value_pp);
extern int DWCi_Ndi_strToInt(char *p, int len);
extern void DWCi_Ndi_memcpy(void *dst, void *src, int size);
extern int DWCi_Ndi_getDecodeLenBASE64(int len);
extern int DWCi_Ndi_decodeBASE64(char *decbin, char *str, int length);
extern void func_02086004(void *);
int func_021C75BC(void *res, HTTPREQ_021C75BC *hrq);
int func_021C7614(void *res, HTTPREQ_021C7614 *hrq);
int DWCi_Ndi_response_list(void *res, tagDWCi_Ndi_HTTPREQ *hrq);
int func_021C78C4(void);
extern char g_021CF528[];


/*
 * sdk:      DWCi_Ndi_response_count (libdwcnd.TWL.HYB.a(dwci_nd.o))
 */
int func_021C75BC(void *res, HTTPREQ_021C75BC *hrq)
{
	char *body;
	int bodyLen;
	unsigned long bodyBufSize;
	bodyLen = func_021BF3E4(res, &body, &bodyBufSize);
	if (bodyLen >= 0) {
		*hrq->count = func_021C7A5C(body, bodyLen);
		return *hrq->count >= 0;
	}
	return 0;
}


/*
 * sdk:      DWCi_Ndi_response_contents (libdwcnd.TWL.HYB.a dwci_nd.o)
 */
int func_021C7614(void *res, HTTPREQ_021C7614 *hrq)
{
    char *body;
    int bodyLen;
    unsigned long bodyBufSize;

    bodyLen = NHTTP_GetBodyBuffer(res, &body, &bodyBufSize);
    return bodyLen == hrq->f10;
}


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


int func_021C78C4(void)
{
    func_02086004((void *)0x021D3C38);
    return 1;
}
