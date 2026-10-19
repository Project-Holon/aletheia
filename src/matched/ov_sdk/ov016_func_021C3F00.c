/*
 * function: procInit2
 * address:  0x021C3F00
 * packet:   pkt_ov016_021C3F00
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procInit2 (libdwcutil.TWL.HYB.a sceneoptmovfailure.o)
 *
 * symbols:
 *   DWCi_BTNlGet  0x021BCB14  arm  ov016
 *   DWCi_MOVlIsEnd  0x021C11B8  arm  ov016
 *   DWCi_BTNlEnable  0x021BCB84  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_SceneOptMovFailure_procScene  0x021C3F30  arm  ov016
 */

extern signed char DWCi_BTNlGet(void);
extern int DWCi_MOVlIsEnd();
extern void DWCi_BTNlEnable();
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_SceneOptMovFailure_procScene();

void procInit2(void)
{
    if (DWCi_BTNlGet() == -2)
        return;
    if (!DWCi_MOVlIsEnd())
        return;
    DWCi_BTNlEnable();
    DWCi_ChangeScene((unsigned int)DWCi_SceneOptMovFailure_procScene);
}
