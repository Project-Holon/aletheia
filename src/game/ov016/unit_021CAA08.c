/*
 * file:     unit_021CAA08.c
 * unit:     yes
 * function: func_021CAA08, func_021CAA28, func_021CAA9C, func_021CAB68, func_021CABF8
 * address:  0x021CAA08
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
 *   DWCi_EFFlWait                    0x021D5790  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   DWCi_EFFlCheck                   0x021D5580  arm
 *   DWCi_BTNlEnd                     0x021BCAE4  arm
 *   DWCi_EFFlFade                    0x021D55A4  arm
 *   Choose                           0x021DE5F8  data
 *   DWCi_BTNlIsEnd                   0x021bcb58 arm
 *   DWCi_ANIMElEnd                   0x021bc8ec arm
 *   DWCi_FNTlDeleteBgLcd             0x021d5ca8 arm
 *   DWCi_COMMENTlDelete              0x021bd138 arm
 *   DWCi_GXlInvisible                0x021d6090 arm
 *   DWCi_RAKUlEnd                    0x021c14f4 arm
 *   DWCi_SetParam_                   0x021c0e50 arm
 *   DWCi_SceneSetSelectWay           0x021cc998 arm
 *   DWCi_SceneSetRakuButton1         0x021cac64 arm
 *   func_021C1518  0x021C1518  arm
 *   func_021C0E40  0x021C0E40  arm
 *   func_021D0014  0x021D0014  arm
 *   func_021CFFAC  0x021CFFAC  arm
 *   func_021D1208  0x021D1208  arm
 *   func_021BCB9C  0x021BCB9C  arm
 *   func_021CAA08  0x021CAA08  arm
 *   func_021CABF8  0x021CABF8  arm
 *   g_021DE5F8  0x021DE5F8  data  a1
 *   DWCi_WINlGet     0x021D1568 arm
 *   DWCi_SNDlPlay    0x021CFFAC arm
 *   DWCi_WINlEnd     0x021D1524 arm
 *   procError1       0x021CAC24 arm
 */
typedef _Bool bool;

extern void DWCi_BTNlDisable(void);
extern bool DWCi_EFFlWait(int frame);
extern void DWCi_ChangeScene(void (*scene)());
extern bool DWCi_EFFlCheck(int lcd);
extern void DWCi_BTNlEnd(void);
extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern bool DWCi_BTNlIsEnd(void);
extern void DWCi_ANIMElEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_RAKUlEnd(void);
extern void DWCi_SetParam_(void *param0, void *param1);
extern void DWCi_SceneSetSelectWay(void);
extern void DWCi_SceneSetRakuButton1(void);
extern int func_021C1518(void);
extern void func_021C0E40(unsigned int v);
extern void func_021D0014(void);
extern void func_021CFFAC(unsigned int v);
extern void func_021D1208(int msg, int type, unsigned char dark, int n, int num);
extern void func_021BCB9C(void);
extern void func_021CAA08(void);
extern void func_021CABF8(void);
int DWCi_WINlGet(void);
void DWCi_SNDlPlay(int no);
void DWCi_WINlEnd(void);
void procError1(void);
void func_021CAB68(void);
void procError(void);
extern unsigned char Choose;
extern unsigned char g_021DE5F8;


static void endScene1(void);


static void endScene(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}


static void endScene2(void);


static void endScene1(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (Choose == 0)
        DWCi_BTNlEnd();
    if (Choose == 0)
        DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene(endScene2);
}


static void endScene2(void)
{
    if (DWCi_EFFlCheck(0)) {
        return;
    }
    if (Choose == 0) {
        if (DWCi_EFFlCheck(1)) {
            return;
        }
    }
    if (!DWCi_BTNlIsEnd()) {
        return;
    }
    DWCi_ANIMElEnd();
    DWCi_FNTlDeleteBgLcd(0);
    if (Choose == 0) {
        DWCi_COMMENTlDelete();
        DWCi_GXlInvisible(1, 1);
    }
    DWCi_GXlInvisible(0, 0x15);
    if (Choose == 0) {
        DWCi_RAKUlEnd();
        DWCi_SetParam_((void *)2, (void *)1);
        DWCi_ChangeScene(DWCi_SceneSetSelectWay);
    } else {
        DWCi_SetParam_(0, 0);
        DWCi_ChangeScene(DWCi_SceneSetRakuButton1);
    }
}


/*
 * sdk:      checkRaku (libdwcutil.TWL.HYB.a(scenesetrakubutt))
 */
void func_021CAB68(void)
{
    switch (func_021C1518()) {
    case 2:
        g_021DE5F8 = 1;
        func_021C0E40((unsigned int)func_021CAA08);
        break;
    case 4:
        g_021DE5F8 = 0;
        func_021D0014();
        func_021CFFAC(9);
        func_021D1208(13, 1, 1, -1, 0);
        func_021BCB9C();
        func_021C0E40((unsigned int)func_021CABF8);
        break;
    }
}


void procError(void)
{
    if (DWCi_WINlGet() == 0) {
        DWCi_SNDlPlay(6);
        DWCi_WINlEnd();
        DWCi_ChangeScene(procError1);
    }
}
