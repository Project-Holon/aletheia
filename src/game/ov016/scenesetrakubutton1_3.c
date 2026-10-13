/*
 * file:     scenesetrakubutton1_3.c
 * unit:     yes
 * function: func_021CAD88, func_021CADAC
 * address:  0x021CAD88
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
 *   DWCi_BTNlGet                     0x021BCB14  arm
 *   DWCi_BTNlEnable                  0x021BCB84  arm
 *   DWCi_ChangeScene                 0x021C0E40  arm
 *   procScene                        0x021CADAC  arm
 *   DWCi_SceneSetRakuButton_draw  0x021CAE04  arm
 */
typedef unsigned int   u32;

extern int DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_ChangeScene(void (*scene)());
extern void func_02085A38(u32 msec);
extern void func_021CAF78(void);
extern void func_021CADCC(void);
extern void DWCi_SceneSetRakuButton_draw(void);
extern void func_021CAE08(void);
void func_021CADAC(void);


static void procScene(void);


static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}


void func_021CADAC(void)
{
    func_02085A38(0xa);
    func_021CAF78();
    func_021CADCC();
    DWCi_SceneSetRakuButton_draw();
    func_021CAE08();
}
