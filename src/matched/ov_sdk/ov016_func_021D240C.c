/*
 * function: DWCi_MOV_MBP_Cancel
 * address:  0x021D240C
 * packet:   pkt_ov016_021D240C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_MOV_MBP_Cancel (libdwcutil.TWL.HYB.a(dwc_mov_mbp.o))
 *
 * symbols:
 *   DWCi_MOV_MBP_ChangeState         0x021D276C  arm
 *   MB_EndToIdle                     0x021F5F74  arm
 */

extern void DWCi_MOV_MBP_ChangeState(unsigned short state);
extern void MB_EndToIdle(void);

void DWCi_MOV_MBP_Cancel(void)
{
	DWCi_MOV_MBP_ChangeState(6);
	MB_EndToIdle();
}
