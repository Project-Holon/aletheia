/*
 * function: func_021D5410
 * address:  0x021D5410
 * packet:   pkt_ov016_021D5410
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_QUElFormEx (libdwcutil.TWL.HYB.a(deque.o))
 *
 * symbols:
 *   func_021D53DC  0x021d53dc  arm  ov016
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct tagQCB {
    u16 size;
    u8 head;
    u8 tail;
    void *data[1];
} QCB;

extern void *func_021D53DC(long size);

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
