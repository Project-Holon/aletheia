/*
 * function: COMM_ENTRY_MENU_QueueSend
 * address:  0x021CEAB0
 * packet:   pkt_ov021_021CEAB0
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

void COMM_ENTRY_MENU_QueueSend(u8 *p)
{
    if (p[0x523] == 1 || p[0x525] == 1) {
        p[0x524] = 1;
    } else {
        p[0x523] = 1;
        p[0x524] = 0;
    }
}
