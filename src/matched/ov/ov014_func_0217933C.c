/*
 * function: DWCi_MOV_WH_SetReceiver
 * address: 0x0217933C
 * packet: pkt_ov014_0217933C
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gWihWork 0x021797A8 data ov014 a4
 *   WM_SetPortCallback 0x0208EB0C arm
 *   DWCi_MOV_WH_PortReceiveCallback 0x02178D9C thumb ov014
 *   WIH_ChangeSysState 0x02178138 thumb ov014
 */
typedef unsigned char u8;
extern u8 *gWihWork;
extern int WM_SetPortCallback(int, void (*)(u8 *), void *);
extern void DWCi_MOV_WH_PortReceiveCallback(u8 *);
extern void WIH_ChangeSysState(int);
void DWCi_MOV_WH_SetReceiver(void *cb)
{
    *(void **)(gWihWork + 0x1E78) = cb;
    if (WM_SetPortCallback(14, DWCi_MOV_WH_PortReceiveCallback, 0) != 0) WIH_ChangeSysState(9);
}
