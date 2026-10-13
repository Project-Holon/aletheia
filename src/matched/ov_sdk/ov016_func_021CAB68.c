/*
 * function: func_021CAB68
 * address:  0x021CAB68
 * packet:   pkt_ov016_021CAB68
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      checkRaku (libdwcutil.TWL.HYB.a(scenesetrakubutt))
 * symbols:
 *   DWCi_RAKUlGetState  0x021C1518  arm
 *   DWCi_ChangeScene  0x021C0E40  arm
 *   DWCi_SNDlStop  0x021D0014  arm
 *   DWCi_SNDlPlay  0x021CFFAC  arm
 *   DWCi_WINlInitEx  0x021D1208  arm
 *   DWCi_BTNlDisable  0x021BCB9C  arm
 *   func_021CAA08  0x021CAA08  arm
 *   func_021CABF8  0x021CABF8  arm
 *   gSceneSetRakuButtonWork  0x021DE5F8  data  a1
 */
extern int DWCi_RAKUlGetState(void);
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_SNDlStop(void);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_WINlInitEx(int msg, int type, unsigned char dark, int n, int num);
extern void DWCi_BTNlDisable(void);
extern void func_021CAA08(void);
extern void func_021CABF8(void);
extern unsigned char gSceneSetRakuButtonWork;

void func_021CAB68(void)
{
    switch (DWCi_RAKUlGetState()) {
    case 2:
        gSceneSetRakuButtonWork = 1;
        DWCi_ChangeScene((unsigned int)func_021CAA08);
        break;
    case 4:
        gSceneSetRakuButtonWork = 0;
        DWCi_SNDlStop();
        DWCi_SNDlPlay(9);
        DWCi_WINlInitEx(13, 1, 1, -1, 0);
        DWCi_BTNlDisable();
        DWCi_ChangeScene((unsigned int)func_021CABF8);
        break;
    }
}
