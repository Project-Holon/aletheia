/*
 * file:     scenesetrakubutton_3.c
 * unit:     yes
 * function: func_021CA95C, func_021CA980
 * address:  0x021CA95C
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
 *   procScene                        0x021CA980  arm
 *   DWCi_SceneSetListSave_button  0x021CA9D8  arm
 */
typedef unsigned int   u32;

extern int DWCi_BTNlGet(void);
extern void DWCi_BTNlEnable(void);
extern void DWCi_ChangeScene(void (*scene)());
extern void func_02085A38(u32 msec);
extern void func_021CAB68(void);
extern void func_021CA9A0(void);
extern void DWCi_SceneSetListSave_button(void);
extern void func_021CA9DC(void);
void func_021CA980(void);


static void procScene(void);


static void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene(procScene);
}


/*
 * Set r0 to 0xa, call func_02085A38, then run the four ov016 steps.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CA980.c \
 *       --func func_021CA980 --addr 0x021CA980 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021CA980(void)
{
    func_02085A38(0xa);
    func_021CAB68();
    func_021CA9A0();
    DWCi_SceneSetListSave_button();
    func_021CA9DC();
}
