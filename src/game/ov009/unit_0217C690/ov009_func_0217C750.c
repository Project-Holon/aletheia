/*
 * function: func_0217C750
 * address:  0x0217C750
 * packet:   pkt_ov009_0217C750
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GSIStartAvailableCheckA (gsavailable.o)
 *
 * symbols:
 *   func_021803BC                  0x021803BC  arm ov009
 *   func_0217F25C                  0x0217F25C  arm ov009
 *   func_02084F40                  0x02084F40  arm
 *   func_0217C690                  0x0217C690  arm ov009
 *   func_0217EB18                  0x0217EB18  arm ov009
 *   func_0209477C                  0x0209477C  arm
 *   func_02092344                  0x02092344  arm
 *   func_0217C704                  0x0217C704  arm ov009
 *   g_021ACEFC                     0x021ACEFC  data
 *   g_021ACF7C                     0x021ACF7C  data
 *   g_021ACF3C                     0x021ACF3C  data
 *   g_021A36E8                     0x021A36E8  data
 *   g_021ACF80                     0x021ACF80  data
 *   g_021ACF8D                     0x021ACF8D  data
 */

#include "../../../matched/include/G_SOCSockAddrIn.h"

struct gsAC {
    int sock;
    char pad0[8];
    unsigned char b0c;
    char pad1[0x4c - 0xd];
    int len;
    int pad50;
    int sent;
};
extern int func_021803BC(char *dst, const char *src, unsigned int n);
extern void func_0217F25C(void);
extern int func_02084F40(char *dst, char *fmt, ...);
extern int func_0217C690(char *hostname, int port, struct SOCSockAddrIn *saddr);
extern int func_0217EB18(int pf, int type, int protocol);
typedef unsigned char  u8;
extern int func_0209477C(const u8 *s);
extern void *func_02092344(void *dst, const void *src, unsigned long n);
extern void func_0217C704(void);
extern char g_021ACEFC[];
extern struct gsAC g_021ACF7C;
extern char g_021ACF3C[];
extern char g_021A36E8[];
extern struct SOCSockAddrIn g_021ACF80;
extern char g_021ACF8D[];

void func_0217C750(char *gamename)
{
    int len;
    int override;
    char *host;
    char hostname[64];

    func_021803BC(g_021ACEFC, gamename, 64);
    g_021ACF7C.sock = -1;
    func_0217F25C();
    override = g_021ACF3C[0];
    if (override == 0)
        func_02084F40(hostname, g_021A36E8, gamename);
    host = g_021ACF3C;
    if (override == 0)
        host = hostname;
    if (!func_0217C690(host, 27900, &g_021ACF80))
        return;
    g_021ACF7C.sock = func_0217EB18(2, 2, 0);
    if (g_021ACF7C.sock == -1)
        return;
    g_021ACF7C.b0c = 9;
    len = func_0209477C((const u8 *)gamename);
    func_02092344(g_021ACF8D, gamename, len + 1);
    g_021ACF7C.len = len + 6;
    func_0217C704();
    g_021ACF7C.sent = 0;
}
