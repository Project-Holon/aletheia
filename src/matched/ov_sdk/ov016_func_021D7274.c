/*
 * function: func_021D7274
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
 *   g_021DE6B0  0x021DE6B0  data
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
extern struct VRAMBANK g_021DE6B0;

void func_021D7274(void)
{
	g_021DE6B0.bg = GX_DisableBankForBG();
	g_021DE6B0.obj = GX_DisableBankForOBJ();
	g_021DE6B0.bgExt = GX_DisableBankForBGExtPltt();
	g_021DE6B0.objExt = GX_DisableBankForOBJExtPltt();
	g_021DE6B0.tex = GX_DisableBankForTex();
	g_021DE6B0.texPltt = GX_DisableBankForTexPltt();
	g_021DE6B0.clrImg = GX_DisableBankForClearImage();
	g_021DE6B0.subBg = GX_DisableBankForSubBG();
	g_021DE6B0.subObj = GX_DisableBankForSubOBJ();
	g_021DE6B0.subBgExt = GX_DisableBankForSubBGExtPltt();
	g_021DE6B0.subObjExt = GX_DisableBankForSubOBJExtPltt();
	g_021DE6B0.arm7 = GX_DisableBankForARM7();
	g_021DE6B0.lcdc = GX_DisableBankForLCDC();
	GX_SetBankForARM7(g_021DE6B0.arm7);
	func_021D73BC();
}
