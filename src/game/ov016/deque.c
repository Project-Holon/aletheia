/*
 * file:     deque.c
 * unit:     yes
 * function: DWCi_QUElForm, DWCi_QUElFormEx, DWCi_QUElDelete, DWCi_QUElPushBack, DWCi_QUElPopBack
 * address:  0x021D53DC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021d6414  arm  ov016
 *   DWCi_HEAPlFree_                  0x021D6438  arm
 *   OS_DisableIrqMask  0x02084998  arm
 *   FX_ModS32  0x0207c994  arm
 *   OS_Terminate  0x02088234  arm
 *   OS_EnableIrqMask  0x02084968  arm
 */
struct tagLISTCB;
#include "../types.h"

typedef struct tagQCB {
    u16 size;
    u8 head;
    u8 tail;
    void *data[1];
} QCB;

#include "heap.h"
typedef unsigned int OSIrqMask;
#include "../arm9/os_interrupt.h"
#include "../arm9/fx_cp.h"
#include "../arm9/os_terminate_processor.h"
void *DWCi_QUElForm(long size);
void *DWCi_QUElFormEx(long size, void *data, long dataSize);
void DWCi_QUElDelete(struct tagLISTCB *list);
void DWCi_QUElPushBack(void *queue, void *data);
void *DWCi_QUElPopBack(void *queue);

void *DWCi_QUElForm(long size)
{
    QCB *qcb;

    qcb = (QCB *)DWCi_HEAPlAllocEx((size + 1) * 4 + 8, 4);
    qcb->size = size + 1;
    qcb->head = 0;
    qcb->tail = 0;
    return qcb;
}

/*
 * sdk:      DWCi_QUElFormEx (libdwcutil.TWL.HYB.a(deque.o))
 */
void *DWCi_QUElFormEx(long size, void *data, long dataSize)
{
    long i;
    u8 *adr = (u8 *)data;
    QCB *qcb;

    qcb = (QCB *)DWCi_QUElForm(size);
    for (i = 0; i < size; i++) {
        qcb->data[i] = adr;
        adr += dataSize;
    }
    qcb->tail = size;
    return qcb;
}

void DWCi_QUElDelete(struct tagLISTCB *list)
{
	DWCi_HEAPlFree_((void **)&list);
}

/*
 * sdk:      DWCi_QUElPushBack (libdwcutil.TWL.HYB.a(deque.o))
 */
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

/*
 * sdk:      DWCi_QUElPopBack (libdwcutil.TWL.HYB.a(deque.o))
 */
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
