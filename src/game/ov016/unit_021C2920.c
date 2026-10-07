/*
 * file:     unit_021C2920.c
 * unit:     yes
 * function: func_021C2920, func_021C2948, func_021C2968, func_021C29C4
 * address:  0x021C2920
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
 *   DWCi_BTNlGet     0x021BCB14  arm
 *   DWCi_SNDlPlay    0x021CFFAC  arm
 *   DWCi_ChangeScene 0x021C0E40  arm
 *   DWCi_BTNlDisable 0x021BCB9C  arm
 *   DWCi_EFFlWait    0x021D5790  arm
 *   DWCi_EFFlCheck   0x021D5580  arm
 *   DWCi_BTNlEnd     0x021BCAE4  arm
 *   DWCi_EFFlFade    0x021D55A4  arm
 *   DWCi_BTNlIsEnd      0x021BCB58  arm
 *   DWCi_FNTlDeleteBgLcd 0x021D5CA8  arm
 *   DWCi_COMMENTlDelete 0x021BD138  arm
 *   DWCi_GXlInvisible   0x021D6090  arm
 *   DWCi_SetParam_      0x021C0E50  arm
 *   DWCi_SceneOptMenu   0x021C2A3C  arm
 */
int DWCi_BTNlGet(void);
void DWCi_SNDlPlay(int no);
void DWCi_ChangeScene(void (*scene)(void));
void DWCi_BTNlDisable(void);
int DWCi_EFFlWait(int frame);
int DWCi_EFFlCheck(int lcd);
void DWCi_BTNlEnd(void);
int DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
int DWCi_BTNlIsEnd(void);
void DWCi_FNTlDeleteBgLcd(int lcd);
int DWCi_COMMENTlDelete(void);
void DWCi_GXlInvisible(int lcd, int plane);
void DWCi_SetParam_(unsigned int param0, unsigned int param1);
void DWCi_SceneOptMenu(void);
void button(void);
void endScene(void);
void endScene1(void);
void endScene2(void);


void button(void)
{
    if (DWCi_BTNlGet() != 0) return;
    DWCi_SNDlPlay(7);
    DWCi_ChangeScene(endScene);
}


void endScene(void)
{
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene(endScene1);
}


void endScene1(void)
{
    if (DWCi_EFFlCheck(1)) return;
    DWCi_BTNlEnd();
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x15, 8);
    DWCi_ChangeScene(endScene2);
}


void endScene2(void)
{
    if (DWCi_EFFlCheck(1)) return;
    if (DWCi_EFFlCheck(0)) return;
    if (!DWCi_BTNlIsEnd()) return;
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_COMMENTlDelete();
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x15);
    DWCi_SetParam_(0, 1);
    DWCi_ChangeScene(DWCi_SceneOptMenu);
}
