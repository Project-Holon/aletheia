/*
 * function: deleteStrList
 * address:  0x021BB8F0
 * packet:   pkt_ov114_021BB8F0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      deleteStrList (libnhttp.TWL.HYB.a(nhttp_request.o))
 *
 * symbols:
 *   NHTTPi_free 0x021BA850 arm ov114
 */

typedef struct List {
    struct List *next;
} List;

extern void NHTTPi_free(int a);

void deleteStrList(List *list_p)
{
    List *p;

    if (list_p) {
        do {
            p = list_p->next;
            if (list_p != p) {
                List *n = p->next;
                NHTTPi_free((int)p);
                list_p->next = n;
            } else {
                NHTTPi_free((int)list_p);
                list_p = 0;
            }
        } while (list_p);
    }
}
