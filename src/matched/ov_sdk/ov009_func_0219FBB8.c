/*
 * function: func_0219FBB8
 * address:  0x0219FBB8
 * packet:   pkt_ov009_0219FBB8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ServerListConnect (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * symbols:
 *   func_0219FB64  0x0219FB64  arm  ov009
 *   func_021803BC  0x021803BC  arm  ov009
 *   func_02084F40  0x02084F40  arm
 *   func_0217ED38  0x0217ED38  arm  ov009
 *   func_0215F650  0x0215F650  arm  ov009
 *   func_0217EB18  0x0217EB18  arm  ov009
 *   func_0217EC08  0x0217EC08  arm  ov009
 *   func_0217EB2C  0x0217EB2C  arm  ov009
 *   g_021AEB04     0x021AEB04  data
 *   g_021A8234     0x021A8234  data
 */

#include "../arm9_sdk/libc/string.h"
#include "../include/G_021AEB04.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

typedef struct {
    char pad0[0xc];
    char gamename[0x6a8];
    int sock;
} SBServerList;

typedef struct {
    u8 len;
    u8 family;
    u16 port;
    u32 addr;
} SOCSockAddrIn;

typedef struct {
    char *name;
    char **aliases;
    short addrType;
    short length;
    u8 **addrList;
} SOCHostEnt;

extern struct G_021AEB04 g_021AEB04;
extern char g_021A8234[];

extern int func_0219FB64(char *s, int numbuckets);
extern u32 func_021803BC(char *dst, char *src, u32 size);
extern int func_02084F40(char *dst, char *fmt, ...);
extern u32 func_0217ED38(char *name);
extern SOCHostEnt *func_0215F650(char *name);
extern int func_0217EB18(int pf, int type, int protocol);
extern int func_0217EC08(int sock, void *addr, int len);
extern int func_0217EB2C(int sock);

int func_0219FBB8(SBServerList *slist)
{
    SOCSockAddrIn saddr;
    SOCHostEnt *hent;
    char masterHostname[128];
    int masterIndex;

    masterIndex = func_0219FB64(slist->gamename, 20);
    if ((*(char * *)&g_021AEB04))
        func_021803BC(masterHostname, (*(char * *)&g_021AEB04), 128);
    else
        func_02084F40(masterHostname, g_021A8234, slist->gamename, masterIndex);
    saddr.family = 2;
    saddr.port = 0xEE70;
    saddr.addr = func_0217ED38(masterHostname);
    if (saddr.addr == (u32)-1) {
        hent = func_0215F650(masterHostname);
        if (!hent)
            return 2;
        memcpy(&saddr.addr, hent->addrList[0], 4);
    }
    if (slist->sock == -1) {
        slist->sock = func_0217EB18(2, 1, 0);
        if (slist->sock == -1)
            return 1;
    }
    if (func_0217EC08(slist->sock, &saddr, 8) == 0)
        return 0;
    func_0217EB2C(slist->sock);
    slist->sock = -1;
    return 3;
}
