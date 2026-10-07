/*
 * function: endScene2
 * address:  0x021C8230
 * packet:   pkt_ov016_021C8230
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
 *   DWCi_FNTlDeleteBgLcd             0x021d5ca8 arm
 *   DWCi_COMMENTlDelete              0x021bd138 arm
 *   DWCi_GXlInvisible                0x021d6090 arm
 *   DWCi_GetParam2_                  0x021c0ea0 arm
 *   DWCi_SetParam_                   0x021c0e50 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   DWCi_SetParam2_                  0x021c0e8c arm
 *   DWCi_SetListReturn               0x021ca5c0 arm
 *   DWCi_SceneSetSelectAp            0x021cbc90 arm
 *   DWCi_SceneSetList                0x021c82fc arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(sceneseterror.o), symbol endScene2 (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021C8230.c \
 *       --func endScene2 --addr 0x021C8230 --region ov016 --cc 1.1p1 --arm --lang c99
 */

typedef _Bool bool;

extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_BTNlIsEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_GetParam2_(void **param2, void **param3);
extern void DWCi_SetParam_(void *param0, void *param1);
extern void DWCi_ChangeScene(void (*scene)());
extern void DWCi_SetParam2_(void *param2, void *param3);
extern void DWCi_SetListReturn(int scene);
extern int DWCi_SceneSetSelectAp;
extern int DWCi_SceneSetList;

static void endScene2(void)
{
    void *prm;

    if (DWCi_EFFlCheck(1) || DWCi_EFFlCheck(0)) {
        return;
    }
    if (!DWCi_BTNlIsEnd()) {
        return;
    }
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_COMMENTlDelete();
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x15);
    DWCi_GetParam2_(0, &prm);
    if (prm != 0) {
        DWCi_SetParam_((void *)2, (void *)1);
        DWCi_ChangeScene((void (*)())&DWCi_SceneSetSelectAp);
    } else {
        DWCi_SetParam_((void *)2, (void *)0);
        DWCi_SetParam2_(0, 0);
        DWCi_SetListReturn(0);
        DWCi_ChangeScene((void (*)())&DWCi_SceneSetList);
    }
}
