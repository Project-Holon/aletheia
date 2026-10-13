/*
 * function: DWCi_RepairVram
 * address:  0x021D72F8
 * packet:   pkt_ov016_021D72F8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_RepairVram (libdwcutil.TWL.HYB.a(sub.o))
 *
 * symbols:
 *   GX_DisableBankForBG  0x02080AD8  arm
 *   GX_DisableBankForOBJ  0x02080AEC  arm
 *   GX_DisableBankForSubBG  0x02080BAC  arm
 *   GX_DisableBankForSubOBJ  0x02080BC0  arm
 *   func_021D73BC  0x021D73BC  arm  ov016
 *   GX_SetBankForBG  0x0207FDCC  arm
 *   GX_SetBankForOBJ  0x0207FFD0  arm
 *   GX_SetBankForBGExtPltt  0x02080100  arm
 *   GX_SetBankForOBJExtPltt  0x020801F8  arm
 *   GX_SetBankForTex  0x02080294  arm
 *   GX_SetBankForTexPltt  0x0208040C  arm
 *   GX_SetBankForClearImage  0x020804E8  arm
 *   GX_SetBankForSubBG  0x020806B0  arm
 *   GX_SetBankForSubOBJ  0x0208074C  arm
 *   GX_SetBankForSubBGExtPltt  0x020807BC  arm
 *   GX_SetBankForSubOBJExtPltt  0x0208083C  arm
 *   GX_SetBankForLCDC  0x0208068C  arm
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
extern int GX_DisableBankForSubBG(void);
extern int GX_DisableBankForSubOBJ(void);
extern void func_021D73BC(void);
extern void GX_SetBankForBG(int bg);
extern void GX_SetBankForOBJ(int obj);
extern void GX_SetBankForBGExtPltt(int bgExtPltt);
extern void GX_SetBankForOBJExtPltt(int objExtPltt);
extern void GX_SetBankForTex(int tex);
extern void GX_SetBankForTexPltt(int texPltt);
extern void GX_SetBankForClearImage(int clrImg);
extern void GX_SetBankForSubBG(int sub_bg);
extern void GX_SetBankForSubOBJ(int sub_obj);
extern void GX_SetBankForSubBGExtPltt(int sub_bgExtPltt);
extern void GX_SetBankForSubOBJExtPltt(int sub_objExtPltt);
extern void GX_SetBankForLCDC(int lcdc);
extern struct VRAMBANK gSubWork;

void DWCi_RepairVram(void)
{
	GX_DisableBankForBG();
	GX_DisableBankForOBJ();
	GX_DisableBankForSubBG();
	GX_DisableBankForSubOBJ();
	func_021D73BC();
	GX_SetBankForBG(gSubWork.bg);
	GX_SetBankForOBJ(gSubWork.obj);
	GX_SetBankForBGExtPltt(gSubWork.bgExt);
	GX_SetBankForOBJExtPltt(gSubWork.objExt);
	GX_SetBankForTex(gSubWork.tex);
	GX_SetBankForTexPltt(gSubWork.texPltt);
	GX_SetBankForClearImage(gSubWork.clrImg);
	GX_SetBankForSubBG(gSubWork.subBg);
	GX_SetBankForSubOBJ(gSubWork.subObj);
	GX_SetBankForSubBGExtPltt(gSubWork.subBgExt);
	GX_SetBankForSubOBJExtPltt(gSubWork.subObjExt);
	GX_SetBankForLCDC(gSubWork.lcdc);
	*(volatile unsigned short *)0x04000050 = 0;
	*(volatile unsigned short *)0x04001050 = 0;
	*(volatile unsigned int *)0x04000010 = 0;
	*(volatile unsigned int *)0x04000014 = 0;
	*(volatile unsigned int *)0x04000018 = 0;
	*(volatile unsigned int *)0x0400001c = 0;
	*(volatile unsigned int *)0x04001010 = 0;
	*(volatile unsigned int *)0x04001014 = 0;
	*(volatile unsigned int *)0x04001018 = 0;
	*(volatile unsigned int *)0x0400101c = 0;
}
