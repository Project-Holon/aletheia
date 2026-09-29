/*
 * function: DWCi_SceneSetRakuComplete
 * address:  0x021CB0A8
 * packet:   pkt_ov016_021CB0A8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   initGraphics                     0x021cb0e4 arm
 *   DWCi_HLlLoadSet                  0x021bd6d4 arm
 *   DWCi_CMNlMsgDraw                 0x021bd29c arm
 *   DWCi_SNDlPlay                    0x021cffac arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   Count                            0x021de600 data
 *   procInit                         0x021cb164 arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetrakucomp), symbol DWCi_SceneSetRakuComplete (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CB0A8.c \
 *       --func DWCi_SceneSetRakuComplete --addr 0x021CB0A8 --region ov016 --cc 1.1p1 --arm --lang c99
 */

extern void DWCi_HLlLoadSet(void);
extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_ChangeScene(void (*scene)());
extern unsigned char Count;

static void initGraphics(void);
static void procInit(void);

void DWCi_SceneSetRakuComplete(void)
{
    Count = 0;
    initGraphics();
    DWCi_HLlLoadSet();
    DWCi_CMNlMsgDraw(0x26);
    DWCi_SNDlPlay(0x10);
    DWCi_ChangeScene(procInit);
}
