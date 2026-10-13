/*
 * function: DWC_RAP_OnReceiveTimeout
 * address: 0x02155BDC
 * packet: pkt_ov009_02155BDC
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _pRapWork 0x021A8264 data ov009 a4
 *   DWC_CloseAllConnectionsHard 0x0216B65C arm ov009
 *   DWC_RAP_SetState 0x02155374 thumb ov009
 */
typedef unsigned char u8;
extern u8 *_pRapWork;
extern int DWC_CloseAllConnectionsHard(void);
extern void DWC_RAP_SetState(int);
void DWC_RAP_OnReceiveTimeout(unsigned int n)
{
    if (n < 2 && _pRapWork[0x7A8]) {
        DWC_CloseAllConnectionsHard();
        *(int *)(_pRapWork + 0x774) = -1;
        DWC_RAP_SetState(20);
    }
}
