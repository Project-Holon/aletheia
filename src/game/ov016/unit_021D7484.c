/*
 * file:     unit_021D7484.c
 * unit:     yes
 * function: func_021D7484, func_021D7588, func_021D75D0, func_021D7680, func_021D7694
 * address:  0x021D7484
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
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_021D5410  0x021D5410  arm  ov016
 *   func_021D53DC  0x021D53DC  arm  ov016
 *   func_021D6D44  0x021D6D44  arm  ov016
 *   func_021D6E04  0x021D6E04  arm  ov016
 *   func_021D6DF4  0x021D6DF4  arm  ov016
 *   g_021DE6E4  0x021DE6E4  data
 *   g_021DAA84  0x021DAA84  data
 *   func_021D6D70  0x021D6D70  arm  ov016
 *   func_021D5450  0x021D5450  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
 *   func_021D54C4  0x021D54C4  arm  ov016
 *   func_021D7750  0x021D7750  arm  ov016
 *   formTask                     0x021D7694  arm
 *   OS_DisableIrqMask  0x02084998  arm
 *   func_021D6DC4  0x021D6DC4  arm  ov016
 *   OS_EnableIrqMask  0x02084968  arm
 */
struct ListCB;
struct TCB;
struct StructR4;
typedef struct TaskNode {
    int f0;
    struct TCB *first;          /* +0x04 */
    int f8;
    int fc;
} TaskNode;

typedef struct {
    void *que;                  /* +0x00 */
    void *delque;               /* +0x04 */
    void *list;                 /* +0x08 */
    TaskNode node0;             /* +0x0c */
    unsigned char b1c;
    unsigned char pad1d[3];
    TaskNode node1;             /* +0x20 */
    unsigned char b30;
    unsigned char pad31[3];
    int num;                    /* +0x34 */
    unsigned char flag;         /* +0x38 */
    unsigned char pad39[3];
    void *mem;                  /* +0x3c */
} MemTaskT;

typedef struct TCB {
	struct TCB *prev;
	struct TCB *next;
	void (*func)(void *, void *);
	void *work;
	unsigned char prio;
	unsigned char alloc;
} TCB;

typedef unsigned int   u32;

extern void *func_021D6414(unsigned long size, int alignment);
extern void *func_021D5410(long size, void *data, long dataSize);
extern void *func_021D53DC(long size);
extern struct ListCB *func_021D6D44(void);
extern void func_021D6E04(char *p, void *ob);
extern void func_021D6DF4(char *p, void *ob);
extern void func_021D6D70(void *list);
extern void func_021D5450(void *queue);
extern void func_021D6438(void **mem);
extern void *func_021D54C4(void *queue);
extern void func_021D7750(u32 idx, struct StructR4 *r4);
extern TCB *formTask(int kind, void (*func)(void *, void *), void *work, unsigned char prio, unsigned char alloc);
extern unsigned long OS_DisableIrqMask(unsigned long intr);
extern void func_021D6DC4(void *pos, void *ob);
extern unsigned long OS_EnableIrqMask(unsigned long intr);
void func_021D7484(void);
void func_021D7588(void);
void func_021D75D0(int kind);
TCB *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
TCB *func_021D7694(int kind, void (*func)(void *, void *), void *work, unsigned char prio, unsigned char alloc);
extern MemTaskT *g_021DE6E4;
extern unsigned char g_021DAA84[2];



void func_021D7484(void)
{
    int i;

    g_021DE6E4 = func_021D6414(0x80, 4);
    for (i = 0; i < 2; i++) {
        int num = g_021DAA84[i];
        g_021DE6E4[i].num = num;
        g_021DE6E4[i].mem = func_021D6414(num * 0x14, 4);
        g_021DE6E4[i].que = func_021D5410(num, g_021DE6E4[i].mem, 0x14);
        g_021DE6E4[i].delque = func_021D53DC(num);
        g_021DE6E4[i].list = func_021D6D44();
        g_021DE6E4[i].b1c = 0;
        g_021DE6E4[i].b30 = 0xff;
        func_021D6E04(g_021DE6E4[i].list, &g_021DE6E4[i].node0);
        func_021D6DF4(g_021DE6E4[i].list, &g_021DE6E4[i].node1);
        g_021DE6E4[i].flag = 1;
    }
}



/*
 * sdk:      DWCi_TSKlEnd (libdwcutil.TWL.HYB.a(task.o))
 */
void func_021D7588(void)
{
	int i;

	for (i = 0; i < 2; i++) {
		func_021D6D70(g_021DE6E4[i].list);
		func_021D5450(g_021DE6E4[i].que);
	}
	func_021D6438((void **)0x021DE6E4);
}



void func_021D75D0(int kind)
{
	TCB *t;
	int i;

	if (g_021DE6E4[kind].flag == 0)
		return;
	for (t = g_021DE6E4[kind].node0.first; t != (TCB *)&g_021DE6E4[kind].node1; t = t->next)
		t->func(t, t->work);
	for (i = 0; i < g_021DE6E4[kind].num; i++) {
		t = (TCB *)func_021D54C4(g_021DE6E4[kind].delque);
		if (t == 0)
			return;
		func_021D7750(kind, (struct StructR4 *)t);
	}
}



TCB *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio)
{
    return formTask(kind, func, work, prio, 0);
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
	for (t = g_021DE6E4[kind].node0.first;; t = t->next) {
		if (prio < t->prio) {
			func_021D6DC4(t, tcb);
			break;
		}
	}
	OS_EnableIrqMask(irq);
	return tcb;
}
