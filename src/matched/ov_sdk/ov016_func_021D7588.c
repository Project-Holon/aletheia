/*
 * function: DWCi_TSKlEnd
 * address:  0x021D7588
 * packet:   pkt_ov016_021D7588
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_TSKlEnd (libdwcutil.TWL.HYB.a(task.o))
 *
 * symbols:
 *   DWCi_LSTlDelete  0x021D6D70  arm  ov016
 *   DWCi_QUElDelete  0x021D5450  arm  ov016
 *   DWCi_HEAPlFree_  0x021D6438  arm  ov016
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

extern void DWCi_LSTlDelete(void *list);
extern void DWCi_QUElDelete(void *queue);
extern void DWCi_HEAPlFree_(void **mem);
extern TK *gMemTask;

void DWCi_TSKlEnd(void)
{
	int i;

	for (i = 0; i < 2; i++) {
		DWCi_LSTlDelete(gMemTask[i].list);
		DWCi_QUElDelete(gMemTask[i].que);
	}
	DWCi_HEAPlFree_((void **)0x021DE6E4);
}
