/*
 * function: DWCi_QUElPopBack
 * address:  0x021D54C4
 * packet:   pkt_ov016_021D54C4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_QUElPopBack (libdwcutil.TWL.HYB.a(deque.o))
 *
 * symbols:
 *   OS_DisableIrqMask  0x02084998  arm
 *   FX_ModS32  0x0207c994  arm
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
extern unsigned long OS_EnableIrqMask(unsigned long intr);

void *DWCi_QUElPopBack(void *queue)
{
    QCB *qcb;
    void *data;
    unsigned long irq;

    qcb = (QCB *)queue;
    data = 0;
    irq = OS_DisableIrqMask(1);
    if (qcb->head != qcb->tail) {
        qcb->tail = FX_ModS32(qcb->tail + qcb->size - 1, qcb->size);
        data = qcb->data[qcb->tail];
    }
    OS_EnableIrqMask(irq);
    return data;
}
