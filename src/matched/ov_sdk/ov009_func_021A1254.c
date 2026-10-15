/*
 * function: ProcessDeleteServer
 * address:  0x021A1254
 * packet:   pkt_ov009_021A1254
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ProcessDeleteServer (sb_serverlist.o)
 *
 * Closed (w5_nm): both field copies are string.h memcpy, ip first then port;
 * mwccarm schedules the inline byte loads in the object's order (port bytes
 * first) and gives the object's registers.  Byte-pointer copies landed the
 * pointer and value temps in swapped registers.
 *
 * symbols:
 *   SBServerListFindServerByIP                  0x0219F6C8  arm ov009
 *   SBServerListRemoveAt                  0x0219F768  arm ov009
 */

#include "../arm9_sdk/libc/string.h"

typedef enum {
    sbe_noerror,
    sbe_socketerror,
    sbe_memoryerror,
    sbe_paramerror,
    sbe_dataerror
} SBError;

struct _SBServerList;

extern int SBServerListFindServerByIP(struct _SBServerList *slist, unsigned int ip, unsigned short port);
extern void SBServerListRemoveAt(struct _SBServerList *slist, int index);

SBError ProcessDeleteServer(struct _SBServerList *slist, char *buf, int len)
{
    int i;
    unsigned short port;
    unsigned int ip;

    if (len < 6)
        return sbe_dataerror;
    memcpy(&ip, buf, 4);
    memcpy(&port, buf + 4, 2);
    i = SBServerListFindServerByIP(slist, ip, port);
    if (i == -1)
        return sbe_noerror;
    SBServerListRemoveAt(slist, i);
    return sbe_noerror;
}
