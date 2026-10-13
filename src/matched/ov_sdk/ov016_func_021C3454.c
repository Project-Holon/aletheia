/*
 * function: func_021C3454
 * address:  0x021C3454
 * packet:   pkt_ov016_021C3454
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procInit (libdwcutil.TWL.HYB.a(sceneoptmovcompl))
 *
 * symbols:
 *   DWCi_EFFlFade  0x021D55A4  arm  ov016
 *   DWCi_GXlVisible  0x021D603C  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   func_021C3490  0x021C3490  arm  ov016
 */

extern int DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C3490(void);

void func_021C3454(void)
{
	DWCi_EFFlFade(2, 0, 0x15, 8);
	DWCi_GXlVisible(0, 0x15);
	DWCi_ChangeScene((unsigned int)func_021C3490);
}
