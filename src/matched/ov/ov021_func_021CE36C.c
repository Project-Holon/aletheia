/*
 * function: COMM_ENTRY_MENU_AdvanceMemberStates
 * address:  0x021CE36C
 * packet:   pkt_ov021_021CE36C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   COMM_ENTRY_MENU_LatchRequest  0x021CE3E8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

extern int COMM_ENTRY_MENU_LatchRequest(u8 *p, u8 *e);

void COMM_ENTRY_MENU_AdvanceMemberStates(u8 *p)
{
    u8 *e;
    u8 j;

    e = p + 0x50;
    for (j = 0; j < 4; j++, e += 0x2c) {
        switch (e[0x20]) {
        case 1:
            if (e[0x21] == 1) {
                e[0x20] = 4;
                p[0x521] |= 1 << j;
            } else {
                e[0x20] = 2;
            }
            break;
        case 2:
            if (COMM_ENTRY_MENU_LatchRequest(p, e) == 1) {
                e[0x20] = 3;
            }
            break;
        }
    }
}
