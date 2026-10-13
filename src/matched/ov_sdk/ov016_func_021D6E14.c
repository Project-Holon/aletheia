/*
 * function: DWCi_OBJlInit
 * address:  0x021D6E14
 * packet:   pkt_ov016_021D6E14
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_OBJlInit (libdwcutil.TWL.HYB.a(obj.o))
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   DWCi_QUElFormEx  0x021D5410  arm  ov016
 *   DWCi_TSKlForm  0x021D7680  arm  ov016
 *   gObjWork  0x021DE6A8  data
 *   func_021D6EA4  0x021D6EA4  arm  ov016
 */

extern void *DWCi_HEAPlAllocEx(unsigned long size, int align);
extern void MIi_CpuClearFast(unsigned long data, void *dst, unsigned long size);
extern void *DWCi_QUElFormEx(long size, void *data, long dsize);
extern void *DWCi_TSKlForm(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void func_021D6EA4(void);
extern char *gObjWork;

void DWCi_OBJlInit(void)
{
	int i;

	gObjWork = DWCi_HEAPlAllocEx(0x80c, 4);
	MIi_CpuClearFast(0x200, gObjWork, 0x800);
	for (i = 0; i < 2; i++)
		*(void **)(gObjWork + i * 4 + 0x800) = DWCi_QUElFormEx(0x40, gObjWork + i * 0x400, 8);
	*(void **)(gObjWork + 0x808) = DWCi_TSKlForm(1, (void (*)(void *, void *))func_021D6EA4, 0, 0xc8);
}
