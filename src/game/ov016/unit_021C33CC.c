/*
 * file:     unit_021C33CC.c
 * unit:     yes
 * function: func_021C33CC, func_021C33EC, func_021C3454
 * address:  0x021C33CC
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
 *   func_021BD29C  0x021BD29C  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021D603C  0x021D603C  arm  ov016
 *   func_021C3490  0x021C3490  arm  ov016
 */
typedef volatile unsigned short vu16;

extern void func_021BD29C(int msg);
extern void func_021C0E40(unsigned int v);
extern int func_021D55A4(int kind, int lcd, int plane, int frame);
extern void func_021D603C(int lcd, int plane);
extern void func_021C3490(void);
void func_021C33CC(void);
void func_021C33EC(void);
void func_021C3454(void);


/*
 * sdk:      DWCi_SceneOptMovComplete (libdwcutil.TWL.HYB.a(sceneoptmovcompl))
 */
void func_021C33CC(void)
{
	func_021C33EC();
	func_021BD29C(0x1f);
	func_021C0E40((unsigned int)func_021C3454);
}


/*
 * sdk:      initGraphics (libdwcutil.TWL.HYB.a(sceneoptmovcompl))
 */
void func_021C33EC(void)
{
    *(vu16 *)0x04001008 = (*(vu16 *)0x04001008 & ~3) | 3;
    *(vu16 *)0x0400100A = (*(vu16 *)0x0400100A & ~3) | 3;
    *(vu16 *)0x04000008 = (*(vu16 *)0x04000008 & ~3) | 3;
    *(vu16 *)0x0400000A = (*(vu16 *)0x0400000A & ~3) | 3;
    *(vu16 *)0x0400000C = (*(vu16 *)0x0400000C & ~3) | 3;
}


/*
 * sdk:      procInit (libdwcutil.TWL.HYB.a(sceneoptmovcompl))
 */
void func_021C3454(void)
{
	func_021D55A4(2, 0, 0x15, 8);
	func_021D603C(0, 0x15);
	func_021C0E40((unsigned int)func_021C3490);
}
