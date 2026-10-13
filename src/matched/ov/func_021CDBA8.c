/*
 * function: DWCi_SceneSetUsbCompleteCallback
 * address:  0x021CDBA8
 * packet:   pkt_021CD3EC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneSetUsbCompleteCallback   0x021CDBA8  arm
 *   DWCi_SceneSetUsbCompleteNop  0x021CDBB8  arm
 *
 * Call func_021CDC78, DWCi_SceneSetUsbCompleteNop.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetUsbCompleteCallback.c \
 *       --func DWCi_SceneSetUsbCompleteCallback --addr 0x021CDBA8 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021CDC78(void);
extern void DWCi_SceneSetUsbCompleteNop(void);

void DWCi_SceneSetUsbCompleteCallback(void)
{
    func_021CDC78();
    DWCi_SceneSetUsbCompleteNop();
}
