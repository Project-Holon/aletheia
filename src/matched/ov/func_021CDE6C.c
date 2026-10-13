/*
 * function: DWCi_SceneSetUsbReadyUpdate
 * address:  0x021CDE6C
 * packet:   pkt_021CD3EC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneSetUsbReadyUpdate   0x021CDE6C  arm
 *   DWCi_SceneSetUsbReadyUpdateNop  0x021CDEBC  arm
 *
 * Call func_021CDE80, DWCi_SceneSetUsbReadyUpdateNop, func_021CDEC0.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetUsbReadyUpdate.c \
 *       --func DWCi_SceneSetUsbReadyUpdate --addr 0x021CDE6C --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021CDE80(void);
extern void DWCi_SceneSetUsbReadyUpdateNop(void);
extern void func_021CDEC0(void);

void DWCi_SceneSetUsbReadyUpdate(void)
{
    func_021CDE80();
    DWCi_SceneSetUsbReadyUpdateNop();
    func_021CDEC0();
}
