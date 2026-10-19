/*
 * function: taskTransfer
 * address:  0x021D6EA4
 * packet:   pkt_ov016_021D6EA4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskTransfer (libdwcutil.TWL.HYB.a(obj.o))
 *
 * symbols:
 *   DC_FlushRange  0x020862F0  arm
 *   GX_LoadOAM  0x0207E684  arm
 *   GXS_LoadOAM  0x0207E708  arm
 *   gObjWork  0x021DE6A8  data
 */

extern void DC_FlushRange(void *start, unsigned long n);
extern void GX_LoadOAM(void *src, unsigned long off, unsigned long sz);
extern void GXS_LoadOAM(void *src, unsigned long off, unsigned long sz);
extern char *gObjWork;

void taskTransfer(void)
{
	DC_FlushRange(gObjWork, 0x800);
	GX_LoadOAM(gObjWork, 0, 0x400);
	GXS_LoadOAM(gObjWork + 0x400, 0, 0x400);
}
