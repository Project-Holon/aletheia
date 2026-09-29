/*
 * function: func_021CECC8
 * address:  0x021CECC8
 * packet:   pkt_ov016_021CECC8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      setBar (libdwcutil.TWL.HYB.a(scrollbar.o))
 *
 * symbols:
 *   func_021D6B64  0x021D6B64  arm  ov016
 *   func_021CEEE8  0x021CEEE8  arm  ov016
 *   g_021DE63C  0x021DE63C  data
 *   g_021DA8BB  0x021DA8BB  data
 */

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

extern int func_021D6B64(COORD *c);
extern void func_021CEEE8(int pos);
extern SB *g_021DE63C;
extern unsigned char g_021DA8BB[];

void func_021CECC8(void)
{
	COORD c;
	int pos;
	int s;

	func_021D6B64(&c);
	s = g_021DA8BB[g_021DE63C->bar];
	pos = c.y - g_021DE63C->y - ((unsigned)s >> 1);
	if (pos < 0)
		pos = 0;
	else if (pos >= g_021DE63C->len - s)
		pos = g_021DE63C->len - s;
	func_021CEEE8(pos);
	g_021DE63C->b = 3;
}
