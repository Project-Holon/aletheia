/*
 * function: func_021C4890
 * address:  0x021C4890
 * packet:   pkt_ov016_021C4890
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      cbMov (libdwcutil.TWL.HYB.a sceneoptmovwait.o)
 *
 * symbols:
 *   DWCi_SNDlStop  0x021D0014  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_MOVlChangeCallback  0x021C11D4  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   gSceneOptMovWaitWork     0x021DE5C8  data
 *   func_021C46DC  0x021C46DC  arm  ov016
 */

extern void DWCi_SNDlStop();
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_MOVlChangeCallback(unsigned int v);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C46DC();
extern unsigned char gSceneOptMovWaitWork;

void func_021C4890(int state)
{
    DWCi_SNDlStop();
    if (state == 0) {
        gSceneOptMovWaitWork = 1;
        DWCi_SNDlPlay(0x10);
    } else {
        gSceneOptMovWaitWork = 2;
        DWCi_SNDlPlay(0x12);
    }
    DWCi_MOVlChangeCallback(0);
    DWCi_ChangeScene((unsigned int)func_021C46DC);
}
