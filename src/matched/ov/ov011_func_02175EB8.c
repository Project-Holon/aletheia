/*
 * function: INTRUDE_COMM_IsResultConfirmed
 * address: 0x02175EB8
 * packet: pkt_ov011_02175EB8
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: alignment at 02175ED6 then existing filed leaf INTRUDE_COMM_GetLeaveFlag.c.
 * interface: BCC matched caller returns int; body returns original object +0xac or null.
 * symbols:
 *   INTRUDE_COMM_GetSessionResult 0x02175BCC thumb ov011
 */
typedef unsigned char u8;
extern u8 *INTRUDE_COMM_GetSessionResult(u8 *p);
int INTRUDE_COMM_IsResultConfirmed(void *p)
{
    u8 *r;
    r = (u8 *)INTRUDE_COMM_GetSessionResult(p);
    if (r == 0) return 0;
    if (r[0x37] == 1) return 1;
    return 0;
}
