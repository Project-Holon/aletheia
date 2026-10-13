/*
 * function: GFL_NET_QUEUE_IsEmpty
 * address:  0x020366A8
 * packet:   pkt_020366A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_QUEUE_GetCount   0x020366C0  arm
 */

extern int GFL_NET_QUEUE_GetCount(char *p);

struct Conn;

int GFL_NET_QUEUE_IsEmpty(struct Conn *p)
{
    return GFL_NET_QUEUE_GetCount((char *)p) == 0;
}
