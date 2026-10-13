/*
 * function: DWCi_LSTlForm
 * address:  0x021D6D44
 * packet:   pkt_ov016_021D6D44
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_LSTlForm (libdwcutil.TWL.HYB.a list.o)
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 */

typedef struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
} ListNode;

typedef struct ListCB {
    void *f0;
    void *f4;
    void *f8;
    void *fc;
} ListCB;

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);

ListCB *DWCi_LSTlForm(void)
{
    ListCB *list = DWCi_HEAPlAllocEx(0x10, 4);
    list->f0 = 0;
    list->f4 = &list->f8;
    list->f8 = list;
    list->fc = 0;
    return list;
}
