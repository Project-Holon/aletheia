/*
 * function: func_021C73A0
 * address:  0x021C73A0
 * packet:   pkt_ov016_021C73A0
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procInit2 (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 *
 * symbols:
 *   func_021BF6E0  0x021BF6E0  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   DWCi_SceneSetEditAddress_procScene  0x021C73C0  arm  ov016
 */

extern unsigned char func_021BF6E0(void);
extern void func_021C0E40(unsigned int v);
extern void DWCi_SceneSetEditAddress_procScene();

void func_021C73A0(void)
{
    if (func_021BF6E0() == 0x1F)
        return;
    func_021C0E40((unsigned int)DWCi_SceneSetEditAddress_procScene);
}
