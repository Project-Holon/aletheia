/*
 * function: func_021CE874
 * address:  0x021CE874
 * packet:   pkt_ov016_021CE874
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SBlInit (libdwcutil.TWL.HYB.a(scrollbar.o))
 *
 * symbols:
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_021D5FE8  0x021D5FE8  arm  ov016
 *   func_021D5394  0x021D5394  arm  ov016
 *   func_021D5118  0x021D5118  arm  ov016
 *   func_021D51F0  0x021D51F0  arm  ov016
 *   func_021D7680  0x021D7680  arm  ov016
 *   func_021CE9E8  0x021CE9E8  arm  ov016
 *   g_021DE63C  0x021DE63C  data
 *   g_021DA8B8  0x021DA8B8  data
 */

typedef struct {
	void *cell;
	int pad0[2];
	void *task;
	unsigned short x;
	unsigned short y;
	unsigned short w;
	unsigned short off;
	unsigned char base;
	unsigned char len;
	unsigned char pos;
	unsigned char bar;
	unsigned char a;
	unsigned char b;
} SB;

extern void *func_021D6414(unsigned long size, int alignment);
extern void func_021D5FE8(int x, int y, void *out);
extern void *func_021D5394(int a, int kind, int c);
extern void func_021D5118(void *cell, int idx, int x, int y);
extern void func_021D51F0(void *cell, int idx, int prio);
extern void *func_021D7680(int kind, void (*func)(void *), void *work, unsigned char prio);
extern void func_021CE9E8(void);
extern SB *g_021DE63C;
extern unsigned char g_021DA8B8[];

void func_021CE874(int kind, int max, int x, int y, int pos)
{
	g_021DE63C = (SB *)func_021D6414(0x20, 4);
	g_021DE63C->bar = kind;
	g_021DE63C->len = max;
	g_021DE63C->pos = pos;
	func_021D5FE8(x, y, &g_021DE63C->x);
	g_021DE63C->cell = func_021D5394(0, g_021DA8B8[kind], 1);
	func_021D5118(g_021DE63C->cell, -1, x, y + pos);
	func_021D51F0(g_021DE63C->cell, -1, 1);
	g_021DE63C->task = func_021D7680(0, (void (*)(void *))func_021CE9E8, 0, 0x80);
}
