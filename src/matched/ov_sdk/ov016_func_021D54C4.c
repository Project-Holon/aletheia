/*
 * function: func_021D54C4
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
 *   func_02084998  0x02084998  arm
 *   func_0207C994  0x0207c994  arm
 *   func_02084968  0x02084968  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct tagQCB {
    u16 size;
    u8 head;
    u8 tail;
    void *data[1];
} QCB;

extern unsigned long func_02084998(unsigned long intr);
extern long func_0207C994(long a, long b);
extern unsigned long func_02084968(unsigned long intr);

void *func_021D54C4(void *queue)
{
    QCB *qcb;
    void *data;
    unsigned long irq;

    qcb = (QCB *)queue;
    data = 0;
    irq = func_02084998(1);
    if (qcb->head != qcb->tail) {
        qcb->tail = func_0207C994(qcb->tail + qcb->size - 1, qcb->size);
        data = qcb->data[qcb->tail];
    }
    func_02084968(irq);
    return data;
}
