/*
 * function: SOCLi_SocketRegister
 * address:  0x0215F2DC
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
 *   func_0215F2F4  0x0215F2F4  arm  ov009
 */

extern char g_021AA4B4[];
extern void func_0215F2F4(char *p, int a);

void SOCLi_SocketRegister(int a)
{
    func_0215F2F4(g_021AA4B4, a);
}

