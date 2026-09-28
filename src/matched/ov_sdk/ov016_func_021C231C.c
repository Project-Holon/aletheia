/*
 * function: DWCi_SceneOptErase1
 * address:  0x021C231C
 * packet:   pkt_ov016_021C231C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_BTNlDisable                 0x021BCB9C  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_CMNlButton                  0x021BD264  arm
 *   DWCi_CMNlMsgDraw                 0x021BD29C  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_GXlVisible                  0x021D603C  arm
 *   DWCi_SETTINGlEraseAll            0x021CFC20  arm
 *   DWCi_SNDlPlay                    0x021CFFAC  arm
 *   DWCi_SceneOptErase1              0x021C231C  arm
 *   button                           0x021C2484  arm
 *   endScene                         0x021C24AC  arm
 *   endScene1                        0x021C24CC  arm
 *   endScene2                        0x021C2528  arm
 *   initGraphics                     0x021C2340  arm
 *   procInit                         0x021C23C0  arm
 *   procInit1                        0x021C23FC  arm
 *   procInit2                        0x021C2428  arm
 *   procScene                        0x021C244C  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneopterase1.o), symbol DWCi_SceneOptErase1 (name and prototype from the
 * vendor object DWARF). The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which
 * no tools/mwccarm build writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021C231C.c \
 *       --func DWCi_SceneOptErase1 --addr 0x021C231C --region ov016 --cc 1.1p1 --arm --lang c99
 */
typedef _Bool bool;

extern void DWCi_CMNlMsgDraw(int msgId);
extern void DWCi_SETTINGlEraseAll(void);
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_GXlVisible(int lcd, int plane);
extern void DWCi_ChangeScene(void (*scene)());
extern void DWCi_CMNlButton(int kind);
extern int DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_BTNlDisable(void);
extern void DWCi_SNDlPlay(int no);

static void initGraphics(void);
static void procInit(void);
static void procInit1(void);
static void procInit2(void);
static void procScene(void);
static void button(void);
static void endScene(void);
static void endScene1(void);
static void endScene2(void);

void DWCi_SceneOptErase1(void)
{
    initGraphics();
    DWCi_CMNlMsgDraw(0x19);
    DWCi_SETTINGlEraseAll();
    DWCi_ChangeScene(procInit);
}
