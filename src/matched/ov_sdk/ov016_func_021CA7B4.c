/*
 * function: endScene1
 * address:  0x021CA7B4
 * packet:   pkt_ov016_021CA7B4
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_EFFlCheck                   0x021d5580 arm
 *   DWCi_COMMENTlDelete              0x021bd138 arm
 *   DWCi_GXlInvisible                0x021d6090 arm
 *   DWCi_SetParam_                   0x021c0e50 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   DWCi_SceneSetSelectAp            0x021cbc90 arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(scenesetlistsave), symbol endScene1 (name and prototype from the vendor object DWARF).
 * The object is stamped Metrowerks C/C++ for ARM 4.0.0.1025, which no tools/mwccarm build
 * writes, so it stays on the default dsi/1.1p1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CA7B4.c \
 *       --func endScene1 --addr 0x021CA7B4 --region ov016 --cc 1.1p1 --arm --lang c99
 */

typedef _Bool bool;

extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(void *param0, void *param1);
extern void DWCi_ChangeScene(void (*scene)());
extern int DWCi_SceneSetSelectAp;

static void endScene1(void)
{
    if (DWCi_EFFlCheck(1) || DWCi_EFFlCheck(0)) {
        return;
    }
    DWCi_COMMENTlDelete();
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 0x14);
    DWCi_SetParam_((void *)2, (void *)1);
    DWCi_ChangeScene((void (*)())&DWCi_SceneSetSelectAp);
}
