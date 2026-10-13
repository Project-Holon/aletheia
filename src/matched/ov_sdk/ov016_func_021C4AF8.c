/*
 * function: func_021C4AF8
 * address:  0x021C4AF8
 * packet:   pkt_ov016_021C4AF8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procScene (libdwcutil.TWL.HYB.a scenesetaossbutton.o)
 *
 * symbols:
 *   func_021C4BDC  0x021C4BDC  arm  ov016
 *   DWCi_SceneSetAossButton_draw  0x021C4C14  arm  ov016
 *   func_021C4C18  0x021C4C18  arm  ov016
 *   DWCi_AOSSlStart  0x021C0900  arm  ov016
 *   DWCi_TSKlDeleteByIndex  0x021D7744  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_SNDlStop  0x021D0014  arm  ov016
 *   DWCi_WINlInitEx  0x021D1208  arm  ov016
 *   DWCi_SNDlPlay  0x021CFFAC  arm  ov016
 *   DWCi_BTNlDisable  0x021BCB9C  arm  ov016
 *   gSceneSetAossButtonWork     0x021DE5CC  data
 *   func_021C4E4C  0x021C4E4C  arm  ov016
 *   func_021C4E00  0x021C4E00  arm  ov016
 */

#include "../include/G_SCENESETAOSSBUTT_BSS.h"

typedef struct Choose {
    unsigned char way;
    void *task;
} Choose;

extern void func_021C4BDC();
extern void DWCi_SceneSetAossButton_draw();
extern void func_021C4C18();
extern int DWCi_AOSSlStart();
extern void DWCi_TSKlDeleteByIndex(unsigned int idx, void *r4);
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_SNDlStop();
extern void DWCi_WINlInitEx(int msg, int type, unsigned char dark, int n, int num);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_BTNlDisable();
extern void func_021C4E4C();
extern void func_021C4E00();
extern struct SCENESETAOSSBUTT_BSS gSceneSetAossButtonWork;

void func_021C4AF8(void)
{
    func_021C4BDC();
    DWCi_SceneSetAossButton_draw();
    func_021C4C18();
    switch (DWCi_AOSSlStart()) {
    case 0:
        return;
    case 1:
        if (gSceneSetAossButtonWork.Task == 0)
            return;
        gSceneSetAossButtonWork.Choose = 1;
        DWCi_TSKlDeleteByIndex(1, gSceneSetAossButtonWork.Task);
        gSceneSetAossButtonWork.Task = 0;
        DWCi_ChangeScene((unsigned int)func_021C4E4C);
        return;
    case 2:
        if (gSceneSetAossButtonWork.Task == 0)
            return;
        DWCi_SNDlStop();
        DWCi_WINlInitEx(0xC, 1, 1, -1, 0);
        DWCi_SNDlPlay(9);
        DWCi_BTNlDisable();
        DWCi_TSKlDeleteByIndex(1, gSceneSetAossButtonWork.Task);
        gSceneSetAossButtonWork.Task = 0;
        DWCi_ChangeScene((unsigned int)func_021C4E00);
        return;
    }
}
