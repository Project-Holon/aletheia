/*
 * function: DWCi_SceneSetUsbReady1Update
 * address:  0x021CE23C
 * packet:   pkt_021CE23C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneSetUsbReady1Update   0x021CE23C  arm
 *   DWCi_SceneSetUsbReady1UpdateNop  0x021CE288  arm
 *
 * Call func_021CE250, DWCi_SceneSetUsbReady1UpdateNop, func_021CE28C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetUsbReady1Update.c \
 *       --func DWCi_SceneSetUsbReady1Update --addr 0x021CE23C --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021CE250(void);
extern void DWCi_SceneSetUsbReady1UpdateNop(void);
extern void func_021CE28C(void);

void DWCi_SceneSetUsbReady1Update(void)
{
    func_021CE250();
    DWCi_SceneSetUsbReady1UpdateNop();
    func_021CE28C();
}
