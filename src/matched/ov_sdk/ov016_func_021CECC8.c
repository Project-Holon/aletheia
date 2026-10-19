/*
 * function: setBar
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
 *   DWCi_TPlGet  0x021D6B64  arm  ov016
 *   func_021CEEE8  0x021CEEE8  arm  ov016
 *   gScrollBar  0x021DE63C  data
 *   sScrollBarStep  0x021DA8BB  data
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

struct tagCOORD;
extern int DWCi_TPlGet(struct tagCOORD *c);
extern void func_021CEEE8(int pos);
extern SB *gScrollBar;
extern unsigned char sScrollBarStep[];

void setBar(void)
{
	COORD c;
	int pos;
	int s;

	DWCi_TPlGet((struct tagCOORD *)(&c));
	s = sScrollBarStep[gScrollBar->bar];
	pos = c.y - gScrollBar->y - ((unsigned)s >> 1);
	if (pos < 0)
		pos = 0;
	else if (pos >= gScrollBar->len - s)
		pos = gScrollBar->len - s;
	func_021CEEE8(pos);
	gScrollBar->b = 3;
}
