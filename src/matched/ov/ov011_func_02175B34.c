/*
 * function: INTRUDE_COMM_GetActiveSessionRequest
 * address: 0x02175B34
 * packet: pkt_ov011_02175B34
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the compiled return.
 * symbols:
 *   INTRUDE_COMM_IsSessionActive 0x02175B14 thumb ov011
 */
typedef unsigned char u8;
extern int INTRUDE_COMM_IsSessionActive(u8 *p);
u8 *INTRUDE_COMM_GetActiveSessionRequest(u8 *p)
{
    if (INTRUDE_COMM_IsSessionActive(p) == 0) p = 0;
    else p += 0x78;
    return p;
}
