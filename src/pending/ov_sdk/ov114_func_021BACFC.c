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
 *
 * w8_nm:    storing list_p->field_0x08 before the increment puts listInfo_p,
 *           req_p and id in r6, r5, r4 as in the object (46 B -> 17 B). Left:
 *           the object reloads idRequest into r2 and stores list_p->id after
 *           the increment. Explicit reload spellings (`= x + 1`, `+= 1`,
 *           `++`, `x++` in the assignment, chained assignment) and moving the
 *           req/-1 stores around did not reproduce it (17 to 46 B).
 *
 * w9_nm2:   unchanged, 17 B. The object's order is ldr id; ldr r2 (reload);
 *           mvn; add; str; then str id into list_p->field_0x08. Any form that
 *           stores field_0x08 after the increment (id load, ++ / += 1 / = x + 1 /
 *           1 + x / post-increment, then the store; req and -1 stores hoisted
 *           or sunk) moves id to r6 and req_p to r4 (36 to 48 B).
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
        list_p->field_0x08 = id;
        listInfo_p->field_0x04++;
        list_p->field_0x0c = req_p;
        list_p->field_0x10 = -1;
        if (listInfo_p->field_0x04 < 0)
            listInfo_p->field_0x04 = 0;
    }
    return id;
}
