/*
 * file:     unit_021BACEC_p01.c
 * unit:     yes
 * function: func_021BACEC, func_021BACFC
 * address:  0x021BACEC
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
 *   NHTTPi_alloc  0x021ba820 arm
 */
struct _NHTTPReq;
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

extern void *NHTTPi_alloc(unsigned long size, int align);
void func_021BACEC(u8 *p);
int NHTTPi_setReqQueue(struct _NHTTPListInfo *listInfo_p, struct _NHTTPReq *req_p);

/*
 * Clears the two leading words.
 */
void func_021BACEC(u8 *p)
{
    *(u32 *)(p + 0) = 0;
    *(u32 *)(p + 4) = 0;
}


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
