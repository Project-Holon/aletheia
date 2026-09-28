/*
 * function: DWCi_SceneOptMovWait
 * address:  0x021C450C
 * packet:   pkt_ov016_021C450C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MOVlInit                    0x021C1074  arm
 *   initGraphics                     0x021C4558  arm
 *   DWCi_CMNlMsgDraw                 0x021BD29C  arm
 *   DWCi_ANIMElInitEx                0x021BC820  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   cbMov                            0x021C4890  arm
 *   Choose                           0x021DE5C8  data
 *   procInit                         0x021C45D8  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneoptmovwait.o), symbol DWCi_SceneOptMovWait (name and
 * prototype from the vendor object DWARF). Callee of endScene2 (sceneoptmovconfi). The object
 * is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build writes, so 1.1p1.
 */

extern void DWCi_MOVlInit(void (*callback)(int));
extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_ANIMElInitEx(int color);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_ChangeScene(void (*scene)());
extern unsigned char Choose;

static void cbMov(int state);
static void initGraphics(void);
static void procInit(void);

void DWCi_SceneOptMovWait(void)
{
    DWCi_MOVlInit(cbMov);
    Choose = 0;
    initGraphics();
    DWCi_CMNlMsgDraw(0x1c);
    DWCi_ANIMElInitEx(0);
    DWCi_SNDlPlay(0xb);
    DWCi_ChangeScene(procInit);
}
