/*
 * function: DWCi_MOV_WH_StateInEndKeyShare
 * address: 0x0217945C
 * packet: pkt_ov014_0217945C
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * return-chain: 0209028C result is passed to 0217814C.
 * symbols:
 *   gWihWork 0x021797A8 data ov014 a4
 *   WM_EndDataSharing 0x0209028C arm
 *   WIH_SetError 0x0217814C thumb ov014
 *   WIH_StateInReset 0x02178CDC thumb ov014
 *   WIH_ChangeSysState 0x02178138 thumb ov014
 */
typedef unsigned char u8;
extern u8 *gWihWork;
extern int WM_EndDataSharing(void *);
extern void WIH_SetError(int);
extern int WIH_StateInReset(void);
extern void WIH_ChangeSysState(int);
void DWCi_MOV_WH_StateInEndKeyShare(void)
{
    int error;
    if (*(int *)(gWihWork + 0x1E70) == 5) {
        error = WM_EndDataSharing(gWihWork + 0x1444);
        if (error != 0) WIH_SetError(error);
    }
    if (WIH_StateInReset() == 0) WIH_ChangeSysState(10);
}
