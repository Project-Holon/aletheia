/*
 * function: procInit2
 * address:  0x021CE218
 * packet:   pkt_ov016_021CE1B0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   Choose                           0x021DE62C  data
 *   DWCi_ANIMElEnd                   0x021BC8EC  arm
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_BTNlEnd                     0x021BCAE4  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_BTNlIsEnd                   0x021BCB58  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_CMNlMsgDraw                 0x021BD29C  arm
 *   DWCi_CMNlStep                    0x021BD214  arm
 *   DWCi_COMMENTlDelete              0x021BD138  arm
 *   DWCi_COMMENTlDispEx              0x021BD060  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_FNTlDeleteBgLcd             0x021D5CA8  arm
 *   DWCi_GXlInvisible                0x021D6090  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_HLlLoad                     0x021BD674  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_SNDlStop                    0x021D0014  arm
 *   DWCi_SceneSetSelectAp            0x021CBC90  arm
 *   DWCi_SceneSetUsbComplete         0x021CDA88  arm
 *   DWCi_SceneSetUsbReady            0x021CDCAC  arm
 *   DWCi_SceneSetUsbReady1           0x021CE070  arm
 *   DWCi_SetParam_                   0x021C0E50  arm
 *   DWCi_USBAPlEnd                   0x021D0CEC  arm
 *   DWCi_USBAPlSetCallback           0x021D0DC8  arm
 *   DWCi_WINlEnd                     0x021D1524  arm
 *   DWCi_WINlGet                     0x021D1568  arm
 *   DWCi_WINlIsInit                  0x021D157C  arm
 *   button                           0x021CE28C  arm
 *   cbUsb                            0x021CE45C  arm
 *   endScene                         0x021CE2D4  arm
 *   endScene1                        0x021CE2F4  arm
 *   endScene2                        0x021CE364  arm
 *   procBoth                         0x021CE5B0  arm
 *   procBoth1                        0x021CE604  arm
 *   procConfirm1                     0x021CE590  arm
 *   procInit                         0x021CE1B0  arm
 *   procInit1                        0x021CE1EC  arm
 *   procInit2                        0x021CE218  arm
 *   procNotFound                     0x021CE564  arm
 *   procScene                        0x021CE23C  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetusbready), symbol procInit2 (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 * The archive holds two members whose names truncate to `scenesetusbready`; tools/sdkobj.py reads
 * only the first, so this second one (DWCi_SceneSetUsbReady1 and its steps) has no DWARF in reach:
 * names are the layout/symbols_sdk.txt rows, types are from the accesses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CE218.c \
 *       --func procInit2 --addr 0x021CE218 --region ov016 --cc 1.1p1 --arm --lang c99
 */
typedef _Bool bool;

extern void DWCi_HLlLoad(int idx);
extern bool DWCi_COMMENTlDispEx(int messageId, int n, int num);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_CMNlStep(int step);
extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_CMNlButton(int kind);
extern int DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_BTNlDisable(void);
extern bool DWCi_BTNlIsEnd(void);
extern void DWCi_BTNlEnd(void);
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern void DWCi_ChangeScene(void (*scene)());
extern void DWCi_SetParam_(void *param0, void *param1);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_SNDlStop(void);
extern int DWCi_WINlGet(void);
extern void DWCi_WINlEnd(void);
extern bool DWCi_WINlIsInit(void);
extern bool DWCi_USBAPlEnd(void);
extern void DWCi_USBAPlSetCallback(void (*callback)(int));
extern void DWCi_ANIMElEnd(void);
extern void DWCi_SceneSetSelectAp(void);
extern void DWCi_SceneSetUsbReady(void);
extern void DWCi_SceneSetUsbReady1(void);
extern void DWCi_SceneSetUsbComplete(void);

/* this member's .bss at 0x021DE62C: the choice that picks the next scene */
extern unsigned char Choose;

static void procInit(void);
static void procInit1(void);
static void procInit2(void);
static void procScene(void);
static void button(void);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);
static void cbUsb(int result);
static void procNotFound(void);
static void procConfirm1(void);
static void procBoth(void);
static void procBoth1(void);

static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}
