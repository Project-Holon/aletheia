/*
 * file:     unit_021CE668_p01.c
 * unit:     yes
 * function: func_021CE6F0, func_021CE708
 * address:  0x021CE6F0
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
 *   MIi_CpuCopy16  0x02082A60  arm
 *   g_021DE630  0x021DE630  data
 */
typedef struct {
	void *task;
	unsigned short data[1];
} SCR;

extern void MIi_CpuCopy16(void *srcp, void *destp, unsigned long size);
void func_021CE6F0(void);
void func_021CE708(void *src, int pos, int w, int h);
extern SCR *g_021DE630;

void func_021CE6F0(void)
{
    *(unsigned char *)(*(char **)0x021DE630 + 0x604) = 1;
}


/*
 * sdk:      DWCi_SCREENlCopy (libdwcutil.TWL.HYB.a(screen.o))
 */
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
