/*
 * file:     unit_021CBB14.c
 * function: endScene1
 * address:  0x021CBB14
 * packet:   pkt_ov016_021CBB14
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene1 (sceneoptinfo.o), TwlDWC libdwcutil.TWL.HYB.a
 *
 * symbols:
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_BTNlEnd                     0x021BCAE4  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   endScene2                        0x021CBB70  arm
 */
typedef _Bool bool;

extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_BTNlEnd(void);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_ChangeScene(void (*scene)());

static void endScene2(void);

static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    DWCi_BTNlEnd();
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene(endScene2);
}
