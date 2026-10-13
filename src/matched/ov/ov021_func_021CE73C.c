/*
 * function: COMM_ENTRY_MENU_CountAcceptedMembers
 * address:  0x021CE73C
 * packet:   pkt_ov021_021CE73C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Counts the entries among the four 0x2C-byte entries at +0x70 whose state is 4.
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct {
    u8 state;
    u8 pad1[0x2b];
} Entry;

typedef struct {
    u8 pad0[0x70];
    Entry ent[4];
} Mgr;

int COMM_ENTRY_MENU_CountAcceptedMembers(Mgr *m)
{
    int i;
    int n = 0;

    for (i = 0; i < 4; i++) {
        if (m->ent[i].state == 4)
            n++;
    }
    return n;
}
