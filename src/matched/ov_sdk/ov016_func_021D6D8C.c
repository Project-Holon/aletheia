/*
 * function: func_021D6D8C
 * address:  0x021D6D8C
 * packet:   pkt_ov016_021D6D8C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_LSTlErase (libdwcutil.TWL.HYB.a list.o)
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

void func_021D6D8C(void *ob)
{
    ListNode *ln = ob;
    unsigned long irq = OS_DisableIrqMask(1);
    ln->next->prev = ln->prev;
    ln->prev->next = ln->next;
    ln->prev = 0;
    ln->next = 0;
    OS_EnableIrqMask(irq);
}
