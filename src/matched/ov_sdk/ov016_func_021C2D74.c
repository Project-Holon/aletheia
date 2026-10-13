/*
 * function: func_021C2D74
 * address:  0x021C2D74
 * packet:   pkt_ov016_021C2D74
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      input (libdwcutil.TWL.HYB.a(sceneoptmenu.o))
 *
 * symbols:
 *   DWCi_TPlCheckTrigger  0x021D696C  arm  ov016
 *   DWCi_BTNlSet  0x021BCB28  arm  ov016
 *   DWCi_FOCUSlDisp4  0x021BD4C8  arm  ov016
 *   DWCi_IPTlCheckTrigger  0x021D6824  arm  ov016
 *   DWCi_IPTlCheckRepeat  0x021D6864  arm  ov016
 *   func_021C30AC  0x021C30AC  arm  ov016
 *   sSceneOptMenuTouchRects  0x021DA4B8  data
 *   sSceneOptMenuFocusX0  0x021DA4D0  data
 *   sSceneOptMenuFocusX1  0x021DA4D4  data
 *   sSceneOptMenuFocusY0  0x021DA4D2  data
 *   sSceneOptMenuFocusY1  0x021DA4D6  data
 *   gSceneOptMenuWork  0x021DE5A8  data
 */

#include "../include/G_FocusPosT.h"
#include "../include/G_RectT.h"

typedef struct {
	unsigned short l;
	unsigned short t;
	unsigned short r;
	unsigned short b;
} RectT;

typedef struct {
	unsigned char idx;
	unsigned char flag;
	unsigned char pad[2];
	void *ptr;
} FocusPosT;

typedef unsigned short u16;
extern int DWCi_TPlCheckTrigger(u16 *a);
extern void DWCi_BTNlSet(signed char v);
extern void DWCi_FOCUSlDisp4(int x0, int x1, int y0, int y1);
extern int DWCi_IPTlCheckTrigger(unsigned int f);
extern int DWCi_IPTlCheckRepeat(unsigned int f);
extern void func_021C30AC(int dir);
extern RectT sSceneOptMenuTouchRects[3];
extern struct RectT sSceneOptMenuFocusX0[3];
extern struct FocusPosT gSceneOptMenuWork;

void func_021C2D74(void)
{
	unsigned i;

	for (i = 0; i < 3; i++) {
		if (DWCi_TPlCheckTrigger((u16 *)(&sSceneOptMenuTouchRects[i]))) {
			DWCi_BTNlSet(1);
			gSceneOptMenuWork.idx = i;
			DWCi_FOCUSlDisp4(sSceneOptMenuFocusX0[gSceneOptMenuWork.idx].l, sSceneOptMenuFocusX0[gSceneOptMenuWork.idx].r,
				sSceneOptMenuFocusX0[gSceneOptMenuWork.idx].t, sSceneOptMenuFocusX0[gSceneOptMenuWork.idx].b);
			return;
		}
	}
	if (DWCi_IPTlCheckTrigger(1)) {
		DWCi_BTNlSet(1);
		return;
	}
	if (DWCi_IPTlCheckTrigger(2)) {
		DWCi_BTNlSet(0);
		return;
	}
	if (DWCi_IPTlCheckRepeat(0x40)) {
		func_021C30AC(1);
		return;
	}
	if (DWCi_IPTlCheckRepeat(0x80))
		func_021C30AC(3);
}
