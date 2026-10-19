/*
 * function: DWCi_SceneOptMenuDispPush
 * address:  0x021C3130
 * packet:   pkt_ov016_021C3130
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      dispPush (libdwcutil.TWL.HYB.a(sceneoptmenu.o))
 *
 * symbols:
 *   gSceneOptMenuWork  0x021DE5A8  data
 *   sSceneOptMenuEntryCount  0x021DA4B0  data
 *   DWCi_SCREENlCopyPalette  0x021CE7B0  arm  ov016
 */

#include "../include/G_FocusPosT.h"

typedef struct {
	unsigned char idx;
	unsigned char flag;
	unsigned char pad[2];
	void *ptr;
} FocusPosT;

extern void DWCi_SCREENlCopyPalette(void *p, int a, int b);
extern struct FocusPosT gSceneOptMenuWork;
extern unsigned char sSceneOptMenuEntryCount[3];

void DWCi_SceneOptMenuDispPush(void)
{
	int n = sSceneOptMenuEntryCount[gSceneOptMenuWork.idx];
	DWCi_SCREENlCopyPalette(gSceneOptMenuWork.ptr, n, n);
}
