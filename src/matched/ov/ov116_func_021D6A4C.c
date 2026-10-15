/*
 * function: WIFI_BSUBWAY_GetTransferState
 * address: 0x021D6A4C
 * packet: pkt_ov116_021D6A4C
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   (none)
 */

int WIFI_BSUBWAY_GetTransferState(unsigned char *p)
{
    if (*(unsigned short *)(p + 12) < 100) {
        return 2;
    }
    return 3;
}
