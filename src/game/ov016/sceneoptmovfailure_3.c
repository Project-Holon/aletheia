/*
 * file:     sceneoptmovfailure_3.c
 * function: func_021C3F00
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
 *   func_021BCB14  0x021BCB14  arm  ov016
 *   func_021C11B8  0x021C11B8  arm  ov016
 *   func_021BCB84  0x021BCB84  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   DWCi_SceneOptMovFailure_procScene  0x021C3F30  arm  ov016
 */

extern signed char func_021BCB14(void);
extern int func_021C11B8();
extern void func_021BCB84();
extern void func_021C0E40(unsigned int v);
extern void DWCi_SceneOptMovFailure_procScene();

void func_021C3F00(void)
{
    if (func_021BCB14() == -2)
        return;
    if (!func_021C11B8())
        return;
    func_021BCB84();
    func_021C0E40((unsigned int)DWCi_SceneOptMovFailure_procScene);
}
