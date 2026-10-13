/*
 * function: NHTTPi_AddRequestPostDataAscii
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
 *   NHTTPi_strlen 0x021BA118 arm ov114
 *   checkTagPost 0x021BAB58 arm ov114
 *   addHdrList 0x021BAA1C arm ov114
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

extern unsigned long NHTTPi_strlen(char *s);
extern int checkTagPost(Req *req_p, char *value_p, unsigned long length);
struct Node;
extern int addHdrList(struct Node **head, int b, int c, int d);

int NHTTPi_AddRequestPostDataAscii(Req *req_p, void *bgnEndInfo_p, char *label_p, char *value_p)
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
        length = NHTTPi_strlen(value_p);
    }
    if (checkTagPost(req_p, value_p, length) != 0) {
        rc = addHdrList((struct Node **)(&req_p->list), (int)bgnEndInfo_p, (int)label_p, (int)value_p);
        if (rc != 0) {
            req_p->list->next->length = length;
        }
    }
    return rc;
}
