/*
 * function: func_021CEC24
 * address:  0x021CEC24
 * packet:   pkt_ov016_021CEC24
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      playSound (libdwcutil.TWL.HYB.a(scrollbar.o))
 *
 * symbols:
 *   FX_DivS32  0x0207C958  arm
 *   func_021CFFD0  0x021CFFD0  arm  ov016
 *   func_021CFFF0  0x021CFFF0  arm  ov016
 *   g_021DE63C  0x021DE63C  data
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

extern long FX_DivS32(long a, long b);
extern void func_021CFFD0(unsigned int v);
extern void func_021CFFF0(unsigned int a, unsigned int b);
extern SB *g_021DE63C;

void func_021CEC24(int pos)
{
	int d;
	int vol;
	int pit;

	d = g_021DE63C->pos - pos;
	if (d < 0)
		d = -d;
	if (d < 2)
		vol = 0;
	else if (d >= 6)
		vol = 0x7f;
	else
		vol = FX_DivS32(0x7f, 6 - d);
	func_021CFFD0(vol);
	if (d < 2)
		pit = -0x100;
	else if (d >= 6)
		pit = 0x100;
	else
		pit = FX_DivS32(0x200, 6 - d) - 0x100;
	func_021CFFF0(0xffff, pit);
}
