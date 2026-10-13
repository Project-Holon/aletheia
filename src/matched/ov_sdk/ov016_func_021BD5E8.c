/*
 * function: DWCi_HLlInit
 * address:  0x021BD5E8
 * packet:   pkt_ov016_021BD5E8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_HLlInit (libdwcutil.TWL.HYB.a headline.o)
 *
 * symbols:
 *   DWCi_HEAPlAllocEx  0x021D6414  arm  ov016
 *   DWCi_CMNlLoadResource  0x021BD1D4  arm  ov016
 *   DWCi_Entry  0x021C0ED8  arm  ov016
 *   GX_LoadBG1Char 0x0207EF90  arm
 *   GX_LoadBG1Scr  0x0207EA00  arm
 *   gHeadlineWork     0x021DE554  data
 *   sHeadlinePathJbBgHlChar     0x021DAE54  data
 *   sHeadlineTable     0x021DAE04  data
 */

extern void *DWCi_HEAPlAllocEx(unsigned long size, int align);
extern void DWCi_CMNlLoadResource(char *file, void (*func)(void *, unsigned long, unsigned long));
extern unsigned int DWCi_Entry(void);
extern void GX_LoadBG1Char(void *, unsigned long, unsigned long);
extern void GX_LoadBG1Scr(void *, unsigned long, unsigned long);
extern unsigned short *gHeadlineWork;
extern char sHeadlinePathJbBgHlChar[];
extern char *sHeadlineTable[];

void DWCi_HLlInit(void)
{
    gHeadlineWork = DWCi_HEAPlAllocEx(0xC0, 4);
    DWCi_CMNlLoadResource(sHeadlinePathJbBgHlChar, GX_LoadBG1Char);
    switch (DWCi_Entry()) {
    case 0:
        DWCi_CMNlLoadResource(sHeadlineTable[0], GX_LoadBG1Scr);
        break;
    case 1:
        DWCi_CMNlLoadResource(sHeadlineTable[1], GX_LoadBG1Scr);
        break;
    }
}
