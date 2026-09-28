/*
 * function: endScene
 * address:  0x021C4350
 * packet:   pkt_ov016_021C4350
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene (sceneoptmovuser.o), TwlDWC libdwcutil.TWL.HYB.a
 *
 * symbols:
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   Error                            0x021DE5C4  data
 *   endScene1                        0x021C43AC  arm
 */
typedef _Bool bool;

static void endScene1(void);
extern bool DWCi_WINlIsInit(void);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_ChangeScene(void (*scene)());
extern unsigned char Error[];

static void endScene(void)
{
    if (DWCi_WINlIsInit())
        return;
    if (Error[1] == 0)
        DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene(endScene1);
}
