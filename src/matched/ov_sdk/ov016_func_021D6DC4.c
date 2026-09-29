/*
 * function: func_021D6DC4
 * address:  0x021D6DC4
 * packet:   pkt_ov016_021D6DC4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_LSTlInsert (libdwcutil.TWL.HYB.a list.o)
 *
 * symbols:
 *   OS_DisableIrqMask 0x02084998  arm
 *   OS_EnableIrqMask 0x02084968  arm
 */

typedef struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
} ListNode;

extern unsigned long OS_DisableIrqMask(unsigned long intr);
extern unsigned long OS_EnableIrqMask(unsigned long intr);

void func_021D6DC4(void *pos, void *ob)
{
    ListNode *tgt = pos;
    ListNode *ln = ob;
    unsigned long irq = OS_DisableIrqMask(1);
    tgt->next->prev = ln;
    ln->next = tgt->next;
    ln->prev = tgt;
    tgt->next = ln;
    OS_EnableIrqMask(irq);
}
