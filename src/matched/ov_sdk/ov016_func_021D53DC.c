/*
 * function: func_021D53DC
 * address:  0x021D53DC
 * packet:   pkt_ov016_021D53DC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_QUElForm (libdwcutil.TWL.HYB.a(deque.o))
 *
 * symbols:
 *   func_021D6414  0x021d6414  arm  ov016
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct tagQCB {
    u16 size;
    u8 head;
    u8 tail;
    void *data[1];
} QCB;

extern void *func_021D6414(unsigned long size, int alignment);

void *func_021D53DC(long size)
{
    QCB *qcb;

    qcb = (QCB *)func_021D6414((size + 1) * 4 + 8, 4);
    qcb->size = size + 1;
    qcb->head = 0;
    qcb->tail = 0;
    return qcb;
}
