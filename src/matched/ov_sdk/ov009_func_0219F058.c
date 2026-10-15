/*
 * function: ServerBrowserGetServer
 * address:  0x0219F058
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call on the object 0x60 bytes in.
 *
 * symbols:
 *   SBServerListNth  0x0219F7C4  arm
 */

extern int SBServerListNth(int *p);

void ServerBrowserGetServer(char *p)
{
    SBServerListNth((int *)(p + 0x60));
}

