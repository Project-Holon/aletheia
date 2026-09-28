/*
 * function: NHTTPi_findReqQueue
 * address:  0x021BAD94
 * packet:   pkt_ov114_021BAD94
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      NHTTPi_findReqQueue (libnhttp.TWL.HYB.a nhttp_list.o)
 *
 * blocker:  codegen only -- identical instruction sequence, but the
 *           compiler keeps the circular-list head/sentinel in ip and the
 *           cursor in r3, while the original keeps the head in r3 and the
 *           cursor in ip; 14 concrete bytes, no C arrangement found to flip
 *           the pair (leaf, 76/76 bytes).
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct _NHTTPi_REQLIST {
    struct _NHTTPi_REQLIST *field_0x00;
    struct _NHTTPi_REQLIST *field_0x04;
    int field_0x08;
};

struct _NHTTPListInfo {
    struct _NHTTPi_REQLIST *field_0x00;
    int field_0x04;
};

struct _NHTTPi_REQLIST *NHTTPi_findReqQueue(struct _NHTTPListInfo *listInfo_p, int id)
{
    struct _NHTTPi_REQLIST *listRet_p = 0;
    struct _NHTTPi_REQLIST *list_p = listInfo_p->field_0x00;

    if (list_p != 0) {
        if (list_p->field_0x08 == id)
            listRet_p = list_p;
        else {
            list_p = list_p->field_0x04;
            if (list_p != listInfo_p->field_0x00) {
                do {
                    if (list_p->field_0x08 == id) {
                        listRet_p = list_p;
                        break;
                    }
                    list_p = list_p->field_0x04;
                } while (list_p != listInfo_p->field_0x00);
            }
        }
    }
    return listRet_p;
}
