/*
 * file:     sub.c
 * unit:     yes
 * function: DWCi_ClearVram, DWCi_RepairVram, clearVram, DWCi_SetLedWireless, DWCi_SetLedNormal
 * address:  0x021D7274
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   gSubWork  0x021DE6B0  data
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
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   PM_GetLEDPattern  0x0208C6C0  arm
 *   PMi_SendLEDPatternCommand  0x0208C6A4  arm
 */
#include "../../matched/include/G_VRAMBANK.h"

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
extern void MIi_CpuClearFast(unsigned long data, void *destp, unsigned long size);
extern unsigned long PM_GetLEDPattern(int *patternBuf);
extern unsigned long PMi_SendLEDPatternCommand(unsigned int pattern);
void DWCi_ClearVram(void);
void DWCi_RepairVram(void);
void DWCi_SetLedWireless(void);
void DWCi_SetLedNormal(void);
extern struct VRAMBANK gSubWork;


/*
 * sdk:      DWCi_ClearVram (libdwcutil.TWL.HYB.a(sub.o))
 */

static void clearVram(void);
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
	clearVram();
}


void DWCi_RepairVram(void)
{
	GX_DisableBankForBG();
	GX_DisableBankForOBJ();
	GX_DisableBankForSubBG();
	GX_DisableBankForSubOBJ();
	clearVram();
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


/*
 * sdk:      clearVram (libdwcutil.TWL.HYB.a(sub.o))
 */
static void clearVram(void)
{
	GX_SetBankForLCDC(0x1f3);
	MIi_CpuClearFast(0, (void *)0x06800000, 0x40000);
	MIi_CpuClearFast(0, (void *)0x06880000, 0x24000);
	GX_DisableBankForLCDC();
	MIi_CpuClearFast(0x200, (void *)0x07000000, 0x400);
	MIi_CpuClearFast(0, (void *)0x05000000, 0x400);
	MIi_CpuClearFast(0x200, (void *)0x07000400, 0x400);
	MIi_CpuClearFast(0, (void *)0x05000400, 0x400);
}


/*
 * sdk:      DWCi_SetLedWireless (libdwcutil.TWL.HYB.a(sub.o))
 */
void DWCi_SetLedWireless(void)
{
	int pat;

	if (PM_GetLEDPattern(&pat) != 0)
		return;
	if (pat != 15)
		PMi_SendLEDPatternCommand(15);
}


void DWCi_SetLedNormal(void)
{
    PMi_SendLEDPatternCommand(1);
}
