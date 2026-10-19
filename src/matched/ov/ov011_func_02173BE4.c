/*
 * function: INTRUDE_COMM_RecvNoticeBytes
 * address: 0x02173BE4
 * packet: pkt_ov011_02173BE4
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov011/unit_02173658.c and filed here.
 */

typedef unsigned char u8;
typedef struct { u8 pad[0x15c]; u8 v[4]; } D_02173B9C;
void INTRUDE_COMM_RecvNoticeBytes(int a, int b, const u8 *src, D_02173B9C *dst);

/*
 * sdk:      INTRUDE_COMM_RecvNoticeBytes (dwc_match.o)
 */
void INTRUDE_COMM_RecvNoticeBytes(int a, int b, const u8 *src, D_02173B9C *dst)
{
    dst->v[0] = src[0];
    dst->v[1] = src[1];
    dst->v[2] = src[2];
    dst->v[3] = src[3];
}
