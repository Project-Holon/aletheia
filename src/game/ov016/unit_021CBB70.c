/*
 * file:     unit_021CBB70.c
 * unit:     yes
 * function: func_021CBB70, func_021CBC44
 * address:  0x021CBB70
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
 *   DWCi_EFFlCheck                   0x021d5580 arm
 *   DWCi_BTNlIsEnd                   0x021bcb58 arm
 *   DWCi_SEARCHlStop                 0x021cf080 arm
 *   DWCi_ANIMElEnd                   0x021bc8ec arm
 *   DWCi_FNTlDeleteBgLcd             0x021d5ca8 arm
 *   DWCi_COMMENTlDelete              0x021bd138 arm
 *   DWCi_GXlInvisible                0x021d6090 arm
 *   DWCi_SEARCHlEnd                  0x021cef50 arm
 *   DWCi_SETTIGNlGet                 0x021cf404 arm
 *   DWCi_SETTINGlSetSetting          0x021cf80c arm
 *   DWCi_SetParam_                   0x021c0e50 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   DWCi_SetParam2_                  0x021c0e8c arm
 *   Choose                           0x021de608 data
 *   DWCi_SceneSetSelectWay           0x021cc998 arm
 *   DWCi_SceneSetApList              0x021c50d4 arm
 *   DWCi_WINlGet                     0x021d1568 arm
 *   DWCi_SNDlPlay                    0x021cffac arm
 *   DWCi_WINlEnd                     0x021d1524 arm
 *   procError1                       0x021cbc70 arm
 */
typedef _Bool bool;

typedef struct tagSETTINGINFO {
    unsigned char pad[0xF4];
    unsigned char setting;            /* 0xF4 */
} SETTINGINFO;

extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_BTNlIsEnd(void);
extern bool DWCi_SEARCHlStop(void);
extern void DWCi_ANIMElEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SEARCHlEnd(void);
extern SETTINGINFO *DWCi_SETTIGNlGet(void);
extern void DWCi_SETTINGlSetSetting(int idx);
extern void DWCi_SetParam_(void *param0, void *param1);
extern void DWCi_ChangeScene(void (*scene)());
extern void DWCi_SetParam2_(void *param2, void *param3);
extern int DWCi_WINlGet(void);
extern void DWCi_SNDlPlay(int no);
extern void DWCi_WINlEnd(void);
extern unsigned char Choose;
extern int DWCi_SceneSetSelectWay;
extern int DWCi_SceneSetApList;


static void endScene2(void)
{
    if (DWCi_EFFlCheck(1) || DWCi_EFFlCheck(0)) {
        return;
    }
    if (!DWCi_BTNlIsEnd()) {
        return;
    }
    while (!DWCi_SEARCHlStop()) {
    }
    DWCi_ANIMElEnd();
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_COMMENTlDelete();
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x15);
    if (Choose != 1) {
        DWCi_SEARCHlEnd();
        DWCi_SETTINGlSetSetting(DWCi_SETTIGNlGet()->setting);
        DWCi_SetParam_((void *)2, (void *)1);
        DWCi_ChangeScene((void (*)())&DWCi_SceneSetSelectWay);
    } else {
        DWCi_SetParam_(0, (void *)1);
        DWCi_SetParam2_(0, 0);
        DWCi_ChangeScene((void (*)())&DWCi_SceneSetApList);
    }
}


static void procError1(void);


static void procError(void)
{
    if (DWCi_WINlGet() != 0) {
        return;
    }
    DWCi_SNDlPlay(6);
    DWCi_WINlEnd();
    DWCi_ChangeScene(procError1);
}
