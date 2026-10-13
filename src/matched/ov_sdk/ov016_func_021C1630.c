/*
 * function: DWCi_SceneEnd
 * address:  0x021C1630
 * packet:   pkt_ov016_021C1630
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_SceneEnd (libdwcutil.TWL.HYB.a(sceneend.o))
 *
 * symbols:
 *   DWCi_EFFlFade  0x021D55A4  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   func_021C1678  0x021C1678  arm  ov016
 */

extern int DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C1678(void);

void DWCi_SceneEnd(void)
{
	DWCi_EFFlFade(3, 1, 0x3f, 0x14);
	DWCi_EFFlFade(3, 0, 0x3f, 0x14);
	DWCi_ChangeScene((unsigned int)func_021C1678);
}
