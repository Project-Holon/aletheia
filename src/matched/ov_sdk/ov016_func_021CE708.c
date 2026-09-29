/*
 * function: func_021CE708
 * address:  0x021CE708
 * packet:   pkt_ov016_021CE708
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SCREENlCopy (libdwcutil.TWL.HYB.a(screen.o))
 *
 * symbols:
 *   MIi_CpuCopy16  0x02082A60  arm
 *   g_021DE630  0x021DE630  data
 */

typedef struct {
	void *task;
	unsigned short data[1];
} SCR;

extern void MIi_CpuCopy16(void *srcp, void *destp, unsigned long size);
extern SCR *g_021DE630;

void func_021CE708(void *src, int pos, int w, int h)
{
	unsigned short *sr;
	unsigned short *dst;
	int i;

	sr = (unsigned short *)src;
	dst = g_021DE630->data + pos;
	for (i = 0; i < h; i++) {
		MIi_CpuCopy16(sr, dst, w * 2);
		sr += 32;
		dst += 32;
	}
}
