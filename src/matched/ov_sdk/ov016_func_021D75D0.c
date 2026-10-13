/*
 * function: DWCi_TSKlAct
 * address:  0x021D75D0
 * packet:   pkt_ov016_021D75D0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_TSKlAct (libdwcutil.TWL.HYB.a(task.o))
 *
 * symbols:
 *   DWCi_QUElPopBack  0x021D54C4  arm  ov016
 *   func_021D7750  0x021D7750  arm  ov016
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
typedef unsigned int   u32;
struct StructR4;
extern void func_021D7750(u32 idx, struct StructR4 *r4);
extern TK *gMemTask;

void DWCi_TSKlAct(int kind)
{
	TCB *t;
	int i;

	if (gMemTask[kind].flag == 0)
		return;
	for (t = gMemTask[kind].first; t != (TCB *)gMemTask[kind].head; t = t->next)
		t->func(t, t->work);
	for (i = 0; i < gMemTask[kind].count; i++) {
		t = (TCB *)DWCi_QUElPopBack(gMemTask[kind].delque);
		if (t == 0)
			return;
		func_021D7750(kind, (struct StructR4 *)t);
	}
}
