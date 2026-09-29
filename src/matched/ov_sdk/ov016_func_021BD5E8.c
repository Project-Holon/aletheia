/*
 * function: func_021BD5E8
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
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_021BD1D4  0x021BD1D4  arm  ov016
 *   func_021C0ED8  0x021C0ED8  arm  ov016
 *   GX_LoadBG1Char 0x0207EF90  arm
 *   GX_LoadBG1Scr  0x0207EA00  arm
 *   g_021DE554     0x021DE554  data
 *   g_021DAE54     0x021DAE54  data
 *   g_021DAE04     0x021DAE04  data
 */

extern void *func_021D6414(unsigned long size, int align);
extern void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern int func_021C0ED8(void);
extern void GX_LoadBG1Char(void *, unsigned long, unsigned long);
extern void GX_LoadBG1Scr(void *, unsigned long, unsigned long);
extern unsigned short *g_021DE554;
extern char g_021DAE54[];
extern char *g_021DAE04[];

void func_021BD5E8(void)
{
    g_021DE554 = func_021D6414(0xC0, 4);
    func_021BD1D4(g_021DAE54, GX_LoadBG1Char);
    switch (func_021C0ED8()) {
    case 0:
        func_021BD1D4(g_021DAE04[0], GX_LoadBG1Scr);
        break;
    case 1:
        func_021BD1D4(g_021DAE04[1], GX_LoadBG1Scr);
        break;
    }
}
