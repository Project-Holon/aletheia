/*
 * function: DWCi_SceneOptMovDisconnect
 * address:  0x021C3B8C
 * packet:   pkt_021C3B8C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_SceneOptMovDisconnect 0x021C3B8C arm
 *   DWCi_CMNlMsgDraw  0x021BD29C  arm
 *   DWCi_ChangeScene  0x021C0E40  arm
 *
 * Clear the counter, reset the sub-state and post the event at 0x021C3C28.
 * Addresses are Black-image addresses.
 */

extern void func_021C3BBC(void);
extern void DWCi_CMNlMsgDraw(int);
extern void DWCi_ChangeScene(unsigned int v);

void DWCi_SceneOptMovDisconnect(void)
{
    *(unsigned char *)0x021DE5BC = 0;
    func_021C3BBC();
    DWCi_CMNlMsgDraw(0x21);
    DWCi_ChangeScene((unsigned int)((void *)0x021C3C28));
}
