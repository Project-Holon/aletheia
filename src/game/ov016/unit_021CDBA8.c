/*
 * file:     unit_021CDBA8.c
 * unit:     yes
 * function: DWCi_SceneSetUsbCompleteCallback, DWCi_SceneSetUsbCompleteNop
 * address:  0x021CDBA8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
extern void func_021CDC78(void);
void DWCi_SceneSetUsbCompleteCallback(void);
void DWCi_SceneSetUsbCompleteNop(void);


/*
 * Call func_021CDC78, DWCi_SceneSetUsbCompleteNop.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetUsbCompleteCallback.c \
 *       --func DWCi_SceneSetUsbCompleteCallback --addr 0x021CDBA8 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetUsbCompleteCallback(void)
{
    func_021CDC78();
    DWCi_SceneSetUsbCompleteNop();
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_SceneSetUsbCompleteNop.c \
 *       --func DWCi_SceneSetUsbCompleteNop --addr 0x021CDBB8 --region ov016 --cc dsi/1.1p1 --arm
 */
void DWCi_SceneSetUsbCompleteNop(void)
{
}
