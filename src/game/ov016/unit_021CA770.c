/*
 * file:     unit_021CA770.c
 * unit:     yes
 * function: func_021CA770, func_021CA7B4
 * address:  0x021CA770
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
 *   DWCi_EFFlFade                    0x021d55a4 arm
 *   DWCi_ChangeScene                 0x021c0e40 arm
 *   DWCi_EFFlCheck                   0x021d5580 arm
 *   DWCi_COMMENTlDelete              0x021bd138 arm
 *   DWCi_GXlInvisible                0x021d6090 arm
 *   DWCi_SetParam_                   0x021c0e50 arm
 *   DWCi_SceneSetSelectAp            0x021cbc90 arm
 */
typedef _Bool bool;

extern bool DWCi_EFFlFade(int kind, int lcd, int plane, int frame);
extern void DWCi_ChangeScene(void (*scene)());
extern bool DWCi_EFFlCheck(int lcd);
extern bool DWCi_COMMENTlDelete(void);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(void *param0, void *param1);
extern int DWCi_SceneSetSelectAp;


static void endScene1(void);


static void endScene(void)
{
    DWCi_EFFlFade(3, 1, 1, 8);
    DWCi_EFFlFade(3, 0, 0x14, 8);
    DWCi_ChangeScene(endScene1);
}


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
