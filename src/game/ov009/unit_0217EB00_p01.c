/*
 * file:     unit_0217EB00_p01.c
 * unit:     yes
 * function: func_0217EB00, func_0217EB18, func_0217EB2C, func_0217EB40, func_0217EB9C
 * address:  0x0217EB00
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
 *   g_021AD0F4  0x021AD0F4  data
 *   SOC_Close        0x0215f644 arm
 *   SOCL_IsReleased  0x0215e7c8 arm
 *   CheckRcode       0x0217eb00 arm
 */
extern int func_0215F428(void);
extern int func_0215F644(int s);
extern int SOC_Close(int s);
extern int SOCL_IsReleased(int s);
extern int CheckRcode(int rcode, int errCode);
extern int func_0215F638(int s, int how);
int func_0217EB00(int a, int b);
int func_0217EB18(int pf, int type, int protocol);
int func_0217EB2C(int sock);
int closesocketsure(int sock, int *notInCloseSocket);
int func_0217EB9C(int sock, int how);
extern char g_021AD0F4[];


/*
 * Stores a negative argument at +0x4 of the module state object and returns the second.
 */
int func_0217EB00(int a, int b)
{
    if (a < 0) {
        *(int *)(g_021AD0F4 + 0x4) = a;
        return b;
    }
    return a;
}


/*
 * Calls the module setter on the value with the sentinel -1.
 */
int func_0217EB18(int pf, int type, int protocol)
{
    return func_0217EB00(func_0215F428(), -1);
}


int func_0217EB2C(int sock)
{
    return func_0217EB00(func_0215F644(sock), -1);
}


int closesocketsure(int sock, int *notInCloseSocket)
{
    int rcode;

    rcode = SOC_Close(sock);
    if (rcode == 0) {
        *notInCloseSocket = (*notInCloseSocket == 0) ? 1 : 0;
        return *notInCloseSocket;
    }
    if (SOCL_IsReleased(sock) == 0)
        return 0;
    CheckRcode(rcode, -1);
    *notInCloseSocket = 1;
    return 1;
}


int func_0217EB9C(int sock, int how)
{
    return func_0217EB00(func_0215F638(sock, how), -1);
}
