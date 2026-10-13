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
 *   DWCi_CELLlSetPosition  0x021D5118  arm  ov016
 *   gScrollBar  0x021DE63C  data
 */

typedef struct {
	void *cell;
	int pad[3];
	unsigned short x;
	unsigned short y;
	char pad2[6];
	unsigned char pos;
} SB;

extern void DWCi_CELLlSetPosition(void *cell, int idx, int x, int y);
extern SB *gScrollBar;

void func_021CEEE8(int pos)
{
	DWCi_CELLlSetPosition(gScrollBar->cell, -1, gScrollBar->x, pos + gScrollBar->y);
	gScrollBar->pos = pos;
}
