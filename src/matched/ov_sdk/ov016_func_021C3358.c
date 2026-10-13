/*
 * function: func_021C3358
 * address:  0x021C3358
 * packet:   pkt_ov016_021C3358
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      cbMov (libdwcutil.TWL.HYB.a(sceneoptmovcomm.o))
 *
 * symbols:
 *   DWCi_SETTINGlEraseAll  0x021CFC20  arm  ov016
 *   DWCi_SNDlStop  0x021D0014  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_MOVlChangeCallback  0x021C11D4  arm  ov016
 *   DWCi_MOVlEnd  0x021C115C  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gSceneOptMovCommWork  0x021DE5B4  data
 *   func_021C3298  0x021C3298  arm  ov016
 */

extern void DWCi_SETTINGlEraseAll(void);
extern void DWCi_SNDlStop(void);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_MOVlChangeCallback(unsigned int v);
extern void DWCi_MOVlEnd(void);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C3298(void);
extern unsigned char gSceneOptMovCommWork;

void func_021C3358(int state)
{
	if (state == 2) {
		DWCi_SETTINGlEraseAll();
		gSceneOptMovCommWork = 1;
		DWCi_SNDlStop();
		DWCi_SNDlPlay(0x10);
	} else if (state == 3) {
		gSceneOptMovCommWork = 2;
		DWCi_SNDlStop();
		DWCi_SNDlPlay(0x12);
	} else {
		gSceneOptMovCommWork = 0;
		DWCi_SNDlStop();
		DWCi_SNDlPlay(0x12);
	}
	DWCi_MOVlChangeCallback(0);
	DWCi_MOVlEnd();
	DWCi_ChangeScene((unsigned int)func_021C3298);
}
