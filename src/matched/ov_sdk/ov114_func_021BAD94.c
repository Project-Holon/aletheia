/*
 * function: NHTTPi_findReqQueue
 * address:  0x021BAD94
 * packet:   pkt_ov114_021BAD94
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_findReqQueue (libnhttp.TWL.HYB.a nhttp_list.o)
 *
 * notes:    the head gets its own local (declared between listRet_p and
 *           list_p), which puts it in r3 and the cursor in ip as in the
 *           object.  The DWARF lists only listRet_p and list_p; every
 *           two-local form tried (w4_nm, w7_nm: head reread through
 *           listInfo_p, peeled or plain loops) keeps the pair swapped.
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
    struct _NHTTPi_REQLIST *head_p = listInfo_p->field_0x00;
    struct _NHTTPi_REQLIST *list_p;

    if (head_p != 0) {
        if (head_p->field_0x08 == id)
            listRet_p = head_p;
        else {
            list_p = head_p->field_0x04;
            if (list_p != head_p) {
                do {
                    if (list_p->field_0x08 == id) {
                        listRet_p = list_p;
                        break;
                    }
                    list_p = list_p->field_0x04;
                } while (list_p != head_p);
            }
        }
    }
    return listRet_p;
}
