/*
 * file:     unit_021CE9B8_p04.c
 * unit:     yes
 * function: func_021CEE10, func_021CEEE8
 * address:  0x021CEE10
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
 *   g_021DE63C  0x021DE63C  data
 *   g_021DA8BB  0x021DA8BB  data
 *   func_021D5118  0x021D5118  arm  ov016
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
} SB_021CEE10;

typedef struct {
	unsigned short x0;
	unsigned short y0;
	unsigned short x1;
	unsigned short y1;
} RECT;

typedef struct {
	void *cell;
	int pad[3];
	unsigned short x;
	unsigned short y;
	char pad2[6];
	unsigned char pos;
} SB_021CEEE8;

extern void func_021D5118(void *cell, int idx, int x, int y);
void func_021CEE10(int idx, RECT *r);
void func_021CEEE8(int pos);
extern SB_021CEE10 *g_021DE63C;
extern unsigned char g_021DA8BB[];


/*
 * sdk:      calcRect (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
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


/*
 * sdk:      disp (libdwcutil.TWL.HYB.a(scrollbar.o))
 */
void func_021CEEE8(int pos)
{
	func_021D5118(g_021DE63C->cell, -1, g_021DE63C->x, pos + g_021DE63C->y);
	g_021DE63C->pos = pos;
}
