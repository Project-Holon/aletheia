/*
 * function: DWCi_SceneInitProcWait
 * address:  0x021C1908
 * packet:   pkt_ov016_021C1908
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procWait (libdwcutil.TWL.HYB.a(sceneinit.o))
 *
 * symbols:
 *   DWCi_EFFlCheck  0x021D5580  arm  ov016
 *   DWCi_Entry  0x021C0ED8  arm  ov016
 *   DWCi_SetParam_  0x021C0E50  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_SceneMenu  0x021C1984  arm  ov016
 *   DWCi_SceneSetSelectAp  0x021CBC90  arm  ov016
 */

extern int DWCi_EFFlCheck(int lcd);
extern unsigned int DWCi_Entry(void);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_SceneMenu(void);
extern void DWCi_SceneSetSelectAp(void);

void DWCi_SceneInitProcWait(void)
{
	if (DWCi_EFFlCheck(1))
		return;
	if (DWCi_EFFlCheck(0))
		return;
	switch (DWCi_Entry()) {
	case 0:
		DWCi_SetParam_(0, (unsigned int)((void *)1));
		DWCi_ChangeScene((unsigned int)DWCi_SceneMenu);
		break;
	case 1:
		DWCi_SetParam_((unsigned int)((void *)1), (unsigned int)((void *)1));
		DWCi_ChangeScene((unsigned int)DWCi_SceneSetSelectAp);
		break;
	}
}
