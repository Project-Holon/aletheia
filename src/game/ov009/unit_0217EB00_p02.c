/*
 * file:     unit_0217EB00_p02.c
 * unit:     yes
 * function: func_0217EBB0, func_0217EC08, func_0217EC4C
 * address:  0x0217EBB0
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
 *   SOC_Bind         0x0215f454 arm
 *   CheckRcode       0x0217eb00 arm
 *   SOC_Connect      0x0215f480 arm
 */
struct SOCSockAddr {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned char addr[4];
} __attribute__((packed));
extern int SOC_Bind(int s, void * sockAddr);
extern int CheckRcode(int rcode, int errCode);
extern int SOC_Connect(int s, void * sockAddr);
extern int func_0215F4DC(void);
extern int func_0217EB00(int a, int b);
int bind(int sock, const struct SOCSockAddr * addr, int len);
int connect(int sock, const struct SOCSockAddr * addr, int len);
int func_0217EC4C(int sock, char *buffer, int len, int flags);


int bind(int sock, const struct SOCSockAddr * addr, int len)
{
    struct SOCSockAddr localAddr;
    int rcode;

    if (addr->port == 0)
        return 0;

    localAddr = *addr;
    localAddr.len = len;
    rcode = SOC_Bind(sock, &localAddr);
    return CheckRcode(rcode, -1);
}


int connect(int sock, const struct SOCSockAddr * addr, int len)
{
    struct SOCSockAddr remoteAddr;
    int rcode;

    remoteAddr = *addr;
    remoteAddr.len = len;
    rcode = SOC_Connect(sock, &remoteAddr);
    return CheckRcode(rcode, -1);
}


/*
 * Calls the module setter on the value with the sentinel -1.
 */
int func_0217EC4C(int sock, char *buffer, int len, int flags)
{
    return func_0217EB00(func_0215F4DC(), -1);
}
