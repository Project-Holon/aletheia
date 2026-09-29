/*
 * function: endScene2
 * address:  0x021CBB70
 * packet:   pkt_ov016_021CBB70
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
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
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetsearch.o), symbol endScene2 (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CBB70.c \
 *       --func endScene2 --addr 0x021CBB70 --region ov016 --cc 1.1p1 --arm --lang c99
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
