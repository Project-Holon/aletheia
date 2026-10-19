/*
 * function: endScene1
 * address:  0x021CD434
 * packet:   pkt_ov016_021CD434
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
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD434.c \n *       --func endScene1 --addr 0x021CD434 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   DWCi_EFFlCheck  0x021D5580  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   func_021CD458  0x021CD458  arm  ov016
 */

extern int DWCi_EFFlCheck(int lcd);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021CD458(void);

void endScene1(void)
{
    if (DWCi_EFFlCheck(0))
        return;
    DWCi_ChangeScene((unsigned int)func_021CD458);
}
