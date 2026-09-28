/*
 * function: NHTTPi_setReqQueue
 * address:  0x021BACFC
 * packet:   pkt_ov114_021BACFC
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      NHTTPi_setReqQueue (libnhttp.TWL.HYB.a nhttp_list.o)
 *
 * symbols:
 *   NHTTPi_alloc  0x021ba820 arm
 *
 * blocker:  register allocation -- identical body, but the running counter
 *           `id` lands in r6 while the original keeps it in r4 (the first
 *           callee-saved register) across the NHTTPi_alloc call; 148/152
 *           bytes, 46 concrete bytes differ.
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct _NHTTPi_REQLIST {
    struct _NHTTPi_REQLIST *field_0x00;
    struct _NHTTPi_REQLIST *field_0x04;
    int field_0x08;
    void *field_0x0c;
    int field_0x10;
};

struct _NHTTPListInfo {
    struct _NHTTPi_REQLIST *field_0x00;
    int field_0x04;
};

struct _NHTTPReq;

extern void *NHTTPi_alloc(unsigned long size, int align);

int NHTTPi_setReqQueue(struct _NHTTPListInfo *listInfo_p, struct _NHTTPReq *req_p)
{
    struct _NHTTPi_REQLIST *list_p;
    int id;

    id = -1;
    list_p = NHTTPi_alloc(0x14, 4);
    if (list_p != 0) {
        if (listInfo_p->field_0x00 == 0) {
            list_p->field_0x00 = list_p;
            list_p->field_0x04 = list_p;
            listInfo_p->field_0x00 = list_p;
        } else {
            list_p->field_0x00 = listInfo_p->field_0x00->field_0x00;
            list_p->field_0x04 = listInfo_p->field_0x00;
            listInfo_p->field_0x00->field_0x00->field_0x04 = list_p;
            listInfo_p->field_0x00->field_0x00 = list_p;
        }
        id = listInfo_p->field_0x04;
        listInfo_p->field_0x04 = id + 1;
        list_p->field_0x08 = id;
        list_p->field_0x0c = req_p;
        list_p->field_0x10 = -1;
        if (listInfo_p->field_0x04 < 0)
            listInfo_p->field_0x04 = 0;
    }
    return id;
}
