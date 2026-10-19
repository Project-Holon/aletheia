/*
 * function: endScene
 * address:  0x021C46DC
 * packet:   pkt_021C46DC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   endScene 0x021C46DC arm
 *   DWCi_BTNlDisable  0x021BCB9C  arm
 *   DWCi_ChangeScene  0x021C0E40  arm
 *   DWCi_MOVlEnd  0x021C115C  arm
 *   DWCi_EFFlWait  0x021D5790  arm
 *
 * Wake the sub-state, flag it and post the event at 0x021C4714.
 * Addresses are Black-image addresses.
 */

extern void DWCi_MOVlEnd(void);
extern void DWCi_BTNlDisable(void);
extern void DWCi_EFFlWait(int);
extern void DWCi_ChangeScene(unsigned int v);

void endScene(void)
{
    if (*(unsigned char *)0x021DE5C8 == 0)
        DWCi_MOVlEnd();
    DWCi_BTNlDisable();
    DWCi_EFFlWait(8);
    DWCi_ChangeScene((unsigned int)((void *)0x021C4714));
}
