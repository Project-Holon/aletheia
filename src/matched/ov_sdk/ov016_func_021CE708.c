/*
 * function: DWCi_SCREENlCopy
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
 *   gScreenWork  0x021DE630  data
 */

typedef struct {
	void *task;
	unsigned short data[1];
} SCR;

extern void MIi_CpuCopy16(void *srcp, void *destp, unsigned long size);
extern SCR *gScreenWork;

void DWCi_SCREENlCopy(void *src, int pos, int w, int h)
{
	unsigned short *sr;
	unsigned short *dst;
	int i;

	sr = (unsigned short *)src;
	dst = gScreenWork->data + pos;
	for (i = 0; i < h; i++) {
		MIi_CpuCopy16(sr, dst, w * 2);
		sr += 32;
		dst += 32;
	}
}
