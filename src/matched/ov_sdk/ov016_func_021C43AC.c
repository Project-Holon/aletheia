/*
 * function: endScene1
 * address:  0x021C43AC
 * packet:   pkt_ov016_021C43AC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene1 (sceneoptmovuser.o), TwlDWC libdwcutil.TWL.HYB.a
 *
 * symbols:
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_MOVlAdmitChild              0x021C11EC  arm
 *   DWCi_MOVlEnd                     0x021C115C  arm
 *   Error                            0x021DE5C4  data
 *   endScene2                        0x021C4408  arm
 */
typedef _Bool bool;

static void endScene2(void);
extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_MOVlAdmitChild();
extern void DWCi_MOVlEnd(void);
extern void DWCi_ChangeScene(void (*scene)());
extern unsigned char Error[];

static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    if (Error[0] == 0 && Error[1] == 1)
        DWCi_MOVlAdmitChild();
    else
        DWCi_MOVlEnd();
    DWCi_ChangeScene(endScene2);
}
