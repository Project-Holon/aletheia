/*
 * function: clearVram
 * address:  0x021D73BC
 * packet:   pkt_ov016_021D73BC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      clearVram (libdwcutil.TWL.HYB.a(sub.o))
 *
 * symbols:
 *   GX_SetBankForLCDC  0x0208068C  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   GX_DisableBankForLCDC  0x02080B98  arm
 */

extern void GX_SetBankForLCDC(int lcdc);
extern void MIi_CpuClearFast(unsigned long data, void *destp, unsigned long size);
extern int GX_DisableBankForLCDC(void);

void clearVram(void)
{
	GX_SetBankForLCDC(0x1f3);
	MIi_CpuClearFast(0, (void *)0x06800000, 0x40000);
	MIi_CpuClearFast(0, (void *)0x06880000, 0x24000);
	GX_DisableBankForLCDC();
	MIi_CpuClearFast(0x200, (void *)0x07000000, 0x400);
	MIi_CpuClearFast(0, (void *)0x05000000, 0x400);
	MIi_CpuClearFast(0x200, (void *)0x07000400, 0x400);
	MIi_CpuClearFast(0, (void *)0x05000400, 0x400);
}
