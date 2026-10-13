/*
 * function: GFL_NET_HANDLE_GetNegotiationState
 * address:  0x020399DC
 * packet:   pkt_020399DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Entry accessor: returns byte 0x4A of a 0x50-byte entry, or 8 for null.
 */
typedef unsigned char u8;
struct Entry { u8 bytes[0x50]; };
int GFL_NET_HANDLE_GetNegotiationState(struct Entry *p)
{
    if (p) return p->bytes[0x4a];
    return 8;
}
