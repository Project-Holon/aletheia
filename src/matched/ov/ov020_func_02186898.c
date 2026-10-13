/*
 * function: FIELD_WFBC_DATA_LOCAL_GetItemSlot
 * address:  0x02186898
 * packet:   pkt_02186898
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned short u16;

u16 FIELD_WFBC_DATA_LOCAL_GetItemSlot(u16 *p, int i)
{
    return p[i];
}
