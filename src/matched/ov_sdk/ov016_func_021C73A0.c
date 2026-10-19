/*
 * function: procInit2
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
 *   DWCi_KB10lGet  0x021BF6E0  arm  ov016
 *   DWCi_ChangeScene  0x021C0E40  arm  ov016
 *   DWCi_SceneSetEditAddress_procScene  0x021C73C0  arm  ov016
 */

extern unsigned char DWCi_KB10lGet(void);
extern void DWCi_ChangeScene(unsigned int v);
extern void DWCi_SceneSetEditAddress_procScene();

void procInit2(void)
{
    if (DWCi_KB10lGet() == 0x1F)
        return;
    DWCi_ChangeScene((unsigned int)DWCi_SceneSetEditAddress_procScene);
}
