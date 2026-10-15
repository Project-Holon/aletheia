/*
 * function: CTVT_COMM_GetMyStatus
 * address: 0x021B8118
 * packet: pkt_ov172_021B8118
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov172/ctvt_comm_p03.c and filed here.
 */

typedef unsigned char  u8;
u8 *CTVT_COMM_GetMyStatus(u8 *p);

u8 *CTVT_COMM_GetMyStatus(u8 *p)
{
    return p + 12;
}
