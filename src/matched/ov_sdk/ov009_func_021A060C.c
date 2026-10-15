/*
 * function: ParseServer
 * address:  0x021A060C
 * packet:   pkt_ov009_021A060C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ParseServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_serverlist.o))
 *
 * The object calls strlen once per string skip and applies the result to buf and
 * len; ADVANCE spells that with a block-scoped temporary.
 *
 * symbols:
 *   SBServerSetFlags  0x0219E9AC  arm  ov009
 *   SBServerSetPrivateAddr  0x0219E9B4  arm  ov009
 *   SBServerSetICMPIP  0x0219E9C0  arm  ov009
 *   ArrayLength  0x02184200  arm  ov009
 *   func_02184208  0x02184208  arm  ov009
 *   func_0219E084  0x0219E084  arm  ov009
 *   func_0219E01C  0x0219E01C  arm  ov009
 *   strlen  0x0209477C  arm
 *   SBServerGetState  0x0219E9D0  arm  ov009
 *   SBServerSetState  0x0219E9C8  arm  ov009
 */

#include "../arm9_sdk/libc/string.h"

#define SWAP16(x) ((unsigned short)((((x) >> 8) & 0xff) | (((x) << 8) & 0xff00)))

#define ADVANCE(b, l) { int n = strlen(b) + 1; b += n; l -= n; }

typedef struct SBServer SBServer;
typedef struct {
    char *keyName;
    int keyType;
} KeyInfo;
typedef struct SBServerList {
    int state;
    void *servers;
    void *keylist;
    char pad0c[0x84 - 0x0c];
    char *popularvalues[255];
    char pad480[0x6ac - 0x480];
    unsigned short defaultport;
} SBServerList;

extern void SBServerSetFlags(SBServer *server, unsigned char flags);
extern void SBServerSetPrivateAddr(SBServer *server, unsigned int ip, unsigned short port);
extern void SBServerSetICMPIP(SBServer *server, unsigned int ip);
extern int ArrayLength(void *array);
extern void *func_02184208(void *array, int n);
extern void func_0219E084(SBServer *server, char *keyname, int value);
extern void func_0219E01C(SBServer *server, char *keyname, char *value);
extern unsigned char SBServerGetState(SBServer *server);
extern void SBServerSetState(SBServer *server, unsigned char state);

int ParseServer(SBServerList *slist, SBServer *server, char *buf, int len, int usepopularlist)
{
    int numkeys;
    int i;
    short sval;
    int strindex;
    int holdlen;
    unsigned int ip;
    unsigned short port;
    unsigned char flags;
    KeyInfo *ki;
    char *k;
    unsigned char state;

    holdlen = len;
    flags = *buf++;
    SBServerSetFlags(server, flags);
    buf += 4;
    len -= 5;
    if (flags & 0x10) {
        buf += 2;
        len -= 2;
    }
    if (flags & 2) {
        memcpy(&ip, buf, 4);
        buf += 4;
        len -= 4;
    } else
        ip = 0;
    if (flags & 0x20) {
        memcpy(&port, buf, 2);
        buf += 2;
        len -= 2;
    } else
        port = slist->defaultport;
    SBServerSetPrivateAddr(server, ip, port);
    if (flags & 8) {
        memcpy(&ip, buf, 4);
        buf += 4;
        len -= 4;
        SBServerSetICMPIP(server, ip);
    }
    if (flags & 0x40) {
        numkeys = ArrayLength(slist->keylist);
        for (i = 0; i < numkeys; i++) {
            ki = (KeyInfo *)func_02184208(slist->keylist, i);
            switch (ki->keyType) {
            case 1:
                func_0219E084(server, ki->keyName, (unsigned char)*buf++);
                len--;
                break;
            case 2:
                memcpy(&sval, buf, 2);
                func_0219E084(server, ki->keyName, SWAP16((unsigned short)sval));
                buf += 2;
                len -= 2;
                break;
            case 0:
                if (usepopularlist) {
                    strindex = (unsigned char)*buf++;
                    len--;
                } else
                    strindex = 0xff;
                if (strindex == 0xff) {
                    func_0219E01C(server, ki->keyName, buf);
                    ADVANCE(buf, len);
                } else
                    func_0219E01C(server, ki->keyName, slist->popularvalues[strindex]);
                break;
            }
        }
        SBServerSetState(server, SBServerGetState(server) | 1);
    }
    if (flags & 0x80) {
        while (*buf && len > 0) {
            k = buf;
            ADVANCE(buf, len);
            func_0219E01C(server, k, buf);
            ADVANCE(buf, len);
        }
        len--;
        SBServerSetState(server, SBServerGetState(server) | 2);
    }
    state = SBServerGetState(server);
    if (!(flags & 0xc0) && ((state & 1) || (state & 2)))
        SBServerSetState(server, state & 0xfc);
    return holdlen - len;
}
