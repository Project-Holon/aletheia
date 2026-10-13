/*
 * function: func_021CDB48
 * address:  0x021CDB48
 * packet:   pkt_ov016_021CDB48
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procInit (libdwcutil.TWL.HYB.a scenesetusbcompl)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CDB48.c \n *       --func func_021CDB48 --addr 0x021CDB48 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   DWCi_EFFlFade  0x021D55A4  arm  ov016
 *   DWCi_GXlVisible  0x021D603C  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   func_021CDB84  0x021CDB84  arm  ov016
 */

extern int DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021CDB84(void);

void func_021CDB48(void)
{
    DWCi_EFFlFade(2, 0, 21, 8);
    DWCi_GXlVisible(0, 21);
    DWCi_ChangeScene((unsigned int)func_021CDB84);
}
