/*
 * function: func_021CEEE8
 * address:  0x021CEEE8
 * packet:   pkt_ov016_021CEEE8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      disp (libdwcutil.TWL.HYB.a(scrollbar.o))
 *
 * symbols:
 *   func_021D5118  0x021D5118  arm  ov016
 *   g_021DE63C  0x021DE63C  data
 */

typedef struct {
	void *cell;
	int pad[3];
	unsigned short x;
	unsigned short y;
	char pad2[6];
	unsigned char pos;
} SB;

extern void func_021D5118(void *cell, int idx, int x, int y);
extern SB *g_021DE63C;

void func_021CEEE8(int pos)
{
	func_021D5118(g_021DE63C->cell, -1, g_021DE63C->x, pos + g_021DE63C->y);
	g_021DE63C->pos = pos;
}
