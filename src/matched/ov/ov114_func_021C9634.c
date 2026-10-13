/*
 * function: DPW_BT_CancelAsync
 * address: 0x021C9634
 * packet: pkt_ov114_021C9634
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   DWCi_EncSessionCancel 0x021CA188 arm ov114
 *   gDpwBtWork 0x021D4084 data a4
 */
extern void DWCi_EncSessionCancel(void);
extern unsigned gDpwBtWork;
void DPW_BT_CancelAsync(void)
{
    switch (gDpwBtWork) {
    case 2: DWCi_EncSessionCancel(); gDpwBtWork = 3; break;
    case 4: DWCi_EncSessionCancel(); gDpwBtWork = 5; break;
    case 6: DWCi_EncSessionCancel(); gDpwBtWork = 7; break;
    case 8: DWCi_EncSessionCancel(); gDpwBtWork = 9; break;
    case 10: DWCi_EncSessionCancel(); gDpwBtWork = 11; break;
    }
}
