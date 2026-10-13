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
 *   DWCi_SNDlSetVolume  0x021CFFD0  arm  ov016
 *   DWCi_SNDlSetPitch  0x021CFFF0  arm  ov016
 *   gScrollBar  0x021DE63C  data
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
extern void DWCi_SNDlSetVolume(unsigned int v);
extern void DWCi_SNDlSetPitch(unsigned int a, unsigned int b);
extern SB *gScrollBar;

void func_021CEC24(int pos)
{
	int d;
	int vol;
	int pit;

	d = gScrollBar->pos - pos;
	if (d < 0)
		d = -d;
	if (d < 2)
		vol = 0;
	else if (d >= 6)
		vol = 0x7f;
	else
		vol = FX_DivS32(0x7f, 6 - d);
	DWCi_SNDlSetVolume(vol);
	if (d < 2)
		pit = -0x100;
	else if (d >= 6)
		pit = 0x100;
	else
		pit = FX_DivS32(0x200, 6 - d) - 0x100;
	DWCi_SNDlSetPitch(0xffff, pit);
}
