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
 *   func_021D54C4  0x021D54C4  arm  ov016
 *   OS_DisableIrqMask  0x02084998  arm
 *   func_021D6DC4  0x021D6DC4  arm  ov016
 *   OS_EnableIrqMask  0x02084968  arm
 *   g_021DE6E4  0x021DE6E4  data
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

extern void *func_021D54C4(void *queue);
extern unsigned long OS_DisableIrqMask(unsigned long intr);
extern void func_021D6DC4(void *pos, void *ob);
extern unsigned long OS_EnableIrqMask(unsigned long intr);
extern TK *g_021DE6E4;

TCB *func_021D7694(int kind, void (*func)(void *, void *), void *work, unsigned char prio, unsigned char alloc)
{
	TCB *tcb;
	TCB *t;
	unsigned long irq;

	tcb = (TCB *)func_021D54C4(g_021DE6E4[kind].que);
	tcb->func = func;
	tcb->work = work;
	tcb->prio = prio;
	tcb->alloc = alloc;
	irq = OS_DisableIrqMask(1);
	for (t = g_021DE6E4[kind].first;; t = t->next) {
		if (prio < t->prio) {
			func_021D6DC4(t, tcb);
			break;
		}
	}
	OS_EnableIrqMask(irq);
	return tcb;
}
