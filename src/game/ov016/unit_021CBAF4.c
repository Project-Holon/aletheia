/*
 * file:     unit_021CBAF4.c
 * function: endScene
 * address:  0x021CBAF4
 * packet:   pkt_ov016_021CBAF4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene (scenesetrakubutt.o), TwlDWC libdwcutil.TWL.HYB.a
 *
 * symbols:
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   endScene1                        0x021CBB14  arm
 */
typedef _Bool bool;

extern void DWCi_BTNlDisable(void);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_ChangeScene(void (*scene)());

static void endScene1(void);

static void endScene(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}
