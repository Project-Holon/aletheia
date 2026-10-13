/*
 * function: COMM_ENTRY_MENU_LatchRequest
 * address:  0x021CE3E8
 * packet:   pkt_ov021_021CE3E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Latches a 0x2C-byte request into the slot at +0x104 when the +0x100 busy flag is clear; returns whether it did.
 *
 * symbols:
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef struct {
    u32 w[11];
} Req;

typedef struct {
    u8 pad0[0x100];
    u32 busy;
    Req req;
} Mgr;

int COMM_ENTRY_MENU_LatchRequest(Mgr *m, Req *r)
{
    if (m->busy == 0) {
        m->req = *r;
        m->busy = 1;
        return 1;
    }
    return 0;
}
