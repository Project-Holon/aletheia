/*
 * function: func_021CD4F4
 * address:  0x021CD4F4
 * packet:   pkt_ov016_021CD4F4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      taskAc (libdwcutil.TWL.HYB.a scenesettest.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD4F4.c \n *       --func func_021CD4F4 --addr 0x021CD4F4 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   DWC_AC_Process  0x0205BC78  arm
 *   DWCi_ICONlEnd  0x021BD7F4  arm  ov016
 *   DWCi_SNDlStop  0x021D0014  arm  ov016
 *   DWC_AC_GetStatus  0x0205BD64  arm
 *   DWCi_SetErrorCode  0x021C82EC  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_TSKlDelete  0x021D7724  arm  ov016
 *   gSceneSetTestWork     0x021DE61C  data
 *   func_021CD40C  0x021CD40C  arm  ov016
 */

extern int DWC_AC_Process(void);
extern void DWCi_ICONlEnd(void);
extern void DWCi_SNDlStop(void);
extern int DWC_AC_GetStatus(void);
extern void DWCi_SetErrorCode(unsigned int v);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_TSKlDelete(int kind, void *task);
extern unsigned char gSceneSetTestWork;
extern void func_021CD40C(void);

void func_021CD4F4(void *task)
{
    int rs = DWC_AC_Process();
    if (rs == 0)
        return;
    DWCi_ICONlEnd();
    DWCi_SNDlStop();
    if (rs > 0) {
        gSceneSetTestWork = 1;
        DWCi_SNDlPlay(17);
    } else {
        DWCi_SetErrorCode(DWC_AC_GetStatus());
        DWCi_SNDlPlay(18);
    }
    DWCi_ChangeScene((unsigned int)func_021CD40C);
    DWCi_TSKlDelete(0, task);
}
