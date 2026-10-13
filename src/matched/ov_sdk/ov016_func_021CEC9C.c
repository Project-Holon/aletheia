/*
 * function: func_021CEC9C
 * address:  0x021CEC9C
 * packet:   pkt_ov016_021CEC9C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      stepBar (libdwcutil.TWL.HYB.a(scrollbar.o))
 *
 * symbols:
 *   gScrollBar  0x021DE63C  data
 */

typedef struct {
	char pad[0x1c];
	unsigned char a;
	unsigned char b;
} SB;

extern SB *gScrollBar;

void func_021CEC9C(int idx)
{
	gScrollBar->a = idx;
	gScrollBar->b = (idx == 2) ? 4 : 6;
}
