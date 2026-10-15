/*
 * function: SOCLi_SocketRegisterTrash
 * address:  0x0215F304
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail call on the object at 0x021AA4B8 with the incoming argument.
 *
 * symbols:
 *   SOCLiTrashList  0x021AA4B8  data
 *   func_0215F2F4  0x0215F2F4  arm  ov009
 */

extern char SOCLiTrashList[];
extern void func_0215F2F4(char *p, int a);

void SOCLi_SocketRegisterTrash(int a)
{
    func_0215F2F4(SOCLiTrashList, a);
}

