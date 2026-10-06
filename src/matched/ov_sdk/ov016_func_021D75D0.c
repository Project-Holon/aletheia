/*
 * function: func_021D75D0
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
 *   func_021D54C4  0x021D54C4  arm  ov016
 *   func_021D7750  0x021D7750  arm  ov016
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
typedef unsigned int   u32;
struct StructR4;
extern void func_021D7750(u32 idx, struct StructR4 *r4);
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
