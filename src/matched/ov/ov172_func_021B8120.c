/*
 * function: CTVT_COMM_IsModeSupported
 * address: 0x021B8120
 * packet: pkt_ov172_021B8120
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov172/ctvt_comm_p03.c and filed here.
 */

int CTVT_COMM_IsModeSupported(int a, int b);

int CTVT_COMM_IsModeSupported(int a, int b)
{
    if (b == 0x20 || b == 3) {
        return 1;
    }
    return 0;
}
