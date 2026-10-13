/*
 * function: DWCi_SCREENlInit
 * address:  0x021CE668
 * packet:   pkt_ov016_021CE668
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SCREENlInit (libdwcutil.TWL.HYB.a(screen.o))
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   func_021CE760  0x021CE760  arm  ov016
 *   gScreenWork  0x021DE630  data
 */

typedef struct {
	void *task;
	unsigned short data[1];
} SCR;

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern void MIi_CpuCopyFast(void *srcp, void *destp, unsigned long size);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *), void *work, unsigned char prio);
extern void func_021CE760(void);
extern SCR *gScreenWork;

void DWCi_SCREENlInit(void *scr)
{
	gScreenWork = (SCR *)DWCi_HEAPlAllocEx(0x608, 4);
	MIi_CpuCopyFast(scr, gScreenWork->data, 0x600);
	gScreenWork->task = DWCi_TSKlForm(1, (void (*)(void *))func_021CE760, 0, 0x78);
}
