/*
 * function: func_021D7694
 * address:  0x021D7694
 * packet:   pkt_ov016_021D7694
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      formTask (libdwcutil.TWL.HYB.a(task.o))
 *
 * symbols:
 *   DWCi_QUElPopBack  0x021D54C4  arm  ov016
 *   OS_DisableIrqMask  0x02084998  arm
 *   DWCi_LSTlInsert  0x021D6DC4  arm  ov016
 *   OS_EnableIrqMask  0x02084968  arm
 *   gMemTask  0x021DE6E4  data
 */

typedef struct TCB {
	struct TCB *prev;
	struct TCB *next;
	void (*func)(void *, void *);
	void *work;
	unsigned char prio;
	unsigned char alloc;
} TCB;

typedef struct {
	void *que;
	void *delque;
	void *list;
	int pad0;
	TCB *first;
	int pad1[3];
	char head[0x14];
	int count;
	unsigned char flag;
	char pad2[7];
} TK;

extern void *DWCi_QUElPopBack(void *queue);
extern unsigned long OS_DisableIrqMask(unsigned long intr);
extern void DWCi_LSTlInsert(void *pos, void *ob);
extern unsigned long OS_EnableIrqMask(unsigned long intr);
extern TK *gMemTask;

TCB *func_021D7694(int kind, void (*func)(void *, void *), void *work, unsigned char prio, unsigned char alloc)
{
	TCB *tcb;
	TCB *t;
	unsigned long irq;

	tcb = (TCB *)DWCi_QUElPopBack(gMemTask[kind].que);
	tcb->func = func;
	tcb->work = work;
	tcb->prio = prio;
	tcb->alloc = alloc;
	irq = OS_DisableIrqMask(1);
	for (t = gMemTask[kind].first;; t = t->next) {
		if (prio < t->prio) {
			DWCi_LSTlInsert(t, tcb);
			break;
		}
	}
	OS_EnableIrqMask(irq);
	return tcb;
}
