/*
 * function: procScene
 * address:  0x021C42E0
 * packet:   pkt_ov016_021C42E0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procScene (sceneoptmovuser.o), TwlDWC libdwcutil.TWL.HYB.a
 *
 * symbols:
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_MOVlChangeCallback          0x021C11D4  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   DWCi_WINlGet                     0x021D1568  arm
 *   Error                            0x021DE5C4  data
 *   draw                             0x021C434C  arm
 *   endScene                         0x021C4350  arm
 *   input                            0x021C4348  arm
 */

static void input(void);
static void draw(void);
static void endScene(void);
extern int DWCi_WINlGet(void);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_MOVlChangeCallback(void (*callback)(int));
extern void DWCi_WINlEnd(void);
extern void DWCi_ChangeScene(void (*scene)());
extern unsigned char Error[];

static void procScene(void)
{
    input();
    draw();
    switch (DWCi_WINlGet()) {
    case 0:
        Error[1] = 0;
        DWCi_SNDlPlay(7);
        break;
    case 1:
        Error[1] = 1;
        DWCi_SNDlPlay(0xe);
        break;
    default:
        return;
    }
    DWCi_MOVlChangeCallback(0);
    DWCi_WINlEnd();
    DWCi_ChangeScene(endScene);
}
