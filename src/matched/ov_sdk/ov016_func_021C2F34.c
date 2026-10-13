/*
 * function: func_021C2F34
 * address:  0x021C2F34
 * packet:   pkt_ov016_021C2F34
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a(sceneoptmenu.o))
 *
 * symbols:
 *   DWCi_EFFlCheck  0x021D5580  arm  ov016
 *   DWCi_BTNlEnd  0x021BCAE4  arm  ov016
 *   DWCi_EFFlFade  0x021D55A4  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gSceneOptMenuWork  0x021DE5A8  data
 *   func_021C2FA0  0x021C2FA0  arm  ov016
 */

#include "../include/G_FocusPosT.h"

typedef struct {
	unsigned char idx;
	unsigned char flag;
	unsigned char pad[2];
	void *ptr;
} FocusPosT;

extern int DWCi_EFFlCheck(int lcd);
extern void DWCi_BTNlEnd(void);
extern int DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C2FA0(void);
extern struct FocusPosT gSceneOptMenuWork;

void func_021C2F34(void)
{
	if (DWCi_EFFlCheck(1))
		return;
	if (gSceneOptMenuWork.flag)
		DWCi_BTNlEnd();
	DWCi_EFFlFade(3, 1, 1, 8);
	DWCi_EFFlFade(3, 0, 0x14, 8);
	DWCi_ChangeScene((unsigned int)func_021C2FA0);
}
