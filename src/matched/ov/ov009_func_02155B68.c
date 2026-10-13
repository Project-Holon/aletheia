/*
 * function: DWC_RAP_SendPendingAck
 * address: 0x02155B68
 * packet: pkt_ov009_02155B68
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _pRapWork 0x021A8264 data ov009 a4
 *   DWC_RAP_SendAck 0x02155B00 thumb ov009
 */
typedef unsigned char u8;
extern u8 *_pRapWork;
extern int DWC_RAP_SendAck(int, int);
void DWC_RAP_SendPendingAck(void)
{
    int value;
    if (_pRapWork[0x7A7]) {
        value = 0;
        if (DWC_RAP_SendAck((int)&value, 4))
            _pRapWork[0x7A7] = 0;
    }
}
