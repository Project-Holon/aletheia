/*
 * function: func_021C2E6C
 * address:  0x021C2E6C
 * packet:   pkt_ov016_021C2E6C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      button (libdwcutil.TWL.HYB.a(sceneoptmenu.o))
 *
 * symbols:
 *   DWCi_BTNlGet  0x021BCB14  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_BM_GetWiFiInfo  0x02058518  arm
 *   DWCi_BTNlSetForce  0x021BCB44  arm  ov016
 *   func_021C3130  0x021C3130  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gSceneOptMenuWork  0x021DE5A8  data
 *   func_021C2F14  0x021C2F14  arm  ov016
 */

#include "../include/G_FocusPosT.h"

typedef struct {
	unsigned char idx;
	unsigned char flag;
	unsigned char pad[2];
	void *ptr;
} FocusPosT;

typedef struct {
	unsigned long long a;
	int c[3];
} WiFiInfoT;

extern signed char DWCi_BTNlGet(void);
extern void DWCi_SNDlPlay(unsigned int v);
struct tagDWCWiFiInfo;
extern void DWCi_BM_GetWiFiInfo(struct tagDWCWiFiInfo *buf);
extern void DWCi_BTNlSetForce(int idx);
extern void func_021C3130(void);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C2F14(void);
extern struct FocusPosT gSceneOptMenuWork;

void func_021C2E6C(void)
{
	WiFiInfoT info;

	switch (DWCi_BTNlGet()) {
	case 0:
		DWCi_SNDlPlay(7);
		break;
	case 1:
		DWCi_BM_GetWiFiInfo((struct tagDWCWiFiInfo *)(&info));
		if (gSceneOptMenuWork.idx != 0 && info.a == 0) {
			DWCi_SNDlPlay(9);
			DWCi_BTNlSetForce(-1);
			return;
		}
		DWCi_SNDlPlay(6);
		func_021C3130();
		gSceneOptMenuWork.flag = 1;
		break;
	default:
		return;
	}
	DWCi_ChangeScene((unsigned int)func_021C2F14);
}
