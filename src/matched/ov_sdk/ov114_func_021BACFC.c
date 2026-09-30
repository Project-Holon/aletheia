/*
 * function: NHTTPi_setReqQueue
 * address:  0x021BACFC
 * packet:   pkt_ov114_021BACFC
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NHTTPi_setReqQueue (libnhttp.TWL.HYB.a nhttp_list.o)
 *
 * symbols:
 *   NHTTPi_alloc  0x021ba820 arm
 *
 * The object loads idRequest twice: once into r4 for the returned `id`, then a
 * fresh r2 for the increment, and only then stores list_p->field_0x08 = id. Any
 * spelling that stores field_0x08 before the increment (the natural order)
 * schedules the store above the reload; any spelling that hoists the increment
 * above the store lets -O4 CSE the two reads into one. Declaring the list
 * counter `volatile` is what keeps both the reload and the object's order:
 * `id = listInfo_p->idRequest; listInfo_p->idRequest++; list_p->id = id; ...`
 * is byte-exact (see docs/idioms/a-re-read-of-a-field-just-stored-is-one-
 * volatile-read-not-a-volatile-field.md).
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
    volatile int field_0x04;
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
        listInfo_p->field_0x04++;
        list_p->field_0x08 = id;
        list_p->field_0x0c = req_p;
        list_p->field_0x10 = -1;
        if (listInfo_p->field_0x04 < 0)
            listInfo_p->field_0x04 = 0;
    }
    return id;
}
