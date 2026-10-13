/*
 * file:     task.c
 * unit:     yes
 * function: DWCi_TSKlInit, DWCi_TSKlEnd, DWCi_TSKlAct, DWCi_TSKlForm, formTask, DWCi_TSKlSetParam, DWCi_TSKlDelete, DWCi_TSKlDeleteByIndex, deleteTcb, DWCi_TSKlOperate
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
 * Store a word at +0x08 of the argument.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_TSKlSetParam.c \
 *       --func DWCi_TSKlSetParam --addr 0x021D771C --region ov016 --cc dsi/1.1p1 --arm
 * sdk:      DWCi_TSKlDelete (task.o), callee of DWCi_WINlEnd / taskWait (L5)
 * ARM tail-call thunk into deleteTcb.
 *   python tools/match.py one --src src/matched/DWCi_TSKlDeleteByIndex.c \
 *       --func DWCi_TSKlDeleteByIndex --addr 0x021D7744 --region ov016 --cc dsi/1.1p1 --arm
 * note: the parked header declared g_021E66E4 (0x021E66E4); the ov016 pool
 * word at 0x021D7790 is 0x021DE6E4, so the wildcarded ABS32 hid the wrong
 * address and kept this at MATCH.  Correcting the address makes it EXACT.
 *
 * symbols:
 *   DWCi_LSTlErase                 0x021D6D8C  arm  ov016
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_QUElFormEx  0x021D5410  arm  ov016
 *   DWCi_QUElForm  0x021D53DC  arm  ov016
 *   DWCi_LSTlForm  0x021D6D44  arm  ov016
 *   DWCi_LSTlPushFront  0x021D6E04  arm  ov016
 *   DWCi_LSTlPushBack  0x021D6DF4  arm  ov016
 *   sTaskTable  0x021DAA84  data
 *   DWCi_LSTlDelete  0x021D6D70  arm  ov016
 *   DWCi_QUElDelete  0x021D5450  arm  ov016
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
 *   DWCi_QUElPopBack  0x021D54C4  arm  ov016
 *   formTask                     0x021D7694  arm
 *   OS_DisableIrqMask  0x02084998  arm
 *   DWCi_LSTlInsert  0x021D6DC4  arm  ov016
 *   OS_EnableIrqMask  0x02084968  arm
 *   MemTask            0x021DE6E4 data
 *   DWCi_QUElPushBack  0x021D546C arm
 */
struct ListCB;
struct TCB;
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

/* Task object of the DWC GUI task list (task.o); only the parameter word is written here. */
typedef struct TaskObj {
    unsigned char pad00[0x08];
    unsigned int param;
} TaskObj;

typedef unsigned char u8;

typedef unsigned short u16;

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void *DWCi_QUElFormEx(long size, void *data, long dataSize);
extern void *DWCi_QUElForm(long size);
extern struct ListCB *DWCi_LSTlForm(void);
extern void DWCi_LSTlPushFront(char *p, void *ob);
extern void DWCi_LSTlPushBack(char *p, void *ob);
extern void DWCi_LSTlDelete(void *list);
extern void DWCi_QUElDelete(void *queue);
extern void DWCi_HEAPlFree_(void **mem);
extern void *DWCi_QUElPopBack(void *queue);
extern unsigned long OS_DisableIrqMask(unsigned long intr);
extern void DWCi_LSTlInsert(void *pos, void *ob);
extern unsigned long OS_EnableIrqMask(unsigned long intr);
void DWCi_QUElPushBack(void *queue, void *data);
extern void DWCi_LSTlErase(void *);
void DWCi_TSKlInit(void);
void DWCi_TSKlEnd(void);
void DWCi_TSKlAct(int kind);
TCB *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
void DWCi_TSKlSetParam(TaskObj *task, unsigned int param);
void DWCi_TSKlDelete(int kind, void *task);
void DWCi_TSKlDeleteByIndex(unsigned int taskIdx, TCB *task);
extern MemTaskT *MemTask;
extern unsigned char sTaskTable[2];

static TCB *formTask(int kind, void (*func)(void *, void *), void *work, unsigned char prio, unsigned char alloc);
static void deleteTcb(u32 idx, TCB *tcb);


void DWCi_TSKlInit(void)
{
    int i;

    MemTask = DWCi_HEAPlAllocEx(0x80, 4);
    for (i = 0; i < 2; i++) {
        int num = sTaskTable[i];
        MemTask[i].num = num;
        MemTask[i].mem = DWCi_HEAPlAllocEx(num * 0x14, 4);
        MemTask[i].que = DWCi_QUElFormEx(num, MemTask[i].mem, 0x14);
        MemTask[i].delque = DWCi_QUElForm(num);
        MemTask[i].list = DWCi_LSTlForm();
        MemTask[i].b1c = 0;
        MemTask[i].b30 = 0xff;
        DWCi_LSTlPushFront(MemTask[i].list, &MemTask[i].node0);
        DWCi_LSTlPushBack(MemTask[i].list, &MemTask[i].node1);
        MemTask[i].flag = 1;
    }
}


/*
 * sdk:      DWCi_TSKlEnd (libdwcutil.TWL.HYB.a(task.o))
 */
void DWCi_TSKlEnd(void)
{
	int i;

	for (i = 0; i < 2; i++) {
		DWCi_LSTlDelete(MemTask[i].list);
		DWCi_QUElDelete(MemTask[i].que);
	}
	DWCi_HEAPlFree_((void **)0x021DE6E4);
}


void DWCi_TSKlAct(int kind)
{
	TCB *t;
	int i;

	if (MemTask[kind].flag == 0)
		return;
	for (t = MemTask[kind].node0.first; t != (TCB *)&MemTask[kind].node1; t = t->next)
		t->func(t, t->work);
	for (i = 0; i < MemTask[kind].num; i++) {
		t = (TCB *)DWCi_QUElPopBack(MemTask[kind].delque);
		if (t == 0)
			return;
		deleteTcb(kind, t);
	}
}


TCB *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio)
{
    return formTask(kind, func, work, prio, 0);
}


/*
 * sdk:      formTask (libdwcutil.TWL.HYB.a(task.o))
 */
static TCB *formTask(int kind, void (*func)(void *, void *), void *work, unsigned char prio, unsigned char alloc)
{
	TCB *tcb;
	TCB *t;
	unsigned long irq;

	tcb = (TCB *)DWCi_QUElPopBack(MemTask[kind].que);
	tcb->func = func;
	tcb->work = work;
	tcb->prio = prio;
	tcb->alloc = alloc;
	irq = OS_DisableIrqMask(1);
	for (t = MemTask[kind].node0.first;; t = t->next) {
		if (prio < t->prio) {
			DWCi_LSTlInsert(t, tcb);
			break;
		}
	}
	OS_EnableIrqMask(irq);
	return tcb;
}


void DWCi_TSKlSetParam(TaskObj *task, unsigned int param)
{
    task->param = param;
}


void DWCi_TSKlDelete(int kind, void *task)
{
    DWCi_QUElPushBack(MemTask[kind].delque, task);
}


void DWCi_TSKlDeleteByIndex(unsigned int taskIdx, TCB *task)
{
    deleteTcb(taskIdx, task);
}


static void deleteTcb(u32 idx, TCB *tcb)
{
    if (tcb->alloc != 0) {
        DWCi_HEAPlFree_(&tcb->work);
    }
    DWCi_LSTlErase(tcb);
    DWCi_QUElPushBack(MemTask[idx].que, tcb);
}


void DWCi_TSKlOperate(int kind, unsigned char flag)
{
    MemTask[kind].flag = flag;
}
