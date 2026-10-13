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
 *   gScrollBar  0x021DE63C  data
 *   sScrollBarStep  0x021DA8BB  data
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

extern SB *gScrollBar;
extern unsigned char sScrollBarStep[];

void func_021CEE10(int idx, RECT *r)
{
	int x = gScrollBar->x;
	r->x0 = x;
	r->x1 = x + 12;
	switch (idx) {
	case 0:
		break;
	case 1:
		r->y0 = gScrollBar->y + gScrollBar->pos;
		r->y1 = r->y0 + sScrollBarStep[gScrollBar->bar];
		break;
	case 2:
		r->y0 = gScrollBar->y - 13;
		r->y1 = gScrollBar->y;
		break;
	case 3:
		r->y0 = gScrollBar->y + gScrollBar->len;
		r->y1 = r->y0 + 13;
		break;
	case 4:
		r->y0 = gScrollBar->y;
		r->y1 = r->y0 + gScrollBar->len;
		break;
	}
}
