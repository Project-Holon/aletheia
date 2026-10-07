/*
 * file:     unit_021CE9B8_p03.c
 * unit:     yes
 * function: func_021CECC8, func_021CED30
 * address:  0x021CECC8
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
 *   func_021D6B64  0x021D6B64  arm  ov016
 *   func_021CEEE8  0x021CEEE8  arm  ov016
 *   g_021DE63C  0x021DE63C  data
 *   g_021DA8BB  0x021DA8BB  data
 *   func_021CEE10  0x021CEE10  arm  ov016
 *   func_021D69F4  0x021D69F4  arm  ov016
 *   func_021D696C  0x021D696C  arm  ov016
 */
struct tagCOORD;
typedef struct {
	void *cell;
	int pad0[2];
	void *task;
	unsigned short x;
	unsigned short y;
	char pad1[5];
	unsigned char len;
	unsigned char pos;
	unsigned char bar;
	unsigned char a;
	unsigned char b;
} SB;

typedef struct {
	unsigned short x;
	unsigned short y;
} COORD;

typedef unsigned short u16;

extern int func_021D6B64(struct tagCOORD *c);
extern void func_021CEEE8(int pos);
extern void func_021CEE10(int idx, void *r);
extern int func_021D69F4(u16 *a);
extern int func_021D696C(u16 *a);
void func_021CECC8(void);
int func_021CED30(void);
extern SB *g_021DE63C;
extern unsigned char g_021DA8BB[];


/*
 * sdk:      setBar (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
void func_021CECC8(void)
{
	COORD c;
	int pos;
	int s;

	func_021D6B64((struct tagCOORD *)(&c));
	s = g_021DA8BB[g_021DE63C->bar];
	pos = c.y - g_021DE63C->y - ((unsigned)s >> 1);
	if (pos < 0)
		pos = 0;
	else if (pos >= g_021DE63C->len - s)
		pos = g_021DE63C->len - s;
	func_021CEEE8(pos);
	g_021DE63C->b = 3;
}


/*
 * sdk:      isTrigger (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
int func_021CED30(void)
{
	int idx;
	int r[2];

	idx = 1;
	func_021CEE10(idx, r);
	if (func_021D69F4((u16 *)r))
		return idx;
	for (idx = 2; idx <= 3; idx++) {
		func_021CEE10(idx, r);
		if (func_021D69F4((u16 *)r))
			return idx;
	}
	idx = 4;
	func_021CEE10(idx, r);
	if (!func_021D696C((u16 *)r))
		idx = 0;
	return idx;
}
