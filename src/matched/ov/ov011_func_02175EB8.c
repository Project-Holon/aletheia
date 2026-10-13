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
 * extent: alignment at 02175ED6 then existing filed leaf ov011_func_02175ED8.c.
 * interface: BCC matched caller returns int; body returns original object +0xac or null.
 * symbols:
 *   func_02175BCC 0x02175BCC thumb ov011
 */
typedef unsigned char u8;
extern u8 *func_02175BCC(u8 *p);
int INTRUDE_COMM_IsResultConfirmed(void *p)
{
    u8 *r;
    r = (u8 *)func_02175BCC(p);
    if (r == 0) return 0;
    if (r[0x37] == 1) return 1;
    return 0;
}
