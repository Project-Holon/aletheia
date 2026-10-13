/*
 * function: NHTTP_GetResponseHeaderField
 * address:  0x021BBCF0
 * packet:   pkt_ov114_021BBCF0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTP_GetResponseHeaderField (libnhttp.TWL.HYB.a(nhttp_response.o))
 *
 * symbols:
 *   NHTTPi_free 0x021BA850 arm ov114
 *   NHTTPi_getHeaderValue 0x021BBBC8 arm ov114
 *   NHTTPi_alloc 0x021BA820 arm ov114
 *   NHTTPi_loadFromHdrRecvBuf 0x021BB210 arm ov114
 *   NHTTPi_strcmp 0x021BA130 arm ov114
 *   sNHTTPStatusCodeLabel 0x021CE414 data
 */

typedef struct {
    int headerLen;
    int bodyLen;
    int totalBodyLen;
    int contentLength;
    int isSuccess;
    int isHeaderParse;
    int httpStatus;
    unsigned long recvBufLen;
    char *allHeader_p;
    char *foundHeader_p;
} Res;

extern char sNHTTPStatusCodeLabel[];

extern void NHTTPi_free(int a);
extern int NHTTPi_getHeaderValue(Res *res_p, char *label_p, int *pos_p);
extern int NHTTPi_alloc(int a, int b);
extern void NHTTPi_loadFromHdrRecvBuf(Res *res_p, char *buf, int pos, int size);
extern int NHTTPi_strcmp(char *a, char *b);

int NHTTP_GetResponseHeaderField(Res *res_p, char *label_p, char **value_pp)
{
    int pos;
    int size;

    if (res_p->isHeaderParse == 0) {
        return -1;
    }
    if (res_p->foundHeader_p) {
        NHTTPi_free((int)res_p->foundHeader_p);
        res_p->foundHeader_p = 0;
    }
    size = NHTTPi_getHeaderValue(res_p, label_p, &pos);
    if (size >= 0) {
        res_p->foundHeader_p = (char *)NHTTPi_alloc(size + 1, 4);
        if (res_p->foundHeader_p == 0) {
            return -1;
        }
        res_p->foundHeader_p[size] = 0;
        NHTTPi_loadFromHdrRecvBuf(res_p, res_p->foundHeader_p, pos, size);
        *value_pp = res_p->foundHeader_p;
        return size;
    }
    if (NHTTPi_strcmp(sNHTTPStatusCodeLabel, label_p) == 0) {
        res_p->foundHeader_p = (char *)NHTTPi_alloc(4, 4);
        if (res_p->foundHeader_p == 0) {
            return -1;
        }
        res_p->foundHeader_p[3] = 0;
        size = 3;
        NHTTPi_loadFromHdrRecvBuf(res_p, res_p->foundHeader_p, 9, size);
        *value_pp = res_p->foundHeader_p;
        return size;
    }
    return -1;
}
