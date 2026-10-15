/*
 * function: GSIStartAvailableCheckA
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
 *   gsiSafeStrcpyA                  0x021803BC  arm ov009
 *   SocketStartUp                  0x0217F25C  arm ov009
 *   OS_SPrintf                  0x02084F40  arm
 *   func_0217C690                  0x0217C690  arm ov009
 *   func_0217EB18                  0x0217EB18  arm ov009
 *   strlen                  0x0209477C  arm
 *   func_02092344                  0x02092344  arm
 *   func_0217C704                  0x0217C704  arm ov009
 *   gGsAvailabilityGameName                     0x021ACEFC  data
 *   gGsAvailableCheck                     0x021ACF7C  data
 *   gGsAvailableOverrideHost                     0x021ACF3C  data
 *   gGsAvailableHostFmt                     0x021A36E8  data
 *   g_021ACF80                     0x021ACF80  data
 *   g_021ACF8D                     0x021ACF8D  data
 */

#include "../include/G_SOCSockAddrIn.h"

struct gsAC {
    int sock;
    char pad0[8];
    unsigned char b0c;
    char pad1[0x4c - 0xd];
    int len;
    int pad50;
    int sent;
};
extern int gsiSafeStrcpyA(char *dst, const char *src, unsigned int n);
extern void SocketStartUp(void);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern int func_0217C690(char *hostname, int port, struct SOCSockAddrIn *saddr);
extern int func_0217EB18(int pf, int type, int protocol);
typedef unsigned char  u8;
extern int strlen(const u8 *s);
extern void *func_02092344(void *dst, const void *src, unsigned long n);
extern void func_0217C704(void);
extern char gGsAvailabilityGameName[];
extern struct gsAC gGsAvailableCheck;
extern char gGsAvailableOverrideHost[];
extern char gGsAvailableHostFmt[];
extern struct SOCSockAddrIn g_021ACF80;
extern char g_021ACF8D[];

void GSIStartAvailableCheckA(char *gamename)
{
    int len;
    int override;
    char *host;
    char hostname[64];

    gsiSafeStrcpyA(gGsAvailabilityGameName, gamename, 64);
    gGsAvailableCheck.sock = -1;
    SocketStartUp();
    override = gGsAvailableOverrideHost[0];
    if (override == 0)
        OS_SPrintf(hostname, gGsAvailableHostFmt, gamename);
    host = gGsAvailableOverrideHost;
    if (override == 0)
        host = hostname;
    if (!func_0217C690(host, 27900, &g_021ACF80))
        return;
    gGsAvailableCheck.sock = func_0217EB18(2, 2, 0);
    if (gGsAvailableCheck.sock == -1)
        return;
    gGsAvailableCheck.b0c = 9;
    len = strlen((const u8 *)gamename);
    func_02092344(g_021ACF8D, gamename, len + 1);
    gGsAvailableCheck.len = len + 6;
    func_0217C704();
    gGsAvailableCheck.sent = 0;
}
