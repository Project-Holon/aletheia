/*
 * function: func_021BD704
 * address:  0x021BD704
 * packet:   pkt_ov016_021BD704
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      taskLoad (libdwcutil.TWL.HYB.a headline.o)
 *
 * symbols:
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *   GX_LoadBG1Scr  0x0207EA00  arm
 *   DWCi_TSKlDelete  0x021D7724  arm  ov016
 *   gHeadlineWork     0x021DE554  data
 */

extern void DWCi_ScreenDC_FlushRange(void *addr, unsigned long n);
extern void GX_LoadBG1Scr(void *src, unsigned long off, unsigned long sz);
extern void DWCi_TSKlDelete(int kind, void *task);
extern unsigned short *gHeadlineWork;

void func_021BD704(void *task)
{
    DWCi_ScreenDC_FlushRange(gHeadlineWork, 0xC0);
    GX_LoadBG1Scr(gHeadlineWork, 0, 0xC0);
    DWCi_TSKlDelete(1, task);
}
