/*
 * function: DWCi_SceneSetRakuReady
 * address:  0x021CB2E8
 * packet:   pkt_ov016_021CB2E8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   initGraphics                     0x021cb344 arm
 *   DWCi_HLlLoadSet                  0x021bd6d4 arm
 *   DWCi_COMMENTlDispEx              0x021bd060 arm
 *   DWCi_CMNlStep                    0x021bd214 arm
 *   DWCi_CMNlMsgDraw                 0x021bd29c arm
 *   DWCi_ANIMElInitEx                0x021bc820 arm
 *   DWCi_SNDlPlay                    0x021cffac arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   Choose                           0x021de604 data
 *   procInit                         0x021cb3ec arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetrakuread), symbol DWCi_SceneSetRakuReady (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CB2E8.c \
 *       --func DWCi_SceneSetRakuReady --addr 0x021CB2E8 --region ov016 --cc 1.1p1 --arm --lang c99
 */

typedef _Bool bool;

extern void DWCi_HLlLoadSet(void);
extern bool DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern void DWCi_CMNlStep(int step);
extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_ANIMElInitEx(int color);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_ChangeScene(void (*scene)());
extern unsigned char Choose;

static void initGraphics(void);
static void procInit(void);

void DWCi_SceneSetRakuReady(void)
{
    Choose = 0;
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_COMMENTlDispEx(0x37, -1, 0);
    DWCi_CMNlStep(2);
    DWCi_CMNlMsgDraw(0x24);
    DWCi_ANIMElInitEx(0);
    DWCi_SNDlPlay(0xb);
    DWCi_ChangeScene(procInit);
}
