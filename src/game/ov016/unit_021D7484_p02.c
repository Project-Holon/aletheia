/*
 * file:     unit_021D7484_p02.c
 * unit:     yes
 * function: func_021D75D0, func_021D7680, func_021D7694
 * address:  0x021D75D0
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
 *   func_021D54C4  0x021D54C4  arm  ov016
 *   func_021D7750  0x021D7750  arm  ov016
 *   g_021DE6E4  0x021DE6E4  data
 *   formTask                     0x021D7694  arm
 *   OS_DisableIrqMask  0x02084998  arm
 *   func_021D6DC4  0x021D6DC4  arm  ov016
 *   OS_EnableIrqMask  0x02084968  arm
 */
struct StructR4;
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

typedef unsigned int   u32;

extern void *func_021D54C4(void *queue);
extern void func_021D7750(u32 idx, struct StructR4 *r4);
extern void formTask(void);
extern unsigned long OS_DisableIrqMask(unsigned long intr);
extern void func_021D6DC4(void *pos, void *ob);
extern unsigned long OS_EnableIrqMask(unsigned long intr);
void func_021D75D0(int kind);
asm void DWCi_TSKlForm(void);
TCB *func_021D7694(int kind, void (*func)(void *, void *), void *work, unsigned char prio, unsigned char alloc);
extern TK *g_021DE6E4;


void func_021D75D0(int kind)
{
	TCB *t;
	int i;

	if (g_021DE6E4[kind].flag == 0)
		return;
	for (t = g_021DE6E4[kind].first; t != (TCB *)g_021DE6E4[kind].head; t = t->next)
		t->func(t, t->work);
	for (i = 0; i < g_021DE6E4[kind].count; i++) {
		t = (TCB *)func_021D54C4(g_021DE6E4[kind].delque);
		if (t == 0)
			return;
		func_021D7750(kind, (struct StructR4 *)t);
	}
}


asm void DWCi_TSKlForm(void)
{
	stmdb sp!, {r3, lr}
	mov ip, #0
	str ip, [sp]
	bl formTask
	ldmia sp!, {r3, pc}
}


/*
 * sdk:      formTask (libdwcutil.TWL.HYB.a(task.o))
 */
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
