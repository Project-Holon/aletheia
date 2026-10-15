/*
 * function: SOCLi_SocketUnregister
 * address:  0x0215F31C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call on the object at 0x021AA4B4 with the incoming argument.
 *
 * symbols:
 *   g_021AA4B4  0x021AA4B4  data
 *   SOCLi_SocketUnregisterList  0x0215F334  arm  ov009
 */

extern char g_021AA4B4[];
struct Sock;
extern void SOCLi_SocketUnregisterList(struct Sock **next, struct Sock *socket);

void SOCLi_SocketUnregister(int a)
{
    SOCLi_SocketUnregisterList((struct Sock **)g_021AA4B4, (struct Sock *)a);
}

