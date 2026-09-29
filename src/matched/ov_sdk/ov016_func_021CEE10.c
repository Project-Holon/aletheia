/*
 * function: func_021CEE10
 * address:  0x021CEE10
 * packet:   pkt_ov016_021CEE10
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      calcRect (libdwcutil.TWL.HYB.a(scrollbar.o))
 *
 * symbols:
 *   g_021DE63C  0x021DE63C  data
 *   g_021DA8BB  0x021DA8BB  data
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

typedef struct {
	unsigned short x0;
	unsigned short y0;
	unsigned short x1;
	unsigned short y1;
} RECT;

extern SB *g_021DE63C;
extern unsigned char g_021DA8BB[];

void func_021CEE10(int idx, RECT *r)
{
	int x = g_021DE63C->x;
	r->x0 = x;
	r->x1 = x + 12;
	switch (idx) {
	case 0:
		break;
	case 1:
		r->y0 = g_021DE63C->y + g_021DE63C->pos;
		r->y1 = r->y0 + g_021DA8BB[g_021DE63C->bar];
		break;
	case 2:
		r->y0 = g_021DE63C->y - 13;
		r->y1 = g_021DE63C->y;
		break;
	case 3:
		r->y0 = g_021DE63C->y + g_021DE63C->len;
		r->y1 = r->y0 + 13;
		break;
	case 4:
		r->y0 = g_021DE63C->y;
		r->y1 = r->y0 + g_021DE63C->len;
		break;
	}
}
