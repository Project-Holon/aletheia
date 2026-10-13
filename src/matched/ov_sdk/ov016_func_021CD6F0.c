/*
 * function: func_021CD6F0
 * address:  0x021CD6F0
 * packet:   pkt_ov016_021CD6F0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      endScene1 (libdwcutil.TWL.HYB.a scenesettestcomp)
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov016_func_021CD6F0.c \n *       --func func_021CD6F0 --addr 0x021CD6F0 --region ov016 --cc 1.1p1 --arm --flags=-O4,p
 *
 * symbols:
 *   DWCi_EFFlCheck  0x021D5580  arm  ov016
 *   DWCi_STEPlIsEnd  0x021D0A84  arm  ov016
 *   DWCi_FNTlDeleteBgLcd  0x021D5CA8  arm  ov016
 *   DWCi_COMMENTlDelete  0x021BD138  arm  ov016
 *   DWCi_GXlInvisible  0x021D6090  arm  ov016
 *   DWCi_SetParam_  0x021C0E50  arm  ov016
 *   DWCi_GetParam2_  0x021C0EA0  arm  ov016
 *   DWCi_SetParam2_  0x021C0E8C  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_SceneSetList  0x021C82FC  arm  ov016
 *   DWCi_SceneMenu  0x021C1984  arm  ov016
 */

extern int DWCi_EFFlCheck(int lcd);
extern int DWCi_STEPlIsEnd(void);
extern void DWCi_FNTlDeleteBgLcd(int lcd);
extern int DWCi_COMMENTlDelete(void);
extern void DWCi_GXlInvisible(int lcd, int plane);
extern void DWCi_SetParam_(unsigned int a, unsigned int b);
extern void DWCi_GetParam2_(unsigned int *a, unsigned int *b);
extern void DWCi_SetParam2_(unsigned int a, unsigned int b);
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_SceneSetList(void);
extern void DWCi_SceneMenu(void);

void func_021CD6F0(void)
{
    int scene;
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    if (!DWCi_STEPlIsEnd())
        return;
    DWCi_FNTlDeleteBgLcd(0);
    DWCi_COMMENTlDelete();
    DWCi_GXlInvisible(1, 1);
    DWCi_GXlInvisible(0, 21);
    DWCi_SetParam_((unsigned int)((void *)2), (unsigned int)((void *)1));
    DWCi_GetParam2_(0, (unsigned int *)((void **)&scene));
    if (scene == 0) {
        DWCi_SetParam2_(0, 0);
        DWCi_ChangeScene((unsigned int)DWCi_SceneSetList);
        return;
    }
    DWCi_ChangeScene((unsigned int)DWCi_SceneMenu);
}
