/*
 * function: func_021C16F4
 * address:  0x021C16F4
 * packet:   pkt_ov016_021C16F4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneInit (libdwcutil.TWL.HYB.a(sceneinit.o))
 *
 * symbols:
 *   func_021CF3B0     0x021CF3B0  arm  ov016
 *   func_021C0F60     0x021C0F60  arm  ov016
 *   func_021BD3E4     0x021BD3E4  arm  ov016
 *   func_021BD5E8     0x021BD5E8  arm  ov016
 *   func_021BD04C     0x021BD04C  arm  ov016
 *   func_021C0EC8     0x021C0EC8  arm  ov016
 *   func_021C0EF0     0x021C0EF0  arm  ov016
 *   func_021C0FAC     0x021C0FAC  arm  ov016
 *   func_021BD170     0x021BD170  arm  ov016
 *   func_021D5280     0x021D5280  arm  ov016
 *   func_021BD1D4     0x021BD1D4  arm  ov016
 *   func_021C0ED8     0x021C0ED8  arm  ov016
 *   func_021D603C     0x021D603C  arm  ov016
 *   func_021C0E40     0x021C0E40  arm  ov016
 *   func_021C18C4     0x021C18C4  arm  ov016
 *   GXS_LoadBG1Char   0x0207F024  arm
 *   GXS_LoadBGPltt    0x0207E468  arm
 *   GXS_LoadOBJ       0x0207E804  arm
 *   GXS_LoadOBJPltt   0x0207E5D0  arm
 *   GX_LoadBG2Char    0x0207F0B8  arm
 *   GX_LoadBGPltt     0x0207E3D0  arm
 *   GX_LoadOBJ        0x0207E780  arm
 *   GX_LoadOBJPltt    0x0207E51C  arm
 *   GXS_LoadBG1Scr    0x0207EABC  arm
 *   g_021DB13C        0x021DB13C  data
 *   g_021DB158        0x021DB158  data
 *   g_021DB168        0x021DB168  data
 *   g_021DB17C        0x021DB17C  data
 *   g_021DB190        0x021DB190  data
 *   g_021DB1A4        0x021DB1A4  data
 *   g_021DB1B8        0x021DB1B8  data
 *   g_021DB1D0        0x021DB1D0  data
 *   g_021DB1E8        0x021DB1E8  data
 *   g_021DB200        0x021DB200  data
 *   g_021DB218        0x021DB218  data
 *   g_021DB230        0x021DB230  data
 *   g_021DB248        0x021DB248  data
 *   g_021DB25C        0x021DB25C  data
 *   g_021DE598        0x021DE598  data
 */

typedef void (*LoadFunc)(void *, unsigned long, unsigned long);

extern void func_021CF3B0(void);
extern void func_021C0F60(void);
extern void func_021BD3E4(void);
extern void func_021BD5E8(void);
extern void func_021BD04C(void);
extern unsigned char func_021C0EC8(void);
extern int func_021C0EF0(unsigned long flag);
extern void *func_021C0FAC(char *file);
extern char *func_021BD170(char *name);
extern void func_021D5280(int lcd, char *file);
extern void func_021BD1D4(char *file, void (*func)(void *, unsigned long, unsigned long));
extern unsigned int func_021C0ED8(void);
extern void func_021D603C(int lcd, int plane);
extern void func_021C0E40(unsigned int v);
extern void func_021C18C4(void);

extern void GXS_LoadBG1Char(void);
extern void GXS_LoadBGPltt(void);
extern void GXS_LoadOBJ(void);
extern void GXS_LoadOBJPltt(void);
extern void GX_LoadBG2Char(void);
extern void GX_LoadBGPltt(void);
extern void GX_LoadOBJ(void);
extern void GX_LoadOBJPltt(void);
extern void GXS_LoadBG1Scr(void);

extern char *g_021DB13C[7];
extern char g_021DB158[];
extern char g_021DB168[];
extern char g_021DB17C[];
extern char g_021DB190[];
extern char g_021DB1A4[];
extern char g_021DB1B8[];
extern char g_021DB1D0[];
extern char g_021DB1E8[];
extern char g_021DB200[];
extern char g_021DB218[];
extern char g_021DB230[];
extern char g_021DB248[];
extern char g_021DB25C[];
extern void *g_021DE598;

void func_021C16F4(void)
{
    char *n;

    func_021CF3B0();
    func_021C0F60();
    func_021BD3E4();
    func_021BD5E8();
    func_021BD04C();
    if (func_021C0EC8() == 1 && func_021C0EF0(2)) {
        n = g_021DB158;
        g_021DE598 = func_021C0FAC(n);
    } else {
        n = g_021DB13C[func_021C0EC8()];
        g_021DE598 = func_021C0FAC(n);
    }
    func_021D5280(1, func_021BD170(g_021DB168));
    func_021D5280(0, func_021BD170(g_021DB17C));
    func_021BD1D4(g_021DB190, (LoadFunc)GXS_LoadBG1Char);
    func_021BD1D4(g_021DB1A4, (LoadFunc)GXS_LoadBGPltt);
    func_021BD1D4(g_021DB1B8, (LoadFunc)GXS_LoadOBJ);
    func_021BD1D4(g_021DB1D0, (LoadFunc)GXS_LoadOBJPltt);
    func_021BD1D4(g_021DB1E8, (LoadFunc)GX_LoadBG2Char);
    func_021BD1D4(g_021DB200, (LoadFunc)GX_LoadBGPltt);
    func_021BD1D4(g_021DB218, (LoadFunc)GX_LoadOBJ);
    func_021BD1D4(g_021DB230, (LoadFunc)GX_LoadOBJPltt);
    switch (func_021C0ED8()) {
    case 0:
        func_021BD1D4(g_021DB248, (LoadFunc)GXS_LoadBG1Scr);
        break;
    case 1:
        func_021BD1D4(g_021DB25C, (LoadFunc)GXS_LoadBG1Scr);
        break;
    }
    *(volatile unsigned short *)0x0400100A = (*(volatile unsigned short *)0x0400100A & ~3) | 3;
    *(volatile unsigned short *)0x0400000A = (*(volatile unsigned short *)0x0400000A & ~3) | 3;
    *(volatile unsigned short *)0x0400000A = (*(volatile unsigned short *)0x0400000A & ~3) | 3;
    func_021D603C(1, 2);
    func_021D603C(0, 2);
    func_021C0E40((unsigned int)func_021C18C4);
}
