/*
 * function: endScene1
 * address:  0x021C4714
 * packet:   pkt_021C4714
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EFFlCheck  0x021D5580  arm
 *   DWCi_MOVlIsEnd  0x021C11B8  arm
 *   DWCi_BTNlEnd  0x021BCAE4  arm
 *   DWCi_EFFlFade  0x021D55A4  arm
 *   DWCi_ChangeScene  0x021C0E40  arm
 *   func_021C4794  0x021C4794  arm
 *   gSceneOptMovWaitWork     0x021DE5C8  data
 */

typedef unsigned char u8;

extern int  DWCi_EFFlCheck(int x);
extern int  DWCi_MOVlIsEnd(void);
extern void DWCi_BTNlEnd(void);
extern void DWCi_EFFlFade(int a, int b, int c, int d);
extern void DWCi_ChangeScene(unsigned int v);
extern void func_021C4794(void);
extern u8   gSceneOptMovWaitWork[];

void endScene1(void)
{
    if (DWCi_EFFlCheck(1) != 0)
        return;
    if (gSceneOptMovWaitWork[0] == 0) {
        if (DWCi_MOVlIsEnd() == 0)
            return;
    }
    DWCi_BTNlEnd();
    if (gSceneOptMovWaitWork[0] == 0)
        DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene((unsigned int)func_021C4794);
}
