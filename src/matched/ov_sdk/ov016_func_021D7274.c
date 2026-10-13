/*
 * function: DWCi_ClearVram
 * address:  0x021D7274
 * packet:   pkt_ov016_021D7274
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ClearVram (libdwcutil.TWL.HYB.a(sub.o))
 *
 * symbols:
 *   GX_DisableBankForBG  0x02080AD8  arm
 *   GX_DisableBankForOBJ  0x02080AEC  arm
 *   GX_DisableBankForBGExtPltt  0x02080B00  arm
 *   GX_DisableBankForOBJExtPltt  0x02080B24  arm
 *   GX_DisableBankForTex  0x02080B48  arm
 *   GX_DisableBankForTexPltt  0x02080B5C  arm
 *   GX_DisableBankForClearImage  0x02080B70  arm
 *   GX_DisableBankForSubBG  0x02080BAC  arm
 *   GX_DisableBankForSubOBJ  0x02080BC0  arm
 *   GX_DisableBankForSubBGExtPltt  0x02080BD4  arm
 *   GX_DisableBankForSubOBJExtPltt  0x02080BFC  arm
 *   GX_DisableBankForARM7  0x02080B84  arm
 *   GX_DisableBankForLCDC  0x02080B98  arm
 *   GX_SetBankForARM7  0x020805E8  arm
 *   func_021D73BC  0x021D73BC  arm  ov016
 *   gSubWork  0x021DE6B0  data
 */

#include "../include/G_VRAMBANK.h"

typedef struct {
	int bg;
	int obj;
	int bgExt;
	int objExt;
	int tex;
	int texPltt;
	int clrImg;
	int subBg;
	int subObj;
	int subBgExt;
	int subObjExt;
	int arm7;
	int lcdc;
} VRAMBANK;

extern int GX_DisableBankForBG(void);
extern int GX_DisableBankForOBJ(void);
extern int GX_DisableBankForBGExtPltt(void);
extern int GX_DisableBankForOBJExtPltt(void);
extern int GX_DisableBankForTex(void);
extern int GX_DisableBankForTexPltt(void);
extern int GX_DisableBankForClearImage(void);
extern int GX_DisableBankForSubBG(void);
extern int GX_DisableBankForSubOBJ(void);
extern int GX_DisableBankForSubBGExtPltt(void);
extern int GX_DisableBankForSubOBJExtPltt(void);
extern int GX_DisableBankForARM7(void);
extern int GX_DisableBankForLCDC(void);
extern void GX_SetBankForARM7(int arm7);
extern void func_021D73BC(void);
extern struct VRAMBANK gSubWork;

void DWCi_ClearVram(void)
{
	gSubWork.bg = GX_DisableBankForBG();
	gSubWork.obj = GX_DisableBankForOBJ();
	gSubWork.bgExt = GX_DisableBankForBGExtPltt();
	gSubWork.objExt = GX_DisableBankForOBJExtPltt();
	gSubWork.tex = GX_DisableBankForTex();
	gSubWork.texPltt = GX_DisableBankForTexPltt();
	gSubWork.clrImg = GX_DisableBankForClearImage();
	gSubWork.subBg = GX_DisableBankForSubBG();
	gSubWork.subObj = GX_DisableBankForSubOBJ();
	gSubWork.subBgExt = GX_DisableBankForSubBGExtPltt();
	gSubWork.subObjExt = GX_DisableBankForSubOBJExtPltt();
	gSubWork.arm7 = GX_DisableBankForARM7();
	gSubWork.lcdc = GX_DisableBankForLCDC();
	GX_SetBankForARM7(gSubWork.arm7);
	func_021D73BC();
}
