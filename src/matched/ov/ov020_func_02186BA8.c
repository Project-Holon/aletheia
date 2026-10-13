/*
 * function: FIELD_WFBC_DATA_LOCAL_IsMoodZero
 * address: 0x02186BA8
 * packet: pkt_ov020_02186BA8
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero alignment bytes.
 */
typedef unsigned char u8;
int FIELD_WFBC_DATA_LOCAL_IsMoodZero(u8 *p)
{
    if (p[2] == 0) return 1;
    return 0;
}
