/*
 * function: DWCi_MSGlInit
 * address:  0x021C0F60
 * packet:   pkt_ov016_021C0F60
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MSGlInit (libdwcutil.TWL.HYB.a(message.o))
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_QUElFormEx  0x021D5410  arm  ov016
 *   gMessageWork  0x021DE58C  data
 */

#include "../include/G_MemMsg.h"

extern void *DWCi_HEAPlAllocEx(unsigned long size, int align);
extern void *DWCi_QUElFormEx(long size, void *data, long dsize);
extern struct MemMsg *gMessageWork;

void DWCi_MSGlInit(void)
{
	void *m = DWCi_HEAPlAllocEx(0x64, 4);
	gMessageWork = m;
	*(void **)(((char *)gMessageWork) + 0x60) = DWCi_QUElFormEx(8, m, 0xc);
}
