/*
 * function: SOCL_SocketIsInTrash
 * address:  0x0215F404
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Non-zero test on the call that takes the object and the argument.
 *
 * symbols:
 *   SOCLiTrashList  0x021AA4B8  data
 *   func_0215F36C  0x0215F36C  arm  ov009
 */

extern char SOCLiTrashList[];
extern int func_0215F36C(char *p, int b);

int SOCL_SocketIsInTrash(int b)
{
    return func_0215F36C(SOCLiTrashList, b) != 0;
}

