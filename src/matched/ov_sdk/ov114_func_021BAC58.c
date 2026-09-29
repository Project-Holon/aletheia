/*
 * function: func_021BAC58
 * address:  0x021BAC58
 * packet:   pkt_ov114_021BAC58
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_AddRequestPostDataAscii (libnhttp.TWL.HYB.a(nhttp_control.o))
 *
 * symbols:
 *   func_021BA118 0x021BA118 arm ov114
 *   func_021BAB58 0x021BAB58 arm ov114
 *   func_021BAA1C 0x021BAA1C arm ov114
 */

typedef struct DataList {
    struct DataList *next;
    char pad[0xC];
    unsigned long length;
} DataList;

typedef struct {
    int f0;
    int f4;
    char pad[8];
    int f10;
    char pad2[0x20];
    DataList *list;
} Req;

extern unsigned long func_021BA118(char *s);
extern int func_021BAB58(Req *req_p, char *value_p, unsigned long length);
extern int func_021BAA1C(DataList **list_pp, void *bgnEndInfo_p, char *label_p, char *value_p);

int func_021BAC58(Req *req_p, void *bgnEndInfo_p, char *label_p, char *value_p)
{
    int rc = 0;
    unsigned long length = 0;

    if (req_p->f4 != 0) {
        return 0;
    }
    if (req_p->f10 != 0) {
        return 0;
    }
    if (value_p != 0) {
        length = func_021BA118(value_p);
    }
    if (func_021BAB58(req_p, value_p, length) != 0) {
        rc = func_021BAA1C(&req_p->list, bgnEndInfo_p, label_p, value_p);
        if (rc != 0) {
            req_p->list->next->length = length;
        }
    }
    return rc;
}
