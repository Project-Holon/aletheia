/*
 * file:     unit_0215F2DC_p03.c
 * unit:     yes
 * function: func_0215F3B8, func_0215F3D0, func_0215F404
 * address:  0x0215F3B8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021AA4B8  0x021AA4B8  data
 *   func_0215F334  0x0215F334  arm  ov009
 *   SOCLi_SocketGetNextPtr   0x0215f36c arm
 *   SOCLiSocketList          0x021aa4b4 data
 *   func_0215F36C  0x0215F36C  arm  ov009
 */
struct Sock;
struct SOCLSocket;
extern void func_0215F334(struct Sock **next, struct Sock *socket);
extern struct SOCLSocket **SOCLi_SocketGetNextPtr(struct SOCLSocket **next,
                                                  struct SOCLSocket *socket);
extern int func_0215F36C(char *p, int b);
void func_0215F3B8(int a);
int SOCL_SocketIsInvalid(struct SOCLSocket *socket);
int func_0215F404(int b);
extern char g_021AA4B8[];
extern struct SOCLSocket *SOCLiSocketList;


/*
 * Tail call on the object at 0x021AA4B8 with the incoming argument.
 */
void func_0215F3B8(int a)
{
    func_0215F334((struct Sock **)g_021AA4B8, (struct Sock *)a);
}


int SOCL_SocketIsInvalid(struct SOCLSocket *socket)
{
    if ((int)socket <= 0
        || SOCLi_SocketGetNextPtr(&SOCLiSocketList, socket) == 0)
        return 1;
    return 0;
}


/*
 * Non-zero test on the call that takes the object and the argument.
 */
int func_0215F404(int b)
{
    return func_0215F36C(g_021AA4B8, b) != 0;
}
