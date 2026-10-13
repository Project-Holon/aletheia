/*
 * function: WIH_UpdateScanTimer
 * address: 0x021793F8
 * packet: pkt_ov014_021793F8
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: final counter store uses unsigned address arithmetic rather than
 *   pointer arithmetic, so its offset is reloaded independently of the flag.
 * symbols:
 *   gWihWork 0x021797A8 data ov014 a4
 *   WIH_ChangeSysState 0x02178138 thumb ov014
 *   DWCi_MOV_WH_StateInStartScan 0x0217863C thumb ov014
 */
typedef unsigned char u8;
typedef short s16;
extern u8 *gWihWork;
extern void WIH_ChangeSysState(int);
extern int DWCi_MOV_WH_StateInStartScan(void);
void WIH_UpdateScanTimer(void)
{
    if (gWihWork != 0 && *(s16 *)(gWihWork + 0x1EBE) > 0) {
        *(s16 *)(gWihWork + 0x1EBE) =
            (*(int *)(gWihWork + 0x1E70) != 2) ? 0 : *(s16 *)(gWihWork + 0x1EBE) - 1;
        if (*(s16 *)(gWihWork + 0x1EBE) == 0) {
            if (*(int *)(gWihWork + 0x1E70) == 2 && gWihWork[0x1EDE] == 0) {
                if (DWCi_MOV_WH_StateInStartScan() == 0) WIH_ChangeSysState(9);
            } else {
                *(s16 *)((unsigned int)gWihWork + 0x1EBE) = 1;
            }
        }
    }
}
