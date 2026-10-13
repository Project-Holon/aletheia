/*
 * function: COMM_ENTRY_ClearParentSlot
 * address:  0x021CEF08
 * packet:   pkt_ov021_021CEF08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void COMM_ENTRY_ClearParentSlot(u8 *p, int i)
{
    (p + i * 0x2c)[0x16a] = 0;
}
