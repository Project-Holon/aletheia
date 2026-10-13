/*
 * function: func_021C38EC
 * address:  0x021C38EC
 * packet:   pkt_ov016_021C38EC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procInit (libdwcutil.TWL.HYB.a(sceneoptmovconfi))
 * symbols:
 *   DWCi_EFFlFade  0x021D55A4  arm
 *   DWCi_GXlVisible  0x021D603C  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm
 *   func_021C3954  0x021C3954  arm
 */
extern void DWCi_EFFlFade(int a, int b, int c, int d);
extern void DWCi_GXlVisible(int a, int b);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C3954(void);

void func_021C38EC(void)
{
    DWCi_EFFlFade(2, 1, 1, 8);
    DWCi_EFFlFade(2, 0, 0x15, 8);
    DWCi_GXlVisible(1, 1);
    DWCi_GXlVisible(0, 0x15);
    DWCi_ChangeScene((unsigned int)func_021C3954);
}
