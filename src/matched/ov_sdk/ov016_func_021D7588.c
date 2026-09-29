/*
 * function: func_021D7588
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
 *   func_021D6D70  0x021D6D70  arm  ov016
 *   func_021D5450  0x021D5450  arm  ov016
 *   func_021D6438  0x021D6438  arm  ov016
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

extern void func_021D6D70(void *list);
extern void func_021D5450(void *queue);
extern void func_021D6438(void **mem);
extern TK *g_021DE6E4;

void func_021D7588(void)
{
	int i;

	for (i = 0; i < 2; i++) {
		func_021D6D70(g_021DE6E4[i].list);
		func_021D5450(g_021DE6E4[i].que);
	}
	func_021D6438((void **)0x021DE6E4);
}
