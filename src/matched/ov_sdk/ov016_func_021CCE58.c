/*
 * function: func_021CCE58
 * address:  0x021CCE58
 * packet:   pkt_ov016_021CCE58
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene (libdwcutil.TWL.HYB.a scenesetselectwa)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CCE58.c \n *       --func func_021CCE58 --addr 0x021CCE58 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   DWCi_BTNlDisable  0x021BCB9C  arm  ov016
 *   DWCi_EFFlWait  0x021D5790  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   func_021CCE78  0x021CCE78  arm  ov016
 */

extern void DWCi_BTNlDisable(void);
extern int DWCi_EFFlWait(int frame);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021CCE78(void);

void func_021CCE58(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene((unsigned int)func_021CCE78);
}
