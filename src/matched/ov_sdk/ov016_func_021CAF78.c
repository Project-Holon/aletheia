/*
 * function: checkRaku
 * address:  0x021CAF78
 * packet:   pkt_ov016_021CAF78
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_RAKUlGetState               0x021c1518 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   DWCi_SNDlStop                    0x021d0014 arm
 *   DWCi_RAKUlSetResult              0x021c15d0 arm
 *   DWCi_SNDlPlay                    0x021cffac arm
 *   DWCi_WINlInitEx                  0x021d1208 arm
 *   DWCi_BTNlDisable                 0x021bcb9c arm
 *   Choose                           0x021de5fc data
 *   endScene                         0x021cae34 arm
 *   procError                        0x021cb05c arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetrakubutt), symbol checkRaku (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CAF78.c \
 *       --func checkRaku --addr 0x021CAF78 --region ov016 --cc 1.1p1 --arm --lang c99
 */

typedef _Bool bool;

extern int DWCi_RAKUlGetState(void);
extern void DWCi_ChangeScene(void (*scene)());
extern void DWCi_SNDlStop(void);
extern void DWCi_RAKUlSetResult(void);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_WINlInitEx(int msg, int type, bool dark, int n, int num);
extern void DWCi_BTNlDisable(void);
extern unsigned char Choose;

static void endScene(void);
static void procError(void);

static void checkRaku(void)
{
    switch (DWCi_RAKUlGetState()) {
    case 3:
        Choose = 1;
        DWCi_SNDlStop();
        DWCi_RAKUlSetResult();
        DWCi_ChangeScene(endScene);
        break;
    case 4:
        Choose = 0;
        DWCi_SNDlStop();
        DWCi_SNDlPlay(9);
        DWCi_WINlInitEx(0xd, 1, 1, -1, 0);
        DWCi_BTNlDisable();
        DWCi_ChangeScene(procError);
        break;
    case 5:
        Choose = 0;
        DWCi_SNDlStop();
        DWCi_SNDlPlay(0x12);
        DWCi_WINlInitEx(0xe, 1, 1, -1, 0);
        DWCi_BTNlDisable();
        DWCi_ChangeScene(procError);
        break;
    }
}
