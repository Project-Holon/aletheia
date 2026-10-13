/*
 * function: DWCi_QUElPushBack
 * address:  0x021D546C
 * packet:   pkt_ov016_021D546C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_QUElPushBack (libdwcutil.TWL.HYB.a(deque.o))
 *
 * symbols:
 *   OS_DisableIrqMask  0x02084998  arm
 *   FX_ModS32  0x0207c994  arm
 *   OS_Terminate  0x02088234  arm
 *   OS_EnableIrqMask  0x02084968  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct tagQCB {
    u16 size;
    u8 head;
    u8 tail;
    void *data[1];
} QCB;

extern unsigned long OS_DisableIrqMask(unsigned long intr);
extern long FX_ModS32(long a, long b);
extern void OS_Terminate(void);
extern unsigned long OS_EnableIrqMask(unsigned long intr);

void DWCi_QUElPushBack(void *queue, void *data)
{
    QCB *qcb = (QCB *)queue;
    unsigned long irq;
    long next;

    irq = OS_DisableIrqMask(1);
    next = FX_ModS32(qcb->tail + 1, qcb->size);
    if (next == qcb->head)
        OS_Terminate();
    qcb->data[qcb->tail] = data;
    qcb->tail = next;
    OS_EnableIrqMask(irq);
}
