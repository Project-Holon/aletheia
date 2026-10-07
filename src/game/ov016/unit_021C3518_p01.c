/*
 * file:     unit_021C3518_p01.c
 * unit:     yes
 * function: func_021C3560, func_021C35BC
 * address:  0x021C3560
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   endScene2                        0x021C35BC  arm
 *   initGraphics                     0x021C2340  arm
 *   procInit                         0x021C23C0  arm
 *   procInit1                        0x021C23FC  arm
 *   procInit2                        0x021C2428  arm
 *   procScene                        0x021C244C  arm
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
extern int func_021D5580(int);
extern void func_02087A04(int);
extern void func_0208BEA4(void);
void func_021C35BC(void);


static void initGraphics(void);

static void procInit(void);

static void procInit1(void);

static void procInit2(void);

static void procScene(void);

static void button(void);

static void endScene(void);

static void endScene1(void);

static void endScene2(void);


static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    DWCi_EFFlFade(3, 1, 0x3F, 0x40);
    DWCi_EFFlFade(3, 0, 0x3F, 0x40);
    DWCi_ChangeScene(endScene2);
}


/*
 * Bail out on two func_021D5580 probes, then arm timer 0x800000 and kick func_0208BEA4.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C35BC.c \
 *       --func func_021C35BC --addr 0x021C35BC --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021C35BC(void)
{
    if (func_021D5580(1))
        return;
    if (func_021D5580(0))
        return;
    func_02087A04(0x800000);
    func_0208BEA4();
}
