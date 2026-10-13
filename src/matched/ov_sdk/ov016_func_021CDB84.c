/*
 * function: func_021CDB84
 * address:  0x021CDB84
 * packet:   pkt_ov016_021CDB84
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a scenesettest.o)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CDB84.c \n *       --func func_021CDB84 --addr 0x021CDB84 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   func_021D5580  0x021D5580  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   DWCi_SceneSetUsbCompleteCallback  0x021CDBA8  arm  ov016
 */

extern int func_021D5580(int lcd);
extern void func_021C0E40(unsigned int v);
extern void DWCi_SceneSetUsbCompleteCallback(void);

void func_021CDB84(void)
{
    if (func_021D5580(0))
        return;
    func_021C0E40((unsigned int)DWCi_SceneSetUsbCompleteCallback);
}
