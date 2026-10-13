/*
 * function: COMM_ENTRY_MENU_AckSend
 * address:  0x021CEADC
 * packet:   pkt_ov021_021CEADC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

u8 *COMM_ENTRY_MENU_AckSend(u8 *p)
{
    p[0x525] = 0;
    p[0x523] = p[0x524];
    p[0x524] = 0;
    return p;
}
