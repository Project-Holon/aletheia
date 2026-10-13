/*
 * function: func_021CE45C
 * address:  0x021CE45C
 * packet:   pkt_ov016_021CE45C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      cbUsb (libdwcutil.TWL.HYB.a scenesetusbready)
 *
 * symbols:
 *   DWCi_SNDlStop  0x021D0014  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_WINlInitEx  0x021D1208  arm  ov016
 *   DWCi_BTNlDisable  0x021BCB9C  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_USBAPlSetCallback  0x021D0DC8  arm  ov016
 *   func_021CE564  0x021CE564  arm  ov016
 *   func_021CE2D4  0x021CE2D4  arm  ov016
 *   func_021CE5B0  0x021CE5B0  arm  ov016
 *   gSceneSetUsbReady1Work  0x021DE62C  data
 */

extern void DWCi_SNDlStop(void);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_WINlInitEx(int msg, int type, unsigned char dark, int n, int num);
extern void DWCi_BTNlDisable(void);
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_USBAPlSetCallback(unsigned int v);
extern void func_021CE564(void);
extern void func_021CE2D4(void);
extern void func_021CE5B0(void);
extern unsigned char gSceneSetUsbReady1Work;

void func_021CE45C(int state)
{
    if (gSceneSetUsbReady1Work != 0)
        return;
    switch (state) {
    case 0:
        gSceneSetUsbReady1Work = 3;
        DWCi_SNDlStop();
        DWCi_SNDlPlay(0x12);
        DWCi_WINlInitEx(0x10, 1, 1, -1, 0);
        DWCi_BTNlDisable();
        DWCi_ChangeScene((unsigned int)func_021CE564);
        break;
    case 1:
        gSceneSetUsbReady1Work = 1;
        DWCi_SNDlStop();
        DWCi_ChangeScene((unsigned int)func_021CE2D4);
        break;
    case 2:
        DWCi_SNDlStop();
        DWCi_USBAPlSetCallback(0);
        DWCi_WINlInitEx(0x11, 0, 1, -1, 0);
        DWCi_BTNlDisable();
        DWCi_ChangeScene((unsigned int)func_021CE5B0);
        break;
    case 3:
        gSceneSetUsbReady1Work = 2;
        DWCi_SNDlStop();
        DWCi_SNDlPlay(9);
        DWCi_ChangeScene((unsigned int)func_021CE2D4);
        break;
    }
}
