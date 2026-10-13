/*
 * function: NET_WHPIPE_SetBeaconStatus
 * address: 0x021780FC
 * packet: pkt_ov014_021780FC
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   g_pWhPipeWork 0x021797A4 data ov014 a4
 *   NET_WHPIPE_PublishBeacon 0x0217778C thumb ov014
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *g_pWhPipeWork;
extern void NET_WHPIPE_PublishBeacon(void);
void NET_WHPIPE_SetBeaconStatus(u8 value)
{
    if (g_pWhPipeWork) {
        g_pWhPipeWork[0xcea] = value;
        NET_WHPIPE_PublishBeacon();
    }
}
