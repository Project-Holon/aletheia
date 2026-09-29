/*
 * function: func_021BBCF0
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
 *   func_021BA850 0x021BA850 arm ov114
 *   func_021BBBC8 0x021BBBC8 arm ov114
 *   func_021BA820 0x021BA820 arm ov114
 *   func_021BB210 0x021BB210 arm ov114
 *   func_021BA130 0x021BA130 arm ov114
 *   g_021CE414 0x021CE414 data
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

extern char g_021CE414[];

extern void func_021BA850(void *p);
extern int func_021BBBC8(Res *res_p, char *label_p, int *pos_p);
extern char *func_021BA820(int size, int a);
extern void func_021BB210(Res *res_p, char *buf, int pos, int size);
extern int func_021BA130(char *a, char *b);

int func_021BBCF0(Res *res_p, char *label_p, char **value_pp)
{
    int pos;
    int size;

    if (res_p->isHeaderParse == 0) {
        return -1;
    }
    if (res_p->foundHeader_p) {
        func_021BA850(res_p->foundHeader_p);
        res_p->foundHeader_p = 0;
    }
    size = func_021BBBC8(res_p, label_p, &pos);
    if (size >= 0) {
        res_p->foundHeader_p = func_021BA820(size + 1, 4);
        if (res_p->foundHeader_p == 0) {
            return -1;
        }
        res_p->foundHeader_p[size] = 0;
        func_021BB210(res_p, res_p->foundHeader_p, pos, size);
        *value_pp = res_p->foundHeader_p;
        return size;
    }
    if (func_021BA130(g_021CE414, label_p) == 0) {
        res_p->foundHeader_p = func_021BA820(4, 4);
        if (res_p->foundHeader_p == 0) {
            return -1;
        }
        res_p->foundHeader_p[3] = 0;
        size = 3;
        func_021BB210(res_p, res_p->foundHeader_p, 9, size);
        *value_pp = res_p->foundHeader_p;
        return size;
    }
    return -1;
}
