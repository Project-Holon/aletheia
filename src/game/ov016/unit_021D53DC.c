/*
 * file:     unit_021D53DC.c
 * unit:     yes
 * function: func_021D53DC, func_021D5410, func_021D5450, func_021D546C, func_021D54C4
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
 *   func_021D6414  0x021d6414  arm  ov016
 *   DWCi_HEAPlFree_                  0x021D6438  arm
 *   func_02084998  0x02084998  arm
 *   func_0207C994  0x0207c994  arm
 *   func_02088234  0x02088234  arm
 *   func_02084968  0x02084968  arm
 */
struct tagLISTCB;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct tagQCB {
    u16 size;
    u8 head;
    u8 tail;
    void *data[1];
} QCB;

extern void *func_021D6414(unsigned long size, int alignment);
extern void DWCi_HEAPlFree_(void **mem);
extern unsigned long func_02084998(unsigned long intr);
extern long func_0207C994(long a, long b);
extern void func_02088234(void);
extern unsigned long func_02084968(unsigned long intr);
void *func_021D53DC(long size);
void *func_021D5410(long size, void *data, long dataSize);
void DWCi_LSTlDelete(struct tagLISTCB *list);
void func_021D546C(void *queue, void *data);
void *func_021D54C4(void *queue);


void *func_021D53DC(long size)
{
    QCB *qcb;

    qcb = (QCB *)func_021D6414((size + 1) * 4 + 8, 4);
    qcb->size = size + 1;
    qcb->head = 0;
    qcb->tail = 0;
    return qcb;
}


/*
 * sdk:      DWCi_QUElFormEx (libdwcutil.TWL.HYB.a(deque.o))
 */
void *func_021D5410(long size, void *data, long dataSize)
{
    long i;
    u8 *adr = (u8 *)data;
    QCB *qcb;

    qcb = (QCB *)func_021D53DC(size);
    for (i = 0; i < size; i++) {
        qcb->data[i] = adr;
        adr += dataSize;
    }
    qcb->tail = size;
    return qcb;
}


void DWCi_LSTlDelete(struct tagLISTCB *list)
{
	DWCi_HEAPlFree_((void **)&list);
}


/*
 * sdk:      DWCi_QUElPushBack (libdwcutil.TWL.HYB.a(deque.o))
 */
void func_021D546C(void *queue, void *data)
{
    QCB *qcb = (QCB *)queue;
    unsigned long irq;
    long next;

    irq = func_02084998(1);
    next = func_0207C994(qcb->tail + 1, qcb->size);
    if (next == qcb->head)
        func_02088234();
    qcb->data[qcb->tail] = data;
    qcb->tail = next;
    func_02084968(irq);
}


/*
 * sdk:      DWCi_QUElPopBack (libdwcutil.TWL.HYB.a(deque.o))
 */
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
